#include <iostream>

using namespace std;

int main() {
    int val = 69;
    int *ptr = &val;
    int **ptr2ptr = &ptr;

    cout << ptr << " --> " << *ptr <<endl;
    cout << ptr2ptr << " --> " << **ptr2ptr << endl;
}