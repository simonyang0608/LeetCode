class TopVotedCandidate(object):
    def __init__(self, persons, times):
        """
        :type persons: List[int]
        :type times: List[int]
        """

        ############
        #Initialize
        ##### Record , Lead arrays #####
        self.lead_arry, self.record_arry = [persons[0]], times[:]

        ####################
        #Whole process/flow
        record_dict = {persons[0]: 1} #Record dictionary/hashmap

        record_max_val = 1 #Record maximun value

        total_length = len(persons) #Total length

        for persons_idx in range(1, total_length):
            (self.lead_arry).append((self.lead_arry)[(-1)]) #Keep updating/recording

            ##### Check if the current person-id existed or not #####
            if (persons[persons_idx] not in record_dict):
                record_dict[persons[persons_idx]] = 1 #Keep updating/recording
            else:
                record_dict[persons[persons_idx]] += 1 #Keep updating/recording

            ##### Check if the current summary counter matched conditions or not #####
            if (record_dict[persons[persons_idx]] >= record_max_val):
                record_max_val = record_dict[persons[persons_idx]] #Keep updating/overwriting

                (self.lead_arry)[(-1)] = persons[persons_idx] #Keep updating/overwriting
            else:
                pass


    def q(self, t):
        """
        :type t: int
        :rtype: int
        """

        ############
        #Initialize
        ##### Record pointers (i.e. left, right) #####
        record_left_ptr, record_right_ptr = 0, (len(self.record_arry) - 1)

        ####################
        #Whole process/flow
        while (record_left_ptr < record_right_ptr):
            record_mid_ptr = ((record_left_ptr + record_right_ptr + 1) // 2) #Record middle pointer

            ##### Check if the current times boundary matched conditions or not #####
            if ((self.record_arry)[record_mid_ptr] > t):
                record_right_ptr = (record_mid_ptr - 1) #Keep updating/overwriting
            else:
                record_left_ptr = record_mid_ptr #Keep updating/overwriting

        return (self.lead_arry)[record_left_ptr]


# Your TopVotedCandidate object will be instantiated and called as such:
# obj = TopVotedCandidate(persons, times)
# param_1 = obj.q(t)
