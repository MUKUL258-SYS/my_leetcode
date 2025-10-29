/**
 * @param {number[]} nums
 * @param {Function} fn
 * @param {number} init
 * @return {number}
 */
var reduce = function(nums, fn, init) {
    let sum=init;
    nums.forEach((element)=>{
        sum=fn(sum,element);
    })
    return sum;
};