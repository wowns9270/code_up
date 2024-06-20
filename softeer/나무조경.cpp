#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int arr[5][5];
int check[5][5];
int n, ret;
vector<int> ans;

void gogo(int x, int y, int cnt)
{
    if (x < 0 || y < 0 || x >= n || y >= n) return;

    if (cnt == 4)
    {
        int sum = 0;
        for (int i = 0; i < ans.size(); i++)
        {
            sum += ans[i];
        }
        ret = max(ret, sum);
    }

    
    if (check[x][y] == 1)
    {
        //이미 체크되어있는 경우, 다음 섹션 이동

        int ny = (y + 1) % n;
        int nx = x + ((y + 1) / n);

        gogo(nx, ny, cnt);
    }
    else
    {
        // 가로 선택
        // 현재에서 선택할 수 있으면 선택 후 다음 
        int kx = x + ((y + 1) / n);
        int ky = (y + 1) % n;

        int ny = y + 1;
        int nx = x ;

        if (ny < n && check[nx][ny] == 0)
        {
            check[x][y] = 1;
            check[nx][ny] = 1;
            ans.push_back(arr[x][y] + arr[nx][ny]);
            gogo(kx, ky, cnt + 1);
            check[x][y] = 0;
            check[nx][ny] = 0;
            ans.pop_back();
        }

        int ux = x + 1;
        int uy = y;

        if (ux < n && check[ux][uy] == 0)
        {
            check[x][y] = 1; 
            check[ux][uy] = 1;
            ans.push_back(arr[x][y] + arr[ux][uy]);
            gogo(kx, ky, cnt + 1);
            check[x][y] = 0;
            check[ux][uy] = 0;
            ans.pop_back();
        }


        gogo(kx, ky, cnt);
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    if (n == 2)
    {
        int ret = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                ret += arr[i][j];
            }
        }
        cout << ret;
    }
    else
    {
        gogo(0, 0, 0);

        cout << ret;
    }
}