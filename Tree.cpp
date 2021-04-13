#include "Header.h"

string finOperation(ifstream& stream)
{
	string operation;
	stream >> operation;
	return operation;
}

int finNumber(ifstream& stream)
{
	int number;
	stream >> number;
	return number;
}

void open_fin(ifstream& stream)
{
	if (!stream)
	{
		cout << "Input file cannot be opened." << endl;
	}
}

void open_fout(ofstream& stream)
{
	if (!stream)
	{
		cout << "Output file cannot be created." << endl;
		
	}
}

void work_I(ifstream& fin,ofstream& fout ,Tree& tr)
{
	int number = finNumber(fin);

	if (tr.insert(number))
	{
		fout << number << ": inserted" << endl;
	}
	else
	{
		fout << number << ": not inserted" << endl;
	}
	
}

void work_D(ifstream& fin, ofstream& fout, Tree& tr)
{
	int number = finNumber(fin);
	if (tr.erase(number))
	{
		fout << number << ": deleted" << endl;
	}
	else
	{
		fout << number << ": not deleted" << endl;
	}

}

void work_F(ifstream& fin, ofstream& fout, Tree& tr)
{
	int number = finNumber(fin);
	int count = 0;
	if (tr.find(number, count))
	{
		fout << number << ": found after " << count << " comparison(s)" << endl;
	}
	else
	{
		fout << number << ": not found after " << count << " comparison(s)" << endl;
	}
}

void work_L(ofstream& fout, Tree& tr)
{
	tr.foutTree(fout);
}

void main_operation(ifstream& fin , ofstream& fout)
{
	string operation;
	Tree tr;
	while (!fin.eof())
	{
		operation = finOperation(fin);

		if (operation == "I")
		{
			work_I(fin , fout , tr);
		}
		else if (operation == "D")
		{
			work_D(fin, fout, tr);
		}
		else if (operation == "F")
		{
			work_F(fin, fout, tr);
		}
		else if (operation == "L")
		{
			work_L(fout, tr);
		}
	}
}

int main()
{
	ifstream fin("INPUT.txt");
	ofstream fout("OUTPUT.txt");

	open_fin(fin);
	open_fout(fout);
	main_operation(fin, fout );
	
	cout << "the program has completed this work"<<endl;
	
	system ("pause");
	fin.close();
	fout.close();
	return 0;
}