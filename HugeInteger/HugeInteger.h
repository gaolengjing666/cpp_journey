#include <iostream>
#include <string>


class HugeInteger{
private:
    char hugeint[41];
    const static size_t max_size=40;
    int count;
    void setcount();
public:
    
    void setInteger();
    void print();
    static void add(HugeInteger &a,HugeInteger &b);
};