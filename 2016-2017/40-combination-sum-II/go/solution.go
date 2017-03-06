import "sort"

func combinationSum2(candidates []int, target int) [][]int {
    sort.Ints(candidates)
    var ret [][]int
    var curlist []int
    combinationSumRecursive(candidates, target, 0, curlist, &ret)
    return ret
}

func combinationSumRecursive(candidates []int, target int, curCandidateIdx int, curlist []int, ret *[][]int) {
    if target == 0 {
        *ret = append(*ret, curlist)
        return
    }
    for i:=curCandidateIdx;i<len(candidates);i++{
        if candidates[i] > target {
            break
        }
        combinationSumRecursive(candidates, target - candidates[i], i+1, append(curlist, candidates[i]), ret)
        for i+1 < len(candidates) && candidates[i+1] == candidates[i] {
            i++
        }
    }
}