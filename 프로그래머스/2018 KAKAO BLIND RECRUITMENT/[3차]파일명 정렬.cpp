#include<bits/stdc++.h>
using namespace std;

struct pp {
    string all;
    string head;
    int mid;
};


vector<pp> llist;

bool cmp(pp x, pp y) {

    if (x.head < y.head) {
        return true;
    }
    else if (x.head == y.head) {
        if (x.mid < y.mid) {
            return true;
        }
    }
    return false;
}


vector<string> solution(vector<string> files) {
    
    vector<string> answer;

    for (int i = 0; i < files.size(); i++) {

        string k = files[i];
        int idx = -1;
        int idx2 = -1;

        for (int j = 0; j < k.size(); j++) {

            if (k[j] >= '0' && k[j] <= '9') {
                idx = j;
                break;
            }
        }

        for (int j = idx; j < k.size(); j++) {

            if (k[j] < '0' || k[j] > '9') {
                idx2 = j;
                break;
            }
        }

        string a = k.substr(0, idx );

        for (int j = 0; j < a.size(); j++) {
            if (a[j] >= 'a' && a[j] <= 'z') {
                a[j] = a[j] - 'a' + 'A';
            }
        }

        int b = atoi(k.substr(idx, idx2 - 1).c_str());

        llist.push_back({ k , a ,b });
    }
    stable_sort(llist.begin(), llist.end(), cmp);

    for (int i = 0; i < llist.size(); i++) {
        answer.push_back(llist[i].all);
   }

    return answer;


}