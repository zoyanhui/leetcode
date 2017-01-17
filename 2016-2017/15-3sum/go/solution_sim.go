import "sort"

func threeSum(nums []int) [][]int {
    if !sort.IntsAreSorted(nums) {  
        sort.Ints(nums)  
    }  
    var result [][]int
	n := len(nums)
	for k:=0; k<n-2; k++{
		if k > 0 && nums[k] == nums[k-1] {
			continue
		}
		target2 := 0 - nums[k]
		i := k + 1
		j := n - 1
		for i < j {
			cur := nums[i] + nums[j]
			if cur == target2 {
				result = append(result, []int{nums[k], nums[i], nums[j]})
				i++
				j--
			} else if cur < target2 {
				i++
			} else {
				j--
			}
			for i<j && i > k+1 && nums[i] == nums[i-1] {
				i++
			}
			for i<j && j+1<n && nums[j] == nums[j+1] {
				j--
			}
		}
	}
	return result
}