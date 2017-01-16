import "sort"

func threeSumClosest(nums []int, target int) int {
	if !sort.IntsAreSorted(nums) {  
        sort.Ints(nums)  
    }  
	n := len(nums)
	minDiff := -1
	minDiffAbs := -1
	for k:=0; k<n-2; k++{
		if k > 0 && nums[k] == nums[k-1] {
			continue
		}
		i := k + 1
		j := n - 1
		for i < j {
			cur := nums[i] + nums[j] + nums[k] 
			if cur == target {
				return target
			} else if cur < target {
				i++
			} else {
				j--
			}
			for i<j && i>k+1 && nums[i] == nums[i-1] {
				i++
			}
			for i<j && j<n-1 && nums[j] == nums[j+1] {
				j--
			}
			absCur := cur - target
			if absCur < 0 {
				absCur = -absCur
			}
			if minDiffAbs < 0 || absCur < minDiffAbs {
				minDiffAbs = absCur
				minDiff = cur
			}
		}
	}
	return minDiff
}