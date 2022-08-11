#ifndef WORDGAME_H
#define WORDGAME_H
#include "Player.h"
#include <string>
using namespace std;

class WordGame {
	int pNum;
	int pIndex;
	string startWord;
	string nextWord;
	Player *p;
public:
	WordGame();
	~WordGame();
	void setStartWord(string word);
	void setPlayerNumber();
	void runGame();
	void showPlayer(int no);
};

#endif