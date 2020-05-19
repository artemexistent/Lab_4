#include "Header.h"


void menu()
{
	string type[2]
	{
		"Interactive",
		"Demonstrative",
	};
	int pos = 0;
	bool end = false;

	while (!end)
	{
		system("cls");
		for (int i = 0; i < 2; i++)
		{
			if (i == pos)
				cout << "->  " << type[i] << endl;
			else cout << "    " << type[i] << endl;
		}

		char key;
		key = _getch();
		if ((int)key != 13)
		{
			if ((int)key == -32)
			{
				key = _getch();
				if ((int)key == 72)
				{
					if (pos> 0)
						pos--;
					else pos = 1;
				}

				if ((int)key == 80)
				{
					if (pos < 1)
						pos++;
					else pos = 0;
				}
			}
		}
		else
		{
			switch (pos)
			{
			case 1:
				system("cls");
				Demo();
				break;
			case 0:
				system("cls");
				inter();
				break;
			case 2:
				system("cls");
				end = true;
				break;
			}
		}
	}
}


int main()
{
	menu();
	return 0;
}
