/*
** EPITECH PROJECT, 2017
** evalexpr.h
** File description:
** header of the evalexpr
*/

#ifndef EVALXPR_H_
#define EVALXPR_H_

char *eval_expr_start(char **, int);
char *eval_expr_complex(char **, int);
int my_find_nbr(char *, int);
char *do_op_inf(char *, char *, char, int);
char *eval_expr_start(char **parse, int);
char *call_evalexpr(char *str, char *);
char *create_number(int lenght, int signe, char **parse, int len);
char *restart_evalexpr(char **parse, int len, int signe);
char *kill_neg(char *str);

#endif /*EVALXPR_H_*/
