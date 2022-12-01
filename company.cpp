#include<iostream>
#include <string>


using namespace std;
const string names[] =
        {"��һ", "�ܶ�", "����", "����", "����"};
const string positions[] =
        {"ǰ��", "���", "��ά", "����", "�޵���"};

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
            cout << e_name << "���ڹ���" << endl;
            return true;
        } else {
            cout << e_name << "δ��,������" << endl;
            return false;
        }
    }

    bool Card_clock() {
        if (e_card)cout <<e_name<< "�Ѵ�" << endl;
        else cout << e_name << "���ڴ�" << endl;
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
        cout << "0����,ѧIT,��н����,����" << C_name << endl;
        return true;
    }

    bool Assigning(string type) {
        bool t = false;
        for (int i = 0; i < 5; i++) {
            if (person[i].getPos() == type) {
                cout << person[i].getName() << "���ɳɹ�" << endl;
                t = true;
            }
        }
        if (!t)cout << "�޸�ְλԱ��������" << endl;
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
    cout << "�������ɵĹ���" << endl;
    for (auto x: positions) { cout << x << " "; }
    cout << endl;
    string choose;
    cin >> choose;

    A.Assigning(choose);
}

int main() {
    Employee a[5];
    Employee a1("��һ", 33, "��", positions[0], "�������ϰ���", "00001");
    a[0] = a1;
    Employee a2("�Ŷ�", 20, "��", positions[1], "�������ϰ���", "00002");
    a[1] = a2;
    Employee a3("����", 21, "��", positions[2], "�������ϰ���", "00003");
    a[2] = a3;
    Employee a4("����", 20, "Ů", positions[3], "�������ϰ���", "00004");
    a[3] = a4;
    Employee a5("����", 19, "Ů", positions[4], "�������ϰ���", "00005");
    a[4] = a5;
    Company A("CQUPT", "�������ϰ���", "school", a);
    test(A);
    return 0;
}