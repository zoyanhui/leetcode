func maxArea(height []int) int {
	n := len(height)
	i := 0
	j := n-1
	max := 0
	for i<j {
		var cur int
		if height[i] > height[j] {
			cur = (j-i) * height[j]
			j--
		} else {
			cur = (j-i) * height[i]
			i++
		}
		if cur > max{
			max = cur
		}
	}
	return max
}