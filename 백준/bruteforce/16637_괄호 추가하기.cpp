#include<bits/stdc++.h>
using namespace std;
#define INF -1999999999

long long n,ret=INF;
string a;
vector<int>arr;

//��ٷο� ��������.
// �ϴ� ��ȣ�� �����ؼ� ���� �� �����Ƿ� 
// �װ� ����ó���ϴºκ� 
// �׸��� ��ȣ���� -�� ���� �� �־ ���� int �迭�� ����� �κ�
// �׸��� ��ȣ ����� �Ѱ��� x + 0 �� ��Ÿ �� �� �ִ� �κ�
// �������� Ǯ�� ���ߴ�.

int main() {
	 cin >> n >>a;
	 int k = n / 2; //k�� �������� ����
	 for (int i = 0; i < a.size(); i++) {
		 if (a[i] >= '0' && a[i] <= '9') {
			 arr.push_back(a[i] - '0');
		 }
		 else if (a[i] == '-') arr.push_back(1);
		 else if (a[i] == '+') arr.push_back(0);
		 else if(a[i] =='*')arr.push_back(2);
	 }
	 for (int i = 0; i < (1 << k); i++) { //��ȣ�� ġ�� ��� ���
		 vector<int> b(arr);
		bool check = true;
		 for (int j = 0; j < k-1; j++) { //�� �ڸ����� ���ڸ��� �ִ���
			 //��ȣ�� ��ġ�� �� �� �����ϱ�..
			 if (i & (1 << j)) { //j�ڸ��� Ȯ�� �տ��� Ȯ���� �ʿ� x
				 if (i & (1 << j + 1)) {//���ڸ��� ��ȣ�� �ȵȴ�.
					 check = false;
					 break;
				 }
			 }
		 }
		 if (check == false) continue; //�ٸ� ��츦 �˾ƺ���.
		 //�ϴܰ�ȣ�� ���°� �����ϸ� ��ȣ�� ó�����ش�.
		 for (int j = 0; j < k; j++) {
			 if (i & (1 << j)) {
				 if (b[2 * j + 1] == 0) {
					 b[2 * j] += b[2 * j + 2];
					 b[2 * j + 2] = 0;
				 }
				 else if (b[2 * j + 1] == 1) {
					 b[2 * j] -= b[2 * j + 2];
					 b[2 * j + 2] = 0;
					 b[2 * j + 1] = 0;
				 }
				 else if (b[2 * j + 1] == 2) {
					 b[2 * j] *= b[2 * j + 2];
					 b[2 * j + 2] = 0;
					 b[2 * j + 1] = 0;
				 }
			 }
		 }
		 long long sum =b[0];
		 for (int j = 2; j < n; j+=2) {
			 if (b[j - 1] == 0) {
				 sum += b[j];
			 }
			 else if (b[j - 1] == 1) {
				 sum -= b[j];
			 }
			 else sum *= b[j];
		 }
		 ret = max(ret, sum);
	 }

	 cout << ret;
	 return 0;
}