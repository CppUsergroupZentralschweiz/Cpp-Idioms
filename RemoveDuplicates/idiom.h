#ifndef IDIOM_H
#define IDIOM_H

#include <algorithm>

template<class Container>
void sort_and_remove_duplicates(Container& container)
{
  using std::begin;
  using std::end;
  std::sort(begin(container), end(container));
  container.erase(std::unique(begin(container), end(container)), end(container));
}

#endif
