class Solution(object):
    def findDifferentBinaryString(self, nums):
        ans = []
        n = len(nums[0])
        
        def solve(i, path):
            if i == 0:
                if path not in nums:
                    ans.append(path)
                return
            
            # Change 'i' here to 'char' so it doesn't break the recursion logic
            for char in ["0", "1"]:
                if ans: return # Optimization: stop if we found one
                solve(i - 1, path + char)

        solve(n, "")
        return ans[0]
