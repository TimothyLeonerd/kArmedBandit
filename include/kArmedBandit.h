#pragma once
#include "leverSet.h"
#include <vector>

class kArmedBandit {
	
public:
	kArmedBandit(int k, double mean, double variance, double epsilon);
	
	int						 getK();
	double					 getMean();
	double					 getVariance();
	std::vector<double>		 getRewardLog();
	std::vector<double>      getOptimalActionLog();
	void					 step();
	void                     run(int numSteps);
	
private:
	int k;
	double mean;
	double variance;
	double epsilon;

	std::vector<double>   rewardLog;
	std::vector<double>   optimalActionLog;

	LeverSet levers;
	std::vector<double> rewardEstimates;
	std::vector<double> numberOfTimesLeverHasBeenPulled;

	int chooseAction();
	void updateEstimate(int action, double reward);
	void updateOptimalActionLog(int action);
	double pullLever(int action);
};