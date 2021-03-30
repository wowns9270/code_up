#include<bits/stdc++.h>

using namespace std;

map<string, int> arr;

vector<int> solution(string msg) {
    vector<int> answer;

    for (int i = 0; i < 26; i++) {
        string r = "";
        char a = 'A' + i;
        r += a;
        arr.insert(pair<string,int>(r, i + 1));
    }
    int idx = 27;

    for (int i = 0; i < msg.size(); i++ ) {

        string k = "";
        for (int j = i; j < msg.size(); j++) {
                
            k += msg[j];

            if( arr.find(k) == arr.end() ) {
               
                string k2 = k.substr(0, k.size() - 1);
                answer.push_back(arr[k2]);
                arr.insert(pair<string, int>(k, idx++));
                i = j - 1;
                break;
            }
            else {
                
                if (msg.size() - 1 == j) {
                    answer.push_back(arr[k]);
                    i = j;
                    break;
                }

                continue;
            }


        }
    }
    return answer;
}