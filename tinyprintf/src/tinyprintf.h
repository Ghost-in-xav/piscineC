#ifndef TINYPRINTF_H
#define TINYPRINTF_H

int tinyprintf(const char *format, ...);
char *my_itoa(long value, char *s);
char *my_itoa_base(long n, char *s, const char *base);

#endif /* ! TINYPRINTF_H */
