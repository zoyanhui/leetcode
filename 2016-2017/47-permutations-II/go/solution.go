import "sort"
func permuteUnique(nums []int) [][]int {
    sort.Ints(nums)
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
        if i > curidx && nums[i] == nums[i-1] {
            continue
        }
        swap(nums, curidx, i)
        permuteRec(nums, curidx+1, ret)
        swap(nums, i, curidx)
    }
}

func swap(nums []int, i int, j int) {
    if i < j {
        temp := nums[j]
        for i < j {
            nums[j] = nums[j-1]
            j--
        }
        nums[i] = temp
    } else {
        temp := nums[j]
        for i > j {
            nums[j] = nums[j+1]
            j++
        }
        nums[i] = temp
    }
}