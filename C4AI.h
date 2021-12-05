//Made by Brycen Tanaka
#include "board.h"
#include <cmath>
#include <iostream>

using namespace std;

class C4AI{
    public:
    C4AI(){Strength = 41;}

    C4AI(int strength){Strength = strength;}

    int evaluate(C4 & board, int player, int pos){
        if (board.move(pos) != -1){
            
            long long bitboard;
            long long ebitboard;

            if (player == 0){
                    bitboard = board.black();
                    ebitboard = board.red();
            } else {
                    bitboard = board.red();
                    ebitboard = board.black();
            }

            int score;

            // check if win is possible, or if board state is a draw
            if (board.win(bitboard)){
                score = 10000;
                board.undomove();
                return score;
            } else if (board.win(ebitboard)){
                score = -10000;
                board.undomove();
                return score;
            }else if (board.movescount() >= 41){
                score = 0;
                board.undomove();
                return score;
            } 

            //assign score based on distance to center
            score = (4 - abs(3 - pos)) * 10;

            //assign points based on # of twos and threes in a row
            long long target = bitboard & (bitboard >> 1);
            if (target != 0){
                int count = 0;
                while (target > 0){
                    target = target & (target - 1);
                    count++;
                }
                score += count * 5;
            }

            target = bitboard & (bitboard >> 6);
            if (target != 0){
                int count = 0;
                while (target > 0){
                    target = target & (target - 1);
                    count++;
                }
                score += count * 5;
            }

            target = bitboard & (bitboard >> 7);
            if (target != 0){
                int count = 0;
                while (target > 0){
                    target = target & (target - 1);
                    count++;
                }
                score += count * 5;
            }

            target = bitboard & (bitboard >> 8);
            if (target != 0){
                int count = 0;
                while (target > 0){
                    target = target & (target - 1);
                    count++;
                }
                score += count * 5;
            }
            
            target = bitboard & (bitboard >> 1) & (bitboard >> 2);
            if (target != 0){
                int count = 0;
                while (target > 0){
                    target = target & (target - 1);
                    count++;
                }
                score += count * 15;
            }

            target = bitboard & (bitboard >> 6) & (bitboard >> 12);
            if (target != 0){
                int count = 0;
                while (target > 0){
                    target = target & (target - 1);
                    count++;
                }
                score += count * 15;
            }

            target = bitboard & (bitboard >> 7) & (bitboard >> 14);
            if (target != 0){
                int count = 0;
                while (target > 0){
                    target = target & (target - 1);
                    count++;
                }
                score += count * 15;
            }
            
            target = bitboard & (bitboard >> 8) & (bitboard >> 16);
            if (target != 0){
                int count = 0;
                while (target > 0){
                    target = target & (target - 1);
                    count++;
                }
                score += count * 15;
            }

            //assign points based on interference with opponent
            target = bitboard & (ebitboard >> 1);
            if (target != 0){
                int count = 0;
                while (target > 0){
                    target = target & (target - 1);
                    count++;
                }
                score += count * 4;
            }

            target = bitboard & (ebitboard >> 6);
            if (target != 0){
                int count = 0;
                while (target > 0){
                    target = target & (target - 1);
                    count++;
                }
                score += count * 4;
            }

            target = bitboard & (ebitboard >> 7);
            if (target != 0){
                int count = 0;
                while (target > 0){
                    target = target & (target - 1);
                    count++;
                }
                score += count * 4;
            }

            target = bitboard & (ebitboard >> 8);
            if (target != 0){
                int count = 0;
                while (target > 0){
                    target = target & (target - 1);
                    count++;
                }
                score += count * 4;
            }
            
            target = bitboard & (ebitboard >> 1) & (ebitboard >> 2);
            if (target != 0){
                int count = 0;
                while (target > 0){
                    target = target & (target - 1);
                    count++;
                }
                score += count * 12;
            }

            target = bitboard & (ebitboard >> 6) & (ebitboard >> 12);
            if (target != 0){
                int count = 0;
                while (target > 0){
                    target = target & (target - 1);
                    count++;
                }
                score += count * 12;
            }

            target = bitboard & (ebitboard >> 7) & (ebitboard >> 14);
            if (target != 0){
                int count = 0;
                while (target > 0){
                    target = target & (target - 1);
                    count++;
                }
                score += count * 12;
            }
            
            target = bitboard & (ebitboard >> 8) & (ebitboard >> 16);
            if (target != 0){
                int count = 0;
                while (target > 0){
                    target = target & (target - 1);
                    count++;
                }
                score += count * 12;
            }

            //subtract point based on strength of enemy position
            if (target != 0){
                int count = 0;
                while (target > 0){
                    target = target & (target - 1);
                    count++;
                }
                score -= count * 5;
            }

            target = ebitboard & (ebitboard >> 6);
            if (target != 0){
                int count = 0;
                while (target > 0){
                    target = target & (target - 1);
                    count++;
                }
                score -= count * 5;
            }

            target = ebitboard & (ebitboard >> 7);
            if (target != 0){
                int count = 0;
                while (target > 0){
                    target = target & (target - 1);
                    count++;
                }
                score -= count * 5;
            }

            target = ebitboard & (ebitboard >> 8);
            if (target != 0){
                int count = 0;
                while (target > 0){
                    target = target & (target - 1);
                    count++;
                }
                score -= count * 5;
            }
            
            target = ebitboard & (ebitboard >> 1) & (ebitboard >> 2);
            if (target != 0){
                int count = 0;
                while (target > 0){
                    target = target & (target - 1);
                    count++;
                }
                score -= count * 15;
            }

            target = ebitboard & (ebitboard >> 6) & (ebitboard >> 12);
            if (target != 0){
                int count = 0;
                while (target > 0){
                    target = target & (target - 1);
                    count++;
                }
                score -= count * 15;
            }

            target = ebitboard & (ebitboard >> 7) & (ebitboard >> 14);
            if (target != 0){
                int count = 0;
                while (target > 0){
                    target = target & (target - 1);
                    count++;
                }
                score -= count * 15;
            }
            
            target = ebitboard & (ebitboard >> 8) & (ebitboard >> 16);
            if (target != 0){
                int count = 0;
                while (target > 0){
                    target = target & (target - 1);
                    count++;
                }
                score -= count * 15;
            }

            //subtract points based on opponents interference
            target = ebitboard & (bitboard >> 1);
            if (target != 0){
                int count = 0;
                while (target > 0){
                    target = target & (target - 1);
                    count++;
                }
                score -= count * 4;
            }

            target = ebitboard & (bitboard >> 6);
            if (target != 0){
                int count = 0;
                while (target > 0){
                    target = target & (target - 1);
                    count++;
                }
                score -= count * 4;
            }

            target = ebitboard & (bitboard >> 7);
            if (target != 0){
                int count = 0;
                while (target > 0){
                    target = target & (target - 1);
                    count++;
                }
                score -= count * 4;
            }

            target = ebitboard & (bitboard >> 8);
            if (target != 0){
                int count = 0;
                while (target > 0){
                    target = target & (target - 1);
                    count++;
                }
                score -= count * 4;
            }
            
            target = ebitboard & (bitboard >> 1) & (bitboard >> 2);
            if (target != 0){
                int count = 0;
                while (target > 0){
                    target = target & (target - 1);
                    count++;
                }
                score -= count * 12;
            }

            target = ebitboard & (bitboard >> 6) & (bitboard >> 12);
            if (target != 0){
                int count = 0;
                while (target > 0){
                    target = target & (target - 1);
                    count++;
                }
                score -= count * 12;
            }

            target = ebitboard & (bitboard >> 7) & (bitboard >> 14);
            if (target != 0){
                int count = 0;
                while (target > 0){
                    target = target & (target - 1);
                    count++;
                }
                score -= count * 12;
            }
            
            target = ebitboard & (bitboard >> 8) & (bitboard >> 16);
            if (target != 0){
                int count = 0;
                while (target > 0){
                    target = target & (target - 1);
                    count++;
                }
                score -= count * 12;
            }

            //preventing opponent from winning
            if ((bitboard & (ebitboard >> 1) & (ebitboard >> 2) & (ebitboard >> 3)) != 0){
                score += 500;
            }
            if ((bitboard & (ebitboard >> 6) & (ebitboard >> 12) & (ebitboard >> 18)) != 0){
                score += 500;
            }
            if ((bitboard & (ebitboard >> 7) & (ebitboard >> 14) & (ebitboard >> 21)) != 0){
                score += 500;
            }
            if ((bitboard & (ebitboard >> 8) & (ebitboard >> 16) & (ebitboard >> 24)) != 0){
                score += 500;
            }

            if ((ebitboard & (ebitboard >> 1) & (ebitboard >> 2) & (bitboard >> 3)) != 0){
             score += 500;
            }
            if ((ebitboard & (ebitboard >> 6) & (ebitboard >> 12) & (bitboard >> 18)) != 0){
                score += 500;
            }
            if ((ebitboard & (ebitboard >> 7) & (ebitboard >> 14) & (bitboard >> 21)) != 0){
                score += 500;
            }
            if ((ebitboard & (ebitboard >> 8) & (ebitboard >> 16) & (bitboard >> 24)) != 0){
                score += 500;
            }

            if ((ebitboard & (bitboard >> 1) & (ebitboard >> 2) & (ebitboard >> 3)) != 0){
                score += 500;
            }
            if ((ebitboard & (bitboard >> 6) & (ebitboard >> 12) & (ebitboard >> 18)) != 0){
                score += 500;
            }
            if ((ebitboard & (bitboard >> 7) & (ebitboard >> 14) & (ebitboard >> 21)) != 0){
                score += 500;
            }
            if ((ebitboard & (bitboard >> 8) & (ebitboard >> 16) & (ebitboard >> 24)) != 0){
                score += 500;
            }

            if ((ebitboard & (ebitboard >> 1) & (bitboard >> 2) & (ebitboard >> 3)) != 0){
             score += 500;
            }
            if ((ebitboard & (ebitboard >> 6) & (bitboard >> 12) & (ebitboard >> 18)) != 0){
                score += 500;
            }
            if ((ebitboard & (ebitboard >> 7) & (bitboard >> 14) & (ebitboard >> 21)) != 0){
                score += 500;
            }
            if ((ebitboard & (ebitboard >> 8) & (bitboard >> 16) & (ebitboard >> 24)) != 0){
                score += 500;
            }
           
            board.undomove();
            return score;
        }
        return -1;
    }


    int alphabeta(C4 & board, int depth, int alpha, int beta, int player, LLDarr & alreadyseen, bool maximizing){        
        if (depth > 0){
            if (maximizing){
                int score = alphabeta(board, depth - 1, alpha, beta, player, alreadyseen, false);
                for (int i = 1; i < 7; i++){
                    if (board.move(i) != -1){
                        //check for repeated board states
                        if (alreadyseen.twoinarow(board.black(), board.red())){
                            board.undomove();
                            break;
                        } else {
                            alreadyseen.insert(board.black());
                            alreadyseen.insert(board.red());
                        }

                        //recursive call of alpha-beta 
                        int value = alphabeta(board, depth - 1, alpha, beta, player, alreadyseen, false);
                        
                        //check for break states
                        if (value == 10000){
                            board.undomove();
                            return value;
                        }
                        
                        if (value > score){
                            score = value;
                        }

                        if (value >= beta){
                            board.undomove();
                            break;
                        }                        

                        if (value > alpha){
                            alpha = value;
                        }
                        
                        board.undomove();
                    }   
                }
                return score;
            } else {
                int score = alphabeta(board, depth - 1, alpha, beta, player, alreadyseen, false);
                for (int i = 1; i < 7; i++){
                    if(board.move(i) != -1){

                        //check for repeated board states
                        if (alreadyseen.twoinarow(board.black(), board.red())){
                            board.undomove();
                            break;
                        } else {
                            alreadyseen.insert(board.black());
                            alreadyseen.insert(board.red());
                        }

                        //recursive call of alpha-beta 
                        int value = alphabeta(board, depth - 1, alpha, beta, player, alreadyseen, true);
                        
                        //check for break states
                        if (value == -10000){
                            board.undomove();
                            return value;
                        }

                        if (value < score){
                            score = value;
                        }

                        if (value <= alpha){
                            board.undomove();
                            break;
                        }

                        if (value < beta){
                            beta = value;
                        }

                        board.undomove();
                    }
                }
                return score;
            }
        } else {
            //evaluate leaf nodes
            int score = evaluate(board, player, 0);
            for (int i = 1; i < 7; i++){
                int eval = evaluate(board, player, i);
                if (eval != -1){
                    if (maximizing){
                        if (eval > score){
                            score = eval;
                        }
                    } else {
                        if (eval < score){
                            score = eval;
                        }
                    }
                }
            }
            return score;
        }
    }

    void makemove(C4 & board){
        int max = 0;
        int pos = 0;
        int player = board.movescount() % 2;
        LLDarr seen;

        for (int i = 0; i < 7; i++){
            if (board.move(i) != -1){
                int score = alphabeta(board, Strength, -99999, 99999, player, seen, true);
                if (score >= max){
                    max = score;
                    pos = i;
                }
                board.undomove();
            }
        }
        board.move(pos);
    }

    private:
    int Strength;
}; 