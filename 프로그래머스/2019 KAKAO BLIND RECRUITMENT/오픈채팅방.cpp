#include<bits/stdc++.h>

using namespace std;

struct pp {

    string p_id;
    int check;

};

vector<pp> arr;

map<string, string> llist;


int second_in(string k) {
    int cnt = 0;
    for (int i = 0; i < k.size(); i++) {
        if (k[i] == ' ') {
            cnt++;

            if (cnt == 2) {
                return i;
            }
        }
    }
}


vector<string> solution(vector<string> record) {
    vector<string> answer;



    for (int i = 0; i < record.size(); i++) {

        if (record[i][0] == 'E') {
            int idx = second_in(record[i]);

            string k = record[i].substr(6, idx - 7 + 1);
            string k2 = record[i].substr(idx + 1, record[i].size() - idx);

            llist[k] = k2;
            arr.push_back({ k , 1 });
        }
        else if (record[i][0] == 'L') {
            int idx = second_in(record[i]);

            string k = record[i].substr(6, idx - 7 + 1);

             arr.push_back({ k , 2 });
        }
        else {
            int idx = second_in(record[i]);

            string k = record[i].substr(7, idx - 8 + 1);
            string k2 = record[i].substr(idx + 1, record[i].size() - idx);

            llist[k] = k2;
        }
    }

    for (int i = 0; i < arr.size(); i++) {

        string k = arr[i].p_id;

        int check = arr[i].check;

        string temp = "";
        temp += llist[k];
        temp += "님이 ";

        if (check == 1) {
            temp += "들어왔습니다.";
        }
        else {
            temp += "나갔습니다.";
        }
        answer.push_back(temp);
    }


    return answer;
}