#include <iostream>

using namespace std;

int main()
{
    int x = 99;
    int *p; // pointer to int

    p = &x; // menunjuk alamat x

    cout << *p; //output berupa value dari variabel yang ditunjuk p (x)
    return 0;
}
