#include<bits/stdc++.h>

using namespace std;

map<int , vector<int>> choice;
vector<int> combination;

void back_tracking(int now , vector<int> v)
{
  if(v.size() == 3)
  {
    return;
  }

  for(int i=0;i<choice[now].size();i++)
  {
    v.push_back(choice[now][i]);
    string s;
    for(int j=0;j<v.size();j++)
    {
      s += (v[j] + '0');
    }
    combination.push_back(stoi(s));

    back_tracking(choice[now][i] , v);
    v.pop_back();
  }
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  choice[1] = {1 ,2 ,3 ,4 ,5 ,6 ,7 ,8 ,9 ,0};
  choice[2] = {2 ,3 ,5 ,6 ,8 ,9 ,0};
  choice[3] = {3 ,6 ,9};
  choice[4] = {4 ,5 ,6 ,7 ,8 ,9 ,0};
  choice[5] = {5 ,6 ,8 ,9 ,0};
  choice[6] = {6 ,9};
  choice[7] = {7 ,8 ,9 ,0};
  choice[8] = {8 ,9 ,0};
  choice[9] = {9};
  choice[0] = {0};

  vector<int> v;
  back_tracking(1 ,v);

  /*for(int i=0;i<combination.size();i++)
  {
    cout<<combination[i]<<endl;
  }*/

  int t;
  cin>>t;
  for(int i=0;i<t;i++)
  {
    int k;
    cin>>k;
    int Min = 1e9;
    for(int j=0;j<combination.size();j++)
    {
      if(abs(Min - k) > abs(combination[j] - k))
      {
        Min = combination[j];
      }
    }
    cout<<Min<<"\n";
  }
}
