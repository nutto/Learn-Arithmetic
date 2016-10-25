#include <iostream>
using namespace std;


class CVector {
	public:
		int x, y;
		// 静态类的变量被称为类的变量（相对应的是对象的变量），它的存储与类相关，
		// 一个类只会有一个存储空间，当新建对象的时候这个空间并不会初始化 
		static int n;
		
		// 可以通过静态变量来统计类初始化的次数 
		CVector () { n++; };
		CVector (int a, int b) : x(a), y(b) { n++; }
		 // 对某个类重载运算符+的运算方式,被重载后的运算符可以按照以下方式调用
		 //  c = a + b; 和 c = a.operator+ (b); 是一样的效果
		 // 关于各个运算符的重载方式可以详看 @link: http://www.cplusplus.com/doc/tutorial/templates/ 
		CVector operator + (const CVector&);
		CVector operator = (const CVector&);
		
		// 静态方法，静态方法的概念和静态变量其实差不多，一个类只会存一个地方
		// 所以静态方法只能访问静态变量，也不能访问this指向对象的指针 
		static int getN() {
			// return x;  // 不能访问非静态变量 
			return n;
		}
};

CVector CVector::operator +(const CVector& param) {
	CVector temp;
	temp.x = x + param.x;
	temp.y = y + param.y;
	return temp;
}

// 为了避免多次的初始化静态变量，静态变量不能在类中初始化，只能在类外初始化 
int CVector::n = 0;

CVector CVector::operator =(const CVector& param) {
	this->x = param.x;  // 关键字this为指向本类的对象指针 
	this->y = param.y;  // 使用指针的方式获取值 
	cout << "show:" << x << ',' << y << endl;
	return *this;  // 返回本对象 
	
	// 以下是三种不同的定义方式决定成员函数不同的意义 
	// int get() const {return x;}        // const member function  常量成员函数中不能使用non-static的成员变量和non-const成员函数 
	// const int& get() {return x;}       // member function returning a const&
	// const int& get() const {return x;} // const member function returning a const&  
	// 详情可以查看 @link: http://www.cplusplus.com/doc/tutorial/templates/
}

int main() {
	CVector foo (3, 1);
	CVector bar (1, 2);
	CVector result;
	
	// 常量对象,常量对象的属性被外部访问的时候表现得像常量一样 
	const CVector con_obj(5,6); // 常量函数的成员变量可以通过构造函数初始化 
	//  常量对象不能调用非常量的成员函数 
	// con_obj.getN(); // 错误,不能调用非常量的成员函数
	// con_obj.x = 1; // 错误,常量对象的成员函数不能被修改 
	
	result = foo + bar;
	cout << result.x << ',' << result.y << endl;
	// 静态变量可以通过类的作用域直接访问，也可以通过对象访问
	cout << "类的作用域访问：" << CVector::n << endl;
	cout << "对象访问：" << result.n << endl;
	cout << "静态函数访问：" << result.getN() << endl;
	return 0;
}
