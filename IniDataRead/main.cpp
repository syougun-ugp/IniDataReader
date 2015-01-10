#include "IniDataReader.hpp"

int main()
{
	IniDataReader ini("test.ini");

	int value = 0;
	value = ini.Get<int>("data.value");

	std::cout << value << std::endl;

	return 0;
}
