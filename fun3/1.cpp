#include <iostream>

using namespace std;

class Base {
public:
    Base(int i) : value_{ i } {}
    Base(){}
    void print(){
      cout << value_ << endl;
    }
protected:
    int value_;
};

/* Not ok!
class Derived_1 : public Base {
    Derived_1(int v){
      value_ = v;
    }
};
*/ // Fixed
struct Derived_1 : public Base {
    Derived_1(int i) : Base(i+1) {}
};



/*
struct Derived_2 : public Derived_1 {
    Derived_2(int v) : Base{ v }, Derived_1{ v } {}
};
// legal?
*/ //Fixed
struct Derived_2 : public Derived_1 {
    Derived_2(int v) : Derived_1{ v+1 } {}
};


/*
struct Derived_3 : public Base {
    Derived_3() {}
};
// legal?
*/ // Fixed
struct Derived_3 : public Base {
    Derived_3() : Base(0) {}
};


int main(){
   Base b{1};
   Derived_1 d1{1}; 
   Derived_2 d2{1};
   Derived_3 d3;
   
   b.print();
   d1.print();
   d2.print();
   d3.print();
}
