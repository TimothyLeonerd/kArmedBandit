#include "kArmedBanditEnsemble.h"

int main()
{
	// Choose parameters
	const int    kArms    = 10;		  // Number of arms/levers of bandit
	const double mean     = 0.0;	  // Each arm has a mean reward.
									  // These means can differ from zero, but they are chosen from a normal
									  // distribution with this mean and variance below
	const double variance = 1.0;      // Variance of the normal distribution from which the rewards are chosen
	const double epsilon = 0.1;       // Probability of choosing a random action
	const int    nRuns = 2000;		  // Number of runs
	const int    nStepsPerRun = 1000; // Number of steps per run
	
	// Create ensemble of bandits
	kArmedBanditEnsemble ensemble(kArms, mean, variance, epsilon, nRuns, nStepsPerRun);
	ensemble.run(); // Run all bandits in the ensemble
	
	return 0;
}