#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

#include"commit2.h"
#include"structs.h"

/*ebteda dar reshte for va if avale tabe vojode file va poroje morede nazar baraye user baresi mishe
bad be akharex link list rafte va bad etelate morede nazar ra dar an vared mikonim va ye file ba name morede nazar sakhte mishavad*/
void commit2(struct file* fptr, struct project* pptr, struct version* vptr, char p2[], char p3[], int* findfile, int* i3, int* userm, int* nosuchproject, int* id, char version_name[], char* ch) {
	struct tm* timeinfo;
	for (*i3 = 0; *i3 < (*userm) * 10; (*i3)++) {
		if (strcmp(pptr[(*i3)].projectname, p2) == 0 && pptr[(*i3)].add_project == 0) {
			for (int i = 0; i < pptr[(*i3)].n_file; i++) {
				if (strcmp(fptr[pptr[(*i3)].sources[i]].filename, p3) == 0) {
					for (int j = 0; j < 20; j++) {
						if (pptr[(*i3)].users[j] == (*id)) {
							*nosuchproject = 1;
							break;
						}
					}
				}
				if (*nosuchproject == 1)
					break;
			}
		}
		if (*nosuchproject == 1)
			break;
	}

	if (*nosuchproject == 1) {
		for (*i3 = 0; *i3 < 20; (*i3)++) {
			if (strcmp(fptr[(*i3)].filename, p3) == 0) {
				*findfile = 1;
				break;
			}
		}

		struct version* current = &vptr[(*i3)];
		while (current->next != NULL) {
			current = current->next;
		}

		current->next = (struct version*)malloc(sizeof(struct version));
		current->next->date_time = (char*)malloc(40 * sizeof(char));
		current->next->next = NULL;
		current->next->committer = *id;
		current->next->previous = current;
		current->next->number = vptr[(*i3)].n_version;
		vptr[(*i3)].n_version = vptr[(*i3)].n_version + 1;
		time_t rawtime = time(NULL);
		strcpy(current->next->date_time, ctime(&rawtime));
		sprintf(version_name, "%d#%s", vptr[(*i3)].n_version - 1, fptr[(*i3)].filename);
		FILE* file_version = fopen(version_name, "w");
		FILE* original_file = fopen(fptr[(*i3)].filename, "r");
		do {
			(*ch) = fgetc(original_file);
			if ((*ch) != EOF)
				fputc((*ch), file_version);
		} while ((*ch) != EOF);
		fclose(file_version);
		fclose(original_file);
		printf("you have committed sucsesfully\n");
	}
	else {
		printf("you dont have access to such project or file\n");
	}
}