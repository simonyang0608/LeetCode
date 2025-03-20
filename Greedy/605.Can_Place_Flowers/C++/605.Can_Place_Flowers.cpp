class Solution {
public:
    bool canPlaceFlowers(vector<int> & flowerbed, int n) 
    {
        //=========================================//
        // Input type:                             //
        //   - vector<int> ref. (flowerbed vector) //
        //   - int (n-th flowers)                  //
        // Return type:                            //
        //   - bool (result flag)                  //
        //=========================================//

        /*Initialize*/
        ///// Length of flowerbed vector /////
        int len_flowerbed = flowerbed.size();

        /*Greedy-based loop traversal*/
        if (len_flowerbed <= 1) //Issue, Boundary-case handling
        {
            if (flowerbed[0])
            {
                if (n <= 0) { return true; }

                return false;
            }

            if (n <= 1) { return true; }

            return false;
        }

        ///// Check if the first indexed-value matched conditions or not /////
        if ((! flowerbed[0]) && (! flowerbed[1])) { flowerbed[0] = 1; (n--); } //Update, Overwrite
        else { ; }

        ///// Check if the last indexed-value matched conditions or not /////
        if ((! flowerbed[(len_flowerbed - 1)]) && (! flowerbed[(len_flowerbed - 2)]))
        {
            flowerbed[(len_flowerbed - 1)] = 1; (n--); //Update, Overwrite
        }
        else { ; }

        for (int flowerbed_idx = 1; (flowerbed_idx < (len_flowerbed - 1)); (flowerbed_idx++)) //Whole
        {
            ///// Check if the current indexed-value matched conditions or not /////
            if (flowerbed[flowerbed_idx]) { continue; }
            
            if ((! flowerbed[(flowerbed_idx - 1)]) && (! flowerbed[(flowerbed_idx + 1)]))
            {
                flowerbed[flowerbed_idx] = 1; (n--); //Keep updating, overwriting
            }
            else { ; }

        } //Whole

        return (n <= 0) ? true : false;
    }
};
