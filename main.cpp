#include <iostream>
#include <string>
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


    //PRE CONDITION: takes the square values of where to and what user wants to move checks if the piece moves are legal
    bool validator (int a,  int b, int c, int d) //should this be bool or void?
    {
        // if it's player 1's turn and they DIDN'T choose one of their pieces (VRO), exit
        if( whoseTurn() == 0 && !( board[a][b] == 'V' || board[a][b] == 'R' || board[a][b] == 'O') ) {
            return false;
        }else if ( whoseTurn() == 1 && !(board[a][b] == 'v' || board[a][b] == 'r' || board[a][b] == 'o')) {
            // if it's player 2's turn and they DIDN'T choose one of their pieces (vro), exit
            return false;
        }

        if (board[c][d] == ' ') { //checks empty space
            if (toupper( board[a][b] ) == 'V') {
                if (a == c) { //checks that the move is in the same row
                    if (((b + 1) == d) || ((b - 1 == d))) { //checks that the move is only moving one square
                        return true;
                    }
                }
            } else if ( toupper( board[a][b] ) == 'R' || toupper( board[a][b] ) == 'O') { //should this be else or something different?
                if (b == d) {//checks that the moves are in the same column
                    if (((a + 1) == c) || ((a - 1)) == c) {
                        return true;
                    }
                }
            }
        }
        cout << "Move is not valid, please try again. " << endl;
        return false;

    }


    //PRE CONDITION: takes inputs
    void mySwap ( int a, int b, int c, int d)
    {
        char temp = board[a][b];
        board[a][b] = board[c][d];
        board[c][d] = temp;
    }
    //POST CONDITION: swaps values of squares

    void nextTurn (){
        turn++; //keeping track turn based on even or odd
        if (turn > 3) {
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
    int startY, startX, endY, endX;
    while(board.finished == false){
        board.printBoard();
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
            board.mySwap(startY, startX, endY, endX); //enacts the move
            board.nextTurn(); //can go in myswap!
        }
        else {
            cout << "Invalid move! Try again. " << endl;
        }
    }






//search object oriented programming in c++ this will have the basics of when you design a class
// encapsulation, inheritance, and polymorphism ?!

}
