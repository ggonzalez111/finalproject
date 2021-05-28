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

    void mySwap ( int a, int b, int c, int d) //CBR because modifying the value of the variable
    {
        char temp = board[a][b];
        //cout << temp;
       // cout << board[a][b];
       // cout << board[1][0];
        board[a][b] = board[c][d];
       // cout << board[a][b] << temp <<"test" << endl;//the board we want to operate on is inside board object
        board[c][d] = temp;





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


};





int main()
{

    board board;
    class board emptyboard; //why do I have to add class here and not the one above???^
    board.initializeBoard();
    board.initializeEmptyBoard();
    board.printBoard();
   // board.printEmptyBoard();
   int a, b, c, d;
    cout << "The x values for the columns are listed across the top of the board from 0-5 " << endl<<" and the y values for the rows are listed on the left side from 0-5.";
    cout << endl << "Enter the coordinates of the square with the piece you want to move: 'yx' :";
    cin >> a;
    cin >> b;
    cout << endl << "Enter the coordinates of the square to which you want to move the piece: 'yx' :";
    cin >> c;
    cin >> d;
    board.mySwap(a, b, c, d);

    board.printBoard();
//actual board is a member of the board object
//create a function that will let you modify the board class, this should be a member of the board class to
//modify the board array

//possible to create a function to extract things from the board class

//search object oriented programming in c++ this will have the basics of when you design a class
// encapsulation, inheritance, and polymorphism ?!

}
