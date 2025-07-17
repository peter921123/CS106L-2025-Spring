/*
 * CS106L Assignment 3: Make a Class
 * Created by Fabio Ibanez with modifications by Jacob Roberts-Baca.
 */
#include "class.h"

void sandbox() {
  Fraction frac1(2, 5);
  Fraction frac2(3, 4);
  std::cout << frac1 << " , " << frac2 << std::endl;
  
  Fraction frac3 = frac1 + frac2;
  std::cout << frac3 << std::endl;

  frac3.setNum(5);
  frac3.setDenum(9);
  std::cout << frac3 << std::endl;

  frac3.setFrac(9, 17);
  std::cout << frac3 << std::endl;
}