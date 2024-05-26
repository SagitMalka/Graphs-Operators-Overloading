//
// 209294768 sagitmalka10@gmail.com
//
#include "doctest.h"
#include "Algorithms.hpp"
#include "Graph.hpp"
#include <iostream>
#include <sstream>
using namespace std;

#include "Graph.hpp"
#include "doctest.h"
#include <vector>

using namespace ariel;
using namespace std;


TEST_CASE("Test operator++ (prefix)") {
    Graph g1, g2;
    vector<vector<int>> graph1 = {
        {0, 1, 2},
        {1, 0, 3},
        {2, 3, 0}
    };
    g1.loadGraph(graph1);
    ++g1;

    vector<vector<int>> graph2 = {
        {1, 2, 3},
        {2, 1, 4},
        {3, 4, 1}
    };
    g2.loadGraph(graph2);
    
    CHECK(g2.getAdjMatrix() == g1.getAdjMatrix());
}
TEST_CASE("Test operator++ (suffix)") {
    Graph g1, g2;
    vector<vector<int>> graph1 = {
        {0, 1, 2},
        {1, 0, 3},
        {2, 3, 0}
    };
    g1.loadGraph(graph1);
    g1++;

    vector<vector<int>> graph2 = {
        {1, 2, 3},
        {2, 1, 4},
        {3, 4, 1}
    };
    g2.loadGraph(graph2);
    
    CHECK(g2.getAdjMatrix() == g1.getAdjMatrix());
}

TEST_CASE("Test operator+= with non-empty graph") {
    Graph g1, g2;
    vector<vector<int>> graph1 = {
        {0, 1, 2},
        {1, 0, 3},
        {2, 3, 0}
    };
    g1.loadGraph(graph1);

    int value = 1;
    g1 += value;

    vector<vector<int>> graph2 = {
        {1, 2, 3,},
        {2, 1, 4},
        {3, 4, 1}
    };
    g2.loadGraph(graph2);
    
    CHECK(g2.getAdjMatrix() == g1.getAdjMatrix());
}


TEST_CASE("Test operator+= with single node graph") {
    Graph g1, g2;
    vector<vector<int>> graph1 = {
        {0}
    };
    g1.loadGraph(graph1);

    g1 += 3;
    vector<vector<int>> graph2 = {
        {3}
    };
    g2.loadGraph(graph2);
    CHECK(g1.getAdjMatrix() == g2.getAdjMatrix());
}


TEST_CASE("Test operator+") {
    Graph g1, g2;
    vector<vector<int>> graph1 = {
        {0, 1, 2},
        {1, 0, 3},
        {2, 3, 0}
    };
    vector<vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}
    };
    g1.loadGraph(graph1);
    g2.loadGraph(graph2);

    Graph result = g1 + g2;
    vector<vector<int>> expected = {
        {0, 2, 3},
        {2, 0, 4},
        {3, 4, 0}
    };
    CHECK(result.getAdjMatrix() == expected);
}

TEST_CASE("Test operator+ with different sized graphs") {
    Graph g1, g2;
    vector<vector<int>> graph1 = {
        {0, 1},
        {1, 0}
    };
    vector<vector<int>> graph2 = {
        {0, 1, 2},
        {1, 0, 3},
        {2, 3, 0}
    };
    g1.loadGraph(graph1);
    g2.loadGraph(graph2);

    CHECK_THROWS_AS(g1 + g2, std::invalid_argument); // Expect an exception due to different sizes
}

TEST_CASE("Test operator+= with identical graphs") {
    Graph g1, g2;
    vector<vector<int>> graph = {
        {0, 1, 2},
        {1, 0, 3},
        {2, 3, 0}
    };
    g1.loadGraph(graph);
    g2.loadGraph(graph);

    g1 += g2;
    vector<vector<int>> expected = {
        {0, 2, 4},
        {2, 0, 6},
        {4, 6, 0}
    };
    CHECK(g1.getAdjMatrix() == expected);
}

TEST_CASE("Test operator+= with different graphs") {
    Graph g1, g2;
    vector<vector<int>> graph1 = {
        {0, 3, 4},
        {3, 0, 5},
        {4, 5, 0}
    };
    vector<vector<int>> graph2 = {
        {0, 1, 2},
        {1, 0, 3},
        {2, 3, 0}
    };
    g1.loadGraph(graph1);
    g2.loadGraph(graph2);

    g1 += g2;
    vector<vector<int>> expected = {
        {0, 4, 6},
        {4, 0, 8},
        {6, 8, 0}
    };
    CHECK(g1.getAdjMatrix() == expected);
}

TEST_CASE("Test operator+= with graph having different sizes") {
    Graph g1, g2;
    vector<vector<int>> graph1 = {
        {0, 1},
        {1, 0}
    };
    vector<vector<int>> graph2 = {
        {0, 1, 2},
        {1, 0, 3},
        {2, 3, 0}
    };
    g1.loadGraph(graph1);
    g2.loadGraph(graph2);

    CHECK_THROWS_AS(g1 += g2, std::invalid_argument);
}

TEST_CASE("Test operator+= with one empty graph and one non-empty graph") {
    Graph g1, g2;
    vector<vector<int>> graph = {
        {0, 1, 2},
        {1, 0, 3},
        {2, 3, 0}
    };
    g1.loadGraph(graph);

    CHECK_THROWS_AS(g1 += g2, std::invalid_argument);
}

TEST_CASE("Test operator+= with both graphs empty") {
    Graph g1, g2;

    CHECK_NOTHROW(g1 += g2);
    vector<vector<int>> expected = {};
    CHECK(g1.getAdjMatrix() == expected);
}
///////////////////////////////////////
TEST_CASE("Test operator-- (prefix)") {
    Graph g1, g2;
    vector<vector<int>> graph1 = {
        {0, 1, 2},
        {1, 0, 3},
        {2, 3, 0}
    };
    g1.loadGraph(graph1);
    --g1;

    vector<vector<int>> graph2 = {
        {-1, 0, 1,},
        {0, -1, 2},
        {1, 2, -1}
    };
    g2.loadGraph(graph2);
    
    CHECK(g2.getAdjMatrix() == g1.getAdjMatrix());
}
TEST_CASE("Test operator-- (suffix)") {
    Graph g1, g2;
    vector<vector<int>> graph1 = {
        {0, 1, 2},
        {1, 0, 3},
        {2, 3, 0}
    };
    g1.loadGraph(graph1);
    g1--;

    vector<vector<int>> graph2 = {
        {-1, 0, 1,},
        {0, -1, 2},
        {1, 2, -1}
    };
    g2.loadGraph(graph2);
    
    CHECK(g2.getAdjMatrix() == g1.getAdjMatrix());
}
TEST_CASE("Test operator- with non-empty graph") {
    Graph g1, g2;
    vector<vector<int>> graph1 = {
        {0, 1, 2},
        {1, 0, 3},
        {2, 3, 0}
    };
    g1.loadGraph(graph1);

    int value = 1;
    g1 = g1 - value;

    vector<vector<int>> graph2 = {
        {-1, 0, 1,},
        {0, -1, 2},
        {1, 2, -1}
    };
    g2.loadGraph(graph2);
    
    CHECK(g2.getAdjMatrix() == g1.getAdjMatrix());
}

TEST_CASE("Test operator-= with non-empty graph") {
    Graph g1, g2;
    vector<vector<int>> graph1 = {
        {0, 1, 2},
        {1, 0, 3},
        {2, 3, 0}
    };
    g1.loadGraph(graph1);

    int value = 1;
    g1 -= value;

    vector<vector<int>> graph2 = {
        {-1, 0, 1,},
        {0, -1, 2},
        {1, 2, -1}
    };
    g2.loadGraph(graph2);
    
    CHECK(g2.getAdjMatrix() == g1.getAdjMatrix());
}


TEST_CASE("Test operator-= with single node graph") {
    Graph g;
    vector<vector<int>> graph = {
        {0}
    };
    g.loadGraph(graph);

    Graph g_copy = g;
    int value = 3;
    g -= value;
    for (size_t i = 0; i < graph.size(); ++i) {
        for (size_t j = 0; j < graph[i].size(); ++j) {
            graph[i][j] -= value;
        }
    }
    CHECK(g.getAdjMatrix() == graph);
}


TEST_CASE("Test operator- with graph subtraction") {
    Graph g1, g2;
    vector<vector<int>> graph1 = {
        {0, 1, 2},
        {1, 0, 3},
        {2, 3, 0}
    };
    vector<vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}
    };
    g1.loadGraph(graph1);
    g2.loadGraph(graph2);

    Graph result = g1 - g2;
    vector<vector<int>> expected = {
        {0, 0, 1},
        {0, 0, 2},
        {1, 2, 0}
    };
    CHECK(result.getAdjMatrix() == expected); // Expect the subtracted graph
}

TEST_CASE("Test operator- with different sized graphs") {
    Graph g1, g2;
    vector<vector<int>> graph1 = {
        {0, 1},
        {1, 0}
    };
    vector<vector<int>> graph2 = {
        {0, 1, 2},
        {1, 0, 3},
        {2, 3, 0}
    };
    g1.loadGraph(graph1);
    g2.loadGraph(graph2);

    CHECK_THROWS_AS(g1 - g2, std::invalid_argument); // Expect an exception due to different sizes
}

TEST_CASE("Test operator-= with identical graphs") {
    Graph g1, g2;
    vector<vector<int>> graph = {
        {0, 1, 2},
        {1, 0, 3},
        {2, 3, 0}
    };
    g1.loadGraph(graph);
    g2.loadGraph(graph);

    g1 -= g2;
    vector<vector<int>> expected = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
    CHECK(g1.getAdjMatrix() == expected);
}

TEST_CASE("Test operator-= with different graphs") {
    Graph g1, g2;
    vector<vector<int>> graph1 = {
        {0, 3, 4},
        {3, 0, 5},
        {4, 5, 0}
    };
    vector<vector<int>> graph2 = {
        {0, 1, 2},
        {1, 0, 3},
        {2, 3, 0}
    };
    g1.loadGraph(graph1);
    g2.loadGraph(graph2);

    g1 -= g2;
    vector<vector<int>> expected = {
        {0, 2, 2},
        {2, 0, 2},
        {2, 2, 0}
    };
    CHECK(g1.getAdjMatrix() == expected);
}

TEST_CASE("Test operator-= with graph having different sizes") {
    Graph g1, g2;
    vector<vector<int>> graph1 = {
        {0, 1},
        {1, 0}
    };
    vector<vector<int>> graph2 = {
        {0, 1, 2},
        {1, 0, 3},
        {2, 3, 0}
    };
    g1.loadGraph(graph1);
    g2.loadGraph(graph2);

    CHECK_THROWS_AS(g1 -= g2, std::invalid_argument);
}

TEST_CASE("Test operator-= with one empty graph and one non-empty graph") {
    Graph g1, g2;
    vector<vector<int>> graph = {
        {0, 1, 2},
        {1, 0, 3},
        {2, 3, 0}
    };
    g1.loadGraph(graph);

    CHECK_THROWS_AS(g1 -= g2, std::invalid_argument);
}

TEST_CASE("Test operator-= with both graphs empty") {
    Graph g1, g2;

    CHECK_NOTHROW(g1 -= g2);
    vector<vector<int>> expected = {};
    CHECK(g1.getAdjMatrix() == expected);
}
TEST_CASE("Test operator> with graphs having different number of edges") {
    Graph g1, g2;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    vector<vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}
    };
    g1.loadGraph(graph1);
    g2.loadGraph(graph2);

    CHECK(g2 > g1); // g2 has more edges than g1
}

TEST_CASE("Test operator< with graphs having different number of edges") {
    Graph g1, g2;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    vector<vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}
    };
    g1.loadGraph(graph1);
    g2.loadGraph(graph2);

    CHECK(g1 < g2); // g1 has fewer edges than g2
}

TEST_CASE("Test operator>= with identical graphs") {
    Graph g1, g2;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g1.loadGraph(graph);
    g2.loadGraph(graph);

    CHECK(g1 >= g2); // g1 and g2 are identical
}

TEST_CASE("Test operator<= with identical graphs") {
    Graph g1, g2;
    vector<vector<int>> graph = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g1.loadGraph(graph);
    g2.loadGraph(graph);

    CHECK(g1 <= g2); // g1 and g2 are identical
}

TEST_CASE("Test operator>= with graphs having different number of edges") {
    Graph g1, g2;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    vector<vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}
    };
    g1.loadGraph(graph1);
    g2.loadGraph(graph2);

    CHECK(g2 >= g1); // g2 has more edges than g1
}

TEST_CASE("Test operator<= with graphs having different number of edges") {
    Graph g1, g2;
    vector<vector<int>> graph1 = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    vector<vector<int>> graph2 = {
        {0, 1, 1},
        {1, 0, 1},
        {1, 1, 0}
    };
    g1.loadGraph(graph1);
    g2.loadGraph(graph2);

    CHECK(g1 <= g2); // g1 has fewer edges than g2
}

TEST_CASE("Test operator== with identical graphs") {
    Graph g1, g2;
    vector<vector<int>> graph = {
        {0, 1, 2},
        {1, 0, 3},
        {2, 3, 0}
    };
    g1.loadGraph(graph);
    g2.loadGraph(graph);

    CHECK(g1 == g2); // Expect true since graphs are identical
}

TEST_CASE("Test operator== with different graphs") {
    Graph g1, g2;
    vector<vector<int>> graph1 = {
        {0, 1, 2},
        {1, 0, 3},
        {2, 3, 0}
    };
    vector<vector<int>> graph2 = {
        {0, 1, 2},
        {1, 0, 4}, // Different value here
        {2, 3, 0}
    };
    g1.loadGraph(graph1);
    g2.loadGraph(graph2);

    CHECK_FALSE(g1 == g2); // Expect false since graphs are different
}

TEST_CASE("Test operator== with different sized graphs") {
    Graph g1, g2;
    vector<vector<int>> graph1 = {
        {0, 1},
        {1, 0}
    };
    vector<vector<int>> graph2 = {
        {0, 1, 2},
        {1, 0, 3},
        {2, 3, 0}
    };
    g1.loadGraph(graph1);
    g2.loadGraph(graph2);

    CHECK_FALSE(g1 == g2); // Expect false since graphs have different sizes
}


TEST_CASE("Test operator== with both graphs empty") {
    Graph g1, g2;

    CHECK(g1 == g2); // Expect true since both graphs are empty
}
TEST_CASE("Test operator!= with identical graphs") {
    Graph g1, g2;
    vector<vector<int>> graph = {
        {0, 1, 2},
        {1, 0, 3},
        {2, 3, 0}
    };
    g1.loadGraph(graph);
    g2.loadGraph(graph);

    CHECK_FALSE(g1 != g2); // Expect false since graphs are identical
}

TEST_CASE("Test operator!= with different graphs") {
    Graph g1, g2;
    vector<vector<int>> graph1 = {
        {0, 1, 2},
        {1, 0, 3},
        {2, 3, 0}
    };
    vector<vector<int>> graph2 = {
        {0, 1, 2},
        {1, 0, 4}, // Different value here
        {2, 3, 0}
    };
    g1.loadGraph(graph1);
    g2.loadGraph(graph2);

    CHECK(g1 != g2); // Expect true since graphs are different
}

TEST_CASE("Test operator!= with different sized graphs") {
    Graph g1, g2;
    vector<vector<int>> graph1 = {
        {0, 1},
        {1, 0}
    };
    vector<vector<int>> graph2 = {
        {0, 1, 2},
        {1, 0, 3},
        {2, 3, 0}
    };
    g1.loadGraph(graph1);
    g2.loadGraph(graph2);

    CHECK(g1 != g2); // Expect true since graphs have different sizes
}


TEST_CASE("Test operator!= with both graphs empty") {
    Graph g1, g2;

    CHECK_FALSE(g1 != g2); // Expect false since both graphs are empty
}
TEST_CASE("Test operator* with valid non-empty graphs") {
    Graph g1;
    vector<vector<int>> graph1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    g1.loadGraph(graph1);

    Graph g2;
    vector<vector<int>> graph2 = {
        {9, 8, 7},
        {6, 5, 4},
        {3, 2, 1}
    };
    g2.loadGraph(graph2);

    Graph result = g1 * g2;

    vector<vector<int>> expected = {
        {30, 24, 18},
        {84, 69, 54},
        {138, 114, 90}
    };

    CHECK(result.getAdjMatrix() == expected);
}

TEST_CASE("Test operator* with zero matrices") {
    Graph g1;
    vector<vector<int>> graph1 = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
    g1.loadGraph(graph1);

    Graph g2;
    vector<vector<int>> graph2 = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
    g2.loadGraph(graph2);

    Graph result = g1 * g2;

    vector<vector<int>> expected = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };

    CHECK(result.getAdjMatrix() == expected);
}

TEST_CASE("Test operator* with identity matrix") {
    Graph g1;
    vector<vector<int>> graph1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    g1.loadGraph(graph1);

    Graph g2;
    vector<vector<int>> graph2 = {
        {1, 0, 0},
        {0, 1, 0},
        {0, 0, 1}
    };
    g2.loadGraph(graph2);

    Graph result = g1 * g2;

    vector<vector<int>> expected = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    CHECK(result.getAdjMatrix() == expected);
}

TEST_CASE("Test operator* with graphs having negative values") {
    Graph g1;
    vector<vector<int>> graph1 = {
        {1, -2, 3},
        {-4, 5, -6},
        {7, -8, 9}
    };
    g1.loadGraph(graph1);

    Graph g2;
    vector<vector<int>> graph2 = {
        {9, -8, 7},
        {-6, 5, -4},
        {3, -2, 1}
    };
    g2.loadGraph(graph2);

    Graph result = g1 * g2;

    vector<vector<int>> expected = {
        {30, -24, 18},
        {-84, 69, -54},
        {138, -114, 90}
    };

    CHECK(result.getAdjMatrix() == expected);
}

TEST_CASE("Test operator* with single node graphs") {
    Graph g1;
    vector<vector<int>> graph1 = {
        {5}
    };
    g1.loadGraph(graph1);

    Graph g2;
    vector<vector<int>> graph2 = {
        {3}
    };
    g2.loadGraph(graph2);

    Graph result = g1 * g2;

    vector<vector<int>> expected = {
        {15}
    };

    CHECK(result.getAdjMatrix() == expected);
}

TEST_CASE("Test operator* with graphs of different sizes") {
    Graph g1;
    vector<vector<int>> graph1 = {
        {1, 2},
        {3, 4}
    };
    g1.loadGraph(graph1);

    Graph g2;
    vector<vector<int>> graph2 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    CHECK_THROWS_AS(g1 * g2, std::invalid_argument);
}

TEST_CASE("Test operator+ with non-empty graph") {
    Graph g;
    vector<vector<int>> graph = {
        {0, 1, 2},
        {1, 0, 3},
        {2, 3, 0}
    };
    g.loadGraph(graph);

    Graph g_copy = g;
    +g;
    CHECK(g.getAdjMatrix() == g_copy.getAdjMatrix());
}

TEST_CASE("Test operator+ with graph having zeroes") {
    Graph g;
    vector<vector<int>> graph = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
    g.loadGraph(graph);

    Graph g_copy = g;
    +g;
    CHECK(g.getAdjMatrix() == g_copy.getAdjMatrix());
}

TEST_CASE("Test operator+ with graph having negative values") {
    Graph g;
    vector<vector<int>> graph = {
        {0, -1, 2},
        {-1, 0, -3},
        {2, -3, 0}
    };
    g.loadGraph(graph);

    Graph g_copy = g;
    +g;
    CHECK(g.getAdjMatrix() == g_copy.getAdjMatrix());
}

TEST_CASE("Test operator+ with single node graph") {
    Graph g;
    vector<vector<int>> graph = {
        {0}
    };
    g.loadGraph(graph);

    Graph g_copy = g;
    +g;
    CHECK(g.getAdjMatrix() == g_copy.getAdjMatrix());
}

TEST_CASE("Test operator+ with empty graph") {
    Graph g;
    vector<vector<int>> graph = {};

    Graph g_copy = g;
    +g;
    CHECK(g.getAdjMatrix() == g_copy.getAdjMatrix());
}
TEST_CASE("Test operator- with empty graph") {
    Graph g;
    vector<vector<int>> graph = {};
    CHECK_NOTHROW(g = -g);
    CHECK(g.getAdjMatrix().empty());
}

TEST_CASE("Test operator- with graph of all positive elements") {
    Graph g;
    vector<vector<int>> graph = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    g.loadGraph(graph);
    g = -g;
    vector<vector<int>> expected = {
        {-1, -2, -3},
        {-4, -5, -6},
        {-7, -8, -9}
    };
    CHECK(g.getAdjMatrix() == expected);
}

TEST_CASE("Test operator- with graph of all negative elements") {
    Graph g;
    vector<vector<int>> graph = {
        {-1, -2, -3},
        {-4, -5, -6},
        {-7, -8, -9}
    };
    g.loadGraph(graph);
    g = -g;
    vector<vector<int>> expected = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    CHECK(g.getAdjMatrix() == expected);
}

TEST_CASE("Test operator- with graph of mixed elements") {
    Graph g;
    vector<vector<int>> graph = {
        {1, -2, 3},
        {-4, 5, -6},
        {7, -8, 9}
    };
    g.loadGraph(graph);
    g = -g;
    vector<vector<int>> expected = {
        {-1, 2, -3},
        {4, -5, 6},
        {-7, 8, -9}
    };
    CHECK(g.getAdjMatrix() == expected);
}

TEST_CASE("Test operator- with graph of zeros") {
    Graph g;
    vector<vector<int>> graph = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
    g.loadGraph(graph);
    g = -g;
    vector<vector<int>> expected = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
    CHECK(g.getAdjMatrix() == expected);
}

TEST_CASE("Test operator<< with a simple graph") {
    Graph g;
    vector<vector<int>> graph = {
        {0, 0, 6},
        {3, 0, 0},
        {0, 2, 0}
    };
    g.loadGraph(graph);
    
    std::ostringstream oss;
    oss << g;
    std::string expected_output = "[0, 0, 6]\n[3, 0, 0]\n[0, 2, 0]\n";
    
    CHECK(oss.str() == expected_output);
}

TEST_CASE("Test operator<< with an empty graph") {
    Graph g;
    vector<vector<int>> graph = {};
    
    std::ostringstream oss;
    oss << g;
    std::string expected_output = "";
    
    CHECK(oss.str() == expected_output);
}

TEST_CASE("Test operator<< with a larger graph") {
    Graph g;
    vector<vector<int>> graph = {
        {0, 1, 2, 3},
        {4, 0, 5, 6},
        {7, 8, 0, 9},
        {10, 11, 12, 0}
    };
    g.loadGraph(graph);
    
    std::ostringstream oss;
    oss << g;
    std::string expected_output = "[0, 1, 2, 3]\n[4, 0, 5, 6]\n[7, 8, 0, 9]\n[10, 11, 12, 0]\n";
    
    CHECK(oss.str() == expected_output);
}

TEST_CASE("Test operator<< with a single element graph") {
    Graph g;
    vector<vector<int>> graph = {
        {42}
    };
    g.loadGraph(graph);
    
    std::ostringstream oss;
    oss << g;
    std::string expected_output = "[42]\n";
    
    CHECK(oss.str() == expected_output);
}

TEST_CASE("Test operator<< with a non-square graph (should throw)") {
    Graph g;
    vector<vector<int>> graph = {
        {1, 2, 3},
        {4, 5}
    };
    CHECK_THROWS_AS(g.loadGraph(graph), std::invalid_argument);
}
