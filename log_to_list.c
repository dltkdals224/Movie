#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct movie_list {
	int serial_num;
	char *str;
	struct movie_list *next;
};
int main(){
	struct movie_list *head = NULL;
	struct linked_list *tmp = NULL;
	struct linked_list *ttmp = NULL;
	struct movie_list *temp = NULL;
	int i = 0, c,log_num=0,j=0,k=0,h=0,serial_num;
	char *array,*update,*p,*title,*genre,*director,*year,*time,*actor;

	FILE *movie_log;
	FILE *movie_list;
	movie_list = fopen("movie_list", "w+");
	movie_log = fopen("movie_log", "r");

	while((c=getc(movie_log))!=EOF)
		if (c == '\n')
			log_num++;
	
	head = (struct movie_list*)calloc(log_num, sizeof(struct movie_list));

	rewind(movie_log);

	while((c=getc(movie_log))!=EOF){

		if (c == 'a') {
			j=0;

			(head+i)->str = (char *)calloc(1000, sizeof(char));

			while (1) {
				c = getc(movie_log);
				if (c == ':'){
					break;}
			}
			array=(char *)calloc(100,sizeof(char));
			while (1) {
				c = getc(movie_log);

				if (c == ':'){
					break;}
				*(array + j) = c;
				j++;
			}
			(head+i)->serial_num = atoi(array);
			free(array);
			j = 0;

			while (1) {
				c = getc(movie_log);
				if (c == '\n') {
					break;
				}
				else if(feof(movie_log))
					break;
				*(((head+i)->str) + k) = c;
				k++;
			}
			k=0;
			i++;
			
		}
		else if(c=='u'){
			j=0;
			update=(char *)calloc(100,sizeof(char));

			while(1){
				c=getc(movie_log);
				if(c==':')
					break;
			}
			array=(char *)calloc(100,sizeof(char));
			while(1){
				c=getc(movie_log);
				if(c==':'){
					break;}
				*(array+j)=c;
				j++;
			}
			j=0;
			serial_num=atoi(array);
			free(array);

			for (int a = 0;a < i;a++) {
	if (serial_num == (head + a)->serial_num) {
		p = strtok((head + a)->str, ":");
		title = p;
		p = strtok(NULL, ":");
		genre = p;
		p = strtok(NULL, ":");
		director = p;
		p = strtok(NULL, ":");
		year = p;
		p = strtok(NULL, ":");
		time = p;
		p = strtok(NULL, "\n");
		actor = p;

		c = getc(movie_log);
		if (c != '=') {
			*(update + j) = c;
			j++;
			while (1) {
				c = getc(movie_log);
				if (c == ':') {
					*(update+j)=c;
					j++;
					break;
				}
				*(update + j) = c;
				j++;
			}
		}
		else {
			strcat(update, title);
			j=0;
			for (int a = 0;*(update + a) != '\0';a++)
				j++;
			*(update+j)=':';
			j++;
			while(1){
				c=getc(movie_log);
				if(c==':'){
					break;
				}
			}
		}
		c=getc(movie_log);
		if (c != '=') {
			*(update + j) = c;
			j++;
			while (1) {
				c = getc(movie_log);
				if (c == ':') {
					*(update+j)=c;
					j++;
					break;
				}
				*(update + j) = c;
				j++;
			}
		}
		else {
			strcat(update, genre);
		j=0;	
			for (int a = 0;*(update + a) != '\0';a++)
				j++;
			*(update+j)=':';
			j++;
			while(1){
				c=getc(movie_log);
				if(c==':')
				{break;}
		}
		}
c=getc(movie_log);
		if (c != '=') {
			*(update + j) = c;
			j++;
			while (1) {
				c = getc(movie_log);
				if (c == ':') {
					*(update+j)=c;
					j++;
					break;
				}
				*(update + j) = c;
				j++;
			}
		}
		else {
			strcat(update, director);
			j=0;
			for (int a = 0;*(update + a) != '\0';a++)
				j++;
			*(update+j)=':';
			j++;
			while(1){
				c=getc(movie_log);
				if(c==':')
				{break;}
			}
		}
		c=getc(movie_log);
		if (c != '=') {
			*(update + j) = c;
			j++;
			while (1) {
				c = getc(movie_log);
				if (c == ':') {
					*(update+j)=c;
					j++;
					break;
				}
				*(update + j) = c;
				j++;
			}
		}
		else {
			strcat(update, year);
			j=0;
			for (int a = 0;*(update + a) != '\0';a++)
				j++;
			*(update+j)=':';
			j++;
			while(1){
				c=getc(movie_log);
				if(c==':')
					break;

		
		}
		}
		c=getc(movie_log);
		if (c != '=') {
			*(update + j) = c;
			j++;
			while (1) {
				c = getc(movie_log);
				if (c == ':') {
					*(update+j)=c;
					j++;
					break;
				}
				*(update + j) = c;
				j++;
			}
		}
		else {
			strcat(update, time);
			j=0;
			for (int a = 0;*(update + a) != '\0';a++)
				j++;
			*(update+j)=':';
			j++;
			while(1){
				c=getc(movie_log);
				if(c==':')
					break;
			}
		}
		c=getc(movie_log);
		if (c != '=') {
			*(update + j) = c;
			j++;
			while (1) {
				c = getc(movie_log);
				if (c == '\n' || feof(movie_log)) {
					break;
				}
				*(update + j) = c;
				j++;
			}
		}
		else {
			strcat(update, actor);
		}
		free((head + a)->str);
		(head + a)->str = update;
		break;
	}
			}
	
	//printf("%s",(head)->str);
	//return 0;
		}	
		else if(c=='d'){
			j=0;
			while(1){
                                c=getc(movie_log);
                                if(c==':')
                                        break;
                        }
                        array=(char *)calloc(100,sizeof(char));
                        while(1){
                                c=getc(movie_log);
                                if(c==':'){
                                        break;}
                                *(array+j)=c;
                                j++;
                        }
                        j=0;
			serial_num=atoi(array);
			free(array);
			for(int a=0;a<i;a++){
				if(serial_num==(head+a)->serial_num){
					(head+a)->serial_num=0;
					break;
				}
			}
			while(1){
				c=getc(movie_log);
				if(c=='\n')
					break;
				else if(feof(movie_log))
					break;
			}
		}
	}
	for(int w=0;w<i;w++){
		if((head+w)->serial_num!=0){
		fprintf(movie_list,"%d:",(head+w)->serial_num);
		if(w==i-1)
			fprintf(movie_list,"%s",(head+w)->str);
		else
			fprintf(movie_list,"%s\n",(head+w)->str);
		}
		else
			;
	}

	fclose(movie_log);
	fclose(movie_list);
	return 0;
}
