class Solution(object):
    def minHeightShelves(self, books, shelfWidth):
        """
        :type books: List[List[int]]
        :type shelfWidth: int
        :rtype: int
        """
        #============================================#
        # Dynamic-programming based traversal method #
        #============================================#

        ############
        #Initialize
        ##### Length of books array #####
        len_books = len(books)

        ##### Record dynamic-programming (i.e. DP) array #####
        record_dp = [0 for _ in range((len_books + 1))]


        ##########################################
        #Dynamic-programming based loop traversal
        for record_idx in range(1, (len_books + 1)):
            book_width, book_height = (books[(record_idx - 1)])[0], (books[(record_idx - 1)])[1] #Book width, height

            record_dp[record_idx] = (record_dp[(record_idx - 1)] + book_height) #Keep updating/overwriting

            for prev_idx in range((record_idx - 2), (-1), (-1)):

                ##### Check if the current width exceeds boundary or not #####
                if ((book_width + (books[prev_idx])[0]) > shelfWidth):
                    break

                book_width += (books[prev_idx])[0] #Keep updating/accumulating

                book_height = max(book_height, (books[prev_idx])[1]) #Keep updating/overwriting

                record_dp[record_idx] = min(record_dp[record_idx], (record_dp[prev_idx] + book_height)) #Keep updating/overwriting

        return record_dp[len_books]
