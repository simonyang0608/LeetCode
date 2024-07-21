class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>> & matrix) 
    {
        //==============================================//
        // Input type:                                  //
        //   - vector<vector<int>> ref. (matrix vector) //
        // Return type:                                 //
        //   - vector<int> (result vector)              //
        //==============================================//

        /*Initialize*/
        ///// Four-pointers directions (i.e top, bottom, left, right) /////
        int top = 0, bottom = (matrix.size() - 1), left = 0, right = ((matrix[0]).size() - 1);

        ///// Directions /////
        int directions = 0;

        ///// Result vector /////
        vector<int> res_vect;


        /*Four-pointers based loop traversal*/
        while ((left <= right) && (top <= bottom)) //Whole
        {
            ///// Check the current directions (i.e. top, bottom, left, right) /////
            if (directions == 0) //Left-Right
            {
                for (int left_right_ptr = left; (left_right_ptr <= right); (left_right_ptr++)) //Whole
                {
                    res_vect.push_back((matrix[top])[left_right_ptr]); //Keep appending, recording

                } //Whole

                (top++); //Keep accumulating
            }

            else if (directions == 1) //Top-Bottom
            {
                for (int top_bottom_ptr = top; (top_bottom_ptr <= bottom); (top_bottom_ptr++)) //Whole
                {
                    res_vect.push_back((matrix[top_bottom_ptr])[right]); //Keep appending, recording

                } //Whole

                (right--); //Keep reducing
            }

            else if (directions == 2) //Right-Left
            {
                for (int right_left_ptr = right; (right_left_ptr >= left); (right_left_ptr--)) //Whole
                {
                    res_vect.push_back((matrix[bottom])[right_left_ptr]); //Keep appending, recording

                } //Whole

                (bottom--); //Keep reducing
            }

            else if (directions == 3) //Bottom-Top
            {
                for (int bottom_top_ptr = bottom; (bottom_top_ptr >= top); (bottom_top_ptr--)) //Whole
                {
                    res_vect.push_back((matrix[bottom_top_ptr])[left]); //Keep appending, recording

                } //Whole

                (left++); //Keep accumulating
            }

            directions = ((directions + 1) % 4); //Keep traversing

        } //Whole

        return res_vect;
    }
};
