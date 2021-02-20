#-----------------------------------------
# Simple Program using dynamic programming 
# to solve the 5 queens problem
#-----------------------------------------

# ----------------------------------------
# uses recursion with lookup table
# to solve problem for given board
# param: board : 2d array with location
# of 0 to 5 queens
# ----------------------------------------
def solve(board, queens, i, j, size):
    # base case: if all 5 queens are placed, return
    if queens == 5:
        return board
    else:
        while (i < size):
            while(j < size):
                board[i][j] = 1
                check(board)
        return solve(board);

# -----------------------------------------
# Check board for correct queen placement
# -----------------------------------------
def check(board, size):
    for (i in range(size)):
        if (board)


# -----------------------------------------
def main ():
    size = 8 
    chessboard = [][]

# -----------------------------------------
