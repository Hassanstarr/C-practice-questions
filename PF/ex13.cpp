/*

Write a C++ program to implement a simple 3x3 Tic-Tac-Toe game for two players. The program should meet the following requirements:

1- Display the board after each turn.
2- Allow Player X and Player O to take turns entering their moves.
3- Ensure that players can only select an empty cell (denoted by *).
4- After each move, check if there is a winner (three of the same marks in a row, column, or diagonal).
5- End the game when either a player wins or the board is full, in which case, print whether the game was a win or a draw.

*/


#include <iostream>
#include<cstdlib>   // to use system("CLS");
using namespace std;



char check_winner(char board[3][3]){

    int x = 3, y =3;

    for(int i = 0; i < y; i++){
        if(board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != '*'){
            return board[i][0];  // Return winner from a row
        }
        if(board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != '*'){
            return board[0][i];  // Return winner from a column
        }
    }

    if(board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != '*'){
        return board[0][0];  // Return winner from the main diagonal
    }
    if(board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != '*'){
        return board[0][2];  // Return winner from the anti-diagonal
    }

    return '*';  // Return '*' if there's no winner yet
    
}


void player_one(char tic_tac[3][3]){

    while(true){

        int x, y;
        cout << "Player X, enter the x-y coordinates (0, 1, or 2 for each)" << endl;
        cout << "Enter the x (No. of column): ";
        cin >> x;
        cout << "Enter the y (No. of row): ";
        cin >> y;

        if(!(x > 2 || x < 0 || y > 2 || y < 0)){
            if (tic_tac[y][x] == '*') {
                tic_tac[y][x] = 'X'; 
                return;
            } else {
                cout << "That cell is already occupied. Try again." << endl;
            }
        } else {
            cout << "Invalid coordinates. Try again." << endl;
        }

    }

}

void player_two(char tic_tac[3][3]){

    while(true){

        int x, y;
        cout << "Player O, enter the x-y coordinates (0, 1, or 2 for each)" << endl;
        cout << "Enter the x (No. of column): ";
        cin >> x;
        cout << "Enter the y (No. of row): ";
        cin >> y;

        if(!(x > 2 || x < 0 || y > 2 || y < 0)){
            if (tic_tac[y][x] == '*') {
                tic_tac[y][x] = 'O'; 
                return;
            } else {
                cout << "That cell is already occupied. Try again." << endl;
            }
        } else {
            cout << "Invalid coordinates. Try again." << endl;
        }

    }

}

void display(char tic_tac[3][3]) {

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            cout << " " << tic_tac[i][j] << " ";
        }
        cout << endl;
    }
}


int main() {

    int count = 0;
    char ch[3][3];
    bool game_end = false;

    for(int i = 0; i < size(ch); i++){
        for(int j = 0; j < size(ch[0]); j++){
            ch[i][j] = '*';
        }
    }
    
    while(!game_end){

        system("CLS");

        cout<<"Turn "<<count + 1<<endl;

        display(ch);

        if(count % 2 == 0){
            player_one(ch);
        } else {
            player_two(ch);
        }


        char winner = check_winner(ch);
        if(winner != '*') {
            system("CLS");
            display(ch);
            cout<<"Player "<<winner<<" wins!"<<endl;
            game_end = true;
        } else if(count == 8) {
            system("CLS");
            display(ch);
            cout<<"It's a draw!"<< endl;
            game_end = true;
        }


        count++;
    }

    
    return 0;
}