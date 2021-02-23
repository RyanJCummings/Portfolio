#-----------------------------------------
# Implements backtracking algorithm
# to solve the N-Queens problem
#-----------------------------------------


# -----------------------------------------
# Initialize Chessboard
# -----------------------------------------
def initialize_board(size):
    board = [[0 for i in range(size)] for j in range(size)]
    print("Board initialized")
    print_board(board, size)


# -----------------------------------------
# Print chessboard
# -----------------------------------------
def print_board(board, size):
    for i in range(size):
        print(board[i])


# ----------------------------------------
# Uses backtracking algorithm
# to solve problem for given board
# and number of queens
# ----------------------------------------
def place_queens(board, queens, row, column, size):
    pass
    # base case: if all 5 queens are placed, return
    """if queens == 5:
        return board
    else:
        # Try each row in current column
        while (row < size):
            while(column < size):
                board[row][column] = 1
                check(board)
        return solve(board);"""


# -----------------------------------------
# Check board for correct queen placement
# -----------------------------------------
def check(board, size):
    pass
    # Check row

    # Check column

    # Check diagonals
    #for (i in range(size)):
     #   if (board)

# -----------------------------------------

def main():
    size = 8
    queens_num = 5
    initialize_board(size)

# -----------------------------------------

main()
