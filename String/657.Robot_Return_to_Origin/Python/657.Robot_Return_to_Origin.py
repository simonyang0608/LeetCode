class Solution(object):
    def judgeCircle(self, moves):
        """
        :type moves: str
        :rtype: bool
        """
        #===============================================#
        # Simple differences & comparisons based method #
        #===============================================#

        ############
        #Initialize
        ##### Length of moves string #####
        len_moves = len(moves)

        ##### Record dictionary/hashmap (i.e. left, right, up, down) #####
        record_dict = {'L': 0, 'R':0, 'U': 0, 'D': 0}


        ########################################################################################
        #Simple differences & comparisons based loop traversal with recorded dictionary/hashmap
        ##### Step 1: Record indexed-char with dictionary/hashmap #####
        for moves_idx in range(len_moves):
            record_dict[moves[moves_idx]] += 1 #Keep updating/recording

        ##### Step 2: Check if the current dictionary matched conditions or not #####
        if ((record_dict['L'] == record_dict['R']) and (record_dict['U'] == record_dict['D'])):
            return True

        return False
