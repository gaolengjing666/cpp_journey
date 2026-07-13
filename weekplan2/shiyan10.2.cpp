#include <iostream>
#include <string>
using namespace std;

class Motor {
protected:
    int people;          // 可载人数
    int tires;           // 轮胎数
    int horsepower;      // 马力数
    string factory;      // 生产厂家
    string owner;        // 车主
public:
    Motor(int p, int t, int h, const string& f, const string& o)
        : people(p), tires(t), horsepower(h), factory(f), owner(o) {}
    virtual void Display() const {
        cout << "载人数: " << people << " 轮胎数: " << tires
             << " 马力: " << horsepower << " 厂家: " << factory
             << " 车主: " << owner;
    }
    virtual ~Motor() {}
};

class Car : public Motor {
public:
    Car(int p, int t, int h, const string& f, const string& o)
        : Motor(p, t, h, f, o) {}
    void Display() const override {
        cout << "【轿车】";
        Motor::Display();
    }
};

class Bus : public Motor {
private:
    int number;  // 车厢节数
public:
    Bus(int p, int t, int h, const string& f, const string& o, int n)
        : Motor(p, t, h, f, o), number(n) {}
    void Display() const override {
        cout << "【巴士】";
        Motor::Display();
        cout << " 车厢节数: " << number;
    }
};

class Truck : public Motor {
private:
    double weight;  // 载重量
public:
    Truck(int p, int t, int h, const string& f, const string& o, double w)
        : Motor(p, t, h, f, o), weight(w) {}
    void Display() const override {
        cout << "【卡车】";
        Motor::Display();
        cout << " 载重量: " << weight << "吨";
    }
};

// 统一的全局显示函数（主函数中调用，不直接调用Display）
void ShowInfo(Motor& m) {
    m.Display();
    cout << endl;
}

int main() {
    Car c(5, 4, 120, "比亚迪", "张三");
    Bus b(40, 6, 200, "宇通", "李四", 2);
    Truck t(3, 8, 300, "解放", "王五", 15.5);

    ShowInfo(c);
    ShowInfo(b);
    ShowInfo(t);

    return 0;
}