class Solution {
public:
    vector<int> asteroidCollision(vector<int> & asteroids) 
    {
        //=========================================//
        // Input type:                             //
        //   - vector<int> ref. (asteroids vector) //
        // Return type:                            //
        //   - vector<int> (result vector)         //
        //=========================================//

        /*Initialize*/
        ///// Length of asteroids vector /////
        int len_asteroids = asteroids.size();

        ///// Result vector /////
        vector<int> res_vect;


        /*Stack-based loop traversal*/
        for (int record_idx = 0; (record_idx < len_asteroids); (record_idx++)) //Whole
        {
            int record_val = asteroids[record_idx]; //Record value

            ///// Check if the current value is less than 0 or not /////
            if (record_val > 0) { res_vect.emplace_back(record_val); } //Keep updating, recording

            else if (((res_vect.empty()) || (res_vect.back() < 0))) { res_vect.emplace_back(record_val); } //Keep updating, recording

            else if ((res_vect.back() > 0) && ((record_val * (-1)) >= res_vect.back()))
            {
                ///// Check if the current value matched conditions or not /////
                if ((record_val * (-1)) == res_vect.back()) { ; }
                else { (record_idx--); } //Keep updating, traversing

                res_vect.pop_back(); //Keep updating, popped
            }

        } //Whole

        return res_vect;
    }
};
