#ifndef POWERDATA_H
#define POWERDATA_H

#include <iostream>
#include "Date.h"

/**
 * 
 * @brief Represents the data for a Power log from www.cer.gov.au
 * @date 9/5/2026
 * */

typedef struct PowerData{
	std::string accreditationCode;
	std::string stationName;
	std::string state;
	float capacity;
	int postCode;
	std::string fuel;
	Date date;
	std::string status;
	double baseLine;
	std::string comments;
	Date approvalDate;

	//default constructor
	PowerData():accreditationCode(""), stationName(""), state(""), capacity(0), postCode(0), fuel(""), date(),status(""), baseLine(0), comments(""), approvalDate(){}
}PowerData;

#endif