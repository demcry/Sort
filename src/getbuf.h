#ifndef GETBUF_H
#define GETBUF_H

void getBuf(FILE *stream, char ***buf, int *size, int *length);
void deleteBuf(char ***buf);

#endif
