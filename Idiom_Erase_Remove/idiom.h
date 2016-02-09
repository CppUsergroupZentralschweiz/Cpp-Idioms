#ifndef IDIOM_H
#define IDIOM_H

#include <algorithm>

template<typename T, class Container>
void remove_multiples_of(T multiple_of, Container& container)
{
  using std::begin;
  using std::end;

  container.erase(std::remove_if(begin(container),
                                 end(container),
                                 [&multiple_of](typename Container::value_type const& elem)
                                 {
                                   return elem % multiple_of == 0;
                                 }),
                  end(container));
}

#endif
