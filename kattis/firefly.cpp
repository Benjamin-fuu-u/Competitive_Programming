#include<bits/stdc++.h>

using namespace std;

int bottom[500001];
int top[500001];

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n , h;
  cin>>n>>h;
  for(int i=1;i<=n;i++)
  {
    int num;
    cin>>num;
    if(i%2 == 1)
    {
      bottom[num]++;
    }
    else
    {
      top[num]++;
    }
  }

  for(int i=h-1;i>=0;i--)
  {
    bottom[i] += bottom[i+1];
    top[i] += top[i+1];
  }


  //cout<<"a"<<endl;
  int ans = 1e9;
  int level = 0;

  for(int i=1;i<=h;i++)
  {
    //cout<<bottom[i] + top[h - i + 1]<<" "<<ans<<endl;
    if(bottom[i] + top[h - i + 1] < ans)
    {
      ans = bottom[i] + top[h - i + 1];
      level = 1;
    }
    else if(bottom[i] + top[h - i + 1] == ans)
    {
      level++;
    }
  }
  cout<<ans<<" "<<level;
  return 0;
}
