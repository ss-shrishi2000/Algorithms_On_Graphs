#include <bits/stdc++.h>
using namespace std;

map<int , bool> visited;

int reach(vector<vector<int> > &adj, int x, int y)
{
  //write your code here
  int n=adj.size();
  if(x==y)
    return 1;

  for(int i=0;i<=n;i++)
    visited[i]=false;

  queue<int> q;
  q.push(x);
  visited[x]=true;
  while(q.empty()==false)
  {
      int head=q.front();
      q.pop();
      for(auto it=adj[head].begin();it!=adj[head].end();it++)
      {
          if(*it == y)
            return 1;

          if(visited[*it]==false)
          {
              visited[*it]=true;
              q.push(*it);
          }
      }
      if(visited[y]==true)
        return 1;
      else
        return 0;
  }
  return 0;
}

int main() {
  size_t n, m;
  cin >> n >> m;
  vector<vector<int> > adj(n, vector<int>());
  for (size_t i = 0; i < m; i++)
  {
    int x, y;
    cin >> x >> y;
    adj[x - 1].push_back(y - 1);
    adj[y - 1].push_back(x - 1);
  }
  int x, y;
  cin >> x >> y;
  cout << reach(adj, x - 1, y - 1);
}
