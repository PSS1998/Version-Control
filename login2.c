#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"login2.h"
#include"structs.h"

void login2(int *tempid, struct user* uptr, int *r, int *id, char p2[], char p3[], int *in, int *j) {
	/*
	user va pass ra ba user va pass haye mojod check karde va darsorate sahih bodan be karbar ejaze vorod dade va (in) ra 1 karde
	va moshakhas mikonad kodam karbar ba che id vorod karde
	*/
	for (*j = 0;*j < (*tempid) + 2;(*j)++) {
		if (strcmp(p2, uptr[*j].username) == 0 && strcmp(p3, uptr[*j].password) == 0) {
			*in = 1;
			*id = *j;
			printf("you loggedin sucsesfully %s\n", uptr[*j].username);
			*r = 1;
			break;
		}
		else if (*j == (*tempid) + 1 && *r != 1) {
			printf("user doesnt exist\n");
		}
	}
}