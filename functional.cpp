// https://chryswoods.com/parallel_c++/functions.html
/// Part 1.2 Functions as Arguments
#include <iostream>



int sum(int x, int y)
{
    return x + y;
}

int diff(int x, int y)
{
    return x - y;
}

// template<class FUNC, class ARG1, class ARG2>
// int call_function(FUNC func, ARG1 arg1, ARG2 arg2)
int call_function(int (*func)(int, int), int arg1, int arg2)
{
    int result = func(arg1, arg2);
    return result;
}

int main(int argc, char **argv)
{
    
    int result = call_function( diff, 9, 2 );
    std::cout << result << std::endl;
    return 0;
}