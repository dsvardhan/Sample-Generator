/*
Name: Srinivas Vardhan Dintakurthi
Class Name: CS-1337 Computer Programming-1
Date:09/12/2022
Description: This program will ask the user for maximum, minimum, number of samples and generates random numbers. Then it finds the average, standard deviation,
variance and displays the samples in a table. 
*/

#include<iostream>//cout/cin
#include<iomanip> //For output manipulation
#include<cstdlib> //For random numbers
#include<ctime>//For random numbers
#include<cmath>//For pow function
using namespace std;

int main() {

	//Variables to store min,max,number of samples and delta
	int min, max;
	int n;
	double d; 

	//Prompt for min and max

	bool invalid_limits ; //Flag for input validation of limits
	do {
		cout << "Please enter the minimum and maximum value\n";
		cin >> min >> max;

		invalid_limits = false;

		if (min > max) {
			cout << "Enter valid values where min<=max\n";
			 invalid_limits = true;
		}
	} while (invalid_limits);

	//Prompt for n and delta

	bool invalid ;//Flag for input validation of n and delta

	do {
		cout << "Enter the number of samples given 1<=n<=80 and smallest difference\n";
		cin >> n >> d;

		invalid = false;

		if (1 <= n && n <= 80 && d <= (max - min)) {

		}
		else {
			cout << "Please check that n is between 1 and 80 and delta is less than or equal to the difference between min and max\n";
			invalid = true;
		}
	} while (invalid);


	//Calculating average, standard deviation, variance after generating random numbers of entered size
	
	double average;// Variable for average
	double standardDeviation;//Variable for standard deviation
	float variance;//Variable for variance

	//Generating random numbers between min and max with difference >= delta

	double a=0, sd=0;

	int new_max = max / d; //Manipulating maximum to make sure min. difference between 2 different smaples is greater than delta
	int i;

	srand(7);
// Calculating average
	for ( i = 0; i < n; i++) {

		//Generating sample-sized random numbers and then manipulating them back

		int rand_num = min + rand() % (new_max - min + 1);
		double rand_double = rand_num * d;

		a += rand_double;
	}

	average = a / n;

	//Calculating standard deviation

	srand(7);
	for (int i = 0; i < n; i++) {

		//Generating sample-sized random numbers and then manipulating them back
		int rand_num = min + rand() % (new_max - min + 1);
		double rand_double = rand_num * d;

		sd=sd+ pow((rand_double-average),2.0);
	}

	standardDeviation = pow((sd / n), 0.5);

	variance = pow(standardDeviation, 2.0);



	//Create a table of all samples 
	srand(7);
	for (int i = 1; i <=n; i++) {

		//Generating sample-sized random numbers and then manipulating them ba
		int rand_num = min + rand() % (new_max - min + 1);
		double rand_double = rand_num * d;

		//Manipulate Output
		cout << setw(10)<<setprecision(3)<<showpos<<rand_double;

		if ((i % 4)== 0) {
			cout << endl;
		}
	}

	cout << endl;


	// Show the three parameters at the bottom of the table

	cout << noshowpos;
	cout << endl<<"Average of " << n << " samples is: " <<fixed<< average << endl;
	cout << "Standard Deviation of " << n << " samples is: " <<fixed<< standardDeviation << endl;
	cout << "Variance of " << n << " samples is: " <<fixed<< variance << endl;

	return 0;
}