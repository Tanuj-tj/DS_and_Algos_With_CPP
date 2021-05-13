# arr = {5,3,4,7} , target = 7
# o/p => True

# arr = {2,4} , target = 7
# o/p => false

# Recursive Approach
# Complexity : if M = target and N = array Lenght , Time = O(N^M) , Space = O(M)   

from typing import List

def canSum( arr:List[int], target:int ) -> bool:
    # Base case
    if (target == 0): return True
    if (target < 0): return False

    for i in arr:
        rem = target - i
        if(canSum(arr,rem) == True):    # Recursive Call
            return True
    
    return False


# Test Cases
print(canSum([5, 3, 4, 7], 7))
print(canSum([2, 3], 7))
print(canSum([2, 4],7))
print(canSum([2, 3, 5],8))
#print(canSum([7, 14],300))  # Break condition

# DP Approach
# Complexity : if M = target and N = array Lenght , Time = O(M*N) , Space = O(M)   

def canSum( arr, target, memo=dict()):
    # Base case
    if(target in memo): return memo[target]
    if (target == 0): return True
    if (target < 0): return False

    for i in arr:
        rem = target - i
        if(canSum(arr,rem,memo) == True):    # Recursive Call
            memo[target] = True
            #print(memo)
            return True
    
    memo[target] = False
    return False


# Test Cases
print(canSum([5, 3, 4, 7], 7))
print(canSum([2, 3], 7))
print(canSum([2, 4],7))
print(canSum([2, 3, 5],8))
print(canSum([7, 14],300))  # Break condition
