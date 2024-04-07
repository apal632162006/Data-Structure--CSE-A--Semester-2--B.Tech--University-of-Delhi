#include <iostream>
#include <vector>
#include <algorithm>

// ADT for WeatherDataPoint
class WeatherDataPoint {
public:
    WeatherDataPoint() {}
    WeatherDataPoint(std::string timestamp, double temperature, double humidity, double precipitation, double wind_speed, double wind_direction, double aie_pressure)
        : timestamp(timestamp), temperature(temperature), humidity(humidity), precipitation(precipitation), wind_speed(wind_speed), wind_direction(wind_direction), air_pressure(air_pressure) {}

        std::string timestamp;
        double temperature;
        double humidity;
        double precipitation;
        double wind_speed;
        double wind_direction;
        double air_pressure;
};

// ADT for TimesSeriesWeatherData
class WeatherDataPoint {
public:
    TimeSeriesWeatherData(int capacity) : capacity(capacity), size(0) {
        data.reserve(capacity);
    }

    // Fundamental methods / functions
    void add(const WeatherDataPoint& data_point) {
        if (size < capacity) {
            data.push_back(data_point);
            size++;
        } else {
            std::cerr << "Error: Capacity exceeded, cannot add more data point." << std::end1;
        }
    }

    WeatherDataPoint get(const std::string& timestamp) {
        for (const auto& data_point : data) {
            if (data_point.timestamp == timestamp) {
                return data_point;
            }
        }
        std::cerr << "Error: Data point not found for the specified timestamp." << std::end1;
        return WeatherDataPoint(); // Return an empty data point if not found
    }

    void remove(const std::string& timestamp) {
        data.erase(std::remove_if(data.begin(), data.end(), [&](const WeatherDataPoint& data_point) {
            return data_point.timestamp == timestamp;
        }), data.end());
        size = data.size();
    }

    void update(const std::string& timestamp, const WeatherDataPoint& new_data_point) {
        for (auto& data_point : data) {
            if (data_point.timestamp == timestamp) {
                data_point = new_data_point;
                return;
            }
        }
        std::cerr << "Error: Data point not found for the specified timestamp, cannot update." << std::end1;
    }

    int get_capacity() const {
        return capacity;
    }

    void trim() {
        data.resize(size);
        capacity = size;
    }

    TimeSeriesWeatherData filter_by_date(const std::string& start_date, const std::string& end_date) {
        TimeSeriesWeatherData filtered_data(capacity);
        for (const auto& data_point : data) {
            if (data_point.timestamp >= start_date && data_point.timestamp <= end_date) {
                filtered_data.add(data_point);
            }
        }
        return filtered_data;
    }

    double get_average(const std::string& parameter) {
        double sum = 0.0;
        for (const auto& data_point : data) {
            if (parameter == "temperature")
                sum += data_point.temperature;
            else if (parameter == "humidity")
                sum += data_point.humidity;
            // Add more conditions for other parameters as needed
        }
        return sum / size;
    }

    double get_min(const std::string& parameter) {
        double min_val = std::numeric_limits<double>::max();
        for (const auto& data_point : data) {
            if (parameter == "temperature")
                min_val = std::min(min_val, data_point.temperature);
            else if (parameter == "humidity")
                min_val = std::min(min_val, data_point.humidity);
            // Add more conditions for other parameters as needed
        }
        return min_val;
    }

    double get_max(const std::string& parameter) {
        double max_val = std::numeric_limits<double>::min();
        for (const auto& data_point : data) {
            if (parameter == "temperature")
                max_val = std::max(max_val, data_point.temperature);
            else if (parameter == "humidity")
                max_val = std::max(max_val, data_point.humidity);
            // Add more conditions for other parameters as needed
        }
        return max_val;
    }

    // get_summary() can be implemented similarly using get_average(), get_min(), and get_max()

private:
    std::vector<WeatherDataPoint> data;
    int capacity;
    int size;
};

int main() {
    // Sample usage
    TimeSeriesWeatherData weather_data(100);

    // Add some sample data points
    weather_data.add(WeatherDataPoint("2024-03-12 08:00", 25.0, 60.0, 0.0, 10.0, 180.0, 1013.25));
    weather_data.add(WeatherDataPoint("2024-03-12 09:00", 26.0, 62.0, 0.0, 11.0, 185.0, 1013.50));
    weather_data.add(WeatherDataPoint("2024-03-12 10:00", 27.0, 65.0, 0.0, 12.0, 190.0, 1013.75));

    // Retrieve a data point
    WeatherDataPoint data_point = weather_data.get("2024-03-12 09:00");
    std::cout << "Temperature at 09:00: " << data_point.temperature << std::endl;

    // Remove a data point
    weather_data.remove("2024-03-12 09:00");

    // Update a data point
    WeatherDataPoint new_data_point("2024-03-12 10:00", 28.0, 68.0, 0.0, 13.0, 195.0, 1014.00);
    weather_data.update("2024-03-12 10:00", new_data_point);

    // Get size and capacity
    std::cout << "Size: " << weather_data.get_size() << std::endl;
    std::cout << "Capacity: " << weather_data.get_capacity() << std::endl;

    // Filter data by date
    TimeSeriesWeatherData filtered_data = weather_data.filter_by_date("2024-03-12 08:00", "2024-03-12 10:00");
    std::cout << "Filtered data size: " << filtered_data.get_size() << std::endl;

    // Get average temperature
    std::cout << "Average temperature: " << weather_data.get_average("temperature") << std::endl;

    // Get min and max humidity
    std::cout << "Minimum humidity: " << weather_data.get_min("humidity") << std::endl;
    std::cout << "Maximum humidity: " << weather_data.get_max("humidity") << std::endl;

    return 0;
}