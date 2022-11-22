# Route-Finding
The main goal of the project can be summarized as figuring out the best path
to two points on the map. The project mainly consists of four parts. The first one
is the read file section. In this section, the data stored in the dataset
"Final_Map.map" will be read and processed. The second part is the data
structure. In this part, the data will be stored in an established data structure.
Then, the third part is the algorithm part. The function of this part is calculating
the best path between two given locations by executing an algorithm which
based on the Dikstra algorithm (Dijkstra, 1959). It is worth noting that the best
route in this project will be considered as the shortest route.
In the end, the final one is visualization part. After the data has been processed
in the first three sections, it will be visualized in this section with Gunplot.

The code portion of the pathfinding project consists mainly of the source files
tu.c and work.c. First, the function of the source file tu.c is to render the
processed data into a visual attempt of the data.

In addition, the source file work.c consists of three modules. The first is the
shortest path finding function, which can pick the nearest point near the
specified point and update the distance between them, and the node visited in
the previous step, that is, if a shorter path is found, choose this shorter path.
The second is the path-tracing function, which tracks the path between the
specified two points. The last part, the main function of the source file, is to
store the node's ID and latitude and longitude from the file into node and
generate a visual map.
