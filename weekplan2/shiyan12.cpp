#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Student
{
public:
    string name;
    string id;
    string gender;

    void input()
    {
        cin >> name >> id >> gender;
    }

    bool isZero()
    {
        return name == "0" && id == "0" && gender == "0";
    }

    void write(ofstream& out)
    {
        out << "姓名：" << name << endl;
        out << "学号：" << id << endl;
        out << "性别：" << gender << endl;
        out << "------------------------" << endl;
    }

    static void read(ifstream& in)
    {
        string line;
        string name, id, gender;
        int count = 0;
        while (getline(in, line))
        {
            if (line.find("姓名：") != string::npos)
            {
                name = line.substr(6);
                count++;
            }
            else if (line.find("学号：") != string::npos)
            {
                id = line.substr(6);
                count++;
            }
            else if (line.find("性别：") != string::npos)
            {
                gender = line.substr(6);
                count++;
            }
            if (count == 3)
            {
                cout << "姓名：" << name << endl;
                cout << "学号：" << id << endl;
                cout << "性别：" << gender << endl;
                cout << "------------------------" << endl;
                count = 0;
            }
        }
    }
};

int main()
{
    Student stu;
    ofstream out("stureginfo.txt", ios::app);
    while (true)
    {
        stu.input();
        if (stu.isZero())
            break;
        stu.write(out);
    }
    out.close();

    ifstream in("stureginfo.txt");
    Student::read(in);
    in.close();

    return 0;
}