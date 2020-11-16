#include <iostream>
#include <string>

// #define MY_DEBUG

using namespace std;

class Complex {
private:
    int _real, _imag;

public:
    Complex(int real, int imag) : _real(real), _imag(imag) {
        #ifdef MY_DEBUG
        cout << to_string(_real) + " + " + to_string(_imag) + "i" << endl;
        #endif
    }

    // 二項演算子で整数のみでコンストラクタが走るようにするため
    Complex(int real) : _real(real), _imag(0) {
        #ifdef MY_DEBUG
        cout << to_string(_real) + " + " + to_string(_imag) + "i" << endl;
        #endif
    }

    // コピーコンストラクタ
    Complex(const Complex &c) {
        *this = c;
    }

    // デストラクタは、メモリ領域を確保した場合に明示的に書く
    // デストラクタを記述しなければ、デフォルトデストラクタをコンパイラが生成する
    // 何もしないデストラクタを記述すると（？）、違反命令発行で落ちる
    // -> デフォルトデストラクタがかぶって悪さする？
    // ~Complex() {
    //     #ifdef MY_DEBUG
    //     cout << to_string(_real) + " + " + to_string(_imag) + "i" << endl;
    //     #endif
    // }

    Complex &operator=(const Complex &c) {
        _real = c._real;
        _imag = c._imag;
        return *this;
    }

    Complex &operator+=(const Complex &c) {
        _real += c._real;
        _imag += c._imag;
        return *this;
    }

    // 引数が実数（整数）の場合はコンストラクタが走らなくなる
    // Complex(int real) を定義しているのに、必要なのか？
    Complex &operator+=(const int real) {
        _real += real;
        return *this;
    }

    Complex &operator-=(const Complex &c) {
        _real -= c._real;
        _imag -= c._imag;
        return *this;
    }

    Complex &operator*=(const Complex &c) {
        Complex tmp = *this;
        _real = tmp._real * c._real - tmp._imag * c._imag;
        _imag = tmp._real * c._imag + tmp._imag * c._real;
        return *this;
    }

public:
    int real() const { return _real; }
    int imag() const { return _imag; }
    string str() const { return to_string(_real) + " + " + to_string(_imag) + "i"; }

};

// 二項演算子で、Complex(int real)があるので、どちらかが整数でもコンストラクタが走る

Complex operator+(const Complex &c1, const Complex &c2) {
    Complex ret = c1;
    ret += c2;
    return ret;
}

Complex operator-(const Complex &c1, const Complex &c2) {
    Complex ret = c1;
    ret -= c2;
    return ret;
}

Complex operator*(const Complex &c1, const Complex &c2) {
    Complex ret = c1;
    ret *= c2;
    return ret;
}