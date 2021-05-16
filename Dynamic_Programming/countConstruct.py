# Recursive : O(N^M * M)  ,  O(M^2)
# DP : O(N * M^2) , O(M^2)

def countConstruct(target,wordBank,memo={}):
    if(target in memo):
        return memo[target]
    if(target == ""):
        return 1
    
    totalCount = 0

    for word in wordBank:
        if(target.startswith(word,0)):
            numWays = countConstruct(target[len(word):], wordBank)
            totalCount += numWays 

    memo[target] = totalCount
    return totalCount


# Test cases
print(countConstruct("purple",["purp","p","ur","le","purpl"])) # 2
print(countConstruct("abcdef", ["ab","abc","cd","def","abcd"])) # 1
print(countConstruct("skateboard",["bo","rd","ate","t","ska","sk","boar"])) # 0
print(countConstruct("eeeeeeeeeeeeeeeeeeeeeeeeeeeeeef", ["e","ee","eee","eeee","eeeee","eeeeeee"]))  # 0