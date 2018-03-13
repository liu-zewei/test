#include <iostream>
#include <fstream>

int main()
{
	std::streampos size;
	char * memblock;
	
	std::ifstream file ("example.bin", std::ios::in|std::ios::binary|std::ios::ate);
	if (file.is_open())
	{
		size = file.tellg();
		memblock = new char [size];
		file.seekg(0, std::ios::beg);
		file.read(memblock, size);
		file.close();

		std::cout << memblock << std::endl;

		delete[] memblock;
	}
	else
	{
		std::cout << "Unable to open file!" << std::endl;
	}
	return 0;
}
