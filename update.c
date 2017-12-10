void update() {
	char *mda, *option, *number;
	char *title, *genre, *director, *year, *run, *actor, *name, *sex, *birth, *movie;
	int t = 0, g = 0, d = 0, y = 0, r = 0, a = 0, n = 0, s = 0, b = 0, m = 0;
	int num, i = 0;
	FILE *movie_log, *actor_log, *director_log;

	movie_log = fopen("movie_log", "a+");
	actor_log = fopen("actor_log", "a+");
	director_log = fopen("dirctor_log", "a+");

	mda = (char *)calloc(10, sizeof(char));
	option = (char *)calloc(10, sizeof(char));
	number = (char*)calloc(10, sizeof(char));


	scanf("%s %s %s", mda, option, number);

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
			scanf("%s", title);
			fprintf(movie_log, "%s:", title);
		}
		else if (t == 0)
			fprintf(movie_log, "=:");

		if (g > 0) {
			genre = (char *)calloc(100, sizeof(char));
			printf("genre > ");
			scanf("%s", genre);
			fprintf(movie_log, "%s:", genre);
		}
		else if (g == 0)
			fprintf(movie_log, "=:");
		if (d > 0) {
			director = (char *)calloc(100, sizeof(char));
			printf("director > ");
			scanf("%s", director);
			fprintf(movie_log, "%s:", director);

		}
		else if (d == 0)
			fprintf(movie_log, "=:");
		if (y > 0) {
			year = (char *)calloc(100, sizeof(char));
			printf("year > ");
			scanf("%s", year);
			fprintf(movie_log, "%s:", year);

		}
		else if (y == 0)
			fprintf(movie_log, "=:");
		if (r > 0) {
			run = (char *)calloc(100, sizeof(char));
			printf("running time > ");
			scanf("%s", run);
			fprintf(movie_log, "%s:", run);

		}
		else if (r == 0)
			fprintf(movie_log, "=:");
		if (a > 0) {
			actor = (char *)calloc(1000, sizeof(char));
			printf("actor > ");
			scanf("%s", actor);
			fprintf(movie_log, "%s\n", actor);

		}
		else if (a == 0)
			fprintf(movie_log, "=\n");
	}
	else if (d == 1) {
		fprintf(director_log, "update:%d", num);

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
			scanf("%s", name);
			fprintf(director_log, "%s", name);
		}
		else if (n == 0)
			fprintf(director_log, " = :");

		if (s > 0) {
			sex = (char *)calloc(100, sizeof(char));
			printf("sex > ");
			scanf("%s", sex);
			fprintf(director_log, "%s", sex);
		}
		else if (s == 0)
			fprintf(director_log, " = :");

		if (b > 0) {
			birth = (char *)calloc(100, sizeof(char));
			printf("birth > ");
			scanf("%s", birth);
			fprintf(director_log, "%s", birth);
		}
		else if (b == 0)
			fprintf(director_log, " = :");

		if (m > 0) {
			movie = (char *)calloc(100, sizeof(char));
			printf("movie > ");
			scanf("%s", movie);
			fprintf(director_log, "%s\n", movie);
		}
		else if (m == 0)
			fprintf(director_log, " = :\n");
	}
	else if (a == 1) {
		fprintf(actor_log, "update:%d", num);

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
			scanf("%s", name);
			fprintf(actor_log, "%s", name);
		}
		else if (n == 0)
			fprintf(actor_log, " = :");

		if (s > 0) {
			sex = (char *)calloc(100, sizeof(char));
			printf("sex > ");
			scanf("%s", sex);
			fprintf(actor_log, "%s", sex);
		}
		else if (s == 0)
			fprintf(actor_log, " = :");

		if (b > 0) {
			birth = (char *)calloc(100, sizeof(char));
			printf("birth > ");
			scanf("%s", birth);
			fprintf(actor_log, "%s", birth);
		}
		else if (b == 0)
			fprintf(actor_log, " = :");

		if (m > 0) {
			movie = (char *)calloc(100, sizeof(char));
			printf("movie > ");
			scanf("%s", movie);
			fprintf(actor_log, "%s\n", movie);
		}
		else if (m == 0)
			fprintf(actor_log, " = :\n");
	}

	fclose(movie_log);
	fclose(director_log);
	fclose(actor_log);

	//원래 동적메모리 전부 free하는 함수
	//log_to_list();
	//movie_memory_make(&head_m, &temp_m);
	//actor_memory_make(&head_a.&temp_a);
	//director_memory_make(&head_d,&temp_d);
	//m_d_a_link(&head_m, &head_d, &head_a);

	return;

}
