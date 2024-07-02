#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct pp 
{
    int a;
    int b;
    int c;
    int d;
    int e;
};
int n;

int g_a,g_b,g_c,g_d;

vector<pp> arr;
vector<int> number;
vector<int> ret_arr;
int ret = 1e9;

int checking()
{
    int sum_a = 0;
    int sum_b = 0;
    int sum_c = 0;
    int sum_d = 0;
    int sum_e = 0;

    for(int i=0; i<number.size(); i++)
    {
        sum_a += arr[number[i]].a;
        sum_b += arr[number[i]].b;
        sum_c += arr[number[i]].c;
        sum_d += arr[number[i]].d;
        sum_e += arr[number[i]].e;
    }

    if(sum_a >= g_a &&
       sum_b >= g_b &&
       sum_c >= g_c &&
       sum_d >= g_d)
    {
        return sum_e;
    }
    else
    {
        return -1;
    }
}

void gogo(int x)
{

    if(x >= n + 1)
    {
        int sum = checking();
        if(sum != -1)
        {
            if(ret > sum)
            {
                ret = sum;
                ret_arr = number;
            }
            // else if(ret == sum )
            // {
            //     if(number.size() > ret_arr.size()) return;
            //     else if(number.size() < ret_arr.size())
            //     {
            //         ret_arr = number;
            //     }
            //     else
            //     {
            //         sort(ret_arr.begin(),ret_arr.end());
            //         sort(number.begin(), number.end());

            //         for(int i=0; i<number.size(); i++)
            //         {
            //             if(ret_arr[i] > number[i])
            //             {
            //                 ret_arr = number;
            //                 break;
            //             }
            //             else if(ret_arr[i] < number[i])
            //             {
            //                 break;
            //             }
            //         }
            //     }
            // }
        }
        return ;
    }


    number.push_back(x);
    gogo(x + 1);
    number.pop_back();
    gogo(x + 1);

}

int main()
{
    cin>>n;
    cin>> g_a >> g_b>>g_c >> g_d; 


    arr.push_back({0,0,0,0,0});
    for(int i=0; i<n; i++)
    {
        int a,b,c,d,e;
        cin>> a>> b>> c>>d>>e;
        arr.push_back({a,b,c,d,e});
    }

    gogo(1);

    if(ret == 1e9)
    {
        cout << -1 <<"\n";
    }
    else 
    {
        cout << ret <<"\n";
        sort(ret_arr.begin(), ret_arr.end());
        for(int i=0; i<ret_arr.size(); i++)
        {
           cout << ret_arr[i]  <<" ";
        }
    }
}