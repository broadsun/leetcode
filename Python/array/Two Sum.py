class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        tmp = {}
        for index in range(len(nums)):
            if target-nums[index] in tmp:
                return [tmp[target-nums[index]],index]
            tmp[nums[index]] = index