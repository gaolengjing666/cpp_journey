#include "HugeInteger.h"
#include <algorithm>



//注意字符型的计算转换

void HugeInteger::setcount(){
    int find=0;
    while(find<=max_size&&hugeint[find]=='0'){
        find++;
    }
    count=max_size-find;
    if(count==0){//输入为0时
        count=1;
    }
}
void HugeInteger::setInteger(){
    std::string input;
    do{//do while循环判断输入正确，不正确时销毁重新申请栈内存，若函数嵌套，会占用多个栈内存
        std::cout<<"请输入不超过40位的整数"<<std::endl;
        std::cin>>input;
    }while(input.size()>40);
    for(int i=39,j=input.size()-1/*数组从0开始，需减1*/;i>=0;i--){
        hugeint[max_size]='\0';
        if(j>=0){
            hugeint[i]=input[j];
            j--;
        }else {
            hugeint[i]='0';
        }//鍓嶉潰鏄珮浣?
    }
    setcount();
}

void HugeInteger::print(){
    int i=max_size-this->count;
    for(;i<max_size;i++){
        std::cout<<hugeint[i];
    }
    std::cout<<std::endl;
}
void HugeInteger::add(HugeInteger &a,HugeInteger &b){//
    char result[41];
    int number=max_size-1;//从0开始需减1
    int store=0;//进位存储
    result[40]='\0';

    for(;number>=0;number--){
        int carry;//进位判断
        carry=(a.hugeint[number]-'0')+(b.hugeint[number]-'0')+store;
        store=0;//存储消耗
        if(carry>9){
            carry%=10;
            result[number]=carry+'0';
            store=1;
        }else {
            result[number]=carry+'0';
        }
    }
    if(store==1){
        std::cout<<"超出部分不显示"<<std::endl;
    }
    std::cout<<"结果为："<<std::endl;;
    for(number=0;number<max_size;number++){//排除0
        if(result[number]!='0'){
            break;//
        }
    }
    if(number==max_size){//都为0时特殊处理
        std::cout<<'0';
    } else{
        for(;number<max_size;number++){
        std::cout<<result[number];
        }
    }
    std::cout<<std::endl;
}
