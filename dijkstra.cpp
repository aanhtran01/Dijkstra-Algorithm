/* PIC 10C Homework 1, dijkstra.cpp
    Purpose: implement dijkstra's algorithm for weighted directed graphs
    Author: Anh Tran
    Date: 10/26/22
 */

#include "dijkstra.h"

//find the index of the orgin value
double find_origin(vector<string> names, string origin)
{
    vector<string>::iterator it;
    it = find(names.begin(), names.end(), origin);
    return (it - names.begin());
}

//find the index of the target value
double find_target(vector<string> names, string target)
{
    vector<string>::iterator it;
    it = find(names.begin(), names.end(), target);
    return (it - names.begin());
}


//find the minimum value in a vector of pairs
double find_minimum(vector<pair<bool, double>> track, double origin_node)
{
    double min_index = 0;
    for (double i = 1; i < track.size(); i++)
    {
        if (track[min_index].first == true)
        {
            min_index++;
        }
        if (track[i].first == false && track[min_index].first == false)
        {
            if (track[min_index].second > track[i].second && track[i].second != 0)
            {
                min_index = i;
            }
        }
    }
    return min_index;
}

//function to make a vector pair <bool_double>, initializing the vector by making all the bool values false and the double values 10000
vector<pair<bool, double>> make_pair_bool_double(double total_nodes, double base_val)
{
    vector<double> track_cost(total_nodes);

    //vector to mark nodes as visited or unvisited
    vector<bool> visited(total_nodes);

    vector<pair<bool, double>> track;

    //mark all unvisted nodes to 10000 (a tentative distance)
    for (int i = 0; i < total_nodes; i++)
    {
        track_cost[i] = base_val;
        visited[i] = false;
    }

    //push back variables into the vector of pairs track
    for (int i = 0; i < total_nodes; i++)
    {
        track.push_back(make_pair(visited[i], track_cost[i]));
    }

    return track;

}



vector<vector<size_t>> dijkstra(const vector<vector<double>>& map, const vector<string>& names, string origin, string target, double& cost)
{
    //initialize a vector to store all the paths
    vector<vector<size_t>> paths;

    double total_nodes = map[0].size();

    vector<pair<bool, double>> track = make_pair_bool_double(total_nodes, 10000);

    //determine origin node
    double origin_node = find_origin(names, origin);

    //set the origin node to 0
    track[origin_node].second = 0;

    //create a current node and set the initial node as current
    double current = origin_node;
    //determine target node
    double target_node = find_target(names, target);

    //vector to store path
    vector<pair<double, double>> path;
    //vector of vectors to store and compare paths

    vector<vector<pair<double, double>>> compare_paths;
    path.push_back(make_pair(origin_node, cost));
    //push back the vector to vector of vectors
    compare_paths.push_back(path);
    path.clear();

    while (track[target_node].first != true)
    {
        //mark the current node as visited
        track[current].first = true;

        for (int index_neighbor = 0; index_neighbor < total_nodes; index_neighbor++)
        {
            if (map[current][index_neighbor] > 0 && track[index_neighbor].first == false && track[index_neighbor].second >= track[current].second + map[current][index_neighbor])
            {
                track[index_neighbor].second = track[current].second + map[current][index_neighbor];

                //make a vector to store all the row numbers of that have the matching ending condition
                vector<int> row_counter;

                for (double a = 0; a < compare_paths.size(); a++)
                {
                   
                        if ((compare_paths[a].end() - 1) -> first == current && (compare_paths[a].end() - 1) -> second == cost && !compare_paths[a].empty())
                        {
                            row_counter.push_back(a);
                        }
        
                }


                //using the row_counter vector that contains all the rows that have the correct path, push the path back into the the vector and push back the neighbor value
                for (double row_count = 0; row_count < row_counter.size(); row_count++)
                {
                    for (int iter = 0; iter < compare_paths[row_counter[row_count]].size(); iter++)
                    {

                        path.push_back(make_pair(compare_paths[row_counter[row_count]][iter].first, compare_paths[row_counter[row_count]][iter].second));
                    }

                    path.push_back(make_pair(index_neighbor, track[index_neighbor].second));
                    //push back the vector to vector of vectors
                    compare_paths.push_back(path);
                    path.clear(); //clear the path vector

                }

                row_counter.clear(); //clear the row_counter vector

            }

        }


        //find the smallest node in unvisted
        int min_index = find_minimum(track, origin_node);

        //if the smallest node cost is infinity break the loop
        if (min_index >= 10000) { break; }

        //update the cost
        cost = track[min_index].second;
        //break loop when the min_index is equal to the target node
        if (min_index == target_node) { break; }

        //set the current node to the minimum index
        current = min_index;
    }

    //if there is no path cost is -1
    if (cost >= 10000) { cost = -1; }

    //delete the non correct paths
    
        for (double a = 0; a < compare_paths.size(); a++)
        {
            for (int iter = 0; iter < compare_paths[a].size(); iter++)
            {
                if (compare_paths[a].back().first == target_node && compare_paths[a].back().second == cost)
                {
                    continue;
                }
                else
                {
                    compare_paths[a].clear();
                }

            }

        }

    //copy the first values of the vector of vector of pairs into the vector of vectors of size_t by pushing back a vector of size_t
    vector<size_t> copy;

    for (int i = 0; i < compare_paths.size(); i++)
    {
        for (int it = 0; it != compare_paths[i].size(); it++)
        {
            if (!compare_paths[i].empty())
            {
                copy.push_back(compare_paths[i][it].first);
            }
     
        }
        if (!compare_paths[i].empty())
        {
            paths.push_back(copy);
            copy.clear();
        }
    }

    //return the vector of vectors
    return paths;
}



void print_paths(const vector<vector<size_t>>& paths, const vector<string>& names)
{
    //if the path is empty print out "No path found!"
    if (paths.empty())
    {
        cout << "No path found!" << endl;
    }

    //print out the path
    for (double a = 0; a < paths.size(); a++)
    {
        for (int iter = 0; iter < paths[a].size(); iter++)
        {
            if (iter == paths[a].size() - 1)
            {
                cout << names[paths[a][iter]];
            }
            else
            {
                cout << names[paths[a][iter]] << " -- ";
            }
        }
        cout << endl;
    }
}


            

