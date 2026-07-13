#include "SessionInfo.h"
#include <cstring>
#include <iostream>
#include <memory>
using namespace std;

SessionInfo::SessionInfo(int id):session_id(id){

}

SessionInfo::~SessionInfo(){}

void prosess(shared_ptr<SessionInfo> sp){
    cout<<"cout number:"<<sp.use_count()<<endl;
}

void prosess1(shared_ptr<SessionInfo>& sp){
    cout<<"cout number:"<<sp.use_count()<<endl;
}

int main(){
    auto sp1=make_shared<SessionInfo>(1001);//初始化对象指针

    auto sp2=sp1;//指针指向同一个对象
    prosess(sp2);//传入形参时计数加1
    cout<<"exit process"<<endl;
    prosess1(sp2);//引用时计数不增加
    cout<<"cout number:"<<sp1.use_count()<<endl;
    sp2.reset();
    cout<<"cout number:"<<sp1.use_count()<<endl;
   
}