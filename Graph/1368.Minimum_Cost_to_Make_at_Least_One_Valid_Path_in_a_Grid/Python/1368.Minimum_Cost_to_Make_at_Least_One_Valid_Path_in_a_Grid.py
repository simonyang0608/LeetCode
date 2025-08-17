class Solution(object):
    def minCost(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        #===================================#
        # Dijkstras' based traversal method #
        #===================================#

        ############
        #Initialize
        ##### Length of rows, columns #####
        len_rows, len_cols = len(grid), len(grid[0])

        ##### Edge-rank array #####
        edge_rank_arry = [[float("inf") for _ in range(len_cols)] for _ in range(len_rows)]

        ##### Record dictionary/hashmap #####
        record_dict = {1: (0, 1), 2: (0, (-1)), 3: (1, 0), 4: ((-1), 0)}

        ##### Record heap/priority-queue #####
        record_pq = []


        #########################################################################
        #Dijkstras' based loop traversal with recorded dictionary/hashmap, array
        ##### Step 1: Record first node informations, ... #####
        heapify(record_pq) #Update/Heapify

        (edge_rank_arry[0])[0] = 0 #Update/Record

        heappush(record_pq, (0, (0, 0))) #Update/Record

        ##### Step 2: Looped-traversal with recorded dictionary, hashmap, array #####
        while (record_pq):
            (curr_cost, (curr_rows_idx, curr_cols_idx)) = record_pq[0] #Current node informations

            heappop(record_pq) #Update/Popped

            ##### Check if the current cost matched conditions or not #####
            if ((edge_rank_arry[curr_rows_idx])[curr_cols_idx] != curr_cost):
                continue

            ##### Check if the current position matched conditions or not #####
            if ((curr_rows_idx == (len_rows - 1)) and (curr_cols_idx == (len_cols - 1))):
                return curr_cost

            for record_idx in range(1, 5):
                next_rows_idx = (curr_rows_idx + (record_dict[record_idx])[0]) #Next rows index
                next_cols_idx = (curr_cols_idx + (record_dict[record_idx])[1]) #Next columns index

                ##### Check if the next position exceed boundary or not #####
                if (((next_rows_idx < 0) or (next_rows_idx >= len_rows)) or ((next_cols_idx < 0) or (next_cols_idx >= len_cols))):
                    continue

                next_cost = (curr_cost if ((grid[curr_rows_idx])[curr_cols_idx] == record_idx) else (curr_cost + 1)) #Next cost

                ##### Check if the next cost matched conditions or not #####
                if (next_cost < (edge_rank_arry[next_rows_idx])[next_cols_idx]):
                    (edge_rank_arry[next_rows_idx])[next_cols_idx] = next_cost #Keep updating/overwriting

                    heappush(record_pq, (next_cost, (next_rows_idx, next_cols_idx))) #Keep updating/recording
                else:
                    pass

        return (-1)
