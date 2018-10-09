#include "engine_instance.h"



int main(int argc, char* argv[])
{
	EngineInstance::instance().Run();

	exit(EXIT_SUCCESS);
}
