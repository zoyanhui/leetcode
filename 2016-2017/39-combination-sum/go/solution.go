import "sort"

func combinationSum(candidates []int, target int) [][]int {
    sort.Ints(candidates)
    var ret [][]int
    var curlist []int
    combinationSumRecursive(candidates, target, 0, &curlist, &ret)
    return ret
}

func combinationSumRecursive(candidates []int, target int, curCandidateIdx int, curlist *[]int, ret *[][]int) {
    if target == 0 {
        s := make([]int, len(*curlist))
        copy(s, *curlist)
        *ret = append(*ret, s)
        return
    }
    for i:=curCandidateIdx;i<len(candidates);i++{
        if candidates[i] > target {
            break
        }
        *curlist = append(*curlist, candidates[i])
        combinationSumRecursive(candidates, target - candidates[i], i, curlist, ret)
        *curlist = (*curlist)[:len(*curlist)-1]
    }
}



// problem code, but I don't know why
import "sort"
import "fmt"

func combinationSum(candidates []int, target int) [][]int {
    sort.Ints(candidates)
    var ret [][]int
    var curlist []int
    combinationSumRecursive(candidates, target, 0, curlist, &ret)
    return ret
}

func combinationSumRecursive(candidates []int, target int, curCandidateIdx int, curlist []int, ret *[][]int) {
    fmt.Printf("address of slice %p, value is %x \n", &curlist, curlist)
    if target == 0 {
        fmt.Println("put", curlist)
        *ret = append(*ret, curlist)
        return
    }
    for i:=curCandidateIdx;i<len(candidates);i++{
        if candidates[i] > target {
            break
        }
        combinationSumRecursive(candidates, target - candidates[i], i, append(curlist, candidates[i]), ret)
    }
}