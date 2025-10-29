/**
 * @param {number[]} arr
 * @param {Function} fn
 * @return {number[]}
 */
var filter = function(arr, fn) {
    const result=[];
    arr.forEach((element,index)=>{
    if(fn(element,index)){
        result.push(element);
    }
    })
    return result;
};