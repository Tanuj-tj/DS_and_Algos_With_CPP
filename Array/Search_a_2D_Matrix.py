class Solution:

    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:

        '''        
        1st Approach :

        Complexity Time O(N*M) ,Space O(1)

        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                if target == matrix[i][j]:
                    return True
        
        return False
        
    
        2nd Approach (Optimal) :

          m = len(matrix[0])
          n = len(matrix)
          i = 0
          j = m-1  
          # ith will go left and jth will go down side
            
          while(i<n and j>=0):    # O ( (N*M) / 2)
            
            if(matrix[i][j]==target):
                return True
            
            elif(matrix[i][j]>target):
                j-=1
            else:
                i+=1
                
          return False
          
          '''
        
      # 3rd Approach (Best) => Use Binary search  , Complexity => O(log(row*col))  , O(1)
        
        if(len(matrix)==0):
            return False
        
        row = len(matrix) 
        col = len(matrix[0])
        
        low = 0
        high = (row*col) - 1
        
        while(low<=high):
            
            mid = (low+(high-low)//2)
            if(matrix[mid//col][mid%col] == target):
                return True
            
            if(matrix[mid//col][mid%col]<target):
                low = mid + 1
                
            else:
                high = mid - 1
        
        return False
        
