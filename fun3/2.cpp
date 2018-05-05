#include <iostream>

class Base
{
public:
   Base(int i = 0, const std::string& s = "") : i_{i}, s_{s} {}
   virtual ~Base() = default;
   void print(){
      std::cout << i_ << std::endl << s_ << std::endl;
   }
protected:
//private:
    Base(const Base&) = default; // cppreference: Typical declaration of a copy constructor. 
    Base& operator=(const Base&) = delete; // cppreference: Typical declaration of a copy assignment operator when copy-and-swap idiom cannot be used
private:
    int i_;
    std::string s_;
};

class Derived : public Base
{
public:
    using Base::Base;
};


/* QUESTIONS
    Which special member functions will Derived have?
    Which access will they have?
    Which access, if the protected declarations are moved to private?

    Experiment (default/delete, protected/private)!     
*/

// Print function that invokes copy cosntructor by taking argument by value
void printCopy(Base b){
   b.print();
}

// Print function that invokes copy cosntructor by taking argument by value
void printCopy(Derived d){
   d.print();
}


int main(){

   Base b(3,"base");
   Derived d(4,"der");

   //Base b1 = b; b1.print();
   //Derived d1 = d; d1.print();

   //b.print();
   //d.print();
 
   // ANSWERS
   // Special member functions
   // Default constructor
   Derived d2; 
   d2.print();
   // Copy constructor // "construct a fresh object based on the state of an existing object"
   // https://stackoverflow.com/questions/4172722/what-is-the-rule-of-three/4172724#4172724
   std::cout << "Copy constructor\n"; 
   Derived d3(d); 
   printCopy(d3); 
   //printCopy(b); // not allowed
   // Move constructor - NA if copy constructor
   // Copy assignment operator // "modify an existing object based on the state of another existing object"
   std::cout << "Copy assignment operator\n";
   Derived d4(1,"hej");
   Derived d5(2,"bil");
   printCopy(d4);
   // d4 = d5; // Not allowed! No copy assignment operator!
   printCopy(d4);
   // Move assignment operator - NA if copy constructor
   
   // Destructor    
   // Classes always has a destructor?
}
