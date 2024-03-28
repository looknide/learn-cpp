#include "iostream"
#include "cstring"
using namespace std;
class CTelNumber
{
private:
    char *num;//char型指针存号码

public:
    explicit CTelNumber(char *number);//构造函数传入号码
    CTelNumber(const CTelNumber & CTel);//拷贝构造函数，传入原号码，进行改变
    ~CTelNumber();//析构函数释放空间
};

//拷贝构造函数
CTelNumber::CTelNumber(const CTelNumber & CTel)
{
    num=new char [9];//再申请一个8+1的内存空间
    //将传入数组加到类中数组之后
    if(CTel.num[0]=='2'||CTel.num[0]=='3'||CTel.num[0]=='4')
    {
        int k=0;
        num[0]='8';//char型，带''
        for (int i = 1; i < 9; i++,k++) {
            num[i]=CTel.num[k];//拷贝
        }

    } else if (CTel.num[0]=='5'||CTel.num[0]=='6'||CTel.num[0]=='7'||CTel.num[0]=='8')
    {
        int k=0;
        num[0]='2';
        for (int i = 1; i < 9; i++,k++) {
            num[i]=CTel.num[k];
        }
    }
    cout<<num<<endl;
}

//构造函数传入号码
CTelNumber::CTelNumber(char *number) {
    num=new char[8];//内存为7+1
    //开辟一个新的内存空间，否则num，number指针指向同一个地址，num改变number内容
    for (int i = 0; i <7 ; i++) {
        num[i]=number[i];
        //num[i]=*number;number++;
    }
}

//析构函数
CTelNumber::~CTelNumber() {
    delete []num;//释放num的内存
    cout<<"delete it"<<endl;
}

//判断是否要加号，放在if的条件中
int IsRight(char *p)
{
    if (p[0]<'2'||p[0]>'8'){
        return 0;
    } else if (strlen(p)==7){
        return 1;
    } else{
        return 0;
    }
}

int main()
{
    cout<<"how many number do you want to put:"<<endl;
    int t;
    cin>>t;//传入要升位的号码数

    while (t--) {
        char FNum[8];
//        for (int i = 0; i <7 ; i++) {
//            cin>>FNum[i];
//        }
        cin >> FNum;//输入号码
        if (IsRight(FNum))//判断是否符合标准
        {
            CTelNumber old(FNum);//创造一个对象
            CTelNumber NewNum(old);//调用拷贝构造函数，再创造一个对象，用原对象初始化
        } else{
            cout<<"Illegal number!"<<endl;
        }
    }
    return 0;
}