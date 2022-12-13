# Assignment-5-Code
Jason Chen
The goal of this assignment is to become familiar with heaps, disjoint sets, and graph algorithms.

To compile type:

 `make all`

To clean object files and executables type:

 `make clean`
 
To run the create and test graph routine, type:
`./CreateGraphAndTest <GRAPH_FILE> <ADJECENCY_QUERYFILE>`

Will read the graph file below:

    5
    1 2 0.2 4 10.1 5 0.5
    2 1 1.5
    3 2 100.0 4 50.2
    4
    5 2 10.5 3 13.9

For each vertex, I have a list of the adjacent vertices with positive edge weights. For instance, in the
above example, vertex 1 is connected to vertex 2 (edge weight 0.2), to vertex 4 (edge weight 10.1) and to
vertex 5 (edge weight 0.5). Vertex 2 is connected to vertex 1 (edge weight 1.5), vertex 4 has no outgoing
edges, etc.
    
And take the query file below:

    4 1
    3 4
    1 5
    5 1 
    1 3
    
I will read a second text file (let us call it AdjacencyQueries1.txt) that will contain a set of pair of
vertices. My program will have to first create the graph by reading it from the text file Graph1.txt. It
will then open the file AdjacencyQueries1.txt and for each pair of vertices in it, my program will print
whether the vertices are adjacent or not, and if they are, my program will print the weight of the edge that
connects them.

Output:

    4 1: not_connected
    3 4: connected 50.2
    1 5: connected 0.5
    5 1: not_connected
    1 3: not_connected


where `<GRAPH_FILE>` is the file used to create the graph and
`<ADJECENCY_QUERYFILE>` is the file used to check if vertices
are adjacent

Example:
`./CreateGraphAndTest Graph1.txt AdjacencyQueries1.txt`

To run the find paths in graph routine, type:
`./FindPaths <GRAPH_FILE> <STARTING_VERTEX>`

This program should use Dijkstra’s Algorithm to find the shortest paths from a given starting vertex to all
vertices in the graph file.

where `<GRAPH_FILE>` is the file used to create the graph and 
`<STARTING_VERTEX>` is the vertex in the graph as the starting
point for the paths

Example:
`./FindPaths Graph2.txt 1`

Output:

    1: 1 cost: 0.0
    2: 1 2 cost: 2.0
    3: 1 4 3 cost: 3.0
    4: 1 cost: 1.0
    5: 1 4 5 cost: 3.0
    6: 1 4 7 6 cost: 6.0
    7: 1 4 7 cost: 5.0

Special Case: Unreachable Vertices
There is a special case that may arise based on the input graph and the starting vertex. This is the case
when there is no path from a starting vertex to the destination. In such cases, you should include the word
not_possible in your output. This case arises multiple times in the following:

./FindPaths Graph2.txt 7

Then, the output should be:

    1: not_possible
    2: not_possible
    3: not_possible
    4: not_possible
    5: not_possible
    6: 7 6 cost: 1.0
    7: 7 cost: 0.0
    
Adjacency List: is a list of arrays where the size of the array is equal to the number of nodes present
in the graph.

Dijkstra's Algorithm: finds the shortest path between a given node (which is called the "source node") and
all other nodes in a graph.


Things I struggled on:

1. I struggled on implementing Dijkstra's Algorithm. Producing abnormally large numbers.


If I had more time:

Spend more time on Dijkstra's Algorithm, and go to tutor.
