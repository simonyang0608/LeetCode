class Solution(object):
    def countCollisions(self, directions):
        """
        :type directions: str
        :rtype: int
        """
        #==============================#
        # Stack-based traversal method #
        #==============================#

        ############
        #Initialize
        ##### Length of directions array #####
        len_directions = len(directions)

        ##### Record stack #####
        record_stack = []

        ##### Result summary counter #####
        res_cnter = 0


        ############################
        #Stack-based loop traversal
        for directions_idx in range(len_directions):
            record_chr = directions[directions_idx] #Record char

            ##### Check the current directions informations (i.e. left, right, static) #####
            if (record_chr == 'L'):

                ##### Check the previous directions informations (i.e. left, right, static) #####
                if (record_stack and (record_stack[(-1)] == 'S')):
                    res_cnter += 1 #Keep updating/accumulating

                elif (record_stack and (record_stack[(-1)] == 'R')):
                    res_cnter += 2 #Keep updating/accumulating

                    record_stack.pop() #Keep updating/popped

                    while (record_stack and (record_stack[(-1)] == 'R')):
                        res_cnter += 1 #Keep updating/accumulating

                        record_stack.pop() #Keep updating/popped

                    record_stack.append('S') #Keep updating/recording

                else:
                    pass

            elif (record_chr == 'S'):
                while (record_stack and (record_stack[(-1)] == 'R')):
                    res_cnter += 1 #Keep updating/accumulating

                    record_stack.pop() #Keep updating/popped

                record_stack.append(record_chr) #Keep updating/recording

            else:
                record_stack.append(record_chr) #Keep updating/recording

        return res_cnter
