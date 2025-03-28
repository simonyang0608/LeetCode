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
class BSTIterator 
{
    /*Initialize*/
    ///// Total length /////
    int total_length;

    ///// Record traversal pointer /////
    int record_trav_ptr;

    ///// Record vector /////
    vector<int> record_vect;


public:
    BSTIterator(TreeNode * root) 
    {
        //=================================//
        // Input type:                     //
        //   - TreeNode * (root tree-node) //
        // Return type:                    //
        //   - void (no return)            //
        //=================================//

        /*Whole process, flow*/
        (this->inorderTraversal)(root, (this->record_vect)); //Iterative function call

        (this->total_length) = (this->record_vect).size(); //Update, Overwrite
        (this->record_trav_ptr) = 0; //Update, Overwrite
    }
    

    int next() 
    {
        //======================//
        // Input type:          //
        //   - void (no input)  //
        // Return type:         //
        //   - void (no return) //
        //======================//

        /*Whole process, flow*/
        if ((this->record_trav_ptr) >= total_length) { return (-1); } //Issue, Boundary-case handling

        return (this->record_vect)[((this->record_trav_ptr)++)];
    }
    

    bool hasNext() 
    {
        //======================//
        // Input type:          //
        //   - void (no input)  //
        // Return type:         //
        //   - void (no return) //
        //======================//

        /*Whole process, flow*/
        if ((this->record_trav_ptr) >= total_length) { return false; } //Issue, Boundary-case handling

        return true;
    }


    void inorderTraversal(TreeNode * root, vector<int> & record_vect)
    {
        //======================================//
        // Input type:                          //
        //   - TreeNode * (root tree-node)      //
        //   - vector<int> ref. (record vector) //
        // Return type:                         //
        //   - void (no return)                 //
        //======================================//

        /*Initialize*/
        ///// Record stack /////
        stack<TreeNode * > record_stack;

        /*Whole process, flow*/
        while ((root != nullptr) || (! record_stack.empty())) //Whole
        {
            while (root != nullptr) //Part
            {
                record_stack.emplace(root); //Keep updating, recording

                root = (root->left); //Keep updating, overwriting

            } //Part

            TreeNode * left_most_node = record_stack.top(); record_stack.pop(); //Keep updating, popped

            record_vect.emplace_back((left_most_node->val)); //Keep updating, recording

            root = (left_most_node->right); //Keep updating, overwriting

        } //Whole
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
