var TimeLimitedCache = function() {
    this.map=new Map();
};

/** 
 * @param {number} key
 * @param {number} value
 * @param {number} duration time until expiration in ms
 * @return {boolean} if un-expired key already existed
 */
TimeLimitedCache.prototype.set = function(key, value, duration) {
    const now= Date.now();
    const existing=this.map.get(key);
    const stillValid=existing&&existing.expiry>now;
    if(existing){
        clearTimeout(existing.timerId);
        if(!stillValid)this.map.delete(key);
    }
    const expiry=now+duration;
    const timerId=setTimeout(()=>{
        this.map.delete(key);
    },duration);
    this.map.set(key,{value,expiry,timerId});
    return Boolean(stillValid);
};

/** 
 * @param {number} key
 * @return {number} value associated with key
 */
TimeLimitedCache.prototype.get = function(key) {
    const now =Date.now();
    const rec=this.map.get(key);
    if(!rec)return -1;
    if(rec.expiry<=now){
        clearTimeout(rec.timerId);
        this.map.delete(key);
        return -1;
    }
    return rec.value;
};

/** 
 * @return {number} count of non-expired keys
 */
TimeLimitedCache.prototype.count = function() {
    const now=Date.now();
    let cnt=0;
    for(const [k,rec] of this.map){
        if(rec.expiry>now)cnt++;
        else{
            clearTimeout(rec.timerId);
            this.map.delete(k);
        }
    }
    return cnt;
};

/**
 * const timeLimitedCache = new TimeLimitedCache()
 * timeLimitedCache.set(1, 42, 1000); // false
 * timeLimitedCache.get(1) // 42
 * timeLimitedCache.count() // 1
 */