#include "lever.h"
#include <random>

Lever::Lever(double mean, double variance)
{
	this->mean = mean;
	this->variance = variance;
}

double Lever::getMean()
{
	return mean;
}

double Lever::getVariance()
{
	return variance;
}

double Lever::getReward()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::normal_distribution<> d(mean, variance);
	return d(gen);
}