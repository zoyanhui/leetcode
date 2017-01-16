import (  
    "fmt"  
    "sort"  
)  

func threeSum(nums []int) [][]int {
    if !sort.IntsAreSorted(nums) {  
        sort.Ints(nums)  
    }  
    var result [][]int
    n := len(nums)
    for i:=0; i<n; {
        idxArray := twoSum(nums, i+1, -nums[i])
        for _, idx := range(idxArray) {
            result = append(result, []int{nums[i], nums[idx[0]],nums[idx[1]]})
        }
        i = increase(i, nums)
    }
    return result
}

func increase(i int, nums []int) int {
    n := len(nums)
    if i+1 < n && nums[i+1] == nums[i] {
        for i+1 < n && nums[i+1] == nums[i] {
            i++
        }
        i++
    } else {
        i++
    }
    return i
}

func decrease(j int, nums []int) int {
    if j >0 && nums[j] == nums[j-1] {
        for j>0 && nums[j] == nums[j-1] {
            j--
        }
        j--
    } else {
        j--
    }
    return j
}

func twoSum(nums []int, startIdx int, target int) [][]int{
    n := len(nums)
    i:=startIdx
    j:=n-1
    var result [][]int
    for i<j{
        if nums[i]+nums[j] == target {
            result = append(result, []int{i, j})
            i = increase(i, nums)
            j = decrease(j, nums)
        } else if nums[i]+nums[j] < target {
            i = increase(i, nums)
        } else {
            j = decrease(j, nums)
            
        }
    }
    return result
}