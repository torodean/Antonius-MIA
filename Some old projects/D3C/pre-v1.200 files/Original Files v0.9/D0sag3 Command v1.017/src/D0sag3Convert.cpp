/*
 * D0sag3Convert.cpp
 *
 *  Created on: Oct 12, 2014
 *      Author: antonius
 */

#include <iostream>
#include <math.h>
#include "D0sag3Convert.h"

namespace std {

string units;
long double value, amu, carat, ug, t, shortcwt, st, dram, mg, g, kg, ST, LT, MT, longcwt, shortqtr, longqtr, lb, oz, gr, troypound, ozt, dwt;

D0sag3Convert::D0sag3Convert() : conversionCase (0){
	// TODO Auto-generated constructor stub
}

void D0sag3Convert::massConversion(long double unconvertedMass, string unconvertedMassUnit){
	if(unconvertedMassUnit == "amu"){
		g = unconvertedMass*1.66053892 * pow(10, -24);
	}else if(unconvertedMassUnit == "carat"){
		g = unconvertedMass * 5;
	} else if (unconvertedMassUnit == "ug" || unconvertedMassUnit == "μg") {
		g = unconvertedMass * pow(10, -6);
	} else if (unconvertedMassUnit == "mg") {
		g = unconvertedMass * pow(10, -3);
	} else if (unconvertedMassUnit == "kg") {
		g = unconvertedMass * pow(10, 3);
	} else if (unconvertedMassUnit == "t") {
		g = unconvertedMass * pow(10, 6);
	} else if (unconvertedMassUnit == "ST") {
		g = unconvertedMass * 907185;
	} else if (unconvertedMassUnit == "LT") {
		g = unconvertedMass * 1.01605 * pow(10, 6);
	} else if (unconvertedMassUnit == "MT") {
		g = unconvertedMass * pow(10, 12);
	} else if (unconvertedMassUnit == "short cwt") {
		g = unconvertedMass * 45359;
	} else if (unconvertedMassUnit == "long cwt") {
		g = unconvertedMass * 50802;
	} else if(unconvertedMassUnit == "long qtr"){
		g = unconvertedMass * 254000;
	} else if (unconvertedMassUnit == "st") {
		g = unconvertedMass * 6350.29;
	} else if (unconvertedMassUnit == "lb") {
		g = unconvertedMass * 453.592;
	} else if (unconvertedMassUnit == "oz") {
		g = unconvertedMass * 28.3495;
	} else if (unconvertedMassUnit == "dram") {
		g = unconvertedMass * 1.7718452;
	} else if (unconvertedMassUnit == "gr") {
		g = unconvertedMass * 0.064799;
	} else if (unconvertedMassUnit == "troy pound") {
		g = unconvertedMass * 373.24;
	} else if (unconvertedMassUnit == "ozt") {
		g = unconvertedMass * 31.1034768;
	} else if (unconvertedMassUnit == "dwt") {
		g = unconvertedMass * 1.5550;
	}
	cout << "g: " << g << endl;
	kg = g/pow(10, 3);
	cout << "kg: " << kg << endl;
	mg = pow(10, -3);
	cout << "mg: " << mg << endl;
	ug = g/pow(10, -6);
	cout << "μg: " << ug << endl;
	oz = g/28.3495;
	cout << "oz: " << oz << endl;
	lb = g/453.592;
	cout << "lb: " << lb << endl;
	amu = g/(1.66053892 * pow(10, -24));
	cout << "amu: " << amu << endl;
	carat = g/5;
	cout << "carat: " << carat << endl;
	dwt = g/1.5550;
	cout << "dwt: " << dwt << endl;
	ozt = g/31.1034768;
	cout << "ozt: " << ozt << endl;
	troypound = g/373.24;
	cout << "troypound: " << troypound << endl;
	gr = g/0.064799;
	cout << "gr: " << gr << endl;
	dram = g/1.7718452;
	cout << "dram: " << dram << endl;
	st = g/6350.29;
	cout << "st: " << st << endl;
	longqtr = g/254000;
	cout << "longqtr: " << longqtr << endl;
	longcwt = g/50802;
	cout << "longcwt: " << longcwt << endl;
	shortcwt = g/45359;
	cout << "shortcwt: " << shortcwt << endl;
	MT = g/pow(10, 12);
	cout << "MT: " << MT << endl;
	LT = g/(1.01605 * pow(10, 6));
	cout << "LT: " << LT << endl;
	ST = g/907185;
	cout << "ST: " << ST << endl;
	t = g/pow(10, 6);
	cout << "t: " << t << endl;
}

void D0sag3Convert::convertHelp(string units){
	if(units == "help"){
		cout << endl << "~~ Mass Units ~~" << endl;
		cout << "-- amu (atomic mass units)" << endl;
		cout << "-- carat (carat)" << endl;
		cout << "-- μg/ug (microgram) - mg (milligram) - g(gram) - kg (kilogram)" << endl;
		cout << "-- t (tonne) - ST (short ton) - LT (long ton) - MT (mega ton)" << endl;
		cout << "-- short cwt (short hundredweight) - long cwt (long hundredweight) - long qtr (long quarter)" << endl;
		cout << "-- st (stone) - lb (pound) - oz (ounce)" << endl;
		cout << "-- dram (drachm) - gr (grain) - troy pound (troy pound) - ozt (troy ounce) - dwt (pennyweight)" << endl;

		cout << endl << "~~ Length Units ~~" << endl;
		cout << "-- Gm (gigametre) - Mm (megametre) - km (kilometre) - hm (hectometre) - dam (decametre) - m (metre) - dm (decimetre) "
			"- cm (centimetre) - mm (millimetre) - μm/um (micrometre) - nm (nanometre)" << endl;
		cout << "-- Å/Ang (ångström)" << endl;
		cout << "-- furlong (furlong) - chain (chain) - rd (rod) - pole (pole) - perch (perch) - fathom (fathom)" << endl;
		cout << "-- mi (mile) - yd (yard) - ft (foot) - hand (hand) - in (inch) - nmi (nautical mile)" << endl;
		cout << "-- Gpc (gigaparsec) - Mpc (megaParsec) - kpc (kiloparsec) - pc (parsec) - Gly (gigalight-year) - Mly (megalight-year) "
			"- kly (kilolight-year) - ly (light-year) - AU (astronomical unit)" << endl;
	}else if(units == "help-mass"){
		cout << endl << "~~ Mass Units ~~" << endl;
		cout << "-- amu (atomic mass units)" << endl;
		cout << "-- carat (carat)" << endl;
		cout << "-- μg/ug (microgram) - mg (milligram) - g(gram) - kg (kilogram)" << endl;
		cout << "-- t (tonne) - ST (short ton) - LT (long ton) - MT (mega ton)" << endl;
		cout << "-- short cwt (short hundredweight) - long cwt (long hundredweight) - long qtr (long quarter)" << endl;
		cout << "-- st (stone) - lb (pound) - oz (ounce)" << endl;
		cout << "-- dram (drachm) - gr (grain) - troy pound (troy pound) - ozt (troy ounce) - dwt (pennyweight)" << endl;

	}
}

void D0sag3Convert::convertRunner(){
	cout << "~~ D0sag3 Convert Initialized ~~" << endl;
	cout << "Type 'help' for a list of valid units. Enter them in by their abbreviations (case sensitive).";
	cout << endl << "type 'exit' at any point to go to the previous menu." << endl;
	bool run = true;

	start:

	while (run == true){

		cout << endl;

		cout << "Enter starting units: ";
		getline(cin, units);
		if(units == "help" || units == "help-mass"){
			convertHelp(units);
			goto start;
		}else if(units == "exit"){
			run = false;
			goto start;
		}
		cout << "Enter value: ";
		cin >> value;
		if (cin.peek() == '\n') {
			cin.ignore();
		}
		if(units == "help" || units == "help-mass"){
			convertHelp(units);
			goto start;
		}else if(units == "exit"){
			run = false;
			goto start;
		}

		if(units == "amu" || units == "carat" || units == "μg/ug" || units == "mg" || units == "g" || units == "kg" || units == "t" || units == "ST" ||
			units == "LT" || units == "MT" || units == "short cwt" || units == "long cwt" || units == "short qtr" || units == "long qtr" || units == "st" ||
			units == "lb" || units == "oz" || units == "dram" || units == "gr" || units == "troy pound" || units == "ozt" || units == "dwt"){
			conversionCase = 1; //mass
		}else if(units == "Gm" || units == "Mm" || units == "km" || units == "hm" || units == "dam" || units == "m" || units == "dm" || units == "cm" ||
				units == "mm" || units == "μm" || units == "um" || units == "nm" || units == "Å/Ang" || units == "furlong" || units == "chain" ||
				units == "rd" || units == "pole" || units == "perch" || units == "fathom" || units == "mi" || units == "yd" || units == "ft" ||
				units == "hand" || units == "in" || units == "nmi" || units == "Gpc" || units == "Mpc" || units == "kpc" || units == "pc" || units == "Gly" ||
				units == "Mly" || units == "kly" || units == "ly" || units == "AU"){
			conversionCase = 2; //length
		}

		switch ( conversionCase ){
		case 1:
			massConversion(value, units);
			break;
		case 2:
			break;
		default:
			break;
		}
	}
}

D0sag3Convert::~D0sag3Convert() {
	// TODO Auto-generated destructor stub
}

} /* namespace std */
