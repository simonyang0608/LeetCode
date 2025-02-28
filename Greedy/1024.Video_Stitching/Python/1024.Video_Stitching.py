class Solution(object):
    def videoStitching(self, clips, time):
        """
        :type clips: List[List[int]]
        :type time: int
        :rtype: int
        """
        #===============================#
        # Greedy-based traversal method #
        #===============================#

        ############
        #Initialize
        ##### Length of clips array #####
        len_clips = len(clips)

        ##### Record start #####
        record_start = 0

        ##### Record traversal pointer #####
        record_trav_ptr = 0

        ##### Result maximun value #####
        res_max_val = 0

        ##### Result summary counter #####
        res_cnter = 0


        #############################
        #Greedy-based loop traversal
        clips.sort() #Sorted operations

        while (record_start < time):
            while ((record_trav_ptr < len_clips) and (record_start >= (clips[record_trav_ptr])[0])):
                res_max_val = max(res_max_val, (clips[record_trav_ptr])[1]) #Result maximun value

                record_trav_ptr += 1 #Keep updating/traversing

            ##### Check if the current start-value matched conditions or not #####
            if (record_start >= res_max_val):
                return (-1)

            record_start = res_max_val #Keep updating/overwriting

            res_cnter += 1 #Keep updating/accumulating

        return (res_cnter if (record_start >= time) else (-1))
