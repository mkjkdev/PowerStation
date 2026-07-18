#include "../include/PowerCollector.h"
#include "../include/Vector.h"
#include "../include/Utilities.h"

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