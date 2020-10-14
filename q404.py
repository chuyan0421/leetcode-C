from collections import deque
# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None



class Solution(object):
    def sumOfLeftLeaves(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """

        if root is None:
            return 0

        q = deque()
        result = 0
        temp = root
        while(True):

            if(temp.right is not None):
                q.append(temp.right)

            # if(temp.left is not None):
            #     q.append(temp.left)
            
            if (temp.left is not None):
                if ((temp.left.left is None)&(temp.left.right is None)):
                    result += temp.left.val
                else:
                    q.append(temp.left)
            
            if (len(q) == 0):
                break                
            else:
                temp = q.pop()
      
        return result


def main():
    print("hello world")
    t = TreeNode(1)
    t.left = TreeNode(2)
    t.right = TreeNode(3)
    t.left.left = TreeNode(4)
    t.left.right = TreeNode(5)
    # t = TreeNode(1)
    # t.right = 2

    s = Solution()
    sum = s.sumOfLeftLeaves(t)
    print("result {}".format(sum))


if __name__ == "__main__":
    main()


