#include <iostream>
#include <string>
using namespace std;

class board
{
public:
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

    //make a constant 2d array with the colored squares and check when a piece lands in that squares
    //if it is in a colored square and then trigger the special output
    //use if statement: if there's no character on that square, check if its a special square
    //and output symbol, otherwise output empty square
    //if the square is empty and its a special square output the special character otherwise
    //output the usual empty square

};

int main()
{

    board board;
    class board emptyboard; //why do I have to add class here and not the one above???^
    board.initializeBoard();
    board.initializeEmptyBoard();
    board.printBoard();
   // board.printEmptyBoard();
    cout << "The x values for the columns are listed across the top of the board from 0-5 and the y values for the rows are listed on the left side from 0-5.";
    cout << "Enter the coordinates of the square with the piece you want to move: 'yx' :";


}
