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
������ ������
C++ 14	Pass	0.61009	20332	100	Code	�����	0	2020 - 02 - 28 04:01
������ ������
C++ 14	Fail	0.00835	20328	0	Code	�����	0	2020 - 02 - 28 03 : 57
������ ������
C++ 14	Fail	0.00954	20328	0	Code	�����	0	2020 - 02 - 28 03 : 54
������ ������
C++ 14	Fail	0.00924	20328	0	Code	�����	0	2020 - 02 - 28 03 : 43
����� �ſ�
C++ 14	Pass	0.16519	17412	100	Code	�����	0	2020 - 02 - 28 02 : 41
����� �ſ�
C++ 14	Pass	0.00596	12520	5	Code	�����	0	2020 - 02 - 28 02 : 40
������ �ٱ�
C++ 14	Pass	0.51185	16620	100	Code	�����	0	2020 - 02 - 28 01 : 46
������ �ٱ�
C++ 14	Pass	0.52905	16620	20	Code	�����	0	2020 - 02 - 28 01 : 43
���� ����
C++ 14	Pass	0.12371	14572	100	Code	�����	0	2020 - 02 - 28 00 : 01
���� ����
C++ 14	Pass	0.12728	14572	33	Code	�����	0	2020 - 02 - 27 23 : 57
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

int test, t_n = 1;
int dp[1000001];
int sum[1000001];
int main() {
	cin >> test;

	dp[1] = 0;
	dp[2] = 1;
	for (int i = 4; i <= 1000000; i += 2) {

		dp[i] = dp[i / 2] + 1;
		dp[i - 1] = dp[i] + 1;
	}
	sum[0] = 0;
	for (int i = 1; i <= 1000000; i++) {
		sum[i] = sum[i - 1] + dp[i];
	}



	while (test--) {
		int ret = 0;
		int a, b; cin >> a >> b;

		ret = sum[b] - sum[a - 1];


		cout << "Case #" << t_n++ << "\n";
		cout << ret << "\n";
	}
	return 0;
}