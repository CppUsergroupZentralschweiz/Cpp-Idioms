#ifndef IDIOM_H
#define IDIOM_H

#include <algorithm>

template<class Container>
void shrink_to_fit(Container& container)
{
  container.shrink_to_fit();
}

#endif
