#include "Base.hpp"

int main() {
	srand(static_cast<unsigned int>(time(0)));

	for (int i = 0; i < 10; i++)
	{
		Base *Bob = generate();
		std::cout << "Identifying using pointer:" << std::endl;
		identify(Bob);
		std::cout << "Identifying using reference:" << std::endl;
		identify(*Bob);
		delete(Bob);
	}
}
