
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void displayBoard(vector<string> &board_array){
            cout << " ---  ---  --- " << endl;

    for (int i = 0; i < board_array.size(); i++){
        if (i == 3 || i == 6){
            cout << endl;
            cout << " ---  ---  --- " << endl;
        }
        cout << "| " << board_array.at(i) << " |";
    }

    cout << " \n ---  ---  --- " << endl;

}

void Player1(vector<string> &board_array, string &name1){
    cout << endl;
    cout << name1 << "'s Turn (Your Symbol is X)" << endl;
    cout << "Please pick a number from 1-9 which holds *" << endl;;

    cout << endl;
    cout << endl;
    cout << "Enter Number: ";

    bool correct_number_not_entered = true;

    while (correct_number_not_entered){
        int number_chosen;
        cin >> number_chosen;

        if (board_array.at(number_chosen-1) == "*"){
           board_array.at(number_chosen-1) = "X";
           correct_number_not_entered = false;
        }
        else{
            cout << "Enter Again, Spot already filled: ";
        }
    }

    cout << endl;

}

void Player2(vector<string> &board_array, string &name2){
    cout << endl;
    cout << name2 << "'s Turn (Your Symbol is O)" << endl;
    cout << "Please pick a number from 1-9 which holds *" << endl;;

    cout << endl;
    cout << "Enter Number: ";

    bool correct_number_not_entered = true;

    while (correct_number_not_entered){
        int number_chosen;
        cin >> number_chosen;

        if (board_array.at(number_chosen-1) == "*"){
           board_array.at(number_chosen-1) = "O";
           correct_number_not_entered = false;
        }
        else{
            cout << "Enter Again, Spot already filled: ";
        }
    }

    cout << endl;
}



bool winGame(vector<string> &board_array){
    if( 
    (board_array.at(0) == "O" && board_array.at(1) == "O" && board_array.at(2) == "O")||    
    (board_array.at(3) == "O" && board_array.at(4) == "O" && board_array.at(5) == "O")||
    (board_array.at(6) == "O" && board_array.at(7) == "O" && board_array.at(8) == "O")||
    (board_array.at(0) == "O" && board_array.at(3) == "O" && board_array.at(6) == "O")||
    (board_array.at(1) == "O" && board_array.at(4) == "O" && board_array.at(7) == "O")||
    (board_array.at(2) == "O" && board_array.at(5) == "O" && board_array.at(8) == "O")||
    (board_array.at(0) == "O" && board_array.at(4) == "O" && board_array.at(8) == "O")||
    (board_array.at(2) == "O" && board_array.at(4) == "O" && board_array.at(6) == "O")||
    (board_array.at(0) == "X" && board_array.at(1) == "X" && board_array.at(2) == "X")||
    (board_array.at(3) == "X" && board_array.at(4) == "X" && board_array.at(5) == "X")||
    (board_array.at(6) == "X" && board_array.at(7) == "X" && board_array.at(8) == "X")||
    (board_array.at(0) == "X" && board_array.at(3) == "X" && board_array.at(6) == "X")||
    (board_array.at(1) == "X" && board_array.at(4) == "X" && board_array.at(7) == "X")||
    (board_array.at(2) == "X" && board_array.at(5) == "X" && board_array.at(8) == "X")||
    (board_array.at(0) == "X" && board_array.at(4) == "X" && board_array.at(8) == "X")||
    (board_array.at(2) == "X" && board_array.at(4) == "X" && board_array.at(6) == "X") ){
        return true;
    }
    else{
        return false;
    }
}

bool gameDraw(vector<string> &board_array){

    if ( (board_array.at(0) != "*") &&
            (board_array.at(1) != "*") &&
            (board_array.at(2) != "*") &&
            (board_array.at(3) != "*") &&
            (board_array.at(4) != "*") &&
            (board_array.at(5) != "*") &&
            (board_array.at(6) != "*") &&
            (board_array.at(7) != "*") &&
            (board_array.at(8) != "*") ){
        return true;
    }
    else{
        return false;
    }
}


int main(){
    string name1;
    string name2;

    cout << "Please enter the name of Player 1: ";
    cin >> name1;
    cout << "Please enter the name of Player 2: ";
    cin >> name2;
    cout << endl;
    cout << name1 << " and " << name2 << " welcome to the Tic-Tac-Toe game." << endl;

    vector<string> board_array {"*","*","*","*","*","*","*","*","*"};
    displayBoard(board_array);

    cout << endl;
    bool whoWon;

    while (winGame(board_array) != true){
    
        Player1(board_array,name1);
        whoWon = true;
        winGame(board_array);
        gameDraw(board_array);
        if (winGame(board_array) == 1 || gameDraw(board_array) == 1){
            displayBoard(board_array);
            break;
        }

        displayBoard(board_array);


        Player2(board_array,name2);
        whoWon = false;
        winGame(board_array);
        gameDraw(board_array);
        if (winGame(board_array) == 1 || gameDraw(board_array) == 1){
            displayBoard(board_array);
            break;
        }


        displayBoard(board_array);

    }
    
    if (whoWon == true && gameDraw(board_array) == 0){
        cout << "Congragulations " << name1 << " you won!" << endl;
    }
    else if (whoWon == false && gameDraw(board_array) == 0){
        cout << "Congragulations " << name2 << " you won!" << endl;
    }

    else if(gameDraw(board_array) == 1){
        cout << "It was a tie. Better Luck Next Time" << endl;
    }

    return 0;
}
