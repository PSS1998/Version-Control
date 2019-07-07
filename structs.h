struct user {
	char *username;
	char *password;

	struct project* projects[20];/*adrese strucct porojeha*/

	int n_project;/*tedade porojehaye in user*/
};
struct project {
	char *projectname;

	int users[20];/*shomare user haye in pororje*/

	int sources[20];/*shomare file haye in pororje*/

	int n_user;/*tedade user haye in pororje*/
	int n_file;/*tedade file haye in pororje*/

	int add_project;/*taine admine pororje*/
};
struct file {
	char *filename;
	int ownerproj;/*poroje sahebe file*/
	int owner;/*usere sahebe file*/

	int version;
};
struct version {
	int number;

	int committer;

	char* date_time;

	struct version* next;
	struct version* previous;

	int n_version;
};