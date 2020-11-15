#include <string>

using namespace std;

class Complex {
private:
    int _img, _real;

public:
    int img() { return _img; }
    int real() { return _real; }
    string str() { return to_string(_real) + " + " + to_string(_img) + "i"; }

};

Complex operator+(const Complex &c1, const Complex &c2) {

}