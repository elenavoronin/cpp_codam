#include "Serializer.hpp"


int main(int argc, char **argv)
{
	if (argc == 1)
	{
		std::cout << "Enter a value" << std::endl;
		return 0;
	}
	Data data;
	data.value = std::stoi(argv[1]);
	std::cout << "value: "<< data.value << std::endl;
	Data* dataPtr = &data;
	uintptr_t raw = Serializer::serialize(dataPtr);
	Data *new_data = Serializer::deserialize(raw);
	if (new_data == dataPtr)
	{
		std::cout << "new data is equal to the original pointer " << std::endl;
		return 0;
	}
	return 1;
	
}
