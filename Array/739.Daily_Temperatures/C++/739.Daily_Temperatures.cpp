class Solution {
public:
    vector<int> dailyTemperatures(vector<int> & temperatures) 
    {
        //============================================//
        // Input type:                                //
        //   - vector<int> ref. (temperatures vector) //
        // Return type:                               //
        //   - vector<int> (result vector)            //
        //============================================//

        /*Initialize*/
        ///// Length of temperatures vector /////
        int len_temperatures = temperatures.size();

        ///// Record stack /////
        stack<pair<int, int>> record_stack;

        ///// Result vector /////
        vector<int> res_vect(len_temperatures, 0);


        /*Stack-based loop traversal*/
        for (int temperatures_idx = 0; (temperatures_idx < len_temperatures); (temperatures_idx++)) //Whole
        {
            while ((! record_stack.empty()) && ((record_stack.top()).first < temperatures[temperatures_idx])) //Part
            {
                res_vect[(record_stack.top()).second] = (temperatures_idx - (record_stack.top()).second); //Keep updating, overwriting

                record_stack.pop(); //Keep updating, popped

            } //Part

            record_stack.emplace(temperatures[temperatures_idx], temperatures_idx); //Keep updating, recording

        } //Whole

        return res_vect;
    }
};
