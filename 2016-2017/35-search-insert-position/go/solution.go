func searchInsert(nums []int, target int) int {
    left, right := 0, len(nums) - 1
    for left < right {
    	mid := (left + right) / 2
    	if nums[mid] == target {
    		return mid
    	} else if nums[mid] < target {

    	}
    }
    return left
}