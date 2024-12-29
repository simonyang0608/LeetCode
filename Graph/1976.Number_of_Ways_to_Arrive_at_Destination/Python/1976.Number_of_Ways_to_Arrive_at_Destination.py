class Solution(object):
    def countPaths(self, n, roads):
        """
        :type n: int
        :type roads: List[List[int]]
        :rtype: int
        """
        #===================================#
        # Dijkstra's based traversal method #
        #===================================#

        ############
        #Initialize
        ##### Length of roads array #####
        len_roads = len(roads)

        ##### Record dictionary/hashmap #####
        record_map = {n_idx: [] for n_idx in range(n)}

        ##### Record heap/priority-queue #####
        record_pq = []

        heapify(record_pq)

        ##### Record accumulate path-summary array #####
        accu_path_arry = [(10 ** 12) for _ in range(n)]

        ##### Result summary counter array #####
        res_cnter_arry = [0 for _ in range(n)]


        ###########################################################################
        #Dijkstra's based loop traversal with recorded dictionary/hashmap, arrays
        ##### Step 1: Record root-child values, distances with dictionary/hashmap #####
        for roads_idx in range(len_roads):
            (record_map[(roads[roads_idx])[0]]).append([(roads[roads_idx])[1], (roads[roads_idx])[2]]) #Keep updating/recording
            (record_map[(roads[roads_idx])[1]]).append([(roads[roads_idx])[0], (roads[roads_idx])[2]]) #Keep updating/recording

        ##### Step 2: Looped-traversal with recorded dictionary/hashmap, arrays #####
        heappush(record_pq, [0, 0]) #Update/Record

        accu_path_arry[0] = 0 #Update/Record

        res_cnter_arry[0] = 1 #Update/Record

        while (record_pq):
            record_dist, record_val = (record_pq[0])[0], (record_pq[0])[1] #Record distance, value

            heappop(record_pq) #Keep updating/popped

            ##### Check if the current summary is valid or not #####
            if (accu_path_arry[record_val] != record_dist):
                continue

            for [next_val, next_dist] in record_map[record_val]:
                next_accu_dist = (accu_path_arry[record_val] + next_dist) #Next accumulate distance

                ##### Check if the current accumulated distance is smaller or not #####
                if (next_accu_dist < accu_path_arry[next_val]):
                    heappush(record_pq, [next_accu_dist, next_val]) #Keep updating/recording

                    accu_path_arry[next_val] = next_accu_dist #Keep updating/overwriting

                    res_cnter_arry[next_val] = res_cnter_arry[record_val] #Keep updating/overwriting

                elif (next_accu_dist == accu_path_arry[next_val]):
                    res_cnter_arry[next_val] += res_cnter_arry[record_val] #Keep updating/accumulating

        return (res_cnter_arry[(n - 1)] % ((10 ** 9) + 7))
