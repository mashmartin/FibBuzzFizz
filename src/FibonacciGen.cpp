/** @file FibonacciGen.cpp
 *
 *  @author Martin Ma
 *  @date   Oct 7, 2015
 *
 *  Copyright 2015. All rights reserved.
 */

#include "FibonacciGen.h"

#include <iostream>

// Define FibonacciGen_OVFL_CHECK to throw an exception and exit the program when the terms are greater than ULLONG_MAX.
#define FibonacciGen_OVFL_CHECK 1
#ifdef FibonacciGen_OVFL_CHECK
#include <climits>
#include <cstdlib>
#include <stdexcept>
#include <sstream>
#include <exception>
#endif

FibonacciGen::FibonacciGen() {
	Init();
}

FibonacciGen::~FibonacciGen() {
	// Empty destructor.
}

void FibonacciGen::Init(unsigned long long const f0, unsigned long long const f1) {
	seqHist.clear();
	seqHist.push_back(f0);
	seqHist.push_back(f1);
}

void FibonacciGen::GetNext(vector<unsigned long long>& seq, unsigned long long const n) {
	unsigned long long idx = 0;
	vector<unsigned long long> seqBfr;

	// Add the seeds into buffer
	seqBfr.push_back(seqHist[0]);
	seqBfr.push_back(seqHist[1]);
	// Generate n more numbers in the sequence
	while (idx < n) {
#ifdef FibonacciGen_OVFL_CHECK
		try
		{
			if (seqBfr[idx + 1] > ULLONG_MAX - seqBfr[idx]) {
				stringstream strStrm;
				strStrm << seqBfr[idx] << " + " << seqBfr[idx + 1];
				throw overflow_error(strStrm.str());
			}
			seqBfr.push_back(seqBfr[idx] + seqBfr[idx + 1]);
		}
		catch (exception& exc) {
			cerr << "Generator overflows at " << exc.what() << "." << endl;
			exit(EXIT_FAILURE);
		}
#else
		seqBfr.push_back(seqBfr[idx] + seqBfr[idx + 1]);
#endif
		++idx;
	}
	// Copy the first n numbers from buffer to output
	seq.insert(seq.end(), seqBfr.begin(), seqBfr.end()-2);
	// Save the remaining 2 numbers for the next batch
	seqHist.clear();
	seqHist.insert(seqHist.end(), seqBfr.end()-2, seqBfr.end());
}

void FibonacciGen::PrintNextInBatches(unsigned long long const n, unsigned long long const batchSize) {
	unsigned long long nBatch = n / batchSize;
	vector<unsigned long long> seqBfr;

	// Print the first nBatch numbers
	for (unsigned long long batchIdx = 0; batchIdx < nBatch; ++batchIdx) {
		seqBfr.clear(); 					// Clear the sequence buffer before getting the new batch
		GetNext(seqBfr, batchSize);
		for (vector<unsigned long long>::iterator itr = seqBfr.begin(); itr != seqBfr.end(); ++itr) {
			cout << *itr << ' ';
		}
		cout << endl;
	}
	// Print the remaining sequence
	seqBfr.clear();
	GetNext(seqBfr, n % batchSize);
	for (vector<unsigned long long>::iterator itr = seqBfr.begin(); itr != seqBfr.end(); ++itr) {
		cout << *itr << ' ';
	}
	cout << endl;
}
