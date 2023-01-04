/* PIC 10C Homework 1, dijkstra.h
    Purpose: implement dijkstra's algorithm for weighted directed graphs
    Author: Anh Tran
    Date: 10/26/22
 */

#ifndef dijkstra_h
#define dijkstra_h

//implement for weighted directed graphs
// all weights are positive numbers and are less than 10000

/*
 map is an adjacency matrix;
 names is a vector that contains names of all nodes;
 origin is the name of the starting node;
 target is the name of the destination node;
 if a path exists, dijkstra returns all possible shortest paths and cost stores the
 smallest cost;
 if a path does not exist, dijkstra returns an empty vector and cost stores -1.
 print paths displays all possible paths using node names.
 */

#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

//function to find origin_index 
double find_origin(vector<string> names, string origin);

//function to find the target_index
double find_target(vector<string> names, string target);

//function to find the minimum_value 
double find_minimum(vector<pair<bool, double>> track, double origin_node);

//function to make a vector pair <bool_double>, initializing the vector by making all the bool values false and the double values 10000
vector<pair<bool, double>> make_pair_bool_double (double total_nodes, double base_val);

//function to return a 2D vector of size_t that contains all the shortest paths from origin to target
vector<vector<size_t>> dijkstra(const vector<vector<double>> & map, const vector<string> & names,string origin, string target, double & cost);

//print_paths 
void print_paths(const vector<vector<size_t>> & paths, const vector<string> & names);

#endif /* dijkstra_h */

