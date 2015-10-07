/** @file FibonacciGen.h
 *	 @brief This class generates Fibonacci numbers. The first 6 numbers are 1, 1, 2, 3, 5, and 8.
 *
 *	 @note The current implementation throws an exception for the first Fibonacci number
 *	       exceeding ULLONG_MAX.
 *
 *  TODO Define a new numeric class to allow the sequence to grow beyond a standard integer type.
 *
 *  @author Martin Ma
 *  @date   Oct 7, 2015
 *
 *  Copyright 2015. All rights reserved.
 */

#ifndef FIBONACCIGEN_H_
#define FIBONACCIGEN_H_

#include <vector>

using namespace std;

class FibonacciGen {
public:
	FibonacciGen();
	virtual ~FibonacciGen();

   /**
		Set the first two numbers in the sequence.

     	@param[in] f0 First number in the sequence. Default = 1.
      @param[in] f1 Second number in the sequence. Default = 1.
    */
	void Init(unsigned long long const f0 = 1, unsigned long long const f1 = 1);

   /**
	   Generate the next n numbers in the sequence. Append the new numbers to the input vector container.

      @param[out] seq Vector container for the sequence.
     	@param[in]  n   Length of sequence. Default = 1;
    */
	void GetNext(vector<unsigned long long>& seq, unsigned long long const n = 1);

   /**
		Print n terms of the sequence. The sequence is generated in batches.

     	@param[in] n 			Number of terms in the sequence to print. Default = 1.
      @param[in] batchSize Maximum number of terms generated in each batch. Default = 32.
    */
	virtual void PrintNextInBatches(unsigned long long const n = 1, unsigned long long const batchSize = 32);

protected:
	vector<unsigned long long> seqHist;		/*!< Buffer for the next 2 values of the sequence. */
};

#endif /* FIBONACCIGEN_H_ */
