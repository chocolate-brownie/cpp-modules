#include <iostream>

namespace MyNameSpace {
	int x = 42;
}

using namespace std;

int main(void)
{
	cout << MyNameSpace::x << endl;
	cout << MyNameSpace::x << endl;
	return 0;
}
