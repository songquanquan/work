#include<iostream>
#include <string>


using namespace std;
const string names[] =
        {"王一", "熊二", "张三", "李四", "刘五"};
const string positions[] =
        {"前端", "后端", "运维", "测试", "修电脑"};

class Employee {
public:
    Employee() {};

    Employee(string name, int age, string sex, string position, string address, string number)
            : e_name(name), e_age(age), e_sex(sex), e_position(position),
              e_address(address), e_number(number), e_card(false) {}

    ~Employee() {}

    void setName(string s) { e_name = s; }

    void setPos(string s) { e_position = s; }

    void setSex(string s) { e_sex = s; }

    void setAge(int a) { e_age = a; }

    void setNmb(string nmb) { e_number = nmb; }

    string getName() { return e_name; }

    string getPos() { return e_position; }

    string getSex() { return e_sex; }

    int getAge() { return e_age; }

    string getNmb() { return e_number; }

    bool Work() const {

        if (e_card) {
            cout << e_name << "正在工作" << endl;
            return true;
        } else {
            cout << e_name << "未打卡,不许工作" << endl;
            return false;
        }
    }

    bool Card_clock() {
        if (e_card)cout <<e_name<< "已打卡" << endl;
        else cout << e_name << "正在打卡" << endl;
        return this->e_card = true;
    }

private:
    int e_age;
    bool e_card;
    string e_name;
    string e_sex;
    string e_position;
    string e_address;
    string e_number;
};

class Company {
public:
    Company(string name, string address, string type, Employee sts[])
            : C_name(name), C_address(address),
              C_type(type), number(0) {
        for (int i = 0; i < 5; i++) {
            person[i] = sts[i];
        }
    }

    ~Company() {};


    bool publicity() {
        cout << "0基础,学IT,月薪过万,就上" << C_name << endl;
        return true;
    }

    bool Assigning(string type) {
        bool t = false;
        for (int i = 0; i < 5; i++) {
            if (person[i].getPos() == type) {
                cout << person[i].getName() << "外派成功" << endl;
                t = true;
            }
        }
        if (!t)cout << "无该职位员工可外派" << endl;
    }

    void addemp(const Employee e) {
        if (number < 5) {
            person[number] = e;
            ++number;
        }
    }
    void reminder()
    {
        for(auto& x:person)
        {
            x.Card_clock();
        }
    }
    void work()
    {
        for(auto &x:person)
        {
            x.Work();
        }
    }
private:
    Employee person[5];
    string C_name;
    string C_address;
    string C_type;
    int number;
};

void test(Company &A) {

    A.work();
    A.reminder();
    A.work();
    cout << "输入外派的工作" << endl;
    for (auto x: positions) { cout << x << " "; }
    cout << endl;
    string choose;
    cin >> choose;

    A.Assigning(choose);
}

int main() {
    Employee a[5];
    Employee a1("张一", 33, "男", positions[0], "重庆市南岸区", "00001");
    a[0] = a1;
    Employee a2("张二", 20, "男", positions[1], "重庆市南岸区", "00002");
    a[1] = a2;
    Employee a3("张三", 21, "男", positions[2], "重庆市南岸区", "00003");
    a[2] = a3;
    Employee a4("张四", 20, "女", positions[3], "重庆市南岸区", "00004");
    a[3] = a4;
    Employee a5("张五", 19, "女", positions[4], "重庆市南岸区", "00005");
    a[4] = a5;
    Company A("CQUPT", "重庆市南岸区", "school", a);
    test(A);
    return 0;
}