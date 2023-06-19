#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

typedef struct Pawn {
    int owner;
    bool isAlive;
    bool isQueen;
    int row;
    int col;
} pawn;


typedef struct User {
    int player;
    int score;
    } user;

/*typedef struct Queen {
    pawn pawn;
    int isSkater;
} queen;*/

pawn** createBoard() {


    int rows = 8, cols = 8, row, col;
    int rowCounter = 0, colCounter;
 
    pawn** board = (pawn**)malloc(rows * sizeof(pawn*));
    if (board == NULL) {
		printf("Memory allocation #1error\n");
        return NULL;
	}
    for (row = 0; row < rows; row++) {
        board[row] = (pawn*)malloc(cols * sizeof(pawn));
    }
    
    if (board[row] == NULL) {
        printf("Memory allocation #2error\n");
        return NULL;
    }
 
    // board[row][col] is equal to *(*(board+row)+col)

    for (row = 0; row < 2; row++) {
        rowCounter++;
        colCounter = 0;
        for (col = 0; col < 8; col++) {
            colCounter++;
            board[row][col].owner = 1;
            board[row][col].isAlive = true;
            board[row][col].isQueen = false;
            board[row][col].row = rowCounter;
            board[row][col].col = colCounter;
        }
    }

    for (row = 2; row < 6; row++) {
        rowCounter++;
        colCounter = 0;
        for (col = 0; col < 8; col++) {
            colCounter++;
            board[row][col].owner = 0;
            board[row][col].isAlive = NULL;
            board[row][col].isQueen = NULL;
            board[row][col].row = rowCounter;
            board[row][col].col = colCounter;
        }
    }

    for (row = 6; row < 8; row++) {
        rowCounter++;
        colCounter = 0;
        for (col = 0; col < 8; col++) {
            colCounter++;
            board[row][col].owner = 2;
            board[row][col].isAlive = true;
            board[row][col].isQueen = false;
            board[row][col].row = rowCounter;
            board[row][col].col = colCounter;
        }
    }
    
    return board;
}


pawn** showBoard(pawn** theBoard) {
    int row, col;
    char colLettering[] = "ABCDEFGH";

    printf("c: ");
    for (col = 0; col < 8; col++) {
            printf("%c", colLettering[col]);
        } 
    printf("\n");   
    for (row = 0; row < 8; row++) {
        printf("%d: ", row+1);
        for (col = 0; col < 8; col++) {
            if (theBoard[row][col].owner == 1) {
            printf("+"); // OR *(*(arr+i)+j) = ++count
            }
            else if (theBoard[row][col].owner == 2) {
            printf("^"); // OR *(*(arr+i)+j) = ++count
            }
            else {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}

/*int getInput() {
    int oldRow, newRow, oldCol, newCol;
    printf("Your move. What piece do you want to move? Choose by field: [takes two numbers] \n");
    scanf("%d %d", &row, &col);
    printf("Choose new field: [takes two numbers] \n");
    scanf("%d %d", &newRow, &newCol);

    return TODO
}*/
void transformToQueen(pawn ** board, int player, int oldRow, int oldCol, int newRow, int newCol) {  
    board[oldRow-1][oldCol-1].isQueen = NULL;
    board[newRow-1][newCol-1].isQueen = true;
}


int validateMovePawn(pawn ** board, int player, int oldRow, int oldCol, int newRow, int newCol) {
    if (board[oldRow-1][oldCol-1].owner == player) { // does player own the pawn?
        if (oldCol==newCol) { //is this move across the board?
            if (player == 1) { 
                //updated2: different for each player|| updated: is next field empty? || older:is requested field empty? ([newRow-1][newCol-1])
                if (board[oldRow][oldCol-1].owner == 0 && board[newRow-1][newCol-1].owner == 0) { 
                    if (newRow > oldRow && newRow <= oldRow + 2)  {
                        printf("P1=>The first row ever of this pawn is %d, and the oldRow is %d\n", board[oldRow-1][oldCol-1].row, oldRow);
                        if (board[oldRow-1][oldCol-1].row == oldRow) {
                            return 0;
                        } else if (newRow == oldRow + 1) {
                            if (oldCol == 7) {
                                return 1;
                            } else {
                                return 0;
                            }
                        } else {
                            printf("Player 1 validation error. Too many steps darling.\n");
                            return -1;
                        }
                    } else {
                        printf("Think you can make a cheat-moveS? Think again\n");
                        return -1;
                    }
                } else {
                    printf("No luck, you ARE stuck. Tryyyyyy agaaaaiiiin\n");
                    return -1;
                }
                
            } else if (player == 2) {
                if (board[oldRow-2][oldCol-1].owner == 0 && board[newRow-1][newCol-1].owner == 0) {
                    if (newRow < oldRow && newRow >= oldRow - 2)  {
                        printf("P2=>The first row ever of this pawn is %d, and the oldRow is %d\n", board[oldRow-1][oldCol-1].row, oldRow);
                        if (board[oldRow-1][oldCol-1].row == oldRow) {
                            return 0;
                        } else if (newRow == oldRow - 1) {
                            if (oldCol == 2) {
                                return 1;
                            } else {
                                return 0;
                            }
                        } else {
                            printf("Player 2 validation error. Too many steps darling.\n");
                            return -1;
                        }
                    } else {
                        printf("Think you can make a cheat-move? Think again\n");
                        return -1;
                    }
                } else {
                    printf("No luck, you ARE stuck. Tryyyyyy agaaaaiiiin\n");
                    return -1;
                }
            }
        } else { 
            printf("Stop trying to fly sideways, train driver. AGAIN\n");
            return -1;
        }
    } else {
        printf("Sorry bumblebee, not your pawn. Tryyyyyy agaaaaiiiin\n");
        return -1;
    }
}

int validateBeatPawn(pawn ** board, int player, int yourRow, int yourCol, int enemyRow, int enemyCol) {
    if (board[yourRow-1][yourCol-1].owner == player) {  // does player own the pawn?
        if (board[enemyRow-1][enemyCol-1].owner != 0 && board[enemyRow-1][enemyCol-1].owner != player) {
            if (enemyCol==yourCol-1 || enemyCol==yourCol+1) {
                if (player==1) {
                    if (enemyRow == yourRow+1) {
                        if (enemyCol==yourCol-1) {
                            if (board[yourRow+2][yourCol-2].owner == 0) {
                                return 0;
                            } else {
                                printf("P1:Ooops, field not available\n");
                            }
                        } else if (enemyCol==yourCol+1) {
                            if (board[yourRow+2][yourCol+2].owner == 0) {
                                return 0;
                            } else {
                                printf("P1:Ooops, field not available\n");
                                return -1;
                            }
                        } else {
                            printf("P1:Unforseen misfortune error\n");
                            return -1;
                        }
                    } else {
                        printf("Need a better choice. Another chance, another row\n");
                        return -1;
                    }
                } else if (player == 2) {
                    if (enemyRow == yourRow-1) {
                        if (enemyCol==yourCol-1) {
                            if (board[yourRow-2][yourCol-2].owner == 0) {
                                return 0;
                            } else {
                                printf("P2:Ooops, field not available\n");
                                return -1;
                            }
                        } else if (enemyCol==yourCol+1) {
                            if (board[yourRow-2][yourCol+2].owner == 0) {
                                return 0;
                            } else {
                                printf("P2:Ooops, field not available\n");
                                return -1;
                            }
                        } else {
                            printf("P2:Unforseen misfortune error\n");
                            return -1;
                        }
                    } else {
                        printf("P2:Need a better choice. Another chance, another row\n");
                        return -1;
                    } 
                }
            } else {
                printf("I'm going to turn a blind eye to the column you chose. Remember: one step diagonally\n");
                return -1;
            }
        } else {
            printf("No enemies there, young warrior\n");
            return -1;
        }
    } else {
        printf("Sorry bumblebee, not your pawn. Tryyyyyy agaaaaiiiin\n");
        return -1;
    }
}

void movePawn(pawn ** beforeMoveBoard, int player) {

    int verification = -1;
    int oldRow, oldCol, newRow, newCol;
    while(1) {
        printf("Choose your soldier, player %d [takes two numbers, row and column]\n", player);
        //scanf("%d %d", &oldRow, &oldCol);
    
        if (!scanf("%d %d", &oldRow, &oldCol)) {
            scanf("%*[^\n]%*[^\n]");
            printf("I need digits, honey\n");
        } else {
            if (oldRow<1 || oldRow>8 || oldCol<1 || oldCol>8) {
                printf("Error1: Field unavailable.\n");
            } else {
                printf("Make your move, player %d [takes two numbers, row and column]\n", player);
                //scanf("%d %d", &newRow, &newCol);
                if (!scanf("%d %d", &newRow, &newCol)) {
                    scanf("%*[^\n]%*[^\n]");
                    printf("I need digits, honey\n");
                } else {
                    if (newRow<1 || newRow>8 || newCol<1 || newCol>8) {
                        printf("Error2: New field unavailable.\n");
                    } else {
                        verification = validateMovePawn(beforeMoveBoard, player, oldRow, oldCol, newRow, newCol);
                        if (verification != -1) {
                            break;
                        }
                    }
                }
            }
        }
    }

    //Removes old position of the pawn
    beforeMoveBoard[oldRow-1][oldCol-1].owner = 0;
    beforeMoveBoard[oldRow-1][oldCol-1].isAlive = NULL;
    beforeMoveBoard[oldRow-1][oldCol-1].isQueen = NULL;

    // Settles new position with player as owner. Crowns pawn, when necessary.

    if (player == 1) {
        beforeMoveBoard[newRow-1][newCol-1].owner = 1;
    } else if (player == 2) {
        beforeMoveBoard[newRow-1][newCol-1].owner = 2;
    }

    beforeMoveBoard[newRow-1][newCol-1].isAlive = true;

    if (verification == 1) {
        beforeMoveBoard[newRow-1][newCol-1].isQueen = true;
    } else if (verification == 0) {
        beforeMoveBoard[newRow-1][newCol-1].isQueen = false;
    } else {
        printf("Unexpected error.\n");
    }
}


int beatPawn(pawn ** beforeAttackBoard, int player, int score) {
    int verification = -1; 
    int yourRow, yourCol, enemyRow, enemyCol;
    while (1) {
        printf("Choose your soldier, player %d [takes two numbers, row and column]\n", player);
        if (!scanf("%d %d", &yourRow, &yourCol)) {
            scanf("%*[^\n]%*[^\n]");
            printf("I need digits, honey\n");
        } else {
            if (yourRow<1 || yourRow>8 || yourCol<1 || yourCol>8) {
                printf("Error1: Field unavailable.\n");
            } else {
                printf("Player %d, choose your enemy by field: [takes two numbers, row and column] \n", player);
                if (!scanf("%d %d", &enemyRow, &enemyCol)) {
                    scanf("%*[^\n]%*[^\n]");
                    printf("I need digits, honey\n");
                } else {
                    if (enemyRow<1 || enemyRow>8 || enemyCol<1 || enemyCol>8) {
                        printf("Error2: New field unavailable.\n");
                    } else {
                        verification = validateBeatPawn(beforeAttackBoard, player, yourRow, yourCol, enemyRow, enemyCol);
                        if (verification != -1) {
                            break;
                        }
                    }
                }
            }
        }
    }


    beforeAttackBoard[yourRow-1][yourCol-1].owner = 0;
    beforeAttackBoard[yourRow-1][yourCol-1].isAlive = NULL;
    beforeAttackBoard[yourRow-1][yourCol-1].isQueen = NULL;

    beforeAttackBoard[enemyRow-1][enemyCol-1].owner = 0;
    beforeAttackBoard[enemyRow-1][enemyCol-1].isAlive = false;
    beforeAttackBoard[enemyRow-1][enemyCol-1].isQueen = NULL;
    
    if (player == 1) {
        
        if (enemyCol<yourCol) { 
            beforeAttackBoard[enemyRow][enemyCol-2].owner = player;
            beforeAttackBoard[enemyRow][enemyCol-2].isAlive = true;
            beforeAttackBoard[enemyRow][enemyCol-2].isQueen = false;
        } else {
            beforeAttackBoard[enemyRow][enemyCol].owner = player;
            beforeAttackBoard[enemyRow][enemyCol].isAlive = true;
            beforeAttackBoard[enemyRow][enemyCol].isQueen = false;
        }
    } else if (player == 2) {
        if (enemyCol>yourCol) {
            beforeAttackBoard[enemyRow-2][enemyCol].owner = player;
            beforeAttackBoard[enemyRow-2][enemyCol].isAlive = true;
            beforeAttackBoard[enemyRow-2][enemyCol].isQueen = false;
        } else {
            beforeAttackBoard[enemyRow-2][enemyCol-2].owner = player;
            beforeAttackBoard[enemyRow-2][enemyCol-2].isAlive = true;
            beforeAttackBoard[enemyRow-2][enemyCol-2].isQueen = false;
        }
    }

    //score = score + 1;
    score++;

    printf("Beaten! Your score is: %d\n", score);
    return score;
}




int main() {

    pawn ** myBoard = createBoard();
    char command[20];

    user User1;
    user User2; 
    User1.player = 1;
    User2.player = 2;
    User1.score = 0;
    User2.score = 0;

    int player = User1.player;
    // user player = User1;
    int score = 0;
        

    showBoard(myBoard);
    while (1) {
        printf("Your wish is my command, player %d [takes 'move', 'beat', 'crownPawn', 'quit']\n", player);
        scanf("%s", command);
        if (strncmp(command, "move", 5) == 0) {
            movePawn(myBoard, player);

        }
        else if (strncmp(command, "beat", 5) == 0) {
            score = beatPawn(myBoard, player, score);
            // player.score++;
            printf("Else if score is %d\n", score);
        }
        else if (strncmp(command, "crownPawn", 10) == 0) {
            //transformToQueen(myBoard, player);
        }
        else if (strncmp(command, "quit", 5) == 0) {
            printf("Game ended by user.\n");
            break;
        }
        showBoard(myBoard);
        
        if (player == User1.player) {
            User1.score = score; 
            player = User2.player;
            score = User2.score;
        } else {
            User2.score = score;
            player = User1.player;
            score = User1.score;
        }
        printf("Player 1 scored: %d.\nPlayer 2 scored: %d.\n", User1.score, User2.score);
    }
    printf("Game ended");
	return 0;
}