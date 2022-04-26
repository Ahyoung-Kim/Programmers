#include <string>
#include <vector>

using namespace std;

bool check(char c) {
	if ((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')
		|| c == '-' || c == '_' || c == '.')
		return true;
	return false;
}

string solution(string new_id) {
	string answer = "";
	int len = new_id.size();
	int size = 0;

	for (int i = 0; i < len; i++) {
		//1. 소문자로 치환
		if (new_id[i] >= 'A' && new_id[i] <= 'Z') {
			new_id[i] = tolower(new_id[i]);
		}

		//2. 소문자, 숫자, -, _, . 을 제외한 모든 문자 제거
		if (check(new_id[i])) {

			if (new_id[i] == '.') {
				if (size == 0) //4. 마침표가 처음이나 끝에 위치한다면 제거
					continue;
				else if (size > 0 && new_id[size - 1] == '.') {
					//3. 마침표가 2번 이상 연속된 부분을 하나로 치환
					continue;
				}
				else if (size > 0 && new_id[size - 1] != '.') {
					new_id[size] = new_id[i];
					size++;
				}
			}
			else {
				new_id[size] = new_id[i];
				size++;
			}
		}
	}

	if (size > 0) {
		if (new_id[size - 1] == '.') {
			new_id.resize(size - 1);
			size--;
		}
		else {
			new_id.resize(size);
		}
	}
	//5. new_id가 빈 문자열이라면, new_id에 "a" 대입
	else if (size == 0) {
		new_id = "a";
		size = 1;
	}


	//6. 길이가 16 이상이라면, new_id의 첫 15개의 문자를 제외한 나머지 문자들 모두 제거
	//만약 제거 후, 마침표가 끝에 위치한다면 제거
	if (size >= 16) {
		if (new_id[14] == '.') {
			new_id.resize(14);
			size--;
		}
		else if (new_id[14] != '.') {
			new_id.resize(15);
		}
	}
	//7. 길이가 2 이하라면, new_id의 마지막 문자를 길이가 3이 될 때까지 반복해서 끝에 붙이기
	else if (size <= 2) {
		new_id.resize(3, new_id[size - 1]);
	}

	answer = new_id;

	return answer;
}