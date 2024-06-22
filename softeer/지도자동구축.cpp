#include<iostream>


using namespace std;

int arr[16];

int main(int argc, char** argv)
{
    arr[0] = 2;

    int n; cin >> n;

    for (int i = 1; i <= n; i++)
    {
        arr[i] = (arr[i - 1] + (arr[i - 1] - 1));
    }

    cout << arr[n] * arr[n];

}