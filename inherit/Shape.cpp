#include <iostream>
using namespace std;
/**

面向对象程序设计中最重要的一个概念是继承。继承允许我们依据另一个类来定义一个类，
这使得创建和维护一个应用程序变得更容易。这样做，也达到了重用代码功能和提高执行时间的效果。

当创建一个类时，您不需要重新编写新的数据成员和成员函数，
只需指定新建的类继承了一个已有的类的成员即可。这个已有的类称为基类，新建的类称为派生类。

继承代表了 is a 关系。

一个派生类继承了所有的基类方法，但下列情况除外：

基类的构造函数、析构函数和拷贝构造函数。
基类的重载运算符。
基类的友元函数。


*/
class Shape {
	public:
	   void setWidth(int w) {
		   width = w;
	   }
	   void setHeight(int h) {
		   height = h;
	   }
	protected:
	int width;
	int height;
};
// 基类 PaintCost
class PaintCost 
{
   public:
      int getCost(int area)
      {
         return area * 70;
      }
};
// 派生类
class Rectangle: public Shape , public PaintCost{
	public:
	  int getArea() {
		  return width*height;
	  }
};

int main () {
	Rectangle rect;
	int area;
	rect.setWidth(5);
	rect.setHeight(7);
	area = rect.getArea();
	
	cout << "total area: " << rect.getArea() <<endl;
	// 输出总花费
   cout << "Total paint cost: $" << rect.getCost(area) << endl;
	
	return 0;
}