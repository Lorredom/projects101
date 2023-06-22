# board = [[-1]*size]*size
import sys

def input_is_valid(row_input, col_input):
    if row_input > 3 or col_input > 3:
        return False
    return True


def play(board, player):
    while True:
        try:
            row_input, col_input = map(int, input(f"Player {player}, enter two 1-3 digits, separated by a comma: ").split(","))
        except ValueError:
            continue

        if not input_is_valid(row_input, col_input):
            continue
        
        row = row_input - 1
        col = col_input - 1

        if board[row][col] == -1:
            if player == 1:
                board[row][col] = "X"
                break
            elif player == 2:
                board[row][col] = "O"
                break
        else:
            print("This field is taken ")


def game_can_continue(board, size):
    for row in range(size):
        for col in range(size):
            if board[row][col] == -1:
                return True
    return False
 

def name_winner(board, size, player):
    for i in range(size):
        if board[i][0] == board[i][1] == board[i][2] != -1:
            return player
        elif board[0][i] == board[1][i] == board[2][i] != -1:
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


def print_board(board, size):
    for row in range(size):
        print()
        for col in range(size):
            if board[row][col] != -1:
                if col != size - 1:
                    print(board[row][col], end="|")
                else:
                    print(board[row][col], end="")
            else:
                if col != size - 1:
                    print(" ", end="|")
                else:
                    print("  ", end="")
        print()
        if row != size - 1:
            for _ in range(size):
                print("--", end="")


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
        if not game_can_continue(board, BOARD_SIZE):
            sys.exit("No more fields are available. Game ended\n")

        play(board, player)
        winner = name_winner(board, BOARD_SIZE, player)
        if winner != 0:
            break
        if player == 1: player = 2
        else: player = 1
        # print(board[0], board[1], board[2], sep="\n")
        print_board(board, BOARD_SIZE)

    if winner != 0:
        print(f"Winner is player {player}")
    # print(board[0], board[1], board[2], sep="\n")
    print_board(board, BOARD_SIZE)

main()