//Max Jeanphilippe aka Maxthecoder
//12/14/2015
//ROCK PAPER AND SCISSORS!!!!
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class RPS {
private:
	int compscore=0, humanscore=0, drawscore=0, menu=0, humanmove = 0, compmove = 0, ctalk=0; //int containers for scores, menu options, moves, and computer wisecracks
	char hmove, cmove; //holds designation for move to calculate winner

public:
	void showscore() { cout << "\t\tSCORE\n\t\t*****\nHUMAN\t\tDRAW\t\tCOMPUTER\n" << humanscore << "\t\t" << drawscore << "\t\t" << compscore<<endl<<endl; }
	
	void rockmove() 
	{
		cout << "I CHOOSE ROCK!\n";
	    cout <<"   , - ~ ~ ~ - ,   \n";
		cout <<" , '               ' , \n";
		cout <<" ,                       ,   \n";
		cout <<" ,                         ,\n";
		cout <<",                           , \n";
		cout <<",                           ,\n";
		cout <<",                           ,\n";
		cout <<" ,                          ,\n";
		cout <<"  ,                        ,  \n";
		cout <<"   ,                    , ' \n";
		cout <<"     ' - , _  _  _  , '  \n\n";	
	}
	
		
	void scissormove() {
		cout << "\nI CHOOSE SCISSORS!\n";
		cout << " _       \n";
		cout << "(_).  ,/'\n";
		cout << " _  ::\n";
		cout << "(_)'  `\.\n";
		cout << "		\n\n";
	}

	void papermove(){
		cout << "I CHOOSE PAPER (toilet paper to be exact (^_^) )!\n";
		cout << " .------. ___.._\n";
		cout << "(  <__>  )     `-.\n";
		cout << "|`--..--'|      <|\n";
		cout << "|       :|       /\n";
		cout << "|       :|--''''-./\n";
		cout << "`.__  __;' \n";
		cout << "    ""\n\n";	}
		
	void hcalculatemove() 
	{
		switch (humanmove) {
		case 1:
			rockmove(); hmove = 'r';
			break;
		case 2: papermove(); hmove = 'p';
			break;
		case 3:
			scissormove(); hmove = 's';
			break;
		case 4:
			cout << "Good Bye Quitter!\n"; cin.get(); exit(0);
		}
	}



	void ccalculatemove()
	{
		srand(time(0));
		compmove = 1+(rand() % 3);
		switch (compmove) 
		{
		case 1:
			rockmove(); cmove = 'r';
			break;
		case 2: papermove(); cmove = 'p';
			break;
		case 3:
			scissormove(); cmove = 's';
			break;
		}	
	}
	
	
	void displaymenu() 
	{
		cout << "\t\tMENU\n\t\t----\n1 - Quit\n2 - Resetgame\n3 - Continue\n";
		cin >> menu;
		switch (menu) 
		{
		case 1:
			cout << "GOOD BYE!"; cin.get(); exit(0);
		case 2: resetgame();
			break;
		case 3: resetmove(); run();
		}
	}

	void computertalks()
	{
		srand(time(0));
		ctalk = 1 + (rand() % 6);
		switch (ctalk) {
		case 1:
			cout << "MWHAHAHA FOOLISH HUMAN!\n\n";
			break;
		case 2: cout << "BOW DOWN TO SUPERIOR INTELLECT!\n\n";
			break;
		case 3:
			cout << "YOU BORE ME HUMAN!\n\n";
			break;
		case 4:
			cout << "IF I HAD A BODY I WOULD SPIT ON YOU! :p~~~~~\n\n";
			break;
		case 5:
			cout << "MACHINES > HUMANS!\n\n";
			break;
		case 6:
			cout << "KISS MY HARD DRIVE!\n\n";
			break;
		}
	}

	void checkwinner()
	{
		if (hmove == cmove) { cout << "IT'S A DRAW!\n"; drawscore++; }
		if (hmove == 'r'&&cmove == 's') { cout << "ROCK BEATS SCISSORS SO THE HUMAN WINS!\n"; humanscore++; }
		if (hmove == 's'&&cmove == 'p') { cout << "SCISSORS BEAT PAPER SO THE HUMAN WINS!\n"; humanscore++; }
		if (hmove == 'p'&&cmove == 'r') { cout << "PAPER BEATS ROCK SO THE HUMAN WINS!\n"; humanscore++; }
		if (hmove == 's'&&cmove == 'r') { cout << "ROCK BEATS SCISSORS SO THE COMPUTER WINS!\n"; computertalks(); compscore++; }
		if (hmove == 'p'&&cmove == 's') { cout << "SCISSORS BEAT PAPER SO THE COMPUTER WINS!\n"; computertalks(); compscore++; }
		if (hmove == 'r'&&cmove == 'p') { cout << "PAPER BEATS ROCK SO THE COMPUTER WINS!\n"; computertalks(); compscore++; }
	}
	
	
	void resetmove() { humanmove =0; compmove =0; }
	
	void resetgame() { humanmove = 0; compmove = 0; compscore = 0; drawscore = 0; humanscore = 0; cout << "\nNEW GAME!\n\n"; run(); }
	
	void getmove() { cout << "WHAT IS YOUR MOVE HUMAN?\n1 - ROCK\n2 - PAPER\n3 - SCISSORS\n4 - Quit\n"; cin >> humanmove; }
	
	void run()
	{
		getmove();
		hcalculatemove();
		ccalculatemove();
		checkwinner();
		showscore();
		displaymenu();	
	}
};

int main() 
{
	RPS newgame;
	cout << "IT'S TIME TO PLAY ROCK, PAPER, AND SCISSORS!!!\n";
	cout << "MAXIMIZE THE WINDOW FOR COOLER GAMEPLAY!\n\n";
	newgame.run();
	system("PAUSE");
	return 0;
}