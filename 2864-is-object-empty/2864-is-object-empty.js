/**
 * @param {Object|Array} obj
 * @return {boolean}
 */
var isEmpty = function(obj) {
    let len=Object.keys(obj).length;
    return (len==0)?true:false;
};