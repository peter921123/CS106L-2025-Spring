#include "class.h"
#include <algorithm>
#include <numeric>

Fraction::Fraction(){
    num = 0;
    denum = 0;
}

Fraction::Fraction(const int num, const int denum) {
    this->num = num;
    this->denum = denum;
}

Fraction::~Fraction() {}

int Fraction::getNum() const {
    return num;
}

int Fraction::getDenum() const {
    return denum;
}

std::pair<int, int> Fraction::getFrac() const {
    return std::make_pair(num, denum);
}

void Fraction::setNum(const int num) {
    this->num = num;
}
void Fraction::setDenum(const int denum) {
    this->denum = denum;
}

void Fraction::setFrac(const int num, const int denum) {
    setNum(num);
    setDenum(denum);
}

int Fraction::lcm(const Fraction& frac) const {
    return std::lcm(this->denum, frac.denum);
}

Fraction operator+(const Fraction& frac1, const Fraction& frac2) {
    int newDenum = frac1.lcm(frac2);
    int newNum = (newDenum / frac1.denum) * frac1.num + (newDenum / frac2.denum) * frac2.num;
    Fraction result(newNum, newDenum);
    return result;
}

std::ostream& operator<<(std::ostream& os, const Fraction& frac) {
    os << frac.num << "/" << frac.denum;
    return os;
}