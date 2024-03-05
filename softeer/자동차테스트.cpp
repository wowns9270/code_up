#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int n, q;
std::vector<int> arr;

int ret = 0;

int main(int argc, char** argv)
{

    cin >> n >> q;

    for (int i = 0; i < n; i++)
    {
        int a; cin >> a;
        arr.push_back(a);
    }
    sort(arr.begin(), arr.end());

    for (int i = 0; i < q; i++)
    {
        int a; cin >> a;
        ret = -1;
        //gogo(0, n - 1, a);


        int st = 0;
        int ed = n - 1;
        while (st <= ed)
        {
            int mid = (st + ed) / 2;
            if (arr[mid] > a)
            {
                ed = mid - 1; 
            }
            else if (arr[mid] < a)
            {
                st = mid + 1;
            }
            else
            {
                ret = mid;
                break;
            }
        }


        if (ret == -1)
        {
            cout << "0" << endl;
        }
        else
        {
            cout << ret * ((n - 1) - (ret + 1) + 1) << endl;
        }
    }


    return 0;
}