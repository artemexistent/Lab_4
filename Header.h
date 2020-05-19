#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<conio.h>
#include<windows.h>
#include <time.h>
using namespace std;

bool checknum(char sign);
int entnum(string mark);
void inter();
void Demo();


struct Node
{
	vector<Node*> path;
	int value;
	Node* prev;
	vector<Node*> next;
};

struct Tree
{
	Node* root;

	void create_empty()
	{
		root = 0;
	}

	Tree() {
		create_empty();
	}

	Node* choose(Node* curr)
	{
		int pos = 0;
		bool end = false;

		while (!end)
		{
			system("cls");
			for (int i = 0; i < curr->path.size(); i++)
				cout << "-> " << curr->path[i]->value;
			cout << endl;
			if (pos == 0)
				cout << "-> Node " << curr->value << endl;
			else cout << "   Node " << curr->value << endl;
			if (pos == 1)
				cout << "-> Back;" << endl;
			else cout << "   Back;" << endl;

			for (int i = 0; i < curr->next.size(); i++)
			{
				if (i == pos-2)
					cout << "-> " << curr->next[i]->value << endl;
				else cout << "   " << curr->next[i]->value << endl;
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
						else pos = curr->next.size()+1;
					}

					if ((int)key == 80)
					{
						if (pos < curr->next.size()+1)
							pos++;
						else pos = 0;
					}
				}
			}
			else
			{
				switch (pos)
				{
				case 0:
					return curr;
					break;
				case 1:
					if (curr->prev)
						return choose(curr->prev);
					else return choose(curr);
					break;
				default:
					return choose(curr->next[pos-2]);
					break;
				}
			}
		}
	}

	void add_int(int number, Node* curr)
	{
		Node* nnew = new Node();
		nnew->value = number;
		vector<Node*> a;
		nnew->next = a;
		if (!root)
		{
			nnew->path = a;
			nnew->prev = 0;
			root = nnew;
		}
		else
		{
			if (!curr)
				curr = choose(root);
			nnew->prev = curr;
			nnew->path = curr->path;
			nnew->path.push_back(curr);
			curr->next.push_back(nnew);
		}
	}

	void print(Node* curr)
	{
		cout << curr->value << " ";
		cout << "(";
		for (int i = 0; i < curr->next.size(); i++)
			print(curr->next[i]);
		cout << ") ";
	}

	Tree* remove(int number, Node* curr)
	{
		if (curr->value == number)
		{
			Tree* delete_tree = new Tree();
			delete_tree->root = curr;
			if (curr->prev)
			{
				for (int i = 0; i < curr->prev->next.size(); i++)
					if (number == curr->prev->next[i]->value)
					{
						curr->prev->next.erase(curr->prev->next.begin() + i);
						i = curr->prev->next.size();
					}
			}
			else
				create_empty();
			return delete_tree;
		}
		else
		{
			if (curr->next.size())
			{
				for (int i = 0; i < curr->next.size(); i++)
					return remove(number, curr->next[i]);
			}
		}

		Tree* delete_tree = new Tree();
		return delete_tree;
	}
};

struct binar
{
	int value;
	binar* prev;
	binar* left;
	binar* right;
};

struct binar_tree
{
	binar* root;

	void create_empty()
	{
		root = 0;
	}

	binar_tree() {
		create_empty();
	}

	void add(int number, binar* curr)
	{
		binar* nnew = new binar();
		nnew->left = 0;
		nnew->right = 0;
		nnew->value = number;
		if (!root)
		{
			nnew->prev = 0;
			root = nnew;
		}
		else
		{
			if (curr->value > number)
			{
				if (curr->left)
					add(number, curr->left);
				else
				{
					nnew->prev = curr;
					curr->left = nnew;
				}
			}
			else {
				if (curr->right)
					add(number, curr->right);
				else
				{
					nnew->prev = curr;
					curr->right = nnew;
				}
			}
		}
	}

	void print(binar* curr)
	{
		cout << curr->value << " ";
		cout << "(";
		if (curr->left)
			print(curr->left);
		else cout << "() ";
		if (curr->right)
			print(curr->right);
		else cout << "()";
		cout << ")";
	}
};

struct symatri
{
	int value;
	symatri* left;
	symatri* right;
	bool have_left;
	bool have_right;
};

struct symatri_tree {
	symatri* root;

	symatri* build_sumatri(binar* curr, symatri* sl, symatri* sr)
	{
		if (curr)
		{
			symatri* root = new symatri;
			root->value = curr->value;
			if ((root->have_left = (curr->left != NULL)))
				root->left = build_sumatri(curr->left, sl, root);
			else root->left = sl;
			if ((root->have_right = (curr->right != NULL)))
				root->right = build_sumatri(curr->right, root, sr);
			else root->right = sr;
			return root;
		}
		else root = 0;
	}

	void create(binar_tree* tree)
	{
		root = build_sumatri(tree->root, 0, 0);
	}

	symatri_tree(binar_tree* tree)
	{
		create(tree);
	}

	symatri* move(symatri* curr) {
		symatri* next_node = curr->right;
		if (curr->have_right)
			while (next_node->have_left)  next_node = next_node->left;
		return next_node;
	}

	void symatri_write(symatri* curr) {
		while (curr->have_left) curr = curr->left;
		while (curr) {
			cout << curr->value << ", ";
			curr = move(curr);
		}
	}
};

