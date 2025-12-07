#include <bits/stdc++.h>

using namespace std;
bool reach[1001];
int Count=0;
map<int,vector<int>>road;

void dfs(int start)
{
    for(int i=0;i<road[start].size();i++)
    {
        if(reach[road[start][i]]==false)
        {
            reach[road[start][i]]=true;
            dfs(road[start][i]);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        fill(reach,reach+1001,false);
        road.clear();
        Count=0;

        int city,r;
        cin>>city>>r;
        for(int j=0;j<r;j++)
        {
            int x,y;
            cin>>x>>y;
            road[x].push_back(y);
            road[y].push_back(x);
        }

        for(int j=0;j<city;j++)
        {
            if(reach[j]==false)
            {
                reach[j]=true;
                dfs(j);
                Count++;
            }
        }
        cout<<Count-1<<"\n";
    }
    return 0;
}
