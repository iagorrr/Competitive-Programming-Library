#include<bits/stdc++.h>
#include <type_traits>

template<typename T>
bool equals(T a, T b){

  const double EPS {1e-9};
  if (std::is_floating_point<T>::value)
    return fabs(a - b) < EPS; 
  else 
    return a==b;
  
}
