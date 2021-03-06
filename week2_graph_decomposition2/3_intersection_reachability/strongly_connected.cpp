Problem Introduction
The police department of a city has made all streets one-way. You would like
to check whether it is still possible to drive legally from any intersection to
any other intersection. For this, you construct a directed graph: vertices are
intersections, there is an edge (𝑢, 𝑣) whenever there is a (one-way) street from
𝑢 to 𝑣 in the city. Then, it suffices to check whether all the vertices in the
graph lie in the same strongly connected component.
Problem Description
Task. Compute the number of strongly connected components of a given directed graph with 𝑛 vertices and
𝑚 edges.
Input Format. A graph is given in the standard format.
Constraints. 1 ≤ 𝑛 ≤ 104, 0 ≤ 𝑚 ≤ 104.
Output Format. Output the number of strongly connected components




#include <algorithm>
#include <iostream>
#include <vector>
#include <stack>

using std::vector;
using std::pair;
using std::stack;

vector<vector<int> > reverseEdges(vector<vector<int> > &adj){
	vector<vector<int> > rAdj(adj.size(), vector<int>());
    for(int i = 0; i < adj.size(); i++){
	  // Recur for all the vertices adjacent to this vertex
	  for(int j = 0; j < adj[i].size(); j++){
		rAdj[adj[i][j]].push_back(i);
	  }
	}
	return rAdj;
}

void dfs(vector<vector<int> > &adj, int x, vector<int> &visited, stack<int> &Stack) {
	// Mark the current node as visited
	visited[x] = 1;

	// Recur for all the vertices adjacent to this vertex
	for (int i = 0; i < adj[x].size(); i++) {
      if(!visited[adj[x][i]]){
        visited[adj[x][i]] = 1;
		dfs(adj, adj[x][i], visited, Stack);
	  }
	}

	// All vertices reachable from x are processed by now, push x to Stack
	Stack.push(x);
}

int number_of_strongly_connected_components(vector<vector<int> > adj) {
  int result = 0;
  stack<int> Stack;

  // Mark all the vertices as not visited (For first DFS)
  vector<int> visited(adj.size(), 0);

  // Fill vertices in stack according to their finishing times
  for (int i = 0; i < adj.size(); i++) {
	if(!visited[i]){
	  dfs(adj, i, visited, Stack);
	}
  }

  // get the reversed adj list
  vector<vector<int> > rAdj = reverseEdges(adj);

  // Mark all the vertices as not visited (For second DFS)
  for(int i = 0; i < adj.size(); i++) {
	visited[i] = 0;
  }

  // Now process all vertices in order defined by Stack
  while (! Stack.empty()) {
	// Pop a vertex from stack
    int x = Stack.top();
    Stack.pop();

    // get one Strongly connected component of the popped vertex
    if (!visited[x]) {
	  stack<int> componentStack;
	  dfs(rAdj, x, visited, componentStack);
	  result++;
	}
  }
  return result;
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
  std::cout << number_of_strongly_connected_components(adj);
}
