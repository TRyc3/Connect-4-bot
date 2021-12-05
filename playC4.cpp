#include "C4AI.h"
#include <iostream>

using namespace std;

int main(){
    C4 board;
    C4AI ai;
    int pos;

    board.printboard();
    while (board.win(board.red()) != true && board.win(board.black()) != true && board.movescount() <= 41 ){
        if (board.movescount() % 2 == 1){
            ai.makemove(board);
        } else {
            cin >> pos;
            board.move(pos - 1);
        }
        board.printboard();
        cout << " 1 2 3 4 5 6 7" << endl;
    }

    if (board.win(board.red())){
        cout << "X wins" << endl;
    }else if (board.win(board.black())){
        cout << "O wins" << endl;
    } else {
        cout << "Draw" << endl;
    }
} 