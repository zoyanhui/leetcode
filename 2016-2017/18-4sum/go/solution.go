import "sort"

func fourSum(nums []int, target int) [][]int {
    if !sort.IntsAreSorted(nums) {  
        sort.Ints(nums)  
    }  
    var result [][]int
	n := len(nums)
	for k:=0; k<n-3; k++{
		if k > 0 && nums[k] == nums[k-1] {
			continue
		}
		for k2:=k+1;k2<n-2;k2++{
			if k2 > k+1 && nums[k2] == nums[k2-1] {
				continue
			}
			target2 := target - nums[k] - nums[k2]
			i := k2 + 1
			j := n - 1
			for i < j {
				cur := nums[i] + nums[j]
				if cur == target2 {
					result = append(result, []int{nums[k], nums[k2], nums[i], nums[j]})
					i++
					j--
				} else if cur < target2 {
					i++
				} else {
					j--
				}
				for i<j && i>k2+1 && nums[i] == nums[i-1] {
					i++
				}
				for i<j && j < n-1 && nums[j] == nums[j+1] {
					j--
				}
			}
		}
		
	}
	return result
}