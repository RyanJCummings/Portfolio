#-----------------------------------------
# Implements backtracking algorithm
# to solve the N-Queens problem
#-----------------------------------------

import sys
import pdb

class Chessboard:
    def __init__(self, size, queens):
        self.size = size
        self.queens = queens
        
        self.board = self.initialize_board()
        self.print_board()

    # Initialize Chessboard
    def initialize_board(self):
        board = [[0 for i in range(self.size)] for j in range(self.size)]
        print("Board initialized")
        
        return board


    # Print chessboard
    def print_board(self):
        for i in range(self.size):
            print(self.board[i])
        print()


    # Uses backtracking algorithm
    # to solve problem for given board
    # and number of queens
    def place_queens(self, row, column, queens_placed = 0):
        # base case: if all queens are correctly placed, return
        if queens_placed == self.queens:
            return self.board
        else:
            for i in range(size):
                # Place a queen, check constraints, and recursively search for solution
                self.board[row][column] = 1
                if self.check(row, column):
                    return self.place_queens(0, column + 1, queens_placed + 1)
                else:
                    # If placement does not lead to solution, remove previous queen try next row
                    self.board[row][column] = 0
                    return self.place_queens(row + 1, column, queens_placed)


    # Check board for correct queen placement
    def check(self, row, col):
        # function vars for better readability
        counter = row
        previous_row = row - 1
        previous_col = col - 1
        next_row = row + 1
        
        # Check row
        row_sum = 0
        for i in self.board[row]:
            if i == 1:
                row_sum += 1
                if row_sum > 1:
                    return False
        
        # Check diagonals
        while counter > previous_row and counter > previous_col and next_row < size:
            if self.board[previous_row][previous_col] == 1:
                return False

            elif self.board[next_row][previous_col] == 1:
                return False

            # update limits and iterate diagonal check
            previous_col -= 1
            previous_row -= 1
            next_row += 1
            counter -= 1

        # If all checks pass, return true
        return True

# -----------------------------------------
if __name__ == "__main__":
    # Setup
    size = int(sys.argv[1])
    queens = int(sys.argv[2])
    chessboard = Chessboard(size, queens)
    chessboard.place_queens(3, 3)
    chessboard.print_board()


