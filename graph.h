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
    
    vector<int> Dijkstra(int V, map<int, vector<pair<int, float>>> adj_list, int S){
        priority_queue<pair<int,float>,vector<pair<int,float>>,greater<pair<int,float>>> pq;
        vector<int> dist(V);
        for(unsigned int i = 0;i<V; i++) dist[i] = 1e9;
        vector<string> paths;
        dist[S] = 0;
        pq.push({0,S});
        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            string path = to_string(S);
            string pathNode;
            for(unsigned int i = 0; i < adj_list[node].size(); i++){
                
                int edgeWeight = adj_list[node][i].second;
                int adjNode = adj_list[node][i].first;
                
                if(dis + edgeWeight < dist[adjNode]){
                    dist[adjNode] = dis + edgeWeight;
                    pq.push({dist[adjNode], adjNode});
                    pathNode = to_string(adjNode);
                    path = path + " " + pathNode;
                }
            }
            paths.push_back(path);
        
        }
        for(unsigned int i = 0; i < dist.size(); i++){
            cout << i+1 <<": " << paths[i] << " cost: " <<  dist[i] << endl;
            
        }
       
        
        return dist;
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
