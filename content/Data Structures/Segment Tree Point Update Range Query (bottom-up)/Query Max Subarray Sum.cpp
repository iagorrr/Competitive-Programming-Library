#pragma once
#include "../../Contest/template.cpp"
#include "./Struct.cpp"

const ll _oo = 1e9;

struct Node {
    ll tot, suf, pref, best;
    // Neutral element
    Node() : tot(-_oo), suf(-_oo), pref(-_oo), best(-_oo) {}  // Neutral element
    // for assign
    Node(ll x) { tot = x, suf = x, pref = x, best = max(0ll, x); }
};

Node combine(Node &nl, Node &nr) {
    if (nl.tot == -_oo) return nr;
    if (nr.tot == -_oo) return nl;
    Node m;
    m.tot = nl.tot + nr.tot;
    m.pref = max({nl.pref, nl.tot + nr.pref});
    m.suf = max({nr.suf, nr.tot + nl.suf});
    m.best = max({nl.best, nr.best, nl.suf + nr.pref});
    return m;
}

using SegTreeMaxSubarraySum = SegTreeBottomUp<Node, Node(), combine>;
