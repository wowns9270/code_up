#include<iostream>
using namespace std;

int main() {



	while (1)
	{
		string k; cin >> k;
		if (k == "end") break;


		bool check1 = false;
		bool check2 = true;
		bool check3 = true;
		
		int visit[21];
		for (int i = 0; i < 21; i++) {
			visit[i] = 0;
		}

		for (int i = 0; i < k.size(); i++)
		{
			if (k[i] == 'a' || k[i] == 'e' || k[i] == 'i' || k[i] == 'o' ||
				k[i] == 'u') {
				check1 = true;
				visit[i] = 1;
			}
		}

		for (int i = 0; i < static_cast<int>(k.size()) - 2; i++)
		{

			if (visit[i] == visit[i + 1] && visit[i + 1] == visit[i + 2])
			{
				check2 = false;
				break;
			}
		}

		for (int i = 0; i < static_cast<int>(k.size()) - 1; i++) {

			if (k[i] == k[i + 1]) {

				if ( (k[i] != 'e') && (k[i] != 'o'))
				{
					check3 = false;
					break;
				}

			}
		}

		if (check1 == true && check2 == true && check3 == true)
		{
			cout << "<" << k << ">" << " is acceptable.\n";
		}
		else
		{
			cout << "<" << k << ">" << " is not acceptable.\n";
		}
	}
}