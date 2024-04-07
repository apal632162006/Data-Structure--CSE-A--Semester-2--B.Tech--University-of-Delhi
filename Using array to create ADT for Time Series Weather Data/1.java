public class TimeSeriesWeatherData {
    private int[] timestamps;
    private double[] temperatures;
    private double[] humidities;
    private int size; // Current size of the data arrays
    private static final int INITIAL_CAPACITY = 10; // Initial capacity of the arrays

    // Constructor
    public TimeSeriesWeatherData() {
        timestamps = new int[INITIAL_CAPACITY];
        temperatures = new double[INITIAL_CAPACITY];
        humidities = new double[INITIAL_CAPACITY];
        size = 0;
    }

    // Method to add data
    public void addData(int timestamp, double temperature, double humidity) {
        if (size == timestamps.length) {
            // If arrays are full, double their capacity
            expandCapacity();
        }
        timestamps[size] = timestamp;
        temperatures[size] = temperature;
        humidities[size] = humidity;
        size++;
    }

    // Method to double the capacity of arrays
    private void expandCapacity() {
        int newCapacity = timestamps.length * 2;
        int[] newTimestamps = new int[newCapacity];
        double[] newTemperatures = new double[newCapacity];
        double[] newHumidities = new double[newCapacity];
        System.arraycopy(timestamps, 0, newTimestamps, 0, size);
        System.arraycopy(temperatures, 0, newTemperatures, 0, size);
        System.arraycopy(humidities, 0, newHumidities, 0, size);
        timestamps = newTimestamps;
        temperatures = newTemperatures;
        humidities = newHumidities;
    }

    // Method to get temperature at a specific index
    public double getTemperature(int index) {
        if (index < 0 || index >= size) {
            throw new IndexOutOfBoundsException("Index out of bounds");
        }
        return temperatures[index];
    }

    // Method to get humidity at a specific index
    public double getHumidity(int index) {
        if (index < 0 || index >= size) {
            throw new IndexOutOfBoundsException("Index out of bounds");
        }
        return humidities[index];
    }

    // Method to get the size of the data
    public int size() {
        return size;
    }

    // Method to get all timestamps
    public int[] getTimestamps() {
        int[] copy = new int[size];
        System.arraycopy(timestamps, 0, copy, 0, size);
        return copy;
    }

    // Method to get all temperatures
    public double[] getTemperatures() {
        double[] copy = new double[size];
        System.arraycopy(temperatures, 0, copy, 0, size);
        return copy;
    }

    // Method to get all humidities
    public double[] getHumidities() {
        double[] copy = new double[size];
        System.arraycopy(humidities, 0, copy, 0, size);
        return copy;
    }

    // Main method for testing
    public static void main(String[] args) {
        TimeSeriesWeatherData weatherData = new TimeSeriesWeatherData();
        weatherData.addData(1, 25.0, 0.6);
        weatherData.addData(2, 26.0, 0.5);
        weatherData.addData(3, 24.5, 0.7);

        System.out.println("Size: " + weatherData.size());
        System.out.println("Temperature at index 1: " + weatherData.getTemperature(1));
        System.out.println("Humidity at index 1: " + weatherData.getHumidity(1));

        int[] timestamps = weatherData.getTimestamps();
        double[] temperatures = weatherData.getTemperatures();
        double[] humidities = weatherData.getHumidities();

        System.out.println("Timestamps:");
        for (int timestamp : timestamps) {
            System.out.print(timestamp + " ");
        }
        System.out.println();

        System.out.println("Temperatures:");
        for (double temperature : temperatures) {
            System.out.print(temperature + " ");
        }
        System.out.println();

        System.out.println("Humidities:");
        for (double humidity : humidities) {
            System.out.print(humidity + " ");
        }
        System.out.println();
    }
}