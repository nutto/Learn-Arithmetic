#include <iostream>
using namespace std;

// 未完待续 

// 定义一个函数模板 
template <typename SomeType>  // 指定 SomeType 为模板类型  使用typename或者class关键字来指定模板类型都可以 
SomeType sum(SomeType a, SomeType b) {  // 在函数的定义中使用模板类型 
	return a + b;
}

// 定义一个带有指定类型参数的模板 
template <class T>
T minus2 (T a, int b) {  // b为一个指定类型 
	return a - b;
}

int main() {
	// 指定 int 来替换模板类型 SomeType 
	int result_i = sum<int> (10, 10);
	// 指定 float 来替换模板类型 SomeType
	float result_f = sum<float> (1.2, 1.3);
	
	// 如果不使用尖括号指定类型,编译器会自动检测传入的类型 
	// 但是传入的类型必须是没有歧义的,否则编译器不能正确地转换类型 
	float a = 1.5;
	float b = 1.9;
	float result_f2 = sum(a, b);
	
	// 使用指定参数模板
	// 要注意的是,5的位置为一个指定类型参数,它会在编译器编译的时候
	// 写死,所以不能传递一个变量进这个参数 
	float c = 10.9; 
	float result_f3 = minus2(c, 5); 
 
	cout << result_i << endl
		 << result_f << endl
		 << result_f2 << endl
		 << result_f3 << endl;
	return 0;
}
