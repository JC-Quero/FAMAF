#ifndef _WEATHER_UTILS
#define _WEATHER_UTILS

#include <stdio.h>
#include "weather.h"
#include "weather_table.h"


int historic_tempMin(WeatherTable a);


void tempMax(WeatherTable a, int output[YEARS]);

unsigned int sum_month_rainfall(WeatherTable a, unsigned int year, month_t month);

void maxMonthPreYear(WeatherTable a, month_t output[YEARS]);



#endif //_WEATHER_UTILS