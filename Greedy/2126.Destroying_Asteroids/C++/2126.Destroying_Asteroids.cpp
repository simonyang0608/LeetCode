class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int> & asteroids) 
    {
        //=========================================//
        // Input type:                             //
        //   - int (mass value)                    //
        //   - vector<int> ref. (asteroids vector) //
        // Return type:                            //
        //   - bool (result flag)                  //
        //=========================================//

        /*Initialize*/
        ///// Length of asteroids vector /////
        int len_asteroids = asteroids.size();

        ///// Record vector /////
        vector<long long> record_vect;


        /*Greedy-based loop traversal*/
        sort(asteroids.begin(), asteroids.end()); //Sorted operations

        record_vect.emplace_back(mass); //Update, Record

        for (int asteroids_idx = 0; (asteroids_idx < len_asteroids); (asteroids_idx++)) //Whole
        {
            ///// Check if the current indexed-value matched conditions or not /////
            if (asteroids[asteroids_idx] > record_vect.back()) { return false; }

            record_vect.emplace_back((record_vect.back() + asteroids[asteroids_idx])); //Keep updating, recording

        } //Whole

        return true;
    }
};
