#include "pimpl.h"
#include <iostream>

#include <string>
#include <vector>

class foo::impl
{
public:
  void initialize()
  {
    member1 = "Hello";
    member2 = "World";
    member3 = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
  }

  void print()
  {
    print_member3();
    std::cout << member1 << member2 << std::endl;
  }

  void print_member3()
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

private:
  std::string member1;
  std::string member2;
  std::vector<int> member3;
};

foo::foo()
  : pimpl(std::make_unique<impl>())
{
  pimpl->initialize();
}

foo::~foo() = default;
foo::foo(const foo& rhs)
  : pimpl(std::make_unique<impl>(*rhs.pimpl))
{
}

foo& foo::operator=(const foo& rhs)
{
  *pimpl = *rhs.pimpl;
  return *this;
}

foo::foo(foo&&) = default;
foo& foo::operator=(foo&&) = default;

void foo::print()
{
  pimpl->print();
}
