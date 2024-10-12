#include <iostream>
#include <fstream>
#include <string>

void __readFile(char path[])
{
	std::string data;
	std::ifstream readFile;
	readFile.open(path);
	if (readFile.is_open())
	{
		while (std::getline(readFile, data))
		{
			std::cout << data << std::endl;
		}
	}
}

void __writeFile(char path[], int dataLength, char* data[], bool writeToEnd = false)
{
	std::ofstream fout;
	if (writeToEnd)
		fout.open(path, std::ios::app);
	else
		fout.open(path);
	if (fout.is_open())
	{
		for (int i = 3; i < dataLength; i++)
		{
			if (std::strcmp(data[i], "endl") == 0)
			{
				fout << std::endl;
				i += 1;
			}
			fout << data[i] << " ";
		}
	}
	fout.close();
}

void main(int argc, char* argv[])
{
	if (argc < 3)
		std::cerr << "FileAction v1.0\nSyntax: <file> <command> [data]";
	if (std::strcmp(argv[2], "write") == 0)
		__writeFile(argv[1], argc, argv);

	else if (std::strcmp(argv[2], "write-to-end") == 0)
		__writeFile(argv[1], argc, argv, true);

	else if (std::strcmp(argv[2], "read") == 0)
		__readFile(argv[1]);
	else
		std::cerr << "FileAction v1.0\nSyntax: <file> <command> [data]";
}
//    0      1       2       ...  
// fa.exe file.txt write bla bla bla    <- example