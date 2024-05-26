//
// 209294768 sagitmalka10@gmail.com
//

#pragma once
#include <ostream>
#include <vector>
#include <list>

using std::vector;
using std::ostream;

namespace ariel{
    class Graph {
    private:
        vector<vector<int>> m_matrix;
        [[nodiscard]] static int countEdges(const vector<vector<int>>& matrix) ;
        /** returns -1 if first < second, 1 if first > second, 0 if equal **/
        [[nodiscard]] int compareMatrixSize(const Graph& other) const;
    
    public:

        void loadGraph(const vector<vector<int>>& matrix);
        void printGraph();
        [[nodiscard]] const vector<vector<int>>& getAdjMatrix() const;

        /**
         * operator overloading
         * **/
        Graph& operator++();
        Graph operator++(int);
        Graph operator+(int value) const;
        Graph& operator+=(int value);
        Graph operator+(const Graph& other) const;
        Graph& operator+=(const Graph& other);

        Graph& operator--();
        Graph operator--(int);
        Graph operator-(int value) const;
        Graph& operator-=(int value);
        Graph operator-(const Graph& other) const;
        Graph& operator-=(const Graph& other);

        bool operator==(const Graph& other) const;
        bool operator>(const Graph& other) const;
        bool operator<(const Graph& other) const;
        bool operator>=(const Graph& other) const;
        bool operator<=(const Graph& other) const;
        bool operator!=(const Graph& other) const;

        Graph& operator*=(int scalar);
        Graph operator*(const Graph& other) const;
        Graph& operator+();
        Graph& operator-();
        friend ostream& operator<<(ostream& os, const Graph& graph);
    };
}




