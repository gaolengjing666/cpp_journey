//递归的使用
//递归的三要素（代码顺序）：定义，出口，调用
#include <iostream>
using namespace std;

//1.求n！
long long factorial(int n){//定义
    
    if(n<0){
        cerr<<"n不能为负数"<<endl;
        return -1;
    }
    //递归出口，设计结束
    if(n==0||n==1) return 1;
    //递归调用
    return n*factorial(n-1);
}

//输出斐波那契数列第n项
long long fib(int n){
    if(n<0){
        cerr<<"n不能为负数"<<endl;
        return -1;
    }
    int b=0;
    //出口
    if(n==0) return b;
    if(n==1) return 1;
    //调用
    return fib(n-1)+fib(n-2);

}

int main(){
    cout<<fib(2)<<endl;
    cout<<factorial(5)<<endl;
}