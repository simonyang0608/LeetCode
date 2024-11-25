class Solution(object):
    def reverseVowels(self, s):
        """
        :type s: str
        :rtype: str
        """
        #=====================================#
        # Two-pointers based traversal method #
        #=====================================#

        ############
        #Initialize
        ##### Record two-pointers (i.e. left, right) #####
        record_left_ptr, record_right_ptr = 0, (len(s) - 1)

        ##### Record s array #####
        record_s = list(s)

        ##### Record dictionary/hashmap #####
        record_dict = {'a': True, 'A': True, 'e': True, 'E': True, 'i': True, 'I': True, 'o': True, 'O': True, 'u': True, 'U': True}


        ####################################################################
        #Two-pointers based loop traversal with recorded dictionary/hashmap
        while (record_left_ptr <= record_right_ptr):

            ##### Check if the current indexed-char matched conditions or not #####
            if (record_s[record_left_ptr] not in record_dict):
                if (record_s[record_right_ptr] not in record_dict):
                    record_right_ptr -= 1 #Keep updating/traversing
                else:
                    pass

                record_left_ptr += 1 #Keep updating/traversing

            else:
                if (record_s[record_right_ptr] not in record_dict):
                    pass
                else:
                    record_s[record_left_ptr], record_s[record_right_ptr] = record_s[record_right_ptr], record_s[record_left_ptr] #Keep updating/swap

                    record_left_ptr += 1 #Keep updating/traversing

                record_right_ptr -= 1 #Keep updating/traversing

        return ''.join(record_s)
