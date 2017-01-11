// 归并扫描的方式，
// 奇数长度，取第(l1+l2+1) / 2 个数
// 偶数长度，取第(l1+l2+1) / 2 个数 和 第(l1+l2+1) / 2 +1 个数的集合
// 复杂度O(m+n)

func stepOn(nums1 []int, nums2[]int, i int, j int, l1 int, l2 int) (int, int, int) {
    if i < l1-1 && j < l2-1 {
        if nums1[i+1] < nums2[j+1] {
            return i+1, j, nums1[i+1]
        }
        return i, j+1, nums2[j+1]
    } else if i==l1-1 && j==l2-1 {
        return i, j, 0   
    } else if i == l1-1 {
        return i, j+1, nums2[j+1]
    } else{
        return i+1, j, nums1[i+1]
    } 
}

func findMedianSortedArrays(nums1 []int, nums2 []int) float64 {
    l1 := len(nums1)
    l2 := len(nums2)
    i := -1
    j := -1
    step:=0
    num := 0
    for step < (l1+l2+1) / 2 {
        i, j, num = stepOn(nums1, nums2, i, j, l1, l2)
        step ++
    }
    if (l1+l2 ) % 2 == 0 {
        var num2 int
        i, j, num2 = stepOn(nums1, nums2, i, j, l1, l2)
        return float64(num2 + num) / 2
    } else {
        return float64(num)
    }
}