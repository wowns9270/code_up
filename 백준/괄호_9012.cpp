#include<iostream>
#include<stack>


using namespace std;

int main()
{
    int n; cin>> n;

    while(n--)
    {
        string k; cin>>k;
        stack<char> st;

        for(int i=0; i<k.size(); i++)
        {
            if(k[i] == '(')
            {
                st.push(k[i]);
            }
            else
            {
                if(!st.empty() && st.top() == '(')
                {
                    st.pop();

                }
                else
                {
                    st.push(k[i]);
                } 
            }
        }

        if(st.empty()) cout <<"YES" <<"\n";
        else cout <<"NO" <<"\n";
    }


}