#include <stdio.h>
#define MAX_SN 1024

int SN_OWNER[1024];

void print_seq(int* sn_list,char* pattern)
{
	int cnt=0;
	printf("  {\n   /*________________________________%s___________________________________*/\n",pattern);
	for(cnt=0;cnt<MAX_SN;cnt++)
	{
		printf("     /*(%04d)*/ %d",cnt,sn_list[cnt]);
		if(cnt+1 != MAX_SN) printf(",");
		if((cnt+1) % 4 == 0) printf("\n");
	}

	printf("  } ,\n");
}


void seq__1_1_1_1(int* sn_list)
{
	int cnt=0;
	for(cnt=0;cnt <MAX_SN; cnt++)
		sn_list[cnt]  = cnt%4;
}

void seq__1_1_1_0(int *sn_list)
{
	int load_balancer_node[] = {0,1,2};
	int load_balancer_index=0;
	int cnt=0;

	seq__1_1_1_1(sn_list);
	for(cnt=3;cnt <MAX_SN; cnt+=4)
	{
		sn_list[cnt] = load_balancer_node[load_balancer_index];
		load_balancer_index = (load_balancer_index + 1) % 3;
	}
}

void seq__1_1_0_1(int *sn_list)
{
	int load_balancer_node[] = {0,1,3};
	int load_balancer_index=0;
	int cnt=0;

	seq__1_1_1_1(sn_list);
	for(cnt=2;cnt <MAX_SN; cnt+=4)
	{
		sn_list[cnt] = load_balancer_node[load_balancer_index];
		load_balancer_index = (load_balancer_index + 1) % 3;
	}
}

void seq__1_0_1_1(int *sn_list)
{
	int load_balancer_node[] = {0,2,3};
	int load_balancer_index=0;
	int cnt=0;

	seq__1_1_1_1(sn_list);
	for(cnt=1;cnt <MAX_SN; cnt+=4)
	{
		sn_list[cnt] = load_balancer_node[load_balancer_index];
		load_balancer_index = (load_balancer_index + 1) % 3;
	}
}

void seq__1_1_0_0(int *sn_list)
{
	int load_balancer_node[] = {0,1};
	int load_balancer_index=0;
	int cnt=0;

	seq__1_1_1_1(sn_list);
	for(cnt=2;cnt <MAX_SN; cnt+=4)
	{
		sn_list[cnt] = load_balancer_node[load_balancer_index];
		load_balancer_index = (load_balancer_index + 1) % 2;
	}

	load_balancer_index=1;
	for(cnt=3;cnt <MAX_SN; cnt+=4)
	{
		sn_list[cnt] = load_balancer_node[load_balancer_index];
		load_balancer_index = (load_balancer_index + 1) % 2;
	}
}

void seq__1_0_0_1(int *sn_list)
{
	int load_balancer_node[] = {0,3};
	int load_balancer_index=0;
	int cnt=0;

	seq__1_1_1_1(sn_list);
	for(cnt=1;cnt <MAX_SN; cnt+=4)
	{
		sn_list[cnt] = load_balancer_node[load_balancer_index];
		load_balancer_index = (load_balancer_index + 1) % 2;
	}

	load_balancer_index=1;
	for(cnt=2;cnt <MAX_SN; cnt+=4)
	{
		sn_list[cnt] = load_balancer_node[load_balancer_index];
		load_balancer_index = (load_balancer_index + 1) % 2;
	}
}

void seq__1_0_1_0(int *sn_list)
{
	int load_balancer_node[] = {0,2};
	int load_balancer_index=0;
	int cnt=0;

	seq__1_1_1_1(sn_list);
	for(cnt=1;cnt <MAX_SN; cnt+=4)
	{
		sn_list[cnt] = load_balancer_node[load_balancer_index];
		load_balancer_index = (load_balancer_index + 1) % 2;
	}

	load_balancer_index=1;
	for(cnt=3;cnt <MAX_SN; cnt+=4)
	{
		sn_list[cnt] = load_balancer_node[load_balancer_index];
		load_balancer_index = (load_balancer_index + 1) % 2;
	}
}

int main()
{
	printf("const int rlc_sequence_owner[7][1024] = { \n");

	seq__1_0_0_1(SN_OWNER);
	print_seq(SN_OWNER,"1_0_0_1");

	seq__1_0_1_0(SN_OWNER);
	print_seq(SN_OWNER,"1_0_1_0");

	seq__1_0_1_1(SN_OWNER);
	print_seq(SN_OWNER,"1_0_1_1");

	seq__1_1_0_0(SN_OWNER);
	print_seq(SN_OWNER,"1_1_0_0");

	seq__1_1_0_1(SN_OWNER);
	print_seq(SN_OWNER,"1_1_0_1");

	seq__1_1_1_0(SN_OWNER);
	print_seq(SN_OWNER,"1_1_1_0");

	seq__1_1_1_1(SN_OWNER);
	print_seq(SN_OWNER,"1_1_1_1");

	printf("};");

	printf("\n\n");
}
