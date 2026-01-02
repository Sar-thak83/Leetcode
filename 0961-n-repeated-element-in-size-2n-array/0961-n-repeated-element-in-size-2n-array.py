class Solution:
    def repeatedNTimes(self, nums: List[int]) -> int:
        A=set()
        for i in range(len(nums)):
            A.add(nums[i])
        B={}
        for num in nums :
            if num in B : 
                B[num]=B[num]+1
            else :
                B[num]=1
        
        for key in B :
            if B[key] == len(A)-1 :
                return key
        
        return 0
