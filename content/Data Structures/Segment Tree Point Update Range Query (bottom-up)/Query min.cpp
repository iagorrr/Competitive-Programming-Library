#pragma once
#include "../../Contest/template.cpp"
#include "./Struct.cpp"

template <typename T>
using SegTreeBottomUpMinQuery =
    SegTreeBottomUp<T, numeric_limits<T>::max(),
                    [](T a, T b) { return min(a, b); }>;
