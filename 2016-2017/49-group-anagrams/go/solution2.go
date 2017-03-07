var prime []uint


func groupAnagrams(strs []string) [][]string {
    prime = []uint{2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103};//最多10609个z
    anagramMap := make(map[uint][]string)
    for _, str := range strs{
        key:=getKey(str)
        val, ok := anagramMap[key]
        if !ok{
            val = []string{}
        }
        val = append(val, str)
        anagramMap[key] = val
    }
    ret := make([][]string, len(anagramMap))
    idx:=0
    for _, v := range anagramMap {
        ret[idx] = v
        idx++
    }
    return ret
}

func getKey(str string) uint{
    var val uint
    val = 1
    for _,c :=range str{
        val *= prime[(uint)(c-'a')]
    }
    return val
}