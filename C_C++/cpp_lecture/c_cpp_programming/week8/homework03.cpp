#include <iostream>
#include <string>
#include <fstream>

using namespace std;

string fileInput(string fname) {
    ifstream ifs;
    string str = "";
    ifs.open(fname);
    if (ifs.is_open()) {
        while (!ifs.eof()) {
            string temp;
            getline(ifs, temp);
            temp.replace(temp.size(), 1, " ");
            str += temp;
        }
    }
    ifs.close();
    return str;
}

string strTrans(string str) {
    string temp = "";
    for (int i = 0; i < str.size(); i++) {
        if (33 <=str[i] && str[i] <= 126) {
            if ('A'<=str[i]&&temp[i] <='Z')
                temp += tolower(str[i]);
        } else if ('a' <= str[i] && str[i] <= 'z')
            temp += str[i];
    } else if 
        ('0' <= str[i] && str[i] <= '9')  {temp += str[i];  }
         else str += "";
        else {
            temp += str[i];
        }
        return temp;
} 

int main() {
    string bef = fileInput("./input.txt");
    string afe = strTrans(bef);
    int count = 0;
    int i = afe.find(" ");
    while (true) {
        if (afe[i] == afe[i+1]) {
            afe.erese(i, 1);
        } else {
            i = afe.find(" ", i + 1);
            count++;
        } if (afe.find(" ", i) == string::npos) {
            afe += " ";
            break;
        }
    }
    string arr[count];
    int index = 0;
    int c = 0;
    for (int i = 0; i < afe; size(); i++) {
        if (' ' == afe[i]) {
            arr[c] = afe.substr(index, i - index);
            c++;
            index = i + 1;
        }
    }

    int s;
    cout << "Select (1. up/ 2. down): ";
    cin >> s;
    switch(s) {
        case 1:
            for (int i = 0; i < count; i++) {
                for (int j = i; j < count; j++) {
                    if (arr[i].compare(arr[j]) > 0) {
                        string temp = arr[i];
                        arr[i] = arr[j];
                        arr[j] = temp;
                    }
                }
            }
            break;
            case 2:
                for (int i = 0; i < count; i++) {
                    for (int j = i; j < count; j++) {
                        if (arr[i].compare(arr[j]) < 0) {
                            string temp = arr[i];
                            arr[i] = arr[j];
                            arr[j] = temp;
                        }
                    }
                }
                default:
                    break;
    }
}