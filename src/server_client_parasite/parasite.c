#include "parasite.h"

static struct parasite_ctl *ctx;
static struct infect_ctx *ictx;

int parasite_initialize(int pid)
{
	int ret = 1;

	/* Allocates a context - compel_infect controls the child */
	ctx = compel_prepare(pid);

	if (ctx) {
		ictx = compel_infect_ctx(ctx);
		if (!ictx){
			ret = 0;
			fprintf(stderr,"No infect context for prepared parasite\n");
		}
		else 
			ictx->log_fd = STDERR_FILENO;
	}
	else {
		ret = 0;
		fprintf(stderr,"parasite context couldn't be created\n");
	}

	return ret;
}
