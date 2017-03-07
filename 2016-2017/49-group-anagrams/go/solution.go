// 1. get the sorted s of str in strs
// 2. use s as key, to keep str in value (type list)
// 3. return map's values

func groupAnagrams(strs []string) [][]string {
    anagramMap := make(map[string][]string)
    for _, str := range strs{
        key:=SortString(str)
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

type sortRunes []rune

func (s sortRunes) Less(i, j int) bool {
    return s[i] < s[j]
}

func (s sortRunes) Swap(i, j int) {
    s[i], s[j] = s[j], s[i]
}

func (s sortRunes) Len() int {
    return len(s)
}

func SortString(s string) string {
    r := []rune(s)
    sort.Sort(sortRunes(r))
    return string(r)
}