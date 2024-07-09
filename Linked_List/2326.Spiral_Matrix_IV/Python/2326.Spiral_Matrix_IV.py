# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def spiralMatrix(self, m, n, head):
        """
        :type m: int
        :type n: int
        :type head: Optional[ListNode]
        :rtype: List[List[int]]
        """
        res_mat = [[-2 for col_idx in range(n)] for row_idx in range(m)]
        
        top, bottom = 0, m
        left, right = 0, n
        
        direction = 0
        
        while ((top < bottom) and (left < right)):
            if (direction == 0):
                for top_col_idx in range(left, right):
                    if (head):
                        res_mat[top][top_col_idx] = head.val
                        head = head.next
                    else:
                        res_mat[top][top_col_idx] = -1
                top += 1
                    
            elif (direction == 1):
                for right_row_idx in range(top, bottom):
                    if (head):
                        res_mat[right_row_idx][right-1] = head.val
                        head = head.next
                    else:
                        res_mat[right_row_idx][right-1] = -1
                right -= 1
                
            elif (direction == 2):
                for bottom_col_idx in range(right-1, left-1, -1):
                    if (head):
                        res_mat[bottom-1][bottom_col_idx] = head.val
                        head = head.next
                    else:
                        res_mat[bottom-1][bottom_col_idx] = -1
                bottom -= 1
            
            elif (direction == 3):
                for left_row_idx in range(bottom-1, top-1, -1):
                    if (head):
                        res_mat[left_row_idx][left] = head.val
                        head = head.next
                    else:
                        res_mat[left_row_idx][left] = -1
                left += 1
                
            direction = (direction+1) % 4
            
        return res_mat
