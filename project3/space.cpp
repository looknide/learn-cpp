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
void count::show(){
    cout<<"the "<<ID<<" "<<name<<" has "<<Ncount<<endl;
}

// 存款
void count::deposite(){
    cout<<"put the number you want to deposite:";
    float num;
    cin>>num;
    Ncount+=num;
    show();
}

// 取款
void count::withdrow(){
    cout<<"put the number you want to withdrow:";
    float num;
    cin>>num;
    if(Ncount<num){
        cout<<"there is no money!"<<endl;
    }
    else
        Ncount-=num;
    show();
}
int main() {
    cout << "put your information:" << endl;
    int x;
    char str[10];
    cin >> x >> str;

    count obj(str, x);

    int choice;
    while (true) {
        cout << "1.deposite\n2.withdrow\n3.show\n0.return:" << endl;
        cin >> choice;
        if (choice == 0) break;
        if (choice == 1) obj.deposite();
        else if (choice == 2) obj.withdrow();
        else if (choice == 3) obj.show();
    }

    return 0;
}