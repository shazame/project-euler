/*******************************
 * Site: Project Euler
 * Link: http://projecteuler.net/problems
 * Problem:
 * You are given the following information, but you may prefer to do some research for yourself.
 * 
 *     1 Jan 1900 was a Monday.
 *     Thirty days has September,
 *     April, June and November.
 *     All the rest have thirty-one,
 *     Saving February alone,
 *     Which has twenty-eight, rain or shine.
 *     And on leap years, twenty-nine.
 *     A leap year occurs on any year evenly divisible by 4, but not on a century unless it is divisible by 400.
 * 
 * How many Sundays fell on the first of the month during the twentieth century (1 Jan 1901 to 31 Dec 2000)?
 * 
 * Solution by: David
 * Answer: 171
 *******************************/

#include <stdio.h>

struct date{
	int jour;   // 1:lundi, ..., 7:dimanche
	int j_ds_m; // [1,31]
	int mois;   // 1:janvier, ..., 12:décembre
	int an;
};

void init_date(struct date *date, int j, int jm, int m, int a)
{
	date->jour = j;
	date->j_ds_m = jm;
	date->mois = m;
	date->an = a;
}

int is_leap_year(int year)
{
	if (year % 100 == 0)
		return year % 400 == 0;
	else 
		return year % 4 == 0;
}

int nb_jour_ds_mois(int mois, int an)
{
	if (mois == 2)
	{
		if (is_leap_year(an))
			return 29;
		else
			return 28;
	}
	else
	{
		if ((mois % 2 && mois <= 7) || (mois % 2 == 0 && mois >= 8))
			return 31;
		else
			return 30;
	}
}

void incr_date(struct date *date)
{
	int incr_mois = 0, incr_an = 0;

	date->jour = (date->jour % 7) + 1;
	
	if (date->j_ds_m == nb_jour_ds_mois(date->mois,date->an))
	{
		date->j_ds_m = 1;
		incr_mois = 1;
	}
	else
		date->j_ds_m++;

	if(incr_mois)
	{
		if(date->mois == 12)
		{	
			date->mois = 1;
			incr_an = 1;
		}else
			date->mois++;

		if(incr_an)
			date->an++;
	}
}

int main(void)
{
	struct date date;
	int compteur = 0;

	init_date(&date, 1, 1, 1, 1900);
	
	while(date.an != 1901 || date.mois != 1 || date.j_ds_m != 1)
		incr_date(&date);

	do{
		if(date.jour == 7 && date.j_ds_m == 1)	
			compteur++;

		incr_date(&date);
	}while(date.an != 2000 || date.mois != 12 || date.j_ds_m != 31);

	printf("%d\n", compteur);

	return 0;
}
