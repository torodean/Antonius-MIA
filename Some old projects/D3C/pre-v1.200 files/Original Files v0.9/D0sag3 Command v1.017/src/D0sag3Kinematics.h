/*
 * D0sag3Kinematics.h
 *
 *  Created on: Oct 7, 2014
 *      Author: antonius
 */

#include <string>
#ifndef KINEMATICS_H_
#define KINEMATICS_H_

namespace std {

class D0sag3Kinematics {
	double displacement, finalVelocity, constantVelocity, initialVelocity, acceleration, finalPosition, initialPosition, velocity, totalTime, totalTime2, initialTime, finalTime, initialAcceleration, finalAcceleration, position;
	string variable;
	int dimension, decideCase;
	bool run, knowDisplacement, windResistance, knowConstantVelocity, constantAcceleration, knowInitialVelocity, knowFinalVelocity, knowInitialPosition, knowFinalPosition, knowTime, knowInitialTime, knowFinalTime, knowAcceleration;

public:
	D0sag3Kinematics();

	//=================================
	//2 Dimensional Kinematic functions
	//=================================
	void finalPositionWithConstantAcceleration1d(double initialPosition, double initialVelocity, double acceleration, double time);
	void finalPositionWithConstantVelocity1d(double initialPosition, double constantVelocity, double time);
	void initialPositionWithConstantAcceleration1d(double finalPosition, double initialVelocity, double acceleration, double time);
	void initialPositionWithConstantVelocity1d(double finalPosition, double constantVelocity, double time);
	void finalVelocityWithConstantAcceleration1d(double initialVelocity, double acceleration, double time);
	void averageAcceleration1d(double finalVelocity, double initialVelocity, double time);
	void initialVelocityWithConstantAcceleration1d(double finalVelocity, double acceleration, double time);
	void totalTimeWithConstantAcceleration1d(double initialVelocity, double finalVelocity, double acceleration);
	void totalTimeWithConstantVelocity1d(double constantVelocity, double initialPosition, double finalPosition);
	void initialVelocityWithConstantAcceleration1d(double finalPosition, double initialPosition, double acceleration, double time);
	void acceleration1d(double finalPosition, double initialPosition, double initialVelocity, double time);
	void totalTime1d(double initialVelocity, double initialPosition, double finalPosition, double acceleration);
	void displacement1d(double initialPosition, double finalPosition);
	void constantVelocity1d(double initialPosition, double finalPosition, double time);
	void finalPosition1d(double initialPosition, double initialVelocity, double finalVelocity, double time);
	void initialPosition1d(double finalPosition, double initialVelocity, double finalVelocity, double time);
	void finalVelocityWithConstantAcceleration1dAlternative(double initialVelocity, double acceleration, double displacement);
	void initialVelocityWithConstantAcceleration1dAlternative(double finalVelocity, double acceleration, double displacement);
	void acceleration1dAlternative(double initialVelocity, double finalVelocity, double displacement);
	void time1d(double displacement, double initialVelocity, double finalVelocity);
	void finalPositionWithConstantAcceleration1dAlternative(double finalVelocity, double initialVelocity, double acceleration, double initialPosition);
	void initialPositionWithConstantAcceleration1dAlternative(double finalVelocity, double initialVelocity, double acceleration, double finalPosition);
	void initialVelocity1d(double displacement, double finalVelocity, double time);
	void finalVelocity1d(double displacement, double initialVelocity, double time);
	void changeInTime(double initialTime, double finalTime);
	//========================================
	//end of 2 Dimensional Kinematic functions
	//========================================

	void kinematicsRunner();
	void kinematicsRunner1d();
	void kinematicsRunner2d();

	virtual ~D0sag3Kinematics();
};

} /* namespace std */

#endif /* KINEMATICS_H_ */
