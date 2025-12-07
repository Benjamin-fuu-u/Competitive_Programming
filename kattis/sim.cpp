#include<bits/stdc++.h>

using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int k;
  cin>>k;
  cin.ignore();
  for(int i=0;i<k;i++)
  {
    list<char> screen;
    string word;
    auto it = screen.begin();
    getline(cin,word);
    for(int j=0;j<word.size();j++)
    {
      if(word[j]=='[')
      {
        it = screen.begin();
      }
      else if(word[j]==']')
      {
        it = screen.end();
      }
      else if(word[j]=='<')
      {
        if(screen.size()>0)
        {
          if(it !=screen.begin())
          {
            it--;
            it = screen.erase(it);
          }
        }

      }
      else
      {
        screen.insert(it,word[j]);
      }
    }

    it = screen.begin();
    while(it != screen.end())
    {
      cout<<*it;
      ++it;
    }
    cout<<"\n";
  }

  return 0;
}
