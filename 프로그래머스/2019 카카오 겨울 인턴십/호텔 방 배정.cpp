#include<bits/stdc++.h>
using namespace std;


//���
int parent[200001];
long long candi[200001];
map<long long, int> q;

int find(int x) {

    if (x == parent[x]) return x;

    int y = find(parent[x]);

    parent[x] = y;

    return y;


}


//�ڿ����� �θ� �տ���
void uunion(int x, int y) {

    x = find(x);
    y = find(y);

    if (x == y) return;

    parent[y] = x;

    return;
}


vector<long long> solution(long long k, vector<long long> room_number) {
    vector<long long> kkkk;


    for (int i = 0; i <= room_number.size(); i++) {
        parent[i] = i;
    }

    map<long long, int>::iterator it;

    for (int i = 0; i < room_number.size(); i++) {

        long long k333 = room_number[i];

        if (q.find(k333) == q.end()) {
            q[k333] = i;
            kkkk.push_back(k333);
            candi[i] = k333;
            //�ְ��� �翷���� �����ϴ��� �ƴ��� Ȯ��

            if (q.find(k333 - 1) != q.end()) {
                uunion(i, q[k333 - 1]);
            }

            if (q.find(k333 + 1) != q.end()) {
                uunion(q[k333 + 1], i);
            }
        }
        else {
            int temp = find(q[k333]);

            q[candi[temp] + 1] = i;
            kkkk.push_back(candi[temp] + 1);

            candi[i] = candi[temp] + 1;

            if (q.find(candi[temp] + 1 - 1) != q.end()) {
                uunion(i, q[candi[temp] + 1 - 1]);
            }

            if (q.find(candi[temp] + 1 + 1) != q.end()) {
                uunion(q[candi[temp] + 1 + 1], i);
            }
        }
    }

    return kkkk;
}
//
//int main() {
//    vector<long long > temp22 = solution(10, { 1,3,4,1,3,1 });
//    return 0;
//}
