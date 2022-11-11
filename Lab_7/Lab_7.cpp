#include <iostream>
#include <string>
#include <fstream>
#include <vector>

#define STRING_LENGHT 30


using namespace std;

class Note
{
private:
	string name;
	int length;
	string status;
public:
	Note() {}

	Note(string _name, int _length, string _status) {
		name = _name;
		length = _length;
		status = _status;
	}

	void ShowNote() {
		cout << name << " " << length << " " << status << endl;
	}

	bool operator ==(const Note& item)
	{
		return name == item.name;
	}

	friend class NoteBook;
};

class NoteBook
{
private:
	vector<Note> note;

	void WriteToTextFile(const string path)
	{
		ofstream fl;
		fl.open(path);

		for (auto i : note) {
			fl << i.name << ' ' << i.length << ' ' << i.status << "\n";
		}

		fl.close();
	}

	void ReadFromTextFile(const string path)
	{
		note.clear();

		ifstream fl;
		
		fl.open(path);

		while (fl.good())
		{
			string name;
			int length;
			string status;

			fl >> name >> length >> status;

			if (name == "")
			{
				break;
			}

			Note det(name, length, status);
			note.push_back(det);
		}

		fl.close();
	}

	void ReversShowForBinaryFile(string path)
	{
		note.clear();

		ifstream fl(path, ios::binary | ios::ate);
		bool f1 = false;
		bool f2 = false;
		char ch;

		while (fl.good())
		{
			char name[STRING_LENGHT];
			char length[STRING_LENGHT];
			char status[STRING_LENGHT];
			int size[] = { 0, 0, 0 };
			int size_tmp = 0;
			int i = 0;
			streampos here = fl.tellg();
			
			here -= 3;
			fl.seekg(here);

			while (!f1) {

				fl.get(ch);
				here = fl.tellg();
				here -= 2;
				fl.seekg(here);

				if (ch == ' ') {
					size[i++] = size_tmp;
					size_tmp = 0;
				}

				if (ch == '\n') {
					size[i++] = size_tmp;
					size_tmp = 0;
					break;
				}

				if (here == -1) {
					size[i++] = size_tmp + 1;
					f1 = true;
				}

				if (here == 1) {
					f2 = true;
					here += 1;
				}

				size_tmp++;
			}

			here += 2;

			if (here == 1) {
				fl.close();

				ifstream fl(path, ios::binary);

				here = fl.tellg();

				fl.read(name, size[2] - 1);
				name[size[2] - 1] = '\0';
				fl.get(ch);
				fl.read(length, size[1] - 1);
				length[size[1] - 1] = '\0';
				fl.get(ch);
				fl.read(status, size[0] + 1);
				fl.get(ch);
				status[size[0] + 1] = '\0';

				int temp = (int)atof(length);
				Note det(string(name), temp, string(status));

				note.push_back(det);
				break;
			}
			else {
				fl.seekg(here);
				fl.read(name, size[2] - 1);
				name[size[2] - 1] = '\0';
				fl.get(ch);
				fl.read(length, size[1] - 1);
				length[size[1] - 1] = '\0';
				fl.get(ch);
				fl.read(status, size[0] + 1);
				fl.get(ch);
				status[size[0] + 1] = '\0';

				int temp = (int)atof(length);
				Note det(string(name), temp, string(status));

				note.push_back(det);
				here = fl.tellg();
				here -= size[0];
				here -= size[1];
				here -= size[2];
				here -= 1;
				fl.seekg(here);
			}

		}

		fl.close();

		Show();
	}

public:

	NoteBook()
	{
	}

	void WriteToFile(const string path, bool IsBinary)
	{
		if (IsBinary == 1) {
			ofstream fl(path, ios::binary | ios::out, ofstream::app);

			for (auto i : note) {
				fl.write(i.name.c_str(), i.name.size());
				fl.write(" ", 1);
				fl.write(to_string(i.length).c_str(), to_string(i.length).size());
				fl.write(" ", 1);
				fl.write(i.status.c_str(), i.status.size());
				fl.write("\n", 1);
			}

			fl.close();
		}
		else
		{
			WriteToTextFile(path);
		}
	}

	void ReadFromFile(const string path, bool IsBinary)
	{
		if (IsBinary == 0) {
			ReadFromTextFile(path);
			return;
		}

		note.clear();

		ifstream fl(path, ios::binary);
		bool f1 = false;
		char ch = '\\';

		while (fl.good())
		{
			char name[STRING_LENGHT];
			char length[STRING_LENGHT];
			char status[STRING_LENGHT];
			int size[] = { 0, 0, 0 };
			int size_tmp = 0;
			int i = 0;
			streampos here = fl.tellg();

			while (!(f1 == true && ch == '\\')) {
				f1 = true;
				fl.get(ch);

				if (ch == ' ') {
					size[i++] = size_tmp;
					size_tmp = 0;
				}

				if (ch == '\n') {
					size[i++] = size_tmp;
					size_tmp = 0;
					break;
				}

				size_tmp++;
			}

			fl.seekg(here);
			fl.read(name, size[0]);

			name[size[0]] = '\0';

			if (string(name).size() == 0) {
				break;
			}

			fl.get(ch);
			fl.read(length, size[1] - 1);

			length[size[1] - 1] = '\0';
			
			fl.get(ch);
			fl.read(status, size[2] - 1);
			fl.get(ch);

			status[size[2] - 1] = '\0';

			int temp = (int)atof(length);
			Note det(string(name), temp, string(status));
			
			note.push_back(det);
		}

		fl.close();
	}

	void AddNote(Note& note)
	{
		this->note.push_back(note);
	}

	void Show()
	{
		for (auto i : note)
		{
			i.ShowNote();
		}
	}

	void ReverseShow(string path, bool IsBinary)
	{
		if (IsBinary == 1) {
			ReversShowForBinaryFile(path);
			return;
		}

		note.clear();

		ifstream fl(path, ios::binary | ios::ate);
		bool f1 = false;
		bool f2 = false;
		char ch;

		while (fl.good())
		{
			char name[STRING_LENGHT];
			char length[STRING_LENGHT];
			char status[STRING_LENGHT];
			int size[] = { 0, 0, 0 };
			int size_tmp = 0;
			int i = 0;
			streampos here = fl.tellg();

			here -= 3;
			fl.seekg(here);

			while (!f1) {

				fl.get(ch);
				here = fl.tellg();

				here -= 2;
				fl.seekg(here);

				if (ch == ' ') {
					size[i++] = size_tmp;
					size_tmp = 0;
				}

				if (ch == '\n') {
					size[i++] = size_tmp;
					size_tmp = 0;
					break;
				}

				if (here == -1) {
					size[i++] = size_tmp + 1;
					f1 = true;
				}

				if (here == 1) {
					f2 = true;
					here += 1;
				}

				size_tmp++;
			}

			here += 2;

			if (here == 1) {
				fl.close();

				ifstream fl(path, ios::binary);
				here = fl.tellg();

				fl.read(name, size[2] - 1);
				name[size[2] - 1] = '\0';
				fl.get(ch);
				fl.read(length, size[1] - 1);
				length[size[1] - 1] = '\0';
				fl.get(ch);
				fl.read(status, size[0]);
				fl.get(ch);
				status[size[0]] = '\0';

				int temp = (int)atof(length);
				Note det(string(name), temp, string(status));
				note.push_back(det);
				
				break;
			}
			else {
				fl.seekg(here);
				fl.read(name, size[2] - 1);
				name[size[2] - 1] = '\0';
				fl.get(ch);
				fl.read(length, size[1] - 1);
				length[size[1] - 1] = '\0';
				fl.get(ch);
				fl.read(status, size[0]);
				fl.get(ch);
				status[size[0]] = '\0';

				int temp = (int)atof(length);
				Note det(string(name), temp, string(status));
				note.push_back(det);

				here = fl.tellg();
				here -= size[0];
				here -= size[1];
				here -= size[2];
				here -= 1;
				fl.seekg(here);
			}
		}

		fl.close();

		Show();
	}

	void FindElement(string path, string name) {
		note.clear();

		ifstream fl;
		fl.open(path);

		while (fl.good()) {
			string dinamicName;
			int length;
			string status;

			fl >> dinamicName >> length >> status;
			
			if (name == dinamicName) {
				Note det(name, length, status);
				note.push_back(det);
			}
		}

		Show();

		fl.close();
	}

	void DeleteFile(string path, string NoteName, bool IsBinary) {
		ReadFromFile(path, IsBinary);

		if (note.size() == 0)
			return;

		for (auto i : note)
		{
			string tmp = i.name;

			if (tmp == NoteName)
			{
				note.erase(find(note.begin(), note.end(), i));
			}
		}

		WriteToFile(path, IsBinary);
	}
};



int main()
{
	try {
		string path;
		NoteBook notebook = NoteBook();
		bool binaryFile = 0;
		int bin;

		cout << "1 - Work with binary file, 2 - Work with text file" << endl;
		
		cin >> bin;

		switch (bin)
		{
		case 1:
		{
			path = "note.bin";
			binaryFile = true;
			break;
		}
		case 2:
		{
			path = "note.txt";

			cout << "1 - Work with text file in text mode, 2 - Work with text file in binary mode" << endl;
			
			int k;
			cin >> k;

			if (k == 2) binaryFile = true;
			else binaryFile = false;
			break;
		}
		default: { throw exception("Bad input"); }
		}

		while (true) {
			cout << "1.Add Note \n2.Delete Note \n3.Show Note List \n4.Find Note \n5.Save changes \n6.Read inf. from file \n7.Reversed output \n" << endl;
			
			int tmp;
			cin >> tmp;
			
			switch (tmp) {
			case 1:
			{
				string name;
				int length;
				string status;

				cout << "Enter Note Name:" << endl;
				cin >> name;
				cout << "Enter Note length:" << endl;
				cin >> length;
				cout << "Enter Status:" << endl;
				cin >> status;

				Note d1(name, length, status);
				notebook.AddNote(d1);
				
				break;
			}
			case 2:
			{
				cout << "Enter Note Name to delete: " << endl;
				
				string name;
				cin >> name;
				
				notebook.DeleteFile(path, name, binaryFile);
				
				break;
			}
			case 3:
			{
				notebook.Show();
				break;
			}
			case 4:
			{
				cout << "Enter Note Name to find: " << endl;

				string name;
				cin >> name;
				
				notebook.FindElement(path, name);
				break;
			}
			case 5:
			{
				notebook.WriteToFile(path, binaryFile);
				break;
			}
			case 6:
			{
				notebook.ReadFromFile(path, binaryFile);
				break;
			}
			case 7:
			{
				if (path == "detail.bin")
				{
					notebook.ReverseShow(path, binaryFile);
				}
				else
				{
					notebook.ReverseShow(path, 0);
				}
					
				break;
			}
			default: 
			{ 
				break; 
			}
			}
		}
	}
	catch (...) {
		terminate();
	}

	return 0;

}