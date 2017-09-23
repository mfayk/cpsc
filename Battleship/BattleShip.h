#include <iostream>
#include <fstream>

using namespace std;
class BattleShip
{
	private:
		char **matrix;
		string *ans;
		int *answer;
		bool *hit;

		int numHit;

		int numDestroyed;
		/*score show num of ships hit*/
		int score;
        int playerAns;

	public:


		/*Default constructor*/
		BatttleShip();

		/*Regular constructor*/
		BattleShip(int *answer, char **matrix);

		/*Destructor*/
		~BattleShip();

		void setMatrix(int **mat);

		void setMatSize(int mSize);

		void setNumAns(int nAns);

		void setAns(string *ans);

		void setAns(int *answers);

		int printInstruction();

		/*prints the game board */
		void printGame();

        void setBoard();

		void start(ifstream &input);



		void updateMatrix(int num);


		void printShips(int count);

};
