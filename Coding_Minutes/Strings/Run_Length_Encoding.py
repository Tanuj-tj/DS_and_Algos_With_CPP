'''
Write a function to pen‘orm basic string compression using the counts of repeated characters,
also known as Run Length Encoding. Let see one example, the input string "aaaabcccccaaa"
would become ”a4b1c5a3". If the "compressed" string would not become smaller than the
original string, your function should return the input string. You can assume the string has only
uppercase and lowercase letters. You may use the to_str‘ing(int) method to convert an
integer into string.

Sample Inputs :
bbbaaaadexxxxxx
abc

Sample Outputs :
b3a4d1e1x6
abc
'''

def compressString(string:str) -> str:
    
    words = string.split()
    ans = ""
    dict_str = {}
    
    for letter in string:
        if (letter in dict_str):
            dict_str[letter] += 1   # {'b':3, 'a':4}
        else:
            dict_str[letter] = 1
    
    for i,j in dict_str.items():
         ans = ans + i+str(j)
            
    if len(ans) < len(string):
        return ans
    else:
        return string
    
    
            

test1 = "bbbaaaadexxxxxx"
test2 = "abc"
print(compressString(test1))
print(compressString(test2))
