
#include <string>
using namespace std;
#ifndef HEADER_H
#define HEADER_H
class header{
	public:
	  void setName(string name);
	  string getName();
	private:
	 string m_strName;
};
#endif