#ifndef COMPLEX_NUMBER_H
#define COMPLEX_NUMBER_H

#include <iostream>
#include <tuple>

class complex {
public:
    complex( double r = 0, double i = 0 )
        : real{r}, imag{i}
    { }

    complex& operator+=( const complex& other ) {
        real += other.real;
        imag += other.imag;
        return *this;
    }

    complex& operator-=( const complex& other ) {
        real -= other.real;
        imag -= other.imag;
        return *this;
    }

    complex& operator++() {
        ++real;
        return *this;
    }

    complex& operator--() {
        --real;
        return *this;
    }

    // implement postincrement in terms of preincrement
    complex operator++( int ) {
        auto temp = *this;
        ++*this;
        return temp;
    }

    // implement postdecrement in terms of predecrement
    complex operator--( int ) {
        auto temp = *this;
        --*this;
        return temp;
    }

    std::ostream& print(std::ostream& os ) const {
        return os << "(" << real << ", " << imag << ")";
    }

    friend bool operator==(const complex& lhs, const complex& rhs) {
        return (!(lhs.real > rhs.real) &&
               !(lhs.real < rhs.real) &&
               !(lhs.imag > rhs.imag) &&
               !(lhs.imag < rhs.imag));
    }

    friend bool operator< (const complex& lhs, const complex& rhs) {
        // Use std::tie to introduce lexicographical comparison of a struct or class
        return std::tie(lhs.real, lhs.imag) < std::tie(rhs.real, rhs.imag);
    }

private:
    double real, imag;
};

// operator+ is written in terms of operator+=
// operator+ should not be a member function.
complex operator+( complex lhs, const complex& rhs ) {
    lhs += rhs;
    return lhs;
}

// operator- is written in terms of operator-=
// operator- should not be a member function.
complex operator-( complex lhs, const complex& rhs ) {
    lhs -= rhs;
    return lhs;
}

// operator<< should not be a member function.
std::ostream& operator<<(std::ostream& os, const complex& c ) {
    return c.print(os);
}

// operator>> should not be a member function.
std::istream& operator>>(std::istream& is, complex& c) {
  double real{};
  double imag{};
  is >> real;
  char op;
  is.get(op);
  while(op == ' ' || op == '\n' || op == '\t'){
    is.get(op);
  }
  if (op == ',')
  {
    while(op == ' ' || op == '\n' || op == '\t'){
      is.get(op);
    }
    int mult;
    switch(op){
      case '+':
         mult = 1;
         break;
      case '-':
         mult = -1;
         break;
      default :
         is.setstate(std::ios::failbit);
         return is;
    };
    is >> imag;
    imag *= mult;
    c = complex{real, imag};
  } else {
    is.setstate(std::ios::failbit);
  }
  return is;
}

// implement operator!= in terms of operator== or
// include <utility> which by default implements operator!= in terms of operator==
bool operator!=(const complex& lhs, const complex& rhs) {
    return !(lhs == rhs);
}

//  implement the other relational operators in terms of operator<  or
// include <utility> which by default implements the other relational operators in terms of operator<
bool operator> (const complex& lhs, const complex& rhs){ return rhs < lhs; }
bool operator<=(const complex& lhs, const complex& rhs){ return !(lhs > rhs); }
bool operator>=(const complex& lhs, const complex& rhs){ return !(lhs < rhs); }

#endif
