#define _GNU_SOURCE
#include <sched.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	int cpu;
	cpu_set_t set;
	char *params[argc - 2];

	if (1 != sscanf(argv[1], "%d", &cpu)) {
		fprintf(stderr, "wrong cpu #\n");
		fprintf(stderr, "Usage:\ncpu_task 2 cmd [parms]\n");
		exit(EXIT_FAILURE);
	}

	CPU_ZERO(&set);
	CPU_SET(cpu, &set);
	fprintf(stderr, "bound program '%s' to cpu %d\n", argv[2], cpu);
	if (sched_setaffinity(getpid(), sizeof(set), &set)) {
		fprintf(stderr, "failed to bound cpu %d\n", cpu);
		exit(EXIT_FAILURE);
	}

	memcpy(params, argv + 2, sizeof(params));
	params[argc - 2] = NULL;

	return execvp(argv[2], params);
}
