#include <iostream>
using namespace std;


// δ����� 
class CVector {
	public:
		int x, y;
		// ��̬��ı�������Ϊ��ı��������Ӧ���Ƕ���ı����������Ĵ洢������أ�
		// һ����ֻ����һ���洢�ռ䣬���½������ʱ������ռ䲢�����ʼ�� 
		static int n;
		
		// ����ͨ����̬������ͳ�����ʼ���Ĵ��� 
		CVector () { n++; };
		CVector (int a, int b) : x(a), y(b) { n++; }
		 // ��ĳ�������������+�����㷽ʽ,�����غ����������԰������·�ʽ����
		 //  c = a + b; �� c = a.operator+ (b); ��һ����Ч��
		 // ���ڸ�������������ط�ʽ�����꿴 @link: http://www.cplusplus.com/doc/tutorial/templates/ 
		CVector operator + (const CVector&);
		CVector operator = (const CVector&);
		
		// ��̬��������̬�����ĸ���;�̬������ʵ��࣬һ����ֻ���һ���ط�
		// ���Ծ�̬����ֻ�ܷ��ʾ�̬������Ҳ���ܷ���thisָ������ָ�� 
		static int getN() {
			// return x;  // ���ܷ��ʷǾ�̬���� 
			return n;
		}
};

CVector CVector::operator +(const CVector& param) {
	CVector temp;
	temp.x = x + param.x;
	temp.y = y + param.y;
	return temp;
}

// Ϊ�˱����εĳ�ʼ����̬��������̬�������������г�ʼ����ֻ���������ʼ�� 
int CVector::n = 0;

CVector CVector::operator =(const CVector& param) {
	this->x = param.x;  // �ؼ���thisΪָ����Ķ���ָ�� 
	this->y = param.y;  // ʹ��ָ��ķ�ʽ��ȡֵ 
	cout << "show:" << x << ',' << y << endl;
	return *this;  // ���ر����� 
}

int main() {
	CVector foo (3, 1);
	CVector bar (1, 2);
	CVector result;
	result = foo + bar;
	cout << result.x << ',' << result.y << endl;
	// ��̬��������ͨ�����������ֱ�ӷ��ʣ�Ҳ����ͨ���������
	cout << "�����������ʣ�" << CVector::n << endl;
	cout << "������ʣ�" << result.n << endl;
	cout << "��̬�������ʣ�" << result.getN() << endl;
	return 0;
}
