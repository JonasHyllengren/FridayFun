#include <iostream>
#include <vector>


using namespace std;

ostream& operator<<(ostream& os, const int* p){
   
   cout << *p << endl;
   return os;

}




int main()
{
    vector<int*> a{ new int(17), new int(4711), new int(11147) };

    for (auto const& p: a)
        cout << *p << '\n';
    cout << '\n';

    return 0;
}
