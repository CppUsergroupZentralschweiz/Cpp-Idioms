#ifndef PIMPL_H
#define PIMPL_H

#include <string>
#include <vector>

class foo
{
public:
  foo();
  void print();

private:
    void initialize();
    void print_member3();
		std::string member1;
    std::string member2;
    std::vector<int> member3;
};

#endif
