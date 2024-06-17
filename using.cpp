#include <iostream>
#include <functional>
#include <string>
#include <vector>

#include "namespace.h"



// using 
// - using-declarations for namespace, class, and enum members
// - using-directives for namespaces
// - type alias (since C++11)
// - alias template declaration 

// https://en.cppreference.com/w/cpp/language/type_alias
// Type alias is a name that refers to a previously defined type (similar to typedef).
// Alias template is a name that refers to a family of types.
// template <class T>

void type_alias() {
    // this is identical to `typedef sz std::size_t;`
    // However, the typedef-declaration would throw an error because std::size_t is a qualified type.
    using sz = std::size_t;
    sz arr_size = 10;
    std::cout << "Type Alias output: " << arr_size << std::endl;
}

// An alias template is simply a way of creating a template for a type alias
template<typename T>
using vec = std::vector<T>;

void alias_template() {
    vec<int> mylist = {0,1,2,3};
    std::cout << "Type Alias output: ";
    for (auto _ : mylist)
        std::cout << _ << " ";
    std:: cout << std::endl;
}



int main() {
    std::cout << "Hello, World!" << std::endl;

    // using-declarations
    // same as using-directives but for namespace members
    using nick::edu::gpa;
    std::cout << "My name is " << nick::first_name << " and I'm studying " << nick::edu::degree << std::endl;
    std::cout << "My current GPA is: " << gpa << std::endl;


    if (true) {
        // using - using-directives for namespaces
        // allows unqualified lookup of names by
        // is only applied to current scope
        using namespace std;
        cout << "My favorite numbers are: ";
        for (int _ = 5; _ < 31; _ += 5) {
            cout << _ << " ";
        }
        cout << endl;

        // fruit f;
        cout << "My favorite fruits are: ";
        cout << fruit::banana << " " << fruit::orange << " ";
        
        // using - Using-enum-declaration (C++20)
        using enum fruit;
        cout << peach << endl;
    }

    std::cout << "Goodbye" << std::endl;


    type_alias();
    alias_template();


    return 0;
}

// using StatusTextCallback = std::function<void(StatusText)>;

// template<typename _Res, typename... _ArgTypes>
// class function<_Res(_ArgTypes...)> : public _Maybe_unary_or_binary_function<_Res, _ArgTypes...>, private _Function_base { 
//    /* code */ 
// }
