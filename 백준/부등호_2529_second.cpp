#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int n; 
vector<char> arr;
vector<string> ret;
int check[10];

bool checking(string k)
{
    bool bret = true;
    for(int i=0; i<k.size() -1; i++)
    {
        char cur = k[i];
        char next = k[i+1];

        if(arr[i] == '<')
        {
            if( cur > next)
            {
                bret = false; break;
            }
        }
        else
        {
            if(cur < next)
            {
                bret = false; break;
            }
        }
    }
    return bret;
}

void gogo(int idx, string k)
{

    if(idx == n + 1)
    {
        if(checking(k))
        {
            ret.push_back(k);
        }
        return ;
    }

    for(int i=0; i<=9; i++)
    {
        if(check[i] == 0)
        {
            check[i] = 1; 
            k += ('0' + i);
            gogo(idx + 1, k );
            k.pop_back();
            check[i] = 0;
        }
    }


}

int main()
{
    cin>> n;

    for(int i=0; i<n; i++)
    {
        char c; cin>> c;
        arr.push_back(c);
    }
    string k ;
    gogo(0, k);

    sort(ret.begin(), ret.end());

    cout << ret[ret.size() -1] <<"\n";
    cout << ret[0] << "\n";
}