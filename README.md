# Arduino Fuzzy Logic Temperature and Humidity Controller

## Description

This Arduino project uses fuzzy logic to analyze temperature and humidity data to provide a qualitative evaluation of the environmental conditions. The system categorizes temperature and humidity into various ranges and then determines an overall result based on predefined rules.

## Prerequisites

- **Arduino Board**: Any Arduino compatible board (e.g., Arduino Uno, Mega).
- **Libraries**: None required (standard Arduino libraries used).

## Code Overview

### Variables

- **Temperature and Humidity Data**:
  - `suhu`: Current temperature.
  - `kelembaban`: Current humidity.
- **Temperature and Humidity Ranges**:
  - Defined ranges for cold, normal, and hot temperatures.
  - Defined ranges for dry, moderate, and wet humidity levels.

### Functions

#### Rule Functions

- **Temperature Rules**:
  - `suhuLow()`: Determines the membership value for "cold" temperature.
  - `suhuMedium()`: Determines the membership value for "normal" temperature.
  - `suhuHigh()`: Determines the membership value for "hot" temperature.
- **Humidity Rules**:
  - `kelembabanLow()`: Determines the membership value for "dry" humidity.
  - `kelembabanMedium()`: Determines the membership value for "moderate" humidity.
  - `kelembabanHigh()`: Determines the membership value for "wet" humidity.

#### Fuzzification and Fuzzy Rules

- **`fuzzifikasi()`**: Executes all the rule functions to fuzzify temperature and humidity data.
- **`fuzzy_rule()`**: Applies fuzzy rules to categorize temperature and humidity conditions and derives the overall result based on the combination of conditions.

#### Setup and Loop

- **`setup()`**:
  - Initializes the serial communication.
  - Sets sample values for temperature and humidity.
  - Calls `fuzzy_rule()` to compute conditions and prints the results to the serial monitor.
- **`loop()`**:
  - Empty in this version; can be used for additional functionality if needed.

## Usage

1. **Upload the Code**:

   - Connect your Arduino to your computer.
   - Open the Arduino IDE, paste the provided code, and upload it to the Arduino.

2. **Open Serial Monitor**:
   - Open the Serial Monitor in the Arduino IDE (set baud rate to 9600).
   - You will see the temperature and humidity conditions and the derived result displayed.

## Notes

- Adjust the `suhu` and `kelembaban` variables in the `setup()` function to test different scenarios.
- The temperature and humidity ranges are predefined; modify them as needed to fit your specific use case.

## Author

- [Your Name] - [Your Email]

## License

- This project is licensed under [License Name] - see [LICENSE](LICENSE) for details.
