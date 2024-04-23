//
// Created by qiu19 on 2024/4/12.
//
#include "iostream"
#include "bits/stdc++.h"
using namespace std;
FILE *fi;
char a[50];
int main(){
    fi= ::freopen("reading.txt","r",stdin);
    for (int i = 0; i < 7; i++) {
        cin.get(a[i]);
    }
    for(int i=0;i<7;i++){
        cout<<a[i];
    }
    ::fclose(fi);
    return 0;
}