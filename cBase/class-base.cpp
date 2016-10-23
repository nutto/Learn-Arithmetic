#include <iostream>
using namespace std;
// ����һ���� 
class Rectangle {
    // Ĭ�ϵķ��ʵȼ�ΪPrivate 
    int width, height;
    public:  // ������������Ի��߷�����Public�ķ���Ȩ�� 
        void setValues(int, int);  // ����һ����Ա���� 
        int area() { return width * height; }  // ����һ����Ա���� 
        Rectangle() {}  // Ĭ�Ϲ��캯�� 
        Rectangle(int x, int y) : width(x), height(y) {}  // ��̬���캯��,ʹ�ó�Ա��ʼ���ķ��������ٳ�ʼ��width��height
        ~Rectangle() { cout << "destroy obj" << endl; }  // �������� 
};
// �����ⶨ��һ����Ա���� 
// ��::��������������޶�setValuesΪ Rectangle��һ����Ա���� 
void Rectangle::setValues(int x, int y) {
    width = x;
    height = y;
}
// ������ 
int main() {
    Rectangle rect;  // ʵ����һ������ 
    Rectangle rectb(5, 6);  // ʹ�ô������Ĺ��캯��,ʵ����һ������
    Rectangle rectc = {8, 9};  // ʹ��uniform ��ʽ���ù��캯�� 
    Rectangle* rectp = &rectc;  // ��ָ�� 
    rect.setValues(3, 4);
    cout << "area: " << rect.area() << endl;
    cout << "b area: " << rectb.area() << endl;
    cout << "c area: " << rectc.area() << endl;
    cout << "p area: " << rectp->area() << endl;  // ��ָ��ʹ��->���������ʳ�Ա�����ͳ�Ա���� 
    return 0;
}
