#include <iostream>
#include <queue>
#include <stack>
#include <vector>
            
using namespace std;



void depthFirstSearch(const vector<vector<int>>& graph, int start,vector<int>& order)
{
    vector<bool> visited(graph.size(), false);
    stack<int> buildingStack;

    visited[start] = true;
    buildingStack.push(start);

    while (!buildingStack.empty()) {
        int current = buildingStack.top();
        buildingStack.pop();
        order.push_back(current);

        for (int i = static_cast<int>(graph[current].size()) - 1; i >= 0; --i) {
            int neighbor = graph[current][i];
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                buildingStack.push(neighbor);
            }
        }
    }
}

void breadthFirstSearch(const vector<vector<int>>& graph, int start,vector<int>& order)
{
    vector<bool> visited(graph.size(), false);
    queue<int> buildingQueue;

    visited[start] = true;
    buildingQueue.push(start);

    while (!buildingQueue.empty()) {
        int current = buildingQueue.front();
        buildingQueue.pop();
        order.push_back(current);

        for (int neighbor : graph[current]) {
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                buildingQueue.push(neighbor);
            }
        }
    }
}

void printOrder(const vector<int>& order)
{
    for (size_t i = 0; i < order.size(); ++i) {
        if (i > 0) {
            cout << ' ';
        }
        cout << order[i];
    }
    cout << '\n';
}

int main()
{
    int buildingCount;
    int roadCount;
    int start;

    if (!(cin >> buildingCount >> roadCount >> start) ||
        buildingCount <= 0 || roadCount < 0 || start < 0 ||
        start >= buildingCount) {
        cerr << "Invalid graph input\n";
        return 1;
    }

    vector<vector<int>> graph(buildingCount);

    for (int road = 0; road < roadCount; ++road) {
        int firstBuilding;
        int secondBuilding;

        if (!(cin >> firstBuilding >> secondBuilding) ||
            firstBuilding < 0 || firstBuilding >= buildingCount ||
            secondBuilding < 0 || secondBuilding >= buildingCount) {
            cerr << "Invalid road input\n";
            return 1;
        }

        graph[firstBuilding].push_back(secondBuilding);
        graph[secondBuilding].push_back(firstBuilding);
    }

    vector<int> dfsOrder;
    vector<int> bfsOrder;

    depthFirstSearch(graph, start, dfsOrder);
    breadthFirstSearch(graph, start, bfsOrder);

    cout << "DFS order: ";
    printOrder(dfsOrder);
    cout << "BFS order: ";
    printOrder(bfsOrder);

    return 0;
}



