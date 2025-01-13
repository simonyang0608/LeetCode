class Solution(object):
    def scheduleCourse(self, courses):
        """
        :type courses: List[List[int]]
        :rtype: int
        """
        #============================================#
        # Heap/Priority-queue based traversal method #
        #============================================#

        ############
        #Initialize
        ##### Length of courses array #####
        len_courses = len(courses)

        ##### Record heap/priority-queue #####
        record_pq = []

        ##### Record summary value #####
        record_sum_val = 0


        #############################################################
        #Heap/Priority-queue based loop traversal with sorted array
        sort_courses = sorted(courses, key = lambda course: course[1]) #Sorted operations

        for courses_idx in range(len_courses):

            ##### Check if the current summary value excced boundary or not #####
            if ((record_sum_val + (sort_courses[courses_idx])[0]) <= (sort_courses[courses_idx])[1]):
                record_sum_val += (sort_courses[courses_idx])[0] #Keep updating/accumulating

                heappush(record_pq, ((-1) * (sort_courses[courses_idx])[0])) #Keep updating/recording
            else:

                ##### Check if the previous maximun value matched conditions or not #####
                if (record_pq and ((record_pq[0] * (-1)) > (sort_courses[courses_idx])[0])):
                    record_sum_val -= (record_pq[0] * (-1)) #Keep updating/reducing

                    heappop(record_pq) #Keep updating/popped

                    record_sum_val += (sort_courses[courses_idx])[0] #Keep updating/accumulating

                    heappush(record_pq, ((sort_courses[courses_idx])[0] * (-1))) #Keep updating/recording
                else:
                    pass

        return len(record_pq)
