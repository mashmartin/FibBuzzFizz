/** @file FibonacciInterpt.cpp
 *
 *  @author Martin Ma
 *  @date   Oct 7, 2015
 *
 *  Copyright 2015. All rights reserved.
 */

#include "FibonacciInterpt.h"

#include <cmath>
#include <iostream>
#include <sstream>

FibonacciInterpt::FibonacciInterpt() {
	// Empty constructor
}

FibonacciInterpt::~FibonacciInterpt() {
	// Empty destructor
}

bool FibonacciInterpt::IsPrime(unsigned long long n) {
	unsigned long long factor;		// factor to test
	bool isPrime = false;			// final result

	if (n > 1) {
		// Number of probable factors
		unsigned long long nProbFact = static_cast<unsigned long long>(sqrt(static_cast<double>(n)));

		factor = 2;
		while ((factor <= nProbFact) && (n % factor != 0)) {
			++factor;
		}

		isPrime = (factor > nProbFact);	// n is a prime number if no factor is found
	}

	return isPrime;
}

string FibonacciInterpt::Fib2BuzzFizz(unsigned long long fib) {
	stringstream strStrm("");

	if (fib > 0) {
		if (fib % 3 == 0) {				// Divisible by 3?
			strStrm << "Buzz ";
		}
		if (fib % 5 == 0) {				// Divisible by 5?
			strStrm << "Fizz";
		}

		if (strStrm.str().empty()) {
			if (IsPrime(fib)) {			// Prime?
				strStrm << "BuzzFizz";
			} else {
				strStrm << fib;			// Output the number
			}
		}
	} else {
		strStrm << fib;					// Output the number
	}
	return strStrm.str();
}

void FibonacciInterpt::PrintNextInBatches(unsigned long long const n, unsigned long long const batchSize) {
	unsigned long long nBatch = n / batchSize;
	vector<unsigned long long> seqBfr;

	// Print the first nBatch numbers
	for (unsigned long long batchIdx = 0; batchIdx < nBatch; ++batchIdx) {
		seqBfr.clear();					// Clear the sequence buffer before getting the new batch
		GetNext(seqBfr, batchSize);
		for (vector<unsigned long long>::iterator itr = seqBfr.begin(); itr != seqBfr.end(); ++itr) {
			cout << Fib2BuzzFizz(*itr) << endl;
		}
	}
	// Print the remaining sequence
	seqBfr.clear();
	GetNext(seqBfr, n % batchSize);
	for (vector<unsigned long long>::iterator itr = seqBfr.begin(); itr != seqBfr.end(); ++itr) {
		cout << Fib2BuzzFizz(*itr) << endl;
	}
}
