class Solution:
    #Function to find the days of buying and selling stock for max profit.
	def stockBuySell(self, A, n):
		#code here

        ans = []
        
		if(n==1):
		    return 
		
		i = 0
		while(i<(n-1)):
		    
		    while(i<(n-1) and (A[i+1] <= A[i])):
		        i+=1
		        
		      
		    if(i==n-1):
		        break
		    
		    buy=i
		    i+=1
		    
		    while((i<n) and (A[i]>=A[i-1])):
		        i+=1
		        
		    sell = i-1
		    
		    ans.append([buy,sell])
		    
		return ans
