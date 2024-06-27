#include<iostream>
#include<vector>
#include<queue>
using namespace std;



int dx[] = { 0, -1, 0, 1 };
int dy[] = { 1, 0, -1, 0};

vector<vector<int>> positive{ {-1,0,1}, {0, 1}, {0, -1} };

int n, t;
int check[101][101];
vector<vector<int>> arr;

struct pp
{
    int x;
    int y;
    int dir;
    int time;
};

void gogo(int x, int y, int time, int dir)
{

    int sinho_number = arr[x * n + y][time];

    int sinho_posi = sinho_number / 4;
    int sinho_dir = sinho_number % 4;
    check[x][y] = 1;
    queue<pp> q;

    if (sinho_dir != dir) return;
    else
    {
        for (int i = 0; i < positive[sinho_posi].size(); i++)
        {
            int new_dir = (dir + positive[sinho_posi][i] + 4) % 4;
            //cout << new_dir <<"\n";
            // 이동할수 있나?
            int nx = x + dx[new_dir];
            int ny = y + dy[new_dir];

            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;

            check[nx][ny] = 1;
            q.push({ nx,ny,new_dir, time + 1 });

            //cout << nx << " "<< ny << " " << new_dir <<"\n";
        }
    }

    while (!q.empty())
    {
        int ux = q.front().x;
        int uy = q.front().y;
        int dir = q.front().dir;
        int new_time = q.front().time;

        q.pop();
        //cout << ux * n + uy <<"\n";
        //cout <<time % 4<<"\n";
        //cout << arr[ux * n + uy][time % 4] % 4 <<"\n";

        if (new_time >= t) continue;
        if (dir != arr[ux * n + uy][new_time % 4] % 4) continue;

        int new_sin = arr[ux * n + uy][new_time % 4] / 4;
        //cout <<new_sin <<"\n";

        for (int i = 0; i < positive[new_sin].size(); i++)
        {
            int new_dir = (dir + positive[new_sin][i] + 4) % 4;

            int nx = ux + dx[new_dir];
            int ny = uy + dy[new_dir];

            if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;

            check[nx][ny] = 1;
            q.push({ nx,ny,new_dir, new_time + 1 });
        }
    }

}

int main(int argc, char** argv)
{
    cin >> n >> t;

    arr.resize(n * n);
    for (int i = 0; i < n * n; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int a; cin >> a;
            arr[i].push_back(a - 1);
        }
    }

    gogo(0, 0, 0, 1);

    int ret = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (check[i][j] == 1)
            {
                //cout << i << " " << j << "\n";
                ret++;
            }
        }
    }
    cout << ret;
    return 0;
}