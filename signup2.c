#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"signup2.h"
#include"structs.h"

void signup2(int *tempid, struct user* uptr, int *ex, int *id, char p2[], char p3[], int *in) {
	/*
	usename zadde shodera ba username haye mojod check mikonad va darsorate tekrari nabodan shomarandeye user hara yeki afzayesh dade
	va (in) ra barabre 1 gharar dade ke yani karbar dakhel ast va user va pass ra zakhire mikonad
	*/
	for (int k = 0;k < (*tempid) + 2;k++) {
		if (strcmp(p2, uptr[k].username) == 0) {
			printf("user alredy exists\n");
			*ex = 1;
			break;
		}
		else if (k == (*tempid) + 1 && *ex == 0) {
			(*tempid)++;
			strcpy(uptr[(*tempid)].username, p2);
			strcpy(uptr[(*tempid)].password, p3);
			*in = 1;
			printf("you signedup sucsesfully %s is added to users\n", p2);
			*id = *tempid;
			break;
		}
	}

}