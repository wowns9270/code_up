CODEGROUND
KOR ENG���Ѵ� MyGround �α׾ƿ�
About
Practice
OpenRound
Community
SCPC
Home MyGround Practice
MyGround
Point

Practice

OpenRound

SCPC

My Info
������	���	���	����ð�	�޸�	����	�����ڵ�	��������	��õ��	�����Ͻ�
���α׷��� ������ȸ
C++ 14	Pass	0.3001	14576	100	Code	�����	0	2020 - 02 - 27 23:51
���α׷��� ������ȸ
C++ 14	Fail	0.28733	14576	0	Code	�����	0	2020 - 02 - 27 23 : 46
���α׷��� ������ȸ
C++ 14	Fail	0.2949	14576	0	Code	�����	0	2020 - 02 - 27 23 : 42
���α׷��� ������ȸ
C++ 14	Fail	0.2987	14576	0	Code	�����	0	2020 - 02 - 27 23 : 40
���α׷��� ������ȸ
C++ 14	Fail	0.29359	14576	0	Code	�����	0	2020 - 02 - 27 22 : 21
���� ��󳻱�
C++ 14	Pass	0.18215	17404	100	Code	�����	0	2020 - 02 - 27 21 : 35
���� ��󳻱�
C++ 14	Pass	0.1028	12520	50	Code	�����	0	2020 - 02 - 27 21 : 35
���� ��󳻱�
C++ 14	Pass	0.09954	12520	100	Code	�����	0	2020 - 02 - 27 21 : 34
���� ��󳻱�
C++ 14	Compile Error	0	0	0	Code	�����	0	2020 - 02 - 27 21 : 34
���� ��󳻱�
C++ 14	Pass	0.09906	12520	100	Code	�����	0	2020 - 02 - 27 21 : 34
Previous123Next
SAMSUNG
��������ó����ħ �̿��� �̸��Ϲ��ܼ����ź�
Google Chrome �������� �����մϴ�.(Internet Explorer 11 ����)
�� ����Ʈ�� �������� ���۱ǹ��� ��ȣ�� �޴¹�, ��������, ����, ���� ���� ���մϴ�.
Copyright�� 2015 - 2020 SAMSUNG ALL Rights Reserved.

Top �ٷΰ���
��
�����ڵ�
#include<bits/stdc++.h>
using namespace std;

int test, t_n = 1, ret;

int main() {
	cin >> test;

	while (test--) {
		ret = 0;
		int n; cin >> n;
		int max_ret = 0;
		vector<int> arr;
		for (int i = 0; i < n; i++) {
			int k; cin >> k;
			arr.push_back(k);
		}
		sort(arr.begin(), arr.end());


		for (int i = 0; i < n; i++) {
			max_ret = max(max_ret, arr[i] + n - i);
		}

		for (int i = 0; i < n; i++) {
			if (max_ret <= arr[i] + n) {
				ret++;
			}
		}


		cout << "Case #" << t_n++ << "\n";
		cout << ret << "\n";
	}
}