#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"add_file2.h"
#include"structs.h"

/*pas az baresiye mojod bodane poroje va mojod nabodane file morede nazar 
be searche poroje morede nazar par dakhte va file ra be file haye an ezafe mikonad va file morede nazar ra dar mahale poroje misazad*/
void add_file2(struct file* fptr, char p2[], char p3[], int* fileexist, int* i2, int* userm, struct project* pptr, int* nosuchproject, int* n_f, int* id) {
	for (int i = 0; i < 20; i++)
		if (strcmp(fptr[i].filename, p2) == 0) {
			*fileexist = 1;
			printf("file alredy exists\n");
			break;
		}
	if (*fileexist == 0) {
		for (*i2; *i2 < (*userm) * 10; (*i2)++)
			if (strcmp(pptr[(*i2)].projectname, p3) == 0 && pptr[(*i2)].add_project == 0) {
				*nosuchproject = 1;
				break;
			}
		if ((*nosuchproject) == 1) {
			FILE *myfile = fopen(p2, "w");
			strcpy(fptr[(*n_f)].filename, p2);
			(pptr[(*i2)].sources[pptr[(*i2)].n_file]) = (*n_f);
			fptr[(*n_f)].ownerproj = (*i2);
			fptr[(*n_f)].owner = (*id);
			(pptr[(*i2)].n_file) = pptr[(*i2)].n_file + 1;
			(*n_f)++;
			fclose(myfile);
			printf("%s is added to project %s\n", fptr[(*n_f) - 1].filename, pptr[(*i2)].projectname);
		}
		else {
			printf("project doesnt exist\n");
		}
	}
}