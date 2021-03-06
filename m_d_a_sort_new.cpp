#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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
struct movie_log_s {
	int serial_num;
	char *str;
	struct movie_log_s *next;
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
void director_memory_make(struct director_list **head, struct director_list **temp) {
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
	return;
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
void m_d_a_link(struct movie_list **head_m, struct director_list **head_d, struct actor_list **head_a) {
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
	 //연결 끝

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
struct sort {
	char *str;
};
int compare(const void *m, const void *n) {
	return strcmp(((struct sort *)m)->str, ((struct sort *)n)->str);
}
int compare_i(const void *m, const void *n) {
	if (*(int *)m > *(int *)n)
		return 1;
	else if (*(int *)m > *(int *)n)
		return -1;
	else
		return 0;
}
int main() {
	struct director_list *head_d = NULL;
	struct director_list *temp_d = NULL;
	struct movie_list *head_m = NULL;
	struct movie_list *temp_m = NULL;
	struct actor_list *head_a = NULL;
	struct actor_list *temp_a = NULL;
	struct a_title_to_title *tmp_a = NULL;
	struct d_title_to_title *tmp_d = NULL;
	struct movie_to_actor *tmp_ma = NULL;
	char *mda, *option, *file_name, *p;
	char *title, *genre, *director, *year, *run, *actor, *name, *sex, *birth, *movie;
	int t = 0, g = 0, d = 0, y = 0, r = 0, a = 0, n = 0, s = 0, b = 0, m = 0, op = 0, file = 0;
	int num, i = 0, k = 0, overrlap;
	int *p_year, *p_time;
	struct sort *pointer = NULL;
	FILE *save_file;

	//log_to_list();
	movie_memory_make(&head_m, &temp_m);
	director_memory_make(&head_d, &temp_d);
	actor_memory_make(&head_a, &temp_a);

	m_d_a_link(&head_m, &head_d, &head_a);

	mda = (char *)calloc(3, sizeof(char)); //입력받는다치면 동적메모리 할당?!
	option = (char *)calloc(10, sizeof(char));//입력받는다치면 동적메모리 할당?!
	file_name = (char *)calloc(100, sizeof(char));//입력받는다치면 동적메모리 할당?!

pointer = (struct sort *)calloc(1000, sizeof(struct sort));


if (*(option) != '\0')
op = 1;
else
op = 0;

if (*(file_name) != '\0')
{
	file = 1;
	save_file = fopen(file_name, "a+");
}
else
file = 0;


for (int i = 0;*(mda + i) != '\0';i++) {
	if (*(mda + i) == 'm')
		m++;
	else if (*(mda + i) == 'a')
		a++;
	else if (*(mda + i) == 'd')
		d++;
}

if (m == 1) {

	if (op) {
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
		if (t == 1) {
			temp_m = head_m;

			while (1) {
				if (temp_m->next == NULL) {
					(pointer + k)->str = (char *)calloc(100, sizeof(char));
					(pointer + k)->str = temp_m->title->str;
					break;
				}
				(pointer + k)->str = (char *)calloc(100, sizeof(char));
				(pointer + k)->str = temp_m->title->str;
				temp_m = temp_m->next;
				k++;
			}
			temp_m = head_m;

			qsort(pointer, k + 1, sizeof(struct sort), compare);
			for (int a = 0;a < k + 1;a++) {
				while (1)
				{
					if (strcmp((pointer + a)->str, temp_m->title->str) == 0)
					{
						printf("num : %d, ", temp_m->serial_num);
						printf("%s, ", temp_m->title->str);
						printf("%s, ", temp_m->genre->str);
						printf("%s ,", temp_m->director->str);
						printf("%d, ", temp_m->year);
						printf("%d, ", temp_m->time);
						tmp_ma = temp_m->actor;
						while (1) {
							printf("%s, ", tmp_ma->str);
							if (tmp_ma->next == NULL) {
								printf("\n");
								break;
							}
							tmp_ma = tmp_ma->next;
						}

						if (file == 1) {
							fprintf(save_file, "num : %d, ", temp_m->serial_num);
							fprintf(save_file, "%s, ", temp_m->title->str);
							fprintf(save_file, "%s, ", temp_m->genre->str);
							fprintf(save_file, "%s ,", temp_m->director->str);
							fprintf(save_file, "%d, ", temp_m->year);
							fprintf(save_file, "%d, ", temp_m->time);
							tmp_ma = temp_m->actor;
							while (1) {
								fprintf(save_file, "%s, ", tmp_ma->str);
								if (tmp_ma->next == NULL) {
									fprintf(save_file, "\n");
									break;
								}
								tmp_ma = tmp_ma->next;
							}
						}
						free((pointer + a)->str);
						break;
					}
					if (temp_m->next == NULL)
						break;
					temp_m = temp_m->next;
				}
			}
		}
		else if (g == 1) {
			temp_m = head_m;

			while (1) {
				if (temp_m->next == NULL) {
					(pointer + k)->str = (char *)calloc(100, sizeof(char));
					(pointer + k)->str = temp_m->genre->str;
					break;
				}
				(pointer + k)->str = (char *)calloc(100, sizeof(char));
				(pointer + k)->str = temp_m->genre->str;
				temp_m = temp_m->next;
				k++;
			}
			qsort(pointer, k + 1, sizeof(struct sort), compare);

			for (int a = 0;a < k + 1;a++) {
				temp_m = head_m;
				while (1) {
					if (strcmp((pointer + a)->str, temp_m->genre->str) == 0)
					{
						printf("num : %d, ", temp_m->serial_num);
						printf("%s, ", temp_m->title->str);
						printf("%s, ", temp_m->genre->str);
						printf("%s ,", temp_m->director->str);
						printf("%d, ", temp_m->year);
						printf("%d, ", temp_m->time);
						tmp_ma = temp_m->actor;
						while (1) {
							printf("%s, ", tmp_ma->str);
							if (tmp_ma->next == NULL) {
								printf("\n");
								break;
							}
							tmp_ma = tmp_ma->next;
						}

						if (file == 1) {
							fprintf(save_file, "num : %d, ", temp_m->serial_num);
							fprintf(save_file, "%s, ", temp_m->title->str);
							fprintf(save_file, "%s, ", temp_m->genre->str);
							fprintf(save_file, "%s ,", temp_m->director->str);
							fprintf(save_file, "%d, ", temp_m->year);
							fprintf(save_file, "%d, ", temp_m->time);
							tmp_ma = temp_m->actor;
							while (1) {
								fprintf(save_file, "%s, ", tmp_ma->str);
								if (tmp_ma->next == NULL) {
									fprintf(save_file, "\n");
									break;
								}
								tmp_ma = tmp_ma->next;
							}
						}
						free((pointer + a)->str);
						break;
					}
					if (temp_m->next == NULL)
						break;
					temp_m = temp_m->next;
				}
			}
		}
		else if (d == 1) {
			temp_m = head_m;

			while (1) {
				if (temp_m->next == NULL) {
					(pointer + k)->str = (char *)calloc(100, sizeof(char));
					(pointer + k)->str = temp_m->director->str;
					break;
				}
				(pointer + k)->str = (char *)calloc(100, sizeof(char));
				(pointer + k)->str = temp_m->director->str;
				temp_m = temp_m->next;
				k++;
			}
			qsort(pointer, k
				+ 1, sizeof(struct sort), compare);

			for (int a = 0;a < k + 1;a++) {
				temp_m = head_m;
				while (1) {
					if (strcmp((pointer + a)->str, temp_m->director->str) == 0)
					{
						printf("num : %d, ", temp_m->serial_num);
						printf("%s, ", temp_m->title->str);
						printf("%s, ", temp_m->genre->str);
						printf("%s ,", temp_m->director->str);
						printf("%d, ", temp_m->year);
						printf("%d, ", temp_m->time);
						tmp_ma = temp_m->actor;
						while (1) {
							printf("%s, ", tmp_ma->str);
							if (tmp_ma->next == NULL) {
								printf("\n");
								break;
							}
							tmp_ma = tmp_ma->next;
						}

						if (file == 1) {
							fprintf(save_file, "num : %d, ", temp_m->serial_num);
							fprintf(save_file, "%s, ", temp_m->title->str);
							fprintf(save_file, "%s, ", temp_m->genre->str);
							fprintf(save_file, "%s ,", temp_m->director->str);
							fprintf(save_file, "%d, ", temp_m->year);
							fprintf(save_file, "%d, ", temp_m->time);
							tmp_ma = temp_m->actor;
							while (1) {
								fprintf(save_file, "%s, ", tmp_ma->str);
								if (tmp_ma->next == NULL) {
									fprintf(save_file, "\n");
									break;
								}
								tmp_ma = tmp_ma->next;
							}
						}
						free((pointer + a)->str);
						break;
					}
					if (temp_m->next == NULL)
						break;
					temp_m = temp_m->next;
				}
			}
		}
		else if (y == 1) {
			p_year = (int *)calloc(100, sizeof(int));
			temp_m = head_m;

			while (1) {
				if (temp_m->next == NULL) {
					*(p_year + k) = temp_m->year;
					break;
				}
				*(p_year + k) = temp_m->year;
				temp_m = temp_m->next;
				k++;
			}
			qsort(p_year, k + 1, sizeof(int), compare_i);

			for (int a = 0;a < k + 1;a++) {
				temp_m = head_m;
				while (1) {
					if (*(p_year + a) == temp_m->year)
					{
						printf("num : %d, ", temp_m->serial_num);
						printf("%s, ", temp_m->title->str);
						printf("%s, ", temp_m->genre->str);
						printf("%s ,", temp_m->director->str);
						printf("%d, ", temp_m->year);
						printf("%d, ", temp_m->time);
						tmp_ma = temp_m->actor;
						while (1) {
							printf("%s, ", tmp_ma->str);
							if (tmp_ma->next == NULL) {
								printf("\n");
								break;
							}
							tmp_ma = tmp_ma->next;
						}

						if (file == 1) {
							fprintf(save_file, "num : %d, ", temp_m->serial_num);
							fprintf(save_file, "%s, ", temp_m->title->str);
							fprintf(save_file, "%s, ", temp_m->genre->str);
							fprintf(save_file, "%s ,", temp_m->director->str);
							fprintf(save_file, "%d, ", temp_m->year);
							fprintf(save_file, "%d, ", temp_m->time);
							tmp_ma = temp_m->actor;
							while (1) {
								fprintf(save_file, "%s, ", tmp_ma->str);
								if (tmp_ma->next == NULL) {
									fprintf(save_file, "\n");
									break;
								}
								tmp_ma = tmp_ma->next;
							}
						}
						free((pointer + a)->str);
						break;
					}
					if (temp_m->next == NULL)
						break;
					temp_m = temp_m->next;
				}
			}
		}
		else if (r == 1) {
			p_time = (int *)calloc(100, sizeof(int));
			temp_m = head_m;

			while (1) {
				if (temp_m->next == NULL) {
					*(p_time + k) = temp_m->time;
					break;
				}
				*(p_time + k) = temp_m->time;
				temp_m = temp_m->next;
				k++;
			}
			qsort(p_time, k + 1, sizeof(int), compare_i);

			for (int a = 0;a < k + 1;a++) {
				temp_m = head_m;
				while (1) {
					if (*(p_time + a) == temp_m->time)
					{
						printf("num : %d, ", temp_m->serial_num);
						printf("%s, ", temp_m->title->str);
						printf("%s, ", temp_m->genre->str);
						printf("%s ,", temp_m->director->str);
						printf("%d, ", temp_m->year);
						printf("%d, ", temp_m->time);
						tmp_ma = temp_m->actor;
						while (1) {
							printf("%s, ", tmp_ma->str);
							if (tmp_ma->next == NULL) {
								printf("\n");
								break;
							}
							tmp_ma = tmp_ma->next;
						}

						if (file == 1) {
							fprintf(save_file, "num : %d, ", temp_m->serial_num);
							fprintf(save_file, "%s, ", temp_m->title->str);
							fprintf(save_file, "%s, ", temp_m->genre->str);
							fprintf(save_file, "%s ,", temp_m->director->str);
							fprintf(save_file, "%d, ", temp_m->year);
							fprintf(save_file, "%d, ", temp_m->time);
							tmp_ma = temp_m->actor;
							while (1) {
								fprintf(save_file, "%s, ", tmp_ma->str);
								if (tmp_ma->next == NULL) {
									fprintf(save_file, "\n");
									break;
								}
								tmp_ma = tmp_ma->next;
							}
						}
						free((pointer + a)->str);
						break;
					}
					if (temp_m->next == NULL)
						break;
					temp_m = temp_m->next;
				}
			}
		}
		else if (a == 1) {
			temp_m = head_m;

			while (1) {
				if (temp_m->next == NULL) {
					(pointer + k)->str = (char *)calloc(100, sizeof(char));
					(pointer + k)->str = temp_m->actor->str;
					break;
				}
				(pointer + k)->str = (char *)calloc(100, sizeof(char));
				(pointer + k)->str = temp_m->actor->str;
				temp_m = temp_m->next;
				k++;
			}
			qsort(pointer, k
				+ 1, sizeof(struct sort), compare);

			for (int a = 0;a < k + 1;a++) {
				temp_m = head_m;
				while (1) {
					if (strcmp((pointer + a)->str, temp_m->actor->str) == 0)
					{
						printf("num : %d, ", temp_m->serial_num);
						printf("%s, ", temp_m->title->str);
						printf("%s, ", temp_m->genre->str);
						printf("%s ,", temp_m->director->str);
						printf("%d, ", temp_m->year);
						printf("%d, ", temp_m->time);
						tmp_ma = temp_m->actor;
						while (1) {
							printf("%s, ", tmp_ma->str);
							if (tmp_ma->next == NULL) {
								printf("\n");
								break;
							}
							tmp_ma = tmp_ma->next;
						}

						if (file == 1) {
							fprintf(save_file, "num : %d, ", temp_m->serial_num);
							fprintf(save_file, "%s, ", temp_m->title->str);
							fprintf(save_file, "%s, ", temp_m->genre->str);
							fprintf(save_file, "%s ,", temp_m->director->str);
							fprintf(save_file, "%d, ", temp_m->year);
							fprintf(save_file, "%d, ", temp_m->time);
							tmp_ma = temp_m->actor;
							while (1) {
								fprintf(save_file, "%s, ", tmp_ma->str);
								if (tmp_ma->next == NULL) {
									fprintf(save_file, "\n");
									break;
								}
								tmp_ma = tmp_ma->next;
							}
						}
						free((pointer + a)->str);
						break;
					}
					if (temp_m->next == NULL)
						break;
					temp_m = temp_m->next;
				}
			}
		}
	}
	else if (op == 0) {
		temp_m = head_m;

		while (1) {
			if (temp_m->next == NULL) {
				(pointer + k)->str = (char *)calloc(100, sizeof(char));
				(pointer + k)->str = temp_m->title->str;
				break;
			}
			(pointer + k)->str = (char *)calloc(100, sizeof(char));
			(pointer + k)->str = temp_m->title->str;
			temp_m = temp_m->next;
			k++;
		}
		temp_m = head_m;

		qsort(pointer, k + 1, sizeof(struct sort), compare);
		for (int a = 0;a < k + 1;a++) {
			while (1)
			{
				if (strcmp((pointer + a)->str, temp_m->title->str) == 0)
				{
					printf("num : %d, ", temp_m->serial_num);
					printf("%s, ", temp_m->title->str);
					printf("%s, ", temp_m->genre->str);
					printf("%s ,", temp_m->director->str);
					printf("%d, ", temp_m->year);
					printf("%d, ", temp_m->time);
					tmp_ma = temp_m->actor;
					while (1) {
						printf("%s, ", tmp_ma->str);
						if (tmp_ma->next == NULL) {
							printf("\n");
							break;
						}
						tmp_ma = tmp_ma->next;
					}

					if (file == 1) {
						fprintf(save_file, "num : %d, ", temp_m->serial_num);
						fprintf(save_file, "%s, ", temp_m->title->str);
						fprintf(save_file, "%s, ", temp_m->genre->str);
						fprintf(save_file, "%s ,", temp_m->director->str);
						fprintf(save_file, "%d, ", temp_m->year);
						fprintf(save_file, "%d, ", temp_m->time);
						tmp_ma = temp_m->actor;
						while (1) {
							fprintf(save_file, "%s, ", tmp_ma->str);
							if (tmp_ma->next == NULL) {
								fprintf(save_file, "\n");
								break;
							}
							tmp_ma = tmp_ma->next;
						}
					}
					free((pointer + a)->str);
					break;
				}
				if (temp_m->next == NULL)
					break;
				temp_m = temp_m->next;
			}
		}

	}


}
else if (a == 1) {
	if (op) {
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
		if (n == 1) {
			temp_a = head_a;

			while (1) {
				if (temp_a->next == NULL) {
					(pointer + k)->str = (char *)calloc(100, sizeof(char));
					(pointer + k)->str = temp_a->name->str;
					break;
				}
				(pointer + k)->str = (char *)calloc(100, sizeof(char));
				(pointer + k)->str = temp_a->name->str;
				temp_a = temp_a->next;
				k++;
			}
			qsort(pointer, k + 1, sizeof(struct sort), compare);

			for (int a = 0;a < k + 1;a++) {
				temp_a = head_a;
				while (1) {
					if (strcmp((pointer + a)->str, temp_a->name->str) == 0)
					{
						printf("num : %d, ", temp_a->serial_num);
						printf("%s, ", temp_a->name->str);
						printf("%s, ", temp_a->sex->str);
						printf("%s, ", temp_a->birth->str);
						tmp_a = temp_a->best_movies;
						while (1) {
							printf("%s, ", tmp_a->str);
							if (tmp_a->next == NULL) {
								printf("\n");
								break;
							}
							tmp_a = tmp_a->next;
						}

						if (file == 1) {
							fprintf(save_file, "num : %d, ", temp_a->serial_num);
							fprintf(save_file, "%s, ", temp_a->name->str);
							fprintf(save_file, "%s, ", temp_a->name->str);
							fprintf(save_file, "%s, ", temp_a->birth->str);
							tmp_a = temp_a->best_movies;
							while (1) {
								fprintf(save_file, "%s, ", tmp_a->str);
								if (tmp_a->next == NULL) {
									fprintf(save_file, "\n");
									break;
								}
								tmp_a = tmp_a->next;
							}
						}
						free((pointer + a)->str);
						break;
					}
					if (temp_a->next == NULL)
						break;
					temp_a = temp_a->next;
				}
			}
		}
		else if (s == 1) {
			temp_a = head_a;

			while (1) {
				if (temp_a->next == NULL) {
					(pointer + k)->str = (char *)calloc(100, sizeof(char));
					(pointer + k)->str = temp_a->sex->str;
					break;
				}
				(pointer + k)->str = (char *)calloc(100, sizeof(char));
				(pointer + k)->str = temp_a->sex->str;
				temp_a = temp_a->next;
				k++;
			}
			qsort(pointer, k + 1, sizeof(struct sort), compare);

			for (int a = 0;a < k + 1;a++) {
				temp_a = head_a;
				while (1) {
					if (strcmp((pointer + a)->str, temp_a->sex->str) == 0)
					{
						printf("num : %d, ", temp_a->serial_num);
						printf("%s, ", temp_a->name->str);
						printf("%s, ", temp_a->sex->str);
						printf("%s, ", temp_a->birth->str);
						tmp_a = temp_a->best_movies;
						while (1) {
							printf("%s, ", tmp_a->str);
							if (tmp_a->next == NULL) {
								printf("\n");
								break;
							}
							tmp_a = tmp_a->next;
						}

						if (file == 1) {
							fprintf(save_file, "num : %d, ", temp_a->serial_num);
							fprintf(save_file, "%s, ", temp_a->name->str);
							fprintf(save_file, "%s, ", temp_a->sex->str);
							fprintf(save_file, "%s, ", temp_a->birth->str);
							tmp_a = temp_a->best_movies;
							while (1) {
								fprintf(save_file, "%s, ", tmp_a->str);
								if (tmp_a->next == NULL) {
									fprintf(save_file, "\n");
									break;
								}
								tmp_a = tmp_a->next;
							}
						}
						free((pointer + a)->str);
						break;

					}
					if (temp_a->next == NULL)
						break;
					temp_a = temp_a->next;
				}
			}
		}
		else if (b == 1) {
			temp_a = head_a;

			while (1) {
				if (temp_a->next == NULL) {
					(pointer + k)->str = (char *)calloc(100, sizeof(char));
					(pointer + k)->str = temp_a->birth->str;
					break;
				}
				(pointer + k)->str = (char *)calloc(100, sizeof(char));
				(pointer + k)->str = temp_a->birth->str;
				temp_a = temp_a->next;
				k++;
			}
			qsort(pointer, k + 1, sizeof(struct sort), compare);

			for (int a = 0;a < k + 1;a++) {
				temp_a = head_a;
				while (1) {
					if (strcmp((pointer + a)->str, temp_a->birth->str) == 0)
					{
						printf("num : %d, ", temp_a->serial_num);
						printf("%s, ", temp_a->name->str);
						printf("%s, ", temp_a->sex->str);
						printf("%s, ", temp_a->birth->str);
						tmp_a = temp_a->best_movies;
						while (1) {
							printf("%s, ", tmp_a->str);
							if (tmp_a->next == NULL) {
								printf("\n");
								break;
							}
							tmp_a = tmp_a->next;
						}

						if (file == 1) {
							fprintf(save_file, "num : %d, ", temp_a->serial_num);
							fprintf(save_file, "%s, ", temp_a->name->str);
							fprintf(save_file, "%s, ", temp_a->sex->str);
							fprintf(save_file, "%s, ", temp_a->birth->str);
							tmp_a = temp_a->best_movies;
							while (1) {
								fprintf(save_file, "%s, ", tmp_a->str);
								if (tmp_a->next == NULL) {
									fprintf(save_file, "\n");
									break;
								}
								tmp_a = tmp_a->next;
							}
						}
						free((pointer + a)->str);
						break;
					}
					if (temp_a->next == NULL)
						break;
					temp_a = temp_a->next;
				}
			}
		}
		else if (m == 1) {
			temp_a = head_a;

			while (1) {
				if (temp_a->next == NULL) {
					(pointer + k)->str = (char *)calloc(100, sizeof(char));
					(pointer + k)->str = temp_a->best_movies->str;
					break;
				}
				(pointer + k)->str = (char *)calloc(100, sizeof(char));
				(pointer + k)->str = temp_a->best_movies->str;
				temp_a = temp_a->next;
				k++;
			}
			qsort(pointer, k + 1, sizeof(struct sort), compare);

			for (int a = 0;a < k + 1;a++) {
				temp_a = head_a;
				while (1) {
					if (strcmp((pointer + a)->str, temp_a->best_movies->str) == 0)
					{
						printf("num : %d, ", temp_a->serial_num);
						printf("%s, ", temp_a->name->str);
						printf("%s, ", temp_a->sex->str);
						printf("%s, ", temp_a->birth->str);
						tmp_a = temp_a->best_movies;
						while (1) {
							printf("%s, ", tmp_a->str);
							if (tmp_a->next == NULL) {
								printf("\n");
								break;
							}
							tmp_a = tmp_a->next;
						}

						if (file == 1) {
							fprintf(save_file, "num : %d, ", temp_a->serial_num);
							fprintf(save_file, "%s, ", temp_a->name->str);
							fprintf(save_file, "%s, ", temp_a->sex->str);
							fprintf(save_file, "%s, ", temp_a->birth->str);
							tmp_a = temp_a->best_movies;
							while (1) {
								fprintf(save_file, "%s, ", tmp_a->str);
								if (tmp_a->next == NULL) {
									fprintf(save_file, "\n");
									break;
								}
								tmp_a = tmp_a->next;
							}
						}
						free((pointer + a)->str);
						break;
					}
					if (temp_a->next == NULL)
						break;
					temp_a = temp_a->next;
				}
			}
		}
	}
}
else if (d == 1) {
	if (op) {
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
		if (n == 1) {
			temp_d = head_d;

			while (1) {
				if (temp_d->next == NULL) {
					(pointer + k)->str = (char *)calloc(100, sizeof(char));
					(pointer + k)->str = temp_d->name->str;
					break;
				}
				(pointer + k)->str = (char *)calloc(100, sizeof(char));
				(pointer + k)->str = temp_d->name->str;
				temp_d = temp_d->next;
				k++;
			}
			qsort(pointer, k + 1, sizeof(struct sort), compare);

			for (int a = 0;a < k + 1;a++) {
				printf("%s", (pointer + a)->str);
				temp_d = head_d;
				while (1) {
					printf("%s", temp_d->name->str);
					if (strcmp((pointer + a)->str, temp_d->name->str) == 0)
					{
						printf("num : %d, ", temp_d->serial_num);
						printf("%s, ", temp_d->name->str);
						printf("%s, ", temp_d->sex->str);
						printf("%s, ", temp_d->birth->str);
						tmp_d = temp_d->best_movies;
						while (1) {
							printf("%s, ", tmp_d->str);
							if (tmp_d->next == NULL) {
								printf("\n");
								break;
							}
							tmp_d = tmp_d->next;
						}

						if (file == 1) {
							fprintf(save_file, "num : %d, ", temp_d->serial_num);
							fprintf(save_file, "%s, ", temp_d->name->str);
							fprintf(save_file, "%s, ", temp_d->sex->str);
							fprintf(save_file, "%s, ", temp_d->birth->str);
							tmp_d = temp_d->best_movies;
							while (1) {
								fprintf(save_file, "%s, ", tmp_d->str);
								if (tmp_d->next == NULL) {
									fprintf(save_file, "\n");
									break;
								}
								tmp_d = tmp_d->next;
							}
						}
						free((pointer + a)->str);
						break;
					}
					if (temp_d->next == NULL)
						break;
					temp_d = temp_d->next;
				}
			}
		}
		else if (s == 1) {
			temp_d = head_d;

			while (1) {
				if (temp_d->next == NULL) {
					(pointer + k)->str = (char *)calloc(100, sizeof(char));
					(pointer + k)->str = temp_d->sex->str;
					break;
				}
				(pointer + k)->str = (char *)calloc(100, sizeof(char));
				(pointer + k)->str = temp_d->sex->str;
				temp_d = temp_d->next;
				k++;
			}
			qsort(pointer, k + 1, sizeof(struct sort), compare);

			for (int a = 0;a < k + 1;a++) {
				temp_d = head_d;
				while (1) {
					if (strcmp((pointer + a)->str, temp_d->sex->str) == 0)
					{
						printf("num : %d, ", temp_d->serial_num);
						printf("%s, ", temp_d->name->str);
						printf("%s, ", temp_d->sex->str);
						printf("%s, ", temp_d->birth->str);
						tmp_d = temp_d->best_movies;
						while (1) {
							printf("%s, ", tmp_d->str);
							if (tmp_d->next == NULL) {
								printf("\n");
								break;
							}
							tmp_d = tmp_d->next;
						}

						if (file == 1) {
							fprintf(save_file, "num : %d, ", temp_d->serial_num);
							fprintf(save_file, "%s, ", temp_d->name->str);
							fprintf(save_file, "%s, ", temp_d->sex->str);
							fprintf(save_file, "%s, ", temp_d->birth->str);
							tmp_d = temp_d->best_movies;
							while (1) {
								fprintf(save_file, "%s, ", tmp_d->str);
								if (tmp_d->next == NULL) {
									fprintf(save_file, "\n");
									break;
								}
								tmp_d = tmp_d->next;
							}
						}
						free((pointer + a)->str);
						break;
					}
					if (temp_d->next == NULL)
						break;
					temp_d = temp_d->next;
				}
			}
		}
		else if (b == 1) {
			temp_d = head_d;

			while (1) {
				if (temp_d->next == NULL) {
					(pointer + k)->str = (char *)calloc(100, sizeof(char));
					(pointer + k)->str = temp_d->birth->str;
					break;
				}
				(pointer + k)->str = (char *)calloc(100, sizeof(char));
				(pointer + k)->str = temp_d->birth->str;
				temp_d = temp_d->next;
				k++;
			}
			qsort(pointer, k + 1, sizeof(struct sort), compare);

			for (int a = 0;a < k + 1;a++) {
				temp_d = head_d;
				while (1) {
					if (strcmp((pointer + a)->str, temp_d->birth->str) == 0)
					{
						printf("num : %d, ", temp_d->serial_num);
						printf("%s, ", temp_d->name->str);
						printf("%s, ", temp_d->sex->str);
						printf("%s, ", temp_d->birth->str);
						tmp_d = temp_d->best_movies;
						while (1) {
							printf("%s, ", tmp_d->str);
							if (tmp_d->next == NULL) {
								printf("\n");
								break;
							}
							tmp_d = tmp_d->next;
						}

						if (file == 1) {
							fprintf(save_file, "num : %d, ", temp_d->serial_num);
							fprintf(save_file, "%s, ", temp_d->name->str);
							fprintf(save_file, "%s, ", temp_d->sex->str);
							fprintf(save_file, "%s, ", temp_d->birth->str);
							tmp_d = temp_d->best_movies;
							while (1) {
								fprintf(save_file, "%s, ", tmp_d->str);
								if (tmp_d->next == NULL) {
									fprintf(save_file, "\n");
									break;
								}
								tmp_d = tmp_d->next;
							}
						}
						free((pointer + a)->str);
						break;
					}
					if (temp_d->next == NULL)
						break;
					temp_d = temp_d->next;
				}
			}
		}
		else if (m == 1) {
			temp_d = head_d;

			while (1) {
				if (temp_d->next == NULL) {
					(pointer + k)->str = (char *)calloc(100, sizeof(char));
					(pointer + k)->str = temp_d->best_movies->str;
					break;
				}
				(pointer + k)->str = (char *)calloc(100, sizeof(char));
				(pointer + k)->str = temp_d->best_movies->str;
				temp_d = temp_d->next;
				k++;
			}
			qsort(pointer, k + 1, sizeof(struct sort), compare);

			for (int a = 0;a < k + 1;a++) {
				temp_d = head_d;
				while (1) {
					if (strcmp((pointer + a)->str, temp_d->best_movies->str) == 0)
					{
						printf("num : %d, ", temp_d->serial_num);
						printf("%s, ", temp_d->name->str);
						printf("%s, ", temp_d->sex->str);
						printf("%s, ", temp_d->birth->str);
						tmp_d = temp_d->best_movies;
						while (1) {
							printf("%s, ", tmp_d->str);
							if (tmp_d->next == NULL) {
								printf("\n");
								break;
							}
							tmp_d = tmp_d->next;
						}

						if (file == 1) {
							fprintf(save_file, "num : %d, ", temp_d->serial_num);
							fprintf(save_file, "%s, ", temp_d->name->str);
							fprintf(save_file, "%s, ", temp_d->sex->str);
							fprintf(save_file, "%s, ", temp_d->birth->str);
							tmp_d = temp_d->best_movies;
							while (1) {
								fprintf(save_file, "%s, ", tmp_d->str);
								if (tmp_d->next == NULL) {
									fprintf(save_file, "\n");
									break;
								}
								tmp_d = tmp_d->next;
							}
						}
						free((pointer + a)->str);
						break;
					}
					if (temp_d->next == NULL)
						break;
					temp_d = temp_d->next;
				}
			}
		}
	}
}
return 0;
}


