//Made by Brycen Tanaka
//Based on https://towardsdatascience.com/creating-the-perfect-connect-four-ai-bot-c165115557b0
#ifndef _BOARD_
#define _BOARD_

#include <iostream>
#include <list>
#include <cstdlib>
#include <bitset>
#include "DynamicArray.h"


using namespace std;

class C4{
    public:
    C4(){
        Red = 0LL;
        Black = 0LL;
        MoveCount = 0;
        for (int i = 0; i < 7; i++){
            Height[i] = i * 7;
        }
        Darr Moves;
    }

    void printboard(){
        // i = col
        for (int i = 5; i >= 0; i--){
            int col = i;
            // j = row
            for (int j = 0; j < 7; j++){
                cout << '|';
                if (1LL & (red() >> (col))){         
                    cout << 'X';
                } else if (1LL & (black() >> (col))){
                    cout << 'O';
                } else{
                    cout << ' ';
                }
                col += 7;
            }
            cout << '|' << endl;
        }
        cout << endl;
    }

    long long move(int col){
        //check if col is filled or not
        if (isvalidmove(col)){
            long long bitboard;
            //insert into bitboard
            long long target = 1LL << Height[col];
            
            Height[col]++;
            //even turns are black
            if (MoveCount % 2 == 0){
                Black = Black ^ target;
                bitboard = Black;
            //odd turns are red    
            } else {
                Red = Red ^ target;
                bitboard = Red;
            }
            MoveCount++;
            Moves.insert(col);
            return bitboard;
        }
        return -1LL;      
    }

    void undomove(){
        //undos last move
        MoveCount--;
        Moves.undolast();
        long long target = 0b1111111111111111111111111111111111111111111111111LL;
        //set long long to all ones except undo target
        //uses exclusive or to set long long to all 1's except undo target
        Height[Moves[MoveCount]]--;
        long long insert = 1LL << Height[Moves[MoveCount]];
        target = target ^ insert;
        if (MoveCount % 2 == 0){
            Black = Black & target;
        } else {
            Red = Red & target;
        }
    }

    bool win(long long bitboard){
    //slide bits over to see if 4 in a row
        if ((bitboard & (bitboard >> 1) & (bitboard >> 2) & (bitboard >> 3)) != 0){
            return true;
        }
        if ((bitboard & (bitboard >> 6) & (bitboard >> 12) & (bitboard >> 18)) != 0){
            return true;
        }
        if ((bitboard & (bitboard >> 7) & (bitboard >> 14) & (bitboard >> 21)) != 0){
            return true;
        }
        if ((bitboard & (bitboard >> 8) & (bitboard >> 16) & (bitboard >> 24)) != 0){
            return true;
        }
        return false;
    }

    void operator =(C4 rhs){
        Red = rhs.red();
        Black = rhs.black();

        MoveCount = rhs.movescount();
        Moves = rhs.moves();

        for (int i = 0; i < 7; i++){
            Height[i] = rhs.height()[i];
        }

    }

    bool isvalidmove(int pos){
        if (pos < 7 && pos >= 0){
            long long top = 0b1000000100000010000001000000100000010000001000000LL;
            if ((top & (1LL << Height[pos])) == 0){
                return true;
            }
        }
        return false;
    }

    long long actingplayer(){
        if (MoveCount % 2 == 0){
            return Black;
        } else {
            return Red;
        }
    }

    long long playerjustmoved(){
        if (MoveCount % 2 == 0){
            return Red;
        } else {
            return Black;
        }
    }


    long long red(){return Red;}
    long long black(){return Black;}
    int* height(){return Height;}
    int movescount(){return MoveCount;}
    Darr moves(){return Moves;}

    void setRed(long long red){Red = red;}
    void setBlack(long long black){Black = black;}

    private:
    long long Red;
    long long Black;

    int MoveCount;
    Darr Moves;

    int Height[7];
};

#endif // _BOARD_