#include<bits/stdc++.h>

using namespace std;

int line , skip;
vector<string> color;
vector<string> perfect;
map<string , vector<string>> avoid;
int counter = 0;

void back_tracking(int now , string last , vector<string> choice)
{
  //cout<<now<<" "<<last<<endl;


  vector<string> next = choice;

  for(auto c : choice)
  {
    if(find(avoid[last].begin() , avoid[last].end() , c) != avoid[last].end())
      continue;

    if(counter == 0)
    {
      perfect.push_back(c);
    }

    auto it = find(next.begin() , next.end() , c);
    next.erase(it);
    back_tracking(now+1 , c , next);
    if(counter == 0)
    {
      perfect.pop_back();
    }
    next.insert(it , c);
  }
  if(now == line)
  {
    counter++;
    return;
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
    cin>>line;
    counter = 0;
    color.clear();
    perfect.clear();
    avoid.clear();

    for(int j=0;j<line;j++)
    {
      string num;
      cin>>num;
      color.push_back(num);
    }

    cin>>skip;
    for(int j=0;j<skip;j++)
    {
      string num1 , num2;
      cin>>num1>>num2;
      avoid[num1].push_back(num2);
      avoid[num2].push_back(num1);
    }
    back_tracking(0 , "0" , color);
    cout<<counter<<"\n";
    for(auto c : perfect)
    {
      cout<<c<<" ";
    }
    cout<<"\n";
  }

}
