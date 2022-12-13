#ifndef STUDENT_GRAPH
#define STUDENT_GRAPH

#include "binary_heap.h"
#include <vector>
#include <map>
#include <queue>


using namespace std;

class Graph {
public:
    
    Graph(int v){
        num_of_vertices = v;
    }
    
    //add edge to graph
    void addEdge(int v1, int v2, float w) {
        adj_list[v1].push_back(make_pair(v2, w));
        
    }
    
    void print(){
        for(unsigned int i = 0; i < adj_list.size(); i++){
            cout << i << ": ";
            for(unsigned j = 0; j < adj_list[i].size(); j++){
                cout << "(" << adj_list[i][j].first << ", " << adj_list[i][j].second << ") ";
            }
            cout << endl;
        }
        
    }
    
    void isAdjacent(int v1, int v2){
        if(v1 > num_of_vertices){
            cout << "VERTEX NOT WITHIN LIST" << endl;
            
        }
        else{
            for(unsigned int i = 0; i < adj_list[v1].size(); i++){
                if(v2 == adj_list[v1][i].first){
                    cout << v1 << " " << v2 << ": connected " <<  adj_list[v1][i].second << endl;
                    return;
                }
            }
            cout << v1 << " " << v2 << ": not_connected " << endl;
            
        }
    }
    
    vector<int> Dijkstra(int  V, map<int, vector<pair<int, float>>> adj_list, int S){
        // Create a priority queue for storing the nodes as a pair {dist,node}
        // where dist is the distance from source to the node.
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        // Initialising distTo list with a large number to
        // indicate the nodes are unvisited initially.
        // This list contains distance from source to the nodes.
        vector<int> distTo(V, INT_MAX);
        
        // Source initialised with dist=0.
        distTo[S] = 0;
        pq.push({0, S});
        
        // Now, pop the minimum distance node first from the min-heap
        // and traverse for all its adjacent nodes.
        while (!pq.empty())
        {
            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();
            
            // Check for all adjacent nodes of the popped out
            // element whether the prev dist is larger than current or not.
            for (unsigned int i = 0; i < adj_list[node].size();i++)
            {
                int v = adj_list[node][i].first;
                int w = adj_list[node][i].second;
                
                if (dis + w < distTo[v])
                {
                    distTo[v] = dis + w;
                    
                    // If current distance is smaller,
                    // push it into the queue.
                    pq.push({dis + w, v});
                }
            }
        }
        // Return the list containing shortest distances
        // from source to all the nodes.
        for(unsigned int i = 0; i < V ;i++){
            cout << distTo[i] << endl;
        }
        return distTo;
    }
       
    
    map<int, vector<pair<int, float>>> getList(){
        return adj_list;
    }

private:
    
    int num_of_vertices;
    //map from vertices to their corresponding adjacency list.
    map<int, vector<pair<int, float>>> adj_list;
};




#endif
