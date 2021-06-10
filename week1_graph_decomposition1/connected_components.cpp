#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> adj , int v, bool vis[])
{
    vis[v]=true;
    for(auto it=adj[v].begin();it!=adj[v].end();it++)
    {
        if(vis[*it]==false)
            dfs(adj, *it , vis);
    }
}

int number_of_components(vector<vector<int> > &adj)
{
  int res = 0 , v=adj.size();
  //write your code here
  int cnt=0;
  bool *vis = new bool[v];
  memset(vis, false, sizeof(vis));
  for(int i=0;i<v;i++)
  {
      if(vis[i]==false)
      {
          dfs(adj , i, vis);
          cnt++;
      }
  }

  return cnt;
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
  cout << number_of_components(adj);
}
