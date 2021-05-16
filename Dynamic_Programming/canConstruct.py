# Recursive : O(N^M * M)  ,  O(M^2)
# DP : O(N * M^2) , O(M^2)

def canConstruct(target,wordBank,memo={}):
    if(target in memo):
        return memo[target]
    if(target == ""):
        return True
    
    for word in wordBank:
        if(target.startswith(word,0)):
            suffix = target[len(word):]
            if(canConstruct(suffix,wordBank)==True):
                memo[target] = True
                return True

    memo[target] = False
    return False


# Test cases
print(canConstruct("abcdef", ["ab","abc","cd","def","abcd"]))  # True
print(canConstruct("skateboard",["bo","rd","ate","t","ska","sk","boar"])) # False
print(canConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", ["e","ee","eee","eeee","eeeee","eeeeeee"]))  # False