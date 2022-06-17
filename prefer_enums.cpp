#include<iostream>

class Date

{
	public:
		Date(int year, int month, int day);
};


/* design clients coudl pass the year, month, and day values
 * in the wrong order, 
 * and they could specify illegal values, 
 * such as a month of 13. to get around these problems, he
 * suggest the introuduction of specific classes to represent year, 
 * month, and day value ,s uch as 
*/

class Year
{
	public:
		explicit Year(int y):mYear(y) {}
		int GetYear() const { return mYear;}

	private:
		int mYear;
};


class Month
{
	public:
		explicit Month(int m) : mMonth(m)
	{}

	private:
		int mMonth;

};
class Day
{
	public:
		
	explicit Day(int d):mDay(d){}
	int GetDay() const{return mDay;}
	private:
			int mDay;

};


class Date
{
	public:
		Date(const Year&y, const Month&m, const Day&d);
};

