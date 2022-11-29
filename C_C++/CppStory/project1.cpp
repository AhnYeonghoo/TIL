#include <iostream>
#include <cstring>

using namespace std;
const int NAME_LEN = 20;
const int MAX_CUS_NUM = 100;

void ShowMenu(void);
void MakeAccount(void);
void DepositMoney(void);
void WithdrawMoney(void);
void ShowAllAccInfo(void);

enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

typedef struct 
{
    int accID;
    int balance;
    char cusName[NAME_LEN];
} ACCOUNT;

ACCOUNT account[MAX_CUS_NUM];
int accNum;

int main() 
{
    int choice;
    while (1) 
    {
        ShowMenu();

        cout << "선택: " ;
        cin >> choice;
        cout << endl;
        
        switch (choice)
        {
            case MAKE:
                MakeAccount();
                break;
            case DEPOSIT:
                DepositMoney();
                break;
            case WITHDRAW:
                WithdrawMoney();
                break;
            case INQUIRE:
                ShowAllAccInfo();
                break;
            case EXIT:
                return 0;
            default:
                cout << "잘못된 입력 입니다." << endl;
        }

    }
    return 0;
}

void ShowMenu(void)
{
    cout << endl;
    cout << "--------------Menu--------------" << endl;
    cout << "1. 계좌 개설" << endl;
    cout << "2. 입금" << endl;
    cout << "3. 출금" << endl;
    cout << "4. 계좌 정보 전체 출력" << endl;
    cout << "5. 프로그램 종료" << endl;
}

void MakeAccount(void) 
{
    cout << endl;
    cout << "[계좌 개설]" << endl;
    cout << "계좌 ID: ";
    cin >> account[accNum].accID;
    cout << "이름: ";
    cin >> account[accNum].cusName;
    cout << "입금액: ";
    cin >> account[accNum].balance;

    accNum++;
}

void DepositMoney(void)
{
    int id;
    int money;
    
    cout << endl;
    cout << "[입금]" << endl;
    cout << "계좌 ID: ";
    cin >> id;

    for (int i = 0; i < accNum; i++)
    {
        if (account[i].accID == id)
        {
            cout << "입금액: ";
            cin >> money;
            account[i].balance += money;
            cout << "입금 완료: " << endl;
            return;
        }
    }
    cout << "잘못된 계좌번호 입력. " << endl;
}

void WithdrawMoney(void)
{
    int id;
    int money;
    
    cout << endl;
    cout << "[출금]" << endl;
    cout << "계좌 ID: " ;
    cin >> id;
    
    for (int i = 0; i < accNum; i++) 
    {
        if (account[i].accID == id)
        {
            cout << "출금액: ";
            cin >> money;
            if (account[i].balance < money) 
            {
                cout << "잔액 부족. " << endl;
                return;
            }
            else 
            {
                account[i].balance -= money;
                cout << "출금 완료" << endl;
                return;
            }
        }
    }
    cout << "잘못된 계좌번호 입력. " << endl;
}

void ShowAllAccInfo(void)
{
    cout << endl;
    cout << "[계좌 정보]" << endl;
    
    for (int i = 0; i < accNum; i++) 
    {
        cout << "계좌 ID: " << account[i].accID << endl;
        cout << "이름; " << account[i].cusName << endl;
        cout << "잔액: " << account[i].balance << endl;
        cout << endl;
    }
}