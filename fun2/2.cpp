//What is this? What does it do, in detail? 

// Declare a constructor (copy?) that takes a reference to an object of the same type as input? 
//But why "::"?
C::C(const C& other)
{
    if (this != &other) // If other isn't "empty"/"fresh"
    {
        p_ = new T{*other.p_}; // p_ is a private pointer? Point p_ at a copy of the T object that other's p_ is pointing at?
    }
}

/*
A better implementation, doing member-wise copy initialization:  
C::C(const C& other) : p_{ new T{ *other.p_} } {} 
Corresponding move constructor, if no swap available:  
C::C(C&& other) : p_{ other.p_ } { other.p_ = nullptr; } 
If p_ is initialized to nullptr in its declaration and a swap is available we could do it this way:  
C::C(C&& other) { swap(other); }
*/


//    What would the following modification imply for the String class code example? 
explicit String(const String&);  
// copy constructor becomes explict
// char* a = "abc";
// String b = a; // This no longer works?
/*
Explicit copy constructor will disallow passing function parameter by value, and function return by value.            
*/
