#include <iostream>
#include "GraphicEditor.h"
#include "UI.h"
#include "Shape.h"
#include "Circle.h"
#include "Rect.h"
#include "Line.h"
using namespace std;
GraphicEditor::GraphicEditor() {
	while (true) {
		UI::printBasicUI();
		switch (UI::sel1) {
		case 1:
			UI::printAddUI();
			switch (UI::sel2) {
			case 1:
				this->attach(new Line());
				break;
			case 2:
				this->attach(new Circle());
				break;
			case 3:
				this->attach(new Rect());
				break;
			}
			break;
		case 2:
			UI::printSubUI();
			this->detach(UI::sel2);
			break;
		case 3:
			this->seeAll();
			break;
		case 4:
			this->endThis();
			return;
		}
	}
}

void GraphicEditor::attach(Shape *p) {
	if (pStart == NULL)
		this->pLast = this->pStart = p;
	else {
		Shape *pS = pStart;
		while (true) {
			if (pS->getNext() == NULL) {
				pLast = pS;
				break;
			}
			pS = pS->getNext();
		}
		this->pLast->add(p);
		this->pLast = p;
	}
	nNum++;
}

void GraphicEditor::detach(int index) { // 매개변수(index)에 해당하는 도형 객체를 삭제한다.
	if (index > nNum - 1) { // 매개변수로 들어온 인덱스가, GraphicEditor 가 관리하고 있는 객체의 수를 넘어서면 오류메시지 출력 후 return한다.
							// 객체의 수는 nNUm이지만, 인덱스와 비교할 때는 0부터 세기 때문에, nNum-1 값과 비교해준다.
		cout << "입력하신 인덱스는 현재 존재하지 않는 인덱스입니다." << endl;
		return;
	}
	int cnt = 1; // 인덱스를 찾아가기 위한 카운팅 변수
				 // 이중 연결리스트로 구현했으면 훨씬 깔끔한 구현이 가능했을 것이다.
				 // 단순 연결리스트에서 pStart의 정보를 잃지 않으면서 원하는 인덱스에 해당하는 객체를 삭제하려면, 불가피하게 포인터 변수가 3개 필요하다.
	Shape *p = pStart;
	Shape *pNext = pStart->getNext();
	Shape *pNNext;
	while (true) {
		if (index == 0) { // 입력한 인덱스가 첫 번째 객체를 가리키고 있을 때의 코드는 비교적 단순하다.
						  // pStart를 다음 노드를 가리키게끔 하고, 그 전의 노드를 delete해준다.
			pStart = pNext;
			delete p;
			nNum--; // 도형의 갯수 감소
			return;
		}
		else {
			pNNext = pNext->getNext();
			if (cnt == index) {
				p->add(pNNext);
				delete pNext;
				nNum--; // 도형의 갯수 감소
				return;
			}
			else {
				cnt++; // 인덱스에 해당하는 객체를 찾기 위해 cnt 값을 하나 증가시켜준다.
				p = p->getNext();
				pNext = pNext->getNext();
				pNNext = pNNext->getNext();
			}
		}
	}
}

void GraphicEditor::seeAll() {
	int cnt = -1; // 인덱스 표시를 위한 변수, 1번째 객체는 0번 인덱스이기 때문에 인덱스 개념에 맞춰 -1값을 초기값으로 설정해줬다.
	if (pStart == NULL) {
		cout << "출력할 도형이 없습니다. 도형을 먼저 생성해주세요." << endl;
		return;
	}
	else {
		Shape *p = pStart;
		while (p != NULL) {
			cnt++;
			cout << cnt << ": ";
			p->paint();
			p = p->getNext();
		}
	}
}

void GraphicEditor::endThis() {
	if (pStart == NULL)
		exit(1);
	else {
		Shape *p = pStart;
		while (p != NULL) {
			pStart = pStart->getNext();
			delete p;
			p = pStart;
		}
	}
}