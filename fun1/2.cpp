#include <iostream>
#include <typeinfo>

using namespace std;

int main(){
int(x(int()));

cout<< typeid(3).name() << endl;
cout << typeid(x).name() << endl;
cout << typeid(int(x(int()))).name() << endl;



}
