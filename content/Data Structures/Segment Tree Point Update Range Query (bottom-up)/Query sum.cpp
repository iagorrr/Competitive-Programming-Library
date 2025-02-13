#pragma once
#include "../../Contest/template.cpp"
#include "./Struct.cpp"

template <typename T>
using SegTreeBottomUpSumQuery =
    SegTreeBottomUp<T, T(0), [](T a, T b) { return a + b; }>;
