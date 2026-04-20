#include <stdio.h>

void convert_lengths(void);
void convert_weights(void);
void length_to_metric(void);
void length_to_us(void);
void weight_to_metric(void);
void weight_to_us(void);
void clearBuffer(void);
int readIntInRange(const char *prompt, int min, int max);
double readNonNegativeDouble(const char *prompt);

void clearBuffer(void) {
   int c;
   while ((c = getchar()) != '\n' && c != EOF) {
   }
}

int readIntInRange(const char *prompt, int min, int max) {
   int value;

   while (1) {
       printf("%s", prompt);

       if (scanf("%d", &value) != 1) {
           printf("Invalid input. Please enter a whole number.\n");
           clearBuffer();
           continue;
       }

       clearBuffer();

       if (value < min || value > max) {
           printf("Please enter a number between %d and %d.\n", min, max);
           continue;
       }

       return value;
   }
}

double readNonNegativeDouble(const char *prompt) {
   double value;

   while (1) {
       printf("%s", prompt);

       if (scanf("%lf", &value) != 1) {
           printf("Invalid input. Please enter a number.\n");
           clearBuffer();
           continue;
       }

       clearBuffer();

       if (value < 0) {
           printf("Please enter a non-negative number.\n");
           continue;
       }

       return value;
   }
}

void length_to_metric(void) {
   double feet = readNonNegativeDouble("Enter feet: ");
   double inches = readNonNegativeDouble("Enter inches: ");

   double total_inches = feet * 12.0 + inches;
   double total_centimeters = total_inches * 2.54;
   int meters = (int)(total_centimeters / 100.0);
   double centimeters = total_centimeters - (meters * 100.0);

   printf("%.2f feet and %.2f inches = %d meter(s) and %.2f centimeter(s).\n\n",
          feet, inches, meters, centimeters);
}

void length_to_us(void) {
   double meters = readNonNegativeDouble("Enter meters: ");
   double centimeters = readNonNegativeDouble("Enter centimeters: ");

   double total_centimeters = meters * 100.0 + centimeters;
   double total_inches = total_centimeters / 2.54;
   int feet = (int)(total_inches / 12.0);
   double inches = total_inches - (feet * 12.0);

   printf("%.2f meter(s) and %.2f centimeter(s) = %d feet and %.2f inches.\n\n",
          meters, centimeters, feet, inches);
}

void weight_to_metric(void) {
   double pounds = readNonNegativeDouble("Enter pounds: ");
   double ounces = readNonNegativeDouble("Enter ounces: ");

   double total_ounces = pounds * 16.0 + ounces;
   double total_grams = total_ounces * 28.3495;
   int kilograms = (int)(total_grams / 1000.0);
   double grams = total_grams - (kilograms * 1000.0);

   printf("%.2f pound(s) and %.2f ounce(s) = %d kilogram(s) and %.2f gram(s).\n\n",
          pounds, ounces, kilograms, grams);
}

void weight_to_us(void) {
   double kilograms = readNonNegativeDouble("Enter kilograms: ");
   double grams = readNonNegativeDouble("Enter grams: ");

   double total_grams = kilograms * 1000.0 + grams;
   double total_ounces = total_grams / 28.3495;
   int pounds = (int)(total_ounces / 16.0);
   double ounces = total_ounces - (pounds * 16.0);

   printf("%.2f kilogram(s) and %.2f gram(s) = %d pound(s) and %.2f ounce(s).\n\n",
          kilograms, grams, pounds, ounces);
}

void convert_lengths(void) {
   int choice;

   while (1) {
       printf("\n--- Length Conversion Menu ---\n");
       printf("1.) Convert feet/inches to meters/centimeters\n");
       printf("2.) Convert meters/centimeters to feet/inches\n");
       printf("0.) Return to the main menu\n");

       choice = readIntInRange("Enter your choice (0, 1, or 2): ", 0, 2);

       if (choice == 1) {
           length_to_metric();
       } else if (choice == 2) {
           length_to_us();
       } else {
           printf("Returning to the main menu...\n\n");
           return;
       }
   }
}

void convert_weights(void) {
   int choice;

   while (1) {
       printf("\n--- Weight Conversion Menu ---\n");
       printf("1.) Convert pounds/ounces to kilograms/grams\n");
       printf("2.) Convert kilograms/grams to pounds/ounces\n");
       printf("0.) Return to the main menu\n");

       choice = readIntInRange("Enter your choice (0, 1, or 2): ", 0, 2);

       if (choice == 1) {
           weight_to_metric();
       } else if (choice == 2) {
           weight_to_us();
       } else {
           printf("Returning to the main menu...\n\n");
           return;
       }
   }
}

int main(void) {
   int choice;

   while (1) {
       printf("-------------------\n");
       printf("Main Menu\n");
       printf("1.) Convert lengths\n");
       printf("2.) Convert weights\n");
       printf("0.) Exit\n");

       choice = readIntInRange("Enter your choice (0, 1, or 2): ", 0, 2);

       if (choice == 1) {
           convert_lengths();
       } else if (choice == 2) {
           convert_weights();
       } else {
           printf("Exiting program.\n");
           break;
       }
   }

   return 0;
}