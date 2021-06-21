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
    
  
  
