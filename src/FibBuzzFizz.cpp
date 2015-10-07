/** FibBuzzFizz.cpp
 *  @brief Interpreted Fibonacci sequence test driver.
 *
 *  This program demonstrates the functionality of the interpreted Fibonacci
 *  sequence generator.
 *
 *  @author  Martin Ma
 *  @date    Oct 7, 2015
 *  @version 1.0
 *
 *  Copyright 2015. All rights reserved.
 */

#include "FibonacciInterpt.h"

using namespace std;

int main(int argc, char* argv[]) {

	FibonacciInterpt fibGen;	// Generator for interpreted Fibonacci sequence

	// Initialize the first 2 terms of the Fibonacci sequence.
	fibGen.Init(1, 1);

	// Print the first 20 terms in the sequence. Internally,
	// 8 terms are generated in each batch.
	fibGen.PrintNextInBatches(20, 8);

	// Print the next 40 terms in the sequence. Internally,
	// 16 terms are generated in each batch.
	fibGen.PrintNextInBatches(40, 16);

	// Attempt to print the next 100 terms in the sequence.
	// This triggers an exception in the FibonacciGen class.
	fibGen.PrintNextInBatches(100, 1);

	return 0;
}
