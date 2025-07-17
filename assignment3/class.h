#ifndef CLASS_H
#define CLASS_H

#include <iostream>
#include <utility>

class Fraction {
private:
    int num;
    int denum;
    int lcm(const Fraction&) const;

    friend Fraction operator+(const Fraction&, const Fraction&);
    friend std::ostream& operator<<(std::ostream&, const Fraction&);

    public:
    Fraction();
    Fraction(const int, const int);
    ~Fraction();
    int getNum() const;
    int getDenum() const;
    std::pair<int, int> getFrac() const;
    
    void setNum(const int);
    void setDenum(const int);
    void setFrac(const int, const int);
};

#endif