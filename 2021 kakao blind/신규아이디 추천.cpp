#include <string>
#include <vector>

using namespace std;

string session1(string k) {

    for (int i = 0; i < k.size(); i++) {

        if (k[i] <= 'Z' && k[i] >= 'A') {

            k[i] = k[i] - 'A' + 'a';
        }
    }
    return k;
}

string session2(string k) {

    for (int i = 0; i < k.size(); i++) {

        if ((k[i] <= 'z' && k[i] >= 'a') ||
            (k[i] >= '0' && k[i] <= '9') ||
            k[i] == '-' || k[i] == '_' || k[i] == '.') {
            continue;
        }
        else {
            k.erase(k.begin() + i, k.begin() + i + 1);
            i--;
        }
    }
    return k;
}

string session3(string k) {


    for (int i = 0; i < k.size(); i++) {

        if (k[i] == '.') {
            int cnt = 1;
            int j = i;
            while (1) {

                if (k[++j] != '.') break;
                cnt++;
            }

            if (cnt >= 2) {
                k.erase(k.begin() + i+1, k.begin() + i + cnt); 
            }
        }
    }
    return k;
}


string session4(string k) {

    if (k[0] == '.') {
        k.erase(k.begin(), k.begin() + 1);
    }

    if (k[k.size() - 1] == '.') {
        k.erase(k.begin() + k.size() - 1, k.begin() + k.size());
    }

    return k;
}

string session5(string k) {

    if (k == "") {
       return  k = "a";
    }
    else {
        return k;
    }
}

string session6(string k) {

    if (k.size() >= 16) {
        k.erase(k.begin() + 15, k.begin() + k.size());

        if (k[k.size() - 1] == '.') {
            k.erase(k.begin() + k.size() - 1, k.begin() + k.size());
        }

        return k;
    }
    else {
        return k;
    }
}

string session7(string k) {

    if (k.size() <= 2) {

        while (1) {
            if (k.size() == 3) break;
            k += k[k.size() - 1];
        }   

        return k;
    }
    else {
        return k;
    }
}

string solution(string new_id) {
   

    string k = session1(new_id);

    k = session2(k);

    k = session3(k);

    k = session4(k);

    k = session5(k);

    k = session6(k);

    k = session7(k);

    return k;


}

int main() {

    solution("...!@BaT#*..y.abcdefghijklm");
    return 0;
}