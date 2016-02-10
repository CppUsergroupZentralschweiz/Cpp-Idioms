#ifndef SORT_H
#define SORT_H

#include <algorithm>

template<typename Container>
void sort_ascending(Container& container)
{
  using std::begin;
  using std::end;
  std::sort(std::begin(container), std::end(container));
}

template<typename Container>
void sort_descending(Container& container)
{
  using std::begin;
  using std::end;
  std::sort(std::begin(container), std::end(container), std::greater<typename Container::value_type>());
}

#endif
