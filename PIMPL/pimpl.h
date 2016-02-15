#ifndef PIMPL_H
#define PIMPL_H

#include <memory>

class foo
{
public:
  foo();
  void print();
  ~foo();
  foo(const foo&);
  foo& operator=(const foo&);
  foo(foo&&);
  foo& operator=(foo&&);

private:
    class impl;
    std::unique_ptr<impl> pimpl;
};

#endif
