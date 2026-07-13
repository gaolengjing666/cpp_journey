//alt+/  启用自动生成
#include <iostream>
using namespace std;
class Cpoint{
public:
  Cpoint();
  Cpoint(int n,int m);
  Cpoint(Cpoint &p);
  void Print();
private:
  int x;
  int y;
};
Cpoint::Cpoint():x(0),y(0){
}
Cpoint::Cpoint(int n,int m):x(n),y(m){

}
Cpoint::Cpoint(Cpoint &p){
  x=p.x;
  y=p.y;
}
void Cpoint::Print(){
  cout<<"x="<<x<<"y="<<y<<endl;
}

int main(){
  Cpoint a;
  a.Print();
  Cpoint b(1,0);
  b.Print();
  Cpoint c(b);
  c.Print();
}