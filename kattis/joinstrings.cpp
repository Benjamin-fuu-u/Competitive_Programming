#include<bits/stdc++.h>

using namespace std;

void print_answer(vector<vector<int>>& connect , vector<string>& word,int now)
{
  cout<<word[now];
  for(int i : connect[now])   //in fact each connect[now] only have one value or no value , but this use can be more good
  {
    print_answer(connect,word,i);
  }
  return ;
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int k;
  cin>>k;
  vector<string> word(k);
  for(int i=0;i<k;i++)
  {
    string s;
    cin>>s;
    word[i] = s;
  }

  int a,b;
  vector<vector<int>> connect;
  connect.assign(k,vector<int>());
  while(cin>>a>>b)
  {
    a--;
    b--;
    connect[a].push_back(b);
  }
  print_answer(connect,word,a);
  return 0;
}
