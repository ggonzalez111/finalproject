#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <chrono>

using namespace std;

class board
{
public:

    bool finished = false;

    void initializeBoard()
    {
        board[0][0] = 'O', //PLAYER ONE IS UPPERCASE
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
        board[1][5] = 'v', // PLAYER TWO IS LOWERCASE
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
    bool secretBunny(int endY, int endX) {
        char choice;
        int bigCounter = 0;
        if (endY == 2 && endX == 3)
        do {

            char magicLetter;
            int total(0);
            int counter(0);

            int numEntries;
            string sentence = "";
            string outputSentence;
            double bunnyNumber;

            cout << "Congratulations! you have landed on a the secret bunny's lair square! There is a wizard bunny who lives in this " << endl;
            cout << "square and he will perform secret calculations. He has a secret algorithm where certain numbers are associated with certain numbers." << endl;
            cout << "enter however many letters you want to give to the bunny so he  can run his magical calculations!" << endl << endl;
            cout << "How many magic letters (between A and H in the alphabet) would you like to enter? ";
            cin >> numEntries;
            cout << endl;
            newLine();

            do {
                cout << "Enter magic letter " << counter + 1 << ": ";
                cin >> magicLetter;
                newLine();

                if (magicLetter == 'a' || magicLetter == 'A') {
                    total += 7;
                } else if (magicLetter == 'b' || magicLetter == 'B') {
                    total += 5;
                } else if (magicLetter == 'c' || magicLetter == 'C') {
                    total += 2;
                } else if (magicLetter == 'd' || magicLetter == 'D') {
                    total += 9;
                } else if (magicLetter == 'e' || magicLetter == 'E') {
                    total += 2;
                } else if (magicLetter == 'f' || magicLetter == 'F') {
                    total += 9;
                } else if (magicLetter == 'g' || magicLetter == 'G') {
                    total += 4;
                } else {
                    cout << "Invalid input!" << endl;
                    counter--;
                }
                counter++;

            } while (counter < numEntries);
            bunnyNumber = total * 1.0 / numEntries;
            sentence = "The magic bunny has decided that your magic calculation is ";
            cout << sentence << bunnyNumber << ". " << endl << endl;

            if (bunnyNumber >= 4.0) {
                cout << "Your bunny calculation is pretty high!" << endl;
                cout << "Congratulations, you have won an extra turn! Thanks bunny!" << endl;
                turn = turn -1;
                return true;
            }

            if (bunnyNumber >= 2.0 && bunnyNumber < 4.0) {
                cout << "Your bunny calculation is somewhere in the middle, it's not as high as it \n";
                cout << "could be, so you do not get another turn!" << endl;
                return false;
            }

            if (bunnyNumber < 2.0) {
                cout << "Your bunny calculation is so low. Sorry, no extra turns. \n";
                return false;
            }
            cout << "Again? y or no" << endl;
            cin >> choice;
            newLine();
            cout << endl;
            bigCounter++;

        }
        while (choice == 'y' && bigCounter < 3 || choice == 'Y' && bigCounter < 3);
    }
        //PRECONDITION: USER ENTERS EXCESS INPUT
    void newLine()
    {
        char c;
        do
        {
            cin.get(c);
        }
        while (c != '\n');
    }
    //POST CONDITION: EXCESS INPUT IS DISCARDED FROM THE STREAM

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

    bool specialHashtagCheck (int endY, int endX, ifstream& inputFile, ifstream& inputFileAnswer) {
        if ((emptyBoard[endY][endX]) == '#') {
            string theQuestion;
            string correctAnswer;
            int i=0;
            int playerAnswer;
            char mathAnswer;
            char startGame;

            cout<< "you have landed on a special square." << endl;
            cout << "If you answer this simple problem in less than 5 seconds you will get an additional turn." << endl;
            cout << "Would you like to try? Answer y or n. " << endl;
            cin >> mathAnswer;
            newLine();
            if (mathAnswer == 'n') {  //do the case sensitive upper thing
                cout << "You entered no, so the game will continue.";
                return false;
            }
            if (mathAnswer == 'y') { //do the case sensitive upper thing
                cout << "Get ready to play. “As soon as the question appears, you will have 5 seconds to answer correctly.";
                cout << '\n' << "Press a key to continue...";
                cin >> startGame;
                newLine();
                getline(inputFile, theQuestion); //have to get the sentence from the file and assign it to the question
                while(i<questionIndex){
                    i++;
                    getline(inputFile, theQuestion);
                    questionIndex++;
                }
                cout << theQuestion << endl;
                cin >> playerAnswer;
                inputFileAnswer >> correctAnswer;
                int stringInteger = stoi(correctAnswer);
                if (playerAnswer == stringInteger) {
                    cout << endl << "Great job, you get another turn! " << endl;
                    turn = turn -1;
                    return true;
                }
                if (stringInteger != playerAnswer) {
                    cout << endl << "Sorry, that's not the right answer." << endl;
                    cout << "You don't get another turn." << endl;
                    return false;
                }
                if (!inputFileAnswer) { // file couldn't be opened
                    cerr << "Error: answer file could not be opened." << endl;
                    exit(1);
                }
                if (!inputFile) { // file couldn't be opened
                    cerr << "Error: question file could not be opened." << endl;
                    exit(1);
                }
            }
        }
        return false;
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
            newLine();
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
        cout << "that move is not valid. " << endl;
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

private:
    char board[6][6];
    char emptyBoard[6][6];
    int turn = 0;
    int questionIndex = 0;
};

int main()
{
    ifstream inputFile( "/Users/giselle/CLionProjects/finalproject/specialsquare.txt"); //pwd in terminal for path
    ifstream inputFileAnswer("/Users/giselle/CLionProjects/finalproject/problemanswers.txt"); //pwd in terminal for path
    board board;
    char directionsRead;
    board.initializeBoard();
    board.initializeEmptyBoard();
    srand (time(NULL)); //seeding the random number generator

    cout << "Hello! Welcome to BEEP BOOP!" << endl << endl;
    cout <<"______**"<< endl;
    cout <<"____*                  ________     ______   _______       _____             _______           _____             ___          ______        "<< endl;
    cout <<"__*___****            |         \\  |         |           |       \\          |        \\       /       \\        /       \\      |      \\" << endl;
    cout <<"_*__*______*          |          | |         |           |       |          |          |    /         \\     /          \\     |       |" << endl;
    cout <<"*__*___*_*__*         |         /  |         |           |_____ /           |         /    |     |     |   |     |     |     |      /" << endl;
    cout <<"*___*__*__*__*        |-------\\    |____     |_____      |                  |-------\\      |     |     |   |     |     |     |-----" << endl;
    cout <<"_*___*___*___*        |         \\  |         |           |                  |         \\    |     |     |   |     |     |     |" << endl;
    cout <<"__*____*____*         |          | |         |           |                  |           |  |     |     |   |     |     |     |" << endl;
    cout <<"___*_______*          |         /  |         |           |                  |          /    \\          /    \\         /      |" << endl;
    cout <<"_____*____*           |_______/    |______   |______     |                  |________/       \\________/       \\______/       |" << endl;
    cout <<"_______**" << endl;
    cout << endl << endl;
    cout << "               *~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~" << endl<<endl<<endl;

    cout<< "Welcome to the game BEEP BOOP! this is a game that's set up on a checkboard-type board. The game consists of two players." << endl;
    cout << "The x values are labeled across the top of the board and the y values of the board are labeled to the left going down the side." << endl;
    cout << "Together, the y and x values create a unique label for each square. You will type in your values ' y space x enter' into the keyboard." << endl;
    cout << "The game will alternate between the two players unless someone lands on a special character, a * or a # which are labeled the board squares." << endl;
    cout << "These squares give you a chance to win another turn. Player one is the capital figures: V, R, and O. Player two is the lower case figures: v, r, and o. " << endl;
    cout << "The V's can only move left to right, either way, one square at a time. They can eat only other V characters, not the R's or the O's. " << endl;
    cout << "The R's and O's only move vertically but they can eat any piece. The only difference is that the R's are the kings on the board. " << endl;
    cout << "If you eat an opponent's R piece, then you automatically win the game and it's over! The only other way to win the game " << endl;
    cout << "is to take a V piece across the board and back without getting eaten. There are also special surprise squares that" << endl;
    cout << "are unlabeled and will take you to a mini challenge! Good luck! " << endl;
    cout << endl << endl << endl << endl;
    cout << "Press s to continue!";
    cin >> directionsRead;
    board.newLine();
    cout <<  endl << endl << endl;
    board.printBoard();
    int startY, startX, endY, endX;
    while(board.finished == false){
        cout << endl;
        if(board.whoseTurn() == 0) {
            cout << "Player one: ";
        } else {
            cout << "Player two: ";
        }
        cout << "Enter the coordinates of the square with the piece you want to move: 'yx' :";
        cin >> startY;
        cin >> startX;
        board.newLine();
        cout << endl << "Enter the coordinates of the square to which you want to move the piece: 'yx' :";
        cin >> endY;
        cin >> endX;
        board.newLine();
        if(board.validator(startY, startX, endY, endX)) { //checks if the move is valid for player 1
            board.nextTurn();
            board.printBoard(); //inserted print board here based on Josh's feedback
            board.specialStarCheck (endY, endX);
            board.specialHashtagCheck (endY, endX, inputFile, inputFileAnswer);
            board.secretBunny(endY, endX);
        }
        else {
            board.printBoard();
            cout << "Invalid move! Try again. " << endl;
        }
    }
//FXNS: extra input throw out
//win if v's get across the board three times
//timer
//win screen
//lose screen
//colors of pieces
//secret special squares
}

