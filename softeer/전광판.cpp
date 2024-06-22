#include<iostream>
#include<string>
using namespace std;

int test;

int arr[11][7] =
{
    {1,1,1,0,1,1,1},
    {0,0,1,0,1,0,0},
    {0,1,1,1,0,1,1},
    {0,1,1,1,1,1,0},
    {1,0,1,1,1,0,0},
    {1,1,0,1,1,1,0},
    {1,1,0,1,1,1,1},
    {1,1,1,0,1,0,0},
    {1,1,1,1,1,1,1},
    {1,1,1,1,1,1,0},
    {0,0,0,0,0,0,0}
}; // Ç¥½Ã

int gogo(string a, string b)
{
    int cnt = 0;

    for (int i = 0; i < 5; i++)
    {
        if (a[i] == b[i]) continue;

        int a_i = 0;
        int b_i = 0;

        if (a[i] == 'a')
        {
            a_i = 10;
        }
        else
        {
            a_i = a[i] - '0';
        }

        if (b[i] == 'a')
        {
            b_i = 10;
        }
        else
        {
            b_i = b[i] - '0';
        }

        for (int j = 0; j < 7; j++)
        {
            if (arr[a_i][j] != arr[b_i][j]) {
                cnt++;
                //cout << a_i << " " << b_i << " " << j << "\n";
            }
        }
    }

    return cnt;
}


int main(int argc, char** argv)
{


    cin >> test;
    while (test--)
    {
        string a, b;
        cin >> a >> b;

        while (a.size() < 5)
        {
            a = 'a' + a;
        }

        while (b.size() < 5)
        {
            b = 'a' + b;
        }
        //cout << a << " " << b <<"\n";

        cout << gogo(a, b) << "\n";
    }


}