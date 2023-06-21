
Dijkstra's Algorithm for Weighted Directed Graphs
=================================================

This repository contains the implementation of Dijkstra's algorithm for weighted directed graphs. The algorithm finds the shortest path between two nodes in a graph with weighted edges.

Usage:
-----

To use this implementation of Dijkstra's algorithm, follow these steps:

Include the header file "dijkstra.h" in your project.
Call the dijkstra function with the following parameters:
map: A vector of vectors representing the weighted directed graph.
names: A vector of strings representing the names of the nodes in the graph.
origin: A string specifying the name of the origin node.
target: A string specifying the name of the target node.
cost: A double reference to store the cost of the shortest path.
The function returns a vector of vectors, where each inner vector represents a path from the origin node to the target node.
Call the print_paths function with the following parameters:
paths: A vector of vectors representing the paths returned by the dijkstra function.
names: A vector of strings representing the names of the nodes in the graph.
The function prints out the paths found by Dijkstra's algorithm. If no path is found, it prints "No path found!"


Function Details:
-----------------

The implementation provides the following functions:

double find_origin(vector<string> names, string origin);
This function finds the index of the origin node in the names vector.

double find_target(vector<string> names, string target);
This function finds the index of the target node in the names vector.

double find_minimum(vector<pair<bool, double>> track, double origin_node);
This function finds the minimum value in a vector of pairs.

vector<pair<bool, double>> make_pair_bool_double(double total_nodes, double base_val);
This function initializes a vector of pairs with bool and double values.

vector<vector<size_t>> dijkstra(const vector<vector<double>>& map, const vector<string>& names, string origin, string target, double& cost);
This function implements Dijkstra's algorithm to find all possible shortest paths from the origin node to the target node. It returns a vector of vectors, where each inner vector represents a path. The cost parameter stores the smallest cost of the shortest path.

void print_paths(const vector<vector<size_t>>& paths, const vector<string>& names);
This function prints out the paths found by Dijkstra's algorithm using the node names.

Notes:
-----

The implementation assumes that the input graph is represented by a vector of vectors (map) where each element represents the weight of an edge from one node to another. The names vector contains the names of the nodes in the same order as the graph representation.
The dijkstra function returns a vector of vectors (paths) where each inner vector represents a path from the origin node to the target node. If no path is found, the paths vector will be empty.
The print_paths function prints out the paths found by Dijkstra's algorithm. If no path is found, it prints "No path found!"
The algorithm calculates the shortest path and stores the cost in the cost parameter passed by reference.
If no path is found, the cost parameter will have a value of -1.
Please refer to the source code for more detailed information on the implementation.