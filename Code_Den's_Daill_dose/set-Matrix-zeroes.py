#Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.
#You must do it in place.

# My Leetcode solution

class Solution:
    def setZeroes(self, matrix: List[List[int]]) -> None:
        """
        Do not return anything, modify matrix in-place instead.
        """
        row = len( matrix )
        col = len( matrix[0] )
        
        rl=set()
        cl=set()
                
        for i in range(0,row):
            for j in range(0,col):
                if matrix[i][j] == 0:
                    rl.add(i)
                    cl.add(j)
                    
        rl=list(rl)
        cl=list(cl)
        
        for j in cl:
            for i in range(0,row):
                matrix[i][j]=0
            
                            
        for i in rl:
            for j in range(0,col):
                matrix[i][j]=0
