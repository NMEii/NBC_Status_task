#include <iostream>
#include <string>
#include <limits>
#include "Windows.h"

using namespace std;

enum
{
	Quit,
	HP_UP,
	MP_UP,
	ATT_UP,
	DEF_UP,
	UserStat,
	Level_Up
};

void setPotion(int count, int* p_HPPotion, int* p_MPPotion)
{
	*p_HPPotion += count;
	*p_MPPotion += count;
}

bool isNum(string str)
{
	bool bNum = false;
	int i = 0;

	if (str[0] == 45)	// ASCII 코드 '-' 값 확인
	{
		i += 1;			// 음수의 경우 처음으로 -의 기호가 붙기 때문에 확인하고
	}					// 문자열의 첫자리가 -라면 다음 문자열을 읽도록 for문에 
						// 들어갈 i의 값을 +1 해준다.

	for (i; i < str.length(); i++)	
	{
		
		if (str[i] >= 48 && str[i] <= 57) // ASCII 코드 0~9 여부 확인
		{
			bNum = true;
		}
		else
		{
			bNum = false;
			return bNum;
		}
	}
	return bNum;		// 숫자면 True / 숫자가 아니라면 Fasle
}

int inputException(string catrgory, int excep)
{
	string str;
	int res = 0;
	while (1)
	{
		cin >> str;

		if (isNum(str))
		{
			if (stoi(str) > excep)
			{
				res = stoi(str);
				break;
			}
			else
			{
				cout << "설정한 " << catrgory << "값이 너무 작습니다. " << excep << "보다 커야합니다.\n";
			}
		}
		else
		{
			cout << "정수만 입력 가능합니다. 다시 입력해주세요.\n";
		}
	}
	return res;
}

int main()
{
	int Stat[] = { 0, 0, 0, 0, 1 };	// HP, MP, ATT, DEF, Level  순서
	int HP_Potion = 0;	// HP 포션
	int MP_Potion = 0;	// MP 포션

	string str = "";
	
	cout << "HP를 입력 해주세요.\n";
	Stat[0] = inputException("HP", 50);

	cout << "MP를 입력 해주세요.\n";
	Stat[1] = inputException("MP", 50);

	cout << "공격력을 입력 해주세요.\n";
	Stat[2] = inputException("공격력", 30);

	cout << "방어력을 입력 해주세요.\n";
	Stat[3] = inputException("방어력", 30);

	cout << "포션이 지급되었습니다. (HP, MP포션 각 5개)\n";
	setPotion(5, &HP_Potion, &MP_Potion);

	Sleep(3000);	// 3초 후 화면 클리어
	system("cls");

	cout << "============================================\n";
	cout << "<스탯 관리 시스템>" << endl;
	cout << "1. HP UP" << endl;
	cout << "2. MP UP" << endl;
	cout << "3. 공격력 UP" << endl;
	cout << "4. 방어력 UP" << endl;
	cout << "5. 현재 능력치" << endl;
	cout << "6. Level UP" << endl;
	cout << "0. 나가기" << endl;
	cout << "번호를 선택해주세요:";

	int choice;

	while (1)
	{
		while (1)
		{
			cin >> str;

			if (isNum(str))
			{
				if (stoi(str) >= 0 && stoi(str) <= 6)
				{
					choice = stoi(str);
					break;
				}
				else
				{
					cout << "0 ~ 6의 수를 입력해주세요.\n";
				}
			}
			else
			{
				cout << "정수만 입력 가능합니다. 다시 입력해주세요.\n";
			}

		}

		switch (choice)
		{
		case Quit:
			return 0;
		case HP_UP:
			if (HP_Potion > 0)
			{
				cout << "HP가 20 증가 되었습니다. 포션이 1개 차감됩니다.\n";
				Stat[0] += 20;
				HP_Potion -= 1;
			}
			else
			{
				cout << "* 현재 HP포션을 소지하고 있지 않습니다.\n";
			}
			break;
		case MP_UP:
			if (MP_Potion > 0)
			{
				cout << "* MP가 20 증가 되었습니다. 포션이 1개 차감됩니다.\n";
				Stat[1] += 20;
				MP_Potion -= 1;

			}
			else
			{
				cout << "현재 MP포션을 소지하고 있지 않습니다.\n";
			}
			break;
		case ATT_UP:
			cout << "* 공격력이 2배로 증가되었습니다.\n";
			Stat[2] *= 2;
			break;
		case DEF_UP:
			cout << "* 방어력이 2배로 증가되었습니다.";
			Stat[3] *= 2;
			break;
		case UserStat:

			cout << "* HP : ";
			cout << Stat[0];
			cout << ", MP : ";
			cout << Stat[1];
			cout << ", ATT : ";
			cout << Stat[2];
			cout << ", DEF : ";
			cout << Stat[3];
			cout << ", Level : ";
			cout << Stat[4] << endl;

			break;
		case Level_Up:
			cout << "* 레벨업! HP/MP 포션이 지급됩니다.\n";
			setPotion(1, &HP_Potion, &MP_Potion);
			
			cout << "남은 HP/MP 포션 포션 수 " << HP_Potion << "/"<< MP_Potion << endl;

			Stat[4] += 1;
			break;
		default:
			cout << "잘못된 입력입니다." << endl;
		}
	}
}