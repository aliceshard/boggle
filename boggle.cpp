#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <cstdlib>

#define BOG_LINE 5
#define BOG_SIZE 25

using namespace std;

int cache[10][5][5];
const int dx[8] = { -1, -1, -1, 1, 1, 1, 0, 0 };
const int dy[8] = { -1, 0, 1, -1, 0 ,1, -1, 1 };
vector<string> word;
vector<vector<char>> bog;

bool recursiveSearch(int y, int x, string word);
bool isRange(int y, int x);

int main(void) {
	// 1. boggle 갯수 입력
	int bogNum = 0;
	cin >> bogNum;

	for (int i = 0; i < bogNum; i++) {
		// 2. boggle table 입력 받음
		for (int j = 0; j < BOG_LINE; j++) {
			string inputLine;
			cin >> inputLine;
			vector<char> inputChar(inputLine.begin(), inputLine.end());

			bog.push_back(inputChar);
		}

		// 3. word 갯수 입력
		int wordNum = 0;
		cin >> wordNum;

		// 4. word 입력 받음
		for (int i = 0; i < wordNum; i++) {
			string inputLine;
			cin >> inputLine;

			word.push_back(inputLine);
		}

		// 5. 재귀 분석 시작.
		bool flag = false;

		for (int i = 0; i < wordNum; i++) {
			memset(cache, -1, sizeof(cache));
			for (int j = 0; j < BOG_LINE; j++) {
				for (int k = 0; k < BOG_LINE; k++) {
					flag = recursiveSearch(j, k, word[i]);
					if (flag) break;
				}
				if (flag) break;
			}

			if (flag) {
				cout << word[i] << " YES" << endl;
				flag = false;
			}
			else {
				cout << word[i] << " NO" << endl;
			}
		}
	}

	bog.clear();
	return 0;
}

bool recursiveSearch(int y, int x, string word) {
	if (!isRange(y, x)) return false;
	if (word[0] != bog[y][x]) return false;
	if (word.length() == 1) return true;

	for (int i = 0; i < 8; i++) {
		if (recursiveSearch(y + dy[i], x + dx[i], word.substr(1))) {
			return true;
		}
	}
	return false;
}

bool isRange(int y, int x) {
	if (y > 4 || y < 0 || x > 4 || x < 0) {
		return false;
	}
	return true;
}