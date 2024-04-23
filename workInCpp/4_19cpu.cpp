//
// Created by qiu19 on 2024/4/5.
//
#include "iostream"
using namespace std;
class CPU{
//private:
//    float f;
public:
    struct {
        int f:12;//0-3000位：位数>=log2(3000+1)
        unsigned int l:1;//32位或64位,1位表示0,1
        unsigned int cn:2;//1,2,4种核数->1-4 2位表示0-3
        unsigned int ht:1;//是否支持
    };
};
int main(){
    cout<<sizeof (CPU)<<endl;
    return 0;
}