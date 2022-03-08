#include <string>
#include <vector>

using namespace std;

typedef struct info {
    int value;
    int idx;
    int sum;
}info;

int solution(vector<int> numbers, int target) {
    int answer = 0;

    vector<info> s;
    s.push_back({ 0, -1, 0 });

    while (!s.empty()) {
        info temp = s.back();
        s.pop_back();

        if (temp.idx == numbers.size() - 1) {
            if (temp.sum == target) {
                answer++;
            }
            continue;
        }

        int val = numbers[temp.idx + 1];
        int idx = temp.idx + 1;
        int sum = temp.sum + val;

        s.push_back({ val, idx, sum });

        val = val - val * 2;
        sum = temp.sum + val;

        s.push_back({ val, idx, sum });

    }

    return answer;
}