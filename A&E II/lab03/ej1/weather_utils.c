#include <stdio.h>

#include "weather_utils.h"

int historic_tempMin(WeatherTable a){
    int h_min = a[0][0][0]._min_temp;

    for(unsigned int year = 0; year < YEARS; ++year){
        for(month_t month = january; month <= december; month++){
            for(unsigned int day = 0; day < DAYS; ++day){
                int current = a[year][month][day]._min_temp;

                if(current < h_min){
                    h_min = current;
                }
            }
        }
    }
    return h_min;
}

void tempMax(WeatherTable a, int output[YEARS]){
    for(unsigned int year = 0; year < YEARS; ++year){
        int max = a[year][0][0]._max_temp;

        for(month_t month = january; month <= december; ++month){
            for(unsigned int day = 0; day < DAYS; ++day){
                int current = a[year][month][day]._max_temp;
                if(current > max){
                    max = current;
                }
            }
        }
        output[year] = max;
    }
}

unsigned int sum_month_rainfall(WeatherTable a, unsigned int year, month_t month){
    unsigned int sum = 0;

    for(unsigned int day = 0; day < DAYS; ++day){
        sum+= a[year][month][day]._rainfall;
    }

    return sum;
}


void maxMonthPreYear(WeatherTable a, month_t output[YEARS]){
    for(unsigned int year = 0; year < YEARS; ++year){
        unsigned int max_rain = sum_month_rainfall(a,year,january);
        month_t max_month = january;


        for(month_t month = february; month <= december; ++month){
            unsigned int total = sum_month_rainfall(a,year,month);

            if(total > max_rain){
                max_rain = total;
                max_month = month;
            }
        }
        output[year] = max_month;
    }
}
