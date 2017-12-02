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
	int i = 0, c,log_num=0,j=0,k=0,serial_num;
	char *array,*update;

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
					*(((head+i)->str) + k) = c;
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
			while(1){
				c=getc(movie_log);
				if(c=='\n'){
					*(update+j)=c;
					break;}
				else if(feof(movie_log))
					break;
				*(update+j)=c;
				j++;
			}
			j=0;
			serial_num=atoi(array);
			free(array);
			for(int a=0;(head+a)->str!=NULL;a++){
				if(serial_num==(head+a)->serial_num){
					free((head+a)->str);
					(head+a)->str=update;
					break;
				}
				
			}
			free(update);
		}
		else if(c=='d'){
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
			for(int a=0;(head+a)->str!=NULL;a++){
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

	for(int a=0;(head+a)->str!=NULL;a++){
		if((head+a)->serial_num==0)
			;
		else{
			fprintf(movie_list,"%d:",(head+a)->serial_num);
			fprintf(movie_list,"%s",(head+a)->str);
		}
	}
	
	fclose(movie_log);
	fclose(movie_list);
	return 0;
}
