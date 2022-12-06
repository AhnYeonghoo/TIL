#include <iostream>
#include <string.h>

class MyString {
    private:
        char* string_content;
        int string_length;
        int memory_capacity;

    public:
        MyString(char c);
        MyString(const char* str);
        MyString(const MyString& str);
        ~MyString();

        int length() const;
        int capacity() const;
        void reserve(int size);
        void print() const;
        void println() const;
        
        MyString& assign(const MyString& str);
        MyString& assign(const char* str);

        char at(int i) const;

        MyString& insert(int loc, const MyString& str);
        MyString& insert(int loc, const char* str);
        MyString& insert(int loc, char c);

        MyString& erase(int loc, int num);
        
        int find(int find_from, const MyString& str) const;
        int find(int find_from, const char* str) const;
        int find(int find_from, char c) const;
        
        int compare(const MyString& str) const;
};

MyString::MyString(char c) {
    string_content = new char[1];
    string_content[0] = c;
    memory_capacity = 1;
    string_length = 1;
}

MyString::MyString(const char* str) {
    string_length = strlen(str);
    memory_capacity = string_length;
    string_content = new char[string_length];
    
    for (int i = 0; i != string_length; i++) 
        string_content[i] = str[i];
}

MyString::MyString(const MyString& str) {
    string_length = str.string_length;
    memory_capacity = str.string_length;
    string_content = new char[string_length];

    for (int i = 0; i != string_length; i++)
        string_content[i] = str.string_content[i];
}

MyString::~MyString() { delete[] string_content; }

int MyString::length() const { return string_length; }

void MyString::print() const {
    for (int i = 0; i != string_length; i++)
        std::cout << string_content[i];
}

void MyString::println() const {
    for (int i = 0; i != string_length; i++)
        std::cout << string_content[i];
    std::cout << std::endl;
}

MyString& MyString::assign(const MyString& str) {
    if (str.string_length > memory_capacity) {
        
        delete[] string_content;
        string_content = new char[str.string_length];
        memory_capacity = str.string_length;
    }
    for (int i = 0; i != string_length; i++)
        string_content[i] = str.string_content[i];
    
    string_length = str.string_length;

    return *this;
}

MyString& MyString::assign(const char* str) {
    int str_length = strlen(str);
    if (str_length > memory_capacity) {
        delete[] string_content;
        string_content = new char[str_length];
        memory_capacity = str_length;
    }
    for (int i = 0; i != str_length; i++)
        string_content[i] = str[i];
    
    string_length = str_length;

    return *this;
}