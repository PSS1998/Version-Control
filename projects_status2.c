#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"projects_status2.h"
#include"structs.h"

void projects_status2(struct user* uptr, int *id) {
	/*
	liste tamame porojehaye fard ra chap mikonad
	*/
	printf("username : %s\n", uptr[*id].username);
	printf("Projects : \n");
	for (int v = 1;v <= (uptr[*id].n_project);v++) {
		printf("%s\n", uptr[*id].projects[v - 1]->projectname);
	}
}