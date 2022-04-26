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
		//1. �ҹ��ڷ� ġȯ
		if (new_id[i] >= 'A' && new_id[i] <= 'Z') {
			new_id[i] = tolower(new_id[i]);
		}

		//2. �ҹ���, ����, -, _, . �� ������ ��� ���� ����
		if (check(new_id[i])) {

			if (new_id[i] == '.') {
				if (size == 0) //4. ��ħǥ�� ó���̳� ���� ��ġ�Ѵٸ� ����
					continue;
				else if (size > 0 && new_id[size - 1] == '.') {
					//3. ��ħǥ�� 2�� �̻� ���ӵ� �κ��� �ϳ��� ġȯ
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
	//5. new_id�� �� ���ڿ��̶��, new_id�� "a" ����
	else if (size == 0) {
		new_id = "a";
		size = 1;
	}


	//6. ���̰� 16 �̻��̶��, new_id�� ù 15���� ���ڸ� ������ ������ ���ڵ� ��� ����
	//���� ���� ��, ��ħǥ�� ���� ��ġ�Ѵٸ� ����
	if (size >= 16) {
		if (new_id[14] == '.') {
			new_id.resize(14);
			size--;
		}
		else if (new_id[14] != '.') {
			new_id.resize(15);
		}
	}
	//7. ���̰� 2 ���϶��, new_id�� ������ ���ڸ� ���̰� 3�� �� ������ �ݺ��ؼ� ���� ���̱�
	else if (size <= 2) {
		new_id.resize(3, new_id[size - 1]);
	}

	answer = new_id;

	return answer;
}