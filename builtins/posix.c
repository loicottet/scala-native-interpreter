#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <math.h>
#include <errno.h>

#include "builtins.h"
extern char* data;
void *scalanative_alloc(int64_t, int64_t);

extern char **environ;
sn_ptr_t *new_environ;

// This file contains functions that wrap posix
// built-in macros. We need this because Scala Native
// can not expand C macros, and that's the easiest way to
// get the values out of those in a portable manner.

int scalanative_eintr() { return EINTR; }

void* scalanative_environ() {
	//printf("in environ\n");

	if (!new_environ) {
		int count = 0;
		for (char **env = environ; *env; ++env) {
			count += 1;
		}
		//printf("%d lines\n", count);

		new_environ = scalanative_alloc(0, (count + 1) * 8);

		int i = 0;
		for (char **env = environ; *env; ++env, ++i) {
			new_environ[i] = *env - data;
		}
		new_environ[count] = 0;
		//printf("new environ%p\n", new_environ);
	}

	return new_environ;
}
