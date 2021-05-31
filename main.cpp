#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

class board
{
public:

    bool finished = false;

    void initializeBoard()
    {
        board[0][0] = 'O', //PINK PLAYER IS UPPERCASE
        board[0][1] = 'O',
        board[0][2] = 'R',
        board[0][3] = 'O',
        board[0][4] = 'O',
        board[0][5] = 'O',
        board[1][0] = 'V',
        board[1][1] = ' ',
        board[1][2] = ' ',
        board[1][3] = ' ',
        board[1][4] = ' ',
        board[1][5] = 'v', //GREEN PLAYER IS LOWERCASE
        board[2][0] = 'V',
        board[2][1] = ' ',
        board[2][2] = ' ',
        board[2][3] = ' ',
        board[2][4] = ' ',
        board[2][5] = 'v',
        board[3][0] = 'V',
        board[3][1] = ' ',
        board[3][2] = ' ',
        board[3][3] = ' ',
        board[3][4] = ' ',
        board[3][5] = 'v',
        board[4][0] = 'V',
        board[4][1] = ' ',
        board[4][2] = ' ',
        board[4][3] = ' ',
        board[4][4] = ' ',
        board[4][5] = 'v',
        board[5][0] = 'o',
        board[5][1] = 'o',
        board[5][2] = 'o',
        board[5][3] = 'r',
        board[5][4] = 'o',
        board[5][5] = 'o';



    }

    void initializeEmptyBoard()
    {
        emptyBoard[0][0] = ' ',
        emptyBoard[1][0] = '*',
        emptyBoard[2][0] = ' ',
        emptyBoard[3][0] = ' ',
        emptyBoard[4][0] = ' ',
        emptyBoard[5][0] = ' ',
        emptyBoard[0][1] = '*',
        emptyBoard[1][1] = ' ',
        emptyBoard[2][1] = '*',
        emptyBoard[3][1] = ' ',
        emptyBoard[4][1] = ' ',
        emptyBoard[5][1] = ' ',
        emptyBoard[0][2] = ' ',
        emptyBoard[1][2] = '*',
        emptyBoard[2][2] = '#',
        emptyBoard[3][2] = ' ',
        emptyBoard[4][2] = ' ',
        emptyBoard[5][2] = '8',
        emptyBoard[0][3] = ' ',
        emptyBoard[1][3] = ' ',
        emptyBoard[2][3] = ' ',
        emptyBoard[3][3] = '#',
        emptyBoard[4][3] = '*',
        emptyBoard[5][3] = ' ',
        emptyBoard[0][4] = ' ',
        emptyBoard[1][4] = ' ',
        emptyBoard[2][4] = ' ',
        emptyBoard[3][4] = '*',
        emptyBoard[4][4] = ' ',
        emptyBoard[5][4] = '*',
        emptyBoard[0][5] = ' ',
        emptyBoard[1][5] = ' ',
        emptyBoard[2][5] = ' ',
        emptyBoard[3][5] = ' ',
        emptyBoard[4][5] = '*',
        emptyBoard[5][5] = ' ';



    }

    void printBoard()
    {
        cout << "   0   1   2   3   4   5  " << endl;
        for (int x=0; x<6; x++) //going down values
        {
            cout << x << " |";
            for (int y=0; y<6; y++) //going horizontal values
            {
                if (board[x][y] == ' ')
                    cout << emptyBoard[x][y] << " | ";
                else
                    cout << board[x][y] << " | ";
            }
            cout << endl;

        }
    }

    void mySwap ( int startY, int startX, int endY, int endX)
    {
        char temp = board[startY][startX];
        board[startY][startX] = board[endY][endX];
        board[endY][endX] = temp;
    }

    void pieceEat ( int startY, int startX, int endY, int endX)
    {
        board[endY][endX] = board[startY][startX]; //assigns second square to first square's piece value
        board[startY][startX] = ' '; //erases first square
    }

    bool specialStarCheck (int endY, int endX)
    {
        if ((emptyBoard[endY][endX]) == '*') {
            char diceAnswer;
            int diceRoll;
            cout << "You have landed on a special square. ";
            cout << "This dice roll will allow you to win another turn if you roll an even number. ";
            cout << "Would you like to roll the dice? Answer y or n.";
            cin >> diceAnswer;

            if (diceAnswer == 'y') {
                cout << "The dice is being rolled. If the roll is an even number, you will get an extra concurrent turn."<< endl << endl;
                diceRoll = rand() % 6 + 1;
                cout << "Your dice roll was " << diceRoll << ". " << endl;

                if (diceRoll % 2 == 1) {
                    cout << "Your dice roll was odd so you don't get another turn. Try again next time." << endl;
                    return false;
                }
                if (diceRoll % 2 == 0) {
                    cout << "Nice job!" << endl << "You rolled an even number so you get another turn. " << endl;
                    turn = turn - 1; //sets turn back so that player can go again
                    return true;
                }
            }
            if (diceAnswer == 'n') {
                return false;
            }


        }
        else {
            return false;
        }
    }

    //PRE CONDITION: takes the square values of where to and what user wants to move checks if the piece moves are legal
    bool validator (int startY,  int startX, int endY, int endX) //should this be bool or void?
    {
        // if it's player 1's turn and they DIDN'T choose one of their pieces (VRO), exit
        if( whoseTurn() == 0 && !( board[startY][startX] == 'V' || board[startY][startX] == 'R' || board[startY][startX] == 'O') ) {
            return false;
        }else if ( whoseTurn() == 1 && !(board[startY][startX] == 'v' || board[startY][startX] == 'r' || board[startY][startX] == 'o')) {
            // if it's player 2's turn and they DIDN'T choose one of their pieces (vro), exit
            return false;
        }

        if (( board[startY][startX] == 'V') && ( board[endY][endX] == 'v' )) {
            pieceEat(startY, startX, endY, endX);
            return true;
        }

        if (( board[startY][startX] == 'O' || board[startY][startX] == 'R') && ( board[endY][endX] == 'v' || board[endY][endX] == 'o')) {
            pieceEat(startY, startX, endY, endX);
            return true;
        }

        if (( board[startY][startX] == 'O' || board[startY][startX] == 'R') && (board[endY][endX] == 'r')) {
            pieceEat(startY, startX, endY, endX);
            cout << "Player one has won the game!";
            finished = true;
            return true;
        }

        if (( board[startY][startX] == 'v') && ( board[endY][endX] == 'V' )) {
            pieceEat(startY, startX, endY, endX);
            return true;
        }

        if (( board[startY][startX] == 'o' || board[startY][startX] == 'r') && ( board[endY][endX] == 'V' || board[endY][endX] == 'O')) {
            pieceEat(startY, startX, endY, endX);
            return true;
        }

        if (( board[startY][startX] == 'o' || board[startY][startX] == 'r') && (board[endY][endX] == 'R')) {
            pieceEat(startY, startX, endY, endX);
            cout << "Player two has won the game!";
            finished = true;
            return true;
        }


        if (board[endY][endX] == ' ') { //checks empty space
            if (toupper( board[startY][startX] ) == 'V') {
                if (startY == endY) { //checks that the move is in the same row
                    if (((startX + 1) == endX) || ((startX - 1 == endX))) { //checks that the move is only moving one square
                        mySwap(startY, startX, endY, endX);
                        return true;

                    }
                }
            } else if ( toupper( board[startY][startX] ) == 'R' || toupper( board[startY][startX] ) == 'O') { //should this be else or something different?
                if (startX == endX) {//checks that the moves are in the same column
                    if (((startY + 1) == endY) || ((startY - 1)) == endY) {
                        mySwap(startY, startX, endY, endX);
                        return true;
                    }
                }
            }
        }
        cout << "Move is not valid, please try again. " << endl;
        return false;

    }

    void nextTurn (){
        turn++; //keeping track turn based on even or odd
        if (turn > 25) {
            finished = true;
        }
    }

    int whoseTurn(){
        return turn % 2; //returns 1 or 0 based on whose turn it is
    }
    /*void printEmptyBoard()
    {
        cout << "   0   1   2   3   4   5  " << endl;
        for (int x=0; x<6; x++) //going down values
        {
            cout << x << " |";
            for (int y=0; y<6; y++) //going horizontal values
            {
                cout << board[x][y] << " | ";
            }
            cout << endl;

        }
    }*/

private:
    char board[6][6];
    char emptyBoard[6][6];

    int turn = 0;

};

int main()
{

    board board;
    class board emptyboard; //why do I have to add class here and not the one above???^
    board.initializeBoard();
    board.initializeEmptyBoard();
    board.printBoard();
    srand (time(NULL));
    int startY, startX, endY, endX;
    while(board.finished == false){
        //board.printBoard(); think this was in the wrong place?
        cout << endl;
        if(board.whoseTurn() == 0) {
            cout << "Player one: ";
        } else {
            cout << "Player two: ";
        }
        cout << "Enter the coordinates of the square with the piece you want to move: 'yx' :";
        cin >> startY;
        cin >> startX;
        cout << endl << "Enter the coordinates of the square to which you want to move the piece: 'yx' :";
        cin >> endY;
        cin >> endX;
        if(board.validator(startY, startX, endY, endX)) { //checks if the move is valid for player 1
            board.nextTurn();
            board.printBoard(); //inserted print board here based on Josh's feedback
            board.specialStarCheck (endY, endX);
        }
        else {
            cout << "Invalid move! Try again. " << endl;
        }
    }

//search object oriented programming in c++ this will have the basics of when you design a class
// encapsulation, inheritance, and polymorphism ?!

}
