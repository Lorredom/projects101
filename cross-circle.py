# board = [[-1]*size]*size


def play(board, player):
    row_input, col_input = map(int, input(f"Player {player}, enter two 1-3 digits, separated by a comma: ").split(","))
    row = row_input - 1
    col = col_input - 1
    # validate TODO
    # print(player, row, col)
    if board[row][col] == -1:
        if player == 1:
            board[row][col] = "X"
        elif player == 2:
            board[row][col] = "O"
    else:
        print("Field taken ")
    
 

def is_winner(board, size, player):
    for i in range(size):
        if board[i][0] == board[i][1] == board[i][2] != -1:
            return player
        elif board[0][i] == board[1][i] == board[1][i] != -1:
            return player
            
    arr = [0 for _ in range(3)]
    for j in range(size):
        arr[j] = board[size-1-j][j]
    if arr[0] == arr[1] == arr[2] != -1:
        return player
    for k in range(size):
        arr[k] = board[k][k]
    if arr[0] == arr[1] == arr[2] != -1:
        return player
    return 0


def main():
    BOARD_SIZE = 3

    # size = int(input("Enter board size: "))

    board = []
    for row in range(BOARD_SIZE):
        board.append([])
        for col in range(BOARD_SIZE):
            board[row].append(-1)

    winner = 0
    player = 1
    while True:
        play(board, player)
        winner = is_winner(board, BOARD_SIZE, player)
        if winner != 0:
            break
        if player == 1: player = 2
        else: player = 1
        print(board[0], board[1], board[2], sep="\n")
    print(f"Winner is {player}")
    print(board[0], board[1], board[2], sep="\n")

main()