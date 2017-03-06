func permute(nums []int) [][]int {
    var ret [][]int
    permuteRec(nums, 0, &ret)
    return ret
}

func permuteRec(nums []int, curidx int, ret *[][]int) {
    if curidx == len(nums) {
        copylist := make([]int, len(nums))
        copy(copylist, nums)
        *ret = append(*ret, copylist)
        return
    }
    for i:=curidx;i<len(nums);i++{
        swap(nums, curidx, i)
        permuteRec(nums, curidx+1, ret)
        swap(nums, curidx, i)
    }
}

func swap(nums []int, i int, j int) {
    temp := nums[i]
    nums[i] = nums[j]
    nums[j] = temp
}