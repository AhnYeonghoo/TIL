#include <iostream>
#include <typeinfo>
template<typename T>

class SmartPtr {

    private:
        T* sptr = nullptr
        
    public:
        SmartPtr(T* sptr) : sptr(sptr){
            std::cout << "sptr type: " << typeid(sptr).name() << std::endl;
        }
        ~SmartPtr() {
            std::cout << "bye" << typeid(sptr).name() << std::endl;
            delete sptr;
        }
};

int main() {
    SmartPtr<A> a_ptr(new A);
    SmartPtr<int> i_ptr(new int);
    return 0;
}
