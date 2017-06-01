/*
 * D0sag3Convert.h
 *
 *  Created on: Oct 12, 2014
 *      Author: antonius
 */

#include <string>
#ifndef D0SAG3CONVERT_H_
#define D0SAG3CONVERT_H_

namespace std {

class D0sag3Convert {
	int conversionCase;
	string output;
public:
	D0sag3Convert();
	void massConversion(long double unconvertedMass, string unconvertedMassUnit);
	void convertHelp(string Units);
	void convertRunner();
	virtual ~D0sag3Convert();
};

} /* namespace std */

#endif /* D0SAG3CONVERT_H_ */
