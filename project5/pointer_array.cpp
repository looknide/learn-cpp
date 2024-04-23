//#include "iostream"
//using namespace std;
//class person{
//public:
//
//};
//int main(){
//    const char* a="aw12";
//    char* a2= nullptr;
//    a2=const_cast<char *>(a);//const char*转char*
//
//    cout<<*a2;
//    return 0;
//}
#include <iostream>


using namespace std;


class A{
public:
    virtual ~A(){
        cout<<"A"<<endl;
    }
};


class B{
public:
    virtual ~B(){
        cout<<"B"<<endl;
    }
};


class C{
public:
    virtual ~C(){
        cout<<"C"<<endl;
    }
};


class D{
public:
    virtual ~D(){
        cout<<"D"<<endl;
    }
};


void f(C c,D d);
int main()
{
    C c;
    D d;
    f(c,d);
    return 0;
}


void f(C c,D d){


    B b;
    A a;
    B* pb=&b;
}