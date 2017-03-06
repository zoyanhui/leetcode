func permute(nums []int) [][]int {
    var ret [][]int
    permuteRec(nums, &ret, []int{})
    return ret
}

func permuteRec(nums []int, ret *[][]int, curlist []int) {
    if len(curlist) == len(nums) {
        copylist := make([]int, len(curlist))
        copy(copylist, curlist)
        *ret = append(*ret, copylist)
        return
    }
    for i:=0;i<len(nums);i++{
        if contains(curlist, nums[i]) {
            continue
        }
        curlist = append(curlist, nums[i])
        permuteRec(nums, ret, curlist)
        curlist = curlist[:len(curlist)-1]
    }
}

func contains(slice []int, item int) bool {
    for _, c := range slice {
        if c == item {
            return true
        }
    }
    return false
}