#include<bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int r,c;
  cin>>r>>c;
  vector<vector<char>> dance;
  for(int i=0;i<r;i++)
  {
    vector<char> row;
    for(int j=0;j<c;j++)
    {
      char now;
      cin>>now;
      row.push_back(now);
    }
    dance.push_back(row);
  }

  int ans=0;

  for(int i=0;i<c;i++)
  {
    bool flag = false;
    for(int j=0;j<r;j++)
    {
      if(dance[j][i]=='$')
      {
        flag=true;
      }
    }

    if(flag==false)
    {
      ans++;
    }
  }
  ans++;
  cout<<ans;
}
