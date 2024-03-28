#include<iostream>
#include<string.h>
using namespace std ;
class stdu{
    private:
        char* name;
        char* addr;
        long long number;
    public:
        //构造函数
        stdu(char* n,char* a,long long num){
            name=new char[15];//new一个对象，申请空间
            addr=new char[31];
            strcpy(name,n);
            strcpy(addr,a);
            number=num;

        }

        //析构函数，销毁时释放内存
        ~stdu(){
            delete []name;
            delete []addr;
            cout<<"调用析构函数清除"<<endl;
        }

        void print(){
            cout<<"name:"<<*name<<endl;
            cout<<"address:"<<*addr<<endl;
            cout<<"phone number:"<<number<<endl;
        }

};

int main(){
    stdu student((char*)"qiu",(char*)"gangguo",1234556733);
    student.print();
    return 0;
}