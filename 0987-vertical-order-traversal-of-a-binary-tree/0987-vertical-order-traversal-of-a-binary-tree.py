class Solution(object):

    def __init__(self):
        self.map = {}

    def dfs(self, root, row, col):
        if not root:
            return

        if col not in self.map:
            self.map[col] = []

        self.map[col].append((row, root.val))

        self.dfs(root.left, row + 1, col - 1)
        self.dfs(root.right, row + 1, col + 1)

    def verticalTraversal(self, root):
        self.dfs(root, 0, 0)

        ans = []

        for col in sorted(self.map):
            # sort by row, then value
            temp = sorted(self.map[col])
            ans.append([val for row, val in temp])

        return ans