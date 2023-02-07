#include "kArmedBandit.h"
#include <random>

kArmedBandit::kArmedBandit(int k, double mean, double variance, double epsilon) : levers(k, mean, variance)
{
	this->k = k;
	this->mean = mean;
	this->variance = variance;
	this->epsilon = epsilon;

	for (int i = 0; i < k; i++)
	{
		rewardEstimates.push_back(0);
		numberOfTimesLeverHasBeenPulled.push_back(0);
	}
}

int kArmedBandit::getK()
{
	return k;
}

double kArmedBandit::getMean()
{
	return mean;
}

double kArmedBandit::getVariance()
{
	return variance;
}

std::vector<double> kArmedBandit::getRewardLog()
{
	return rewardLog;
}

std::vector<double> kArmedBandit::getOptimalActionLog()
{
	return optimalActionLog;
}

void kArmedBandit::step()
{
	int action =    chooseAction();
	double reward = pullLever(action);
	updateEstimate(action, reward);
	
	
	rewardLog.push_back(reward);
	updateOptimalActionLog(action);
}

int kArmedBandit::chooseAction()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_real_distribution<> d(0, 1);

	if (d(gen) < epsilon)
	{
		std::uniform_int_distribution<> d(0, k - 1);
		return d(gen);
	}
	else
	{
		int bestAction = 0;
		double bestReward = rewardEstimates[0];

		for (int i = 1; i < k; i++)
		{
			if (rewardEstimates[i] > bestReward)
			{
				bestAction = i;
				bestReward = rewardEstimates[i];
			}
		}

		return bestAction;
	}
}

void kArmedBandit::updateEstimate(int action, double reward)
{
	rewardEstimates[action] = rewardEstimates[action] + (1.0 / numberOfTimesLeverHasBeenPulled[action]) * (reward - rewardEstimates[action]);
}

void kArmedBandit::run(int numSteps)
{
	while (numSteps--)
	{
		step();
	}
}

void kArmedBandit::updateOptimalActionLog(int action)
{
	if (levers.getOptimalLeverIndex() == action)
	{
		optimalActionLog.push_back(1.0);
	}
	else
	{
		optimalActionLog.push_back(0.0);
	}
}

double kArmedBandit::pullLever(int action)
{
	numberOfTimesLeverHasBeenPulled[action]++;

	return levers.getLever(action).getReward();
}