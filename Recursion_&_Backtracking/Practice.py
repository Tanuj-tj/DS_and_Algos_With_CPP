# If base case is not present 
# RecursionError: maximum recursion depth exceeded
# This is commonly known as Stack overflow exception

# Recurrence Relation :
# Thinking of the Runtime of our code parametrically 

'''

Running time of the recursive function will depend upon N

so we can say => T(N)

T(N) = T(n-1) + O(1)  

T(N-1) = T(n-2 ) + O(1)

T(N-2) = T(n-3) + O(1)

T(N-3) = T(n-4) + O(1)



'''

# Check Palindrome
def checkPalindrome(string:str,s:int,e:int)->bool:
    
    if(s == e):
        return True
    
    if(string[s]!=string[e]):
        return False
    
    if(string[s] == string[e]):
        return checkPalindrome(string,s+1,e-1)
    
    return False

def main():
    string = "racecarr"
    print(checkPalindrome(string,0,len(string)-1))
    
main()


# Print earch character of a string in reverse order
def printChar(s:str,pos):
    if(pos == len(s)):
        return
    printChar(s,pos+1)
    print(s[pos])

def main():
    printChar("tanuj",0)
    
main()

# Power a ^ b
def power(a:int,b:int)->int:
    if(b==0):
        return 1
    
    return a * power(a,b-1)

def main():
    print(power(2,3))
    print(power(2,2))
    
main()

# Sum of natural no
# n = n + n-1 + n-2 + n-3.....1

def nat(n):
    if(n==1):
        return 1
    return n + nat(n-1)  

# 5 + nat(4) => 10+5=>15
# 4 + nat(3) => 6+4=>10
# 3 + nat(2) => 3+3=>6
# 2 + nat(1) => 3

nat(5)

# Fibonacci series

# n!= n! * n-1! * n-2! * n-3! .......1


def fact(n):
    if(n==0):   # base case  O(1)
        return 1           
    
    return n * fact(n-1)
    
'''
5 * fact(4) => 5 * 24 => 120
4 * fact(3) => 4 * 6 => 24
3 * fact(2) => 3 * 2 => 6
2 * fact(1) => 2 * 1 => 2 

'''

def main():
    print(fact(5))
    print(fact(4))
    print(fact(7))
    
main()


# Sum of digits up till one 

"""
Eg.  12345

1 + 2 + 3 + 4 + 5 => 15
1 + 5 = 6

"""

def sumUpTillOne(n):
    if(n < 10):
        return n
    
    return sumUpTillOne(sumOfDigits(n))


def sumOfDigits(n):
    
    if(n==0):
        return 0
    
    
    last = n % 10
    
    rem = n // 10
    
    return last + sumUpTillOne(rem)
    

def main():
    N = 12345
    print(sumUpTillOne(N))
    
main()


# Tower of Hanoi 

'''

You have thr e rods (A, B, C) and N discs. Your task is to move the N discs from
rod A to rod C Print the steps to do this in minimum number of moves. You must
follow the following rules:

1. You may move only one disk at a time.

2. A larger disc can never be on top of a smaller disc.


SOlution :

moving n discs from A to B = Moving (n-1) discs from A to C 
                             + Moving 1 disc from A to B
                             + Moving (n-1) discs from C to B

'''


def towerOfHanoi(n,sourceRoad, desRoad, auxRoad):
    
    # Base Case
    if(n==1):
        print(sourceRoad+"->"+desRoad)
        return
    
    towerOfHanoi(n-1,sourceRoad,auxRoad,desRoad);
    print(sourceRoad+"->"+desRoad)
    towerOfHanoi(n-1,auxRoad,desRoad,sourceRoad);
         
    




def main():
    n = 3
    towerOfHanoi(n,"A","B","C")
    
    
main()
