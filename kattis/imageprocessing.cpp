#include<bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int h,w,kh,kw;
  cin>>h>>w>>kh>>kw;
  int graph[21][21];
  for(int i=0;i<h;i++)
  {
    for(int j=0;j<w;j++)
    {
      cin>>graph[i][j];
    }
  }

  int graph2[21][21];

  for(int i=0;i<kh;i++)
  {
    for(int j=0;j<kw;j++)
    {
      cin>>graph2[i][j];
    }
  }
  //build graph
  for(int i=0;i<kh;i++)
  {
    for(int j=0;j<kw/2;j++)
    {
      swap(graph2[i][j],graph2[i][kw-j-1]);
    }
  }

  for(int i=0;i<kw;i++)
  {
    for(int j=0;j<kh/2;j++)
    {
      swap(graph2[j][i],graph2[kh-j-1][i]);
    }
  }
  // swap grap
  for(int i=0;i<=h-kh;i++)
  {
    for(int j=0;j<=w-kw;j++)
    {
      int ans=0;
      for(int k=0;k<kh;k++)
      {
        for(int l=0;l<kw;l++)
        {
          ans+=graph[i+k][j+l]*graph2[k][l];
          //cout<<graph[i+k][j+l]<<" "<<graph2[k][l]<<" ";
        }
      }
      cout<<ans<<" ";
    }
    cout<<"\n";
  }
}
