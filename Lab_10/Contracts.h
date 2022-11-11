#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include "Exceptions.h"

using namespace std;

void OpenFile(ifstream* file)
{
	file->open("Main.txt");

	cout << "Main.txt file is opened" << endl;

	if (!file->is_open())
	{
		throw FileOpeningException();
	}
}

void OpenResultsFile(ofstream* file)
{
	file->open("Results.txt", ofstream::app);

	cout << "Results.txt file is opened" << endl;

	if (!file->is_open())
	{
		throw FileOpeningException();
	}
}

void CloseResultsFile(ofstream* file)
{
	file->close();

	cout << "Results.txt file is closed" << endl;
}

void CloseFile(ifstream* file)
{
	file->close();

	cout << "Main.txt file is closed" << endl;
}

vector<string> GetWords(vector<string> Lines)
{
	vector<string> Words;
	string word;

	for (int i = 0; i < Lines.size(); i++)
	{
		stringstream ss(Lines[i]);

		while (ss >> word)
		{
			if (ss.peek() == ' ')
			{
				ss.ignore();
			}

			Words.push_back(word);
		}
	}

	return Words;
}

int FindSymbols(vector<string> words, vector<char> symb)
{
	int count = 0;
	bool flag = false;

	for (int i = 0; i < words.size(); i++)
	{
		words[i][0] = tolower(words[i][0]);
	}

	for (int i = 0; i < words.size(); i++)
	{
		for (int j = 0; j < symb.size(); j++)
		{
			if (words[i].find(symb[j]) != string::npos)
			{
				flag = true;
			}
		}

		if (!flag)
		{
			count++;
		}

		flag = false;
	}

	return count;
}

vector<string> GetLines(ifstream* Data, vector<char> symb)
{
	vector<string> Lines;
	vector<string> Words;
	string line;
	ofstream Results;
	int count = 0;
	
	while (getline(*Data, line))
	{
		cout << "Line " << count << " is processed." << endl;
		cout << "'" << line << "'" << endl;
		
		OpenResultsFile(&Results);

		Results << "'" << line << "'" << endl;

		cout << "Writing string " << count << " to the Results.txt" << endl;
		
		count++;
		Lines.push_back(line);
		
		Words = GetWords(Lines);

		Results << "Words in line that don't contain the symbols: " << to_string(FindSymbols(Words, symb)) << endl;

		Lines.clear();

		CloseResultsFile(&Results);
	}

	CloseFile(Data);

	return Lines;
}

void WriteSymbols(vector<char> symb)
{
	ofstream Results;

	OpenResultsFile(&Results);

	Results << "Restricted symbols: ";

	for (char i : symb)
	{
		Results << i << ' ';
	}

	cout << "Writing symbols to Results.txt" << endl;

	Results << '\n';

	CloseResultsFile(&Results);
}