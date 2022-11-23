#include <iostream>
#include <string.h>


class MyString {
    
    char* stringContent;
    int stringLength;
    int memoryCapacity;
    
    public: 
        MyString(char c);
        MyString(const char* str);
        MyString(const MyString& str);
        ~MyString();
        int length() const;
        void print() const;
        void println() const;
        int capacity() const;
        void reserve(int size);
        
        MyString& assign(const MyString& str);
        MyString& assign(const char* str);

        char at(int i) const;
        
        MyString& insert(int loc, const MyString& str);
        MyString& insert(int loc, const char* str);
        MyString& insert(int loc, char c);
};

MyString::MyString(char c) {
    stringContent = new char[1];
    stringContent[0] = c;
    memoryCapacity = 1;
    stringLength = 1;

}

MyString::MyString(const char* str) {
    stringLength = strlen(str);
    memoryCapacity = stringLength;
    stringContent = new char[stringLength];

    for (int i = 0; i != stringLength; i++)
        stringContent[i] = str[i];
}

MyString::MyString(const MyString& str) {
    stringLength = str.stringLength;
    memoryCapacity = str.stringLength;
    stringContent = new char[stringLength];

    for (int i = 0; i != stringLength; i++)
        stringContent[i] = str.stringContent[i];
}

MyString::~MyString() { delete[] stringContent; }

int MyString::length() const { return stringLength; }

void MyString::print() const {
    for (int i = 0; i != stringLength; i++) 
        std::cout << stringContent[i];
}

void MyString::println() const {
    for (int i = 0; i != stringLength; i++)
        std::cout << stringContent[i];
    std::cout << std::endl;
}

MyString& MyString::assign(const MyString& str) {
    if (str.stringLength > memoryCapacity) {
        delete[] stringContent;
        
        stringContent = new char[str.stringLength];
        memoryCapacity = str.stringLength;
    }
    for (int i = 0; i != str.stringLength; i++) 
        stringContent[i] = str.stringContent[i];
    
    stringLength = str.stringLength;
    return *this;
}


MyString& MyString::assign(const char* str) {
    int strLength = strlen(str);
    if (strLength > memoryCapacity) {
        delete[] stringContent;
        stringContent = new char[strLength];
        memoryCapacity = strLength;
    }
    for (int i = 0; i != strLength; i++) 
        stringContent[i] = str[i];
    
    stringLength = strLength;
    return *this;
}

int MyString::capacity() const { return memoryCapacity; }

void MyString::reserve(int size) {
    if (size > memoryCapacity) {
        char* prevStringContent = stringContent;
        stringContent = new char[size];
        memoryCapacity = size;
        for (int i = 0; i != stringLength; i++) 
            stringContent[i] = prevStringContent[i];
        delete[] prevStringContent;
    }
}

char MyString::at(int i) const {
    if (i >= stringLength || i < 0) {
        return 0;
    } else {
        return stringContent[i];
    }
}

MyString& MyString::insert(int loc, const MyString& str) {
    if (loc < 0 || loc > stringLength) return *this;

    if (stringLength + str.stringLength > memoryCapacity) {
        memoryCapacity = stringLength + str.stringLength;\
        char* prevStringContent = stringContent;
        stringContent = new char[memoryCapacity];
        int i;
        for (i = 0; i < loc; i++) 
            stringContent[i] = prevStringContent[i];
        
        for (int j = 0; j != str.stringLength; j++) 
            stringContent[i + j] = str.stringContent[j];

        for (; i < stringLength; i++) 
            stringContent[str.stringLength + i] = prevStringContent[i];
        
        delete[] prevStringContent;
        stringLength = stringLength + str.stringLength;
        return *this;
    }

    for (int i = stringLength - 1; i >= loc; i--) {
        stringContent[i + str.stringLength] = stringContent[i];
    }
    for (int i = 0; i < str.stringLength; i++) {
        stringContent[i + loc] = str.stringContent[i];
    }
    stringLength = stringLength + str.stringLength;
    return *this;
}
MyString& MyString::insert(int loc, const char* str) {
  MyString temp(str);
  return insert(loc, temp);
}
MyString& MyString::insert(int loc, char c) {
  MyString temp(c);
  return insert(loc, temp);
}
int main() {
  MyString str1("very long string");
  MyString str2("<some string inserted between>");
  str1.reserve(30);

  std::cout << "Capacity : " << str1.capacity() << std::endl;
  std::cout << "String length : " << str1.length() << std::endl;
  str1.println();

  str1.insert(5, str2);
  str1.println();
}