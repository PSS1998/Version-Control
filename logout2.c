#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#include"logout2.h"
#include"structs.h"

void logout2(int *tempid, struct user* uptr, int *id, int *in) {
	/*
	(in) ra mosaviye 0 gharar dade va ejaze login va signup mojadad midahad
	*/
	(*in) = 0;
	printf("you loggedout sucsesfully %s\n", uptr[*id].username);
	(*id) = (*tempid);
}
