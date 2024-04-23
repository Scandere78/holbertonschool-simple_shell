#ifndef SHELL_H
#define SHELL_H







char *get_line(void);
char *get_line(void);
char **split_line(char *line);
void execute_command(char **args);
void execute_command(char **args, char **envp);
int main(void);
#endif
