#include "pimpl.h"
#include <iostream>

foo::foo()
{
  initialize();
}

void foo::print()
{
  print_member3();
  std::cout << member1 << member2 << std::endl;
}

void foo::initialize()
{
  member1 = "Hello";
  member2 = "World";
  member3 = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
}
void foo::print_member3()
{
  auto it = std::begin(member3);
  do {
    std::cout << (*it);
    if(++it != std::end(member3))
    {
      std::cout << ", ";
    }
  } while (it != std::end(member3));
  std::cout << "..." << std::endl;
}
