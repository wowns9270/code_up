#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<char> compare;
vector<int> big;
vector<int> small;

//���� �ε�ȣ 2529
//���Ʈ ���� ������ ������ �̿��� �����̴�.


//���ǿ� �������� Ȯ���ϴ� �Լ� true��false�� �ǹ̻� �Ųܷ�����
//���ǿ� ���� �� �ε�ȣ�� �´ٸ� false�� ��ȯ�Ѵ�.
bool check_cc(vector<int>& arr) {
	for (int i = 0; i < compare.size(); i++) {
		if (compare[i] == '<') {
			if (arr[i] >= arr[i + 1]) return true;
		}
		else if (compare[i] == '>') {
			if (arr[i] <= arr[i + 1]) return true;
		}
	}

	return false;
}

void small_brouteforce() {

	while (1) {
		//small�� �ݴ�� �ε�ȣ�� �������� ������ ���� ������ �ҷ��´�.
		// 123 �� �������� ������ ���� ������  132
		if (check_cc(small) == true)
			next_permutation(small.begin(), small.end());
		else {
			for (int i = 0; i < big.size(); i++) {
				cout << small[i];
			}
			cout << "\n";
			break;
		}

	}
}


//���� ū ���� ���ϴ� �Լ� �� �Լ��� ���� ������
//prev_permutation �� next_permutation�� �ٸ��� �����̴�.
void big_brouteforce() {

	while (1) {
		//true�̸� �ε�ȣ�� �������� �����Ƿ�
		//���� ������ �θ��� 987 �̶�� ���� ������ 978 �� ȣ���Ѵ�.
		if (check_cc(big) == true)
			prev_permutation(big.begin(), big.end());
		else {
			//else�� ������ ���ݱ��� ������ ���� ū���� �����ϹǷ�
			//���� �̾��ְ� �Լ��� �������´�.
			for (int i = 0; i < big.size(); i++) {
				cout << big[i];
			}
			cout << "\n";
			break;
		}

	}
}

int main() {
	int n; cin >> n;

	//��Һ� ���ڵ��� ���Ϳ� ������� �߰��Ѵ�.
	for (int i = 0; i < n; i++) {
		char c; cin >> c;
		compare.push_back(c);
	}
	//���ǿ��� ���õǴ� ���ڴ� ��� �޶�� �ϱ⿡
	//���� ū ���� �� 3����� 987 ���� 3�� 4����� 9876 ���ڵ�� �����Ȱ���
	//���� ū ���� ���� ���ִ� ���� �������� �ݴ��̴� 012 0123
	for (int i = 0; i < n + 1; i++) {
		big.push_back(9 - i);
		small.push_back(i);
	}
	//���ǿ� �����ϴ� ���� ū ���� �������� ã�´�,
	big_brouteforce();
	small_brouteforce();
	return 0;

}