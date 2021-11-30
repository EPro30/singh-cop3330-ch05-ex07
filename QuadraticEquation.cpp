/*
 *  UCF COP3330 Fall 2021 Assignment 5 Solution
 *  Copyright 2021 Riya Singh
 */

//The purpose of this program is to find the value of x in quadratic equation.

#include <iostream> //allows program to perform input and output
#include <string> //allows program to work with strings
#include "std_lib_facilities.h" //header file
#include <cmath> //allows a program to use math functions

//add the root to find a possible solution
double plus(double root, double a, double b)
{
	double result = (-b + sqrt(root))/(2*a);
	return result;
}

//subtract the root to find a possible solution
double minus(double root, double a, double b)
{
	double result = (-b - sqrt(root))/(2*a);
	return result;
}

//calculate the root
double root(double a, double b, double c)
{
	return pow(b,2)-(4*a*c);
}

//check if the root is a real number
int check(double x, double a, double b, double c)
{
	int result = (a*(pow(x,2)))+(b*x)+c;
	if(result == 0)
		return 0;
	else
		return 1;
}

int main()
{
	double a, b, c;
	std::cin >> a >> b >> c; //scan and store the input
	double x1, x2;
	int check1, check2;
	
	double rt = root(a, b, c); //find the root
	
	//decision statements to print the right solution
	if(rt >= 0)
	{
		x1 = ::plus(rt, a, b);
		x2 = ::minus(rt, a, b);
		check1 = check(x1, a, b, c);
		check2 = check(x2, a, b, c);
		if(check1 == 0 && check2 == 0)
		{
			std::cout << x1 << " and " << x2 << " are the solution for the quadratic equation" << std::endl;
		}
		else if(check1 == 0 && check2 != 0)
		{
			std::cout << x1  << " is the solution for the quadratic equation" << std::endl;
		}
		else if(check1 != 0 && check2 == 0)
		{
			std::cout << x2  << " is the solution for the quadratic equation" << std::endl;
		}
		else
		{
			std::cout  << " No solution for the quadratic equation" << std::endl;
		}
	}
	else
	{
		std::cout  << " No real roots" << std::endl;
	}
}