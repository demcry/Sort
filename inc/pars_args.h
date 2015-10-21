#ifndef PARS_ARGS_H
#define PARS_ARGS_H

#define COND_ALPH_ORD 0x1
#define COND_IGN_CASE 0x2
#define COND_RAND 0x4
#define COND_HELP 0x8
#define COND_VER 0x10
#define COND_FILE 0x20
#define COND_ERR 0x8000

#define COND_DEFAULT COND_ALPH_ORD

void analyseTok(char *tok, int *cond, char **file);

#endif
