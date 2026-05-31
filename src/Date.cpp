#include "../include/Date.h"

//Constructors, member initialization list, assignment
Date::Date() : day(1), month(1), year(1900){}
Date::Date(int d, int m, int y) : day(d), month(m), year(y){}

//Day getter and setter
int Date::getDay() const{
    return day;
}
bool Date::setDay(const int da){
    day = da;
    if(day == da){
        return true;
    }
    else{
        return false;
    }
}

//Month getter and setter
int Date::getMonth() const{
    return month;
}
bool Date::setMonth(const int mon){
    month = mon;

    if(month == mon){
        return true;
    }
    else{
        return false;
    }
}

//Year getter and setter
int Date::getYear() const{
    return year;
}
bool Date::setYear(int yea){
    year = yea;

    if(year == yea){
        return true;
    }
    else{
        return false;
    }
}

//Date string getter, takes formatter, return by value as string is built inside
//method scope
 const std::string Date::getDate(const std::string formatter) const{
    //String to build
    std::string result;
    std::string m = "";
    //Create month string
    switch(month){
        case 1:
            m = "January";
        break;
        case 2:
            m = "February";
        break;
        case 3:
            m = "March";
        break;
        case 4:
            m = "April";
        break;
        case 5:
            m = "May";
        break;
        case 6:
            m = "June";
        break;
        case 7:
            m = "July";
        break;
        case 8:
            m = "August";
        break;
        case 9:
            m = "September";
        break;
        case 10:
            m = "October";
        break;
        case 11:
            m = "November";
        break;
        case 12:
            m = "December";
        break;
        default:
            m = "January";
    }
    //Convert values to string
    std::string d = std::to_string(day);
    //std::string m = std::to_string(month);
    std::string y = std::to_string(year);
    //Build return string with formatter
    result = result + d + formatter + m + formatter + y;

    return result;
}

