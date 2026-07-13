#include "Rational.cpp"
using namespace std;
int main(){
    Rational r1(1,2);
    Rational r2(3,4);
    Rational r3;
    cout<<"请输入一个分数，格式为：分子/分母"<<endl;
    cin>>r3;
    r1.Print();
    r2.Print();
    r3.Print();
    r1.RationalPlus(r1,r2);
    return 0;
}