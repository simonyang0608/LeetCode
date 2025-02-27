class Solution(object):
    def findSafeWalk(self, grid, health):
        """
        :type grid: List[List[int]]
        :type health: int
        :rtype: bool
        """
        #===================================#
        # Dijkstra's-based traversal method #
        #===================================#

        ############
        #Initialize
        ##### Length of rows, columns #####
        len_rows, len_cols = len(grid), len(grid[0])

        ##### Record heap/priority-queue #####
        record_pq = []

        ##### Record directions #####
        record_direct = [[0, (-1)], [(-1), 0], [0, 1], [1, 0]]

        ##### Visit dictionary/hashmap #####
        visit_dict = {}


        ###################################################################
        #Dijkstra's-based loop traversal with recorded heap/priority-queue
        heapify(record_pq) #Heapify

        ##### Check if the current indexed-value is 1 or not #####
        if ((grid[0])[0] == 1):
            heappush(record_pq, [((-1) * (health - 1)), 0, 0]) #Update/Record
        else:
            heappush(record_pq, [((-1) * health), 0, 0]) #Update/Record

        visit_dict[(0, 0)] = True #Update/Record

        while (record_pq):
            [record_health, rows_idx, cols_idx] = record_pq[0] #Record informations

            heappop(record_pq) #Keep updating/popped

            record_health *= (-1) #Keep updating/overwriting

            ##### Check if the current position reached destinations or not #####
            if ((rows_idx >= (len_rows - 1)) and ((cols_idx >= (len_cols - 1)))):

                ##### Check if the current health-value matched conditions or not #####
                if (record_health >= 1):
                    return True

            for direct_idx in range(4):
                next_rows_idx, next_cols_idx = (rows_idx + (record_direct[direct_idx])[0]), (cols_idx + (record_direct[direct_idx])[1]) #Next rows, columns index

                ##### Check if the current position exceed boundary or not #####
                if (((next_rows_idx < 0) or (next_rows_idx >= len_rows)) or ((next_cols_idx < 0) or (next_cols_idx >= len_cols))):
                    continue

                ##### Check if the current position is visited or not #####
                if ((next_rows_idx, next_cols_idx) in visit_dict):
                    continue

                next_health = ((record_health - 1) if ((grid[next_rows_idx])[next_cols_idx] == 1) else record_health) #Next health-value

                ##### Check if the next health-value matched conditions or not #####
                if (next_health <= 0):
                    continue

                visit_dict[(next_rows_idx, next_cols_idx)] = True #Keep updating/recording

                heappush(record_pq, [((-1) * next_health), next_rows_idx, next_cols_idx]) #Keep updating/recording

        return False
