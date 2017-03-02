func trap(height []int) int {
    trapWater := 0
    curTrapWater := 0
    maxBar := 0
    idx:=0
    for idx < len(height) {
        if height[idx] >= maxBar{
            maxBar = height[idx]
            trapWater += curTrapWater
            curTrapWater = 0
        } else {
            curTrapWater += maxBar - height[idx]
        }
        idx++
    }
    if curTrapWater > 0 {
        curTrapWater = 0
        rightMaxBar := 0
        idx = len(height) - 1
        for idx >=0 && height[idx] < maxBar {
            if height[idx] >= rightMaxBar{
                rightMaxBar = height[idx]
                trapWater += curTrapWater
                curTrapWater = 0
            } else {
                curTrapWater += rightMaxBar - height[idx]
            }
            idx--
        }
    }
    if curTrapWater > 0 {
        trapWater += curTrapWater
    }     
    return trapWater
}