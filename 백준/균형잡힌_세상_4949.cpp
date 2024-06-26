#include<iostream>
#include<stack>
#include<string>
using namespace std;

int main()
{
    while(1)
    {
        string n; 

        int cnt = 0;
        while(1)
        {
            string k; cin>> k;

            if(cnt == 0 && k.size() ==0 && k[0] =='.') return 0;
            

            n = n + k;
            cnt++;
            if(k[k.size() - 1 ] == '.') break;
        }
       

        if(n.size() == 1 && n[0] == '.') break;




        stack<char>st;

        for(int i=0; i<n.size(); i++)
        {
            if(n[i] == '[') st.push(n[i]);
            else if(n[i] == '(') st.push(n[i]);
            else if(n[i] == ']')
            {
                if(!st.empty() && st.top() == '[')
                {
                     st.pop();
                } 
                else st.push(n[i]);
            }
            else if(n[i] == ')')
            {
                if(!st.empty() && st.top() == '(')
                {
                   st.pop(); 
                } 
                else st.push(n[i]);
            }
        }


        if(st.empty()) cout <<"yes\n";
        else cout <<"no\n";
    }
}