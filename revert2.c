#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"revert2.h"
#include"structs.h"

/*ebteda dar reshte for va if avale tabe vojode file va poroje morede nazar baraye user baresi mishe
bad adade morede nazar az char be int tabdil shode va version morede nazar dar link list peyda shode
va bad file ba esme morede nazar sakhte shode va ye copy az file asli dar an rikhte mishe*/
void revert2(struct file* fptr, struct project* pptr, struct version* vptr, char p2[], char p3[], char p4[], int* findfile, int* i3, int* userm, int* nosuchproject, int* id, char version_name[], char* ch, int* findversion) {
	for ((*i3) = 0; (*i3) < 20; (*i3)++) {
		if (strcmp(pptr[(*i3)].projectname, p2) == 0 && pptr[(*i3)].add_project == 0) {
			for (int i = 0; i < pptr[(*i3)].n_file; i++) {
				if (strcmp(fptr[pptr[(*i3)].sources[i]].filename, p3) == 0) {
					for (int j = 0; j < 20; j++) {
						if (pptr[(*i3)].users[j] == *id) {
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

	int v_num = p4[0] - '0';

	for ((*i3) = 0; (*i3) < 20; (*i3)++) {
		if (strcmp(fptr[(*i3)].filename, p3) == 0) {
			*findfile = 1;
			break;
		}
	}

	struct version* current = &vptr[(*i3)];
	while (current != NULL) {
		if (v_num == current->number) {
			*findversion = 1;
			break;
		}
		current = current->next;
	}

	if (*findversion == 1 && *nosuchproject == 1) {
		sprintf(version_name, "%s#%s", p4, fptr[(*i3)].filename);
		FILE* file_version = fopen(version_name, "r");
		FILE* original_file = fopen(fptr[(*i3)].filename, "w");
		do {
			*ch = fgetc(file_version);
			if ((*ch) != EOF)
				fputc(*ch, original_file);
		} while ((*ch) != EOF);
		fclose(file_version);
		fclose(original_file);
		printf("you have revertted sucsesfully\n");
	}
	else {
		printf("you dont have access to such project, file or version\n");
	}
}