# ULTRASONIC Library

A C++ library for interfacing with ultrasonic sensors. This library provides methods to measure distance, detect objects, and filter out noise to obtain smoothed distance values.

## Installation

1. Download or clone the repository.
2. Copy the `ULTRASONIC` folder to your desired directory.

## Usage

### Including the Library

Include the `ULTRASONIC` library in your sketch.

### Creating an Instance

Create an instance of the `ULTRASONIC` class by specifying the trigger and echo pins.

### Measuring Distance

To measure distance, use the `get_distance` method. You can specify the unit of measurement (default is centimeters).

### Object Detection

To check if an object is within a specified distance, use the `object_detected` method.

### Printing Distance

To print the measured distance to the serial monitor, use the `print_distance` method.

### Smoothed Distance

To get a noise-filtered distance measurement, use the `get_smoothed_distance` method.

## Example Sketch

An example sketch demonstrating the usage of the library is included in the repository.
