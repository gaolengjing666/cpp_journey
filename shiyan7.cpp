#include <iostream>

using namespace std;

class point{
private:
    double x;
    double y;
public:
    point(double x=0.0,double y=0.0);
    point &operator++();
    friend ostream &operator<<(ostream &out, const point &p);
};

point::point(double xx,double yy):x(xx),y(yy)
{

}

point &point::operator++(){
    ++x;
    ++y;
    return *this;
}

ostream &operator<<(ostream &out, const point &p){
    out << "(" << p.x << ", " << p.y << ")";
    return out;
}


