//============================================================================
// Name        : utkereses.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

// A C / C++ program for Dijkstra's single source shortest path algorithm.
// The program is for adjacency matrix representation of the graph

#include <stdio.h>
#include <limits.h>
#include <iostream>
#include <conio.h>
#include <ctime>

// Number of vertices in the graph
#define V 7

// A utility function to find the vertex with minimum distance value, from
// the set of vertices not yet included in shortest path tree
int minDistance(int dist[], bool sptSet[])
{
	// Initialize min value
	int min = INT_MAX, min_index;

	for (int v = 0; v < V; v++)
	if (sptSet[v] == false && dist[v] <= min)
		min = dist[v], min_index = v;

	return min_index;
}

// A utility function to print the constructed distance array
int printSolution(int dist[], int n)
{
	printf("Vertex   Distance from Source\n");
	for (int i = 0; i < V; i++)
		printf("%d \t\t %d\n", i, dist[i]);
	return true;

}

int** flipGraph(int graph[V][V])
{
	int min = 1;
	int max = 9;
	int** table = new int*[V];
	for (int i = 0; i < V; ++i)
	{
		table[i] = new int[V];
		table[i] = graph[i];
	}

	graph;
	// 0 - A, 1 - B, 2 - C, 3 - D, 4 - E
	for (int v = 0; v < V - 1; v++) {
		for (int i = v + 1; i < V; i++) {
			if (table[v][i] == 1) {
				table[v][i] = min + (rand() % (int)(max - min + 1));
				printf("Mirrorer at: %d, %d \t", v, i);
			}
		}
		printf("\n");
	}
	printf("Graph:\n");


	return table;
}

int drawGraph(int graph[V][V])
{
	// 0 - A, 1 - B, 2 - C, 3 - D, 4 - E, 5 - F, 6 - G
	printf("Graph:\n");

	printf("\t\t    %d     %d \n", graph[0][1], graph[1][2]);
	printf("\t\t A --- B --- C \n");
	printf("\t     %d  /|     |     | \n", graph[0][3]);
	printf("\t       / |     |     | \n");
	printf("\t      /  |     |     | \n");
	printf("\t     D   | %d   | %d   | %d\n", graph[0][4], graph[1][5], graph[2][6]);
	printf("\t      \\  |     |     | \n");
	printf("\t       \\ |     |     | \n");
	printf("\t     %d  \\|     |     | \n", graph[3][4]);
	printf("\t\t E --- F --- G \n");
	printf("\t\t    %d    %d \n", graph[4][5], graph[5][6]);
	return true;
}

// Funtion that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
void dijkstra(int graph[V][V], int src)
{
	int dist[V];     // The output array.  dist[i] will hold the shortest
	// distance from src to i

	bool sptSet[V]; // sptSet[i] will true if vertex i is included in shortest
	// path tree or shortest distance from src to i is finalized

	// Initialize all distances as INFINITE and stpSet[] as false
	for (int i = 0; i < V; i++)
		dist[i] = INT_MAX, sptSet[i] = false;

	// Distance of source vertex from itself is always 0
	dist[src] = 0;

	// Find shortest path for all vertices
	for (int count = 0; count < V - 1; count++)
	{
		// Pick the minimum distance vertex from the set of vertices not
		// yet processed. u is always equal to src in first iteration.
		int u = minDistance(dist, sptSet);

		// Mark the picked vertex as processed
		sptSet[u] = true;

		// Update dist value of the adjacent vertices of the picked vertex.
		for (int v = 0; v < V; v++)

			// Update dist[v] only if is not in sptSet, there is an edge from
			// u to v, and total weight of path from src to  v through u is
			// smaller than current value of dist[v]
		if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
			&& dist[u] + graph[u][v] < dist[v])
			dist[v] = dist[u] + graph[u][v];
	}

	// print the constructed distance array
	printSolution(dist, V);
}

// driver program to test above function
int main()
{
	srand(time(0));
	/* Let us create the example graph discussed above */
	int graph[V][V] = {
		{ 0, 1, 0, 1, 1, 0, 0 },
		{ 0, 0, 1, 0, 0, 1, 0 },
		{ 0, 0, 0, 0, 0, 0, 1 },
		{ 0, 0, 0, 0, 1, 0, 0 },
		{ 0, 0, 0, 0, 0, 1, 0 },
		{ 0, 0, 0, 0, 0, 0, 1 },
		{ 0, 0, 0, 0, 0, 0, 0 }
	};

	int graph1Template[V][V] = {
		{ 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0 }
	};
	int route[V] = {
		0, 0, 0, 0, 0, 0, 0
	};

	drawGraph(graph);
	flipGraph(graph);

	std::cin.ignore();
	dijkstra(graph, 0);
	drawGraph(graph);
	std::cin.ignore();
	return 0;
}
