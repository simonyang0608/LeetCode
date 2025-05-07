class Solution(object):
    def findAllRecipes(self, recipes, ingredients, supplies):
        """
        :type recipes: List[str]
        :type ingredients: List[List[str]]
        :type supplies: List[str]
        :rtype: List[str]
        """
        #============================================#
        # Breath-first search based traversal method #
        #============================================#

        ############
        #Initialize
        ##### Length of total, supplies array #####
        len_total, len_supplies = len(recipes), len(supplies)

        ##### Root-child dictionary/hashmap #####
        root_child_dict = {}

        ##### Edge-rank array #####
        edge_rank_dict = {}

        ##### Record queue #####
        record_queue = []

        ##### Result array #####
        res_arry = []


        ###########################################################################
        #Breath-first search based loop traversal with recorded dictionary/hashmap
        ##### Step 1: Record indexed-nodes informations with dictionary/hashmap #####
        for total_idx in range(len_total):
            len_ingele = len(ingredients[total_idx]) #Length of ingrdient element

            for sub_idx in range(len_ingele):

                ##### Check if the current indexed-element existed or not #####
                if ((ingredients[total_idx])[sub_idx] not in root_child_dict):
                    root_child_dict[(ingredients[total_idx])[sub_idx]] = [recipes[total_idx]] #Keep updating/recording
                else:
                    (root_child_dict[(ingredients[total_idx])[sub_idx]]).append(recipes[total_idx]) #Keep updating/recording

                ##### Check if the current indexed-recipe existed or not #####
                if (recipes[total_idx] not in edge_rank_dict):
                    edge_rank_dict[recipes[total_idx]] = 1 #Keep updating/recording
                else:
                    edge_rank_dict[recipes[total_idx]] += 1 #Keep updating/recording
        
        ##### Step 2: Looped-traversal with recorded dictionary/hashmap #####
        for supplies_idx in range(len_supplies):
            record_queue.append(supplies[supplies_idx]) #Keep updating/recording

        while (record_queue):
            len_queue = len(record_queue) #Length of queue

            for queue_idx in range(len_queue):
                record_str = record_queue.pop(0) #Record string

                ##### Check if the current string existed or not #####
                if (record_str in root_child_dict):
                    for next_str in root_child_dict[record_str]:

                        ##### Check if the next string existed or not #####
                        if (next_str in edge_rank_dict):
                            edge_rank_dict[next_str] -= 1 #Keep updating/reducing

                            ##### Check if the current summary counter matched conditions or not #####
                            if (not edge_rank_dict[next_str]):
                                res_arry.append(next_str) #Keep updating/recording

                                record_queue.append(next_str) #Keep updating/recording
                            else:
                                pass
                        else:
                            pass
                else:
                    pass

        return res_arry
