class Solution(object):
    def merge(self, nums1, m, nums2, n):
        """
        :type nums1: List[int]
        :type m: int
        :type nums2: List[int]
        :type n: int
        :rtype: None Do not return anything, modify nums1 in-place instead.
        """
        #=====================================#
        # Two-pointers based traversal method #
        #=====================================#

        ############
        #Initialize
        ##### Pointers (nums1, nums2 arrays) #####
        nums1_ptr, nums2_ptr = 0, 0

        ###################################
        #Two-pointers based loop traversal
        ##### Step 1: Remove the last n-th value from aarray #####
        for n_idx in range(n):
            nums1.pop() #Keep updating/popped

        ##### Step 2: Looped-traversal for the updated array #####
        while ((nums1_ptr < len(nums1)) and (nums2_ptr < n)):

            ##### Check if the current indexed-value matched conditions or not #####
            if (nums1[nums1_ptr] > nums2[nums2_ptr]):
                nums1.insert(nums1_ptr, nums2[nums2_ptr]) #Keep updating/recording

                nums2_ptr += 1 #Keep updating/traversing
            else:
                pass

            nums1_ptr += 1 #Keep updating/traversing

        ##### Step 3: Post-process/Final-completions #####
        while (nums2_ptr < n):
            nums1.append(nums2[nums2_ptr]) #Keep updating/recording

            nums2_ptr += 1 #Keep updating/traversing
