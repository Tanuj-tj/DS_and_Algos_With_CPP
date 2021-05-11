# Fibonacci Series using recursion 
# Complexity : O(2^n)

def fib_rec(n):
    if(n<=2):
        return 1
    return fib(n-1) + fib(n-2)


print(fib_rec(5))
print(fib_rec(6))
# print(fib_rec(50)) # This will take 2^50 step to execute 


## Memoization ## 

# Create Dictionaries where keys will be arg to function and value will be return value

def fib_dy(n, memo=dict()):
    if(n in memo):
        return memo[n]
    if(n<=2):
        return 1
    memo[n] = fib_dy(n-1,memo) + fib_dy(n-2,memo)
    print(memo)
    return memo[n] 

print(fib_dy(5))   # 5
#print(fib_dy(6))   # 8
#print(fib_dy(50))  # 12586269025