// Skynet-HK-Aerial-Drone.cpp : Defines the entry point for the console application.
//Documentation
/* Write a program in C++ for the Skynet HK-Aerial
You should initialize a grid search of 8x8.

On each run, your program should choose a random numbered square on the grid numbered 1-64 to 
	indicate where the enemy is located.

The enemy does not move in this simulation.

This program should be able to search for ground based enemies faster then when in the current 
	linear search HK mode, however, you do not need to code in this comparision.

This program is for it's internal AI only and does not require human other other AI players.

This program should keep track of each turn and display this.

This program should use an unpredictable search pattern to the human on the ground.

The AI should used a Binary Search Pattern.

This program should loop unitl the Grid that the enemy is on is found by the Skynet HK-Aerial. 
At that point the found and engaging enemy status is displayed along with other information such 
as how long it took to find them by showing how many grids the HK searched before finding the enemy, 
what where the cordinates of the grids the HK looked at, and how large the search grid was. */

#include "stdafx.h"
#include <cstdlib> // includes random number generation
#include <iostream> // includes objects cout
#include <time.h> // include the time when the user opened the program

using namespace std;

int i = 1; // loop counter

// A recursive binary search function. It returns 
// location of enemy x in given array arr[l-64] is present, 
// otherwise -1
int binarySearch(int arr[], int l, int r, int x)
{
	while (r >= l)
	{
		int mid = l + (r - l) / 2;

		cout << "============================================================" << endl;
		cout << "Skynet HK-Aerial Radar sending out ping #" << i << endl;

		// If the element is present at the middle
		// Then the target number is itself
		// ***To compensate on finding the random number and not
		// ***Just the index number it is located on the array.
		// ***We add 1 to mid to show what number it is Actually comparing

		if (arr[mid] == x)
		{
			cout << "Enemy was hiding at location #" << x << endl;
			cout << "Target was found at location #" << mid + 1 << endl;
			return mid;
		}

		// If element is smaller than mid, then 
		// it can only be present in left subarray

		if (arr[mid] > x)
		{
			cout << "The target location prediction of " << mid + 1 <<
				" is greater than target enemy " << x << endl;
			i++;
			return binarySearch(arr, l, mid - 1, x);
		}

		// Else the element can only be present
		// in right subarray

		else
		{
			cout << "The target location prediction of " << mid + 1 <<
				" is less than target enemy " << x << endl;
			i++;
			return binarySearch(arr, mid + 1, r, x);
		}
	}

	// We reach here when element is not 
	// present in array

	return -1;
}
// The main function which creates an array from 1 to 64
// Here we calculate and set the left and right index for
// BinarySearch

int main(void)
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8,
	9, 10, 11, 12, 13, 14, 15, 16,
	17, 18, 19, 20, 21, 22, 23, 24,
	25, 26, 27, 28, 29, 30, 31, 32,
	33, 34, 35, 36, 37, 38, 39, 40,
	41, 42, 43, 44, 45, 46, 47, 48,
	49, 50, 51, 52, 53, 54, 55, 56,
	57, 58, 59, 60, 61, 62, 63, 64};
	int n = sizeof(arr) / sizeof(arr[0]);
	srand(time(NULL));  // Set a seed using a time set at the start of the program
	int x = (rand() % 64) + 1; // Get a pseudo-random number in [1,64]

	cout << "Generate Random enemy location on 8x8 grid....." << endl;
	cout << "The enemy is located on square " << x << endl;
	cout << "Initiating search algorithm" << endl;

	int result = binarySearch(arr, 0, n - 1, x); // Call BinarySearch with the given arguments
	// A Ternary condition that either prints if the enemy is in the array or not
	(result == -1) ? printf("Enemy was not found on the grid") 
		: printf("The search algorithm took %d predictions to find the enemy\n\n", i); 

	return 0; // end
}

