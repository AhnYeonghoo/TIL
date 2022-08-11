#include "WordGame.h"
#include "Player.h"
#include <iostream>
using namespace std;

WordGame::WordGame() {
	cout << "끝말 잇기 게임을 시작합니다" << endl;
	setStartWord("아버지");
	setPlayerNumber();
	runGame();
}
WordGame::~WordGame() {
	delete[] p;
}
void WordGame::setStartWord(string word) {
	startWord = word;
}
void WordGame::setPlayerNumber() {
	cout << "게임에 참가하는 인원은 몇명입니까? ";
	cin >> pNum;
	p = new Player[pNum];
	pIndex = 0;
}
void WordGame::runGame() {
	cout << "시작하는 단어는 " << startWord << "입니다" << endl;
	while (true) {
		showPlayer(pIndex);
		cin >> nextWord;
		if (startWord.size() == 4) { // 단어가 2개의 한글로 이루어져 있을 때
			if (startWord.at(2) == nextWord.at(0) && startWord.at(3) == nextWord.at(1)) {
				startWord = nextWord; // 다음 단어와 비교를 위해 교체
				if (pIndex < pNum - 1)
					pIndex++;
				else {
					pIndex = 0;
				}
			}
			else {
				showPlayer(pIndex);
				cout << "이 졌습니다.";
				return;
			}
		}
		else if (startWord.size() == 6) { // 단어가 3개의 한글로 이루어져 있을 때
			if (startWord.at(4) == nextWord.at(0) && startWord.at(5) == nextWord.at(1)) {
				startWord = nextWord; // 다음 단어와 비교를 위해 교체
				if (pIndex < pNum - 1)
					pIndex++;
				else {
					pIndex = 0;
				}
			}
			else {
				showPlayer(pIndex);
				cout << "이 졌습니다.";
				return;
			}
		}
	}
}
void WordGame::showPlayer(int no) {
	p[no].show();
}