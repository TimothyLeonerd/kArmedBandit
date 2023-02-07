# k-armed Bandit Problem
Implementation of the k-armed bandit problem as described in Chapter 2 of "Reinforcement Learning" by Sutton and Barto.
[Here is a free online version of the book](https://www.andrew.cmu.edu/course/10-703/textbook/BartoSutton.pdf#page=47) (Or just google, in case link is down)
## Usage
Simply use [CMake](https://cmake.org/) to build and run the project.
The parameters of the problem can be set in main.cpp

After running the program, two output files are produced:
* meanRewardLog_eps_xxx.txt: This contains the reward per timestep, average over the entire ensemble of runs. Corresponds to the top in Figure 2.2 of Sutton and Barto 
* meanOptimalActionLog_eps_xxx.txt: This contains the percentage of times, the optimal action was taken at each specific timestep. Corresponds to the bottom in Figure 2.2 of Sutton and Barto 

Here are some example outputs of the two respective files:
![Mean reward per timestep](Mean_Reward.pdf "Mean Reward")
![Mean optimal action per timestep](Mean_Optimal_Action.pdf "Mean Optimal Action")
