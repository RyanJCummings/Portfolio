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
    
    return board

# -----------------------------------------
# Print chessboard
# -----------------------------------------

def print_board(board, size):
    for i in range(size):
        print(board[i])
    print()

# ----------------------------------------
# Uses backtracking algorithm
# to solve problem for given board
# and number of queens
# ----------------------------------------

def place_queens(board, queens, row, column, size):
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

    board[0][0] = 1
    print("Queen added")
    print_board(board, size)
    return check(board, size, row , column)

# -----------------------------------------
# Check board for correct queen placement
# -----------------------------------------

def check(board, size, row, col):
    pass
    # Check row
    for i in range(size):
        if board[i][col] == 1:
            return False
    
    # Check column
    for j in range(size):
        if board[row][j] == 1:
            return False
    
    # Check diagonals
    
    # If all checks pass, return true
    return True
# -----------------------------------------

def main():
    # Setup
    size = 8
    queens = 5
    chessboard = initialize_board(size)
    print(place_queens(chessboard, queens, 0, 0, size))
# -----------------------------------------

main()
