#ifndef WEATHER_H
#define WEATHER_H

#include <stdlib.h>
#include <time.h>

typedef enum {
    SEASON_SPRING,
    SEASON_SUMMER,
    SEASON_AUTUMN,
    SEASON_WINTER
} Season;

typedef enum {
    WEATHER_SUNNY,
    WEATHER_RAINY,
    WEATHER_CLOUDY,
    WEATHER_DROUGHT
} Weather;

const char* getSeasonName(Season season);
const char* getWeatherName(Weather weather);



#endif    // WEATHER_H