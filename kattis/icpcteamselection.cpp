#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long int test;
    cin>>test;
    for(long long int i=0;i<test;i++)
    {
        long long int k;
        cin>>k;
        vector<long long int> score;
        for(long long int j=0;j<3*k;j++)
        {
            long long int num;
            cin>>num;
            score.push_back(num);
        }
        sort(score.begin() , score.end());

        long long int ans = 0;

        bool choose[301];
        for(long long int j=0;j<301;j++)
        {
            choose[j] = false;
        }


        for(long long int j=3*k - 2 , e =0 ; j > 0 ; j-=2 , e++)
        {
            choose[e] = true;
            if(choose[j] == true)
            {
                break;
            }
            ans+= score[j];
        }

        cout<<ans<<"\n";
    }

}
