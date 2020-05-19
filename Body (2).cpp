#include "Header.h"

void body()
{
	Tree* tree = new Tree();
	binar_tree* binar = new binar_tree();
	symatri_tree* symatri = new symatri_tree(binar);


	string func[8] =ь{"Add int","Print","Print int","Delete","Add","Print","Symetric tree","Back."};

	int pos = 0;
	bool end = false;

	while (!end)
	{
		system("cls");
		for (int i = 0; i < 8; i++)
		{
			if (i == 4)
				cout << "Binary tree:" << endl;
			if (i == pos)
				cout << "->  " << func[i] << endl;
			else cout << "    " << func[i] << endl;
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
					if (pos > 0)
						pos--;
					else pos = 7;
				}

				if ((int)key == 80)
				{
					if (pos < 7)
						pos++;
					else pos = 0;
				}
			}
		}
		else
		{
			system("cls");
			Tree* delete_tree = new Tree();
			Node* node = nullptr;
			switch (pos)
			{
			case 0:
				tree->add_int(entnum("integer"), node);
				break;
			case 1:
				if (tree->root)
					tree->print(tree->root);
				else cout << "No elements";
				cout << endl;
				system("pause");
				break;
			case 2:
				if (tree->root)
					node = tree->choose(tree->root);
				else cout << "No elements" << endl;
				break;
			case 3:
				if (tree->root)
					delete_tree = tree->remove(entnum("integer"),tree->root);
				else cout << "No elements" << endl;
				break;
			case 4:
				binar->add(entnum("integer"), binar->root);
				break;
			case 5:
				if (binar->root)
					binar->print(binar->root);
				else cout << "No elements";
				cout << endl;
				system("pause");
				break;
			case 6:
				if (binar->root)
				{
					symatri->create(binar);
					symatri->symatri_write(symatri->root);
				}
				else cout << "No elements";
				cout << endl;
				system("pause");
				break;
			case 7:
				end = true;
				break;
			}
		}
	}
}
