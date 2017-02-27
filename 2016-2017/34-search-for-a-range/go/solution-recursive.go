// avaiable solution, two binary search
func searchRange(nums []int, target int) []int {
    sRange := []int{-1,-1}
    sRange[0] = binarySearch(nums, target, 0, len(nums) - 1, true)
    if sRange[0] >=0 {
        sRange[1] = binarySearch(nums, target, 0, len(nums) - 1, false)    
    }
    return sRange
}

func binarySearch(nums []int, target int, left int, right int, low bool) int {
    if left > right {
        return -1
    }
    mid := (left + right) / 2
    if nums[mid] < target {
        return binarySearch(nums, target, mid+1, right, low)
    } else if nums[mid] > target {
        return binarySearch(nums, target, left, mid-1, low)
    } else {
        if low {
            if mid > 0 && nums[mid-1] == target {
                return binarySearch(nums, target, left, mid-1, low)
            } else {
                return mid
            }
        } else {
            if mid < right && nums[mid+1] == target {
                return binarySearch(nums, target, mid+1, right, low)
            } else {
                return mid
            }
        }
    }
}

// below solution
// a litte improvement
func searchRange(nums []int, target int) []int {
    sRange := []int{-1,-1}
    binarySearch(nums, target, 0, len(nums) - 1, sRange)
    return sRange
}

func binarySearch(nums []int, target int, left int, right int, sRange []int) {
    if left > right {
        return
    }
    mid := (left + right) / 2
    if nums[mid] < target {
        binarySearch(nums, target, mid+1, right, sRange)
        return 
    } else if nums[mid] > target {
        binarySearch(nums, target, left, mid-1, sRange)
        return 
    } else {
        if mid == 0 || nums[mid-1] < target {
            sRange[0] = mid
        } else {
            binarySearch(nums, target, left, mid-1,sRange)
        }
        if mid == right || nums[mid+1] > target {
            sRange[1] = mid
        } else {
            binarySearch(nums, target, mid+1, right,sRange)
        }
    }
}