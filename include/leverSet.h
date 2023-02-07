#pragma once

#include "lever.h"
#include <vector>

class LeverSet
{
public:
	LeverSet(int numberOfLevers, double mean, double variance);

	std::vector<Lever> getLevers();
	Lever getLever(int index);
	int   getNumberOfLevers();
	int   getOptimalLeverIndex();
	
private:
	std::vector<Lever> levers;
	int numberOfLevers;
	int opimalLeverIndex;
};
