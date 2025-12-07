#include<bits/stdc++.h>

using namespace std;

int main()
{
  int n,m;
  cin>>n>>m;
  vector<vector<int>> work;
  for(int i=0;i<n;i++)
  {
    vector<int> first;
    for(int j=0;j<m;j++)
    {
      int num;
      cin>>num;
      first.push_back(num);
    }
    work.push_back(first);
  }

  int can_work_time[m];
  fill(can_work_time+0,can_work_time+m,0);
  for(int i=0;i<n;i++)
  {
    int ans;
    int last_work=0;
    for(int j=0;j<m;j++)
    {
      int start_time=max(last_work,can_work_time[j]);
      int end_time=start_time+work[i][j];
      last_work=end_time;
      can_work_time[j]=end_time;
      ans=end_time;
    }
    cout<<ans<<" ";
  }
  return 0;
}
