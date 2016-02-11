#ifndef SORT_H
#define SORT_H

#include <string>
#include <type_traits>

template<class T,
	       typename = std::enable_if_t<std::is_integral<T>::value>>
T get_PI()
{
  return T{3};
}

template<class T,
         typename std::enable_if<std::is_floating_point<T>::value>::type* = nullptr>
T get_PI()
{
  return T{3.1415926536};
}

template<class T>
std::string get_PI(typename std::enable_if<!std::is_arithmetic<T>::value>::type* = 0)
{
  return "PI";
}

#endif
