#include <iostream>
#include <list>
#include <vector>

using namespace std;

int main() {
    vector<int> v= { 1,2,3,4,5 };
    for (auto _ : v) {
        cout << _ << " ";
    }
    cout << endl;
    return 0;
}