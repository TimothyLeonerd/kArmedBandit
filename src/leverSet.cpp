#include "leverSet.h"
#include <random>

LeverSet::LeverSet(int numberOfLevers, double mean, double variance)
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::normal_distribution<> d(mean, variance);
	double optimalLeverValue = -1000000.0;

	for (int i = 0; i < numberOfLevers; i++)
	{
		double leverMean = d(gen);
		
		levers.push_back(Lever(leverMean, variance));

		if (leverMean > optimalLeverValue)
		{
			optimalLeverValue = leverMean;
			opimalLeverIndex = i;
		}
	}
}

std::vector<Lever> LeverSet::getLevers()
{
	return levers;
}

Lever LeverSet::getLever(int index)
{
	return levers[index];
}

int LeverSet::getNumberOfLevers()
{
	return numberOfLevers;
}

int LeverSet::getOptimalLeverIndex()
{
	return opimalLeverIndex;
}
