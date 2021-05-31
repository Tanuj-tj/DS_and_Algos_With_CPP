# Given a string s, find the length of the longest substring without repeating characters.

# I/P : "abcabcbb"
# O/P : 3

class Solution:
    def lengthOfLongestSubstring(self, s: str):
        
        # Corner Cases
        if(s==" "): return 1
        if(s==""): return 0
        
        # Convet into list
        s = list(s)  # ["a","b","c","a","b","c","b","b"]
        
        # Seperate condition for all unique string
        s_set = set(s)
        if(len(s_set) == len(s)): return len(s)
        
        j = 0  # 0, 1
        ans = []  # ['a','b']
        count_max = 0
        while(j<len(s)):
            if(s[j] not in ans):
                ans.append(s[j])
                j+=1
                count_max = max(count_max,len(ans))
            else:
                count_max = max(count_max,len(ans))
                ans = ans[1:]
                
        return count_max
                
    
print(Solution().lengthOfLongestSubstring("dvdf"))  # 3
print(Solution().lengthOfLongestSubstring("abcabcbb"))  # 3
print(Solution().lengthOfLongestSubstring("aab")) # 2
print(Solution().lengthOfLongestSubstring(" ")) # 1
print(Solution().lengthOfLongestSubstring("")) # 1
print(Solution().lengthOfLongestSubstring("bbbbb")) # 1
print(Solution().lengthOfLongestSubstring("pwwkew")) # 3
