#include "HugeInteger.h"
using namespace std;
int main(){
    HugeInteger x,y;
    x.setInteger();
    y.setInteger();
    x.print();
    y.print();
    HugeInteger::add(x,y);
}