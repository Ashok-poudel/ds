#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

// Function to add an edge to the graph
void addEdge(unordered_map<int, vector<int>>& graph, int u, int v) {
    graph[u].push_back(v);
    graph[v].push_back(u);
}

// Function to check if a vertex has an odd degree
bool hasOddDegree(const unordered_map<int, vector<int>>& graph, int vertex) {
    return graph.at(vertex).size() % 2 != 0;
}

// Function to check if the graph has an Euler circuit
bool hasEulerCircuit(const unordered_map<int, vector<int>>& graph) {
    for (const auto& pair : graph) {
        if (hasOddDegree(graph, pair.first)) {
            return false;
        }
    }
    return true;
}

// Function to check if the graph has an Euler path
bool hasEulerPath(const unordered_map<int, vector<int>>& graph) {
    int oddDegreeCount = 0;
    for (const auto& pair : graph) {
        if (hasOddDegree(graph, pair.first)) {
            oddDegreeCount++;
        }
    }
    return oddDegreeCount == 2;
}

// Function to find an Euler circuit or path using Hierholzer's algorithm
void findEulerCircuitOrPath(unordered_map<int, vector<int>>& graph, int startVertex) {
    stack<int> stack;
    vector<int> circuitOrPath;
    stack.push(startVertex);

    while (!stack.empty()) {
        int currentVertex = stack.top();
        if (!graph[currentVertex].empty()) {
            int nextVertex = graph[currentVertex].back();
            graph[currentVertex].pop_back();
            graph[nextVertex].erase(remove(graph[nextVertex].begin(), graph[nextVertex].end(), currentVertex), graph[nextVertex].end());
            stack.push(nextVertex);
        } else {
            circuitOrPath.push_back(stack.top());
            stack.pop();
        }
    }

    // Print the Euler circuit or path
    for (int i = circuitOrPath.size() - 1; i >= 0; i--) {
        cout << circuitOrPath[i] << " ";
    }
    cout << endl;
}

int main() {
    unordered_map<int, vector<int>> graph;
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);

    if (hasEulerCircuit(graph)) {
        cout << "The graph has an Euler circuit: ";
        findEulerCircuitOrPath(graph, 0);
    } else if (hasEulerPath(graph)) {
        cout << "The graph has an Euler path: ";
        // Find a vertex with an odd degree to start the path
        for (const auto& pair : graph) {
            if (hasOddDegree(graph, pair.first)) {
                findEulerCircuitOrPath(graph, pair.first);
                break;
            }
        }
    } else {
        cout << "The graph does not have an Euler circuit or path." << endl;
    }

    return 0;
}
