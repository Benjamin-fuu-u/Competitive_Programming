#include<bits/stdc++.h>

using namespace std;

bool cmp(vector<char> a ,vector<char> b)
{
  for(int i=0;i<a.size();i++)
  {
    if(a[i]<97)
    {
      a[i]+=32;
    }
    if(b[i]<97)
    {
      b[i]+=32;
    }
    if(a[i]!=b[i])
    {
      return a[i]<b[i];
    }
    else
    {
      continue;
    }
  }
  return false;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int r,c;
  while(cin>>r>>c)
  {
    if(r==0 && c==0)
    {
      break;
    }
    char word[15][15];
    for(int i=0;i<r;i++)
    {
      for(int j=0;j<c;j++)
      {
        cin>>word[i][j];
      }
    }

    vector<vector<char>> be_sort;

    for(int i=0;i<c;i++)
    {
      vector<char> use;
      for(int j=0;j<r;j++)
      {
        use.push_back(word[j][i]);
      }
      be_sort.push_back(use);
    }

    stable_sort(be_sort.begin(),be_sort.end(),cmp);
    int length = be_sort[0].size();
    for(int i=0;i<length;i++)
    {
      for(int j=0;j<be_sort.size();j++)
      {
        cout<<be_sort[j][i];
      }
      cout<<"\n";
    }
    cout<<"\n";
  }
}
