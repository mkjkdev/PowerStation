#include <istream>
#include "PowerData.h"

/**
 * @brief non member operator overloads
 * @author mitchel king
 * @date 9/05/2026
 * 
 * */

bool openFile(std::fstream & file, std::string & fileName);

/**
 * @brief callback routine to display PowerData
 * */
void displayInfo(const PowerData & item);

/**
 * @brief Date input and output stream operators
 * 
 * */
std::istream & operator >>(std::istream & input, Date & date);

std::ostream & operator<<(std::ostream & os, const Date & date);

/**
 * @brief PowerData input and output stream operators
 * 
 * */
std::ostream & operator <<(std::ostream & os, const PowerData & pd);

std::istream & operator >>(std::istream & is, PowerData & pd);

/**
 * @brief PowerData greater and less than operators
 * 
 * */
bool operator >(const PowerData & callData, const PowerData & otherData);

bool operator <(const PowerData & callData, const PowerData & otherData);

/**
 * @brief comparison operator
 * 
 * */

bool operator ==(const PowerData & callData, const PowerData & otherData);