class Solution(object):
    def simplifyPath(self, path):
        """
        :type path: str
        :rtype: str
        """
        #==============================#
        # Stack-based traversal method #
        #==============================#

        ############
        #Initialize
        ##### Length of path string #####
        len_path = len(path)

        ##### Path index #####
        path_idx = 0

        ##### Record stack #####
        record_stack = []

        ##### Result string #####
        res_str = ""


        ############################
        #Stack-based loop traversal
        while (path_idx < len_path):

            ##### Check if the current indexed-char is valid or not #####
            if (path[path_idx] == "/"):
                path_idx += 1 #Keep updating/traversing

                continue

            record_str = "" #Record string

            while ((path_idx < len_path) and (path[path_idx] != "/")):
                record_str += path[path_idx] #Keep updating/recording

                path_idx += 1 #Keep updating/traversing

            ##### Check if the current indexed-char is valid or not #####
            if (record_str == "."):
                path_idx += 1 #Keep updating/traversing

                continue

            ##### Check if the current indexed-char is valid or not #####
            if (record_str == ".."):
                if (record_stack):
                    record_stack.pop() #Keep updating/popped
                else:
                    pass

                path_idx += 1 #Keep updating/traversing

                continue

            record_stack.append(record_str) #Keep updating/recording

            path_idx += 1 #Keep updating/traversing

        ##### Check if the current stack is empty or not #####
        if (not record_stack):
            res_str += "/" #Keep updating/recording
        else:
            while (record_stack):
                res_str += "/" #Keep updating/recording
                res_str += record_stack.pop(0) #Keep updating/recording

        return res_str
