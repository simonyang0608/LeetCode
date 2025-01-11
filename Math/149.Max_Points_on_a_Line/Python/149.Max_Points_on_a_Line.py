class Solution(object):
    def maxPoints(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        #================================#
        # Hashmap-based traversal method #
        #================================#

        ############
        #Initialize
        ##### Length of points array #####
        len_points = len(points)

        ##### Record dictionary/hashmap #####
        record_dict = {}

        ##### Result maximun summary value #####
        res_max_sum = 1


        ##############################
        #Hashmap-based loop traversal
        sort_points = sorted(points, key = lambda point: point[1]) #Sorted operations

        for points_idx in range((len_points - 1)):
            for sub_points_idx in range((points_idx + 1), len_points):
                record_relative = (((10 ** 8) + 1.) if ((points[points_idx])[0] == (points[sub_points_idx])[0]) else ((1.)*((points[points_idx])[1] - (points[sub_points_idx])[1]) / ((1.)*(points[points_idx])[0] - (points[sub_points_idx])[0]))) #Record relative-value

                ##### Check if the current relative-value existed or not #####
                if (record_relative not in record_dict):
                    record_dict[record_relative] = 1 #Keep updating/recording
                else:
                    record_dict[record_relative] += 1 #Keep updating/recording

                res_max_sum = max(res_max_sum, (record_dict[record_relative] + 1)) #Keep updating/overwriting

            record_dict.clear() #Keep updating/reset

        return res_max_sum
