#include"signup2.h"
#include"login2.h"
#include"new_project2.h"
#include"add_user2.h"
#include"projects_status2.h"
#include"logout2.h"
#include"add_file2.h"
#include"files_status2.h"
#include"commit2.h"
#include"revert2.h"
#include"get_versions2.h"
#include"delete_version2.h"

#include"structs.h"

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>


int main() {

	struct user* u;
	struct project* p;
	struct file* f;
	struct version* v;

	u = (struct user*)malloc(20 * sizeof(struct user));
	p = (struct project*)malloc(10 * 10 * sizeof(struct project));
	f = (struct file*)malloc(20 * sizeof(struct file));
	v = (struct version*)malloc(20 * sizeof(struct version));

	for (int i = 0;i < 10;i++) {
		u[i].username = (char*)malloc(20 * sizeof(char));
	}
	for (int i = 0;i < 10;i++) {
		u[i].password = (char*)malloc(20 * sizeof(char));
	}
	for (int i = 0;i < 10 * 10;i++) {
		p[i].projectname = (char*)malloc(20 * sizeof(char));
	}
	for (int i = 0;i < 20;i++) {
		f[i].filename = (char*)malloc(20 * sizeof(char));
	}
	for (int i = 0;i < 20;i++) {
		v[i].date_time = (char*)malloc(40 * sizeof(char));
	}

	struct user* uptr = u;
	struct project* pptr = p;
	struct file* fptr = f;
	struct version* vptr = v;
	//=======================intial=======================
	/*4 moteghayeri ke temp dar anha zakhire mishavad*/
	char* part5;
	char* part4;
	char* part3;
	char* part2;
	char* comm;
	/*daryafte vorodi*/
	char temp[100];
	char *temp2;
	char *temp3;
	char *temp4;
	/*zakhire tike haye mokhtalefe file version dar save*/
	char* temporary1;
	char* temporary2;
	char* temporary3;
	char* temporary4;
	char* temporary5;
	/*moteghayerhaye kontoroli baraye taine vaziate system*/
	int m = 0;/*bara taine tekrari bodane esme poroje*/
	int ab = 0;/*bara taine realloc monaseb*/
	int g = 0;/*baraye controle type nakardane bakshe chaharome code*/
	int ex = 0;/*tekrari nabodane user vaghte signup*/
	int z = 0;/* baraye taine zakhire kardane poroje dar kodam user dar adduser*/
	int j = 0;/*bara taine inke kodom user login ast*/
	int w = 0;/*bara vojod nadashtane user dar adduser*/
	int e = 0;/*baraye vojod nadashtane poroje dar adduser*/
	int r = 0;/*baraye taine vojode user va pass*/
	int in = 0;/*taine login bodan*/
	int b = 40;/*tedadehorofe username*/
	int h = 20;/*tedade charectere morede niaz*/
	int h1 = 20;/*tedade charectere morede niaz*/
	int kl = 0;/*bara taine taghire adress bade realloc*/
	int lk = 0;/*bara taine niaz be realloc kardan*/
	int l = 0;/*sharte baresi teda horof usename*/
	int k = 0;/*sharte baresi teda horof password*/
	int d = 20;/*tedade user*/
	int s = 20;/*tedade password*/
	int qw = 0;
	int i3 = 0;
	time_t rawtime;
	struct tm* timeinfo;
	char version_name[30];
	/*3 moteghayer baraye anjame amaliatha*/
	char *command;/*zakhire dastore asli*/
	char *p2;/*zakhire bakhsh dovome dastor*/
	char *p3;/*zakhire bakhsh sevome dastor*/
	char *p4;/*zakhire bakhsh chaharome dastor*/

	int asd = 0;/*baraye taine tedad halghe morede niaz dar files_status*/
	int projectnumber = 0;/*baraye taine por bodane poroje morede nazar*/
	int userm = 10;/*tedade user ha baraye alloc kardan*/
	int projm = 100;/*tedade poroje ha baraye alloc kardan*/
	int filem = 20;/*tedade file ha baraye alloc kardan*/
	int fileexist = 0;/*baraye taine tekrari bodane file*/
	int nosuchproject = 0;/*baraye taine vojode poroje*/
	int findfile = 0;
	int findversion = 0;
	int i2 = 0;/*baraye peyda kardane poroje morede nazar dar add_file*/
	int n_f = 0;/*tedade fileha*/
	int n_p = 0;/*tedade porojeha*/

				/*shomarandeha*/
	int id = -1;/*shomare fardi ke dar system hats*/
	int tempid = -1;/*tedade afradi ke dar system sabtenamand*/
					//	int *n;/*tedade porojehaye har fard*/

					/*liste dastorat*/
	char signup[7] = "signup";
	char exit[5] = "exit";
	char logout[7] = "logout";
	char login[6] = "login";
	char add_user[9] = "add_user";
	char projects_status[16] = "projects_status";
	char new_project[12] = "new_project";
	char add_file[9] = "add_file";
	char files_status[13] = "files_status";
	char commit[7] = "commit";
	char revert[7] = "revert";
	char get_versions[13] = "get_versions";
	char delete_version[15] = "delete_version";
	//baraye daryafte vorodi charecter be charecter az ch estefade shode
	char ch;
	//lines baraye tedade khat haye save estefade shode
	int lines[20];
	for (int i = 0;i < 20;i++)
		lines[i] = 0;
	//baraye tedade setareha
	int stars = 0;

	char ch2;

	int lines2[20];
	for (int i = 0;i < 20;i++)
		lines2[i] = 0;
	int stars2 = 0;
	int lines3[20][20];
	for (int i = 0;i < 20;i++)
		for (int j = 0;j < 20;j++)
			lines3[i][j] = 0;

	int x_p = 0;/*shomare poroje morede nazar dar search*/

				//=======================intial=======================
	command = (char*)malloc(20 * sizeof(char));
	p2 = (char*)malloc(40 * sizeof(char));
	p3 = (char*)malloc(40 * sizeof(char));
	p4 = (char*)malloc(40 * sizeof(char));

	/*	comm = (char*)malloc(20 * sizeof(char));
	part2 = (char*)malloc(40 * sizeof(char));
	part3 = (char*)malloc(40 * sizeof(char));
	part4 = (char*)malloc(40 * sizeof(char));

	temp2 = (char*)malloc(20 * sizeof(char));
	temp3 = (char*)malloc(20 * sizeof(char));*/

	temporary1 = (char*)malloc(10 * sizeof(char));
	temporary2 = (char*)malloc(10 * sizeof(char));
	temporary3 = (char*)malloc(10 * sizeof(char));
	temporary4 = (char*)malloc(10 * sizeof(char));
	temporary5 = (char*)malloc(10 * sizeof(char));

	for (int i = 0;i < 20;i++)
		u[i].n_project = 0;

	for (int i = 0;i < 10 * 10;i++)
		p[i].n_file = 0;

	for (int i = 0;i < 10 * 10;i++)
		p[i].n_user = 0;

	for (int i = 0;i < 20;i++) {
		v[i].number = 0;
		v[i].previous = NULL;
		v[i].next = NULL;
		v[i].n_version = 1;
	}


	//bara vasl kardane porojeha be user ha
	for (int i = 0;i < 10;i++) {
		for (int j = 0;j < 10;j++)
			(u[i].projects[j]) = (&p[(i * 10) + j]);
	}

	for (int i = 0;i < userm * 10;i++)
		p[i].add_project = 0;

	//--------------------------------------------------------------------
	//shoroe khondane fileha
	FILE *users_info_read = fopen("users_info.txt", "r");
	if (users_info_read != NULL) {
		/*shemordane setareha baraye fahmidane tedade user ha*/
		while (!feof(users_info_read))
		{
			ch = fgetc(users_info_read);
			if (ch == '*')
			{
				stars++;
			}
		}
		stars = stars / 3;
		tempid = stars - 1;
		/*shemordane setareha baraye fahmidane tedade user ha*/
		fseek(users_info_read, 0, SEEK_SET);
		int ij = 0;
		/*shemordane tedade khat ha baraye fahmidane tedade poroje ha*/
		while (1) {
			do
			{
				ch = fgetc(users_info_read);
				if (ch == '\n')
				{
					lines[ij]++;
				}
				if (ch == EOF)
					break;
			} while (ch != '*');
			fseek(users_info_read, 4, SEEK_CUR);
			ij++;
			if (ch == EOF)
				break;
		}
		for (int i = 0;i < ij - 1;i++)
			u[i].n_project = lines[i] - 2;
		/*shemordane tedade khat ha baraye fahmidane tedade poroje ha*/
		fseek(users_info_read, 0, SEEK_SET);/*bordane pointer file be ebteda*/
		int n = 0;
		for (int i = 0;i < tempid + 1;i++) {
			fscanf(users_info_read, "%s\n", u[i].username);
			/*			fgets(u[i].username, 20, users_info_read);
			u[i].username = strtok(u[i].username, "\n");*/
			fscanf(users_info_read, "%s\n", u[i].password);
			/*			fgets(u[i].password, 20, users_info_read);
			u[i].password = strtok(u[i].password, "\n");*/
			for (int j = 0;j < u[i].n_project;j++) {
				fscanf(users_info_read, "%s\n", u[i].projects[j]->projectname);
				/*				fgets(u[i].projects[j]->projectname, 20, users_info_read);
				u[i].projects[j]->projectname = strtok(u[i].projects[j]->projectname, "\n");*/
				for (n = 0;n < userm * 10;n++) {
					if (strcmp(u[i].projects[j]->projectname, p[n].projectname) == 0) {
						(p[n].n_user) = (p[n].n_user) + 1;
						p[n].users[p[n].n_user] = i;
						qw = 1;
						n_p++;
						break;
					}
				}
			}
			fseek(users_info_read, 5, SEEK_CUR);
		}
		fclose(users_info_read);
	}

	//--------------------------------------------------------------------	

	FILE *files_info_read = fopen("files_info.txt", "r");
	if (files_info_read != NULL) {
		while (!feof(files_info_read))
		{
			ch2 = fgetc(files_info_read);
			if (ch2 == '*')
			{
				stars2++;
			}
		}
		stars2 = stars2 / 3;
		asd = stars2;

		fseek(files_info_read, 0, SEEK_SET);

		for (int i = 0;i < asd;i++) {

			fgets(temp2, 20, files_info_read);
			temp2 = strtok(temp2, "\n");
			fgets(temp3, 20, files_info_read);
			temp3 = strtok(temp2, "\n");
			for (int i = 0;i < 10;i++) {
				if (strcmp(u[i].username, temp2) == 0)
					break;
				for (int j = 0;j < 10;j++) {
					if (strcmp(u[i].projects[j]->projectname, temp2) == 0)
						break;
					u[i].projects[j]->add_project = 1;
				}
			}
			fseek(files_info_read, 5, SEEK_CUR);
		}
		fclose(files_info_read);
	}

	//--------------------------------------------------------------------

	FILE *projects_info_read = fopen("projects_info.txt", "r");
	if (projects_info_read != NULL) {
		/*shemordane setareha baraye fahmidane tedade porojeha ha*/
		while (!feof(projects_info_read))
		{
			ch2 = fgetc(projects_info_read);
			if (ch2 == '*')
			{
				stars2++;
			}
			if (ch2 == EOF)
				break;/*ajjjjjjjjjjjjjjjjjjjjjjjjjjjib*/
		}
		stars2 = stars2 / 3;
		n_p = stars2;
		/*shemordane setareha baraye fahmidane tedade porojeha ha*/
		fseek(projects_info_read, 0, SEEK_SET);
		//ghaaaaaaaaaaaaaaaalaaaaaaaaaaaaaaaaaaaaat
		while(1) {
			ch = fgetc(projects_info_read);
			if (ch == '\n')
				break;
		}
		int ij3 = 0;
		int ij4 = 0;
		/*shemordane setareha baraye fahmidane tedade fileha ha*/
		while (1) {
			do {
				do
				{
					ch2 = fgetc(projects_info_read);
					if (ch2 == '*') {
						break;
					}
					if (ch2 == '\n')
					{
						lines3[ij3][ij4]++;
					}
					if (ch2 == EOF)
						break;
				} while (ch2 != '#');
				if (ch2 == '*')
					break;
				fseek(projects_info_read, 4, SEEK_CUR);
				ij4++;
				if (ch2 == EOF)
					break;
			} while (ch2 != '*');
			fseek(projects_info_read, 4, SEEK_CUR);
			ij4 = 0;
			ij3++;
			while (ch!=EOF) {
				ch = fgetc(projects_info_read);
				if (ch == '\n')
					break;
			}
			if (ch2 == EOF)
				break;
		}
		/*shemordane setareha baraye fahmidane tedade fileha ha*/
		fseek(projects_info_read, 0, SEEK_SET);

		int ij2 = 0;
		/*shemordane setareha baraye fahmidane tedade fileha ha*/
		while (1) {
			do
			{
				ch2 = fgetc(projects_info_read);
				if (ch2 == '#')
				{
					lines2[ij2]++;
				}
				if (ch2 == EOF)
					break;
			} while (ch2 != '*');
			fseek(projects_info_read, 4, SEEK_CUR);
			ij2++;
			if (ch2 == EOF)
				break;
		}
		/*shemordane setareha baraye fahmidane tedade fileha ha*/
		fseek(projects_info_read, 0, SEEK_SET);

		for (int i = 0;i < n_p;i++) {
			fscanf(projects_info_read, "%s\n", temp);
//			fgets(temp, 20, projects_info_read);
//			temp3 = strtok(temp, "\n");
			for (x_p = 0;x_p < 10 * 10;x_p++) {
				if (strcmp(p[x_p].projectname, temp) == 0 && p[x_p].add_project == 0)
					break;
			}
			p[x_p].n_file = lines2[i] / 3;
			for (int j = 0;j < p[x_p].n_file;j++) {
				fscanf(projects_info_read, "%s %s\n", f[n_f].filename, temp);
//				fgets(temp, 20, projects_info_read);
//				f[n_f].filename = strtok(temp3, " ");
//				temp4 = strtok(temp, " ");

//				temp2 = strtok(NULL, " ");
//				temp4 = strtok(temp4, "\n");
//				strcpy(f[n_f].filename, temp4);
//				temp2 = strtok(temp2, "\n");
				for (int n = 0;n < 10;n++) {
					if (strcmp(u[n].username, temp) == 0) {
						f[n_f].owner = n;
						break;
					}
				}
				f[n_f].ownerproj = x_p;
				p[x_p].sources[j] = n_f;
				v[n_f].n_version = lines3[i][j] - 1;


				struct version* current = &v[n_f];
				for (int z = 0;z < v[n_f].n_version;z++) {

					current->next = (struct version*)malloc(sizeof(struct version));
					current->next->date_time = (char*)malloc(40 * sizeof(char));
					current->next->next = NULL;
					fscanf(projects_info_read, "%d %s %s %s %s %s %s\n", &(current->next->number), temp, temporary1, temporary2, temporary3, temporary4, temporary5);
					for (int i = 0;i < 10;i++) {
						if (strcmp(u[i].username, temp) == 0) {
							current->next->committer = i;
							break;
						}
					}
					sprintf(current->next->date_time, "%s %s %s %s %s\n", temporary1, temporary2, temporary3, temporary4, temporary5);
					current->next->previous = &current;

					current = current->next;
				}
				n_f++;
				fseek(projects_info_read, 5, SEEK_CUR);//shaaaaaaaaaaaaaaaaaaaaak
			}
			fseek(projects_info_read, 5, SEEK_CUR);
		}
		fclose(projects_info_read);
	}

	//--------------------------------------------------------------------




	//=======================main program=======================
	do {
		j = 0;

		/*baresiye allocating e dorost*/
		if (u == NULL || p == NULL || f == NULL || command == NULL || p2 == NULL || p3 == NULL) {
			printf("Oops! Memory allocation failed.\n");
			break;
		}
		//=======================input=======================
		/*
		temp daryaft shode va ba space ghesmat shode va dar command va p2 va p3 gharar migirad
		*/
		printf("please enter command\n");
		gets(temp);
		comm = strtok(temp, " ");
		part2 = strtok(NULL, " ");
		part3 = strtok(NULL, " ");
		part4 = strtok(NULL, " ");
		part5 = strtok(NULL, " ");
		if (part5 != NULL) {
			printf("wrong command\n");
			g = 1;
		}

		if (comm != NULL)strcpy(command, comm);
		if (part2 != NULL)strcpy(p2, part2);
		if (part3 != NULL)strcpy(p3, part3);
		if (part4 != NULL)strcpy(p4, part4);

		if (strlen(p2) > h1 + 1) {
			h1 = strlen(p2) + 1;
			l = 1;
		}
		if (strlen(p3) > h + 1) {
			h = strlen(p3) + 1;
			k = 1;
		}
		if (h > h1)
			h1 = h;
		else
			h = h1;

		//=======================signup=======================	

		if (strcmp(command, signup) == 0 && in == 0 && g == 0 && part3 != NULL && part4 == NULL)
		{
			signup2(&tempid, uptr, &ex, &id, p2, p3, &in);
		}
		//=======================signup=======================
		//=======================login========================
		else if (strcmp(command, login) == 0 && in == 0 && g == 0 && part4 == NULL) {

			login2(&tempid, uptr, &r, &id, p2, p3, &in, &j);
		}

		//=======================login========================
		else if (in == 0 && strcmp(command, exit) != 0 && g == 0) {
			printf("you didnt get in\n");
		}
		//=======================new_project========================

		else if (strcmp(command, new_project) == 0 && in == 1 && g == 0 && part3 == NULL && part2 != NULL) {
			new_project2(&tempid, uptr, &m, &id, p2, &n_p, pptr);
		}
		//=======================new_project========================
		//=======================add_user========================

		else if (strcmp(command, add_user) == 0 && in == 1 && g == 0 && part3 != NULL && part4 == NULL) {
			add_user2(&tempid, uptr, &z, &id, p2, p3, &w, &e, pptr, &userm);
		}
		//=======================add_user========================
		//=======================projects_status========================
		else if (strcmp(command, projects_status) == 0 && in == 1 && g == 0 && part2 == NULL) {
			projects_status2(uptr, &id);
		}
		//=======================projects_status========================
		//=======================add_file========================
		else if (strcmp(command, add_file) == 0 && in == 1 && g == 0 && part3 != NULL && part4 == NULL) {
			add_file2(fptr, p2, p3, &fileexist, &i2, &userm, pptr, &nosuchproject, &n_f, &id);
		}
		//=======================add_file========================
		//=======================files_status========================
		else if (strcmp(command, files_status) == 0 && in == 1 && g == 0 && part3 == NULL && part2 != NULL) {
			files_status2(fptr, p2, &i2, &userm, pptr, &nosuchproject);
		}
		//=======================files_status========================
		//=======================commit========================
		else if (strcmp(command, commit) == 0 && in == 1 && g == 0 && part4 == NULL && part3 != NULL) {
			commit2(fptr, pptr, vptr, p2, p3, &findfile, &i3, &userm, &nosuchproject, &id, version_name, &ch);
		}
		//=======================commit========================
		//=======================revert========================
		else if (strcmp(command, revert) == 0 && in == 1 && g == 0 && part4 != NULL) {
			revert2(fptr, pptr, vptr, p2, p3, p4, &findfile, &i3, &userm, &nosuchproject, &id, &rawtime, version_name, &ch, &findversion);
		}
		//=======================revert========================
		//=======================get_versions========================
		else if (strcmp(command, get_versions) == 0 && in == 1 && g == 0 && part4 == NULL && part3 != NULL) {
			get_versions2(uptr, fptr, pptr, vptr, p2, p3, &findfile, &i3, &nosuchproject, &id);
		}
		//=======================get_versions========================
		//=======================delete_version========================
		else if (strcmp(command, delete_version) == 0 && in == 1 && g == 0 && part4 != NULL) {
			delete_version2(fptr, pptr, vptr, p2, p3, p4, &findfile, &i3, &userm, &nosuchproject, &id, version_name, &findversion);
		}
		//=======================delete_version========================
		//=======================logout========================

		else if (strcmp(command, logout) == 0 && in == 1 && g == 0 && part2 == NULL) {
			logout2(&tempid, uptr, &id, &in);
		}
		//=======================logout========================
		else if (in == 1 && strcmp(command, exit) != 0 && g == 0) {
			printf("wrong command\n");
		}

		/*
		dar inja bakhsh haye morede niaz darsorate niaz realloc shode
		*/

		if (tempid + 2 > userm) {
			userm = userm + 10;
			lk = 1;
		}
		if (n_f + 1 > filem) {
			filem = filem + 20;
			lk = 1;
		}

		if (lk == 1) {
			u = (struct user*)realloc(u, userm * sizeof(struct user));
			p = (struct project*)realloc(p, userm * 10 * sizeof(struct project));
			f = (struct file*)realloc(f, filem * sizeof(struct file));
			kl = 1;
		}


		if (l == 1 || k == 1 || kl == 1) {
			for (int i = 0; i < userm; i++) {
				u[i].username = (char*)realloc(u[i].username, h * sizeof(char));
				if (u[i].username == NULL) {
					ab = 1;
					break;
				}
			}
			for (int i = 0; i < userm; i++) {
				u[i].password = (char*)realloc(u[i].password, h * sizeof(char));
				if (u[i].password == NULL) {
					ab = 1;
					break;
				}
			}
			for (int i = 0; i < userm * 10; i++) {
				p[i].projectname = (char*)realloc(p[i].projectname, h * sizeof(char));
				if (p[i].projectname == NULL) {
					ab = 1;
					break;
				}
			}
			for (int i = 0; i < filem; i++) {
				f[i].filename = (char*)realloc(f[i].filename, h * sizeof(char));
				if (f[i].filename == NULL) {
					ab = 1;
					break;
				}
			}
			if (ab == 1) {
				printf("Oops! Memory allocation failed.\n");
				break;
			}
		}

		if (kl == 1) {
			for (int i = 0; i < userm; i++)
				u[i].n_project = 0;

			for (int i = 0; i < userm * 10; i++)
				p[i].n_file = 0;

			for (int i = 0; i < userm * 10; i++)
				p[i].n_user = 0;

			for (int i = 0; i < userm; i++) {
				for (int j = 0; j < 10; j++)
					(u[i].projects[j]) = (&p[(i * 10) + j]);
			}
		}
		/*
		moteghayer haye kontorolira 0 mikonad
		*/
		e = 0;
		m = 0;
		w = 0;
		r = 0;
		g = 0;
		l = 0;
		i2 = 0;
		qw = 0;
		j = 0;
		fileexist = 0;
		nosuchproject = 0;
		findfile = 0;
		findversion = 0;
		kl = 0;
		lk = 0;
		ab = 0;

	} while (strcmp(command, exit) != 0);

	printf("you exited\n");

	//---------------------------------------------------
	//shoroe zakhire kardane file ha
	FILE *users_info = fopen("users_info.txt", "w");
	for (int i = 0;i < tempid + 1;i++) {
		fprintf(users_info, "%s\n", u[i].username);
		fprintf(users_info, "%s\n", u[i].password);
		for (int j = 0;j < u[i].n_project;j++)
			fprintf(users_info, "%s\n", u[i].projects[j]->projectname);
		fprintf(users_info, "***\n");
	}
	fclose(users_info);

	//---------------------------------------------------

	FILE *projects_info = fopen("projects_info.txt", "w");
	for (int n = 0;n < userm * 10;n++) {
		for (int i = 0; i < 20; i++) {
			if (p[n].projectname[i] == '\0') {
				projectnumber = 1;
				break;
			}
		}
		if (projectnumber == 1 && p[n].add_project == 0) {
			fprintf(projects_info, "%s\n", p[n].projectname);
			for (int j = 0;j < p[n].n_file;j++)
				if (p[n].sources[j] >= 0) {
					fprintf(projects_info, "%s %s\n", f[p[n].sources[j]].filename, u[f[p[n].sources[j]].owner].username);
					struct version* current = &(v[p[n].sources[j]]);
					while (current->next != NULL) {
						fprintf(projects_info, "%d %s %s", current->next->number, u[current->next->committer].username, current->next->date_time);
						current = current->next;
					}
					fprintf(projects_info, "###\n");
				}
			fprintf(projects_info, "***\n");
		}
		projectnumber = 0;
	}
	fclose(projects_info);

	//---------------------------------------------------

	FILE *files_info = fopen("files_info.txt", "w");
	for (int i = 0; i < userm; i++) {
		for (int j = 0;j < 10;j++) {
			if (u[i].projects[j]->add_project == 1) {
				fprintf(files_info, "%s\n", u[i].username);
				fprintf(files_info, "%s\n", u[i].projects[j]->projectname);
				fprintf(projects_info, "***\n");
			}
		}
	}
	fclose(files_info);

	//---------------------------------------------------
	/*free kardane hafeze ha*/

	for (int i = 0; i < userm; i++) {
		free(u[i].username);
	}
	for (int i = 0; i < userm; i++) {
		free(u[i].password);
	}
	for (int i = 0; i < userm * 10; i++) {
		free(p[i].projectname);
	}
	for (int i = 0; i < filem; i++) {
		free(f[i].filename);
	}
	free(command);
	free(p2);
	free(p3);
	free(u);
	free(p);
	free(f);
	free(temporary1);
	free(temporary2);
	free(temporary3);
	free(temporary4);
	free(temporary5);
}