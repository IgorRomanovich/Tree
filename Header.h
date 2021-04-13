#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct TreeItem
{
	int value;
	TreeItem* right;
	TreeItem* left;
	TreeItem()
	{
		this->left = NULL;
		this->right = NULL;
		this->value = 0;
	}
	TreeItem(int value)
	{
		this->left = NULL;
		this->right = NULL;
		this->value = value;
	}
};

class Tree
{
private:
	TreeItem* root;

	bool find(int, TreeItem*&) const;
	bool find(int) const;

	void callBackFout(TreeItem*, ostream&) const;

	bool callBackErase(TreeItem*&, int);
	void callBackEraseAdd(TreeItem*&, TreeItem*&);

	void callBackDelete(TreeItem*);
	void deleteAll();

	TreeItem* clone(TreeItem*&);

public:
	Tree()
	{
		root = NULL;
	}

	Tree(const Tree&);

	const Tree& operator = (const Tree&);

	~Tree()
	{
		deleteAll();
	}

	bool insert(int);

	bool erase(int);

	bool find(int, int&) const;

	void foutTree(ostream&) const;
};

