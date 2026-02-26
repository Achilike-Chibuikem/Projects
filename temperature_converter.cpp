#include <iostream>
#include <iomanip>

using namespace std;

// Conversion functions
double celsiusToFahrenheit(double c) { return (c * 9.0 / 5.0) + 32; }
double celsiusToKelvin(double c) { return c + 273.15; }

double fahrenheitToCelsius(double f) { return (f - 32) * 5.0 / 9.0; }
double fahrenheitToKelvin(double f) { return fahrenheitToCelsius(f) + 273.15; }

double kelvinToCelsius(double k) { return k - 273.15; }
double kelvinToFahrenheit(double k) { return celsiusToFahrenheit(kelvinToCelsius(k)); }

void displayMenu()
{
    cout << "\n===== Temperature Converter =====" << endl;
    cout << "1. Celsius    -> Fahrenheit & Kelvin" << endl;
    cout << "2. Fahrenheit -> Celsius & Kelvin" << endl;
    cout << "3. Kelvin     -> Celsius & Fahrenheit" << endl;
    cout << "4. Exit" << endl;
    cout << "=================================" << endl;
    cout << "Enter choice: ";
}

int main()
{
    int choice;
    double temp;

    cout << fixed << setprecision(2);

    while (true)
    {
        displayMenu();
        cin >> choice;

        if (choice == 4)
        {
            cout << "Goodbye!" << endl;
            break;
        }

        if (choice < 1 || choice > 3)
        {
            cout << "Invalid choice! Please try again." << endl;
            continue;
        }

        switch (choice)
        {
        case 1:
            cout << "Enter temperature in Celsius: ";
            cin >> temp;
            cout << "\n--- Results ---" << endl;
            cout << temp << " C  =  " << celsiusToFahrenheit(temp) << " F" << endl;
            cout << temp << " C  =  " << celsiusToKelvin(temp) << " K" << endl;
            break;

        case 2:
            cout << "Enter temperature in Fahrenheit: ";
            cin >> temp;
            cout << "\n--- Results ---" << endl;
            cout << temp << " F  =  " << fahrenheitToCelsius(temp) << " C" << endl;
            cout << temp << " F  =  " << fahrenheitToKelvin(temp) << " K" << endl;
            break;

        case 3:
            cout << "Enter temperature in Kelvin: ";
            cin >> temp;
            if (temp < 0)
            {
                cout << "Error: Kelvin cannot be negative!" << endl;
                break;
            }
            cout << "\n--- Results ---" << endl;
            cout << temp << " K  =  " << kelvinToCelsius(temp) << " C" << endl;
            cout << temp << " K  =  " << kelvinToFahrenheit(temp) << " F" << endl;
            break;
        }
    }

    return 0;
}