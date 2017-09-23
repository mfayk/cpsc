#include <iostream>
#include <cstdlib>
#include <fstream>
#include "BattleShip.h"
using namespace std;

int main(){
    int *answer;
    char **matrix;
    int k;
    BattleShip n;
    answer= new int[5];
    matrix = new char*[10];
    for(int i=0; i<10; ++i){
        matrix[i] = new char[10];
    }
    n.BattleShip(matrix,answer);
    k=n.printInstruction();
    if(k==1){
        n.printGame();
        n.setBoard();

    }

    for(i=0;i<10;i++){
        delete [] matrix[i];
    }
    delete [] answer;
    return (0);
}
