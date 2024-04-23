#include "iostream"
using namespace std;
class father{
public:
    virtual void function1(){cout<<"fa1"<<endl;}
    virtual void function2 ()const{cout<<"fa2"<<endl;}
};
class son:public father{
public:
    void function2()const{cout<<"son2"<<endl;}
    void function1(){cout<<"son1"<<endl;}
};
int main(){
    son s;
    father *f;
    f=&s;
    f->function1();
    f->function2();
    s.function1();
    s.function2();
    return 0;
}
