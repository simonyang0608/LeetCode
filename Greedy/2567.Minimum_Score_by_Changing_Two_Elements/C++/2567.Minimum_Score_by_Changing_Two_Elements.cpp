class Solution {
public:
    int minimizeSum(vector<int> & nums) 
    {
        //====================================//
        // Input type:                        //
        //   - vector<int> ref. (nums vector) //
        // Return type:                       //
        //   - int (result minimun score)     //
        //====================================//

        /*Initialize*/
        ///// Length of nums vector /////
        int len_nums = nums.size();

        /*Greedy-based loop traversal with sorted-operations*/
        sort(nums.begin(), nums.end()); //Sorted-operations

        int right_most1 = (nums.back() - nums[2]); //Right-most value 1
        int right_most2 = (nums[(len_nums - 2)] - nums[1]); //Right-most value 2
        int right_most3 = (nums[(len_nums - 3)] - nums[0]); //Right-most value 3

        return min(right_most1, min(right_most2, right_most3));
    }
};
