
#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;




// n is the number of vertices
// n - 1 is the maximum number of edges to get from one vertex to another
// source and destination are the indices of the vertices
bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
    if (n == 0 || n == 1) return true;

    unordered_map<int,vector<int>> graph;
    for (int i = 0; i < edges.size(); ++i) {
        graph[edges[i][0]].push_back(edges[i][1]);
        graph[edges[i][1]].push_back(edges[i][0]);
    }
    vector<bool> visited(n, 0);
    queue<int> q;
    q.push(source);
    visited[source] = true;

    while (!q.empty()) {
        int curr = q.front();
        q.pop();
        if (curr == destination) {
            return true;
        }
        for (int i = 0; i < graph[curr].size(); ++i) {
            if (!visited[graph[curr][i]]) {
                visited[graph[curr][i]] = true;
                q.push(graph[curr][i]);
            } 
        }
    }
    
    return false;




}



int main() {
    int n = 10;
    vector<vector<int>> edges = {{4,3},{1,4},{4,8},{1,7},{6,4},{4,2},{7,4},{4,0},{0,9},{5,4}};

    // print_edges(edges);

    bool result = validPath(n, edges, 5, 9);
    if (result) {
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }



    
}

