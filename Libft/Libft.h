#ifndef Libft_h
#define Libft_h


#include <stdlib.h> // for malloc
#include <stdio.h> // for size_t => acceptable ??

// prototypes
int	ft_atoi(char *str);
void	ft_bzero (void *s, unsigned int n);
void	*ft_calloc(size_t count, size_t size);
int	ft_isalnum(int c);
int ft_isalpha(int c);
int ft_isascii(int c);
int	ft_isdigit(int c);
int ft_isprint(int c);
void	*ft_memchr(const void *s, int c, size_t n);
int	ft_memcmp(const void *s1, const void *s2, size_t n);
void	*ft_memcpy(void *dst, const void *src, unsigned int n);
void	*ft_memmove(void *dst, const void *src, unsigned int len);
void	*ft_memset(void *b, int c, size_t len);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *str);
int ft_strncmp(char *s1, char *s2, unsigned int n);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strrchr(const char *s, int c);
// char *ft_strtrim(char const *s1, char const *set);
char *ft_substr(char const *s, unsigned int start, size_t len);
int	ft_tolower(int c);
int	ft_toupper(int c);


//Total nb fonctions: 34 Obligatoires. 23 - Partie 1, 11 - Partie 2. 










// remove restrict !
size_t	ft_strlen(const char *str);


#endif