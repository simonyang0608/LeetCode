class Solution {
public:
    vector<string> findAllRecipes(vector<string> & recipes, vector<vector<string>> & ingredients, vector<string> & supplies) 
    {
        //======================================================//
        // Input type:                                          //
        //   - vector<string> ref. (recipes vector)             //
        //   - vector<vector<string>> ref. (ingredients vector) //
        //   - vector<string> ref. (supplies vector)            //
        // Return type:                                         //
        //   - vector<string> (result vector)                   //
        //======================================================//

        /*Initialize*/
        ///// Length of total, supplies vector /////
        int len_total = recipes.size(), len_supplies = supplies.size();

        ///// Root-child dictionary, hashmap /////
        unordered_map<string, vector<string>> root_child_map;

        ///// Edge-rank dictionary, hashmap /////
        unordered_map<string, int> edge_rank_map;

        ///// Record queue /////
        queue<string> record_queue;

        ///// Result vector /////
        vector<string> res_vect;


        /*Breath-first search based loop traversal with recorded dictionary, hashmap*/
        ///// Step 1: Record indexed-nodes informations with dictionary, hashmap /////
        for (int total_idx = 0; (total_idx < len_total); (total_idx++)) //Whole
        {
            int len_ingele = (ingredients[total_idx]).size(); //Length of ingredient elements

            for (int sub_idx = 0; (sub_idx < len_ingele); (sub_idx++)) //Part
            {
                (root_child_map[(ingredients[total_idx])[sub_idx]]).emplace_back(recipes[total_idx]); //Keep updating, recording

                ((edge_rank_map[recipes[total_idx]])++); //Keep updating, accumulating

            } //Part

        } //Whole

        ///// Step 2: Looped-traversal with recorded dictionary, hashmap /////
        for (int supplies_idx = 0; (supplies_idx < len_supplies); (supplies_idx++)) //Whole
        {
            record_queue.emplace(supplies[supplies_idx]); //Keep updating, recording

        } //Whole

        while (! record_queue.empty()) //Cycled-times
        {
            for (int queue_idx = record_queue.size(); (queue_idx > 0); (queue_idx--)) //Queue-size
            {
                string record_str = record_queue.front(); record_queue.pop(); //Record string

                for (string & next_str: root_child_map[record_str]) //Next-string
                {
                    ///// Check if the current summary counter matched conditions or not /////
                    if (! (--(edge_rank_map[next_str])))
                    {
                        res_vect.emplace_back(next_str); //Keep updating, recording

                        record_queue.emplace(next_str); //Keep updating, recording
                    }
                    else { ; }

                } //Next-string

            } //Queue-size

        } //Cycled-times

        return res_vect;
    }
};
