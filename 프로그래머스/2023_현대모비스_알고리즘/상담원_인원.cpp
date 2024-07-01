#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

void DFS(int sum, int k, vector<int> numbers, vector<vector<int>>& orders)
{
    if (k == 1)
    {
        numbers.push_back(sum);
        orders.push_back(numbers);
        return;
    }

    for (int i = 0; i <= sum; i++)
    {

        numbers.push_back(i);
        DFS(sum - i, k - 1, numbers, orders);
        numbers.pop_back();
    }

}

vector<vector<int>> get_order(int n, int k)
{
    int sum = n - k;

    vector<vector<int>> orders;

    vector<int>numbers;
    DFS(sum, k, numbers, orders);

    return orders;
}

int callTime(int stTime, int time, vector<int>& mt)
{

    int waitTime = 0;

    sort(mt.begin(), mt.end());

    if (stTime >= mt[0])
    {
        mt[0] = stTime + time;
    }
    else
    {
        waitTime = mt[0] - stTime;

        mt[0] = mt[0] + time;
    }

    return waitTime;
}

int solution(int k, int n, vector<vector<int>> reqs) {

    vector<vector<int>> order = get_order(n, k);

    int g_ret = 1e9;
    for (int i = 0; i < order.size(); i++) // 멘토 배치 순서
    {
        vector<vector<int>> mt(k);
        int ret = 0;

        for (int j = 0; j < order[i].size(); j++)
        {
            mt[j].resize(order[i][j] + 1, 0); // 순서 + 1 만큼 끝나는시간 설정
        }

        for (int k = 0; k < reqs.size(); k++)
        {
            int waitTime = callTime(reqs[k][0], reqs[k][1], mt[reqs[k][2] - 1]);
            ret += waitTime;
        }


        g_ret = min(g_ret, ret);
    }

    return g_ret; 
}

int main()
{
    cout << solution(3, 5, { {10, 60, 1},{15, 100, 3},{20, 30, 1},
        {30, 50, 3},{50, 40, 1},{60, 30, 2},{65, 30, 1},{70, 100, 2} });
}