#============================================================================
# Name        : workoutPlots.py
# Author      : Antonius Torode
# Date        : 3/28/18
# Copyright   : This file can be used under the conditions of Antonius' 
#				 General Purpose License (AGPL).
# Description : Program for generating workout plots for the documentation.
#============================================================================

import numpy as np
import matplotlib.pyplot as plt

#declare variables that are inputs
toughness = 0.1
minNumOfWorkouts = 3.0
maxNumOfWorkouts = 25
minNumOfSets = 1.0
maxNumOfSets = 10.0
b = 0.5
minModifier = 1.5
val = 1.9

def numMaxModifier(min, max, difficulty):
	'''
	Returns the modifier that determines the maximum of a thing allowed based on difficulty.
	'''
	return (max/(10.0*10.0**(1.0/3.0)) - min/(10.0*10.0**(1.0/3.0)))*difficulty**(2.0/3.0)+min
	
def numMaxModifierOLD(min, max, difficulty):
	'''
	Returns the modifier that determines the maximum of a thing allowed based on difficulty.
	'''
	return (max-min)/100.0 * difficulty + min
	
def numMinModifier(min, max, difficulty):
	'''
	Returns the modifier that determines the manimum of a thing allowed based on difficulty.
	'''
	return (-((-max + min*val)/(10.0*10.0**(1.0/3.0)* val)))*difficulty**(2.0/3.0) + min
	
def numMinModifierOLD(min, max, difficulty):
	'''
	Returns the modifier that determines the manimum of a thing allowed based on difficulty.
	'''
	return (max-min)/200.0 * difficulty + min
	
	
def numOfWorkoutsAverage(MinNumOfWorkouts, MaxNumOfWorkouts, difficulty):
	'''
	Inputs are minNumOfWorkouts and maxNumOfWorkouts and difficulty.
	Returns the average value of the first two inputs at the given difficulty.
	'''
	maxNumOfWorkoutsModifier = numMaxModifier(minNumOfWorkouts, maxNumOfWorkouts, difficulty)
	minNumOfWorkoutsModifier = numMinModifier(minNumOfWorkouts, maxNumOfWorkouts, difficulty)
	
	return (maxNumOfWorkoutsModifier+minNumOfWorkoutsModifier)/2.0
	
def numOfSetsAverage(minNumOfSets, maxNumOfSets, difficulty):
	'''
	Inputs are minNumOfSets and maxNumOfSets and the difficulty.
	Returns the average value of the first two inputs at the given difficulty.
	'''
	maxNumOfSetsModifier = numMaxModifier(minNumOfSets, maxNumOfSets, difficulty)
	minNumOfSetsModifier = numMinModifier(minNumOfSets, maxNumOfSets, difficulty)
	
	return (maxNumOfSetsModifier+minNumOfSetsModifier)/2.0
	
	
def numOfRepsMin(toughness, difficulty):
	'''
	Inputs are difficulty and toughness.
	Returns the min number of reps performed for a given difficulty.
	'''
	return (toughness*difficulty)/2.0 + 1.0
	
def numOfRepsMax(toughness, difficulty):
	'''
	Inputs are difficulty and toughness.
	Returns the max number of reps performed for a given difficulty.
	'''
	return toughness*difficulty+1.0

def numOfRepsAverage(difficulty, toughness):
	'''
	Inputs are difficulty and toughness.
	Returns the average number of reps performed for a given difficulty.
	'''
	repsMin = numOfRepsMin(toughness, difficulty)
	repsMax = toughness*difficulty + 1.0
	
	return (repsMax + repsMin)/2.0
	
	
def actualDifficulty(workouts, reps, sets):
	'''
	Inputs are workouts, reps, and sets.
	This function determines a relative actual difficulty based on inputs and returns a relative value.
	'''
	return workouts*reps*sets

difficulty = np.arange(100)
	
aveWorkouts = numOfWorkoutsAverage(minNumOfWorkouts, maxNumOfWorkouts, difficulty)
aveSets = numOfSetsAverage(minNumOfSets, maxNumOfSets, difficulty)
aveReps = numOfRepsAverage(difficulty, toughness)

maxWorkouts = numMaxModifier(minNumOfWorkouts, maxNumOfWorkouts, difficulty)
maxSets = numMaxModifier(minNumOfSets, maxNumOfSets, difficulty)
maxWorkoutsOLD = numMaxModifierOLD(minNumOfWorkouts, maxNumOfWorkouts, difficulty)
maxSetsOLD = numMaxModifierOLD(minNumOfSets, maxNumOfSets, difficulty)
maxReps = numOfRepsMax(toughness, difficulty)

minWorkouts = numMinModifier(minNumOfWorkouts, maxNumOfWorkouts, difficulty)
minSets = numMinModifier(minNumOfSets, maxNumOfSets, difficulty)
minWorkoutsOLD = numMinModifierOLD(minNumOfWorkouts, maxNumOfWorkouts, difficulty)
minSetsOLD = numMinModifierOLD(minNumOfSets, maxNumOfSets, difficulty)
minReps = numOfRepsMin(toughness, difficulty)

actDifficultyAve = actualDifficulty(aveWorkouts, aveReps, aveSets)
actDifficultyMax = actualDifficulty(maxWorkouts, maxReps, maxSets)
actDifficultyMin = actualDifficulty(minWorkouts, minReps, minSets)
	
plt.xlabel('Difficulty')
plt.ylabel('Number of Workouts')
plt.title('Workouts vs Difficulty in MIA')
plt.plot(difficulty, aveWorkouts,color="red", linestyle='--')
plt.plot(difficulty, maxWorkouts,color="green")
plt.plot(difficulty, maxWorkoutsOLD,color="green", linestyle = ':')
plt.plot(difficulty, minWorkouts,color="blue")
plt.plot(difficulty, minWorkoutsOLD,color="blue", linestyle = ':')
plt.show()

plt.xlabel('Difficulty')
plt.ylabel('Number of Sets')
plt.title('Sets vs Difficulty in MIA')
plt.plot(difficulty, aveSets,color="red", linestyle='--')
plt.plot(difficulty, maxSets,color="green")
plt.plot(difficulty, maxSetsOLD,color="green", linestyle = ':')
plt.plot(difficulty, minSets,color="blue")
plt.plot(difficulty, minSetsOLD,color="blue", linestyle = ':')
plt.show()

plt.xlabel('Difficulty')
plt.ylabel('Number of Reps Per Workout')
plt.title('Reps vs Difficulty in MIA')
plt.plot(difficulty, aveReps,color="red", linestyle='--')
plt.plot(difficulty, maxReps,color="green")
plt.plot(difficulty, minReps,color="blue")
plt.show()
	
plt.xlabel('Input Difficulty Parameter')
plt.ylabel('Relative Workout Difficulty')
plt.title('Input vs Output MIA Workout Difficulties')
plt.plot(difficulty, actDifficultyAve,color="red", linestyle='--')
plt.plot(difficulty, actDifficultyMax,color="green")
plt.plot(difficulty, actDifficultyMin,color="blue")
plt.show()


	