#include "../include/PowerCollector.h"
#include "../include/Vector.h"
#include "../include/Utilities.h"

/***
 * @brief PowerCollector provides a static vector instance Vector<PowerData> to store traversed items
 * @author mkjkdev
 * @date 18/07/2026
 * 
*/

//initialize static members
int PowerCollector::counter = 0;
Vector<PowerData> PowerCollector::results = Vector<PowerData>();

//constructor
PowerCollector::PowerCollector(){
	counter = 0;
	results = Vector<PowerData>();
}

//deconstructor
PowerCollector::~PowerCollector(){
	//clear vector
	results.clear();
}

//getCounter
int PowerCollector::getCounter(){
	return counter;
}

PowerData PowerCollector::getData(int value){
	return results[value];
}