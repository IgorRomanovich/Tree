#include "Header.h"

bool Tree::insert(int value)
{
	TreeItem* tmp = root;
	if (find(value, tmp))
	{
		return false;
	}
	TreeItem* p = new TreeItem(value);
	if (tmp == NULL)
	{
		root = p;
	}
	else
	{
		if (tmp->value < value)
		{
			tmp->right = p;
		}
		else
		{
			tmp->left = p;
		}
	}
	return true;
}

bool Tree::find(int value, TreeItem*& result) const
{
	if (root == NULL)
	{
		result = NULL;
		return false;
	}
	result = root;
	while (1)
	{
		if (result->value == value)
		{
			return true;
		}
		else
		{
			if (result->value > value)
			{
				if (result->left == NULL)
				{
					return false;
				}
				result = result->left;
			}
			else
			{
				if (result->right == NULL)
				{
					return false;
				}
				result = result->right;
			}
		}
	}
}

bool Tree::erase(int value)
{
	if (!find(value))
	{
		return false;
	}
	TreeItem* tmp = root;
	callBackErase(tmp, value);

	return true;
}

bool Tree::find(int value) const
{
	if (root == NULL)
	{
		return false;
	}
	TreeItem* result;
	result = root;
	
	while (1)
	{
		if (result->value == value)
		{
			return true;
		}
		else
		{
			if (result->value > value)
			{
				if (result->left == NULL)
				{
					return false;
				}
				result = result->left;
			}
			else
			{
				if (result->right == NULL)
				{
					return false;
				}
				result = result->right;
			}
		}
	}
}

bool Tree::callBackErase(TreeItem*& tmp, int value)
{
	if (value < tmp->value)
	{
		callBackErase(tmp->left, value);
	}
	else {
		if (value > tmp->value)
		{
			callBackErase(tmp->right, value);
		}
		else
		{
			TreeItem* p = tmp;
			if (p->right == NULL)
			{
				tmp = p->left;
				delete p;
			}
			else
			{
				if (p->left == NULL)
				{
					tmp = p->right;
					delete p;
				}
				else
				{
					callBackEraseAdd(p->right, p);
				}
			}
		}
	}
	return true;
}

void Tree::callBackEraseAdd(TreeItem*& right, TreeItem*& curr)
{

	if (right->left == NULL)
	{
		TreeItem* del;
		curr->value = right->value;
		curr = right;
		del = right;
		right = right->left;
		delete del;
	}
	else
	{
		callBackEraseAdd(right->left, curr);
	}
}

bool Tree::find(int value, int& count) const
{
	count = 0;
	if (root == NULL)
	{
		return false;
	}

	TreeItem* result;
	result = root;
	
	while (1)
	{
		count++;
		if (result->value == value)
		{
			return true;
		}
		else
		{
			if (result->value > value)
			{
				if (result->left == NULL)
				{
					return false;
				}
				result = result->left;
			}
			else
			{
				if (result->right == NULL)
				{
					return false;
				}
				result = result->right;
			}
		}
	}
}  


void Tree::foutTree(ostream& stream) const
{
	TreeItem* tmp = root;
	stream << "List of elements" << endl;
	callBackFout(tmp, stream);
	stream << endl;
}

void Tree::callBackFout(TreeItem* tmp, ostream& stream) const
{
	
	 if (tmp != NULL)
	{
		callBackFout(tmp->left, stream);
		stream << tmp->value << endl;
		callBackFout(tmp->right, stream);
	}
}

void Tree::deleteAll()
{
	TreeItem* tmp = root;
	callBackDelete(tmp);
}

void Tree::callBackDelete(TreeItem* tmp)
{
	if (tmp != NULL)
	{
		callBackDelete(tmp->left);
		callBackDelete(tmp->right);
		erase(tmp->value);
	}
}

const Tree& Tree::operator = (const Tree& tree)
{
	if (&tree != this)
	{
		deleteAll();
		TreeItem* tmp = tree.root;
		root = clone(tmp);
	}
	return *this;
}

Tree::Tree(const Tree& tree)
{
	TreeItem* tmp = tree.root;
	root = clone(tmp);
}

TreeItem* Tree::clone(TreeItem*& tmp)
{
	if (tmp == NULL)
		return NULL;
	TreeItem* New = new TreeItem;
	New->value = tmp->value;
	New->left = clone(tmp->left);
	New->right = clone(tmp->right);
	return New;
}