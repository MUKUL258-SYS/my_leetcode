module Comparable
    def max(v) = (self > v ? self : v)
end

def max_distance(nums1, nums2)
    return 0 if nums1.last > nums2.first
    n1, n2 = nums1.size, nums2.size
    i1 = 0
    nums2.each_with_index.inject(0) {|res, (v2, i2)|
        i1 += 1 while i1 < i2 && i1 < n1 && nums1[i1] > v2
        return res if i1 >= n1
        res.max(i2 - i1)
    }
end