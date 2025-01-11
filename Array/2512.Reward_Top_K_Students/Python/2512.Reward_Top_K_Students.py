class Solution(object):
    def topStudents(self, positive_feedback, negative_feedback, report, student_id, k):
        """
        :type positive_feedback: List[str]
        :type negative_feedback: List[str]
        :type report: List[str]
        :type student_id: List[int]
        :type k: int
        :rtype: List[int]
        """
        #============================================#
        # Heap/Priority-queue based traversal method #
        #============================================#

        ############
        #Initialize
        ##### Length of arrays (i.e. positive, negative feedback, report) #####
        len_pfb, len_nfb, len_report = len(positive_feedback), len(negative_feedback), len(report)

        ##### Record dictionary/hashmap (i.e. positive, negative feedback) #####
        record_pdict, record_ndict = {}, {}

        ##### Record heap/priority-queue #####
        record_pq = []

        ##### Result array #####
        res_arry = []


        ###########################################################################
        #Heap/Priority-queue based loop traversal with recorded dictionary/hashmap
        ##### Step 1: Record indexed-string with dictionary/hashmap #####
        heapify(record_pq) #Update/Heapify

        for record_pidx in range(len_pfb):
            record_pdict[positive_feedback[record_pidx]] = True #Keep updating/recording

        for record_nidx in range(len_nfb):
            record_ndict[negative_feedback[record_nidx]] = True #Keep updating/recording

        ##### Step 2: Looped-traversal with recorded dictionary/hashmap #####
        for report_idx in range(len_report):
            record_str, record_score = "", 0 #Record string, score
            
            len_str = len(report[report_idx]) #Length of record string

            for str_idx in range(len_str):

                ##### Check if it's the end of string or not #####
                if ((report[report_idx])[str_idx] == ' '):

                    ##### Check if the current string existed or not #####
                    if (record_str in record_pdict):
                        record_score += 3 #Keep updating/accumulating
                    else:
                        pass

                    if (record_str in record_ndict):
                        record_score += (-1) #Keep updating/accumulating
                    else:
                        pass

                    record_str = "" #Keep updating/reset

                    continue

                record_str += (report[report_idx])[str_idx] #Keep updating/recording

            ##### Check if the current string existed or not #####
            if (record_str in record_pdict):
                record_score += 3 #Keep updating/accumulating
            else:
                pass

            if (record_str in record_ndict):
                record_score += (-1) #Keep updating/accumulating
            else:
                pass

            heappush(record_pq, [(record_score * (-1)), student_id[report_idx]]) #Keep updating/recording

        ##### Step 3: Post-process/Final completions #####
        for k_idx in range(k):
            res_arry.append((record_pq[0])[1]) #Keep updating/recording

            heappop(record_pq) #Keep updating/popped

        return res_arry
