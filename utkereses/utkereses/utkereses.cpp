#include <string>
#include <cstdio>
#include <iostream>
#include <ctime>


using namespace std;

// Number of points
#define V 12
#define INFINITE 9999

class Graph {
public:
	// Graph descriptor object with weights in matrix showing line weight
	int graph[V][V];   
	// Weights of points of graph
	int pointWeights[V] = {
		0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0
	};

	const char letters[V] = {
		'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L'
	};


	void setGraph(int paramGraph[V][V]) {
		for (int v = 0; v < V; v++) {
			for (int i = 0; i < V; i++) {
				graph[v][i] = paramGraph[v][i];
			}
		}
	}

	int drawGraph()
	{
		printf("\nGraph:\n");

		printf("\t\t    %s    %s    %s\n", getValueAsString(0, 1).c_str(), getValueAsString(1, 2).c_str(), getValueAsString(2, 3).c_str());
		printf("\t\t %c%c%s %c%c%s %c%c%s %c%c\n", drawPoint(0), getPointWeightAsChar(0), getVectorAsString(0, 1).c_str(), drawPoint(1), getPointWeightAsChar(1), getVectorAsString(1, 2).c_str(), drawPoint(2), getPointWeightAsChar(2), getVectorAsString(2, 3).c_str(), drawPoint(3), getPointWeightAsChar(3));
		for (int i = 0; i < 3; i++) {
			printf("\t         %s     %s     %s     %s \n", getVectorAsString(0, 4).c_str(), getVectorAsString(1, 5).c_str(), getVectorAsString(2, 6).c_str(), getVectorAsString(3, 7).c_str());
		}
		printf("\t         %s %s  %s %s  %s %s  %s %s\n", getVectorAsString(0, 4).c_str(), getValueAsString(0, 4).c_str(), getVectorAsString(1, 5).c_str(), getValueAsString(1, 5).c_str(), getVectorAsString(2, 6).c_str(), getValueAsString(2, 6).c_str(), getVectorAsString(3, 7).c_str(), getValueAsString(3, 7).c_str());
		for (int i = 0; i < 2; i++) {
			printf("\t         %s     %s     %s     %s \n", getVectorAsString(0, 4).c_str(), getVectorAsString(1, 5).c_str(), getVectorAsString(2, 6).c_str(), getVectorAsString(3, 7).c_str());
		}
		printf("\t         %s  %s %s  %s %s  %s %s \n", getVectorAsString(0, 4).c_str(), getValueAsString(4, 5).c_str(), getVectorAsString(1, 5).c_str(), getValueAsString(5, 6).c_str(), getVectorAsString(2, 6).c_str(), getValueAsString(6, 7).c_str(), getVectorAsString(3, 7).c_str());
		printf("\t\t %c%c%s %c%c%s %c%c%s %c%c\n", drawPoint(4), getPointWeightAsChar(4), getVectorAsString(4, 5).c_str(), drawPoint(5), getPointWeightAsChar(5), getVectorAsString(5, 6).c_str(), drawPoint(6), getPointWeightAsChar(6), getVectorAsString(6, 7).c_str(), drawPoint(7), getPointWeightAsChar(7));

		for (int i = 0; i < 3; i++) {
			printf("\t         %s     %s     %s     %s \n", getVectorAsString(4, 8).c_str(), getVectorAsString(5, 9).c_str(), getVectorAsString(6, 10).c_str(), getVectorAsString(7, 11).c_str());
		}
		printf("\t         %s %s  %s %s  %s %s  %s %s\n", getVectorAsString(4, 8).c_str(), getValueAsString(4, 8).c_str(), getVectorAsString(5, 9).c_str(), getValueAsString(5, 9).c_str(), getVectorAsString(6, 10).c_str(), getValueAsString(6, 10).c_str(), getVectorAsString(7, 11).c_str(), getValueAsString(7, 11).c_str());
		for (int i = 0; i < 3; i++) {
			printf("\t         %s     %s     %s     %s \n", getVectorAsString(4, 8).c_str(), getVectorAsString(5, 9).c_str(), getVectorAsString(6, 10).c_str(), getVectorAsString(7, 11).c_str());
		}
		printf("\t\t %c%c%s %c%c%s %c%c%s %c%c\n", drawPoint(8), getPointWeightAsChar(8), getVectorAsString(8, 9).c_str(), drawPoint(9), getPointWeightAsChar(9), getVectorAsString(9, 10).c_str(), drawPoint(10), getPointWeightAsChar(10), getVectorAsString(10, 11).c_str(), drawPoint(11), getPointWeightAsChar(11));
		printf("\t\t    %s    %s    %s\n", getValueAsString(8, 9).c_str(), getValueAsString(9, 10).c_str(), getValueAsString(10, 11).c_str());

		return true;
	}

	string getValueAsString(int x, int y)
	{
		string stringValue = "  ";

		if (graph[x][y] != 0) {

			stringValue = std::to_string(graph[x][y]);
			if (graph[x][y] < 10) {
			    stringValue = stringValue + " ";
			}
		}
		return stringValue;
	}

	char getPointWeightAsChar(int x)
	{
		char charValue = ' ';

		if (pointWeights[x] != 0) {
			charValue = '0' + pointWeights[x];
		}
		return charValue;
	}

	// Dont draw points that have no connections
	char drawPoint(int x)
	{
		bool found = false;
		char point = ' ';

		// Search "to" and "from" connections
		for (int i = 0; i < V; i++) {
			if (graph[x][i] != 0) {
				found = true;
			}
		}
		for (int i = 0; i < V; i++) {
			if (graph[i][x] != 0) {
				found = true;
			}
		}

		if (found == true) {
			point = letters[x];
		}
		return point;
	}


	string getVectorAsString(int x, int y)
	{
		string stringValue = " ";
		if ((graph[x][y] != 0 || graph[y][x] != 0) && x + 1 == y) {
			stringValue = "---";
		} else if (graph[x][y] != 0 || graph[y][x] != 0) {
			stringValue = "|";
		} else if (x + 1 == y) {
			stringValue = "   ";
		}
		return stringValue;
	}

	// A utility function to print the constructed distance array from dijkstras return value
	void printSolution(int dist[])
	{
		printf("\n\nPoint Distance from Source\n");
		for (int i = 0; i < V; i++) {
			printf("%d - %c \t\t %d\n", i, letters[i], dist[i]);
		}
	}

	// Dijkstras algorithm function
	void dijkstra()
	{
		int graph1Template[V][V] = {
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
		};

		int n = V;
		int startnode = 0;
		// pred[] stores predecessor of each point
		// Count is the number of nodes visited
		int cost[V][V], distance[V], pred[V];
		int visited[V], count, mindistance, nextnode, i, j;

		// Cost matrix creation, unconnected points have infinite weight
		for (i = 0; i < n; i++) {
			for (j = 0; j < n; j++) {
				if (graph[i][j] == 0) {
					cost[i][j] = INFINITE;
				}
				else {
					cost[i][j] = graph[i][j];
				}
			}
		}
/*
		// Transpone matrix
		for (int i = 0; i < V; i++) {
			for (int j = i; j < V; j++) {
				if (cost[i][j] != 0)
					cost[j][i] = cost[i][j];
			}
		}
		*/

		// Initialize pred[], distance[] and visited[] arrays
		for (i = 0; i < n; i++)
		{
			distance[i] = cost[startnode][i];
			pred[i] = startnode;
			visited[i] = 0;
		}

		distance[startnode] = 0;
		visited[startnode] = 1;
		count = 1;

		while (count < n - 1)
		{
			mindistance = INFINITE;

			// Find the closest point (nextnode)
			for (i = 0; i < n; i++)
				if (distance[i] < mindistance && !visited[i])
				{
					mindistance = distance[i];
					nextnode = i;
				}

			// Check if a better path exists through nextnode            
			visited[nextnode] = 1;
			for (i = 0; i < n; i++)
				if (!visited[i])
					if (mindistance + cost[nextnode][i] < distance[i])
					{
						distance[i] = mindistance + cost[nextnode][i];
						pred[i] = nextnode;
					}
			count++;
		}

		// Print the paths of each point
		for (i = 0; i < n; i++) {
			if (i != startnode)
			{
				if (distance[i] != 9999) {
					printf("\nPath= %d ", i);
				}
				j = i;
				do
				{
					j = pred[j];
					printf(" <- %d", j);
				} while (j != startnode);
			}
	    }

		// Calculated lines that will remain
		for (i = 0; i < n; i++) {
			int from, to;
			if (pred[i] < i) {
				from = pred[i];
				to = i;
			}
			else {
				from = i;
				to = pred[i];
			}
			cost[from][to] = 1;
		}

		// Apply new calculated graph to original graph
		for (int v = 0; v < V; v++) {
			for (int i = 0; i < V; i++) {
				if (cost[v][i] != 1) {
					graph[v][i] = 0;
				}
			}
		}
		printSolution(distance);
	}

	virtual void randomize() = 0;
};



class Normal : public Graph {
public:

	void randomize()
	{
		int min = 1;
		int max = 9;

		// Give random values to the graph lines
		for (int v = 0; v < V; v++) {
			for (int i = v + 1; i < V; i++) {
				if (graph[v][i] == 1) {
					graph[v][i] = min + (rand() % (int)(max - min + 1));
				}
			}
		}
	}

};


class Randomized : public Graph {
public:

	void randomize()
	{
		int min = 1;
		int max = 9;
//		int binMin = 0;
//		int binMax = 1;

		for (int v = 0; v < V; v++) {
			for (int i = v + 1; i < V; i++) {
				if (graph[v][i] == 1) {
			  //    graph[v][i] = binMin + (rand() % (int)(binMax - binMin + 1));
					if (removeVectorByProbability(findExistingConnectionCount(v)) == true) {
						graph[v][i] = 0;
					}
				}
			}
		}

		// Give random values to the graph lines
		for (int v = 0; v < V; v++) {
			for (int i = v + 1; i < V; i++) {
				if (graph[v][i] == 1) {
					graph[v][i] = min + (rand() % (int)(max - min + 1));
				}
			}
		}
	}

	// Finds number of connections of a given point
	int findExistingConnectionCount(int node)
	{
		int connections = 0;
			for (int i = 0; i < V; i++) {
				if (graph[node][i] != 0) {
					connections++;
				}
			}
		return connections;
	}

	// Add new lines by lowering probability with account of existing lines
	// The more neighbours, the higher probability of removing the line
	bool removeVectorByProbability(int neighbours) {
		int val;
		int min = 1;
		int max = 100;
		val = min + (rand() % (int)(max - min + 1));
		bool remove = false;
		if (neighbours == 4) {
			remove = true;
		}
		else if (neighbours == 3 && val < 50) {
			remove = true;
		}
		else if (neighbours == 2 && val < 33) {
			remove = true;
		}
		else if (neighbours == 1 && val < 25) {
			remove = true;
		}
		return remove;
	}

};


class Weighted : public Graph {
public:

	void randomize()
	{
		int min = 1;
		int max = 9;

		// Give a random value to graph lines
		for (int v = 0; v < V; v++) {
			for (int i = v + 1; i < V; i++) {
				if (graph[v][i] == 1) {
					graph[v][i] = min + (rand() % (int)(max - min + 1));
				}
			}
			printf("\n");
		}
	}

	void randomizeWeights()
	{
		int min = 1;
		int max = 9;

		// Give a random value to weights
		printf("\nRandomized weights are:\n");
		for (int v = 0; v < V; v++) {
			pointWeights[v] = min + (rand() % (int)(max - min + 1));
			printf("\nPoint: %c - %d", letters[v], pointWeights[v]);
		}

	}

	void addWeightsToGraph()
	{
		randomizeWeights();
		// Add point weights on to graph lines
		for (int v = 0; v < V; v++) {
			for (int i = v + 1; i < V; i++) {
				if (graph[v][i] != 0) {
					graph[v][i] = graph[v][i] + pointWeights[i];
				}
			}
		}
	}
};


int main()
{
	srand(time(0));

	// Descriptor of graph structure and weights
	int graphTemplate[V][V] = {
		{ 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
	};
	
	Normal graph1;
	graph1.setGraph(graphTemplate);

	Randomized graph2;
	graph2.setGraph(graphTemplate);

	Weighted graph3;
	graph3.setGraph(graphTemplate);

	printf("Drawing normal values graph");
	std::cin.ignore();

	graph1.randomize();
	graph1.drawGraph();
	graph1.dijkstra();
	graph1.drawGraph();
	printf("Drawing randomized values graph");
	std::cin.ignore();

	graph2.randomize();
	graph2.drawGraph();
	graph2.dijkstra();
	graph2.drawGraph();
	printf("Drawing weighted values graph");
	std::cin.ignore();

	graph3.randomize();
	graph3.drawGraph();
	graph3.dijkstra();
	graph3.drawGraph();
	printf("Adding weights to graph");
	std::cin.ignore();

	graph3.addWeightsToGraph();
	graph3.dijkstra();
	graph3.drawGraph();
	printf("Ending program");
	std::cin.ignore();

	return 0;
}
