#pragma once

#include "kArmedBandit.h"
#include <string>

class kArmedBanditEnsemble {
public:

	kArmedBanditEnsemble(int k, double mean, double variance, double epsilon, int nRuns, int nStepsPerRun);
	
	int    getK();
	double getMean();
	double getVariance();
	int    getNRuns();
	int    getNStepsPerRun();
	std::vector<double> getMeanRewardLog();

	void run();

private:
	int k;
	double mean;
	double variance;
	double epsilon;
	int nRuns;
	int nStepsPerRun;
	std::string meanRewardLogFile;
	std::string meanOptimalActionLogFile;

	std::vector<double> meanRewardLog;
	std::vector<double>    meanOptimalActionLog;
	void updateMeanRewardLog(std::vector<double> rewardLog);
	void updateMeanOptimalActionLog(std::vector<double> optimalActionLog);
	void normalizeMeanRewardLog();
	void normalizeMeanOptimalActionLog();
	void normalizeLogs();
	void saveMeanLogFiles();
};
