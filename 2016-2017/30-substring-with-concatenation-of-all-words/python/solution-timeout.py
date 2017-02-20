class Solution(object):
    def findSubstring(self, s, words):
        """
        :type s: str
        :type words: List[str]
        :rtype: List[int]
        """
        resultList = []
        if not words:
            return resultList
        wordDict = self.buildWordDict(words)
        wordLen = len(words[0])
        for i in range(len(s) - wordLen + 1):
            cur = s[i:i+wordLen]
            count = wordDict.get(cur, None)
            if count:
                count -= 1
                if count:
                    wordDict[cur] = count
                else:
                    del wordDict[cur]
                self.findSubStr(s[i+wordLen:], i, wordDict, wordLen, resultList)
                wordDict[cur] = count + 1
        return resultList


    def findSubStr(self, s, startIdx, wordDict, wordLen, resultList):
        if not wordDict:
            resultList.append(startIdx)
            return
        cur = s[0:wordLen]
        count = wordDict.get(cur, None)
        if count:
            count -= 1
            if count:
                wordDict[cur] = count
            else:
                del wordDict[cur]
            self.findSubStr(s[wordLen:], startIdx, wordDict, wordLen, resultList)
            wordDict[cur] = count + 1



    def buildWordDict(self, words):
        d = dict()
        for w in words:
            c = d.get(w, 0)
            d[w] = c+1
        return d


# change to not slice origin string,  Time Limit Exceeded too
class Solution(object):
    def findSubstring(self, s, words):
        """
        :type s: str
        :type words: List[str]
        :rtype: List[int]
        """
        resultList = []
        if not words:
            return resultList
        wordDict = self.buildWordDict(words)
        wordLen = len(words[0])
        for i in range(len(s) - wordLen + 1):
            cur = s[i:i+wordLen]
            count = wordDict.get(cur, None)
            if count:
                count -= 1
                if count:
                    wordDict[cur] = count
                else:
                    del wordDict[cur]
                self.findSubStr(s, i, i+wordLen, wordDict, wordLen, resultList)
                wordDict[cur] = count + 1
        return resultList


    def findSubStr(self, s, startIdx, curStart, wordDict, wordLen, resultList):
        if not wordDict:
            resultList.append(startIdx)
            return
        cur = s[curStart:curStart+wordLen]
        count = wordDict.get(cur, None)
        if count:
            count -= 1
            if count:
                wordDict[cur] = count
            else:
                del wordDict[cur]
            self.findSubStr(s, startIdx, curStart+wordLen, wordDict, wordLen, resultList)
            wordDict[cur] = count + 1



    def buildWordDict(self, words):
        d = dict()
        for w in words:
            c = d.get(w, 0)
            d[w] = c+1
        return d


# use iterator, Time Limit Exceeded too
class Solution(object):
    def findSubstring(self, s, words):
        """
        :type s: str
        :type words: List[str]
        :rtype: List[int]
        """
        resultList = []
        if not words:
            return resultList
        wordDict = self.buildWordDict(words)
        wordLen = len(words[0])
        for i in range(len(s) - wordLen + 1):  # chang to ` for i in range(len(s) - len(words) * wordLen + 1):` Time Limit Not Exceeeded
            cur = s[i:i+wordLen]
            if cur in wordDict:
                wordDictClone = dict(wordDict)
                curI = i
                while wordDictClone:
                    cur = s[curI:curI+wordLen]
                    count = wordDictClone.get(cur, 0)
                    if not count:
                        break
                    wordDictClone[cur] -= 1
                    if not wordDictClone[cur]:
                        del wordDictClone[cur]
                    if curI > len(s) - wordLen:
                        break
                    curI += wordLen
                if not wordDictClone:
                    resultList.append(i)
        return resultList

    def buildWordDict(self, words):
        d = dict()
        for w in words:
            c = d.get(w, 0)
            d[w] = c+1
        return d