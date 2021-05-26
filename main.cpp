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
        board[1][1] = '_',
        board[1][2] = '_',
        board[1][3] = '_',
        board[1][4] = '_',
        board[1][5] = 'v', //GREEN PLAYER IS LOWERCASE
        board[2][0] = 'V',
        board[2][1] = '_',
        board[2][2] = '_',
        board[2][3] = '_',
        board[2][4] = '_',
        board[2][5] = 'v',
        board[3][0] = 'V',
        board[3][1] = '_',
        board[3][2] = '_',
        board[3][3] = '_',
        board[3][4] = '_',
        board[3][5] = 'v',
        board[4][0] = 'V',
        board[4][1] = '_',
        board[4][2] = '_',
        board[4][3] = '_',
        board[4][4] = '_',
        board[4][5] = 'v',
        board[5][0] = 'o',
        board[5][1] = 'o',
        board[5][2] = 'o',
        board[5][3] = 'r',
        board[5][4] = 'o',
        board[5][5] = 'o';



    }

    void printBoard()
    {
        cout << "   0   1   2   3   4   5  " << endl;
        for (int y=0; y<6; y++) //going down values
        {
            cout << y << " |";
            for (int x=0; x<6; x++) //going horizontal values
            {
                cout << board[y][x] << " | ";
            }
            //cout << endl << "  -----------------------" <<
            cout << endl;

        }
    }

private:
    char board[6][6];

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
    board.initializeBoard();
    board.printBoard();
    cout << "The x values for the columns are listed across the top of the board from 0-5 and the y values for the rows are listed on the left side from 0-5.";
    cout << "Enter the square you want to move and to which location in the following format: 'yxyx' :";


}
