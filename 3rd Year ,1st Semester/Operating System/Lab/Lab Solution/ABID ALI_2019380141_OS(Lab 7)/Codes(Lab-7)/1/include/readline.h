#ifndef _READLINE_H_
#define _READLINE_H_

#include <stdio.h>
#include <string.h>
/**
 * This function implements a safer way to read strings from a C stream
 * (that is, safer than scanf and gets).
 *
 * The function causes characters to be read one at a time and placed into
 * an input buffer that is automatically enlarged to fit the entire string.
 * The returned value is a pointer to a dynamically allocated area of
 * memory. Note that the caller of this function becomes responsible for
 * disposing of the memory allocated for the string read in.
 *
 * @parm stream Pointer to an open C stream (such as stdin)
 * @return A pointer to the line read from source on success or NULL on failure.
 */
extern char*
readline(FILE* stream);

#endif /* _READLINE_H_ */
