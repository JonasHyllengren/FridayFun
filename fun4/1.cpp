
struct S
{
    S() : value_{0} {}
    S(int x) : value_{x} {}
    S(S&&) = delete; // move ctor 
    S& operator=(S&&) = delete; // Move assignment operator disabled?
    int value_;
};
 
S operator+(const S& x, const S& y)
{
    S s;
    s.value_ = x.value_ + y.value_;
    return s;
}
 
int main()
{
    S s1{1}; // Cntr call, ok
    S s2{2};
    S s3 = s1 + s2; // Move ctor, not ok
    //S s3{s1+s2}; // This should be ok
    //S stemp; S s3 = steemp; // Move ctor, not ok
    //S s3; s3 = s1+s2; // Move assignmentoperator, not ok
    
    return 0;
}

// Guess: Problems at "S s3 = s1 + s2". Why? Because "s1+s2" results in a S object, which we use move ctor to s3, but move ctor is disallowed. But why doesn't this use copy ctor? Would "S s3{s1+s2};" be ok?
