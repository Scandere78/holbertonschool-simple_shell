#include <unistd.h>
#include <termios.h>

/**
 * This function determines whether the specified file descriptor
 * is associated with an interactive terminal.
 *
 * @param fd The file descriptor to check.
 * @return 1 if the file descriptor is an interactive terminal, 0 otherwise.
 */
int isatty(int fd)
{
	struct termios term;

	if (tcgetattr(fd, &term) < 0)
		return (0);

	return (1);
}
