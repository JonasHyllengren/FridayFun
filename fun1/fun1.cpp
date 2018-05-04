#include <iostream>

using namespace std;

/*
// Overload char* <<, print with string <<
ostream& operator<< (ostream& os, const char* str) 
{
    return os << string("Initialisation\n") << string(str) << string("Cleanup\n");
}
*/

// Call std::<< explicitly
ostream& operator<< (ostream& os, const char* str) 
{
    std::operator<<(os, "Initialisation\n");
    std::operator<<(os, str);
    std::operator<<(os, "Cleanup\n");
    return os;
}

int main()

{

    cout << "Hello!\n";

}
