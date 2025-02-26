class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int> & leftChild, vector<int> & rightChild) 
    {
        //==========================================//
        // Input type:                              //
        //   - int (n-th node)                      //
        //   - vector<int> ref. (leftChild vector)  //
        //   - vector<int> ref. (rightChild vector) //
        // Return type:                             //
        //   - bool (result flag)                   //
        //==========================================//

        /*Initialize*/
        ///// Length of leftChild vector /////
        int len_leftChild = leftChild.size();

        ///// Edge counter vector /////
        vector<int> edge_cnter_vect(n, 0);

        ///// Record queue /////
        queue<int> record_queue;

        ///// Root node /////
        int root_node = (-1);

        ///// Result summary counter /////
        int res_cnter = 0;


        /*Queue-based BFS loop traversal*/
        ///// Step 1: Looped-traversal for filtering doubled-parents node /////
        for (int record_idx = 0; (record_idx < len_leftChild); (record_idx++)) //Whole
        {
            int leftChild_node = leftChild[record_idx]; int rightChild_node = rightChild[record_idx]; //Left, Right-child node

            ///// Check if the next node's parents is more than 1 or not /////
            if ((leftChild_node != (-1)) && ((++edge_cnter_vect[leftChild_node]) > 1)) { return false; }
            else { ; }

            if ((rightChild_node != (-1)) && ((++edge_cnter_vect[rightChild_node]) > 1)) { return false; }
            else { ; }

        } //Whole

        ///// Step 2: Looped-traversal for filtering double-root status /////
        for (int n_idx = 0; (n_idx < n); (n_idx++)) //N-th
        {
            ///// Check if the current node is root or not /////
            if (edge_cnter_vect[n_idx]) { continue; }

            ///// Check if the it has more than 1 root or not /////
            if (root_node != (-1)) { return false; }

            root_node = n_idx; //Keep updating, overwriting

        } //N-th

        ///// Step 3: Looped-traversal for the final graph, tree /////
        if (root_node == (-1)) { return false; } //Issue, Boundary-case handling

        record_queue.emplace(root_node); //Update, Record

        while (! record_queue.empty()) //Whole
        {
            for (int queue_idx = record_queue.size(); (queue_idx > 0); (queue_idx--)) //Queue-size
            {
                int record_node = record_queue.front(); record_queue.pop(); //Record node

                (res_cnter++); //Keep updating, accumulating

                ///// Check if the next left-node existed or not /////
                if (leftChild[record_node] != (-1)) { record_queue.emplace(leftChild[record_node]); } //Keep updating, recording
                else { ; }

                ///// Check if the next right-node existed or not /////
                if (rightChild[record_node] != (-1)) { record_queue.emplace(rightChild[record_node]); } //Keep updating, recording
                else { ; }

            } //Queue-size

        } //Whole

        return (res_cnter == n) ? true : false;
    }
};
