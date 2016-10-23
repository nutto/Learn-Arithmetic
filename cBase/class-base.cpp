#include <iostream>
using namespace std;
// 定义一个类 
class Rectangle {
    // 默认的访问等级为Private 
    int width, height;
    public:  // 声明下面的属性或者方法是Public的访问权限 
        void setValues(int, int);  // 声明一个成员方法 
        int area() { return width * height; }  // 定义一个成员方法 
        Rectangle() {}  // 默认构造函数 
        Rectangle(int x, int y) : width(x), height(y) {}  // 多态构造函数,使用成员初始化的方法来快速初始化width和height
        ~Rectangle() { cout << "destroy obj" << endl; }  // 析构函数 
};
// 在类外定义一个成员方法 
// 用::作用域操作符来限定setValues为 Rectangle的一个成员方法 
void Rectangle::setValues(int x, int y) {
    width = x;
    height = y;
}
// 主函数 
int main() {
    Rectangle rect;  // 实例化一个对象 
    Rectangle rectb(5, 6);  // 使用带参数的构造函数,实例化一个对象
    Rectangle rectc = {8, 9};  // 使用uniform 方式调用构造函数 
    Rectangle* rectp = &rectc;  // 类指针 
    rect.setValues(3, 4);
    cout << "area: " << rect.area() << endl;
    cout << "b area: " << rectb.area() << endl;
    cout << "c area: " << rectc.area() << endl;
    cout << "p area: " << rectp->area() << endl;  // 类指针使用->操作符访问成员函数和成员变量 
    return 0;
}
