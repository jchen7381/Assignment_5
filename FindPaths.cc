#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <algorithm>
#include "graph.h"

using namespace std;

void pathReader(const string graph_filename, const string starting_vertex){
    // Open file
    ifstream file(graph_filename);
    
    // Check if the file was opened successfully
    if(!file.is_open()){
        cerr << "COULD NOT OPEN FILE!" << endl;
    }
    
    string line;
    getline(file,line);
    int total_vertices = stoi(line);
    Graph list(total_vertices);
    int vertices_counter{0};
    while(getline(file, line)){
        vertices_counter++;
        if(vertices_counter > total_vertices){
            cerr << "TOO MANY VERTICES!" << endl;
        }
        stringstream ss(line);
        float num;
        vector<float> nums;
        
        while(ss >> num){
            if(num <= 0){
                cerr << "NO NEGATIVE VERTEX NUMBER ALLOWED!" << endl;

            }
            nums.push_back(num);
            
        }
       
        for(unsigned int i = 1; i < nums.size(); i++){
            list.addEdge(nums[0], nums[i], nums[i+1]);
            i++;
            
            
        }
    }
    
    //list.print();
    int V = total_vertices;
    int S = stoi(starting_vertex);
    map<int, vector<pair<int, float>>> adj_list = list.getList();
    vector<int> distance = list.Dijkstra(V, adj_list,S);
    
    
    file.close();
    
}

int pathfindDriver(int argc, char **argv) {
    
    // Begin your code here. Feel free to add any helper functions or classes you need,
    // as long as we only have to call this function to run the specified assignment.
    const string graph_filename(argv[1]);
    const string starting_vertex(argv[2]);
    

    pathReader(graph_filename, starting_vertex);

    return 0;
}

int main(int argc, char **argv) {
    if (argc != 3) {
		cout << "Usage: " << argv[0] << " <GRAPH_FILE>" << "<STARTING_VERTEX>" << endl;
		return 0;
    }

    pathfindDriver(argc, argv);

    return 0;
}
