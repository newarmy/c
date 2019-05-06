#include <iostream>
using namespace std;

class Box {
	
	double width;
	public:
	  friend void printWidth(Box box);
	  friend class BigBox;
	  /*
	  C++ 内联函数是通常与类一起使用。如果一个函数是内联的，那么在编译时，编译器会把该函数的代码副本放置在每个调用该函数的地方。

对内联函数进行任何修改，都需要重新编译函数的所有客户端，因为编译器需要重新更换一次所有的代码，否则将会继续使用旧的函数。

如果想把一个函数定义为内联函数，则需要在函数名前面放置关键字 inline，在调用函数之前需要对函数进行定义。如果已定义的函数多于一行，编译器会忽略 inline 限定符。

在类定义中的定义的函数都是内联函数，即使没有使用 inline 说明符。
	  */
	  inline void setWidth(double wid);
};

void Box::setWidth(double wid) {
	width =wid;
}


class BigBox {
	public:
	void print(int width, Box &box) {
		//  // BigBox是Box的友元类，它可以直接访问Box类的任何成员
		box.setWidth(width);
		  cout << "Width of box : " << box.width << endl;
	}
};


// 请注意：printWidth() 不是任何类的成员函数
/**
友元函数的使用

因为友元函数没有this指针，则参数要有三种情况： 

要访问非static成员时，需要对象做参数；

要访问static成员或全局变量时，则不需要对象做参数；

如果做参数的对象是全局对象，则不需要对象做参数.

可以直接调用友元函数，不需要通过对象或指针
*/
void printWidth(Box box) {
	/* 因为 printWidth() 是 Box 的友元，它可以直接访问该类的任何成员 */
	cout << "width of box : " << box.width <<endl;
}



int main () {
	Box box;
	BigBox big;
	
	box.setWidth(10.2);
	 // 使用友元函数输出宽度
	printWidth(box);
	
	 // 使用友元类中的方法设置宽度
	big.print(20.22, box);
	
	return 0;
}