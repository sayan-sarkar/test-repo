#include <stdio.h>
#include "rlc_seq_table.h"


int get_next_sn(int seq_id, int set_id, int curr_sn)
{
	const int *seq_ptr = rlc_sequence_owner[seq_id];
	int next_sn = -1;

	if(!(seq_id >=0 && seq_id <= 6) || !(curr_sn >=0 && curr_sn <=1023))
	{
		printf("\nError Invalid entry seq_id(%d) curr_sn(%d)",seq_id,curr_sn);
		return -1;
	}

	if(seq_ptr[(curr_sn+1)%1024] == set_id )  next_sn =  (curr_sn+1)%1024;
	else if(seq_ptr[(curr_sn+2)%1024] == set_id )  next_sn = (curr_sn+2)%1024;
	else if(seq_ptr[(curr_sn+3)%1024] == set_id )  next_sn = (curr_sn+3)%1024;
	else if(seq_ptr[(curr_sn+4)%1024] == set_id )  next_sn = (curr_sn+4)%1024;
	else next_sn = -1;

	printf("\nNextSn(%d) , SeqId,SetId,CurrSn:(%d,%d,%d)",next_sn,seq_id,set_id,curr_sn);
	return next_sn;
}


int main()
{
	get_next_sn(3,3,207);
	get_next_sn(0,3,207);
	get_next_sn(6,2,1023);
	get_next_sn(7,2,1023);
	get_next_sn(2,1,0);
	get_next_sn(2,2,0);

	printf("\n");
}
