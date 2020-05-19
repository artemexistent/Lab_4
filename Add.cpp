#include "Header.h"

bool checknum(char a)
{
	return (a != '1' && a != '2' && a != '3' && a != '4' && a != '5' && a != '6' && a != '7' && a != '8' && a != '9' && a != '0');
}

bool check_int(string word)
{
	bool num = true;
	for (int i = 0; i < word.length(); i++)
		if (checknum(word[i]))
			num = false;
	return num;
}

int entnum(string mark)
{
	bool end = false;
	while (!end)
	{
		cout << "Enter the " + mark + "." << endl;
		string word;
		cin >> word;
		bool is_int = check_int(word);
		if (is_int)
		{
			int num = stoi(word);
			end = true;
			return num;
		}
		else
		{
			system("cls");
			cout << "Not integer. Enter again.";
		}
	}
}
