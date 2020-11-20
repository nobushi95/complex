#define MY_DEBUG
#include "complex.hpp"

using namespace std;

int main() {
    Complex i(0, 1);
    // i += 1;
    // cout << "i = " << i.str() << endl;
    
    Complex a = 1 + 2 * i;
    Complex b = 3 + 4 * i;
    Complex c = a + b;
    Complex d = a * b;
    Complex e = a - 1;
    Complex f = a - 2 * i;

    cout << "a = " << a.str() << endl;
    cout << "b = " << b.str() << endl;
    cout << "c = " << c.str() << endl;
    cout << "d = " << d.str() << endl;
    cout << "e = " << e.str() << endl;
    cout << "f = " << f.str() << endl;
}