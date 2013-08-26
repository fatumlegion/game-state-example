#include "Application.hpp"

int main(int argc, char **argv)
{
	app_ptr p = Application::getSingleton();
	p->initialize();
	return p->run(argc, argv);
}