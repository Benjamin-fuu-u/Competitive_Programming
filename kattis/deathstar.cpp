#include<bits/stdc++.h>

using namespace std;

int main()
{
  int k;
  cin>>k;
  vector<vector<int>> paper;
  for(int i=0;i<k;i++)
  {
    vector<int> use;
    for(int j=0;j<k;j++)
    {
      int num;
      cin>>num;
      use.push_back(num);
    }
    paper.push_back(use);

  }
  int answer[1000];
  fill(answer,answer+1000,0);
  for(int i=0;i<k;i++)
  {
    for(int j=0;j<k;j++)
    {
      if(i!=j)
      {
        answer[i] = answer[i] | paper[i][j];
      }
    }
  }

  for(int i=0;i<k;i++)
  {
    cout<<answer[i]<<" ";
  }
}
