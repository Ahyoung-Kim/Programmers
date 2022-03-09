#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

vector<int> solution(vector<int> answers) {
	vector<int> answer;
	int maxnum = 0;
	vector<vector<int>> person;
	vector<int> correct(3, 0);
	person.push_back({ 1, 2, 3, 4, 5 });
	person.push_back({ 2, 1, 2, 3, 2, 4, 2, 5 });
	person.push_back({ 3, 3, 1, 1, 2, 2, 4, 4, 5, 5 });

	for (int i = 0; i < 3; i++) {
		vector<int> p = person[i];

		int j = 0;

		for (int k = 0; k < answers.size(); k++) {
			if (j >= p.size())
				j = 0;

			if (answers[k] == p[j]) {
				correct[i]++;
			}
			j++;
		}
		maxnum = max(maxnum, correct[i]);
	}

	for (int i = 0; i < 3; i++) {
		if (maxnum == correct[i]) {
			answer.push_back(i + 1);
		}
	}

	return answer;
}