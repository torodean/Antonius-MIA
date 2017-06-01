/*
 * D0sag3Kinematics.cpp
 *
 *  Created on: Oct 7, 2014
 *      Author: antonius
 */

#include <iostream>
#include "D0sag3Kinematics.h"
#include <math.h>

namespace std {

D0sag3Kinematics::D0sag3Kinematics() : dimension(0), decideCase(0){
	// TODO Auto-generated constructor stub
}

//=====================================================================================
//=====================================================================================
// 2 Dimensional kinematic equations
//=====================================================================================
//=====================================================================================
void D0sag3Kinematics::finalPositionWithConstantAcceleration1d(double initialPosition, double initialVelocity, double acceleration, double time){
	finalPosition = initialPosition + (initialVelocity*time) + (acceleration*time*time)/2;
	knowFinalPosition = true;
}
void D0sag3Kinematics::finalPositionWithConstantVelocity1d(double initialPosition, double constantVelocity, double time){
	finalPosition = initialPosition + (constantVelocity*time);
	knowFinalPosition = true;
}
void D0sag3Kinematics::initialPositionWithConstantAcceleration1d(double finalPosition, double initialVelocity, double acceleration, double time){
	initialPosition = finalPosition - (initialVelocity*time) - (acceleration*time*time)/2;
	knowInitialPosition = true;
}
void D0sag3Kinematics::initialPositionWithConstantVelocity1d(double finalPosition, double constantVelocity, double time){
	initialPosition = finalPosition - (constantVelocity*time);
	knowInitialPosition = true;
}
void D0sag3Kinematics::finalVelocityWithConstantAcceleration1d(double initialVelocity, double acceleration, double time){
	finalVelocity = initialVelocity + acceleration*time;
	knowFinalVelocity = true;
}
void D0sag3Kinematics::averageAcceleration1d(double finalVelocity, double initialVelocity, double time){
	acceleration = (finalVelocity - initialVelocity)/time;
	knowAcceleration = true;
}
void D0sag3Kinematics::initialVelocityWithConstantAcceleration1d(double finalVelocity, double acceleration, double time){
	initialVelocity = finalVelocity - acceleration*time;
	knowInitialVelocity = true;
}
void D0sag3Kinematics::totalTimeWithConstantAcceleration1d(double initialVelocity, double finalVelocity, double acceleration){
	totalTime = (finalVelocity - initialVelocity)/acceleration;
	knowTime = true;
}
void D0sag3Kinematics::totalTimeWithConstantVelocity1d(double constantVelocity, double initialPosition, double finalPosition){
	totalTime = (finalPosition - initialPosition)/constantVelocity;
	knowTime = true;
}
void D0sag3Kinematics::initialVelocityWithConstantAcceleration1d(double finalPosition, double initialPosition, double acceleration, double time){
	initialVelocity = (finalPosition - initialPosition - (acceleration*time*time)/2)/time;
	knowInitialVelocity = true;
}
void D0sag3Kinematics::acceleration1d(double finalPosition, double initialPosition, double initialVelocity, double time){
	acceleration = ((finalPosition - initialPosition - initialVelocity*time)*2)/(time*time);
	knowAcceleration = true;
}
void D0sag3Kinematics::totalTime1d(double initialVelocity, double initialPosition, double finalPosition, double acceleration){
	totalTime = (-initialVelocity + sqrt(initialVelocity*initialVelocity - 2*(initialPosition - finalPosition)*acceleration))/(2*(initialPosition - finalPosition));
	totalTime2 = (-initialVelocity - sqrt(initialVelocity*initialVelocity - 2*(initialPosition - finalPosition)*acceleration))/(2*(initialPosition - finalPosition));
	knowTime = true;
}
void D0sag3Kinematics::displacement1d(double initialPosition, double finalPosition){
	displacement = finalPosition - initialPosition;
	knowDisplacement = true;
}
void D0sag3Kinematics::constantVelocity1d(double initialPosition, double finalPosition, double time){
	constantVelocity = (finalPosition - initialPosition)/time;
	knowConstantVelocity = true;
}
void D0sag3Kinematics::finalPosition1d(double initialPosition, double initialVelocity, double finalVelocity, double time){
	finalPosition = ((initialVelocity + finalVelocity)*time)/2 + initialPosition;
	knowFinalPosition = true;
}
void D0sag3Kinematics::initialPosition1d(double finalPosition, double initialVelocity, double finalVelocity, double time){
	initialPosition = finalPosition - ((initialVelocity + finalVelocity)*time)/2;
	knowInitialPosition = true;
}
void D0sag3Kinematics::finalVelocityWithConstantAcceleration1dAlternative(double initialVelocity, double acceleration, double displacement){
	finalVelocity = sqrt(initialVelocity*initialVelocity + 2*acceleration*(displacement));
	knowFinalVelocity = true;
}
void D0sag3Kinematics::initialVelocityWithConstantAcceleration1dAlternative(double finalVelocity, double acceleration, double displacement){
	initialVelocity = sqrt(finalVelocity*finalVelocity - 2*acceleration*(displacement));
	knowInitialVelocity = true;
}
void D0sag3Kinematics::acceleration1dAlternative(double initialVelocity, double finalVelocity, double displacement){
	acceleration = (finalVelocity*finalVelocity - initialVelocity*initialVelocity)/(2*(displacement));
	knowAcceleration = true;
}
void D0sag3Kinematics::time1d(double displacement, double initialVelocity, double finalVelocity){
	totalTime = 2*(displacement)/(initialVelocity + finalVelocity);
	knowTime = true;
}
void D0sag3Kinematics::finalPositionWithConstantAcceleration1dAlternative(double finalVelocity, double initialVelocity, double acceleration, double initialPosition){
	finalPosition = (finalVelocity*finalVelocity - initialVelocity*initialVelocity)/(2*acceleration) + initialPosition;
	knowFinalPosition = true;
}
void D0sag3Kinematics::initialPositionWithConstantAcceleration1dAlternative(double finalVelocity, double initialVelocity, double acceleration, double finalPosition){
	initialPosition = finalPosition - (finalVelocity*finalVelocity - initialVelocity*initialVelocity)/(2*acceleration);
	knowInitialPosition = true;
}
void D0sag3Kinematics::initialVelocity1d(double displacement, double finalVelocity, double time){
	initialVelocity = (2*displacement)/time - finalVelocity;
	knowInitialVelocity = true;
}
void D0sag3Kinematics::finalVelocity1d(double displacement, double initialVelocity, double time){
	finalVelocity = (2*displacement)/time - initialVelocity;
	knowFinalVelocity = true;
}
void D0sag3Kinematics::changeInTime(double initialTime, double finalTime){
	totalTime = finalTime - initialTime;
	knowTime = true;
}
//=====================================================================================
//=====================================================================================
// end of 2 Dimensional kinematic equations
//=====================================================================================
//=====================================================================================


void D0sag3Kinematics::kinematicsRunner(){
	run = true;

	runner:
	while (run == true){

		cout << endl;
		cout << "D0sag3Kinematics initialization:" << endl; // prints D0sag3Kinematics initialization:
		cout << "Enter 'exit' at any point to retun to the main command menu." << endl;
		cout << "Make sure all inputs are in metric units." << endl;
		startOfKinematics:

		cout << "Is this a 1 dimensional or 2 dimentional problem? (1/2): ";
		getline(cin, variable);
		if (variable == "1"){
			dimension = 1;
			kinematicsRunner1d();
			variable = "0";
		} else if(variable == "2"){
			dimension = 2;
			kinematicsRunner2d();
			run = false;
			goto startOfKinematics;

			variable = "0";
		} else if(variable == "exit"){
			run = false;
			goto runner;
		} else {
			cout << "Invalid command" << endl;
			variable = "0";
			goto startOfKinematics;
		}
	}
}

void D0sag3Kinematics::kinematicsRunner1d() {
	runner:

	while (run == true) {
		startOfKinematics:

		cout << "Is acceleration constant? (y/n): ";
		getline(cin, variable);
		if (variable == "y") {
			constantAcceleration = true;
			variable = "0";

			cout << "Do we know acceleration? (y/n): ";
			getline(cin, variable);
			if (variable == "y") {
				knowAcceleration = true;
				cout << "What is the acceleration?: ";
				cin >> acceleration;
				if (cin.peek() == '\n') {
					cin.ignore();
				}
				variable = "0";
			} else if (variable == "n") {
				knowAcceleration = false;
				variable = "0";
			} else if (variable == "exit") {
				run = false;
				goto runner;
			} else {
				cout << "Invalid command" << endl;
				variable = "0";
				goto startOfKinematics;
			}

		} else if (variable == "n") {
			constantAcceleration = false;

			cout << "non-constance acceleration is not yet programmed in."	<< endl;
			run = false;
			goto runner;

			variable = "0";
		} else if (variable == "exit") {
			run = false;
			goto runner;
		} else {
			cout << "Invalid command" << endl;
			variable = "0";
			goto startOfKinematics;
		}

		cout << "Do we know the initial position? (y/n): ";
		getline(cin, variable);
		if (variable == "y") {
			knowInitialPosition = true;
			cout << "What is the initial position?: ";
			cin >> initialPosition;
			if (cin.peek() == '\n') {
				cin.ignore();
			}
			variable = "0";
		} else if (variable == "n") {
			knowInitialPosition = false;
			variable = "0";
		} else if (variable == "exit") {
			run = false;
			goto runner;
		} else {
			cout << "Invalid command" << endl;
			variable = "0";
			goto startOfKinematics;
		}

		cout << "Do we know the final position? (y/n): ";
		getline(cin, variable);
		if (variable == "y") {
			knowFinalPosition = true;
			cout << "What is the final position: ";
			cin >> finalPosition;
			if (cin.peek() == '\n') {
				cin.ignore();
			}
			variable = "0";
		} else if (variable == "n") {
			knowFinalPosition = false;
			variable = "0";
		} else if (variable == "exit") {
			run = false;
			goto runner;
		} else {
			cout << "Invalid command" << endl;
			variable = "0";
			goto startOfKinematics;
		}

		if(knowAcceleration == false || acceleration == 0){
			cout << "Is velocity constant? (y/n): ";
			getline(cin, variable);
		}else{
			variable = "n";
		}

		if (variable == "y") {
			variable = "0";
			cout << "Do we know the constant velocity? (y/n): ";
			getline(cin, variable);
			if (variable == "y") {
				knowConstantVelocity = true;
				cout << "What is the constant velocity: ";
				cin >> constantVelocity;
				if (cin.peek() == '\n') {
					cin.ignore();
				}
				variable = "0";
			} else if (variable == "n") {
				knowConstantVelocity = false;
				variable = "0";
			} else if (variable == "exit") {
				run = false;
				goto runner;
			} else {
				cout << "Invalid command" << endl;
				variable = "0";
				goto startOfKinematics;
			}
		} else if (variable == "n") {

			cout << "Do we know the initial velocity? (y/n): ";
			getline(cin, variable);
			if (variable == "y") {
				knowInitialVelocity = true;
				cout << "What is the initial velocity: ";
				cin >> initialVelocity;
				if (cin.peek() == '\n') {
					cin.ignore();
				}
				variable = "0";
			} else if (variable == "n") {
				knowInitialVelocity = false;
				variable = "0";
			} else if (variable == "exit") {
				run = false;
				goto runner;
			} else {
				cout << "Invalid command" << endl;
				variable = "0";
				goto startOfKinematics;
			}

			cout << "Do we know the final velocity? (y/n): ";
			getline(cin, variable);
			if (variable == "y") {
				knowFinalVelocity = true;
				cout << "What is the final velocity: ";
				cin >> finalVelocity;
				if (cin.peek() == '\n') {
					cin.ignore();
				}
				variable = "0";
			} else if (variable == "n") {
				knowFinalVelocity = false;
				variable = "0";
			} else if (variable == "exit") {
				run = false;
			} else {
				cout << "Invalid command" << endl;
				variable = "0";
				goto startOfKinematics;
			}
		}

		cout << "Do we know the change in time (answer yes if you know final and initial)? (y/n): ";
		getline(cin, variable);
		if (variable == "y") {
			knowTime = true;
			cout << "Enter time (final time - initial time): ";
			cin >> totalTime;
			if (cin.peek() == '\n') {
				cin.ignore();
			}
			variable = "0";
		} else if (variable == "n") {
			knowTime = false;
			variable = "0";

			cout << "Do we know the initial time? (y/n)";
			getline(cin, variable);
			if (variable == "y") {
				knowInitialTime = true;
				cout << "Enter initial time: ";
				cin >> initialTime;
				if (cin.peek() == '\n') {
					cin.ignore();
				}
				variable = "0";
			} else if (variable == "n") {
				knowInitialTime = false;
				variable = "0";

				cout << "Do we know the final time? (y/n)";
				getline(cin, variable);
				if (variable == "y") {
					knowFinalTime = true;
					cout << "Enter final time: ";
					cin >> finalTime;
					if (cin.peek() == '\n') {
						cin.ignore();
					}
					variable = "0";
				} else if (variable == "n") {
					knowFinalTime = false;
					variable = "0";
				} else if (variable == "exit") {
					run = false;
					goto runner;
				} else {
					cout << "Invalid command" << endl;
					variable = "0";
					goto startOfKinematics;
				}

			} else if (variable == "exit") {
				run = false;
				goto runner;
			} else {
				cout << "Invalid command" << endl;
				variable = "0";
				goto startOfKinematics;
			}

		} else if (variable == "exit") {
			run = false;
			goto runner;
		} else {
			cout << "Invalid command" << endl;
			variable = "0";
			goto startOfKinematics;
		}

		if(knowInitialTime == true && knowFinalTime == true){
			changeInTime(initialTime, finalTime);
			knowTime = true;
		}

		if (knowInitialPosition == true && knowAcceleration == true	&& knowInitialVelocity == true && knowTime == true) {
			cout << "case set to: " << decideCase << endl;
			decideCase = 1;
		} else if (knowFinalPosition == true && knowAcceleration == true && knowInitialVelocity == true && knowTime == true) {
			cout << "case set to: " << decideCase << endl;
			decideCase = 2;
		} else if (knowFinalVelocity == true && knowInitialVelocity == true && knowAcceleration == true) {
			cout << "case set to: " << decideCase << endl;
			decideCase = 3;
		} else if (knowInitialPosition == true && knowFinalPosition == true) {
			cout << "case set to: " << decideCase << endl;
			decideCase = 4;
		} else if (knowFinalVelocity == true && knowInitialVelocity == true && knowTime == true) {
			cout << "case set to: " << decideCase << endl;
			decideCase = 5;
		} else if (knowConstantVelocity == true && knowInitialPosition == true && knowTime == true) {
			cout << "case set to: " << decideCase << endl;
			decideCase = 6;
		} else if (knowFinalPosition == true && knowInitialPosition == true && knowTime == true) {
			cout << "case set to: " << decideCase << endl;
			decideCase = 7;
		} else if (knowInitialVelocity == true && knowAcceleration == true && knowTime == true) {
			cout << "case set to: " << decideCase << endl;
			decideCase = 8;
		} else if (knowFinalVelocity == true && knowAcceleration == true && knowTime == true) {
			cout << "case set to: " << decideCase << endl;
			decideCase = 9;
		} else if (knowConstantVelocity == true && knowFinalPosition == true && knowTime == true) {
			cout << "case set to: " << decideCase << endl;
			decideCase = 10;
		} else if (knowConstantVelocity == true && knowFinalPosition == true && knowInitialPosition == true) {
			cout << "case set to: " << decideCase << endl;
			decideCase = 11;
		} else if (knowInitialPosition == true && knowFinalPosition == true && knowAcceleration == true && knowTime == true) {
			cout << "case set to: " << decideCase << endl;
			decideCase = 12;
		} else if (knowFinalPosition == true && knowInitialPosition == true && knowInitialVelocity == true && knowTime == true) {
			cout << "case set to: " << decideCase << endl;
			decideCase = 13;
		} else if (knowInitialVelocity == true && knowInitialPosition == true && knowFinalPosition == true && knowAcceleration == true) {
			cout << "case set to: " << decideCase << endl;
			decideCase = 14;
		} else if (knowInitialVelocity == true && knowAcceleration == true && knowInitialPosition == true && finalPosition == true) {
			cout << "case set to: " << decideCase << endl;
			decideCase = 15;
		} else if (knowFinalVelocity == true && knowAcceleration == true && knowInitialPosition == true && finalPosition == true) {
			cout << "case set to: " << decideCase << endl;
			decideCase = 16;
		} else if (knowFinalVelocity == true && knowInitialVelocity == true && knowInitialPosition == true && finalPosition == true) {
			cout << "case set to: " << decideCase << endl;
			decideCase = 17;
		} else if (knowFinalVelocity == true && knowInitialVelocity == true && knowInitialPosition == true && knowTime == true) {
			cout << "case set to: " << decideCase << endl;
			decideCase = 18;
		} else if (knowFinalVelocity == true && knowInitialVelocity == true && knowFinalPosition == true && knowTime == true) {
			cout << "case set to: " << decideCase << endl;
			decideCase = 19;
		} else if (knowFinalVelocity == true && knowInitialVelocity == true && knowInitialPosition == true && knowFinalPosition == true) {
			cout << "case set to: " << decideCase << endl;
			decideCase = 20;
		} else if (knowFinalVelocity == true && knowInitialVelocity == true && knowInitialPosition == true && knowAcceleration == true) {
			cout << "case set to: " << decideCase << endl;
			decideCase = 21;
		} else if (knowFinalVelocity == true && knowInitialVelocity == true && knowFinalPosition == true && knowAcceleration == true) {
			cout << "case set to: " << decideCase << endl;
			decideCase = 22;
		} else if (knowFinalVelocity == true && knowFinalPosition == true && knowInitialPosition == true && knowTime == true) {
			cout << "case set to: " << decideCase << endl;
			decideCase = 23;
		} else if (knowInitialVelocity == true && knowFinalPosition == true && knowInitialPosition == true && knowTime == true) {
			cout << "case set to: " << decideCase << endl;
			decideCase = 24;
		}

		switch (decideCase) {
		case 1:
			finalPositionWithConstantAcceleration1d(initialPosition, initialVelocity, acceleration, totalTime);
			finalVelocityWithConstantAcceleration1d(initialVelocity, acceleration, totalTime);
			displacement1d(initialPosition, finalPosition);
			cout << endl;
			cout << "Initial position = " << initialPosition << endl;
			cout << "Final position = " << finalPosition << endl;
			cout << "Acceleration = " << acceleration << endl;
			cout << "Initial Velocity = " << initialVelocity << endl;
			cout << "Final velocity = " << finalVelocity << endl;
			cout << "Displacement = " << displacement << endl;
			cout << "Total time = " << totalTime << endl;
			break;
		case 2:
			initialPositionWithConstantAcceleration1d(finalPosition, initialVelocity, acceleration, totalTime);
			finalVelocityWithConstantAcceleration1d(initialVelocity, acceleration, totalTime);
			displacement1d(initialPosition, finalPosition);
			cout << endl;
			cout << "Initial position = " << initialPosition << endl;
			cout << "Final position = " << finalPosition << endl;
			cout << "Acceleration = " << acceleration << endl;
			cout << "Initial Velocity = " << initialVelocity << endl;
			cout << "Final velocity = " << finalVelocity << endl;
			cout << "Displacement = " << displacement << endl;
			cout << "Total time = " << totalTime << endl;
			break;
		case 3:
			totalTimeWithConstantAcceleration1d(initialVelocity, finalVelocity, acceleration);
			initialPosition = 0;
			finalPositionWithConstantAcceleration1d(initialPosition, initialVelocity, acceleration, totalTime);
			displacement1d(initialPosition, finalPosition);
			cout << endl;
			cout << "Acceleration = " << acceleration << endl;
			cout << "Initial Velocity = " << initialVelocity << endl;
			cout << "Final velocity = " << finalVelocity << endl;
			cout << "Displacement = " << displacement << endl;
			cout << "Total time = " << totalTime << endl;
			break;
		case 4:
			displacement1d(initialPosition, finalPosition);
			cout << endl;
			cout << "Displacement = " << displacement << endl;
			break;
		case 5:
			averageAcceleration1d(finalVelocity, initialVelocity, totalTime);
			initialPosition = 0;
			finalPositionWithConstantAcceleration1d(initialPosition, initialVelocity, acceleration, totalTime);
			displacement1d(initialPosition, finalPosition);
			cout << endl;
			cout << "Acceleration = " << acceleration << endl;
			cout << "Initial Velocity = " << initialVelocity << endl;
			cout << "Final velocity = " << finalVelocity << endl;
			cout << "Displacement = " << displacement << endl;
			cout << "Total time = " << totalTime << endl;
			break;
		case 6:
			finalPositionWithConstantVelocity1d(initialPosition, constantVelocity, totalTime);
			displacement1d(initialPosition, finalPosition);
			cout << endl;
			cout << "Initial position = " << initialPosition << endl;
			cout << "Final position = " << finalPosition << endl;
			cout << "Acceleration = 0" << endl;
			cout << "Constant velocity = " << constantVelocity << endl;
			cout << "Displacement = " << displacement << endl;
			cout << "Total time = " << totalTime << endl;
			break;
		case 7:
			constantVelocity1d(initialPosition, finalPosition, totalTime);
			displacement1d(initialPosition, finalPosition);
			cout << endl;
			cout << "Initial position = " << initialPosition << endl;
			cout << "Final position = " << finalPosition << endl;
			cout << "Acceleration = 0" << endl;
			cout << "Constant velocity = " << constantVelocity << endl;
			cout << "Displacement = " << displacement << endl;
			cout << "Total time = " << totalTime << endl;
			break;
		case 8:
			finalVelocityWithConstantAcceleration1d(initialVelocity, acceleration, totalTime);
			initialPosition = 0;
			finalPositionWithConstantAcceleration1d(initialPosition, initialVelocity, acceleration, totalTime);
			displacement1d(initialPosition, finalPosition);
			cout << endl;
			cout << "Initial position = " << initialPosition << endl;
			cout << "Final position = " << finalPosition << endl;
			cout << "Acceleration = " << acceleration << endl;
			cout << "Initial Velocity = " << initialVelocity << endl;
			cout << "Final velocity = " << finalVelocity << endl;
			cout << "Displacement = " << displacement << endl;
			cout << "Total time = " << totalTime << endl;
			break;
		case 9:
			initialVelocityWithConstantAcceleration1d(finalVelocity, acceleration, totalTime);
			initialPosition = 0;
			finalPositionWithConstantAcceleration1d(initialPosition, initialVelocity, acceleration, totalTime);
			displacement1d(initialPosition, finalPosition);
			cout << endl;
			cout << "Initial position = " << initialPosition << endl;
			cout << "Final position = " << finalPosition << endl;
			cout << "Acceleration = " << acceleration << endl;
			cout << "Initial Velocity = " << initialVelocity << endl;
			cout << "Final velocity = " << finalVelocity << endl;
			cout << "Displacement = " << displacement << endl;
			cout << "Total time = " << totalTime << endl;
			break;
		case 10:
			initialPositionWithConstantVelocity1d(finalPosition, constantVelocity, totalTime);
			displacement1d(initialPosition, finalPosition);
			cout << endl;
			cout << "Initial position = " << initialPosition << endl;
			cout << "Final position = " << finalPosition << endl;
			cout << "Acceleration = 0" << endl;
			cout << "Constant velocity = " << constantVelocity << endl;
			cout << "Displacement = " << displacement << endl;
			cout << "Total time = " << totalTime << endl;
			break;
		case 11:
			totalTimeWithConstantVelocity1d(constantVelocity, initialPosition, finalPosition);
			displacement1d(initialPosition, finalPosition);
			cout << endl;
			cout << "Initial position = " << initialPosition << endl;
			cout << "Final position = " << finalPosition << endl;
			cout << "Acceleration = 0" << endl;
			cout << "Constant velocity = " << constantVelocity << endl;
			cout << "Displacement = " << displacement << endl;
			cout << "Total time = " << totalTime << endl;
			break;
		case 12:
			initialVelocityWithConstantAcceleration1d(finalPosition, initialPosition, acceleration, totalTime);
			displacement1d(initialPosition, finalPosition);
			finalVelocityWithConstantAcceleration1d(initialVelocity, acceleration, totalTime);
			cout << endl;
			cout << "Initial position = " << initialPosition << endl;
			cout << "Final position = " << finalPosition << endl;
			cout << "Acceleration = " << acceleration << endl;
			cout << "Initial Velocity = " << initialVelocity << endl;
			cout << "Final velocity = " << finalVelocity << endl;
			cout << "Displacement = " << displacement << endl;
			cout << "Total time = " << totalTime << endl;
			break;
		case 13:
			acceleration1d(finalPosition, initialPosition, initialVelocity, totalTime);
			displacement1d(initialPosition, finalPosition);
			finalVelocityWithConstantAcceleration1d(initialVelocity, acceleration, totalTime);
			cout << endl;
			cout << "Initial position = " << initialPosition << endl;
			cout << "Final position = " << finalPosition << endl;
			cout << "Acceleration = " << acceleration << endl;
			cout << "Initial Velocity = " << initialVelocity << endl;
			cout << "Final velocity = " << finalVelocity << endl;
			cout << "Displacement = " << displacement << endl;
			cout << "Total time = " << totalTime << endl;
			break;
		case 14:
			totalTime1d(initialVelocity, initialPosition, finalPosition, acceleration);
			finalVelocityWithConstantAcceleration1d(initialVelocity, acceleration, totalTime);
			displacement1d(initialPosition, finalPosition);
			cout << endl;
			cout << "Initial position = " << initialPosition << endl;
			cout << "Final position = " << finalPosition << endl;
			cout << "Acceleration = " << acceleration << endl;
			cout << "Initial Velocity = " << initialVelocity << endl;
			cout << "Final velocity = " << finalVelocity << endl;
			cout << "Displacement = " << displacement << endl;
			cout << "Total time 1 = " << totalTime << endl;
			cout << "Total time 2 = " << totalTime2 << endl;
			break;
		case 15:
			displacement1d(initialPosition, finalPosition);
			finalVelocityWithConstantAcceleration1dAlternative(initialVelocity, acceleration, displacement);
			totalTimeWithConstantAcceleration1d(initialVelocity, finalVelocity, acceleration);
			cout << endl;
			cout << "Initial position = " << initialPosition << endl;
			cout << "Final position = " << finalPosition << endl;
			cout << "Acceleration = " << acceleration << endl;
			cout << "Initial Velocity = " << initialVelocity << endl;
			cout << "Final velocity = +/-" << finalVelocity << endl;
			cout << "Displacement = " << displacement << endl;
			cout << "Total time = " << totalTime << endl;
			break;
		case 16:
			displacement1d(initialPosition, finalPosition);
			initialVelocityWithConstantAcceleration1dAlternative(finalVelocity, acceleration, displacement);
			totalTimeWithConstantAcceleration1d(initialVelocity, finalVelocity, acceleration);
			cout << endl;
			cout << "Initial position = " << initialPosition << endl;
			cout << "Final position = " << finalPosition << endl;
			cout << "Acceleration = " << acceleration << endl;
			cout << "Initial Velocity = +/-" << initialVelocity << endl;
			cout << "Final velocity = " << finalVelocity << endl;
			cout << "Displacement = " << displacement << endl;
			cout << "Total time = " << totalTime << endl;
			break;
		case 17:
			displacement1d(initialPosition, finalPosition);
			acceleration1dAlternative(initialVelocity, finalVelocity, displacement);
			totalTimeWithConstantAcceleration1d(initialVelocity, finalVelocity, acceleration);
			cout << endl;
			cout << "Initial position = " << initialPosition << endl;
			cout << "Final position = " << finalPosition << endl;
			cout << "Acceleration = " << acceleration << endl;
			cout << "Initial Velocity = " << initialVelocity << endl;
			cout << "Final velocity = " << finalVelocity << endl;
			cout << "Displacement = " << displacement << endl;
			cout << "Total time = " << totalTime << endl;
			break;
		case 18:
			finalPosition1d(initialPosition, initialVelocity, finalVelocity, totalTime);
			displacement1d(initialPosition, finalPosition);
			acceleration1dAlternative(initialVelocity, finalVelocity, displacement);
			cout << endl;
			cout << "Initial position = " << initialPosition << endl;
			cout << "Final position = " << finalPosition << endl;
			cout << "Acceleration = " << acceleration << endl;
			cout << "Initial Velocity = " << initialVelocity << endl;
			cout << "Final velocity = " << finalVelocity << endl;
			cout << "Displacement = " << displacement << endl;
			cout << "Total time = " << totalTime << endl;
			break;
		case 19:
			initialPosition1d(finalPosition, initialVelocity, finalVelocity, totalTime);
			displacement1d(initialPosition, finalPosition);
			acceleration1dAlternative(initialVelocity, finalVelocity, displacement);
			cout << endl;
			cout << "Initial position = " << initialPosition << endl;
			cout << "Final position = " << finalPosition << endl;
			cout << "Acceleration = " << acceleration << endl;
			cout << "Initial Velocity = " << initialVelocity << endl;
			cout << "Final velocity = " << finalVelocity << endl;
			cout << "Displacement = " << displacement << endl;
			cout << "Total time = " << totalTime << endl;
			break;
		case 20:
			displacement1d(initialPosition, finalPosition);
			acceleration1dAlternative(initialVelocity, finalVelocity, displacement);
			totalTimeWithConstantAcceleration1d(initialVelocity, finalVelocity, acceleration);
			cout << endl;
			cout << "Initial position = " << initialPosition << endl;
			cout << "Final position = " << finalPosition << endl;
			cout << "Acceleration = " << acceleration << endl;
			cout << "Initial Velocity = " << initialVelocity << endl;
			cout << "Final velocity = " << finalVelocity << endl;
			cout << "Displacement = " << displacement << endl;
			cout << "Total time = " << totalTime << endl;
			break;
		case 21:
			finalPositionWithConstantAcceleration1dAlternative(finalVelocity, initialVelocity, acceleration, initialPosition);
			displacement1d(initialPosition, finalPosition);
			totalTimeWithConstantAcceleration1d(initialVelocity, finalVelocity, acceleration);
			cout << endl;
			cout << "Initial position = " << initialPosition << endl;
			cout << "Final position = " << finalPosition << endl;
			cout << "Acceleration = " << acceleration << endl;
			cout << "Initial Velocity = " << initialVelocity << endl;
			cout << "Final velocity = " << finalVelocity << endl;
			cout << "Displacement = " << displacement << endl;
			cout << "Total time = " << totalTime << endl;
			break;
		case 22:
			initialPositionWithConstantAcceleration1dAlternative(finalVelocity, initialVelocity, acceleration, finalPosition);
			displacement1d(initialPosition, finalPosition);
			totalTimeWithConstantAcceleration1d(initialVelocity, finalVelocity, acceleration);
			cout << endl;
			cout << "Initial position = " << initialPosition << endl;
			cout << "Final position = " << finalPosition << endl;
			cout << "Acceleration = " << acceleration << endl;
			cout << "Initial Velocity = " << initialVelocity << endl;
			cout << "Final velocity = " << finalVelocity << endl;
			cout << "Displacement = " << displacement << endl;
			cout << "Total time = " << totalTime << endl;
			break;
		case 23:
			displacement1d(initialPosition, finalPosition);
			initialVelocity1d(displacement, finalVelocity, totalTime);
			acceleration1dAlternative(initialVelocity, finalVelocity, displacement);
			cout << endl;
			cout << "Initial position = " << initialPosition << endl;
			cout << "Final position = " << finalPosition << endl;
			cout << "Acceleration = " << acceleration << endl;
			cout << "Initial Velocity = " << initialVelocity << endl;
			cout << "Final velocity = " << finalVelocity << endl;
			cout << "Displacement = " << displacement << endl;
			cout << "Total time = " << totalTime << endl;
			break;
		case 24:
			displacement1d(initialPosition, finalPosition);
			finalVelocity1d(displacement, initialVelocity, totalTime);
			acceleration1dAlternative(initialVelocity, finalVelocity, displacement);
			cout << endl;
			cout << "Initial position = " << initialPosition << endl;
			cout << "Final position = " << finalPosition << endl;
			cout << "Acceleration = " << acceleration << endl;
			cout << "Initial Velocity = " << initialVelocity << endl;
			cout << "Final velocity = " << finalVelocity << endl;
			cout << "Displacement = " << displacement << endl;
			cout << "Total time = " << totalTime << endl;
			break;
		default:
			cout << "There is nothing to be solved for 'or' you entered an impossible scenario." << endl;
			break;
		}
	} /* Ends run == true while loop */
	run = true;
}

void D0sag3Kinematics::kinematicsRunner2d(){
	cout << "Three-dimensional kinematics are not yet programmed in." << endl;
}
D0sag3Kinematics::~D0sag3Kinematics() {
	// TODO Auto-generated destructor stub
}

} /* namespace std */
