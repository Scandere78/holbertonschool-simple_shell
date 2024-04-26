# Project Simple shell

Introduction:
un shell est un interpreteur de ligne de commande,c'est programme informatique qui fournit une interface utilisateur pour acceder aux services du systeme d'exploitation. selon le type d'interface qu'ils utilisent,les shells peuvent etre de differents types,dans ce cas,un programma shell du type sh (Bourne shell) sera developpe. les utilisateurs interagissent generalement avec un shell a l'aide d'un emulateur de terminal utilise pour saisir des donnees et afficher ou imprimer des donnees a partir d'un ordinateur ou d'un systeme informatique.

Environnement
Suite CRMSystÃ¨me d'exploitation : Ubuntu 20.04 LTS

Terminal

C Langage de programmation de bas niveauLangage : C Compilateur : gcc 9.3.0

Suite CRMEditeur : VIM 8.1.2269

systÃ¨me de contrÃ´le de version distribuÃ© gitVersion de contrÃ´le : Git

GitHub

Directives de style : style Betty

Exigences gÃ©nÃ©rales
Ã‰diteurs autorisÃ©s : vi, vim, emacs
Tous vos fichiers seront compilÃ©s surUbuntu 14.04 LTS
Vos programmes et fonctions C seront compilÃ©s en gcc 4.8.4utilisant les drapeaux -Wall -Werror -Wextraet-pedantic
Votre code doit utiliser le style Betty. Il sera vÃ©rifiÃ© en utilisant betty-style.pl et betty-doc.pl
Pas plus de 5 fonctions par fichier
Tous vos fichiers d'en-tÃªte doivent Ãªtre protÃ©gÃ©s
Ce shell ne devrait avoir aucune fuite de mÃ©moire
Sauf indication contraire, votre programme doit avoir exactement la mÃªme sortie que sh( /bin/sh) ainsi que exactement la mÃªme sortie d'erreur.

Fonctions autorisÃ©es utilisÃ©es
execve(homme 2 exÃ©cutif)
exit(sortie homme 3)
_exit(homme 2 _sortie)
fork(homme 2 fourchette)
free(homme 3 libre)
getline(homme 3 getline)
isatty(homme 3 isatty)
malloc(homme 3 malloc)
perror(homme 3 erreur)
signal(signal de l'homme 2)
stat(__ xstat) (statistique de l'homme 2)
strtok(homme 3 temps)
wait(homme 2 attends)
write(homme 2 Ã©crit)

Documentation
Installation

Clonez ce dÃ©pÃ´t :git clone "https://github.com/Scandere78/holbertonschool-simple_shell"
AccÃ©dez aux rÃ©pertoires du rÃ©fÃ©rentiel :cd simple_shell
Compiler:gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
ExÃ©cutez le shell en mode interactif :./hsh
Ou exÃ©cutez le shell en mode non interactif : exempleecho "Hello world!" | ./hsh

Essai
Compilez d'abord puis exÃ©cutez le fichier exÃ©cutable sur votre terminal. Pour la compilation, voir la section Installation .

$ ./hsh
$
$ ls -l
-rw-r--r-- 1 root root  238 Dec  25 17:43 AUTHORS
-rwxr-xr-x 1 root root  393 Dec  25 17:43 README.md
-rw-r--r-- 1 root root 2263 Dec  25 17:43 execute_command.c
-rw-r--r-- 1 root root  263 Dec  25 17:44 get_line.c
-rw-r--r-- 1 root root  341 Dec  25 17:44 get_path.c
-rw-r--r-- 1 root root  580 Dec  25 17:44 hsh
-rw-r--r-- 1 root root 1160 Dec  25 17:44 main.c
-rw-r--r-- 1 root root 1475 Dec  25 17:45 man_1_simple_shell
-rw-r--r-- 1 root root  695 Dec  25 17:45 shell.h
-rw-r--r-- 1 root root 1066 Dec  25 17:45 split_line_c

Files
File                                Description
AUTHORS                      Contributors in this repository
README.md                  	Information about our repository
hsh_execute                 	Execute builtins and commands
hsh_get_path.c                     	Get variable PATH
hsh_getenv.c               	Prints enviroment to stndard output
hsh_getline_command.c               	Gets input
hsh_shell.c	Main                    arguments functions
man_1_simple_shell          	Manual page our of Simple Shell
shell.h                     	Prototypes functions and headers
![img](data:image/svg+xml;base64,PHN2ZyBmaWxsPSIjZTk1NDIwIiByb2xlPSJpbWciIHZpZXdCb3g9IjAgMCAyNCAyNCIgeG1sbnM9Imh0dHA6Ly93d3cudzMub3JnLzIwMDAvc3ZnIj48dGl0bGU+VWJ1bnR1PC90aXRsZT48cGF0aCBkPSJNMTcuNjEuNDU1YTMuNDEgMy40MSAwIDAgMC0zLjQxIDMuNDEgMy40MSAzLjQxIDAgMCAwIDMuNDEgMy40MSAzLjQxIDMuNDEgMCAwIDAgMy40MS0zLjQxIDMuNDEgMy40MSAwIDAgMC0zLjQxLTMuNDF6TTEyLjkyLjhDOC45MjMuNzc3IDUuMTM3IDIuOTQxIDMuMTQ4IDYuNDUxYTQuNSA0LjUgMCAwIDEgLjI2LS4wMDcgNC45MiA0LjkyIDAgMCAxIDIuNTg1LjczN0E4LjMxNiA4LjMxNiAwIDAgMSAxMi42ODggMy42IDQuOTQ0IDQuOTQ0IDAgMCAxIDEzLjcyMy44MzQgMTEuMDA4IDExLjAwOCAwIDAgMCAxMi45Mi44em05LjIyNiA0Ljk5NGE0LjkxNSA0LjkxNSAwIDAgMS0xLjkxOCAyLjI0NiA4LjM2IDguMzYgMCAwIDEtLjI3MyA4LjMwMyA0Ljg5IDQuODkgMCAwIDEgMS42MzIgMi41NCAxMS4xNTYgMTEuMTU2IDAgMCAwIC41NTktMTMuMDg5ek0zLjQxIDcuOTMyQTMuNDEgMy40MSAwIDAgMCAwIDExLjM0MmEzLjQxIDMuNDEgMCAwIDAgMy40MSAzLjQwOSAzLjQxIDMuNDEgMCAwIDAgMy40MS0zLjQxIDMuNDEgMy40MSAwIDAgMC0zLjQxLTMuNDF6bTIuMDI3IDcuODY2YTQuOTA4IDQuOTA4IDAgMCAxLTIuOTE1LjM1OCAxMS4xIDExLjEgMCAwIDAgNy45OTEgNi42OTggMTEuMjM0IDExLjIzNCAwIDAgMCAyLjQyMi4yNDkgNC44NzkgNC44NzkgMCAwIDEtLjk5OS0yLjg1IDguNDg0IDguNDg0IDAgMCAxLS44MzYtLjEzNiA4LjMwNCA4LjMwNCAwIDAgMS01LjY2My00LjMyem0xMS40MDUuOTI4YTMuNDEgMy40MSAwIDAgMC0zLjQxIDMuNDEgMy40MSAzLjQxIDAgMCAwIDMuNDEgMy40MSAzLjQxIDMuNDEgMCAwIDAgMy40MS0zLjQxIDMuNDEgMy40MSAwIDAgMC0zLjQxLTMuNDF6Ii8+PC9zdmc+)


## Environnement

Systeme d'exploitation: Ubuntu 20.04 LTS
Editeur: VI
Language: C compilateur gcc
Directives de style: style Betty

## Exigences gÃ©nÃ©rales
* Editeurs autorises: VI, VIM , emacs
* tous voc fichiers sera compiles sur Ubuntu 14.04 LTS
* vos programmes et fonctions C seront compiles en gcc 4.8.4 utilisant les drapeaux -wall -werror -wextra et -pedantic
* votre code doit utiliser le style betty. il sera verifie en utilisant betty-style.pl et betty-doc.pl
* pas plus de cinq fonctions par fichier 
* tous vos fichiers d'en tete doivent etre proteges
* ce shell ne devrait avoir aucune fuite de memoire
* sauf indication contraire, votre programme doit avoir exactement la meme sortie que sh (/bin/sh) ainsi que exactement la meme sortie d'erreur.

## Fonctions autorises

access (man 2 access);
chdir (man 2 chdir);
close (man 2 close);
closedir (man 3 closedir);
fork (man 2 fork);
getpid (man 2 getpid);
free (man 3 free);
getline (man 2 getline);
signal (man 2 signal);
readdir (man 3 readdir);
kill (man 2 kill);
isatty (man 3 isatty);
malloc (man 3 malloc);
perror (man 3 perror);
printf (man 3 printf);
wait (man 2 wait);
putchar (man 3 putchar);

## DOCUMENTS

Installation:
$ cloner ce depot: git clone htpps://github.com/scandere78/holbertonshool-simple_shell.git
$ acceder au repertoires du referentiel: cd simple_shell
$ compiler: gcc -wall werror -wextra -pedantic -std=gnu89 *.C -O hsh 
$ ExÃ©cutez le shell en mode interactif: ./hsh
Ou exÃ©cutez le shell en mode non interactif: exemple echo "hello world!" | ./hsh

ESSAI

Compiler d'abord puis exÃ©cutez le fichier exÃ©cutable sur votre terminal. Pour la compilation, voir la section Installation.

$ ./hsh
$
$ ls -l
total 8
drwxrwxrwt 1 root root 4096 Feb 12 21:54 .
drwxr-xr-x 1 root root 4096 Apr 26 06:12 ..



ISTEST
![Diagramme sans nom drawio](https://github.com/Scandere78/holbertonschool-simple_shell/assets/159014102/247732d1-b72f-428d-8f21-7df5dbe6aaa8)
