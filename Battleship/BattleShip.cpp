#include <cstdlib>
#include "BattleShip.h"
#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
using namespace std;

BattleShip::BattleShip(){


		numAns=0;
		ans='/0';
		answer=0;
		hit=false;
        numHit=0;
		numDestroyed=0;
		score=0;
}

BattleShip::BattleShip(int **matrix, int answer){
    int numHit=0;
    bool hit=false;
    int score=0;
    int numDestroyed=0;

    this->matrix = new char*[10];
    for(int i=0; i<10; ++i){
          this->matrix[i] = new char[10];
        }

    for(int w=0;w<10;w++){
            for(int x=0;x<10;x++){
                this->matrix[w][x]=matrix[w][x];
            }
    }

    for (int k=0;k<numAns;k++){
         this->answer[k]=answer[k];
    }

}


BattleShip::~BattleShip(){
    for(int i=0;i<10;i++){
        delete [] matrix[i];
    }
}




int BattleShip::printInstruction(){
    int a;
    cout<<"\tBATTLESHIP\t"<<endl;
    cout<<"\nWelcome to a game of battleship"<<endl;
    cout<<"This is a one player game it will be the player vs the computer"<<endl;
    cout<<"a standard game of battleship is played on a 10by10 grid"<<endl;
    cout<<"To play this game enter 1 to quit enter 0"<<endl;
    cin>>a;
    return a;
}

void BattleShip::printGame(){
    int i,k,j,w,z;
    int count1=0;
    int count2=0;
    cout<<"enemy board"<<endl;
    for(z=0;z<10;z++){
        cout<<"  "<<count2<<"  ";
        count2++;
    }
    count2=0;
    for(i=0;i<10;i++){
        for(w=0;w<10;w++){
            cout<<"+---";
        }
        cout<<"+\n"<<count1<" ";
        for(k=0;k<10;k++){
        cout<<"| ? ";
        }
        cout<<"|\n";
        count1++;
    }
    count1=0;
    cout<<"\n\nyour board";
    for(z=0;z<10;z++){
        cout<<"  "<<count2<<"  ";
        count2++;
    }
    for(i=0;i<10;i++){
           for(w=0;w<10;w++){
                cout<<"+---";
            }
            cout<<"+\n"<<count1<<" ";
            for(k=0;k<10;k++){
            cout<<"|   ";
            }
            cout<<"|\n";
            count1++;
    }
    cout<<"now you need to set up your playing board please place your ships with proper size";
    cout<<"you are given 5 ships\n";
    cout<<"#1:carrier size=5\n#2:Battleship size=4\n;
    cout<<"#3:cruiser size=3\n#4:Submarine size=3;
    cout<<"#5:destroyer size=2\n;
    setBoard();
}

void BattleShip::setBoard(){
    vector<int> finder;
    cout<<"please insert grid numbers for your ships";
     int i,k,w,r;
     int count1=0;
     int count2=0;
     int vecSize;
     for(k=0;k<10;k++){
        cout<<"+";
        for (i=0;i<10;i++){
            cout<<"---+";
        }
        cout<<"\n";
        cout<<"| ";
        for (i=0;i<10;i++){
            cout<<count1<<" | ";
            count1++;
        }
        cout<<"\n";
    }
    for(int i=0;i<5;i++){
     cin>>answer[i];
     r=answer[i];
    w=r;
    while(w>0){
    finder.push_back(w%10);
        w=w/10;
        count2++;
    }
    }
    vecSize=finder.size();
    int count=0;
    int kill=0;
    for(k=0;k<10;k++){
                cout<<"+";
                for (i=0;i<10;i++){
                    cout<<"---+";
                }
                cout<<"\n| ";
                for (i=0;i<10;i++){
                    kill=0;
                    for(int sera=0;sera<vecSize;sera++){
                        if(count==finder[sera]-1){
                            kill=5;
                        }
                    }
                    if(kill==5){
                        cout<<"B"<<" | ";
                        matrix[k][i]='1';
                    }
                    else {
                        matrix[k][i]= '0';
                        cout<<" "<<" | ";
                    }
                count++;
                }
                cout<<"\n";
                }

            for (i=0;i<10;i++){
                cout<<"+---";
                    }
                cout<<"+\n\n";
}

