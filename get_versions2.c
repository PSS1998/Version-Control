#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"get_versions2.h"
#include"structs.h"

/*ebteda dar reshte for va if avale tabe vojode file va poroje morede nazar baraye user baresi mishe
bad dar link liste morede nazar ta jayi ke be null nareside etelate morede nazar ra print mikondad*/
void get_versions2(struct user* uptr, struct file* fptr, struct project* pptr, struct version* vptr, char p2[], char p3[], int* findfile, int* i3, int* nosuchproject, int* id) {
	for ((*i3) = 0; (*i3) < 20; (*i3)++) {
		if (strcmp(pptr[(*i3)].projectname, p2) == 0 && pptr[(*i3)].add_project == 0) {
			for (int i = 0; i < pptr[(*i3)].n_file; i++) {
				if (strcmp(fptr[pptr[(*i3)].sources[i]].filename, p3) == 0) {
					for (int j = 0; j < 20; j++) {
						if (pptr[(*i3)].users[j] == *id) {
							(*nosuchproject) = 1;
							break;
						}
					}
				}
				if ((*nosuchproject) == 1)
					break;
			}
		}
		if ((*nosuchproject) == 1)
			break;
	}

	for ((*i3) = 0; (*i3) < 20; (*i3)++) {
		if (strcmp(fptr[(*i3)].filename, p3) == 0) {
			(*findfile) = 1;
			break;
		}
	}

	if ((*nosuchproject) == 1) {
		struct version* current = &vptr[(*i3)];
		while (current->next != NULL) {
			printf("%d\n", current->next->number);
			printf("%s", current->next->date_time);
			printf("%s\n", uptr[current->next->committer].username);
			current = current->next;
		}
	}
	else {
		printf("no such file comitted\n");
	}
}