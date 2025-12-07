#include<bits/stdc++.h>

using namespace std;
int graph[510][510];
bool visited[510][510];
int ans=0;
bool flag =false;
void dfs(int height,int i,int j)
{
    visited[i][j]=true;
    int last=min(graph[i+1][j],graph[i][j-1]);
    last=min(last,graph[i-1][j]);
    last=min(last,graph[i][j+1]);
    ans++;
    if(last<height)
    {
        flag=true;
    }

    if(graph[i+1][j]==height && visited[i+1][j]==false)
    {
        dfs(graph[i+1][j],i+1,j);
    }
    if(graph[i][j-1]==height && visited[i][j-1]==false)
    {
        dfs(graph[i][j-1],i,j-1);
    }
    if(graph[i-1][j]==height && visited[i-1][j]==false)
    {
        dfs(graph[i-1][j],i-1,j);
    }
    if(graph[i][j+1]==height && visited[i][j+1]==false)
    {
        dfs(graph[i][j+1],i,j+1);
    }
}

int main()
{
    int x,y;
    cin>>x>>y;
    fill(&graph[0][0], &graph[0][0]+509*509,9999);
    for(int i=1;i<=y;i++)
    {
      for(int j=1;j<=x;j++)
      {
          cin>>graph[i][j];
      }
    }
    int ans_sum=0;
    for(int i=1;i<=y;i++)
    {
        for(int j=1;j<=x;j++)
        {
            if(visited[i][j]==false)
            {
                dfs(graph[i][j],i,j);

                if(flag==true)
                {
                    ans=0;
                }

                ans_sum+=ans;
                flag=false;
                ans=0;
            }
        }
    }
    cout<<ans_sum<<endl;
}
