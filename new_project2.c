#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"new_project2.h"
#include"structs.h"

void new_project2(int *tempid, struct user* uptr, int *m, int *id, char p2[], int* n_p, struct project* pptr) {
	/*
	shomarande poroje fard ra ke (n) hast yeki afzayesh dade va name poroje vared shode ra ba tamame poroje haye mojod check mikonad
	va darsorate nabode moshabeh an ra zakhire mikonad baraye karbar
	*/
	(uptr[*id].n_project) = (uptr[*id].n_project) + 1;
	for (int l = 0;l < (*tempid) + 1;l++) {
		for (int b = 1;b < uptr[l].n_project + 1;b++) {
			if (strcmp(p2, uptr[l].projects[b-1]->projectname) == 0) {
				printf("project alredy exists\n");
				*m = 1;
				(uptr[*id].n_project) = (uptr[*id].n_project) - 1;
			}
			else if (b == (uptr[l].n_project) && l == *tempid && *m != 1) {
				strcpy((uptr[*id].projects[(uptr[*id].n_project)-1]->projectname), p2);
				strcpy((pptr[((*id) * 10) + (uptr[*id].n_project)-1].projectname), p2);
				pptr[((*id) * 10) + (uptr[*id].n_project)-1].users[pptr[((*id) * 10) + (uptr[*id].n_project)-1].n_user] = *id;
				pptr[((*id) * 10) + (uptr[*id].n_project)-1].n_user = pptr[((*id) * 10) + (uptr[*id].n_project)-1].n_user + 1;
				printf("%s is added to project %s\n", uptr[*id].username, p2);
				*(n_p) = *(n_p)+1;
			}
		}
	}
}