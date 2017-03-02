func trap(height []int) int {
    trapWater := 0
    leftMaxBar, rightMaxBar := 0, 0
    left, right := 0, len(height) - 1
    for left < right {
        if height[left] < height[right] {
            if height[left] > leftMaxBar {
                leftMaxBar = height[left]
            } else {
                trapWater += leftMaxBar - height[left]
            }
            left++
        } else {
            if height[right] > rightMaxBar {
                rightMaxBar = height[right]
            } else {
                trapWater += rightMaxBar - height[right]
            }
            right--
        }
    }     
    return trapWater
}