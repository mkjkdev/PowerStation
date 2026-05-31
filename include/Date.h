#ifndef DATE_H
#define DATE_H
#include <iostream>
#include <string>  // std::cstring string library

    /**
    * @class Date
    * @brief Manages a calander Date
    *   Date is constructed with WeatherLog creation
    *   Composition relationship with WeatherLog
    *
    *
    *
    *
    *
    * @author Mitchel King
    * @version 01
    * @date 17/4/21
    */
class Date
{
    public:
        /**
        * @brief Default constructor
        *   Sets day to 1
        *   Sets month to 1
        *   Sets year to 1900
        **/
        Date();

        /**
        * Overloaded constructor setting to params
        * @param day Day of the month
        * @param month Month of the year
        * @param year Year of the century
        * @pre passed values exist
        **/
        Date(int d, int m, int y);

        /**
        * Day getter
        * @return Returns the day
        * @pre calling instance has day set
        * @post instance day returned
        **/
        int getDay() const;

        /**
        * Day setter
        * @param val Day to set
        * @return bool to indicate success
        * @pre val contains a value to set
        * @post instance day set
        **/
        bool setDay(int val);

        /**
        * Month getter
        * @return Returns the month
        * @pre instance has month set
        * @post insance month returned
        **/
        int getMonth() const;

        /**
        * Month setter
        * @param val Month to set
        * @return bool to indicate success
        * @pre val contains a value to set
        * @post instance month set
        **/
        bool setMonth(int val);

        /**
        * Year getter
        * @return Returns the year
        * @pre instance has month set
        * @post instance year returned
        **/
        int getYear() const;

        /**
        * Year setter
        * @param val Year to set
        * @return bool to indicate success
        * @pre val contains a value to set
        **/
        bool setYear(int val);

        /**
        * Date getter
        * @return Returns the date in string format
        * @param formatter to format between day,month,year
        * @pre formatter contains a value
        * @post returns a formatted string with member details
        **/
        std::string const getDate(const std::string formatter) const;

    private:
        int day {1}; ///<day of the month in class initialized to 1
        int month {1}; ///< month of the year in class initialized to 1
        int year {1900}; ///< year in class initialized to 1900
};

#endif // DATE_H
