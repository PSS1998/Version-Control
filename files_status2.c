#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"files_status2.h"
#include"structs.h"

/*searche name poroje morede nazar va bad chape tameme file haye dar an*/
void files_status2(struct file* fptr, char p2[], int* i2, int* userm, struct project* pptr, int* nosuchproject) {
	for ((*i2); (*i2) < *userm; (*i2)++)
		if (strcmp(pptr[(*i2)].projectname, p2) == 0 && pptr[(*i2)].add_project == 0) {
			*nosuchproject = 1;
			break;
		}
	if (*nosuchproject == 1) {
		for (int i = 0; i < pptr[(*i2)].n_file; i++)
			printf("%s\n", fptr[pptr[(*i2)].sources[i]].filename);
	}
	else if (*i2 == (*userm) - 1 && *nosuchproject == 0) {
		printf("no such project");
	}
}