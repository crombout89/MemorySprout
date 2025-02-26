#include "weather.h"

const char* getSeasonName(Season season) {
    switch (season) {
        case SEASON_SPRING: return "Spring";
        case SEASON_SUMMER: return "Summer";
        case SEASON_AUTUMN: return "Autumn";
        case SEASON_WINTER: return "Winter";
        default:            return "Unknown Season";
    }
}

const char* getWeatherName(Weather weather) {
    switch (weather) {
        case WEATHER_SUNNY: return "Sunny";
        case WEATHER_RAINY: return "Rainy";
        case WEATHER_CLOUDY: return "Cloudy";
        case WEATHER_DROUGHT: return "Drought";
        default:             return "Unknown Weather";
    }
}