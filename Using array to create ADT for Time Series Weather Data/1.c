#include <stdio.h>
#include <stdlib.h>

#define MAX_DATA_POINTS 100

// Structure to represent a single data point
typedef struct {
    int year;
    int month;
    int day;
    float temperature;
    float precipitation;
} WeatherDataPoint;

// Structure to represent time series weather data
typedef struct {
    WeatherDataPoint data[MAX_DATA_POINTS];
    int size;
} TimeSeriesWeatherData;

// Function to initialize the time series data
void initialize(TimeSeriesWeatherData *tsData) {
    tsData->size = 0;
}

// Function to add a data point to the time series data
void addDataPoint(TimeSeriesWeatherData *tsData, WeatherDataPoint newData) {
    if (tsData->size < MAX_DATA_POINTS) {
        tsData->data[tsData->size++] = newData;
    } else {
        printf("Error: Data points limit reached\n");
    }
}

// Function to print all data points in the time series
void printData(TimeSeriesWeatherData tsData) {
    printf("Year\tMonth\tDay\tTemperature\tPrecipitation\n");
    for (int i = 0; i < tsData.size; i++) {
        printf("%d\t%d\t%d\t%.2f\t\t%.2f\n", tsData.data[i].year, tsData.data[i].month,
               tsData.data[i].day, tsData.data[i].temperature, tsData.data[i].precipitation);
    }
}

int main() {
    TimeSeriesWeatherData weatherData;
    initialize(&weatherData);

    // Adding some sample data points
    addDataPoint(&weatherData, (WeatherDataPoint){2024, 3, 21, 25.5, 0.0});
    addDataPoint(&weatherData, (WeatherDataPoint){2024, 3, 22, 26.0, 0.5});
    addDataPoint(&weatherData, (WeatherDataPoint){2024, 3, 23, 24.0, 1.2});

    // Printing the data
    printData(weatherData);

    return 0;
}