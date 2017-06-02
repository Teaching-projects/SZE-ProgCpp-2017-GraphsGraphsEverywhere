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
#include <string>
#include <limits.h>
#include <iostream>
#include <conio.h>
#include <ctime>
using namespace std;

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

int drawGraph(int graph[V][V])
{
	string abVector = "   ";
	char abValue = ' ';
	string bcVector = "   ";
	char bcValue = ' ';
	string efVector = "   ";
	char efValue = ' ';
	string fgVector = "   ";
	char fgValue = ' ';
	string aeVector = " ";
	char aeValue = ' ';
	string bfVector = " ";
	char bfValue = ' ';
	string cgVector = " ";
	char cgValue = ' ';
	string adVector = " ";
	char adValue = ' ';
	string deVector = " ";
	char deValue = ' ';
	// 0 - A, 1 - B, 2 - C, 3 - D, 4 - E, 5 - F, 6 - G
	printf("\nGraph:\n");
	if (graph[0][1] != 0) {
        abVector = "---";
	    abValue = '0' + graph[0][1];
	}
	if (graph[1][2] != 0) {
		bcVector = "---";
		bcValue = '0' + graph[1][2];
	}
	if (graph[4][5] != 0) {
		efVector = "---";
		efValue = '0' + graph[4][5];
	}
	if (graph[5][6] != 0) {
		fgVector = "---";
		fgValue = '0' + graph[5][6];
	}
	if (graph[0][4] != 0) {
		aeVector = "|";
		aeValue = '0' + graph[0][4];
	}
	if (graph[1][5] != 0) {
		bfVector = "|";
		bfValue = '0' + graph[1][5];
	}
	if (graph[2][6] != 0) {
		cgVector = "|";
		cgValue = '0' + graph[2][6];
	}
	if (graph[0][3] != 0) {
		adVector = "/";
		adValue = '0' + graph[0][3];
	}
	if (graph[3][4] != 0) {
		deVector = "\\";
		deValue = '0' + graph[3][4];
	}
	printf("\t\t    %c     %c \n", abValue, bcValue);
	printf("\t\t A %s B %s C \n", abVector.c_str(), bcVector.c_str());
	printf("\t     %c  %s%s     %s     %s \n", adValue, adVector.c_str(), aeVector.c_str(), bfVector.c_str(), cgVector.c_str());
	printf("\t       %s %s     %s     %s \n", adVector.c_str(), aeVector.c_str(), bfVector.c_str(), cgVector.c_str());
	printf("\t      %s  %s     %s     %s \n", adVector.c_str(), aeVector.c_str(), bfVector.c_str(), cgVector.c_str());
	printf("\t     D   %s %c   %s %c   %s %c\n", aeVector.c_str(), aeValue, bfVector.c_str(), bfValue, cgVector.c_str(), cgValue);
	printf("\t      %s  %s     %s     %s \n", deVector.c_str(), aeVector.c_str(), bfVector.c_str(), cgVector.c_str());
	printf("\t       %s %s     %s     %s \n", deVector.c_str(), aeVector.c_str(), bfVector.c_str(), cgVector.c_str());
	printf("\t     %c  %s%s     %s     %s \n", deValue, deVector.c_str(), aeVector.c_str(), bfVector.c_str(), cgVector.c_str());
	printf("\t\t E %s F %s G \n", efVector.c_str(), fgVector.c_str());
	printf("\t\t    %c     %c \n", efValue, fgValue);
	return true;
}

// A utility function to print the constructed distance array
int printSolution(int dist[], char letters[], int graphResult[V][V])
{

	drawGraph(graphResult);

	printf("\nVertex   Distance from Source\n");
	for (int i = 0; i < V; i++) {
		printf("%d - %c \t\t %d\n", i, letters[i], dist[i]);

	}

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

	// 0 - A, 1 - B, 2 - C, 3 - D, 4 - E
	for (int v = 0; v < V - 1; v++) {
		for (int i = v + 1; i < V; i++) {
			if (table[v][i] == 1) {
				table[v][i] = min + (rand() % (int)(max - min + 1));
		//		printf("Randomizer at: %d, %d \t", v, i);
			}
		}
		printf("\n");
	}


	return table;
}

// Funtion that implements Dijkstra's single source shortest path algorithm
// for a graph represented using adjacency matrix representation
void dijkstra(int graph[V][V], int src, char letters[V])
{
	int graphResult[V][V] = {
		{ 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0 }
	};
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
			&& dist[u] + graph[u][v] < dist[v]) {
		
			dist[v] = dist[u] + graph[u][v];
//			printf("\n  %c  %d     %d    ", letters[v], graph[u][v], dist[v]);
			printf("\n   %d     %d    %d ", u, v, graph[u][v]);

			graphResult[u][v] = graph[u][v];
		}
	}

	// print the constructed distance array
	printSolution(dist, letters, graphResult);
}

class Graph {
public:
	int graph[V][V];   // Length of a box

	int initGraph(void) {
		printf("\n  Hi \n ");
		return 1;
	}
	int copyGraph(int paramGraph[V][V]) {
		for (int v = 0; v < V; v++) {
			for (int i = 0; i < V; i++) {
				graph[v][i] = paramGraph[v][i];
				}
			}
		printf("\n  set \n ");
		return 1;
	}

	void printGraph() {
		for (int v = 0; v < V; v++) {
			for (int i = 0; i < V; i++) {
				printf("\n  %d ", graph[v][i]);

			}
		}
		printf("\n  printed \n ");
	}
};

// driver program to test above function
int main()
{
	srand(time(0));
	/* Let us create the example graph discussed above */
	int testGraph[V][V] = {
		{ 0, 1, 0, 1, 1, 0, 0 },
		{ 0, 0, 1, 0, 0, 1, 0 },
		{ 0, 0, 0, 0, 0, 0, 1 },
		{ 0, 0, 0, 0, 1, 0, 0 },
		{ 0, 0, 0, 0, 0, 1, 0 },
		{ 0, 0, 0, 0, 0, 0, 1 },
		{ 0, 0, 0, 0, 0, 0, 0 }
	};

	Graph graph1;
	graph1.initGraph();
	graph1.copyGraph(testGraph);
	graph1.printGraph();



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

	char letters[V] = {
		'A', 'B', 'C', 'D', 'E', 'F', 'G'
	};

	drawGraph(graph);
	flipGraph(graph);
	drawGraph(graph);
	std::cin.ignore();

	dijkstra(graph, 0, letters);

	std::cin.ignore();
	return 0;
}
