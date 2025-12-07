#include<bits/stdc++.h>

using namespace std;

char graph[10][10];

int Max = 0;
int counter = 0;
bool visited[10][10];

void back_tracking(int x , int y )
{
    //cout<<x<<" "<<y<<endl;
    Max = max(Max , counter);
   int dx[4] = {1 , 1 , -1 , -1};
   int dy[4] = {1 , -1 , -1 , 1};
   int dx1[4] = {2 , 2, -2 , -2};
   int dy1[4] = {2 , -2 , -2 , 2};
   for(int i=0;i<4;i++)
   {
       //cout<<x + dx1[i] <<" "<<x + dx1[i]<<" "<<y + dy1[i] <<" "<<y + dy1[i]<<endl;
       if(x + dx1[i] > 9 || x + dx1[i] < 0 || y + dy1[i] > 9 || y + dy1[i] < 0)
       {
           continue;
       }
       //cout<<graph[y + dy[i]][x + dx[i]]<<endl;
        //cout<<graph[y + dy1[i]][x + dx1[i]]<<" "<<x+dx1[i]<<" "<<y+dy1[i]<<endl;
        if(graph[y + dy[i]][x + dx[i]] == 'B' && visited[y + dy[i]][x + dx[i]] == false && graph[y + dy1[i]][x + dx1[i]] == '#')
        {
            //visited[y + dy[i]][x + dx[i]] = true;

            graph[y + dy[i]][x + dx[i]] ='#';
            counter++;
            back_tracking(x + dx1[i] , y + dy1[i]);
            graph[y + dy[i]][x + dx[i]] ='B';
            counter--;
        }
    }
}



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    vector<pair<int , int>> white_space;
    for(int i=0;i<t;i++)
    {
        Max = 0;
        white_space.clear();
        for(int j=0;j<10;j++)
        {
            for(int k=0;k<10;k++)
            {
                visited[j][k] = false;
            }
        }
        for(int j=0;j<10;j++)
        {
            string s;
            cin>>s;
            for(int k=0;k<10;k++)
            {
                graph[j][k] = s[k];
                if(s[k] == 'W')
                {
                    white_space.push_back(make_pair(k , j));
                    //cout<<k<<" "<<j<<endl;
                }
            }
        }


        for(int j = 0;j<white_space.size();j++)
        {
            counter = 0;
            graph[white_space[j].second][white_space[j].first] = '#';
            back_tracking(white_space[j].first , white_space[j].second);
            graph[white_space[j].second][white_space[j].first] = 'W';
        }

        cout<<Max<<"\n";
    }
    return 0;
}
