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
    
    //print function
    void print(){
        for(unsigned int i = 0; i < adj_list.size(); i++){
            cout << i << ": ";
            for(unsigned j = 0; j < adj_list[i].size(); j++){
                cout << "(" << adj_list[i][j].first << ", " << adj_list[i][j].second << ") ";
            }
            cout << endl;
        }
        
    }

    //check if vertices are adjacent to eachother, if so cout weight.
    void isAdjacent(int v1, int v2){
        if(v1 > num_of_vertices){           //cout vertex not within list if its greater than the num of vertices
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
    
    //Dijkstra algorithm
    void Dijkstra(int V, map<int, vector<pair<int, float>>> adj_list, int S){
        priority_queue<pair<int,float>,vector<pair<int,float>>,greater<pair<int,float>>> pq;
        vector<int> distance(V, INT_MAX);
    
        distance[S] = 0;
        pq.push({0,S});
        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(unsigned int i = 0; i < adj_list[node].size(); i++){
                
                int edgeWeight = adj_list[node][i].second;
                int adjNode = adj_list[node][i].first;
             
                if(dis + edgeWeight < distance[adjNode]){
                    distance[adjNode] = dis + edgeWeight;
                    pq.push({distance[adjNode], adjNode});
                    
                }
            }
        
        }
        for(unsigned int i = 0; i < distance.size(); i++){
            cout << i << ": " << S << " cost: "<<  distance[i] << endl;
            
        }
        
       
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


