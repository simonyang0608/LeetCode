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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    ListNode * find_middle(ListNode * head)
    {
        //==============================================//
        // Input type:                                  //
        //   - ListNode * (head node)                   //
        // Return type:                                 //
        //   - ListNode * (result previous middle node) //
        //==============================================//

        /*Initialize*/
        ///// Three-pointers (i.e. previous middle, slow, fast) /////
        ListNode * prev_middle, * slow, * fast = head;
        slow = fast;

        /*Three-pointers based loop traversal*/
        while (fast && (fast->next)) //Whole
        {
            prev_middle = slow; //Previous middle node

            slow = (slow->next); //Keep updating, overwriting
            fast = ((fast->next)->next); //Keep updating, overwriting

        } //Whole

        return prev_middle;
    }


    TreeNode * sortedListToBST(ListNode * head)
    {
        //===================================//
        // Input type:                       //
        //   - ListNode * (head node)        //
        // Return type:                      //
        //   - TreeNode * (result root node) //
        //===================================//
        if (! head) { return NULL; } //Issue, Boundary-case handling

        if (! (head->next)) { return new TreeNode((head->val)); } //Issue, Boundary-case handling


        /*Initialize*/
        ///// Record list-nodes (i.e. previous middle, right-half head) /////
        ListNode * prev_middle, * right_half_head;

        ///// Result tree-nodes (i.e. root) /////
        TreeNode * root;


        /*Recursion-based in-place pointers loop traversal*/
        ///// Step 1: Find previous middle, middle node /////
        prev_middle = find_middle(head); //Previous middle node

        root = new TreeNode(((prev_middle->next)->val)); //Root node

        right_half_head = ((prev_middle->next)->next); //Right-half head node

        (prev_middle->next) = NULL; //Left-half head node

        ///// Step 2: Looped-traversal /////
        (root->left) = sortedListToBST(head); //Recursion function call (i.e. root left-half node)
        (root->right) = sortedListToBST(right_half_head); //Recursion function call (i.e. root right-half node)

        return root;
    }
};
