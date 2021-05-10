class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        
        # Moore's Voting Algo
        
        count = 0
        x = 0
        
        for i in nums:
            if(count==0):
                x=i
            if(i==x):
                count+=1
            else:
                count-=1
        
        return x
