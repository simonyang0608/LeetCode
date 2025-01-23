class trieNode(object):
    def __init__(self):
        """
        :type: None
        :rtype: None
        """
        ############
        #Initialize
        ##### Record dictionary/hashmap #####
        self.record_dict = {}

        ##### Is-terminal flag #####
        self.is_terminal = False


class Trie(object):
    def __init__(self):
        """
        :type: None
        :rtype: None
        """
        ############
        #Initialize
        ##### Main trie-node #####
        self.main_trieNode = trieNode()


    def insert(self, word):
        """
        :type word: str
        :rtype: None
        """
        ############
        #Initialize
        ##### Sub trie-node #####
        sub_trieNode = self.main_trieNode

        ##### Length of word string #####
        len_word = len(word)


        ####################
        #Whole process/flow
        for word_idx in range(len_word):

            ##### Check if the current indexed-char existed or not #####
            if (word[word_idx] not in sub_trieNode.record_dict):
                ((sub_trieNode.record_dict)[word[word_idx]]) = trieNode() #Keep updating/recording
            else:
                pass

            sub_trieNode = (sub_trieNode.record_dict)[word[word_idx]] #Keep updating/overwriting

        sub_trieNode.is_terminal = True #Update/Overwrite


    def search(self, word):
        """
        :type word: str
        :rtype: bool
        """
        ############
        #Initialize
        ##### Sub trie-node #####
        sub_trieNode = self.main_trieNode

        ##### Record traversal pointer, length of word string #####
        record_trav_ptr, len_word = 0, len(word)


        ####################
        #Whole process/flow
        while (record_trav_ptr < len_word):

            ##### Check if the current indexed-char existed or not #####
            if ((word[record_trav_ptr] not in sub_trieNode.record_dict)):
                return False

            sub_trieNode = (sub_trieNode.record_dict)[word[record_trav_ptr]] #Keep updating/overwriting

            record_trav_ptr += 1 #Keep updating/traversing

        ##### Check if the current string existed or not #####
        if ((sub_trieNode.is_terminal)):
            return True

        return False
        

    def startsWith(self, prefix):
        """
        :type prefix: str
        :rtype: bool
        """
        ############
        #Initialize
        ##### Sub trie-node #####
        sub_trieNode = self.main_trieNode

        ##### Record traversal pointer, length of prefix string #####
        record_trav_ptr, len_prefix = 0, len(prefix)


        ####################
        #Whole process/flow
        while (record_trav_ptr < len_prefix):

            ##### Check if the current indexed-char existed or not #####
            if ((prefix[record_trav_ptr] not in sub_trieNode.record_dict)):
                return False

            sub_trieNode = (sub_trieNode.record_dict)[prefix[record_trav_ptr]] #Keep updating/overwriting

            record_trav_ptr += 1 #Keep updating/traversing

        return True


# Your Trie object will be instantiated and called as such:
# obj = Trie()
# obj.insert(word)
# param_2 = obj.search(word)
# param_3 = obj.startsWith(prefix)
