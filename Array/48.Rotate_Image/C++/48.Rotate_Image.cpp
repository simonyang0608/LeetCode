class Solution {
public:
    void rotate(vector<vector<int>> & matrix) 
    {
        //==============================================//
        // Input type:                                  //
        //   - vector<vector<int>> ref. (matrix vector) //
        // Return type:                                 //
        //   - void (no return)                         //
        //==============================================//

        /*Initialize*/
        ///// Length of edge /////
        int len_edge = matrix.size();

        ///// Record two-pointers (i.e. left, right) /////
        int record_left_ptr = 0, record_right_ptr = (len_edge - 1);


        /*Two-pointers based loop traversal*/
        while (record_left_ptr <= record_right_ptr) //Two-pointers
        {
            rotateEdge(matrix, len_edge, record_left_ptr, record_right_ptr); //Rotation function call

            (record_left_ptr++); (record_right_ptr--); //Keep updating, traversing

        } //Two-pointers
    }


    void rotateEdge(vector<vector<int>> & matrix, int & len_edge, int & record_left_ptr, int & record_right_ptr)
    {
        //==============================================//
        // Input type:                                  //
        //   - vector<vector<int>> ref. (matrix vector) //
        //   - int ref. (length of edge)                //
        //   - int ref. (record left-pointer)           //
        //   - int ref. (record right pointer)          //
        // Return type:                                 //
        //   - void (no return)                         //
        //==============================================//

        /*Initialize*/
        ///// Record vector /////
        vector<int> record_vect((matrix[record_left_ptr]).begin(), (matrix[record_left_ptr]).end());

        /*Whole process, flow*/
        for (int left_idx = 0; (left_idx < (record_right_ptr - record_left_ptr)); (left_idx++)) //Left-sider
        {
            (matrix[record_left_ptr])[(record_left_ptr + left_idx)] = (matrix[(record_right_ptr - left_idx)])[record_left_ptr]; //Keep updating, overwriting

        } //Left-sider

        for (int down_idx = record_right_ptr; (down_idx > record_left_ptr); (down_idx--)) //Down-sider
        {
            (matrix[down_idx])[record_left_ptr] = (matrix[record_right_ptr])[down_idx]; //Keep updating, overwriting

        } //Down-sider

        for (int right_idx = 0; (right_idx < (record_right_ptr - record_left_ptr)); (right_idx++)) //Right-sider
        {
            (matrix[record_right_ptr])[(record_right_ptr - right_idx)] = (matrix[(record_left_ptr + right_idx)])[record_right_ptr]; //Keep updating, overwriting

        } //Right-sider

        for (int up_idx = record_left_ptr; (up_idx < record_right_ptr); (up_idx++)) //Up-sider
        {
            (matrix[up_idx])[record_right_ptr] = record_vect[up_idx]; //Keep updating, overwriting

        } //Up-sider
    }
};
