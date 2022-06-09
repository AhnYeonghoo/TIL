#include <iostream>
#include <stack>

int main() {
    std::stack<int> Stack;

    Stack.push(1);
    Stack.emplace(3);
    Stack.emplace(4);
    std::cout << Stack.size() << std::endl;
    
    std::cout << Stack.top() << std::endl;
    Stack.pop();
    std::cout << Stack.top() << std::endl;
    return 0;
}