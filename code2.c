#include <stdio.h>
#include <stdlib.h>

/*declaring functions and types*/
float celsius_to_fahrenheit(float celsius);
float fahrenheit_to_celsius(float fahrenheit);
float celsius_to_kelvin(float celsius);
float kelvin_to_celsius(float kelvin);
float fahrenheit_to_kelvin(float fahrenheit);
float kelvin_to_fahrenheit(float kelvin);
void categorize_temperature(float celsius);

int main() {
    /*gets  a temp from uses and mode its in and mode to go to*/
    float temp_input, converted_temp;
    int input_scale, target_scale;
    int result;

    while (1) { 
        /*runs until user enters 0*/
        printf("Enter the temperature (0 to exit): ");
        result = scanf("%f", &temp_input);
        if (result != 1 || temp_input == 0) {
            printf("Exiting the program.\n");
            break;
        }
        printf("Choose the current scale (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
        result = scanf("%d", &input_scale);
        if (result != 1 || input_scale < 1 || input_scale > 3) {
            printf("Invalid choice for temperature scale.\n");
            continue;
        }
        /*Input target */ 
        printf("Convert to (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
        result = scanf("%d", &target_scale);
        if (result != 1 || target_scale < 1 || target_scale > 3) {
            printf("Invalid choice for target scale.\n");
            continue;
        }
        /*Error checking*/
        if (input_scale == 3 && temp_input < 0) {
            printf("Invalid temperature. Kelvin cannot be negative.\n");
            continue; // Prompt user again
        }
        /*checks if they are the same scale*/
        if (input_scale == target_scale) {
            printf("No conversion needed. Same temperature scale selected.\n");
            continue; // Prompt user again
        }

        switch (input_scale) {
            /*celsius input*/
            case 1:
                if (target_scale == 2) {
                    converted_temp = celsius_to_fahrenheit(temp_input);
                } else if (target_scale == 3) {
                    converted_temp = celsius_to_kelvin(temp_input);
                }
                break;
            /*fahrenheit input*/
            case 2:
                if (target_scale == 1) {
                    converted_temp = fahrenheit_to_celsius(temp_input);
                } else if (target_scale == 3) {
                    converted_temp = fahrenheit_to_kelvin(temp_input);
                }
                break;
            /*kelvin input*/
            case 3: 
                if (target_scale == 1) {
                    converted_temp = kelvin_to_celsius(temp_input);
                } else if (target_scale == 2) {
                    converted_temp = kelvin_to_fahrenheit(temp_input);
                }
                break;
        }

        /*print converted temp*/
        switch (target_scale) {
            case 1:
                printf("Converted temperature: %.2f°C\n", converted_temp);
                categorize_temperature(converted_temp);  // Categorize and give advisory based on Celsius
                break;
            case 2:
                printf("Converted temperature: %.2f°F\n", converted_temp);
                categorize_temperature(fahrenheit_to_celsius(converted_temp));  // Convert to Celsius for categorization
                break;
            case 3:
                printf("Converted temperature: %.2fK\n", converted_temp);
                categorize_temperature(kelvin_to_celsius(converted_temp));  // Convert to Celsius for categorization
                break;
        }
    }

    return 0;
}
/*converts celsius to fahrenheit*/
float celsius_to_fahrenheit(float celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}
/*converts fahrenheit to celsius*/
float fahrenheit_to_celsius(float fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}
/*converts celsius to kelvin*/
float celsius_to_kelvin(float celsius) {
    return celsius + 273.15;
}
/*converts kelvin to celsius*/
float kelvin_to_celsius(float kelvin) {
    return kelvin - 273.15;
}
/*converts fahrenheit to kelvin*/
float fahrenheit_to_kelvin(float fahrenheit) {
    return celsius_to_kelvin(fahrenheit_to_celsius(fahrenheit));
}
/*converts kelvin to fahrenheit */
float kelvin_to_fahrenheit(float kelvin) {
    return celsius_to_fahrenheit(kelvin_to_celsius(kelvin));
}
/*prints what it feels like based on intup temp*/
void categorize_temperature(float celsius) {
    if (celsius < 0) {
        printf("Temperature category: Freezing\n");
        printf("Weather advisory: It's freezing. Stay warm!\n");
    } else if (celsius >= 0 && celsius < 10) {
        printf("Temperature category: Cold\n");
        printf("Weather advisory: Wear a jacket.\n");
    } else if (celsius >= 10 && celsius < 25) {
        printf("Temperature category: Comfortable\n");
        printf("Weather advisory: You should feel comfortable.\n");
    } else if (celsius >= 25 && celsius < 35) {
        printf("Temperature category: Hot\n");
        printf("Weather advisory: It's getting warm. Stay hydrated.\n");
    } else {
        printf("Temperature category: Extreme Heat\n");
        printf("Weather advisory: Extreme heat. Stay indoors and stay cool!\n");
    }
}
