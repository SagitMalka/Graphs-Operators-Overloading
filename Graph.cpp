//
// 209294768 sagitmalka10@gmail.com
//

#include "Graph.hpp"
#include <iostream>
#include <stdexcept>

using std::cout;
using std::vector;
using std::endl;
using std::invalid_argument;
using std::ostream;

namespace ariel {
    void ariel::Graph::loadGraph(const vector<vector<int>> &matrix) {
        if (matrix.empty()) {
            throw std::invalid_argument("Invalid graph: The graph is empty.");
        }
        size_t rows = matrix.size();
        for (const auto &row: matrix) {
            if (row.size() != rows) {
                throw std::invalid_argument("Invalid graph: The graph is not a square matrix.");
            }
        }
        this->m_matrix = matrix;
    }

    void Graph::printGraph() {
        size_t vertices = this->m_matrix.size();
        size_t edges = 0;
        for (auto &i: this->m_matrix) {
            for (size_t j = 0; j < this->m_matrix.size(); j++) {
                if (i[j] != 0) {
                    edges++;
                }
            }
        }
        cout << "Graph with " << vertices << " vertices and " << edges << " edges." << endl;

    }

    const vector<vector<int>> &Graph::getAdjMatrix() const {
        return m_matrix;
    }

    Graph &Graph::operator++() {
        for (auto &row: m_matrix) {
            for (auto &val: row) {
                ++val;
            }
        }
        return *this;
    }

    Graph Graph::operator++(int) {
        Graph temp = *this;
        ++(*this);
        return temp;
    }

    Graph Graph::operator+(int value) const {
        Graph result = *this;
        for (auto &row: result.m_matrix) {
            for (auto &val: row) {
                val += value;
            }
        }
        return result;
    }

    Graph &Graph::operator+=(int value) {
        for (auto &row: m_matrix) {
            for (auto &val: row) {
                val += value;
            }
        }
        return *this;
    }

    Graph Graph::operator+(const Graph &other) const {
        // Check row size
        if (m_matrix.size() != other.m_matrix.size()) {
            throw invalid_argument("Graphs must have the same dimensions to be added.");
        }

        Graph result = *this;
        // Check column size
        for (size_t i = 0; i < m_matrix.size(); ++i) {
            if (m_matrix[i].size() != other.m_matrix[i].size()) {
                throw invalid_argument("Graphs must have the same dimensions to be added.");
            }
            // actual adding
            for (size_t j = 0; j < m_matrix[i].size(); ++j) {
                result.m_matrix[i][j] += other.m_matrix[i][j];
            }
        }
        return result;
    }

    Graph &Graph::operator+=(const Graph &other) {
        if (m_matrix.size() != other.m_matrix.size()) {
            throw invalid_argument("Graphs must have the same dimensions to be added.");
        }
        for (size_t i = 0; i < m_matrix.size(); ++i) {
            for (size_t j = 0; j < m_matrix[i].size(); ++j) {
                m_matrix[i][j] += other.m_matrix[i][j];
            }
        }
        return *this;
    }

    Graph &Graph::operator--() {
        for (auto &row: m_matrix) {
            for (auto &value: row) {
                --value;
            }
        }
        return *this;
    }

    Graph Graph::operator--(int) {
        Graph temp = *this;
        --(*this);
        return temp;
    }

    Graph Graph::operator-(int value) const {
        Graph result = *this;
        for (auto &row: result.m_matrix) {
            for (auto &val: row) {
                val -= value;
            }
        }
        return result;
    }

    Graph &Graph::operator-=(int value) {
        for (auto &row: m_matrix) {
            for (auto &val: row) {
                val -= value;
            }
        }
        return *this;
    }

    Graph Graph::operator-(const Graph &other) const {
        // Check row size
        if (m_matrix.size() != other.m_matrix.size()) {
            throw invalid_argument("Graphs must have the same dimensions to be added.");
        }

        Graph result = *this;
        // Check column size
        for (size_t i = 0; i < m_matrix.size(); ++i) {
            if (m_matrix[i].size() != other.m_matrix[i].size()) {
                throw invalid_argument("Graphs must have the same dimensions to be added.");
            }
            // actual adding
            for (size_t j = 0; j < m_matrix[i].size(); ++j) {
                result.m_matrix[i][j] -= other.m_matrix[i][j];
            }
        }
        return result;
    }

    Graph &Graph::operator-=(const Graph &other) {
        if (m_matrix.size() != other.m_matrix.size()) {
            throw invalid_argument("Graphs must have the same dimensions to be added.");
        }
        for (size_t i = 0; i < m_matrix.size(); ++i) {
            for (size_t j = 0; j < m_matrix[i].size(); ++j) {
                m_matrix[i][j] -= other.m_matrix[i][j];
            }
        }
        return *this;
    }

    bool Graph::operator==(const Graph &other) const {
        if (m_matrix.size() != other.m_matrix.size()) {
        }
        for (size_t i = 0; i < m_matrix.size(); ++i) {
            if (m_matrix[i].size() != other.m_matrix[i].size()) {
                return false;
            }
            for (size_t j = 0; j < m_matrix[i].size(); ++j) {
                if (m_matrix[i][j] != other.m_matrix[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }

    bool Graph::operator>(const Graph &other) const {
        int comp_s = this->compareMatrixSize(other);
        if (comp_s == -1) {
            std::cout << "198" << std::endl;
            return false;
        } else if (comp_s == 1) {
            for (size_t i = 0; i < m_matrix.size(); ++i) {
                for (size_t j = 0; j < m_matrix[0].size(); ++j) {
                    if ((other.m_matrix[i][j] != 0) && (other.m_matrix[i][j] != m_matrix[i][j])) {
                        std::cout << "204" << std::endl;
                        return false;
                    }
                }
            }
        } else {
            int edges_g1 = countEdges(m_matrix);
            int edges_g2 = countEdges(other.m_matrix);
            std::cout << "212" << std::endl;
            return edges_g1 > edges_g2;
        }
        std::cout << "215" << std::endl;
        return false;
    }

    int Graph::countEdges(const vector<vector<int>> &matrix) {
        int edges = 0;
        for (size_t i = 0; i < matrix.size(); ++i) {
            for (size_t j = 0; j < matrix[0].size(); ++j) {
                if (matrix[i][j] != 0) {
                    edges++;
                }
            }
        }
        return edges;
    }

    int Graph::compareMatrixSize(const Graph &other) const {
        if (m_matrix.size() < other.m_matrix.size()) {
            return -1;
        } else if (m_matrix.size() > other.m_matrix.size()) {
            return 1;
        } else {
            return 0;
        }
    }

    bool Graph::findCommonElement(const Graph &other) const {
        bool contains = false;
        for (size_t i = 0; i < other.m_matrix.size(); ++i) {
            for (size_t j = 0; j < other.m_matrix.size(); ++j) {
                if (m_matrix[i][j] != 0) {
                    if (m_matrix[i][j] == other.m_matrix[i][j]) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

    Graph &Graph::operator*=(int scalar) {
        for (auto &row: m_matrix) {
            for (auto &val: row) {
                val *= scalar;
            }
        }
        return *this;
    }


    ostream &operator<<(ostream &os, const Graph &graph) {
        for (size_t i = 0; i < graph.m_matrix.size(); i++) {
            for (size_t j = 0; j < graph.m_matrix.size(); j++) {
                if (j == 0) {
                    os << "[" << graph.m_matrix[i][j];
                } else if (j == graph.m_matrix.size() - 1) {
                    os << ", " << graph.m_matrix[i][j] << "]";
                } else {
                    os << ", " << graph.m_matrix[i][j];
                }
            }
            os << endl;
        }
        return os;
    }

    Graph &Graph::operator+() {
        return *this;
    }

    Graph &Graph::operator-() {
        return this->operator*=(-1);
    }

    Graph Graph::operator*(const Graph &other) const {
        if (this->compareMatrixSize(other) != 0) {
            throw invalid_argument("Graphs must have the same matrix dimensions to be multiply");
        }
        size_t size = m_matrix.size();
        Graph res_graph;
        res_graph.m_matrix.resize(size, vector<int>(size, 0));
        for (size_t i = 0; i < this->m_matrix.size(); ++i) {
            for (size_t j = 0; j < this->m_matrix.size(); ++j) {
                for (size_t k = 0; k < this->m_matrix.size(); ++k) {
                    res_graph.m_matrix[i][j] += this->m_matrix[i][k] * other.m_matrix[k][j];
                }
            }
        }
        return res_graph;
    }

    bool Graph::operator>=(const Graph &other) const {
        int edges_g1 = countEdges(m_matrix);
        int edges_g2 = countEdges(other.m_matrix);
        if (edges_g1 >= edges_g2) {
            return true;
        }

        return false;
    }

    bool Graph::operator<=(const Graph &other) const {
        int edges_g1 = countEdges(m_matrix);
        int edges_g2 = countEdges(other.m_matrix);
        if (edges_g1 <= edges_g2) {
            return true;
        }

        return false;
    }

    bool Graph::operator<(const Graph &other) const {

        int edges_g1 = countEdges(m_matrix);
        int edges_g2 = countEdges(other.m_matrix);
        std::cout << "343" << std::endl;
        return edges_g1 < edges_g2;

    }

    bool Graph::operator!=(const Graph &other) const {
        if(this->operator==(other)){
            return false;
        }
        return true;
    }

}

