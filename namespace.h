#pragma once
#include <string>

// Concepts
// A qualified name is a name that appears on the rhs of the scope resolution operator `::`, 
// i.e. a member of a class, namespace or enum.
// Argument-dependent lookup (ADL) is the set of rules using to lookup unqualified names.
// When performing name lookups, a non-ADL is usually tried first because it's often preferable.

namespace nick {
    std::string first_name = "Nick";
    std::string last_name = "Pratt";
    unsigned int age = 27;
    
    namespace edu {
        std::string level = "senior";
        std::string degree = "Computer Science";
        
    }
}

namespace nick::edu {
    double gpa = 3.5;
}

enum fruit {
    orange,
    apple,
    banana,
    peach
};