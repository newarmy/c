#include <iostream>
using namespace std;
/**
在 C++ 中，每一个对象都能通过 this 指针来访问自己的地址。this 指针是所有成员函数的隐含参数。
因此，在成员函数内部，它可以用来指向调用对象。

友元函数没有 this 指针，因为友元不是类的成员。只有成员函数才有 this 指针。
我们可以使用 static 关键字来把类成员定义为静态的。当我们声明类的成员为静态时，这意味着无论创建多少个类的对象，静态成员都只有一个副本。

静态成员在类的所有对象中是共享的。如果不存在其他的初始化语句，在创建第一个对象时，
所有的静态数据都会被初始化为零。我们不能把静态成员的初始化放置在类的定义中，
但是可以在类的外部通过使用范围解析运算符 :: 来重新声明静态变量从而对它进行初始化，如下面的实例所示。

静态成员函数与普通成员函数的区别：

静态成员函数没有 this 指针，只能访问静态成员（包括静态成员变量和静态成员函数）。
普通成员函数有 this 指针，可以访问类中的任意成员；而静态成员函数没有 this 指针。
*/
class Box {
  public:
    static int objectCount;
    Box(double l = 2.0, double w = 2.0, double h = 2.0) {
		 cout <<"Constructor called." << endl;
		 this->length = l;
		 this->width = w;
		 this->height = h;
		 objectCount++;
		 
	}  
	double volume() {
		return length*width*height;
	}
	int compare(Box box) {
		return this->volume() > box.volume();
	}
	static int getCount(){
		//length = 2; error
		return objectCount;
	}
   private:
    double length;
	double width;
	double height;
	
};
int Box::objectCount = 0;

int main () {
	Box box1(3.3, 1.2, 1.5);
	Box box2(10.0, 10.0, 3.0);
	if(box1.compare(box2)) {
		 cout << "Box2 is smaller than Box1" <<endl;
	} else {
		cout << "Box2 is equal to or larger than Box1" <<endl;
	}
	Box *ptrBox;
	ptrBox = &box1;
	 cout << "Volume of ptrBox: " << ptrBox->volume() << endl;
	 
	  cout << "Total objects: " << Box::getCount() << endl;
	return 0;
}