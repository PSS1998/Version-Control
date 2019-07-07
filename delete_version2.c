#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"delete_version2.h"
#include"structs.h"

/*ebteda dar reshte for va if avale tabe vojode file va poroje morede nazar baraye user baresi mishe
bad link list ra ta zanjire morede nazar tey karde va az zanjire morede nazar dar temp ye copy negah midarim va zanjire ghabl ra be bad va bad ra be ghabl vasl mikonim va hafezeye node hazf shode ra azad mikonim va file morede nazar ra pak mikonim*/
void delete_version2(struct file* fptr, struct project* pptr, struct version* vptr, char p2[], char p3[], char p4[], int* findfile, int* i3, int* userm, int* nosuchproject, int* id, char version_name[], int* findversion) {
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

	struct version* temp = &vptr[(*i3)];
	struct version* current = &vptr[(*i3)];
	while (current != NULL) {
		if (v_num == current->number) {
			*findversion = 1;
			break;
		}
		current = current->next;
	}

	if (*nosuchproject == 1 && *findversion == 1 && *findfile == 1) {
		current = &vptr[(*i3)];
		while (current != NULL) {
			if (v_num == current->number) {
				temp = current;
				current = current->previous;
				current->next = temp->next;
				current = current->next;
				current->previous = temp->previous;
				free(temp->date_time);
				free(temp);
				break;
			}
			current = current->next;
		}
		sprintf(version_name, "%d#%s", v_num, p3);
		remove(version_name);
		printf("version is deleted\n");
	}
	else {
		printf("no such project, file or version\n");
	}
}