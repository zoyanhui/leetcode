class Solution(object):
    def findSubstring(self, s, words):
        """
        :type s: str
        :type words: List[str]
        :rtype: List[int]
        """
        resultList = []
        wordsLen = len(words)
        if wordsLen == 0:
            return resultList
        wordDict = self.buildWordDict(words)
        wordLen = len(words[0])
        for i in range(len(s) - wordsLen * wordLen + 1):
            curDict = {}
            w = 0
            while w < wordsLen:
                wStart = i + w*wordLen
                wEnd = wStart + wordLen
                curWord = s[wStart:wEnd]
                if curWord in wordDict:
                    curDict[curWord] = curDict.get(curWord,0) + 1
                    if wordDict.get(curWord,0) < curDict[curWord]:
                        break
                else:
                    break
                w+=1
            if w == wordsLen:
                resultList.append(i)
        return resultList

    def buildWordDict(self, words):
        d = dict()
        for w in words:
            c = d.get(w, 0)
            d[w] = c+1
        return d