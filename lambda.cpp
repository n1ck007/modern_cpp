// Lambda Expressions (C++11)
// 	syntax `[](){};`
	
// 	[] capture clause
// 	() parameters
// 	{} definition
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;



int main() {
    // creating a struct and overriding an operator is a bit overkill
    // Use a lambda instead, the behaviour is the same.
    // struct {
    //     void operator() (int x) {
    //         cout << x << "\n";
    //     }
    // }something;
    // is the same  as
    // [](int x){cout << x << "\n";}

    vector<int> v{ 2, 3, 7, 14, 23 };
    // for_each(v.begin(), v.end(), something);
    for_each(v.begin(), v.end(), [](int x){cout << x << "\n";});

    // Another lambda example
    for_each(v.begin(), v.end(), [](int x) {
        if (x%2 == 0)
            cout << x << " is even\n";
        else
            cout << x << " is odd\n";
    });

    // a lambda has access to all the variables in it's enclosing scope



    return 0;
}