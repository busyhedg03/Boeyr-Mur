#include <iostream>
int seeekSubStr(std::string mainS, std::string subS) {
	using namespace std;
	int mainLength{ (int)mainS.length() };
	int subLength{ (int)subS.length() };
	//���������� ������� �������
	int table[256]{ 0 }; //256 �������� ASCII
	for (int i{ 0 }; i < 256; ++i) { //��� �� ����� ������
		table[i] = subLength; //���� ������� ��� - ����� �� ����� ���������
	}
	for (int i{ 0 }; i < subLength - 1; ++i) { //��������� ������ �� �������������
		table[(unsigned char)subS[i]] = subLength - i - 1; //���������� �������
	}
	//�����
	int point{ 0 }; // ��������� ������ ��������� ������������ ������ ������
	//�������� �� ������
	int mainOffset{ 0 };
	//�������� �� ���������
	int subOffset{ 0 };
	int shift{ 0 };
	while (point + subLength - 1 < mainLength) {
		mainOffset = point;
		subOffset = 0;
		while (subOffset < subLength && mainS[mainOffset] == subS[subOffset]) { //�������� �������� ����� �� ���������� 
			++mainOffset; //���� �������, ���������� ������
			++subOffset;
		}
		if (subOffset == subLength) { //����� �� ����� ���������
			if (point == 0) {
				cout << "No need for shift"; //��� ����� � ������
			}
			return point; //������� ������� ������ � ���������
		}
		shift = table[(unsigned)mainS[point + subLength - 1]];
		cout << shift << " "; //������� �������� ������;
		point += shift; //������ ����� �������� �������
	}
	cout << "\tNot found";
	return -1; //�� �������
}
