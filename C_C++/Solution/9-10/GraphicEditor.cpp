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

void GraphicEditor::detach(int index) { // �Ű�����(index)�� �ش��ϴ� ���� ��ü�� �����Ѵ�.
	if (index > nNum - 1) { // �Ű������� ���� �ε�����, GraphicEditor �� �����ϰ� �ִ� ��ü�� ���� �Ѿ�� �����޽��� ��� �� return�Ѵ�.
							// ��ü�� ���� nNUm������, �ε����� ���� ���� 0���� ���� ������, nNum-1 ���� �����ش�.
		cout << "�Է��Ͻ� �ε����� ���� �������� �ʴ� �ε����Դϴ�." << endl;
		return;
	}
	int cnt = 1; // �ε����� ã�ư��� ���� ī���� ����
				 // ���� ���Ḯ��Ʈ�� ���������� �ξ� ����� ������ �������� ���̴�.
				 // �ܼ� ���Ḯ��Ʈ���� pStart�� ������ ���� �����鼭 ���ϴ� �ε����� �ش��ϴ� ��ü�� �����Ϸ���, �Ұ����ϰ� ������ ������ 3�� �ʿ��ϴ�.
	Shape *p = pStart;
	Shape *pNext = pStart->getNext();
	Shape *pNNext;
	while (true) {
		if (index == 0) { // �Է��� �ε����� ù ��° ��ü�� ����Ű�� ���� ���� �ڵ�� ���� �ܼ��ϴ�.
						  // pStart�� ���� ��带 ����Ű�Բ� �ϰ�, �� ���� ��带 delete���ش�.
			pStart = pNext;
			delete p;
			nNum--; // ������ ���� ����
			return;
		}
		else {
			pNNext = pNext->getNext();
			if (cnt == index) {
				p->add(pNNext);
				delete pNext;
				nNum--; // ������ ���� ����
				return;
			}
			else {
				cnt++; // �ε����� �ش��ϴ� ��ü�� ã�� ���� cnt ���� �ϳ� ���������ش�.
				p = p->getNext();
				pNext = pNext->getNext();
				pNNext = pNNext->getNext();
			}
		}
	}
}

void GraphicEditor::seeAll() {
	int cnt = -1; // �ε��� ǥ�ø� ���� ����, 1��° ��ü�� 0�� �ε����̱� ������ �ε��� ���信 ���� -1���� �ʱⰪ���� ���������.
	if (pStart == NULL) {
		cout << "����� ������ �����ϴ�. ������ ���� �������ּ���." << endl;
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