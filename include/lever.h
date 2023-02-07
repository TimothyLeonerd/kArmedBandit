#pragma once

class Lever
{
public:
	Lever(double mean, double variance);

	double getMean();
	double getVariance();
	double getReward();
	
private:
	double mean;
	double variance;
};
