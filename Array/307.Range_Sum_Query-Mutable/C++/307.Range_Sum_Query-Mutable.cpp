class NumArray {
public:
    /*Initialize*/
    ///// Record length /////
    int record_length;

    ///// Record nums vector /////
    vector<int> record_nums;

    ///// Record binary-indexed tree vector /////
    vector<int> bit_vect;

public:
    NumArray(vector<int> & nums) 
    {
        //====================================//
        // Input type:                        //
        //   - vector<int> ref. (nums vector) //
        // Return type:                       //
        //   - void (no return)               //
        //====================================//

        /*Initialize*/
        ///// Record length /////
        (this->record_length) = nums.size();

        ///// Record nums vector /////
        (this->record_nums) = vector<int>(nums.begin(), nums.end());

        ///// Record binary-indexed tree vector /////
        (this->bit_vect) = vector<int>(((this->record_length) + 1), 0);

        for (int nums_idx = 0; (nums_idx < (this->record_length)); (nums_idx++)) //Whole
        {
            (this->build_tree)(nums_idx, (this->record_nums)[nums_idx]); //Keep updating, recording

        } //Whole
    }


    void update(int index, int val) 
    {
        //=========================//
        // Input type:             //
        //   - int (vector index)  //
        //   - int (indexed-value) //
        // Return type:            //
        //   - void (no return)    //
        //=========================//

        /*Initialize*/
        ///// Record index /////
        int record_idx = (index + 1);

        ///// Difference value /////
        int diff_val = (val - (this->record_nums)[index]);


        /*Whole process, flow*/
        (this->record_nums)[index] = val; //Update, Overwrite

        while (record_idx <= (this->record_length)) //Whole
        {
            (this->bit_vect)[record_idx] += diff_val; //Keep updating, recording

            record_idx += (this->lsb)(record_idx); //Keep updating, traversing

        } //Whole
    }


    int sumRange(int left, int right) 
    {
        //================================//
        // Input type:                    //
        //   - int (left-half)            //
        //   - int (right-half)           //
        // Return type:                   //
        //   - int (result summary range) //
        //================================//
        if (! left) { return (this->prefix_sum)(right); } //Issue, Boundary-case handling

        return ((this->prefix_sum)(right) - (this->prefix_sum)((left - 1)));
    }


    int prefix_sum(const int & index)
    {
        //===================================//
        // Input type:                       //
        //   - const int ref. (vector index) //
        // Return type:                      //
        //   - int (result summary value)    //
        //===================================//

        /*Initialize*/
        ///// Record index /////
        int record_idx = (index + 1);

        ///// Result summary value /////
        int res_sum_val = 0;


        /*Whole process, flow*/
        while (record_idx > 0) //Whole
        {
            res_sum_val += (this->bit_vect)[record_idx]; //Keep updating, accumulating

            record_idx -= (this->lsb)(record_idx); //Keep updating, traversing

        } //Whole

        return res_sum_val;
    }


    void build_tree(const int & nums_idx, const int & num_val)
    {
        //====================================//
        // Input type:                        //
        //   - const int ref. (vector index)  //
        //   - const int ref. (indexed-value) //
        // Return type:                       //
        //   - void (no return)               //
        //====================================//

        /*Initialize*/
        ///// Record index /////
        int record_idx = (nums_idx + 1);

        /*Whole process, flow*/
        while (record_idx <= (this->record_length)) //Whole
        {
            (this->bit_vect)[record_idx] += num_val; //Keep updating, recording

            record_idx += (this->lsb)(record_idx); //Keep updating, traversing

        } //Whole
    }


    int lsb(const int & record_idx)
    {
        //========================================//
        // Input type:                            //
        //   - const int ref. (vector index)      //
        // Return type:                           //
        //   - int (result least significant bit) //
        //========================================//
      
        return (record_idx & ((~record_idx + 1)));
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
