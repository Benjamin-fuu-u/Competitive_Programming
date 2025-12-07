#include<bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        int n;
        cin>>n;

        priority_queue<int> buy;
        priority_queue<int , vector<int> ,  greater<int>> sell;
        int last = 0;
        bool ever = false;

        for(int j=0;j<n;j++)
        {
            int shares , prices;
            string b , type , a;
            cin>>type>>shares>>a>>b>>prices;

            if(type == "buy")
            {
                for(int k=0;k<shares;k++)
                {
                    buy.push(prices);
                }
            }
            else if(type == "sell")
            {
                for(int k=0;k<shares;k++)
                {
                    sell.push(prices);
                }
            }


            bool f = false;
            while(true)
            {
                if(!buy.empty() && !sell.empty()  && buy.top() >= sell.top())
                {
                    last = sell.top();
                    sell.pop();
                    buy.pop();
                    f = true;
                    ever = true;
                }
                else
                {
                    break;
                }
            }

            if(!sell.empty())   cout<<sell.top()<<" ";
            else    cout<<"- ";

            if(!buy.empty()) cout<<buy.top()<<" ";
            else cout<<"- ";

            if(f == true || ever == true)
            {
                cout<<last<<"\n";
            }

            else
            {
                cout<<"-\n";
            }
        }


    }
    return 0;
}
