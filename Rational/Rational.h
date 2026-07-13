#include <iostream>


class Rational{
private:
    int numerator;
    int denominator;

public:
    Rational(int x=0,int y=1);
    void normalize();
    void RationalPlus(Rational x1,Rational y1);
    void Print();
    void doublePrint();
    friend std::istream&/*in stream输入流*/ operator>>(std::istream& in,Rational& f);

};