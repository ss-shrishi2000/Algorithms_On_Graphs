Problem Introduction ->
A Computer Science curriculum specifies the prerequisites for each course as a list of courses that should be
taken before taking this course. You would like to perform a consistency check of the curriculum, that is,
to check that there are no cyclic dependencies. For this, you construct the following directed graph: vertices
correspond to courses, there is a directed edge (𝑢, 𝑣) is the course 𝑢 should be taken before the course 𝑣.
Then, it is enough to check whether the resulting graph contains a cycle.
Problem Description  ->
Task. Check whether a given directed graph with 𝑛 vertices and 𝑚 edges contains a cycle.
Input Format. A graph is given in the standard format.
Constraints. 1 ≤ 𝑛 ≤ 103, 0 ≤ 𝑚 ≤ 103.
Output Format. Output 1 if the graph contains a cycle and 0 otherwise




#include <iostream>
#include <vector>

using std::vector;
using std::pair;

int dfs(vector<vector<int> > &adj, int x, vector<int> &visited, vector<int> &recStack) {
  // Mark the current node as visited and part of recursion stack
  visited[x] = 1;
  recStack[x] = 1;
  // Recur for all the vertices adjacent to this vertex
  for (int i = 0; i < adj[x].size(); i++) {
    if (!visited[adj[x][i]] && dfs(adj, adj[x][i], visited, recStack))
	  return 1;
	else if(recStack[adj[x][i]])
	  return 1;
  }
  recStack[x] = 0;  // remove the vertex from recursion stack
  return 0;
}

int acyclic(vector<vector<int> > &adj) {
  // Mark all the vertices as not visited and not part of recursion stack
  vector<int> visited(adj.size());
  vector<int> recStack(adj.size());
  for (int i = 0; i < adj.size(); i++)
  {
    if (!visited[i]) {
      if (dfs(adj, i, visited, recStack))
        return 1;
    }
  }
  return 0;
}

int main() {
  size_t n, m;
  std::cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    adj[x - 1].push_back(y - 1);
  }
  std::cout << acyclic(adj);
}
