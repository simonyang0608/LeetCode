class Solution(object):
    def finalPositionOfSnake(self, n, commands):
        """
        :type n: int
        :type commands: List[str]
        :rtype: int
        """
        #========================================#
        # One-pass update based traversal method #
        #========================================#

        ############
        #Initialize
        ##### Length of commands array #####
        len_commands = len(commands)

        ##### Record directions (i.e. right, down) #####
        record_right, record_down = 0, 0


        ######################################
        #One-pass update based loop traversal
        for commands_idx in range(len_commands):

            ##### Check the current indexed-command is which directions #####
            if (commands[commands_idx] == "DOWN"):
                record_down += 1 #Keep updating/traversing

            elif (commands[commands_idx] == "UP"):
                record_down -= 1 #Keep updating/traversing

            elif (commands[commands_idx] == 'RIGHT'):
                record_right += 1 #Keep updating/traversing

            elif (commands[commands_idx] == "LEFT"):
                record_right -= 1 #Keep updating/traversing

        return ((n * record_down) + record_right)
