#include <bits/stdc++.h>

using namespace std;
bool internet_check[200001];
bool visited[200001];
map<int, vector<int>> internet;
void dfs(int now)
{
    internet_check[now]=true;
    for(int i=0;i<internet[now].size();i++)
    {
        if(visited[internet[now][i]]==false)
        {
            visited[internet[now][i]]=true;
            dfs(internet[now][i]);
        }
    }
}

int main()
{
    int house,internet_line;
    cin>>house>>internet_line;

    memset(internet_check ,0 ,sizeof(internet_check));

    for(int i=0;i<internet_line;i++)
    {
        int connect_1,connect_2;
        cin>>connect_1>>connect_2;
        internet[connect_1].push_back(connect_2);
        internet[connect_2].push_back(connect_1);
    }
    visited[1]=true;
    dfs(1);
    bool check=false;
    for(int j=1;j<=house;j++)
    {
        if(internet_check[j]==false)
        {
            check=true;
            cout<<j<<endl;
        }
    }
    if(check==false)
    {
        cout<<"Connected"<<endl;
    }
    return 0;
}
