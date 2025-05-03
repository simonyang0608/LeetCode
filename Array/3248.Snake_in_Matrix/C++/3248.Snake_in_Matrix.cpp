class Solution {
public:
    int finalPositionOfSnake(int n, vector<string> & commands) 
    {
        //===========================================//
        // Input type:                               //
        //   - int (n-th length)                     //
        //   - vector<string> ref. (commands vector) //
        // Return type:                              //
        //   - int (result position value)           //
        //===========================================//

        /*Initialize*/
        ///// Length of commands vector /////
        int len_commands = commands.size();

        ///// Record directions (i.e. right, down) /////
        int record_right = 0, record_down = 0;


        /*One-pass update based loop traversal*/
        for (int commands_idx = 0; (commands_idx < len_commands); (commands_idx++)) //Whole
        {
            ///// Check if the current indexed-string is which directions ///// 
            if (commands[commands_idx] == "DOWN") { (record_down++); } //Keep updating, traversing

            else if (commands[commands_idx] == "UP") { (record_down--); } //Keep updating, traversing

            else if (commands[commands_idx] == "RIGHT") { (record_right++); } //Keep updating, traversing

            else if (commands[commands_idx] == "LEFT") { (record_right--); } //Keep updating, traversing

        } //Whole

        return ((n * record_down) + record_right);
    }
};
