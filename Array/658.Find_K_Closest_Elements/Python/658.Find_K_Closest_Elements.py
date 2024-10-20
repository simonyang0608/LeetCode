class Solution(object):
    def findClosestElements(self, arr, k, x):
        """
        :type arr: List[int]
        :type k: int
        :type x: int
        :rtype: List[int]
        """
        #=====================================#
        # Two-pointers based traversal method #
        #=====================================#
        if (x >= arr[(-1)]): #Issue/Boundary-case handling (i.e. exceed maximun)
            return arr[(len(arr) - k): ]

        elif (x <= arr[0]): #Issue/Boundary-case handling (i.e. below minimun)
            return arr[: k]

        ############
        #Initialize
        ##### Length of arr array #####
        len_arr = len(arr)

        ##### Record two-pointers (i.e. left, right) #####
        record_left_ptr, record_right_ptr = 0, 1

        ##### Result array #####
        res_arr = []


        ###################################
        #Two-pointers based loop traversal
        ##### Step 1: Looped-traversal for the index/place of x value #####
        while (record_left_ptr < len_arr):

            ##### Check if the current indexed-value matched conditions or not #####
            if (arr[(record_left_ptr + 1)] > x):
                record_right_ptr += record_left_ptr #Update/Accumulate

                break

            record_left_ptr += 1 #Keep updating/accumulating

        ##### Step 2: Post-process/Final completions #####
        for _ in range(k):

            ##### Check if the current pointer exceed boundary or not #####
            if (record_left_ptr >= 0):
                if (record_right_ptr < len_arr):
                    curr_left_diff = (x - arr[record_left_ptr]) #Current left-half indexed-value differences
                    curr_right_diff = (arr[record_right_ptr] - x) #Current right-half indexed-value differences
                
                    ##### Check if the current indexed-value matched conditions or not #####
                    if (curr_left_diff <= curr_right_diff):
                        res_arr.insert(0, arr[record_left_ptr]) #Keep updating/recording

                        record_left_ptr -= 1 #Keep updating/reducing

                    else:
                        res_arr.append(arr[record_right_ptr]) #Keep updating/recording

                        record_right_ptr += 1 #Keep updating/accumulating

                else:
                    res_arr.insert(0, arr[record_left_ptr]) #Keep updating/recording

                    record_left_ptr -= 1 #Keep updating/reducing

            else:
                ##### Check if the current pointer exceed boundary or not #####
                if (record_right_ptr < len_arr):
                    res_arr.append(arr[record_right_ptr]) #Keep updating/recording

                    record_right_ptr += 1 #Keep updating/accumulating

                else:
                    pass

        return res_arr
