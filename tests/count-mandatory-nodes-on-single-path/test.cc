#include <gtest/gtest.h>

#include "../../content/Contest/template.cpp"
#include "../../content/Graphs/Block-Cut tree.cpp"
#include "../../content/Graphs/Count mandatory nodes on a single path.cpp"

TEST(CountMandatoryNodesOnPathTest, SimpleChain) {
    // Graph: 0 - 1 - 2 - 3
    vi2d g(4);
    g[0].pb(1);
    g[1].pb(0);
    g[1].pb(2);
    g[2].pb(1);
    g[2].pb(3);
    g[3].pb(2);

    BlockCutTree bct(g);

    EXPECT_EQ(bct.countMandatoryNodesOnPath(0, 3), 4);
    EXPECT_EQ(bct.countMandatoryNodesOnPath(1, 2), 2);
}

TEST(CountMandatoryNodesOnPathTest, CycleGraph) {
    // Graph: 0 - 1 - 2 - 0 (cycle)
    //
    vi2d g(3);
    g[0].pb(1), g[1].eb(0);
    g[1].pb(2), g[2].eb(1);
    g[2].pb(0), g[0].eb(2);

    BlockCutTree bct(g);

    EXPECT_EQ(bct.countMandatoryNodesOnPath(0, 2), 2);
}

TEST(CountMandatoryNodesOnPathTest, StarGraph) {
    // Graph:    0
    //         / | \
    //        1  2  3
    vi2d g(4);
    g[0].pb(1), g[1].pb(0);
    g[0].pb(2), g[2].pb(0);
    g[0].pb(3), g[3].pb(0);

    BlockCutTree bct(g);

    EXPECT_EQ(bct.countMandatoryNodesOnPath(1, 2), 3);  // 1 - 0 - 2
    EXPECT_EQ(bct.countMandatoryNodesOnPath(1, 3), 3);  // 1 - 0 - 3
    EXPECT_EQ(bct.countMandatoryNodesOnPath(0, 1), 2);  // 0 - 1
}

TEST(CountMandatoryNodesOnPathTest, ComplexGraph) {
    // Graph: 0 - 1 - 2 - 3
    //                 |
    //                 4
    vi2d g(5);
    g[0].pb(1), g[1].pb(0);
    g[1].pb(2), g[2].pb(1);
    g[2].pb(3), g[3].pb(2);
    g[2].pb(4), g[4].pb(2);

    BlockCutTree bct(g);

    EXPECT_EQ(bct.countMandatoryNodesOnPath(0, 3), 4);  // Path: 0-1-2-3
    EXPECT_EQ(bct.countMandatoryNodesOnPath(3, 4), 3);  // Path: 3-2-4
    EXPECT_EQ(bct.countMandatoryNodesOnPath(1, 4), 3);  // Path: 1-2-4
}
