#include "kArmedBanditEnsemble.h"
#include <fstream>
#include <iostream>


kArmedBanditEnsemble::kArmedBanditEnsemble(int k, double mean, double variance, double epsilon, int nRuns, int nStepsPerRun)
{
	this->k = k;
	this->mean = mean;
	this->variance = variance;
	this->epsilon = epsilon;
	this->nRuns = nRuns;
	this->nStepsPerRun = nStepsPerRun;
	this->meanRewardLogFile        = "meanRewardLog_eps_" + std::to_string(epsilon) + ".txt";
	this->meanOptimalActionLogFile = "meanOptimalActionLog_eps_" + std::to_string(epsilon) + ".txt";;

	for (int i = 0; i < nStepsPerRun; i++)
	{
		meanRewardLog.push_back(0);
		meanOptimalActionLog.push_back(0);
	}
}

int kArmedBanditEnsemble::getK()
{
	return k;
}

double kArmedBanditEnsemble::getMean()
{
	return mean;
}

double kArmedBanditEnsemble::getVariance()
{
	return variance;
}

int kArmedBanditEnsemble::getNRuns()
{
	return nRuns;
}

int kArmedBanditEnsemble::getNStepsPerRun()
{
	return nStepsPerRun;
}

std::vector<double> kArmedBanditEnsemble::getMeanRewardLog()
{
	return meanRewardLog;
}

void kArmedBanditEnsemble::run()
{
	for (int i = 0; i < nRuns; i++)
	{
		kArmedBandit bandit(k, mean, variance, epsilon);
		for (int j = 0; j < nStepsPerRun; j++)
		{
			bandit.step();
		}
		
		updateMeanRewardLog(bandit.getRewardLog());
		updateMeanOptimalActionLog( bandit.getOptimalActionLog());

		std::cout << "Run " << i << " complete." << std::endl;
	}
	
	normalizeLogs();
	saveMeanLogFiles();
	
}

void kArmedBanditEnsemble::updateMeanRewardLog(std::vector<double> rewardLog)
{
	for (int i = 0; i < rewardLog.size(); i++)
	{
		meanRewardLog[i] += rewardLog[i];
	}
}

void kArmedBanditEnsemble::normalizeMeanRewardLog()
{
	for (int i = 0; i < meanRewardLog.size(); i++)
	{
		meanRewardLog[i] /= nRuns;
	}
}

void kArmedBanditEnsemble::updateMeanOptimalActionLog(std::vector<double> optimalActionLog)
{
	for (int i = 0; i < optimalActionLog.size(); i++)
	{
		meanOptimalActionLog[i] += optimalActionLog[i];
	}
}

void kArmedBanditEnsemble::normalizeMeanOptimalActionLog()
{
	for (int i = 0; i < meanOptimalActionLog.size(); i++)
	{
		meanOptimalActionLog[i] /= nRuns;
	}
}

void kArmedBanditEnsemble::saveMeanLogFiles()
{
	std::ofstream file;
	file.open(meanRewardLogFile);
	for (int i = 0; i < meanRewardLog.size(); i++)
	{
		file << meanRewardLog[i] << std::endl;
	}
	file.close();

	std::cout << "Mean reward log saved to " << meanRewardLogFile << std::endl;

	file.open(meanOptimalActionLogFile);
	for (int i = 0; i < meanOptimalActionLog.size(); i++)
	{
		file << meanOptimalActionLog[i] << std::endl;
	}
	file.close();

	std::cout << "Mean optimal action log saved to " << meanOptimalActionLogFile << std::endl;
}

void kArmedBanditEnsemble::normalizeLogs()
{
	normalizeMeanRewardLog();
	normalizeMeanOptimalActionLog();
}