class Solution(object):
    def maxEvents(self, events):
        """
        :type events: List[List[int]]
        :rtype: int
        """
        #============================================#
        # Heap/Priority-queue based traversal method #
        #============================================#

        ############
        #Initialize
        ##### Length of events #####
        len_events = len(events)

        ##### Sorted operations #####
        events.sort()

        ##### Record dictionary/hashmap #####
        record_dict = {}

        ##### Record minimun, maximun days #####
        record_min_days = (events[0])[0]
        record_max_days = 0

        for events_idx in range(len_events):
            record_start_day, record_end_day = (events[events_idx])[0], (events[events_idx])[1]
            record_max_days = max(record_max_days, record_start_day, record_end_day)

            if (record_start_day not in record_dict):
                record_dict[record_start_day] = [record_end_day]
            else:
                (record_dict[record_start_day]).append(record_end_day)

        record_max_days += 1

        ##### Record priority/heap-queue array #####
        record_hq = []

        ##### Result maximun summary counter #####
        res_max_cnter = 0


        ##########################################
        #Heap/Priority-queue based loop traversal
        for days_idx in range(record_min_days, record_max_days):

            ##### Check if the current days existed or not #####
            if (days_idx in record_dict):
                for sub_end_day in record_dict[days_idx]:
                    heappush(record_hq, sub_end_day) #Keep updating/recording
            else:
                pass

            while (record_hq and (record_hq[0] < days_idx)):
                heappop(record_hq) #Keep updating/popping

            if (record_hq and (record_hq[0] >= days_idx)):
                res_max_cnter += 1 #Keep updating/accumulating

                heappop(record_hq) #Keep updating/popping

        return res_max_cnter
