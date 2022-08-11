#include "WordGame.h"
#include "Player.h"
#include <iostream>
using namespace std;

WordGame::WordGame() {
	cout << "���� �ձ� ������ �����մϴ�" << endl;
	setStartWord("�ƹ���");
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
	cout << "���ӿ� �����ϴ� �ο��� ����Դϱ�? ";
	cin >> pNum;
	p = new Player[pNum];
	pIndex = 0;
}
void WordGame::runGame() {
	cout << "�����ϴ� �ܾ�� " << startWord << "�Դϴ�" << endl;
	while (true) {
		showPlayer(pIndex);
		cin >> nextWord;
		if (startWord.size() == 4) { // �ܾ 2���� �ѱ۷� �̷���� ���� ��
			if (startWord.at(2) == nextWord.at(0) && startWord.at(3) == nextWord.at(1)) {
				startWord = nextWord; // ���� �ܾ�� �񱳸� ���� ��ü
				if (pIndex < pNum - 1)
					pIndex++;
				else {
					pIndex = 0;
				}
			}
			else {
				showPlayer(pIndex);
				cout << "�� �����ϴ�.";
				return;
			}
		}
		else if (startWord.size() == 6) { // �ܾ 3���� �ѱ۷� �̷���� ���� ��
			if (startWord.at(4) == nextWord.at(0) && startWord.at(5) == nextWord.at(1)) {
				startWord = nextWord; // ���� �ܾ�� �񱳸� ���� ��ü
				if (pIndex < pNum - 1)
					pIndex++;
				else {
					pIndex = 0;
				}
			}
			else {
				showPlayer(pIndex);
				cout << "�� �����ϴ�.";
				return;
			}
		}
	}
}
void WordGame::showPlayer(int no) {
	p[no].show();
}