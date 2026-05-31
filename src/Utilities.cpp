#include "../include/Utilities.h"
#include "../include/Node.h"
#include "../include/PowerData.h"

#include<fstream>
#include<iostream>
#include<sstream>


void displayInfo(const PowerData & item){
	std::cout << item << std::endl;
}

bool openFile(std::fstream & file, std::string & fileName){
	file.open(fileName);
	//error if cannot be opened
	if(!file){
		file.close();
		return false;
	}
	return true;
}

//Date insertion and extraction operator overloads
std::istream & operator >>(std::istream & is, Date & d){
    //Strings to read into
    std::string da, mon, yea;
    //Change to use getline, for csv format

    std::getline(is, da, '/');
    std::getline(is,mon,'/');
    std::getline(is,yea, ' ');

    //Assign to date, converting to int
    try{
	    d.setDay(std::stoul(da));
	    d.setMonth(std::stoul(mon));
	    d.setYear(std::stoul(yea));
    }
    catch(const std::invalid_argument & e){
    	std::cout << e.what();
    	exit(0);
    }
    return is;
}

std::ostream & operator << (std::ostream & os, Date & d){
    os << "  Date: "+d.getDate(" ");
    return os;
}


/**
 * @brief PowerData comparison operator overload
 * 
 * */
bool operator ==(const PowerData & callData, const PowerData & otherData){
	//compare accreditation codes
	if (callData.accreditationCode == otherData.accreditationCode){return true;}
	else{return false;}
}

bool operator <(const PowerData & callData, const PowerData & otherData){
	if(callData.accreditationCode < otherData.accreditationCode){return true;}
	else{return false;}
}

bool operator >(const PowerData & callData, const PowerData & otherData){
	if(callData.accreditationCode > otherData.accreditationCode){return true;}
	else{return false;}
}

/**
 * @brief operator overload implementations
 * 
 * 
 * */
std::ostream & operator <<(std::ostream & os, const PowerData & pd){
	os << "Accreditation code: " << pd.accreditationCode << '\n';
	os << "Station Name: " << pd.stationName << '\n';
	return os;
}

//powerdata stream insertion operator
std::istream & operator >>(std::istream & is, PowerData & pd){
	//string stream
	std::stringstream ss;
	//power data
	std::string tempString;
	std::string tempStr1;
	std::string word;

	//re write into loop
	//get firstline
	std::getline(is, tempString, ',');

	//first value
	//wrap and send to primitive
	ss = std::stringstream(tempString);
	ss >> pd.accreditationCode;

	//second value, check for quoted comma in stationName
	if(is.peek()=='"'){
		std::getline(is, tempString,'"');
		std::getline(is, tempStr1, '"');
		std::getline(is, tempString, ',');
	}
	else{
		std::getline(is, tempString, ',');
	}
	pd.stationName = tempString;
	std::cout <<pd.stationName << std::endl;


	//third value
	std::getline(is, tempString, ',');
	ss = std::stringstream(tempString);
	ss >> pd.state;

	std::getline(is, tempString, ',');
	ss = std::stringstream(tempString);
	ss >> pd.capacity;


	std::getline(is, tempString, ',');
	ss = std::stringstream(tempString);
	ss >> pd.postCode;

	std::getline(is, tempString, ',');
	ss = std::stringstream(tempString);
	ss >> pd.fuel;

	std::getline(is, tempString, ',');
	ss = std::stringstream(tempString);
	ss >> pd.date;

	std::getline(is, tempString, ',');
	ss = std::stringstream(tempString);
	ss >> pd.status;

	std::getline(is, tempString, ',');
	ss = std::stringstream(tempString);
	ss >> pd.baseLine;

	std::getline(is, tempString, ',');
	ss = std::stringstream(tempString);
	ss >> pd.comments;

	return is;
}