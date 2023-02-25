#include<iostream>

using namespace std;

//C++ 17 main
int main() {
	cout << "Hello world!" << endl;
	
	int a = 10;
	int* pa = &a;

	int& b = a;

	cout << a << ":" << &a << endl;
	cout << *pa << ":" << pa <<":" << &pa << endl;
	cout << b << ":" << &b << endl;


}
