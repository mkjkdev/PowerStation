#include "PowerData.h"
#include "Vector.h"
#include "Utilities.h"

/***
 * @brief PowerCollector provides a static vector instance Vector<PowerData> to store traversed items
 * @author mkjkdev
 * @date 9/05/2026
 * 
*/

class PowerCollector{
	public:
		//Contrusctor
		PowerCollector();

		//deconstructor
		virtual ~PowerCollector();

		//call back func, insert into results Vector
		template<class T>
		static void callBackFunc(T & data);

		static int getCounter();

		PowerData getData(int value);

	private:
		static int counter;
		static Vector<PowerData> results;

};

//Call back funcction, insert data into Vector, increment counter
template<class T>
void PowerCollector::callBackFunc(T & data){
	results.insert(data);
	counter++;
}