209294768 sagitmalk10@gmail.com
# Graphs & Operators Overloading

This project extands [the previous project](https://github.com/SagitMalka/cpp_1.git) by enabling manipulating graphs using an adjacency matrix. The class supports various operations including addition, subtraction, comparison, and printing of graphs.
No changes has been made on Algorithms.hpp's functions.
## Features

- **Graph Operations**:
  - Load and print graphs.
  - Perform arithmetic operations on graphs (addition, subtraction).
  - Increment and decrement graphs.
  - Compare graphs.
  - Multiply graphs by a scalar.
  - Graphs multiplication.
  - Unary operations.

- **Operator Overloading**:
  - `operator+` (addition)
  - `operator-` (subtraction)
  - `operator*` (multiplication)
  - `operator+=`
  - `operator-=`
  - `operator++` (prefix and postfix)
  - `operator--` (prefix and postfix)
  - `operator==` (equality)
  - `operator!=` (inequality)
  - `operator>`
  - `operator<`
  - `operator>=`
  - `operator<=`


## Usage
### Loading a Graph

To load a graph, use the loadGraph method:

```ruby
#include "Graph.hpp"

ariel::Graph g;
std::vector<std::vector<int>> matrix = {
    {0, 1, 0},
    {1, 0, 1},
    {0, 1, 0}
};
g.loadGraph(matrix);
```
### Printing a Graph

To print a graph, use the printGraph method:
```ruby
g.printGraph();
```
### Arithmetic Operations
#### Adding a Scalar
```ruby
g = g + 5;
g += 5;
```
#### Subtracting a Scalar
```ruby
g = g - 3;
g -= 3;
```
#### Adding Another Graph
```ruby
ariel::Graph g2;
g2.loadGraph(matrix);
g = g + g2;
g += g2;
```
#### Subtracting Another Graph
```ruby
g = g - g2;
g -= g2;
```
### Comparison Operators
#### Equality
```ruby
if (g == g2) {
    // Do something
}
```
#### Inequality
```ruby
if (g != g2) {
    // Do something
}
```
#### Greater Than
```ruby
if (g > g2) {
    // Do something
}
```
#### Less Than
```ruby
if (g < g2) {
    // Do something
}
```
### Increment and Decrement
#### Prefix Increment
```ruby
++g;
```
#### Postfix Increment
```ruby
g++;
```
#### Prefix Decrement
```ruby
--g;
```
#### Postfix Decrement
```ruby
g--;
```
#### Multiplication by a Scalar
```ruby
g *= 2;
```
### Unary Operators
#### Unary Plus
```ruby
+g;
```
#### Unary Minus
```ruby
-g;
```
### Example
Here is an example of how to use the `Graph` class:
```ruby
#include "Graph.hpp"

int main() {
    ariel::Graph g;
    std::vector<std::vector<int>> matrix = {
        {0, 1, 0},
        {1, 0, 1},
        {0, 1, 0}
    };
    g.loadGraph(matrix);
    g.printGraph();
    
    ariel::Graph g2;
    g2.loadGraph(matrix);
    
    g += g2;
    g.printGraph();
    
    if (g == g2) {
        std::cout << "Graphs are equal." << std::endl;
    }

    return 0;
}
```

## License
MIT
## Acknowledgements
- [Doctest](https://github.com/doctest/doctest) for unit testing.
