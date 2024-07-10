#include<iostream>
#include<string>
#include<vector>
#include<deque>
using namespace std;

int main()
{
    int test; cin >> test;

    while (test--)
    {
        string str; cin >> str;

        int n; cin >> n;

        string s; cin >> s;

        string tmp = "";
        deque<int> arr;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '[') continue;
            else if (s[i] == ',' || s[i] == ']')
            {
                if (tmp == "") continue;
                int num = atoi(tmp.c_str());
                arr.push_back(num);
                tmp = "";
            }
            else
            {
                tmp += s[i];
            }
        }

        int flag = 0;
        int err_flag = false;

        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == 'R')
            {
                flag ^= 1;
            }
            else if (str[i] == 'D')
            {
                if (arr.size() <= 0)
                {
                    err_flag = true;
                    break;
                }
                if (flag == 0) arr.pop_front();
                else arr.pop_back();
            }
        }

        if (err_flag == true)
        {
            cout << "error\n";
            continue;
        }

        cout << '[';
        if (flag == 0)
        {
            if (arr.size() > 0)
            {
                for (int i = 0; i < arr.size(); i++)
                {
                    if (i == arr.size() - 1)
                    {
                        cout << arr[i];
                    }
                    else
                        cout << arr[i] << ",";
                }
            }
        }
        else
        {
            if (arr.size() > 0)
            {
                for (int i = arr.size() -1; i >= 0; i--)
                {
                    if (i == 0) cout << arr[i];
                    else cout << arr[i] << ",";
                }
            }
        }


        cout << "]\n";
    }
}