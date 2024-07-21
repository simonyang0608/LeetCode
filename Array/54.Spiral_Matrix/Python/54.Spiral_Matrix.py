class Solution(object):
    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        #=================================================#
        # Four-pointers directions based traversal method #
        #=================================================#

        ############
        #Initialize
        ##### Four-pointers directions #####
        top, bottom, left, right = 0, (len(matrix) - 1), 0, (len(matrix[0]) - 1)

        ##### Directions type #####
        directions = 0

        ##### Result array #####
        res_arry = []


        ###############################################
        #Four-pointers directions based loop traversal
        while ((left <= right) and (top <= bottom)):

            ##### Check the current directions (i.e. top, bottom, left, right) #####
            if (directions == 0): #Left-Right
                for left_right_ptr in range(left, (right + 1)):
                    res_arry.append((matrix[top])[left_right_ptr]) #Keep appending/recording

                top += 1 #Keep accumulating

            elif (directions == 1): #Top-Bottom
                for top_bottom_ptr in range(top, (bottom + 1)):
                    res_arry.append((matrix[top_bottom_ptr])[right]) #Keep appending/recording

                right -= 1 #Keep reducing

            elif (directions == 2): #Right-Left
                for right_left_ptr in range(right, (left - 1), -1):
                    res_arry.append((matrix[bottom])[right_left_ptr]) #Keep appending/recording

                bottom -= 1 #Keep reducing

            elif (directions == 3): #Bottom-Top
                for bottom_top_ptr in range(bottom, (top - 1), -1):
                    res_arry.append((matrix[bottom_top_ptr])[left]) #Keep appending/recording

                left += 1 #Keep accumulating

            directions = ((directions + 1) % 4) #Keep traversing

        return res_arry
