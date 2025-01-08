/*
   Toothpick Game - Instructions

   Write a C++ program to simulate a two-player toothpick game between a human and a computer.
   Implement the following functions:

   1. twothree() - The main game loop function that alternates between the human_turn() and computer_turn() functions until the game ends.

   2. human_turn() - Handles the human’s turn. Prompts the user to pick 1, 2, or 3 toothpicks, checks for valid input, and updates the remaining toothpicks.

   3. computer_turn() - Implements the computer’s strategy based on the following rules:
      - If more than 4 toothpicks remain, the computer picks the same number as the human’s previous move.
      - If 2 to 4 toothpicks remain, the computer picks a number that leaves exactly 1 toothpick for the human.
      - If only 1 toothpick remains, the computer picks it and loses the game.

   Game Objective:
   - The game starts with 23 toothpicks. Players alternate turns, taking 1, 2, or 3 toothpicks per turn.
   - The player who is forced to pick the last toothpick loses the game.

*/



#include <iostream>
using namespace std;

void human_turn(int &t, int &tpk, bool &h_t){
    cout<<"Enter the number of toothpick to take (1, 2, or 3): ";
    cin>>t;

    if(t > 3 || t < 1){
        cout<<"Invalid number!!! can only choice 1, 2, or 3. Try again"<<endl<<endl;
        return;
    }

    if(t > tpk){
        cout<<"Error! can't take "<<t<<" toothpick as only "<<tpk<<" toothpick(s) are left"<<endl;
        return;
    }


    tpk -= t;
    h_t = false;

    cout<<"Human picked  "<<t<<" toothpick(s), now "<<tpk<<" toothpick(s) are left."<<endl;

    if(tpk == 0){
        cout<<endl<<"Human lost HAHAHAHHA"<<endl;
    }

    return;
}

void computer_turn(int &t, int &tpk, bool &h_t){

    if (tpk > 1 && tpk <= 4) {
        t = tpk - 1;
    } 
    else if (tpk == 1) {
        t = 1;
    }

    tpk = tpk - t;
    h_t = true;
    cout<<"Computer picked  "<<t<<" toothpick(s), now "<<tpk<<" toothpick(s) are left."<<endl;

    if(tpk == 0){
        cout<<endl<<"Good Game Human!"<<endl;
        cout<<"Human won"<<endl;
    }
    
}


void twothree(int &tpk){
    int turn;
    bool h_t = true;

    while (tpk > 0){

        if(h_t){
            human_turn(turn, tpk, h_t);
        } else {
            computer_turn(turn, tpk, h_t);
        }

        cout<<endl;
        
    }  
}



int main() {

    int toothpick = 23;

    cout<<"There are "<<toothpick<<" toothpick total who ever picked the last toothpick losses"<<endl;

    twothree(toothpick);

    
    return 0;
}