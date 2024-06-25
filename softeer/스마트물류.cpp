#include<iostream>
#include<string>


using namespace std;
int n, k;
int check[200001];

int main(int argc, char** argv)
{
    cin >> n >> k;

    string str; cin >> str;

    int ret = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == 'H') continue;

        for (int j = i - k; j <= i + k; j++)
        {
            if (j < 0 || j > n) continue;

            if (str[j] == 'H' && check[j] == false)
            {
                check[j] = true;
                ret++;
                break;
            }
        }
    }

    cout << ret;






















}