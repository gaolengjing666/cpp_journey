#include <iostream>
#include <cmath>
using namespace std;

// 抽象基类
class Base {
public:
    virtual double area() const = 0;  // 纯虚函数
    virtual ~Base() {}
};

// 三角形
class Triangle : public Base {
private:
    double a, b, c;
public:
    Triangle(double x, double y, double z) : a(x), b(y), c(z) {}
    double area() const override {
        double p = (a + b + c) / 2;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }
};

// 正方形
class Square : public Base {
private:
    double side;
public:
    Square(double s) : side(s) {}
    double area() const override {
        return side * side;
    }
};

// 圆形
class Circle : public Base {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double area() const override {
        return 3.14159 * radius * radius;
    }
};

// 单接口多实现
void printArea(Base* p) {
    cout << "面积为: " << p->area() << endl;
}

int main() {
    Triangle tri(3, 4, 5);
    Square sq(5);
    Circle cir(3);

    printArea(&tri);
    printArea(&sq);
    printArea(&cir);

    return 0;
}