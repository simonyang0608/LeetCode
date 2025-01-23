struct trieNode
{
    /*Initialize*/
    ///// Record dictionary, hashmap /////
    unordered_map<char, shared_ptr<trieNode>> record_map;

    ///// Is-terminal flag /////
    bool is_terminal;

    trieNode()
    {
        //======================//
        // Input type:          //
        //   - void (no input)  //
        // Return type:         //
        //   - void (no return) //
        //======================//

        /*Initialize*/
        ///// Is-terminal flag /////
        (this->is_terminal) = false;
    }

    ~trieNode()
    {
        //======================//
        // Input type:          //
        //   - void (no input)  //
        // Return type:         //
        //   - void (no return) //
        //======================//
        ;
    }
};

class Trie 
{
    /*Initialize*/
    ///// Main trie pointer /////
    shared_ptr<trieNode> main_trie_ptr;

public:
    Trie()
    {
        //======================//
        // Input type:          //
        //   - void (no input)  //
        // Return type:         //
        //   - void (no return) //
        //======================//

        /*Initialize*/
        ///// Main trie pointer /////
        (this->main_trie_ptr) = make_shared<trieNode>(); 
    }
    
    void insert(string word) 
    {
        //==========================//
        // Input type:              //
        //   - string (word string) //
        // Return type:             //
        //   - void (no return)     //
        //==========================//

        /*Initialize*/
        ///// Sub-trie pointer /////
        shared_ptr<trieNode> sub_trie_ptr = (this->main_trie_ptr);

        /*Whole process, flow*/
        for (const char & record_chr: word)
        {
            ///// Check if the current indexed-char existed or not /////
            if ((sub_trie_ptr->record_map)[record_chr] == nullptr) { (sub_trie_ptr->record_map)[record_chr] = make_shared<trieNode>(); } //Keep updating, recording
            else { ; }

            sub_trie_ptr = (sub_trie_ptr->record_map)[record_chr]; //Keep updating, overwriting
        }

        (sub_trie_ptr->is_terminal) = true; //Update, Overwrite
    }
    
    bool search(string word) 
    {
        //==========================//
        // Input type:              //
        //   - string (word string) //
        // Return type:             //
        //   - bool (result flag)   //
        //==========================//

        /*Initialize*/
        ///// Sub-trie pointer /////
        shared_ptr<trieNode> sub_trie_ptr = (this->main_trie_ptr);

        ///// Record traversal pointer, length of word string /////
        int record_trav_ptr = 0, len_word = word.size();


        /*Whole process, flow*/
        while (record_trav_ptr < len_word) //Whole
        {
            ///// Check if the current indexed-char existed or not /////
            if ((sub_trie_ptr->record_map)[word[record_trav_ptr]] == nullptr) { return false; }

            sub_trie_ptr = (sub_trie_ptr->record_map)[word[(record_trav_ptr++)]]; //Keep updating, overwriting

        } //Whole

        ///// Check if the current string existed or not /////
        if ((sub_trie_ptr->is_terminal)) { return true; }

        return false;
    }
    
    bool startsWith(string prefix) 
    {
        //============================//
        // Input type:                //
        //   - string (prefix string) //
        // Return type:               //
        //   - bool (result flag)     //
        //============================//

        /*Initialize*/
        ///// Sub-trie pointer /////
        shared_ptr<trieNode> sub_trie_ptr = (this->main_trie_ptr);

        ///// Record traversal pointer, length of word string /////
        int record_trav_ptr = 0, len_prefix = prefix.size();


        /*Whole process, flow*/
        while (record_trav_ptr < len_prefix) //Whole
        {
            ///// Check if the current indexed-char existed or not /////
            if ((sub_trie_ptr->record_map)[prefix[record_trav_ptr]] == nullptr) { return false; }

            sub_trie_ptr = (sub_trie_ptr->record_map)[prefix[(record_trav_ptr++)]]; //Keep updating, overwriting

        } //Whole

        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
