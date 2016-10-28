#include <iostream>
using namespace std;

// δ����� 

// ����һ������ģ�� 
template <typename SomeType>  // ָ�� SomeType Ϊģ������  ʹ��typename����class�ؼ�����ָ��ģ�����Ͷ����� 
SomeType sum(SomeType a, SomeType b) {  // �ں����Ķ�����ʹ��ģ������ 
	return a + b;
}

// ����һ������ָ�����Ͳ�����ģ�� 
template <class T>
T minus2 (T a, int b) {  // bΪһ��ָ������ 
	return a - b;
}

// ����һ����ģ��
template <class T>
class mycontainer {
		T element;
	public:
		mycontainer(T a, T b) {
			element = a + b;
		}
		T getEl() {
			cout << element << endl;
		}
};

// ����һ�����ģ��
template <>
class mycontainer <char> {
	char element_a;
	char element_b;
	public:
		mycontainer(char a, char b) {
			element_a = a;
			element_b = b;
		}
		char getEl() {
			cout << element_a << element_b << endl;
		}
}; 

int main() {
	// ָ�� int ���滻ģ������ SomeType 
	int result_i = sum<int> (10, 10);
	// ָ�� float ���滻ģ������ SomeType
	float result_f = sum<float> (1.2, 1.3);
	
	// �����ʹ�ü�����ָ������,���������Զ���⴫������� 
	// ���Ǵ�������ͱ�����û�������,���������������ȷ��ת������ 
	float a = 1.5;
	float b = 1.9;
	float result_f2 = sum(a, b);
	
	// ʹ��ָ������ģ��
	// Ҫע�����,5��λ��Ϊһ��ָ�����Ͳ���,�����ڱ����������ʱ��
	// д��,���Բ��ܴ���һ��������������� 
	float c = 10.9; 
	float result_f3 = minus2(c, 5); 

	// ʹ����ģ��
	mycontainer<int> mi(1, 4);
	mycontainer<float> ct(1.88, 4.98);
	mycontainer<char> st('a', 'b');
	mi.getEl();
	ct.getEl();
	st.getEl(); 
 
	cout << result_i << endl
		 << result_f << endl
		 << result_f2 << endl
		 << result_f3 << endl;
	return 0;
}
