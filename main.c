#include "main.h"

/**
 * single_handler - checks if Ctrl C is pressed
 * @sig_num: int
 */


void single_handler(int sig_num)
{
	if (sig_num == SIGINT)
	{
		_puts_("\n(KSHELL) & ");
	}
}

/**
* _EOF_ - handles the End of File
* @len: return value of getline function
* @buff: buffer
 */

void _EOF_(int len, char *buff)
{
	(void)buff;
	if (len == -1)
	{
		if (isatty(STDIN_FILENO))
		{
			_puts_("\n");
			free(buff);
		}
		exit(0);
	}
}
/**
  * _satty - verif if terminal
  */


void _satty(void)
{
	if (isatty(STDIN_FILENO))
		_puts_("(KSHELL) & ");
}
/**
 * main - Shell
 * Return: 0 on success
 */


int main(void)
{
	ssize_t len = 0;
	char *buff = NULL, *value, *pathname, **arv;
	size_t size = 0;
	list_path *head = '\0';
	void (*f)(char **);

	signal(SIGINT, single_handler);
	while (len != EOF)
	{
		_satty();
		len = getline(&buff, &size, stdin);
		_EOF_(len, buff);
		arv = splitstring(buff, " \n");
		if (!arv || !arv[0])
			execute(arv);
		else
		{
			value = _getenv("PATH");
			head = linkpath(value);
			pathname = _which(arv[0], head);
			f = checkbuild(arv);
			if (f)
			{
				free(buff);
				f(arv);
			}
			else if (!pathname)
				execute(arv);
			else if (pathname)
			{
				free(arv[0]);
				arv[0] = pathname;
				execute(arv);
			}
		}
	}
	free_list(head);
	freearv(arv);
	free(buff);
	return (0);
}
