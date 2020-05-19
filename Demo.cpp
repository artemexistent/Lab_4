#include "Header.h"

void Demo()
{
	Tree* tree = new Tree();
	Tree* delete_tree = new Tree();
	binar_tree* binar = new binar_tree();
	symatri_tree* symatri = new symatri_tree(binar);
    sleep(3000);

	cout << endl << endl;

	cout << "Add '5' " << endl;
	tree->add_int(5, nullptr);
	tree->print(tree->root);
	cout << endl;
	sleep(3000);

	cout << endl << endl;


	cout << "Add '3' and '9' " << endl;
	tree->add_int(3, tree->root);
	tree->add_int(9, tree->root);
	tree->print(tree->root);
	cout << endl;
	sleep(3000);

	cout << endl << endl;

	cout << "Add  '1'  ,  and '4' to '5' " << endl;
	tree->add_int(1, tree->root->next[0]);
	tree->add_int(4, tree->root);
	tree->print(tree->root);
	cout << endl;
	sleep(3000);

	cout << endl << endl;

	cout << "Delete with root 3" << endl;
	delete_tree = tree->remove(3, tree->root);
	cout << "This tree: ";
	tree->print(tree->root);
	cout << endl;
	cout << "This deleted tree: ";
	delete_tree->print(delete_tree->root);
	cout << endl;
        sleep(3000);

	cout << endl << endl;

	cout << "Delete with root 11" << endl;
	delete_tree = tree->remove(11, tree->root);
	tree->print(tree->root);
	cout << endl;
	sleep(3000);

	cout << endl << endl;

	cout << "Add elements in binary 12,15,35,26,12,45,42" << endl;
	binar->add(12, binar->root);
	binar->add(15, binar->root);
	binar->add(35, binar->root);
	binar->add(26, binar->root);
	binar->add(12, binar->root);
	binar->add(45, binar->root);
	binar->add(42, binar->root);
	cout << "Added success." << endl;
	sleep(3000);

	cout << endl << endl;

	binar->print(binar->root);
	cout << endl;
	sleep(3000);

	cout << endl << endl;

	cout << "Symetric tree" << endl;
	symatri->create(binar);
	symatri->symatri_write(symatri->root);
	cout << endl;
	sleep(3000);

	cout << endl << endl;
	system("pause");
}
