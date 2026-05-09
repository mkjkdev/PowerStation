#include "PowerData.h"
#include "Vector.h"

class PowerCollector{
	public:
		//Contrusctor
		LogCollector();

		//deconstructor
		virtual ~LogCollector();

		//call back func, insert into results Vector
		template<class T>
		static void callBackFunc(T & data);

	private:
		static int counter;
		static Vector<PowerData> results;

};