#include<bits/stdc++.h>
using namespace std;

struct pp {vector<int> llist;};

pp arr[4][3][3][3];
int score[500001];
vector<int> ret_list;


vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;

    for (int i = 0; i < info.size(); i++) {
        int a, b, c, d;
        if (info[i][0] == 'j') a = 2;
        else if (info[i][0] == 'c') a = 1;
        else if (info[i][0] == 'p') a = 3;

        string cnt = "";
        for (int j = 1; j < info[i].size(); j++) {

            if (info[i][j] == ' ') {
                if (info[i][j + 1] == 'b') b = 1;
                if (info[i][j + 1] == 'f') b = 2;
                if (info[i][j + 1] == 'j') c = 1;
                if (info[i][j + 1] == 's') c = 2;
                if (info[i][j + 1] == 'c') d = 1;
                if (info[i][j + 1] == 'p') d = 2;

            }

            if (info[i][j] >= '0' && info[i][j] <= '9') {
                cnt += info[i][j];
            }
        }
        score[i] = atoi(cnt.c_str());


        for (int k1 : {0, a}) {
            for (int k2 : {0, b}) {
                for (int k3 : {0, c}) {
                    for (int k4 : {0, d}) {
                        arr[k1][k2][k3][k4].llist.push_back(score[i]);
                    }
                }
            }
        }
    }

    for (int i = 0; i < query.size(); i++) {

        int a, b, c, d, scoree, sink = 0;
        if (query[i][0] == 'j') a = 2;
        else if (query[i][0] == 'c') a = 1;
        else if (query[i][0] == 'p') a = 3;
        else if (query[i][0] == '-') a = 0;

        string cnt = "";
        for (int j = 1; j < query[i].size(); j++) {

            if (query[i][j] == ' ') {
                if (query[i][j + 1] == 'b') b = 1;
                if (query[i][j + 1] == 'f') b = 2;
                if (query[i][j + 1] == 'j') c = 1;
                if (query[i][j + 1] == 's') c = 2;
                if (query[i][j + 1] == 'c') d = 1;
                if (query[i][j + 1] == 'p') d = 2;
                if (query[i][j + 1] == 'a') sink++;
            }

            if (query[i][j] == '-' && sink == 1) b = 0;
            if (query[i][j] == '-' && sink == 2) c = 0;
            if (query[i][j] == '-' && sink == 3) d = 0;

            if (query[i][j] >= '0' && query[i][j] <= '9') {
                cnt += query[i][j];
            }
        }
        scoree = atoi(cnt.c_str());
        int ret = 0;

        for (int j = 0; j < arr[a][b][c][d].llist.size(); j++) {
            int k = arr[a][b][c][d].llist[j];
            if (scoree <= k) {
                ret++;
            }
        }

        ret_list.push_back(ret);
    }
    return ret_list;
}