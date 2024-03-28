#include<iostream>
#include<cstring>
using namespace std;

class count
{
private:
    char name[31];
//    int baviour;
    int ID;
    float Ncount;

public:
    count(char *nam,int id){
        strcpy(name,nam);
        ID=id;
        Ncount=0;
    };
//    ~count();

    void withdrow();
    void deposite();
    void show();
};