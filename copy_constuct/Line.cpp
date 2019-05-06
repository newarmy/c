#include <iostream>
using namespace std;

class Line {
	
	public:
	 int getLength(void);
	 Line (int len);
	 Line (const Line &obj); // 拷贝构造函数
	 ~Line();
	private:
	 int *ptr;
};

Line::Line(int len) {
	
	cout << "调用构造函数" << endl;
	// 为指针分配内存
	ptr = new int;
	*ptr = len;
}
Line::Line(const Line &obj) {
	cout << "调用拷贝构造函数并为指针 ptr 分配内存" << endl;
	ptr = new int;
	*ptr = *obj.ptr;
}
Line::~Line() {
	cout << "release memory" <<endl;
	delete ptr;
}
int Line::getLength( void )
{
    return *ptr;
}

void display(Line obj) {
	cout << "line 大小 : " << obj.getLength() <<endl;
}

int main () {
	Line line(10);
	display(line);
	return 0;
}