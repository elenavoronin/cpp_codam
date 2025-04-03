#include "Base.hpp"


Base::Base() {
	std::cout << "Base was created" << std::endl;
}

Base::~Base() {
	std::cout << "Base was destroyed" << std::endl;
}

Base* generate(void) {
	int randomValue = rand() % 3;
	switch (randomValue) {
		case 0:
			return new A();
		case 1:
			return new B();
		case 2:
			return new C();
		default:
			return nullptr;
	}
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p) != nullptr)
		std::cout << "I am A" << std::endl;
	else if (dynamic_cast<B*>(p) != nullptr)
		std::cout << "I am B" << std::endl;
	else if (dynamic_cast<C*>(p) != nullptr)
		std::cout << "I am C" << std::endl;
	else
		std::cout << "I don't know who I am" << std::endl;

}
void identify(Base& p) {
	if (dynamic_cast<A*>(&p) != nullptr)
		std::cout << "I am a reference to A" << std::endl;
	else if (dynamic_cast<B*>(&p) != nullptr)
		std::cout << "I am a reference to B" << std::endl;
	else if (dynamic_cast<C*>(&p) != nullptr)
		std::cout << "I am a reference to C" << std::endl;
	else
		std::cout << "I am an unknown type" << std::endl;

}
