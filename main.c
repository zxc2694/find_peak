#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int peak_cnt_func(int *data, int data_size, int param_uphill_threshold, int param_downhill_cnt_limit)
{
	int i = 0;
	bool trigger = false;
	int search = 0;
	int peak_cnt = 0;

	for(i = 0; i < data_size ; i++)
	{
	    if(param_uphill_threshold < data[i] && trigger == false)
	    {
	    	trigger = true;
	    	search = 0;
	    }
		if(trigger == true)
		{
			if(data[i] > data[i-1])
				search = 0;
			else
			{
				if(search > param_downhill_cnt_limit)
				{
					trigger = false;
					search = 0;
					peak_cnt++;
				}
				else
					search++;
			}
		}
	}
	return peak_cnt;
}
int main(int argc, char *argv[]) {
	FILE *fp, *fpcnt;
	char buffer[20];	
	int i = 0, fileLine = 0;
	fpcnt = fopen("rawdata.txt", "r");
	while(fgets(buffer, 20, (FILE*)fpcnt))
	    fileLine++;
	fclose(fpcnt);

	int data[fileLine];
	fp = fopen("rawdata.txt", "r");
	while(fgets(buffer, 20, (FILE*)fp)) {
	    data[i] = atoi(buffer);
	    i++;
	}
        fclose(fp);
	int peak_cnt = peak_cnt_func(data, fileLine, 150, 10);
	printf("peak_cnt = %d\r\n", peak_cnt);
	
	return 1;
}
