Problem Introduction ->
Now, when you are sure that there are no cyclic dependencies in the given CS curriculum, you would like to
find an order of all courses that is consistent with all dependencies. For this, you find a topological ordering
of the corresponding directed graph.
Problem Description ->
Task. Compute a topological ordering of a given directed acyclic graph (DAG) with 𝑛 vertices and 𝑚 edges.
Input Format. A graph is given in the standard format.
Constraints. 1 ≤ 𝑛 ≤ 105, 0 ≤ 𝑚 ≤ 105. The given graph is guaranteed to be acyclic.
Output Format. Output any topological ordering of its vertices. (Many DAGs have more than just one
topological ordering. You may output any of them.)




#include <bits/stdc++.h>
using namespace std;

void topologicalSortUtil( vector<vector<int> >& adj , int v, bool visited[] , stack<int>& Stack)
{
    visited[v] = true;

    for (auto i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            topologicalSortUtil(adj,*i, visited, Stack);

    Stack.push(v);
}

void topologicalSort(vector<vector<int> > adj , int n)
{
    stack<int> Stack;
    bool* visited = new bool[n+1];
    for (int i = 0; i <= n; i++)
        visited[i] = false;

    for (int i = 1; i <= n; i++)
        if (visited[i] == false)
            topologicalSortUtil(adj , i, visited, Stack);

    // Print contents of stack
    while (Stack.empty() == false) {
        cout << Stack.top() << " ";
        Stack.pop();
    }
}

int main()
{
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n+1, vector<int>());
  for (size_t i = 0; i < m; i++)
  {
    int x, y;
    std::cin >> x >> y;
    adj[x].push_back(y );
  }
  topologicalSort(adj , n);
}
