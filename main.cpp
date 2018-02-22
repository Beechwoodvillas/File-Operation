#include<iostream>
#include<string>
#include<fstream>
using namespace std;


class FileOperation
{
public:
	void ReadFromFile();
	void PutTheLineIntoTheArray(char* pointer, int size, string concatenatedTarget);
	void WriteToFile(char* pointer, int size, int sentenceLength[]);
};

int main()
{
	setlocale(LC_ALL, "hun");
	FileOperation instance;
	instance.ReadFromFile();
	system("PAUSE");
	return 0;
}


void FileOperation::ReadFromFile()
{
	ifstream InPutFile;
	string target;
	string concatenatedTarget;
	InPutFile.open("source.txt");
	int sentenceLength[100];
	int size = 0;
	int numberOfLinesInFile = 0;

	while (!InPutFile.eof())
	{
		getline(InPutFile, target);
		sentenceLength[numberOfLinesInFile] = target.length();
		numberOfLinesInFile++;
		cout << target << endl;
		size = size + target.length();
		concatenatedTarget = concatenatedTarget + target; //Concatenating
	}
	cout << endl;

	int z = 0;
	while (z<numberOfLinesInFile)
	{
		cout << "length of " << z + 1 << ". sentence: " << sentenceLength[z] << endl;
		z++;

	}
	cout << endl;
	char* pointer = new char[size];
	PutTheLineIntoTheArray(pointer, size, concatenatedTarget);
	WriteToFile(pointer, size, sentenceLength);
	delete[] pointer;
	InPutFile.close();
}

void FileOperation::PutTheLineIntoTheArray(char* pointer, int size, string concatenatedTarget)
{
	for (int i = 0; i < size; i++)
	{
		pointer[i] = concatenatedTarget[i];//Convert string to char
	}
	int j = 0;
	while (j < size)
	{
		cout << pointer[j] << endl;
		j++;
	}
	cout << endl;
}


void FileOperation::WriteToFile(char* pointer, int size, int sentenceLength[])
{
	ofstream outPutFile;
	outPutFile.open("target.txt");

	int i = 0;
	int k = 0;
	int sentenceLengthVariable = 0;

	cout << "Total number of caharacters: " << size << endl;
	cout << endl;

	while (i < size)
	{

		outPutFile << pointer[i];
		if (sentenceLength[sentenceLengthVariable] == k)
		{
			outPutFile << endl;
			sentenceLengthVariable++;
			i++;
			k = 1;
			outPutFile << pointer[i];
		}
		i++;
		k++;

	}
	outPutFile.close();
}