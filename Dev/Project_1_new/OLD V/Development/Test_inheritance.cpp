#include <iostream>
using namespace std;
class A{
    int a;
    public:
        void virtual fn(){
            cout << "A" << endl;
        }
};

class B:public A{
    public:
        void fn() override {
            cout << "B" << endl;
        }


};

int main(){
    A *a = new B();
    B b;
    a -> fn();


}