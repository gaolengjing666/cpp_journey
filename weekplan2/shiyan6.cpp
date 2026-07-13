#include <iostream>
#include <string>
using namespace std;
class store
{
private:
    static float m;//总重量
    static string name;//货物名称
public:
    static void setname(string mm){
        name=mm;
    }
    static void setstore(float mm=0.0){
        m=mm;
        cout<<"商店库存总重量为"<<m<<endl;
    }
    static void print(){
        cout<<"商店库存总重量为"<<m<<endl;
    }
    static void sell(float mm){
        m-=mm;
        cout<<"卖出了"<<mm<<endl;
        print();
    }
    static void buy(float mm){
        m+=mm;
        cout<<"买入了"<<mm<<endl;
        print();
    }
};

float store::m=0.0;
string store::name="none";

int main(){
    store::setname("apple");
    store::setstore(10000);
    store::sell(20);
    store::buy(200);
}