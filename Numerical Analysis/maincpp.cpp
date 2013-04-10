#include <iostream>
#include <math.h>
#include <complex>
#define pi 3.1428571428571428571428571428571
using namespace std;

void bisection(double , double, double , int);
double f(double);

int main (int argc , char** argv)
{
	int imax;		 // maximum number of iterations
	double a, b;	 // left and right ends of the original interval
	double epsilon;  // convergence criterion

	//Obtain Input Data
	cout<< "Enter the limits of the original search interval , a and b: ";
	cin>>a>>b;
	cout<<"Enter the convergence criteria: ";
	cin>>epsilon;
	cout<<"Enter the maximum number of iterations allowed: ";
	cin>>imax;

	bisection(a, b, epsilon, imax);

	return 0;
}


/*
	A bisection function that finds roots of a function .
	The interval a < x < b is known to contain a root of 
	f(x). The estimate of the root is improved successively 
	by finding in which half of the interval the root lies 
	and then replacing the original interval by that 
	half-interval.
*/
void bisection(double a, double b, double epsilon, int imax)
{
	int i; 				// current iteration counter
	double x1,x2,x3;	// left, right, and midpoint of the current interval
	double f1,f2,f3;	// function evaluated at these points
	double width;		// width of the original interval = (b - a)
	double curwidth;	// width of the current interval = (x3 - x1)

	// Echo back the passed input data
	cout << " \n The original search interval is from "<< a <<" to "<< b << endl;
	cout << "The Convergence criterion is: interval < " << epsilon << endl;
	cout << "The maximum number of iterations allowed is " << imax << endl;

	// Calculate the root
	x1 = a;
	x3 = b;
	f1 = f(x1);
	f3 = f(x3);
	width = (b-a);
	
	// Verify there is a root in the interval
	if(f1 * f3 > 0.0)
		cout << "\n No root in the original interval exists" << endl;
	else
	{
		// Root is present in the interval given

		for (i = 1; i <= imax; i++)
		{
			// Divide the interval into 2 parts
			x2 = (x1 + x3)/2.0;
			// Find which half of the interval contains the root
			f2 = f(x2);
			if(f1 * f2 <= 0.0) // root is in left half-interval
			{
				curwidth = (x2 -x1)/2.0;
				f3 = f2;
				x3 = x2;
			}
			else // root is in the right half-interval
			{
				curwidth = (x3 - x2)/2.0;
				f1 = f2;
				x1 = x2;
			}

			// Checking if the solution is acurate enough and printing it
			if (curwidth < epsilon)
			{
				cout << "\nA root at x = " << x2 << " was found in "
					<< i << " iterations " << endl;
				cout << "The value of the function is " << f2 << endl;

				return;
			}
		}
	}

	// Prints that the root isnt found for the required accuracy 
	// over the specified number of iterations
	cout <<  "\nAfter " << imax << " iterations, no root was found within the convergence criterion " << endl;

	return;
}

// Function to evaluate the function under test f(x)
double f(double x)
{
	return (exp(-x) - sin(0.5 * pi * x));
}