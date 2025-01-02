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
    bool isSubPath(ListNode * head, TreeNode * root)
    {
        //=================================//
        // Input type:                     //
        //   - ListNode * (head list-node) //
        //   - TreeNode * (root tree-node) //
        // Return type:                    //
        //   - bool (result flag)          //
        //=================================//
        if (! root) { return false; } //Issue, Boundary-case handling

        if (dfsTraversal(head, root)) { return true; } //Resursion function call (top-first root tree-node)

        return (isSubPath(head, (root->left)) || isSubPath(head, (root->right))); //Resursion function call (following root tree-node)
    }


    bool dfsTraversal(ListNode * head, TreeNode * root)
    {
        //=================================//
        // Input type:                     //
        //   - ListNode * (head list-node) //
        //   - TreeNode * (root tree-node) //
        // Return type:                    //
        //   - bool (result flag)          //
        //=================================//
        if (! head) { return true; } //Issue, Boundary-case handling

        if (! root) { return false; } //Issue, Boundary-case handling

        if ((head->val) != (root->val)) { return false; } //Issue, Boundary-case handling

        return (dfsTraversal((head->next), (root->left)) || dfsTraversal((head->next), (root->right))); //Resursion function call (next root tree-node)
    }
};
