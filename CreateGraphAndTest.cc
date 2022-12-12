#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include "graph.h"

using namespace std;


void graphReader(const string &graph_filename, const string &adjacency_filename){
    
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
            list.addEdge( nums[0], nums[i], nums[i+1]);
            i++;
            
            
        }
    }

    
    //list.print();
    
    file.close();
    
    
    ifstream adj_file(adjacency_filename);
    if (!adj_file.is_open()){
        cerr << "COULD NOT OPEN FILE!" << endl;
    }
    while(getline(adj_file,line)){
        stringstream ss(line);
        float nums;
        vector<float> query_nums;
        while(ss >> nums){
            if(nums <= 0){
                cerr << "NO NEGATIVE QUERY VERTEX NUMBER!" << endl;
            }
            query_nums.push_back(nums);
    
        }
        
        list.isAdjacent(query_nums[0], query_nums[1]);
    
    }
    
    adj_file.close();
}

int graphTestDriver(int argc, char **argv) {
    
    const string graph_filename(argv[1]);
    const string adjacency_filename(argv[2]);
    
    // Begin your code here. Feel free to add any helper functions or classes you need,
    // as long as we only have to call this function to run the specified assignment.
    graphReader(graph_filename, adjacency_filename);

    return 0;
}

int main(int argc, char **argv) {
    if (argc != 3) {
		cout << "Usage: " << argv[0] << " <GRAPH_File>" << "<ADJACENCY_QUERYFILE>" << endl;
		return 0;
    }

    graphTestDriver(argc, argv);

    return 0;
}
