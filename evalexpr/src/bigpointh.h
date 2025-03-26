#ifndef BIGPOINTH_H
#define BIGPOINTH_H

#include <stddef.h>

////////////////////////PILE INT/////////////////////////
struct stack
{
    int data;
    struct stack *next;
};
struct stack *stack_init();
int stack_len(struct stack *s);
struct stack *stack_push(struct stack *s, int e);
struct stack *stack_pop(struct stack *s);
int stack_peek(struct stack *s);

////////////////////////PILE CHAR///////////////////////

struct stackchar
{
    char data;
    struct stackchar *next;
};

int stackchar_len(struct stackchar *s);
struct stackchar *stackchar_push(struct stackchar *s, char e);
struct stackchar *stackchar_pop(struct stackchar *s);
char stackchar_peek(struct stackchar *s);

////////////////////////FILE///////////////////////////

struct list
{
    int data;
    struct list *next;
};

struct fifo
{
    struct list *head;
    struct list *tail;
    size_t size;
};

struct fifo *fifo_init(void);
size_t fifo_size(struct fifo *fifo);
void fifo_push(struct fifo *fifo, int elt);
int fifo_head(struct fifo *fifo);
void fifo_pop(struct fifo *fifo);
void fifo_clear(struct fifo *fifo);
void fifo_destroy(struct fifo *fifo);
void fifo_print(const struct fifo *fifo);

//////////////////////POLONAISE/////////////////////////

int lapolonaisedesesmorts(char *input);
int my_pow(int a, int b);
void check_valid_rpn(char *input);

/////////////////////TRANSFORMATION/////////////////////

int Prioritylevel(char operateur);
int Isequilibrer(char *input);
struct stackchar *vidange(char *res, struct stackchar *pile);
struct stackchar *gestion_char(struct stackchar *pile, char *res, char *token3);
char *convertir(char *input);
struct stackchar *gestion_ope(int i, char *res, char *token3,
                              struct stackchar *pile);
void IfIseq(char *input, char *token, char *soustoken);
char *my_tostring(char c);
char *my_itoa(int value, char *s);

///////////////////////GESTION////////////////////////

char *unary_op(char *input);
char *unary_conflict(char *input);
char *remove_spaces(char *input);
char *gestion(char *input);
void check_valid(char *input);
int is_op(char c);

#endif /* ! BIGPOINTH_H */
