#include <iostream>
#include <vector>

using namespace std;

const int MAXN = 100;

vector<int> adj[MAXN];
int process[MAXN];
int resource[MAXN];

// Adds a process node to the graph
void addProcess(int p) {
    process[p] = 1;
}

// Adds a resource node to the graph
void addResource(int r) {
    resource[r] = 1;
}

// Adds an edge from a process to a resource
void addEdge(int p, int r) {
    adj[p].push_back(r);
}

// Returns true if the RAG has a cycle
bool hasCycle() {
    vector<int> inDegree(MAXN, 0);
    for (int i = 0; i < MAXN; i++) {
        for (int j : adj[i]) {
            inDegree[j]++;
        }
    }
    vector<int> q;
    for (int i = 0; i < MAXN; i++) {
        if (process[i] && inDegree[i] == 0) {
            q.push_back(i);
        }
    }
    int cnt = 0;
    while (!q.empty()) {
        int p = q.front();
        q.erase(q.begin());
        cnt++;
        for (int r : adj[p]) {
            inDegree[r]--;
            if (inDegree[r] == 0) {
                q.push_back(r);
            }
        }
    }
    return cnt != MAXN;
}

int main() {
    // Example graph
    addProcess(0);
    addProcess(1);
    addResource(2);
    addResource(3);
    addEdge(0, 2);
    addEdge(1, 2);
    addEdge(2, 3);

    if (hasCycle()) {
        cout << "RAG has a cycle" << endl;
    } else {
        cout << "RAG does not have a cycle" << endl;
    }

    return 0;
}
