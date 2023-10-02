#include <iostream>

#include <EngineCore/Utils/test.hpp>

int main() 
{
	std::cout << "Hello from Engine Editor" << std::endl;

	Engine::checkGLFW();

	std::cin.get();
}