/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/

int is_leap(int);
int is_month(int, int);
int nl_month(int, int);
int Older(int, int, int, int, int, int);

int isOlder(char *dob1, char *dob2) {
	int i, year1 = 0, year2 = 0, x, y, month1 = 0, month2 = 0, day1 = 0, day2 = 0, z, t, mainres;
	if (dob1[2] != '-' || dob1[5] != '-' || dob2[2] != '-' || dob2[5] != '-' || (dob1[3] - '0')<0 || (dob1[3] - '0')>1 || (dob2[3] - '0')<0 || (dob2[3] - '0')>1 || (dob1[4] - '0')<0 || (dob1[4] - '0')>9 || (dob2[4] - '0')<0 || (dob2[4] - '0')>9 || (dob1[0] - '0')<0 || (dob1[0] - '0')>3 || (dob2[0] - '0')<0 || (dob2[0] - '0')>3 || (dob1[1] - '0')<0 || (dob1[1] - '0')>9 || (dob2[1] - '0')<0 || (dob2[1] - '0')>9){
		return -1;
	}
	else{
		i = 6;
		while (i != 10){
			year1 = year1 * 10 + (dob1[i] - '0');
			year2 = year2 * 10 + (dob2[i] - '0');
			i++;
		}
		x = is_leap(year1);
		y = is_leap(year2);
		i = 3;
		while (i != 5){
			month1 = month1 * 10 + (dob1[i] - '0');
			month2 = month2 * 10 + (dob2[i] - '0');
			i++;
		}
		i = 0;
		while (i != 2){
			day1 = day1 * 10 + (dob1[i] - '0');
			day2 = day2 * 10 + (dob2[i] - '0');
			i++;
		}
		if (x == 1){
			z = is_month(month1, day1);
			if (z == 0){
				return -1;
			}
		}
		else{
			z = nl_month(month1, day1);
			if (z == 0){
				return -1;
			}
		}
		if (y == 1){
			t = is_month(month2, day2);
			if (t == 0){
				return -1;
			}
		}
		else{
			t = nl_month(month2, day2);
			if (t == 0){
				return -1;
			}
		}
		mainres = Older(day1, month1, year1, day2, month2, year2);
		return mainres;
	}
}
int is_leap(int year){
	if (year % 4 == 0){
		if (year % 100 == 0){
			if (year % 400 == 0)
				return 1;
			else
				return 0;
		}
		else
			return 1;
	}
	else
		return 0;
}
int is_month(int month, int day){
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){
		if (day > 0 && day <= 31){
			return 1;
		}
	}
	if (month == 2){
		if (day > 0 && day <= 29){
			return 1;
		}
	}
	if (month == 4 || month == 6 || month == 9 || month == 11){
		if (day > 0 && day <= 30){
			return 1;
		}
	}
	return 0;
}
int nl_month(int month, int day){
	if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){
		if (day > 0 && day <= 31){
			return 1;
		}
	}
	if (month == 2){
		if (day > 0 && day <= 28){
			return 1;
		}
	}
	if (month == 4 || month == 6 || month == 9 || month == 11){
		if (day > 0 && day <= 30){
			return 1;
		}
	}
	return 0;
}
int Older(int day1, int month1, int year1, int day2, int month2, int year2){
	if (year1 < year2)
		return 1;
	else if (year1 > year2)
		return 2;
	else{
		if (month1 < month2)
			return 1;
		else if (month1 > month2)
			return 2;
		else{
			if (day1 < day2)
				return 1;
			else if (day1 > day2)
				return 2;
			else
				return 0;
		}
	}
}
