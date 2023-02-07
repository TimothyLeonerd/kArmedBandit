# -*- coding: utf-8 -*-
"""
Created on Sat Feb  4 14:27:18 2023

@author: tleon
"""

from matplotlib import pyplot as plt

def plotFile(filename, param, color):
    vals = []
    for line in open(filename + param + ".txt", "r"):
        line = line[:-1]
        vals.append(float(line))
    plt.plot(vals, color)


plt.rcParams["figure.figsize"] = [7.00, 3.50]
plt.rcParams["figure.autolayout"] = True

meanRewardFile_base        = "meanRewardLog_eps_"
meanOptimalActionFile_base = "meanOptimalActionLog_eps_"

# Plot the mean rewards
plotFile(meanRewardFile_base, "0.000000", "r")
plotFile(meanRewardFile_base, "0.010000", "g")
plotFile(meanRewardFile_base, "0.100000", "b")
plt.show()

# Plot mean optimal action percentage
plotFile(meanOptimalActionFile_base, "0.000000", "b")
plotFile(meanOptimalActionFile_base, "0.010000", "r")
plotFile(meanOptimalActionFile_base, "0.100000", "g")
plt.show()


