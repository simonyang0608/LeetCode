class Solution {
public:
    int robotSim(vector<int> & commands, vector<vector<int>> & obstacles) 
    {
        //=================================================//
        // Input type:                                     //
        //   - vector<int> ref. (commands vector)          //
        //   - vector<vector<int>> ref. (obstacles vector) //
        // Return type:                                    //
        //   - int (result maximun distance)               //
        //=================================================//

        /*Initialize*/
        ///// Length of commands vector /////
        int len_commands = commands.size();

        ///// Record char /////
        char record_direc = 'n';

        ///// Record set /////
        set<vector<int>> record_set(obstacles.begin(), obstacles.end());

        ///// Record vector /////
        vector<int> record_vect(2, 0);

        ///// Result maximun distance /////
        int res_max_sum = 0;


        /*Hashset-based loop traversal*/
        for (int commands_idx = 0; (commands_idx < len_commands); (commands_idx++)) //Whole
        {
            ///// Check if the current command matched conditions or not /////
            if (commands[commands_idx] == (-2))
            {
                ///// Check if the current directions matched conditions or not /////
                if (record_direc == 'n') { record_direc = 'w'; continue; }

                else if (record_direc == 's') { record_direc = 'e'; continue; }
                else if (record_direc == 'w') { record_direc = 's'; continue; }
                else if (record_direc == 'e') { record_direc = 'n'; continue; }
            }

            else if (commands[commands_idx] == (-1))
            {
                ///// Check if the current directions matched conditions or not /////
                if (record_direc == 'n') { record_direc = 'e'; continue; }

                else if (record_direc == 's') { record_direc = 'w'; continue; }
                else if (record_direc == 'w') { record_direc = 'n'; continue; }
                else if (record_direc == 'e') { record_direc = 's'; continue; }
            }

            else
            {
                ///// Check if the current directions matched conditions or not /////
                if (record_direc == 'n')
                {
                    for (int steps = 0; (steps < commands[commands_idx]); (steps++)) //Steps
                    {
                        ((record_vect[1])++); //Keep updating, traversing

                        ///// Check if the current position existed or not /////
                        if (record_set.find(record_vect) != record_set.end()) { record_vect[1] -= 1; break; }

                    } //Steps
                }

                else if (record_direc == 's') 
                {
                    for (int steps = 0; (steps < commands[commands_idx]); (steps++)) //Steps
                    {
                        ((record_vect[1])--); //Keep updating, traversing

                        ///// Check if the current position existed or not /////
                        if (record_set.find(record_vect) != record_set.end()) { record_vect[1] += 1; break; }

                    } //Steps
                }

                else if (record_direc == 'w')
                {
                    for (int steps = 0; (steps < commands[commands_idx]); (steps++)) //Steps
                    {
                        ((record_vect[0])--); //Keep updating, traversing

                        ///// Check if the current position existed or not /////
                        if (record_set.find(record_vect) != record_set.end()) { record_vect[0] += 1; break; }

                    } //Steps
                }

                else if (record_direc == 'e')
                {
                    for (int steps = 0; (steps < commands[commands_idx]); (steps++)) //Steps
                    {
                        ((record_vect[0])++); //Keep updating, traversing

                        ///// Check if the current position existed or not /////
                        if (record_set.find(record_vect) != record_set.end()) { record_vect[0] -= 1; break; }

                    } //Steps
                }
            }

            res_max_sum = max(res_max_sum, (record_vect[0] * record_vect[0]) + (record_vect[1] * record_vect[1])); //Keep updating, overwriting

        } //Whole

        return res_max_sum;
    }
};
