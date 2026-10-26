#include <fstream>
#include<sstream>

#include "include/PowerCollector.h"
#include "include/Utilities.h"
#include "include/bst.h"
#include "include/Node.h"


/***
 * @brief PowerCollector provides a static vector instance Vector<PowerData> to store traversed items
 * @author mkjkdev
 * @date 18/07/2026
 * 
*/

int main(){
	std::fstream inFile;
	std::string inputFileName ="data/historical-accredited-power-stations-and-projects-0.csv";
	std::string outputFileName = "data/output.csv";

	if(!openFile(inFile, inputFileName)){
		return 0;
	}

	PowerCollector collector;
	Bst<PowerData> powerTree;
	std::string tempS;
	std::string colNames;
	PowerData tempPower;

	getline(inFile, colNames);
	getline(inFile, tempS);
	while(getline(inFile, tempS)){
		std::stringstream ss(tempS);
		ss >> tempPower;
		powerTree.insert(tempPower);
	}
	inFile.close();

	//traverse and load sorted vector for faster IO
	powerTree.inOrder(PowerCollector::callBackFunc);

	//Print sorted vector
	for(int i=0;i < collector.getCounter();i++){
		std::cout << collector.getData(i);
	}

	return 0;
}