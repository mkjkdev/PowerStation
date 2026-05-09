#ifndef DATE_H
#define DATE_H

typedef struct Date{
	int seconds;
	int minute;
	int hour;

	//default constructor
	Date(): seconds(0), minute(0), hour(0){}
}Date;

#endif