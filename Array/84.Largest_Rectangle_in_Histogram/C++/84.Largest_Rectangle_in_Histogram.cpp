class Solution {
public:
    int largestRectangleArea(vector<int> & heights) 
    {
        //=======================================//
        // Input type:                           //
        //   - vector<int> ref. (heights vector) //
        // Return type:                          //
        //   - int (result maximun area)         //
        //=======================================//

        /*Initialize*/
        ///// Length of heights vector /////
        int len_heights = heights.size();

        ///// Record stack /////
        stack<int> record_stack;

        ///// Result maximun area /////
        int res_max_area = 0;


        /*Stack-based loop traversal*/
        heights.emplace_back((-1)); //Update, Record

        for (int heights_idx = 0; (heights_idx <= len_heights); (heights_idx++)) //Whole
        {
            while ((! record_stack.empty()) && (heights[heights_idx] <= heights[record_stack.top()])) //Part
            {
                int record_idx = record_stack.top(); record_stack.pop(); //Keep updating, popped

                res_max_area = max(res_max_area, (heights[record_idx] * ((record_stack.empty()) ? heights_idx : (heights_idx - record_stack.top() - 1)))); //Keep updating, overwriting

            } //Part

            record_stack.emplace(heights_idx); //Keep updating, recording

        } //Whole

        return res_max_area;
    }
};
