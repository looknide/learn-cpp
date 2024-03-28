#include "iostream"
#include "cstring"
using namespace std;
class CData{
private:
    int year;
    int month;
    int day;
public:
    CData(int y,int m,int d);
//    ~CData();好像用不着
    int GetYear()const;//为啥return他们呢
    int GetMonth()const;
    int GetDay()const;
    int GetDayOfYear()const;//容易想不到
    CData();//之后的类中定义CData时如果没有默认构造函数，需要进行初始化，不能去掉
    bool IsLeap()const;//bool
};

//构造函数传参
CData::CData(int y,int m,int d) {
    year=y;
    month=m;
    day=d;
}
CData::CData() {}
//int CData::IsLeap() {
//    if (year%4==0&&year%100==0||year%400==0)
//    {
//        return 1;
//    } else{return 0;}
//}
//判断是否是闰年
bool CData::IsLeap()const {
    return (year%4==0&&year%100==0||year%400==0);
}

int CData::GetYear()const {//常量成员函数const放后面
    return year;
}
int CData::GetMonth()const {
    return month;
}
int CData::GetDay()const {
    return day;
}

int CData::GetDayOfYear()const {
    int MDay[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    //把每个月天数存在数组中
    int sum=day;//最好用sum来存天数，否则会改变day
    if (IsLeap()){
        MDay[2]++;
    }//调整不同情况下二月份的天数
    for(int i=0;i<month;i++){//注意，如果是三月份，月份的天数只加到2月，再加上三月的零头
        sum+=MDay[i];
    }
    return sum;
}

class software{
private:
    char *name;
    char m_type;
    char m_media;
    CData limit_day;//对象成员，若该函数无构造函数时要进行初始化
    //主程序检查到有成员对象，先运行对象的构造函数
public:
    software(char *p,char p_type,char p_media,CData day);
    ~software();
    software(const software &pri);//拷贝构造函数
    int calculate();
    void print();
};

software::software(char *p, char p_type, char p_media,CData day) {//构造函数时未初始化成员对象，自动调用缺省构造函数
    m_media=p_media;
    m_type=p_type;
    limit_day=day;
    size_t n= strlen(p);
    name=new char[++n];
    for(int i=0;i<n+1;i++){
        name[i]=*p;
        p++;
    }
}

software::~software() {
    delete[]name;
    cout<<"delete it"<<endl;
}

software::software(const software &pri):limit_day(pri.limit_day) {//只在前面初始化了CData的对象
    size_t n= strlen(pri.name);
    name=new char [n+1];
    for(int i=0;i<n+1;i++){
        name[i]=pri.name[i];
    }
    m_type='B';
    m_media='H';
}

int software::calculate(){
    if (limit_day.GetYear()==0&&limit_day.GetMonth()==0&&limit_day.GetDay()==0)
    {
        return 1;
    }
    else if (limit_day.GetYear()<=2015&&limit_day.GetDay()==7&&limit_day.GetMonth()<4)
    {
        return 2;
    }
    else
    {
        int result=0;
        CData data(2015,4,7);//直接让CData来计算2015.4.7的月转化为天数
        result=limit_day.GetDayOfYear()-data.GetDayOfYear()+360*(limit_day.GetYear()-data.GetYear());
        return result;
    }
}

void software::print() {
    cout<<"name:"<<name<<endl;
    if (m_type=='O'){cout<<"type:"<<"original"<<endl;}
    else if(m_type=='B'){cout<<"type:"<<"backup"<<endl;}
    else{cout<<"type:"<<"trial"<<endl;}

    if (m_media=='D'){cout<<"optical disk";}
    else if (m_media=='H'){cout<<"hard disk";}
    else {cout<<"USB disk";}

    if (calculate()==1){cout<<"unlimited"<<endl;}
    else if (calculate()==2){cout<<"expired"<<endl;}
    else{cout<<calculate()<<endl;}
}

int main(){
    int t;
    cin>>t;
    while (t--){
        char p[100];
        int y;int m;int d;char m_type;char m_media;
        cout<<"name:";
        cin>>p;
        cout<<"type:";
        cin>>m_type;
        cout<<"media:";
        cin>>m_media;
        cout<<"limit day:";
        cin>>y>>m>>d;
        CData OldData(y,m,d);
        software old(p,m_type,m_media,OldData);
        software now(old);
        now.print();
        cout<<endl;
        old.print();
        cout<<endl;
    }
    return 0;
}