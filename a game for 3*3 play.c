#include <stdio.h>

int main(void){
    int player = 0; //Player number -- 0 or 1.
    int winner = 0; //The winner player.
    int choice = 0; //Squar selection number for turn.
    int row = 0;    //Row index for a square.
    int colum = 0;  //Colum index for a square.
    int line = 0;   //Row or colum index in checking loop.
    
    char board[3][3] = {
        {'1','2','3'},
        {'4','5','6'},
        {'7','8','9'}
    };
    
    //The main game loop. The game continue for up to 9 turns
    //As long as there is no winner.
    for (int i = 0; i < 9 && winner == 0; i++) {
        //Display the board
        printf("\n\n");
        printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
        printf("---+---+---\n");
        printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
        printf("---+---+---\n");
        printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
        player = i%2 + 1; //Select player.
        
        //Get valid player square selection
        do{
            printf("\nPlayer %d, please enter the number of the square "
                   "Where you want to place your %c: ",
                   player,(player == 1)?'X':'O');
            scanf("%d", &choice);
            row = --choice/3;
            colum = choice%3;
        }while(choice<0 || choice>9 || board[row][colum]>'9');
        
        //Insert player symbol.
        board[row][colum] = (player == 1) ? 'X' : 'O';
        
        //Code to check for a winner.
        if((board[0][0] == board[1][1] && board[0][0] == board[2][2]) ||
            (board[0][2] == board[1][1] && board[0][2] == board[2][0]))
            winner = player;
        else
            //Check rows and colums for a winning line.
            for(line = 0; line <= 2; line++){
                if ((board[line][0] == board[line][1] &&
                     board[line][0] == board[line][2]) ||
                    (board[0][line] == board[1][line] &&
                     board[0][line] == board[2][line]))
                        winner = player;
                
            }
        
        
        //code to play the game.
        
        
    }
    //Game is over so display the final board.
    printf("\n\n");
    printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);
    
    //Display result message.
    if(winner == 0)
        printf("\nHow bring, it is a draw\n");
    else
        printf("\nCongratulations, player %d, You are the winnwe!\n", winner);
    
    return 0;
}