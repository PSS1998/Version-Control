#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"add_user2.h"
#include"structs.h"

void add_user2(int *tempid, struct user* uptr, int *z, int *id, char p2[], char p3[], int *w, int *e, struct project* pptr, int* userm) {
	/*
	ebteda vojode karbar va sepas vojod poroje morede nazar baraye karbar hazer ra check mikonad va darsorate vojod baraye an karbar poroje ra zakhire karde va shomarandeye shakhs ra
	ke ba n namayesh dade shode yeki afzayesh midahad
	*/
	int v = 1;
	for (*z = 0;*z < (*tempid) + 2;(*z)++) {
		if (strcmp(p2, uptr[*z].username) == 0) {
			*w = 1;
			break;
		}
	}
	if ((*w) != 1) {
		printf("no such user\n");
	}
	for (v = 1;v < ((*userm) * 10) + 1;v++) {
		if (strcmp(p3, pptr[v - 1].projectname) == 0 && pptr[v - 1].add_project == 0) {
			*e = 1;
			break;
		}
	}
	if ((*e) != 1) {
		printf("no such project\n");
	}
	if ((*w) == 1 && (*e) == 1) {
		(uptr[*z].n_project)++;
		strcpy((uptr[*z].projects[(uptr[*z].n_project) - 1]->projectname), p3);
		uptr[*z].projects[(uptr[*z].n_project) - 1]->add_project = 1;
		pptr[v - 1].users[pptr[v - 1].n_user] = *z;
		pptr[v - 1].n_user = pptr[v - 1].n_user + 1;
		printf("%s is added to project %s\n", uptr[*z].username, p3);
	}
}

				