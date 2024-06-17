// Preliminary concepts:
// 1. Name lookup: associating names with declarations.
// 2. Name binding: associating names with addresses, i.e. data.
// 3. A qualified name is a name that appears on the rhs of the scope 
//    resolution operator `::`, i.e. a member of a class, namespace or enum.
// 4. There two types of templates: class and function
//
// Centeral concept:
// A dependant name is a name whose type depends on a template parameter.
//
// Lookup and Bind time
// 1. Non-dependent names: template definition.
// 2. Dependent names: postponed until parent template arguments are known.
//
// The `typename` disambiguator for dependent names:
// A dependent name is not deduced to be a type name unless the keyword `typename` is used,
// unless it was somehow previously established as a type name, like in a typedef-declaration.
//
// The `template` disambiguator for dependent names:
// A dependent name is not deduced to be a template name unless the keyword `template` is used,
// unless it was somehow previously established as a template name.
//
// Special Case Execption - Current Instantiation
// Within a class template definition, some names may be deduced to refer to the current 
// instantiation. This allows certain errors to be detected at the point of definition, 
// rather than instantiation, and removes the requirement on the `typename` and `template` 
// disambiguators for dependent names.

#include <iostream>
#include <array>
#include <vector>

using namespace std;


template <typename T, std::size_t n>
void InsertionSort(std::array<T, n> &arr) {
    // for each item
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        // insert into correct position in subarray
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// Dependent type name in a function template:
// `auto` can be replaced with `std::array<int, 5>::value_type` 
// and the program with run with no errors. To be more generic 
// we can use `std::array<T, n>::value_type`. But 
// `std::array<T,n>::value_type` is a dependant type name,
// so the keyword `typename` must be used.
template <typename T, std::size_t n>
void PrintArray(std::array<T,n> arr) {
    for (typename std::array<T,n>::value_type _ : arr) {
        std::cout << _ << " ";
    }
    std::cout << std::endl;

}

// But we can make things even more generic like this.
template <typename T>
void PrintContainer(T arr) {
    for (typename T::value_type _ : arr) {
        std::cout << _ << " ";
    }
    std::cout << std::endl;

}

int main() {
    std::vector<std::string> v = {"E", "\u018E"};
    std::array<int,5> a = { 12, 11, 13, 5, 6 };
    
    PrintContainer(a);
    // InsertionSort(a);
    // PrintArray(a);

    return 0;
}
