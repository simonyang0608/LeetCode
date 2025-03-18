class Solution {
public:
    vector<bool> kidsWithCandies(vector<int> & candies, int extraCandies) 
    {
        //=======================================//
        // Input type:                           //
        //   - vector<int> ref. (candies vector) //
        //   - int (extraCandies value)          //
        // Return type:                          //
        //   - vector<bool> (result vector)      //
        //=======================================//

        /*Initialize*/
        ///// Length, Maximun of candies vector /////
        int len_candies = candies.size(), max_candies = *max_element(candies.begin(), candies.end());

        ///// Result vector /////
        vector<bool> res_vect(len_candies, false);


        /*One-pass update based loop traversal*/
        for (int candies_idx = 0; (candies_idx < len_candies); (candies_idx++)) //Whole
        {
            ///// Check if the current summary value matched conditions or not /////
            if ((candies[candies_idx] + extraCandies) >= max_candies) { res_vect[candies_idx] = true; } //Keep updating, overwriting
            else { ; }

        } //Whole

        return res_vect;
    }
};
