#include "Rational.h"
#include <cmath>
#include <numeric>


void Rational::normalize(){
    if(denominator<0){
        numerator=-numerator;
        denominator=-denominator;
    }
    int g=std::gcd(abs(numerator),denominator);//辗转相除法得到最大公约数
    numerator=numerator/g;
    denominator=denominator/g;
}

Rational::Rational(int x,int y):numerator(x),denominator(y){
    if(denominator==0){
        std::cout<<"分母不能为0，请重新输入分母:"<<std::endl;
        std::cin>>denominator;
        normalize();

    }
    normalize();
}

void Rational::RationalPlus(Rational x1,Rational y1){
    int numplus;
    int denoplus;
    
    int g=std::lcm(abs(x1.denominator),abs(y1.denominator));//最小公倍数
    numplus=x1.numerator*y1.denominator+y1.numerator*x1.denominator;
    denoplus=x1.denominator*g;
    Rational plusResult(numplus,denoplus);
    std::cout<<"相加结果是"<<static_cast<double> (plusResult.numerator)/static_cast<double> (plusResult.denominator)<<std::endl;

}

void Rational::Print(){
    std::cout<<numerator<<"/"<<denominator<<std::endl;
}

void Rational::doublePrint(){
    std::cout<<numerator/denominator<<std::endl;
}

 std::istream&/*in stream输入流，返回一个istream对象的引用*/ operator>>(std::istream& in/*给cin取一个别名*/,Rational& f){
    int num,den;
    char slash;

    if(in>>num>>slash>>den){
        if(slash=='/'){
            if(den==0){
                in.setstate(std::ios::failbit);
                return in;//此时输入流中状态为fail，不进行输入赋值，r3为垃圾值，需要用cin.clear()清除fail状态
            }
            f.numerator=num;
            f.denominator=den;
            f.normalize();
        } else{
            in.setstate(std::ios::failbit);
        }
    }
    return in;
 }