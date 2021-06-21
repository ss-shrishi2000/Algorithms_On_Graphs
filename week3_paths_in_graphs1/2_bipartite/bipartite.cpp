
Checking whether a Graph is Bipartite
Problem Introduction
An undirected graph is called bipartite if its vertices can be split into two parts such that each edge of the
graph joins to vertices from different parts. Bipartite graphs arise naturally in applications where a graph
is used to model connections between objects of two different types (say, boys and girls; or students and
dormitories).
An alternative definition is the following: a graph is bipartite if its vertices can be colored with two colors
(say, black and white) such that the endpoints of each edge have different colors.
Problem Description
Task. Given an undirected graph with 𝑛 vertices and 𝑚 edges, check whether it is bipartite.
Input Format. A graph is given in the standard format.
Constraints. 1 ≤ 𝑛 ≤ 105, 0 ≤ 𝑚 ≤ 105.
Output Format. Output 1 if the graph is bipartite and 0 otherwise.
   
  Sample 1.
Input:
4 4
1 2
4 1
2 3
3 1
Output:
0
1 2
4

SOLUTION:-

#include<bits/stdc++.h>
using namespace std;
# define vi vector<int>
# define N 1e5+5


vi g[N];
int colour[N];

void dfs(int node)
{
  for(int &i : g)
  {
    if(colour[i]==colour[node])
    {
      cout<<"0";
      exit(0);
    }
    if(colour[i]==0)
    {
      colour[i]= 3-colour[node];
      dfs(i);
    }
  }
}

int main()
{
  int x,y,n,m;
  cin>>n>>m;
  for(int i=0;i<m;i++)
  {
    cin>>x>>y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  for(int i=1;i<=n;i++)
    colour[i]=0;
  
  for(int i=1;i<=n;i++)
  {
    if(colour[i]==0)
      dfs(i);
  }
  cout<<1;
  return 0;
}
    
  
  
