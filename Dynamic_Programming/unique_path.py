# Recursive Solution 
# Complexity : O(2^N+M) Time , O(N+M) Space

def uniquePaths(n,m):
    if(n==1 or m==1):
        return 1
    else:
        return uniquePaths(n-1, m) + uniquePaths(n, m-1)

print(uniquePaths(2,2))
#print(uniquePaths(18,18))  # Break for this case


# DP Solution 
# Complexity : O(M*N) Time , O(N+M) Space

def uniquePaths(n,m,memo=dict()):
    key = m,n
    if(key in memo):
        return memo[key]
    if(n==1 or m==1):
        return 1
    memo[key] = uniquePaths(n-1, m) + uniquePaths(n, m-1)
    print(memo)
    return memo[key]

print(uniquePaths(3,3))
print(uniquePaths(23,12))