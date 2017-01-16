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
        if i+1 < n && nums[i+1] == nums[i] {
            for i+1 < n && nums[i+1] == nums[i] {
                i++
            }
            i++
        } else {
            i++
        }
    }
    return result
}

func increase(i int, )

func twoSum(nums []int, startIdx int, target int) [][]int{
    n := len(nums)
    i:=startIdx
    j:=n-1
    var result [][]int
    for i<j{
        if nums[i]+nums[j] == target {
            result = append(result, []int{i, j})
            i++
            for i+1 < n && nums[i+1] == nums[i] {
                i++
            }
            j--
            for j>0 && nums[j] == nums[j-1] {
                j--
            }
        } else if nums[i]+nums[j] < target {
            i++
            for i+1 < n && nums[i+1] == nums[i] {
                i++
            }
        } else {
            j--
            for j>0 && nums[j] == nums[j-1] {
                j--
            }
        }
    }
    return result
}