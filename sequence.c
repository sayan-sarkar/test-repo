/*
	All unique sequence number from 1 to 23 whose summation can result into 23.

	Assume 1 to 23 bit sequence where each index represent the sequence number. 
  	Max Number of sequence with 23 bit will be 2^23 . Iterate though all possible sequence 
  	and based on set bits get the sum of the sequence if it matches 23. Print the sequence.
 */

#include <stdio.h>
#include <math.h>

#define MAX_SEQUENCE 23 

void print_sequence(int* list, int seq_index)
{
	int iter=0;
	for(iter=0;iter<seq_index;iter++) printf("%d ",list[iter]);
	printf("\n");
}
void compute_sequence(int temp_val)
{
	int sum=0;
	int shift_index=0;
	int seq_index=0;
	int list[MAX_SEQUENCE]={0};
	while(temp_val)
	{
		if(temp_val & 0x01){
			sum+=(shift_index+1);
			if(sum > MAX_SEQUENCE) { /*printf("\nSum Exceeded Max");*/ break; }
			list[seq_index++] = shift_index+1;
		}
		shift_index++;
		temp_val = temp_val >> 1;
	}

	if(temp_val==0 && (sum == MAX_SEQUENCE)) 
		print_sequence(list,seq_index);
}

int main()
{
	int max_sequence = pow(2,MAX_SEQUENCE)-1;
	int count,iter;

	for(count=1;count<=max_sequence; count++)
		compute_sequence(count);
}


