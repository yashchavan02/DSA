#include <fstream>
#include <climits>
#include <iostream>
#include <string>
using namespace std;

class Graph {
    int **A, v;
    string *V;
public:
    fstream file1, file2;
    Graph(string filename1, string filename2) {
        file1.open(filename1, ios::in);
        file1 >> v;
        A = new int *[v];
        for (int i = 0; i < v; i++) {
            A[i] = new int[v];
            for (int j = 0; j < v; j++) {
                file1 >> A[i][j];
            }
        }
        file1.close();

        file2.open(filename2, ios::in);
        V = new string[v];
        for (int i = 0; i < v; i++)
            file2 >> V[i];
        file2.close();
    }

    ~Graph() {
        for (int i = 0; i < v; i++)
            delete[] A[i];
        
        delete[] A;
        delete[] V;
    }

    void dijkstra(int start = 0) {
        int *cost = new int[v];
        bool *visited = new bool[v];

        for (int i = 0; i < v; i++) {
            cost[i] = INT_MAX;
            visited[i] = false;
        }
        cost[start] = 0;

        for (int i = 0; i < v - 1; i++) {
            int minCost = INT_MAX, minIndex = -1;
            for (int j = 0; j < v; j++) {
                if (!visited[j] && cost[j] < minCost) {
                    minCost = cost[j];
                    minIndex = j;
                }
            }

            if (minIndex == -1)
                break;
            visited[minIndex] = true;

            for (int j = 0; j < v; j++) {
                if (A[minIndex][j] && !visited[j] && cost[minIndex] != INT_MAX) {
                    cost[j] = min(cost[j], cost[minIndex] + A[minIndex][j]);
                }
            }
        }

        for (int i = 0; i < v; i++)
            cout << V[i] << " - " << (cost[i] == INT_MAX ? "INF" : to_string(cost[i])) << "\n";

        delete[] cost;
        delete[] visited;
    }
};

int main() {
    Graph g("matrix.txt", "names.txt");
    g.dijkstra();
    return 0;
}
