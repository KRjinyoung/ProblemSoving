#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"

struct Date
{
	int month;
	int day;
	int year;
};

void printDate_KoreaStyle(const struct Date *d)
{
	printf("%d년 %d월 %d일\n", d->year, d->month, d->day);
}

void printDate(const struct Date *d)
{
	printf("%d-%d-%d\n", d->year, d->month, d->day); // Corrected the order for proper output
}

int Days(const struct Date *d)
{
	int days = 0;

	days += (d->year - 2000) * 360; // Calculate years in days
	days += (d->month - 1) * 30;	// Approximate month to days
	days += (d->day - 1);			// Add days

	return days;
}

struct Date *recent(struct Date *d1, struct Date *d2)
{
	if (d1->year > d2->year)
	{
		return d1;
	}
	if (d1->year < d2->year)
	{
		return d2;
	}

	// If years are equal, check months
	if (d1->month > d2->month)
	{
		return d1;
	}
	if (d1->month < d2->month)
	{
		return d2;
	}

	// If months are equal, check days
	if (d1->day > d2->day)
	{
		return d1;
	}
	if (d1->day < d2->day)
	{
		return d2;
	}

	// If they are equal, return one of them
	return d1; // or d2
}

int main()
{
	struct Date d1 = {10, 16, 2024},
				d2 = {5, 8, 2025};

	printDate_KoreaStyle(&d1);
	printf("2000년 1월 1일 기준 %d일 경과하였습니다.\n",
		   Days(&d1));

	printf("가장 최근의 날짜: ");
	printDate(recent(&d1, &d2));

	return 0;
}
