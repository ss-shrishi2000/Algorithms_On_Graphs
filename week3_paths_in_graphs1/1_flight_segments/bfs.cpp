Computing the Minimum Number of Flight Segments

Problem Introduction :-
 You would like to compute the minimum number of flight segments to get from one city to another one. For
this, you construct the following undirected graph: vertices represent cities, there is an edge between two
vertices whenever there is a flight between the corresponding two cities. Then, it suffices to find a shortest
path from one of the given cities to the other one.
  
Problem Description
Task. Given an undirected graph with 𝑛 vertices and 𝑚 edges and two vertices 𝑢 and 𝑣, compute the length
of a shortest path between 𝑢 and 𝑣 (that is, the minimum number of edges in a path from 𝑢 to 𝑣).
Input Format. A graph is given in the standard format. The next line contains two vertices 𝑢 and 𝑣.
Constraints. 2 ≤ 𝑛 ≤ 105, 0 ≤ 𝑚 ≤ 105, 𝑢 ̸= 𝑣, 1 ≤ 𝑢, 𝑣 ≤ 𝑛.
Output Format. Output the minimum number of edges in a path from 𝑢 to 𝑣, or −1 if there is no path.
  
  Sample 1.
  Input:
   4 4
   1 2
   4 1
   2 3
   3 1
   2 4
  Output: 2
    
  Solution :-
#include <bits/stdc++.h>
using namespace std;

int distance(vector<vector<int> > &adj, int s, int t)
{
  //write your code here
  int V = adj.size();
  int dist[V+10];
  bool vis[V+10];
  for(int i=0;i<V;i++)
    dist[i]=INT_MAX,vis[i]=false;

  queue<int> q;
  q.push(s);
  dist[s]=0;
  vis[s]=true;
    while(!q.empty())
    {
        int h=q.front();
        q.pop();
        for(auto it=adj[h].begin();it!=adj[h].end();it++)
        {
            if(*it==t)
            {
                return dist[h]+1;
            }
            if(vis[*it]==false)
            {
                vis[*it]=true;
                q.push(*it);
                dist[*it]=dist[h]+1;
            }
        }
    }

  return -1;
}

int main()
{
  int n, m;
  cin>>n>>m;
  vector<vector<int> > adj(n+10, vector<int>());
  for (int i = 0; i < m; i++)
  {
    int x, y;
    cin >> x >> y;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  int s, t;
  cin>>s>>t;
  cout<<distance(adj, s, t);
}
