#include <string>
#include "header.h"
using namespace std;
void header::setName(string name) {
	m_strName = name;
}
string header::getName() {
	return m_strName;
}