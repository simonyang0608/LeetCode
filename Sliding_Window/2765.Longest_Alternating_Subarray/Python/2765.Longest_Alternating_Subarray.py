class Solution(object):
    def alternatingSubarray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        #=======================================#
        # Sliding-window based traversal method #
        #=======================================#

        ############
        #Initialize
        ##### Length of nums array #####
        len_nums = len(nums)

        ##### Record char #####
        record_chr = 'n'

        ##### Record traversal pointer #####
        record_trav_ptr = 0

        ##### Record summary counter #####
        record_cnter = 0

        ##### Result maximun summary counter #####
        res_max_cnter = 0


        #####################################
        #Sliding-window based loop traversal
        while (record_trav_ptr < len_nums):

            ##### Check if the next indexed-pointer exceed boundary or not #####
            if ((record_trav_ptr + 1) < len_nums):

                ##### Check if the current, next indexed-value matched conditions or not #####
                if (nums[record_trav_ptr] == (nums[(record_trav_ptr + 1)] + 1)):

                    ##### Check if the previous char matched conditions or not #####
                    if ((record_chr == 'n') or (record_chr == 'd')):

                        ##### Check if the current summary counter matched conditions or not #####
                        if (record_cnter):
                            record_cnter &= 0 #Keep updating/reset
                        else:
                            pass

                        ##### Check if the current char matched conditions or not #####
                        if (record_chr == 'd'):
                            record_chr = 'n' #Keep updating/overwriting
                        else:
                            pass
                    else:
                        record_cnter += 1 #Keep updating/accumulating

                        record_chr = 'd' #Keep updating/overwriting

                elif ((nums[record_trav_ptr] + 1) == nums[(record_trav_ptr + 1)]):

                    ##### Check if the previous char matched conditions or not #####
                    if ((record_chr == 'n') or (record_chr == 'i')):

                        ##### Check if the current summary counter matched conditions or not #####
                        if (record_cnter != 2):
                            record_cnter = 2 #Keep updating/reset
                        else:
                            pass

                        ##### Check if the current char matched conditions or not #####
                        if (record_chr == 'n'):
                            record_chr = 'i' #Keep updating/overwriting
                        else:
                            pass
                    else:
                        record_cnter += 1 #Keep updating/accumulating

                        record_chr = 'i' #Keep updating/overwriting
                else:
                    ##### Check if the current summary counter matched conditions or not #####
                    if (record_cnter):
                        record_cnter &= 0 #Keep updating/reset

                        record_chr = 'n' #Keep updating/overwriting
                    else:
                        pass
            else:
                pass

            res_max_cnter = max(res_max_cnter, record_cnter) #Keep updating/overwriting

            record_trav_ptr += 1 #Keep updating/traversing

        return ((-1) if (not res_max_cnter) else res_max_cnter)
