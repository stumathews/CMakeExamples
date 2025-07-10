#include "collector.h"
#include "engine.h"
#include "algorithm.h"
#include <iostream>

void Collector::Collect()
{
	std::cout << "Collecting\n";
	Engine engine;
	Algorithm algo;
	
	engine.Start();  // Need to link the engine library for this
	algo.Run();	 // Need to link the algorithm library for this 

}