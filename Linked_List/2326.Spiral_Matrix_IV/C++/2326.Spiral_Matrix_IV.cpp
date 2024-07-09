/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) 
    {
        vector<int> col_val_array;
        col_val_array.assign(n, -1);
        
        vector<vector<int>> res_array;
        res_array.assign(m, col_val_array);
        
        int top = 0;
        int bottom = m;
        int left = 0;
        int right = n;
        
        int direction = 0;
        
        while ((top < bottom) && (left < right))
        {
            if (direction == 0)
            {
                for (int top_col_idx = left; top_col_idx < right; top_col_idx++)
                {
                    if (head)
                    {
                        res_array[top][top_col_idx] = head->val;
                        head = head->next;
                    }
                }
                top += 1;
            }
            
            else if (direction == 1)
            {
                for (int right_row_idx = top; right_row_idx < bottom; right_row_idx++)
                {
                    if (head)
                    {
                        res_array[right_row_idx][right-1] = head->val;
                        head = head->next;
                    }
                }
                right -= 1;
            }
            
            else if (direction == 2)
            {
                for (int bottom_col_idx = right-1; bottom_col_idx > left-1; bottom_col_idx--)
                {
                    if (head)
                    {
                        res_array[bottom-1][bottom_col_idx] = head->val;
                        head = head->next;
                    }
                }
                bottom -= 1;
            }
            
            else if (direction == 3)
            {
                for (int left_row_idx = bottom-1; left_row_idx > top-1; left_row_idx--)
                {
                    if (head)
                    {
                        res_array[left_row_idx][left] = head->val;
                        head = head->next;
                    }
                }
                left += 1;
            }
            
            direction = (direction+1) % 4;
        }
        
        return res_array;
    }
};
