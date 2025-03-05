class Solution {
public:
    int smallestEvenMultiple(int n) 
    {
        //========================//
        // Input type:            //
        //   - int (n-th value)   //
        // Return type:           //
        //   - int (result value) //
        //========================//

        /*Math-GCD based method*/
        
        return ((n % 2)) ? (n * 2) : n;
    }
};
