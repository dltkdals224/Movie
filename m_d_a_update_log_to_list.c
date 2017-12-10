#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
struct movie_list {
	int serial_num;
	struct linked_list *title;
	struct linked_list *genre;
	struct movie_to_director *director;
	int year;
	int time;
	struct movie_to_actor *actor;
	struct movie_list *next;
};
struct director_list {
	int serial_num;
	struct linked_list *name;
	struct linked_list *sex;
	struct linked_list *birth;
	struct d_title_to_title *best_movies;
	struct director_list *next;
};
struct actor_list {
	int serial_num;
	struct linked_list *name;
	struct linked_list *sex;
	struct linked_list *birth;
	struct a_title_to_title *best_movies;
	struct actor_list *next;
};
struct linked_list {
	char *str;
	struct linked_list *next;
};
struct movie_to_director {
	char *str;
	struct director_list *pair;
	struct movie_to_director *next;
};
struct movie_to_actor {
	char *str;
	struct actor_list *pair;
	struct movie_to_actor *next;
};
struct a_title_to_title {
	char *str;
	struct movie_list *title;
	struct d_title_to_title *pair;
	struct a_title_to_title *next;
};
struct d_title_to_title {
	char *str;
	struct movie_list *title;
	struct a_title_to_title *pair;
	struct d_title_to_title *next;
};
void director_memory_make(struct director_list **head, struct director_list **temp){
	struct linked_list *tmp = NULL;
	struct d_title_to_title *ttmp = NULL;
	int i = 0, c;
	char *array;

	FILE *director_list;
	director_list = fopen("director_list", "r");

	while ((c = getc(director_list)) != EOF) {
		if (*head == NULL) {
			*head = (struct director_list *)calloc(1, sizeof(struct director_list));
			array = (char *)calloc(100, sizeof(char));
			*(array + i) = c;
			i++;

			while (1) {
				c = getc(director_list);
				if (c == ':')
					break;
				*(array + i) = c;
				i++;
			}
			(*head)->serial_num = atoi(array);
			free(array);
			i = 0;

			(*head)->name = (struct linked_list *)calloc(1, sizeof(struct linked_list));
			(*head)->name->str = (char *)calloc(100, sizeof(char));
			while (1) {
				c = getc(director_list);
				if (c == ':')
					break;
				*(((*head)->name->str) + i) = c;
				i++;
			}
			i = 0;

			(*head)->sex = (struct linked_list *)calloc(1, sizeof(struct linked_list));
			(*head)->sex->str = (char *)calloc(100, sizeof(char));

			while (1) {
				c = getc(director_list);
				if (c == ':')
					break;
				*(((*head)->sex->str) + i) = c;
				i++;
			}
			i = 0;

			(*head)->birth = (struct linked_list *)calloc(1, sizeof(struct linked_list));
			(*head)->birth->str = (char *)calloc(8, sizeof(char));
			while (1) {
				c = getc(director_list);
				if (c == ':')
					break;
				*(((*head)->birth->str) + i) = c;
				i++;
			}
			i = 0;

			(*head)->best_movies = (struct d_title_to_title *)calloc(1, sizeof(struct d_title_to_title));
			(*head)->best_movies->str = (char *)calloc(1000, sizeof(char));
			array = (char *)calloc(100, sizeof(char));
			while (1) {
				c = getc(director_list);
				if (c == '\n') {
					ttmp = (*head)->best_movies;
					while (ttmp->next != NULL)
						ttmp = ttmp->next;
					ttmp->str = (char *)calloc(100, sizeof(char));
					ttmp->next = NULL;
					strcpy(ttmp->str, array);
					break;
				}
				else if (feof(director_list)) {
					ttmp = (*head)->best_movies;
					while (ttmp->next != NULL)
						ttmp = ttmp->next;
					ttmp->str = (char *)calloc(100, sizeof(char));
					ttmp->next = NULL;
					strcpy(ttmp->str, array);
					break;
				}
				else if (c == ',') {
					if ((*head)->best_movies->next == NULL) {
						(*head)->best_movies->next = (struct d_title_to_title *)calloc(1, sizeof(struct d_title_to_title));
						strcpy((*head)->best_movies->str, array);
					}
					else {
						ttmp = (*head)->best_movies;
						while (ttmp->next != NULL)
							ttmp = ttmp->next;
						ttmp->str = (char *)calloc(100, sizeof(char));
						ttmp->next = (struct d_title_to_title *)calloc(1, sizeof(struct d_title_to_title));
						strcpy(ttmp->str, array);
					}
					i = 0;
					free(array);
					array = (char *)calloc(100, sizeof(char));
				}
				else {
					*(array + i) = c;
					i++;
				}
			}
			free(array);
			i = 0;

		}

		else {
			*temp = *head;
			while ((*temp)->next != NULL)
				*temp = (*temp)->next;
			(*temp)->next = (struct director_list *)calloc(1, sizeof(struct director_list));
			array = (char *)calloc(100, sizeof(char));
			*(array + i) = c;
			i++;

			while (1) {
				c = getc(director_list);
				if (c == ':')
					break;
				*(array + i) = c;
				i++;
			}
			(*temp)->next->serial_num = atoi(array);
			free(array);
			i = 0;

			(*temp)->next->name = (struct linked_list *)calloc(1, sizeof(struct linked_list));
			(*temp)->next->name->str = (char *)calloc(100, sizeof(char));
			while (1) {
				c = getc(director_list);
				if (c == ':')
					break;
				*(((*temp)->next->name->str) + i) = c;
				i++;
			}
			i = 0;

			(*temp)->next->sex = (struct linked_list *)calloc(1, sizeof(struct linked_list));
			(*temp)->next->sex->str = (char *)calloc(100, sizeof(char));

			while (1) {
				c = getc(director_list);
				if (c == ':')
					break;
				*(((*temp)->next->sex->str) + i) = c;
				i++;
			}
			i = 0;

			(*temp)->next->birth = (struct linked_list *)calloc(1, sizeof(struct linked_list));
			(*temp)->next->birth->str = (char *)calloc(8, sizeof(char));
			while (1) {
				c = getc(director_list);
				if (c == ':')
					break;
				*(((*temp)->next->birth->str) + i) = c;
				i++;
			}
			i = 0;

			(*temp)->next->best_movies = (struct d_title_to_title *)calloc(1, sizeof(struct d_title_to_title));
			(*temp)->next->best_movies->str = (char *)calloc(1000, sizeof(char));
			array = (char *)calloc(100, sizeof(char));
			while (1) {
				c = getc(director_list);
				if (c == '\n') {
					ttmp = (*temp)->next->best_movies;
					while (ttmp->next != NULL)
						ttmp = ttmp->next;
					ttmp->str = (char *)calloc(100, sizeof(char));
					ttmp->next = NULL;
					strcpy(ttmp->str, array);
					break;
				}
				else if (feof(director_list)) {
					ttmp = (*temp)->next->best_movies;
					while (ttmp->next != NULL)
						ttmp = ttmp->next;
					ttmp->str = (char *)calloc(100, sizeof(char));
					ttmp->next = NULL;
					strcpy(ttmp->str, array);
					break;
				}
				else if (c == ',') {
					if ((*temp)->next->best_movies->next == NULL) {
						(*temp)->next->best_movies->next = (struct d_title_to_title *)calloc(1, sizeof(struct d_title_to_title));
						strcpy((*temp)->next->best_movies->str, array);
					}
					else {
						ttmp = (*temp)->next->best_movies;
						while (ttmp->next != NULL)
							ttmp = ttmp->next;
						ttmp->str = (char *)calloc(100, sizeof(char));
						ttmp->next = (struct d_title_to_title *)calloc(1, sizeof(struct d_title_to_title));
						strcpy(ttmp->str, array);
					}
					i = 0;
					free(array);
					array = (char *)calloc(100, sizeof(char));
				}
				else {
					*(array + i) = c;
					i++;
				}
			}
			free(array);
			i = 0;
		}
	}

	fclose(director_list);
	return ;
}
void actor_memory_make(struct actor_list **head, struct actor_list **temp) {
	struct linked_list *tmp = NULL;
	struct a_title_to_title *ttmp = NULL;
	int i = 0, feoff = 1, c;
	char *array;

	FILE *actor_list;
	actor_list = fopen("actor_list", "r");

	while ((c = getc(actor_list)) != EOF) {
		if (*head == NULL) {
			*head = (struct actor_list *)calloc(1, sizeof(struct actor_list));
			array = (char *)calloc(100, sizeof(char));
			*(array + i) = c;
			i++;
			while (1) {
				c = getc(actor_list);
				if (c == ':')
					break;
				*(array + i) = c;
				i++;
			}
			(*head)->serial_num = atoi(array);
			free(array);
			i = 0;

			(*head)->name = (struct linked_list *)calloc(1, sizeof(struct linked_list));
			(*head)->name->str = (char *)calloc(100, sizeof(char));
			while (1) {
				c = getc(actor_list);
				if (c == ':')
					break;
				*(((*head)->name->str) + i) = c;
				i++;
			}
			i = 0;

			(*head)->sex = (struct linked_list *)calloc(1, sizeof(struct linked_list));
			(*head)->sex->str = (char *)calloc(100, sizeof(char));

			while (1) {
				c = getc(actor_list);
				if (c == ':')
					break;
				*(((*head)->sex->str) + i) = c;
				i++;
			}
			i = 0;

			(*head)->birth = (struct linked_list *)calloc(1, sizeof(struct linked_list));
			(*head)->birth->str = (char *)calloc(8, sizeof(char));
			while (1) {
				c = getc(actor_list);
				if (c == ':')
					break;
				*(((*head)->birth->str) + i) = c;
				i++;
			}
			i = 0;


			(*head)->best_movies = (struct a_title_to_title *)calloc(1, sizeof(struct a_title_to_title));
			(*head)->best_movies->str = (char *)calloc(1000, sizeof(char));
			array = (char *)calloc(100, sizeof(char));
			while (1) {
				c = getc(actor_list);
				if (c == '\n') {
					ttmp = (*head)->best_movies;
					while (ttmp->next != NULL)
						ttmp = ttmp->next;
					ttmp->str = (char *)calloc(100, sizeof(char));
					ttmp->next = NULL;
					strcpy(ttmp->str, array);
					break;
				}
				else if (feof(actor_list)) {
					ttmp = (*head)->best_movies;
					while (ttmp->next != NULL)
						ttmp = ttmp->next;
					ttmp->str = (char *)calloc(100, sizeof(char));
					ttmp->next = NULL;
					strcpy(ttmp->str, array);
					break;
				}
				else if (c == ',') {
					if ((*head)->best_movies->next == NULL) {
						(*head)->best_movies->next = (struct a_title_to_title *)calloc(1, sizeof(struct a_title_to_title));
						strcpy((*head)->best_movies->str, array);
					}
					else {
						ttmp = (*head)->best_movies;
						while (ttmp->next != NULL)
							ttmp = ttmp->next;
						ttmp->str = (char *)calloc(100, sizeof(char));
						ttmp->next = (struct a_title_to_title *)calloc(1, sizeof(struct a_title_to_title));
						strcpy(ttmp->str, array);
					}
					i = 0;
					free(array);
					array = (char *)calloc(100, sizeof(char));
				}
				else {
					*(array + i) = c;
					i++;
				}
			}
			free(array);
			i = 0;

		}
		else {
			*temp = (*head);
			while ((*temp)->next != NULL)
				(*temp) = (*temp)->next;
			(*temp)->next = (struct actor_list *)calloc(1, sizeof(struct actor_list));
			array = (char *)calloc(100, sizeof(char));
			*(array + i) = c;
			i++;

			while (1) {
				c = getc(actor_list);
				if (c == ':')
					break;
				*(array + i) = c;
				i++;
			}
			(*temp)->next->serial_num = atoi(array);
			free(array);
			i = 0;

			(*temp)->next->name = (struct linked_list *)calloc(1, sizeof(struct linked_list));
			(*temp)->next->name->str = (char *)calloc(100, sizeof(char));
			while (1) {
				c = getc(actor_list);
				if (c == ':')
					break;
				*(((*temp)->next->name->str) + i) = c;
				i++;
			}
			i = 0;

			(*temp)->next->sex = (struct linked_list *)calloc(1, sizeof(struct linked_list));
			(*temp)->next->sex->str = (char *)calloc(100, sizeof(char));

			while (1) {
				c = getc(actor_list);
				if (c == ':')
					break;
				*(((*temp)->next->sex->str) + i) = c;
				i++;
			}
			i = 0;

			(*temp)->next->birth = (struct linked_list *)calloc(1, sizeof(struct linked_list));
			(*temp)->next->birth->str = (char *)calloc(8, sizeof(char));
			while (1) {
				c = getc(actor_list);
				if (c == ':')
					break;
				*(((*temp)->next->birth->str) + i) = c;
				i++;
			}
			i = 0;

			(*temp)->next->best_movies = (struct a_title_to_title *)calloc(1, sizeof(struct a_title_to_title));
			(*temp)->next->best_movies->str = (char *)calloc(1000, sizeof(char));
			array = (char *)calloc(100, sizeof(char));
			while (1) {
				c = getc(actor_list);
				if (c == '\n') {
					ttmp = (*temp)->next->best_movies;
					while (ttmp->next != NULL)
						ttmp = ttmp->next;
					ttmp->str = (char *)calloc(100, sizeof(char));
					ttmp->next = NULL;
					strcpy(ttmp->str, array);
					break;
				}
				else if (feof(actor_list)) {
					ttmp = (*temp)->next->best_movies;
					while (ttmp->next != NULL)
						ttmp = ttmp->next;
					ttmp->str = (char *)calloc(100, sizeof(char));
					ttmp->next = NULL;
					strcpy(ttmp->str, array);
					break;
				}
				else if (c == ',') {
					if ((*temp)->next->best_movies->next == NULL) {
						(*temp)->next->best_movies->next = (struct a_title_to_title *)calloc(1, sizeof(struct a_title_to_title));
						strcpy((*temp)->next->best_movies->str, array);
					}
					else {
						ttmp = (*temp)->next->best_movies;
						while (ttmp->next != NULL)
							ttmp = ttmp->next;
						ttmp->str = (char *)calloc(100, sizeof(char));
						ttmp->next = (struct a_title_to_title *)calloc(1, sizeof(struct a_title_to_title));
						strcpy(ttmp->str, array);
					}
					i = 0;
					free(array);
					array = (char *)calloc(100, sizeof(char));
				}
				else {
					*(array + i) = c;
					i++;
				}
			}
			free(array);
			i = 0;
		}
	}

	fclose(actor_list);
	return;
}
void movie_memory_make(struct movie_list **head, struct movie_list **temp) {
	struct linked_list *tmp = NULL;
	struct movie_to_actor *ttmp = NULL;
	int i = 0, c;
	char *array;

	FILE *movie_list;
	movie_list = fopen("movie_list", "r");


	while ((c = getc(movie_list)) != EOF) {
		if (*head == NULL) {
			*head = (struct movie_list *)calloc(1, sizeof(struct movie_list));
			array = (char *)calloc(100, sizeof(char));
			*(array + i) = c;
			i++;

			while (1) {
				c = getc(movie_list);
				if (c == ':')
					break;
				*(array + i) = c;
				i++;
			}
			(*head)->serial_num = atoi(array);
			free(array);
			i = 0;

			(*head)->title = (struct linked_list *)calloc(1, sizeof(struct linked_list));
			(*head)->title->str = (char *)calloc(100, sizeof(char));
			while (1) {
				c = getc(movie_list);
				if (c == ':')
					break;
				*(((*head)->title->str) + i) = c;
				i++;
			}
			i = 0;

			(*head)->genre = (struct linked_list *)calloc(1, sizeof(struct linked_list));
			(*head)->genre->str = (char *)calloc(100, sizeof(char));
			while (1) {
				c = getc(movie_list);
				if (c == ':')
					break;
				*(((*head)->genre->str) + i) = c;
				i++;
			}
			i = 0;


			(*head)->director = (struct movie_to_director *)calloc(1, sizeof(struct movie_to_director));
			(*head)->director->str = (char *)calloc(1000, sizeof(char));
			while (1) {
				c = getc(movie_list);
				if (c == ':')
					break;
				*(((*head)->director->str) + i) = c;
				i++;
			}
			i = 0;

			array = (char *)calloc(40, sizeof(char));
			while (1) {
				c = getc(movie_list);
				if (c == ':')
					break;
				*(array + i) = c;
				i++;
			}
			(*head)->year = atoi(array);
			free(array);
			i = 0;

			array = (char *)calloc(30, sizeof(char));
			while (1) {
				c = getc(movie_list);
				if (c == ':')
					break;
				*(array + i) = c;
				i++;
			}
			(*head)->time = atoi(array);
			free(array);
			i = 0;

			(*head)->actor = (struct movie_to_actor *)calloc(1, sizeof(struct movie_to_actor));
			(*head)->actor->str = (char *)calloc(1000, sizeof(char));
			array = (char *)calloc(100, sizeof(char));
			while (1) {
				c = getc(movie_list);
				if (c == '\n') {
					ttmp = (*head)->actor;
					while (ttmp->next != NULL)
						ttmp = ttmp->next;
					ttmp->str = (char *)calloc(100, sizeof(char));
					ttmp->next = NULL;
					strcpy(ttmp->str, array);
					break;
				}
				else if (feof(movie_list)) {
					ttmp = (*head)->actor;
					while (ttmp->next != NULL)
						ttmp = ttmp->next;
					ttmp->str = (char *)calloc(100, sizeof(char));
					ttmp->next = NULL;
					strcpy(ttmp->str, array);
					break;
				}


				else if (c == ',') {
					if ((*head)->actor->next == NULL) {
						(*head)->actor->next = (struct movie_to_actor *)calloc(1, sizeof(struct movie_to_actor));

						strcpy((*head)->actor->str, array);
					}
					else {
						ttmp = (*head)->actor;
						while (ttmp->next != NULL)
							ttmp = ttmp->next;
						ttmp->str = (char *)calloc(100, sizeof(char));
						ttmp->next = (struct movie_to_actor *)calloc(1, sizeof(struct movie_to_actor));
						strcpy(ttmp->str, array);
					}
					i = 0;
					free(array);
					array = (char *)calloc(100, sizeof(char));
				}
				else {
					*(array + i) = c;
					i++;
				}
			}

			free(array);
			i = 0;
		}
		else {
			*temp = *head;
			while ((*temp)->next != NULL)
				(*temp) = (*temp)->next;
			(*temp)->next = (struct movie_list *)calloc(1, sizeof(struct movie_list));
			array = (char *)calloc(100, sizeof(char));
			*(array + i) = c;
			i++;

			while (1) {
				c = getc(movie_list);
				if (c == ':')
					break;
				*(array + i) = c;
				i++;
			}
			(*temp)->next->serial_num = atoi(array);
			free(array);
			i = 0;

			(*temp)->next->title = (struct linked_list *)calloc(1, sizeof(struct linked_list));
			(*temp)->next->title->str = (char *)calloc(100, sizeof(char));

			while (1) {
				c = getc(movie_list);
				if (c == ':')
					break;
				*(((*temp)->next->title->str) + i) = c;
				i++;
			}
			i = 0;

			(*temp)->next->genre = (struct linked_list *)calloc(1, sizeof(struct linked_list));
			(*temp)->next->genre->str = (char *)calloc(100, sizeof(char));
			while (1) {
				c = getc(movie_list);
				if (c == ':')
					break;
				*(((*temp)->next->genre->str) + i) = c;
				i++;
			}
			i = 0;


			(*temp)->next->director = (struct movie_to_director *)calloc(1, sizeof(struct movie_to_director));
			(*temp)->next->director->str = (char *)calloc(1000, sizeof(char));
			while (1) {
				c = getc(movie_list);
				if (c == ':')
					break;
				*(((*temp)->next->director->str) + i) = c;
				i++;
			}
			i = 0;

			array = (char *)calloc(40, sizeof(char));
			while (1) {
				c = getc(movie_list);
				if (c == ':')
					break;
				*(array + i) = c;
				i++;
			}
			(*temp)->next->year = atoi(array);
			free(array);
			i = 0;

			array = (char *)calloc(30, sizeof(char));
			while (1) {
				c = getc(movie_list);
				if (c == ':')
					break;
				*(array + i) = c;
				i++;
			}
			(*temp)->next->time = atoi(array);
			free(array);
			i = 0;

			(*temp)->next->actor = (struct movie_to_actor *)calloc(1, sizeof(struct movie_to_actor));
			(*temp)->next->actor->str = (char *)calloc(1000, sizeof(char));
			array = (char *)calloc(100, sizeof(char));
			while (1) {
				c = getc(movie_list);
				if (c == '\n') {
					ttmp = (*temp)->next->actor;
					while (ttmp->next != NULL)
						ttmp = ttmp->next;
					ttmp->str = (char *)calloc(100, sizeof(char));
					ttmp->next = NULL;
					strcpy(ttmp->str, array);
					break;
				}
				else if (feof(movie_list)) {
					ttmp = (*temp)->next->actor;
					while (ttmp->next != NULL)
						ttmp = ttmp->next;
					ttmp->str = (char *)calloc(100, sizeof(char));
					ttmp->next = NULL;
					strcpy(ttmp->str, array);
					break;
				}

				else if (c == ',') {
					if ((*temp)->next->actor->next == NULL) {
						(*temp)->next->actor->next = (struct movie_to_actor *)calloc(1, sizeof(struct movie_to_actor));

						strcpy((*temp)->next->actor->str, array);
					}
					else {
						ttmp = (*temp)->next->actor;
						while (ttmp->next != NULL)
							ttmp = ttmp->next;
						ttmp->str = (char *)calloc(100, sizeof(char));
						ttmp->next = (struct movie_to_actor *)calloc(1, sizeof(struct movie_to_actor));
						strcpy(ttmp->str, array);
					}
					i = 0;
					free(array);
					array = (char *)calloc(100, sizeof(char));
				}
				else {
					*(array + i) = c;
					i++;
				}
			}


			free(array);
			i = 0;
		}
	}
	fclose(movie_list);
	return;
}
void m_d_a_link(struct movie_list **head_m, struct director_list **head_d, struct actor_list **head_a){
	struct movie_list *temp_m;
	struct director_list *temp_d;
	struct actor_list *temp_a;
	struct movie_to_director *tmp_md;
	struct movie_to_actor *tmp_ma;
	struct d_title_to_title *tmp_dt;
	struct a_title_to_title *tmp_at;

	temp_m = *head_m;
		temp_d = *head_d;
	while (1) {
		while (1) {
			if (strcmp(temp_d->name->str, temp_m->director->str) == 0) {
				temp_m->director->pair = temp_d;
				break;
			}
			if (temp_d->next == NULL)
				break;
			temp_d = temp_d->next;
		}
		if (temp_m->next == NULL)
			break;
		temp_m = temp_m->next;
	}//movie의 director에서 director로 연결

	temp_m = *head_m;
	while (1) {
		tmp_ma = temp_m->actor;
		while (1) {
			temp_a = *head_a;
			while (1) {
				if (strcmp(tmp_ma->str, temp_a->name->str) == 0) {
					tmp_ma->pair = temp_a;
					break;
				}
				if (temp_a->next == NULL)
					break;
				temp_a = temp_a->next;
			}
			if (tmp_ma->next == NULL)
				break;
			tmp_ma = tmp_ma->next;
		}
		if (temp_m->next == NULL)
			break;
		temp_m = temp_m->next;
	}//movie의 actor에서 actor로 연결

	temp_d = *head_d;
	while (1) {
		tmp_dt = temp_d->best_movies;
		while (1) {
			temp_m = *head_m;
			while (1) {
				if (strcmp(temp_m->title->str, tmp_dt->str) == 0) {
					tmp_dt->title = temp_m;
					break;
				}
				if (temp_m->next == NULL)
					break;
				temp_m = temp_m->next;
			}
			if (tmp_dt->next == NULL)
				break;
			tmp_dt = tmp_dt->next;
		}
		if (temp_d->next == NULL)
			break;
		temp_d = temp_d->next;
	}//director의 title에서 movie로 연결

	temp_a = *head_a;
	while (1) {
		tmp_at = temp_a->best_movies;
		while (1) {
			temp_m = *head_m;
			while (1) {
				if (strcmp(temp_m->title->str, tmp_at->str) == 0) {
					tmp_at->title = temp_m;
					break;
				}
				if (temp_m->next == NULL)
					break;
				temp_m = temp_m->next;
			}
			if (tmp_at->next == NULL)
				break;
			tmp_at = tmp_at->next;
		}
		if (temp_a->next == NULL)
			break;
		temp_a = temp_a->next;
	}//actor의 title에서 movie로 연결

		temp_d = *head_d;
	while (1) {
		tmp_dt = temp_d->best_movies;
		while (1) {
			temp_a = *head_a;
			while (1) {
				tmp_at = temp_a->best_movies;
				while (1) {
					if (strcmp(tmp_at->str, tmp_dt->str) == 0) {
						tmp_at->pair = tmp_dt;
						tmp_dt->pair = tmp_at;
						break;
					}
					if (tmp_at->next == NULL)
						break;
					tmp_at = tmp_at->next;
				}
				if (temp_a->next == NULL)
					break;
				temp_a = temp_a->next;
			}
			if (tmp_dt->next == NULL)
				break;
			tmp_dt = tmp_dt->next;
		}
		if (temp_d->next == NULL)
			break;
		temp_d = temp_d->next;
	}//director의 title과 actor의 title 상호 연결

	return;
	}
void reverseString(char* s) {
        size_t size = strlen(s);
        char temp;

        for (size_t i = 0; i < size / 2; i++) {
                temp = *(s+i);
                *(s+i)= *(s+size - 1 - i);
                *(s+size - 1 - i) = temp;
        }
}
struct log_head {
	int serial_num;
	char *str;
};
int log_to_list_m(){
	struct log_head *head=NULL;
	int i = 0, c,log_num=0,j=0,serial_num,k=0;
	char *array,*re_name,*update,*p,*title,*genre,*director,*year,*timi,*actor;
	time_t t=time(NULL);
	struct tm tm=*localtime(&t);

	FILE *movie_log;
	FILE *movie_list;
	FILE *origin_movie_list;
	movie_log = fopen("movie_log", "r");

	if((movie_list=fopen("movie_list","r"))==NULL){
		fclose(movie_list);
		movie_list=fopen("movie_list","w");
	}
	else{
		re_name=(char *)calloc(100,sizeof(char));
		sprintf(re_name,"movie_list.%d%20d%20d%20d%20d",tm.tm_year+1900,tm.tm_mon+1,tm.tm_mday,tm.tm_hour,tm.tm_min);
		origin_movie_list=fopen(re_name,"w");
		while(1){
			c-fgetc(movie_list);
			if(!feof(movie_list))
					fputc(c,origin_movie_list);
			else
				break;
		}
		fclose(movie_list);
		fclose(origin_movie_list);
	
		movie_list=fopen("movie_list","w");
	}

	while((c=getc(movie_log))!=EOF)
		if (c == '\n')
			log_num++;

	head = (struct log_head*)calloc(log_num, sizeof(struct log_head));

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
		timi = p;
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
			strcat(update, timi);
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
	return i;
}
int log_to_list_d(){
	struct log_head *head = NULL;
	int i = 0, c, log_num = 0, j = 0, serial_num, k = 0;
	char *array,*re_name, *update, *p, *name, *sex, *birth, *best_movies;
	time_t t=time(NULL);
	struct tm tm=*localtime(&t);

	FILE *director_log;
	FILE *director_list;
	FILE *origin_director_list;
	director_log = fopen("director_log", "r");

	if((director_list=fopen("director_list","r"))==NULL)
	{
		fclose(director_list);
		director_list=fopen("director_list","w");
	}
	else{
		re_name=(char *)calloc(100,sizeof(char));
		sprintf(re_name,"director_list.%d%20d%20d%20d%20d",tm.tm_year+1900,tm.tm_mon+1,tm.tm_mday,tm.tm_hour,tm.tm_min);
		origin_director_list=fopen(re_name,"w");
		while(1){
			c=fgetc(director_list);
			if(!feof(director_list))
				fputc(c,origin_director_list);
			else 
				break;
		}
		fclose(director_list);
		fclose(origin_director_list);

		director_list=fopen("director_list","w");
	}

	while ((c = getc(director_log)) != EOF)
		if (c == '\n')
			log_num++;

	head = (struct log_head*)calloc(log_num, sizeof(struct log_head));

	rewind(director_log);

	while ((c = getc(director_log)) != EOF) {
		if (c == 'a') {
			j = 0;

			(head + i)->str = (char *)calloc(1000, sizeof(char));

			while (1) {
				c = getc(director_log);
				if (c == ':') {
					break;
				}
			}
			array = (char *)calloc(100, sizeof(char));
			while (1) {
				c = getc(director_log);

				if (c == ':') {
					break;
				}
				*(array + j) = c;
				j++;
			}
			(head + i)->serial_num = atoi(array);
			free(array);
			j = 0;

			while (1) {
				c = getc(director_log);
				if (c == '\n') {
					break;
				}
				else if (feof(director_log))
					break;
				*(((head + i)->str) + k) = c;
				k++;
			}
			k = 0;
			i++;

		}
		else if (c == 'u') {
			j = 0;
			update = (char *)calloc(100, sizeof(char));

			while (1) {
				c = getc(director_log);
				if (c == ':')
					break;
			}
			array = (char *)calloc(100, sizeof(char));
			while (1) {
				c = getc(director_log);
				if (c == ':') {
					break;
				}
				*(array + j) = c;
				j++;
			}
			j = 0;
			serial_num = atoi(array);
			free(array);
			for (int a = 0;a < i;a++) {
				if (serial_num == (head + a)->serial_num) {
					p = strtok((head + a)->str, ":");
					name = p;
					p = strtok(NULL, ":");
					sex = p;
					p = strtok(NULL, ":");
					birth = p;
					p = strtok(NULL, "\n");
					best_movies = p;

					c = getc(director_log);
					if (c != '=') {
						*(update + j) = c;
						j++;
						while (1) {
							c = getc(director_log);
							if (c == ':') {
								*(update + j) = c;
								j++;
								break;
							}
							*(update + j) = c;
							j++;
						}
					}
					else {
						strcat(update, name);
						j = 0;
						for (int a = 0;*(update + a) != '\0';a++)
							j++;
						*(update + j) = ':';
						j++;
						while (1) {
							c = getc(director_log);
							if (c == ':') {
								break;
							}
						}
					}
					c = getc(director_log);
					if (c != '=') {
						*(update + j) = c;
						j++;
						while (1) {
							c = getc(director_log);
							if (c == ':') {
								*(update + j) = c;
								j++;
								break;
							}
							*(update + j) = c;
							j++;
						}
					}
					else {
						strcat(update, sex);
						j = 0;
						for (int a = 0;*(update + a) != '\0';a++)
							j++;
						*(update + j) = ':';
						j++;
						while (1) {
							c = getc(director_log);
							if (c == ':') {
								break;
							}
						}
					}

					c = getc(director_log);
					if (c != '=') {
						*(update + j) = c;
						j++;
						while (1) {
							c = getc(director_log);
							if (c == ':') {
								*(update + j) = c;
								j++;
								break;
							}
							*(update + j) = c;
							j++;
						}
					}
					else {
						strcat(update, birth);
						j = 0;
						for (int a = 0;*(update + a) != '\0';a++)
							j++;
						*(update + j) = ':';
						j++;
						while (1) {
							c = getc(director_log);
							if (c == ':') {
								break;
							}
						}
					}
					c = getc(director_log);
					if (c != '=') {
						*(update + j) = c;
						j++;
						while (1) {
							c = getc(director_log);
							if (c == '\n' || feof(director_log)) {
								break;
							}
							*(update + j) = c;
							j++;
						}
					}
					else {
						strcat(update, best_movies);
					}
					free((head + a)->str);
					(head + a)->str = update;
					break;
				}
			}
		}
				else if (c == 'd') {
					j = 0;
					while (1) {
						c = getc(director_log);
						if (c == ':')
							break;
					}
					array = (char *)calloc(100, sizeof(char));
					while (1) {
						c = getc(director_log);
						if (c == ':') {
							break;
						}
						*(array + j) = c;
						j++;
					}
					j = 0;
					serial_num = atoi(array);
					free(array);
					for (int a = 0;a<i;a++) {
						if (serial_num == (head + a)->serial_num) {
							(head + a)->serial_num = 0;
							break;
						}
					}
					while (1) {
						c = getc(director_log);
						if (c == '\n')
							break;
						else if (feof(director_log))
							break;
					}
				}
		}

		for (int w = 0;w<i;w++) {
			if ((head + w)->serial_num != 0) {
				fprintf(director_list, "%d:", (head + w)->serial_num);
				if (w == i - 1)
					fprintf(director_list, "%s", (head + w)->str);
				else
					fprintf(director_list, "%s\n", (head + w)->str);
			}
			else
				;
		}
printf("%d",i);
		fclose(director_log);
		fclose(director_list);
		return i;
}
int log_to_list_a(){
	struct log_head *head = NULL;
	int i = 0, c, log_num = 0,j = 0, serial_num, k = 0;
	char *array,*re_name, *update, *p, *name, *birth, *sex, *best_movies;
	time_t t=time(NULL);
	struct tm tm=*localtime(&t);

	FILE *actor_log;
	FILE *actor_list;
	FILE *origin_actor_list;
	actor_log = fopen("actor_log", "r");

	if((actor_list=fopen("actor_list","r"))==NULL)
	{
		fclose(actor_list);
		actor_list=fopen("actor_list","w");
	}
	else
	{
		re_name=(char *)calloc(100,sizeof(char));
		sprintf(re_name,"movie_list.%d%02d%02d%02d%02d",tm.tm_year+1900,tm.tm_mon+1,tm.tm_mday,tm.tm_hour,tm.tm_min);
		origin_actor_list=fopen(re_name,"w");
		while(1){
			c=fgetc(actor_list);

			if(!feof(actor_list))
					fputc(c,origin_actor_list);
			else
				break;
		}
		fclose(actor_list);
		fclose(origin_actor_list);

		actor_list=fopen("actor_list","w");
	}

	while ((c = getc(actor_log)) != EOF)
		if (c == '\n')
			log_num++;

	head = (struct log_head*)calloc(log_num, sizeof(struct log_head));

	rewind(actor_log);

	while((c=getc(actor_log))!=EOF){
		if (c == 'a') {
			j = 0;

			(head + i)->str = (char *)calloc(1000, sizeof(char));

			while (1) {
				c = getc(actor_log);
				if (c == ':')
					break;
			}
				array = (char *)calloc(100, sizeof(char));
				while (1) {
					c = getc(actor_log);

					if (c == ':') {
						break;
					}
					*(array + j) = c;
					j++;
				}
				(head + i)->serial_num = atoi(array);
				free(array);
				j = 0;

				while (1) {
					c = getc(actor_log);
					if (c == '\n') {
						break;
					}
					else if (feof(actor_log))
						break;
					*(((head + i)->str) + k) = c;
					k++;
				}
				k = 0;
				i++;
		}
		else if (c == 'u') {
			j = 0;
			update = (char *)calloc(100, sizeof(char));

			while (1) {
				c = getc(actor_log);
				if (c == ':')
					break;
			}
			array = (char *)calloc(100, sizeof(char));
			while (1) {
				c = getc(actor_log);
				if (c == ':') {
					break;
				}
				*(array + j) = c;
				j++;
			}
			j = 0;
			serial_num = atoi(array);
			free(array);
			for (int a = 0;a < i;a++) {
				if (serial_num == (head + a)->serial_num) {
					p = strtok((head + a)->str, ":");
					name = p;
					p = strtok(NULL, ":");
					sex = p;
					p = strtok(NULL, ":");
					birth = p;
					p = strtok(NULL, "\n");
					best_movies = p;

					c = getc(actor_log);
					if (c != '=') {
						*(update + j) = c;
						j++;
						while (1) {
							c = getc(actor_log);
							if (c == ':') {
								*(update + j) = c;
								j++;
								break;
							}
							*(update + j) = c;
							j++;
						}
					}
					else {
						strcat(update, name);
						j = 0;
						for (int a = 0;*(update + a) != '\0';a++)
							j++;
						*(update + j) = ':';
						j++;
						while (1) {
							c = getc(actor_log);
							if (c == ':') {
								break;
							}
						}
					}
					c = getc(actor_log);
					if (c != '=') {
						*(update + j) = c;
						j++;
						while (1) {
							c = getc(actor_log);
							if (c == ':') {
								*(update + j) = c;
								j++;
								break;
							}
							*(update + j) = c;
							j++;
						}
					}
					else {
						strcat(update, sex);
						j = 0;
						for (int a = 0;*(update + a) != '\0';a++)
							j++;
						*(update + j) = ':';
						j++;
						while (1) {
							c = getc(actor_log);
							if (c == ':')
							{
								break;
							}
						}
					}
					c = getc(actor_log);
					if (c != '=') {
						*(update + j) = c;
						j++;
						while (1) {
							c = getc(actor_log);
							if (c == ':') {
								*(update + j) = c;
								j++;
								break;
							}
							*(update + j) = c;
							j++;
						}
					}
					else {
						strcat(update, birth);
						j = 0;
						for (int a = 0;*(update + a) != '\0';a++)
							j++;
						*(update + j) = ':';
						j++;
						while (1) {
							c = getc(actor_log);
							if (c == ':')
							{
								break;
							}
						}
					}
					c = getc(actor_log);
					if (c != '=') {
						*(update + j) = c;
						j++;
						while (1) {
							c = getc(actor_log);
							if (c == '\n' || feof(actor_log)) {
								break;
							}
							*(update + j) = c;
							j++;
						}
					}
					else {
						strcat(update, best_movies);
						while(1){
							c=getc(actor_log);
							if(c=='\n'||feof(actor_log))
									break;
									}
					}
					free((head + a)->str);
					(head + a)->str = update;
					break;
				}
			}
		}
		else if (c == 'd') {
			j = 0;
			while (1) {
				c = getc(actor_log);
				if (c == ':')
					break;
			}
			array = (char *)calloc(100, sizeof(char));
			while (1) {
				c = getc(actor_log);
				if (c == ':') {
					break;
				}
				*(array + j) = c;
				j++;
			}
			j = 0;
			serial_num = atoi(array);
			free(array);
			for (int a = 0;a < i;a++) {
				if (serial_num == (head + a)->serial_num) {
					(head + a)->serial_num = 0;
					break;
				}
			}
			while (1) {
				c = getc(actor_log);
				if (c == '\n')
					break;
				else if (feof(actor_log))
					break;
			}
		}
	}
		for (int w = 0;w<i;w++) {
			if ((head + w)->serial_num != 0) {
				fprintf(actor_list, "%d:", (head + w)->serial_num);
				if (w == i - 1)
					fprintf(actor_list, "%s", (head + w)->str);
				else
					fprintf(actor_list, "%s\n", (head + w)->str);
			}
		}

		fclose(actor_log);
		fclose(actor_list);
		return i;
}

void update(struct movie_list *head_m,struct director_list *head_d,struct actor_list *head_a) {
	char *mda, *option, *number;
	char *title, *genre, *director, *year, *run, *actor, *name, *sex, *birth, *movie;
	int t = 0, g = 0, d = 0, y = 0, r = 0, a = 0, n = 0, s = 0, b = 0, m = 0;
	int num, i = 0;
	FILE *movie_log, *actor_log, *director_log;

	struct movie_list *temp_m=NULL;
	struct director_list *temp_d=NULL;
	struct actor_list *temp_a=NULL;

	movie_log = fopen("movie_log", "a+");
	actor_log = fopen("actor_log", "a+");
	director_log = fopen("director_log", "a+");

	mda = (char *)calloc(10, sizeof(char));
	option = (char *)calloc(10, sizeof(char));
	number = (char*)calloc(10, sizeof(char));


	scanf("%s %s %s", mda, option, number);

	getchar();

	num = atoi(number);

	for (int i = 0;*(mda + i) != '\0';i++) {
		if (*(mda + i) == 'm')
			m++;
		else if (*(mda + i) == 'a')
			a++;
		else if (*(mda + i) == 'd')
			d++;
	}
	if (m == 1) {
		fprintf(movie_log, "update:%d:", num);

		for (int i = 0;*(option + i) != '\0';i++) {
			if (*(option + i) == 't')
				t++;
			else if (*(option + i) == 'g')
				g++;
			else if (*(option + i) == 'd')
				d++;
			else if (*(option + i) == 'y')
				y++;
			else if (*(option + i) == 'r')
				r++;
			else if (*(option + i) == 'a')
				a++;
		}
		i = t + g + d + y + r + a;


		if (t > 0) {
			title = (char *)calloc(100, sizeof(char));
			printf("title > ");
			scanf("%[^\n]", title);
			getchar();
			fprintf(movie_log, "%s:", title);
		}
		else if (t == 0)
			fprintf(movie_log, "=:");

		if (g > 0) {
			genre = (char *)calloc(100, sizeof(char));
			printf("genre > ");
			scanf("%[^\n]", genre);
			getchar();
			fprintf(movie_log, "%s:", genre);
		}
		else if (g == 0)
			fprintf(movie_log, "=:");
		if (d > 0) {
			director = (char *)calloc(100, sizeof(char));
			printf("director > ");
			scanf("%[^\n]", director);
			getchar();
			fprintf(movie_log, "%s:", director);

		}
		else if (d == 0)
			fprintf(movie_log, "=:");
		if (y > 0) {
			year = (char *)calloc(100, sizeof(char));
			printf("year > ");
			scanf("%[^\n]", year);
			getchar();
			fprintf(movie_log, "%s:", year);

		}
		else if (y == 0)
			fprintf(movie_log, "=:");
		if (r > 0) {
			run = (char *)calloc(100, sizeof(char));
			printf("running time > ");
			scanf("%[^\n]", run);
			getchar();
			fprintf(movie_log, "%s:", run);

		}
		else if (r == 0)
			fprintf(movie_log, "=:");
		if (a > 0) {
			actor = (char *)calloc(1000, sizeof(char));
			printf("actor > ");
			scanf("%[^\n]", actor);
			getchar();
			fprintf(movie_log, "%s\n", actor);

		}
		else if (a == 0)
			fprintf(movie_log, "=\n");
		fclose(movie_log);

		log_to_list_m();	
	}
	else if (d == 1) {
		fprintf(director_log, "update:%d:", num);

		for (int i = 0;*(option + i) != '\0';i++) {
			if (*(option + i) == 'n')
				n++;
			else if (*(option + i) == 's')
				s++;
			else if (*(option + i) == 'b')
				b++;
			else if (*(option + i) == 'm')
				m++;
		}
		i = n + s + b + m;

		if (n > 0) {
			name = (char *)calloc(100, sizeof(char));
			printf("name > ");
			scanf("%[^\n]", name);
			getchar();
			fprintf(director_log, "%s:", name);
		}
		else if (n == 0)
			fprintf(director_log, "=:");

		if (s > 0) {
			sex = (char *)calloc(100, sizeof(char));
			printf("sex > ");
			scanf("%[^\n]", sex);
			getchar();
			fprintf(director_log, "%s", sex);
		}
		else if (s == 0)
			fprintf(director_log, "=:");

		if (b > 0) {
			birth = (char *)calloc(100, sizeof(char));
			printf("birth > ");
			scanf("%[^\n]", birth);
			getchar();
			fprintf(director_log, "%s", birth);
		}
		else if (b == 0)
			fprintf(director_log, "=:");

		if (m > 0) {
			movie = (char *)calloc(100, sizeof(char));
			printf("movie > ");
			scanf("%[^\n]", movie);
			getchar();
			fprintf(director_log, "%s\n", movie);
		}
		else if (m == 0)
			fprintf(director_log, "=\n");
		fclose(director_log);

		log_to_list_d();
	}
	else if (a == 1) {
		fprintf(actor_log, "update:%d:", num);

		for (int i = 0;*(option + i) != '\0';i++) {
			if (*(option + i) == 'n')
				n++;
			else if (*(option + i) == 's')
				s++;
			else if (*(option + i) == 'b')
				b++;
			else if (*(option + i) == 'm')
				m++;
		}
		i = n + s + b + m;
		if (n > 0) {
			name = (char *)calloc(100, sizeof(char));
			printf("name > ");
			scanf("%[^\n]", name);
			getchar();
			fprintf(actor_log, "%s:", name);
		}
		else if (n == 0)
			fprintf(actor_log, "=:");

		if (s > 0) {
			sex = (char *)calloc(100, sizeof(char));
			printf("sex > ");
			scanf("%[^\n]", sex);
			getchar();
			fprintf(actor_log, "%s:", sex);
		}
		else if (s == 0)
			fprintf(actor_log, "=:");

		if (b > 0) {
			birth = (char *)calloc(100, sizeof(char));
			printf("birth > ");
			scanf("%[^\n]", birth);
			getchar();
			fprintf(actor_log, "%s:", birth);
		}
		else if (b == 0)
			fprintf(actor_log, "=:");

		if (m > 0) {
			movie = (char *)calloc(100, sizeof(char));
			printf("movie > ");
			scanf("%[^\n]", movie);
			getchar();
			fprintf(actor_log, "%s\n", movie);
		}
		else if (m == 0)
			fprintf(actor_log, "=\n");
		
	fclose(actor_log);}
	//원래 동적메모리 전부 free하는 함수
	log_to_list_a();
	//movie_memory_make(&head_m, &temp_m);
	//actor_memory_make(&head_a,&temp_a);
	//director_memory_make(&head_d,&temp_d);
	//m_d_a_link(&head_m, &head_d, &head_a);

	return;

}


int main() {
	struct director_list *head_d = NULL;
	struct director_list *temp_d = NULL;
	struct movie_list *head_m = NULL;
	struct movie_list *temp_m = NULL;
	struct actor_list *head_a = NULL;
	struct actor_list *temp_a = NULL;
	struct a_title_to_title *tmp_a=NULL;
        struct d_title_to_title *tmp_d=NULL;
        struct movie_to_actor *tmp_ma=NULL;
        char *str,*mda,*reverse;
        int m=0,a=0,d=0,str_len=0,accord=0,accord_num=0,q_n=0;

	//movie_memory_make(&head_m, &temp_m);
	//director_memory_make(&head_d, &temp_d);
	//actor_memory_make(&head_a, &temp_a);

	//m_d_a_link(&head_m, &head_d, &head_a);

	update(head_m,head_d,head_a);
	
	return 0;
}
