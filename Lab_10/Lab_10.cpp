#include <iostream>
#include <vector>
#include <fstream>
#include "Contracts.h"
#include "Exceptions.h"

using namespace std;

int main()
{
	ifstream Data;
	ofstream Results;
	string line;
	vector<char> symbols;
	int count = 0;
	char sym;

	do
	{
		cin >> sym;

		symbols.push_back(sym);
	} while (sym != '`');

	symbols.erase(symbols.end() - 1);


	try
	{
		OpenFile(&Data);
	
		WriteSymbols(symbols);

		vector<string> lines = GetLines(&Data, symbols);
	}
	catch (ExceptionHandler ex)
	{
		cout << ex.what() << endl;
	}
}
