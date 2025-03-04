class Solution {
public:
    int countCollisions(string directions) 
    {
        //==================================//
        // Input type:                      //
        //   - string (directions string)   //
        // Return type:                     //
        //   - int (result summary counter) //
        //==================================//

        /*Initialize*/
        ///// Length of directions string /////
        int len_directions = directions.size();

        ///// Record stack /////
        stack<char> record_stack;

        ///// Result summary counter /////
        int res_cnter = 0;


        /*Stack-based loop traversal*/
        for (int directions_idx = 0; (directions_idx < len_directions); (directions_idx++)) //Whole
        {
            char record_chr = directions[directions_idx]; //Record char

            ///// Check if the current char's directions (i.e. left, right, static) /////
            if (record_chr == 'L')
            {
                ///// Check the previous directions informations /////
                if ((! record_stack.empty()) && (record_stack.top() == 'S')) { (res_cnter++); } //Keep updating, accumulating

                else if ((! record_stack.empty()) && (record_stack.top() == 'R'))
                {
                    res_cnter += 2; record_stack.pop(); //Keep updating, popped

                    while ((! record_stack.empty()) && (record_stack.top() == 'R')) //Part
                    {
                        (res_cnter++); record_stack.pop(); //Keep updating, popped

                    } //Part

                    record_stack.emplace('S'); //Keep updating, recording
                }
                else { ; }
            }

            else if (record_chr == 'S')
            {
                while ((! record_stack.empty()) && (record_stack.top() == 'R')) //Part
                {
                    (res_cnter++); record_stack.pop(); //Keep updating, popped

                } //Part

                record_stack.emplace(record_chr); //Keep updating, recording
            }

            else { record_stack.emplace(record_chr); } //Keep updating, recording

        } //Whole

        return res_cnter;
    }
};
