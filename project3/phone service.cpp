//#include "iostream"
//using namespace std;
////日期类，存放停机时间
//class Data{
//private:
//    int year;
//    int month;
//    int day;
//public:
//    Data(int y,int m,int d);
//    Data();
//    ~Data();
//    void print()const;
//    int GetYear()const;
//    int GetMonth()const;
//    int GetDay()const;
//};
//Data::Data(int y, int m, int d) {
//    year=y;
//    month=m;
//    day=d;
//}
//void Data::print()const {
//    cout<<year<<"."<<month<<"."<<day;
//}
//
//int Data::GetYear() const {
//    return year;
//}
//
//int Data::GetMonth() const {
//    return month;
//}
//
//int Data::GetDay() const {
//    return day;
//}
//
//class obj{
//private:
//    char type;//号码类型：用户类别，A机构，B企业，C个人
//    char *number;//11位号码
//    Data * OData;//停机日期指针
//    int state;//状态：1.在用，2.未用，3.停用
//public:
//    obj(char t,char *num,int s,Data OD);
//    ~obj();
//    obj(const Data& obj);
//
//};
//obj::obj(char t, char *num, int s,Data OD) {
//    type=t;
//    state=s;
//    number=new char[12];
//    for (int i = 0; i <11 ; i++) {
//        number[i]=*num;
//        num++;
//    }
//}
//obj::~obj() {delete[]number;}
//obj::obj(const Data &obj2){
//    if (OData){
//
//    }
//}




#include<iostream>
using namespace std;

class CDate
{
private:
    int year;
    int month;
    int day;
public:
    CDate();
    CDate(int y, int m, int d);
    int getYear();
    int getMonth();
    int getDay();
    void print();
};
CDate::CDate()
{

}
CDate::CDate(int y, int m, int d)
{
    year = y;
    month = m;
    day = d;
}
int CDate::getMonth()
{
    return month;
}
int CDate::getDay()
{
    return day;
}
int CDate::getYear()
{
    return year;
}
void CDate::print()//用于打印停机信息
{
    cout << "停机日期=" << year << '.' << month << '.' << day<<endl;
}

class Phone
{
private:
    char type;
    char *num;
    char state;
    CDate* date=NULL;
public:
    Phone(char t,char*n,char s);//构造函数
    Phone(const Phone& p);//拷贝构造函数
    ~Phone();//析构函数
    void stop(CDate &a);
    void print();


};
Phone::Phone(char t, char* n, char s)
{
    type = t;
    num = new char[15];
    for (int i = 0; i < 12; i++)
    {
        num[i] = n[i];
    }
    num[12] = '\0';
    state = s;
    cout << "Construct a new phone " <<num<< endl;
}
Phone::Phone(const Phone& p)
{
    cout << "Construct a copy of phone " << p.num << endl;
    type = 'D';
    num = new char[15];
    for (int i = 0; i < 11; i++)
    {
        num[i] = p.num[i];
    }
    num[11] = 'X';
    num[12] = '\0';
    state = p.state;
    if (p.date != NULL)
    {
        date = new CDate(*p.date);
    }
}
Phone::~Phone()
{
    delete[]num;
    if(date!=NULL)
        delete date;
}
void Phone::stop(CDate &a)//停机函数
{
    state = '3';
    date = new CDate(a.getYear(), a.getMonth(), a.getDay());
    cout << "Stop the phone " << num << endl;
}
void Phone::print()
{
    cout << "类型=";
    if (type == 'A')
    {
        cout << "机构||号码=" << num;
    }
    else if (type == 'B')
    {
        cout << "企业||号码=" << num;
    }
    else if(type=='C')
    {
        cout << "个人||号码=" << num;
    }
    else
    {
        cout << "备份||号码=" << num;
    }
    cout << "||State=";
    if (state == '1')
    {
        cout << "在用" << endl;
    }
    else if (state == '2')
    {
        cout << "未用" << endl;
    }
    else------------"<<endl;
}
    {
        cout << "停用 ||";
        this->date->print();
    }
}

int main()
{
    int t, y, m, d;
    char s;
    char type;
    char num[15];
    cin >> t;
    while (t--)
    {
        cin >> type >> num >> s >> y >> m >> d;
        CDate date(y, m, d);
        Phone p1(type, num, s);
        p1.print();
        Phone p2(p1);
        p2.print();
        p1.stop(date);
        p1.print();
        cout << "- - - -" << endl;
    }

    //system("pause");
    return 0;
}