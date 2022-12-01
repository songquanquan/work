#include <cstring>

using namespace std;

class apple {
public:
    apple() : m_norder(0), m_nShape(0) {
        m_weight = new int(0);
    }

    apple(const apple &a) {
        m_norder = a.m_norder;
        m_nShape = a.m_nShape;
        strcpy_s(m_szDetail, a.m_szDetail);
        m_weight = new int(*a.m_weight);
    }

    ~apple() {
        delete m_weight;
    }

    /*
˵�����÷�������ʵ�ֳ�Ա����m_norder�ļ�norder����
*/
    void apple_number_dec(int norder) {
        m_norder -= norder;
    }

/*
˵�����÷�������ʵ�ֳ�Ա����m_norder�ļ�norder����
*/
    void apple_number_add(int norder) {
        m_norder += norder;
    }

    int m_nShape;
    int m_norder;
    char m_szDetail[100];

private:
    int *m_weight;
};

int main() {
    apple A;
    A.apple_number_add(4);
    apple B = A;
}