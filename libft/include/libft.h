/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebini <ebini@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:45:51 by ebini             #+#    #+#             */
/*   Updated: 2025/07/10 21:50:01 by ebini            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include "defs.h"

/*************************************************/
/*                   CONVERTER                   */
/*************************************************/

/**
 * @brief Will parse a string into an int
 * @param nptr Pointer of the first character of the string to parse
 * @note This function will accept one '+' or '-' optional character for the 
 * sign before the number and as many whitespaces as you want before the
 * sign. It will also stop to parse at the first non-digit character found
 * after the sign.
 * @warning Any trying to parse a number bigger than INT_MAX or smaller than
 * INT_MIN will result in a overflow.
 * @return An int corresponding to the string passed in parameter.
 */
int		ft_atoi(const char *nptr);

/**
 * @brief Will convert an int into a allocated string.
 * @param n The number converted
 * @return An allocated string corresponding to the number passed in parameter.
 */
char	*ft_itoa(int n);

/**
 * @brief Free n pointers of an array arr of pointer (and the array itself).
 * @param arr The array containing the pointers
 * @param n The number of pointer to free
 */
void	free_n(char **arr, size_t n);

/**
 * @brief Will free an array string NULL terminated (the format returned by
 * ft_split).
 * @param splitted_string An array string NULL terminated
 */
void	free_split(char **splitted_string);

/*************************************************/
/*                  IDENTIFIERS                  */
/*************************************************/

/**
 * @brief Identify if a character is alphanumeric.
 * @param c the character to identify
 */
bool	ft_isalnum(int c);

/**
 * @brief Identify if a character is in the alphabet.
 * @param c the character to identify
 */
bool	ft_isalpha(int c);

/**
 * @brief Identify if a character is in the ascii table.
 * @param c the character to identify
 */
bool	ft_isascii(int c);

/**
 * @brief Identify if a character is a digit.
 * @param c the character to identify
 */
bool	ft_isdigit(int c);

/**
 * @brief Identify if a character is a lowercase letter.
 * @param c the character to identify
 */
bool	ft_islower(int c);

/**
 * @brief Identify if a character is printable.
 * @param c the character to identify
 */
bool	ft_isprint(int c);

/**
 * @brief Identify if a character is an uppercase letter.
 * @param c the character to identify
 */
bool	ft_isupper(int c);

/*************************************************/
/*                     LIST                      */
/*************************************************/

/**
 * @brief Will add a new t_list struct at the back of the list pointed by the
 * double pointer lst.
 * @param lst A double pointer to the first element of a list made of t_list
 * @param new A pointer to the first element of a list made of t_list
 * @note The parameter lst is a double pointer because in the case where it is
 * NULL, it will be replaced by the new pointer.
 */
void	lstadd_back(t_list **lst, t_list *new);

/**
 * @brief Will add a new t_list struct at the front of the list pointed by the
 * double pointer lst.
 * @param lst A double pointer to the first element of a list made of t_list
 * @param new A pointer to a t_list element added at the front of lst
 * @note The parameter lst is a double pointer because the first element of the
 * list lst will be replaced by the first element of the list new
 */
void	lstadd_front(t_list **lst, t_list *new);

/**
 * @brief Will free all element composing a list made of t_list.
 * @param lst A double pointer to the list that needs to be freed
 * @param del A function that will free the element stored in each list node
 * @note The value of *lst will be replaced by NULL
 */
void	lstclear(t_list **lst, void (*del)(void *));

/**
 * @brief Delete and free the content of one node of a list.
 * @param lst The node to delete
 * @param del The function to free the content of the node
 */
void	lstdelone(t_list *lst, void (*del)(void *));

/**
 * @brief Apply the function f to the content of every node of the list lst.
 * @param lst The first node of a listto iter through
 * @param f The funciton to call with the content of every node
 */
void	lstiter(t_list *lst, void (*f)(void *));

/**
 * @brief Duplicate the list lst and update the content of every node with the
 * function f.
 * @param lst The first node of the list to map
 * @param f The function to apply on the content of every node
 * @param del The function used to free the content of nodes if a malloc fails
 * @note Every memory allocation of this function is secure meaning that if one
 * of the many malloc returns NULL, all the new created list will be freed
 * @return The same list as lst but updated by the function f.
 */
t_list	*lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/**
 * @brief Creates a new node of t_list.
 * @param content The the content that will be contained by the list node
 * @return A pointer on a new node of a list.
 */
t_list	*lstnew(void *content);

/**
 * @brief Delete the last node of a t_list list an returns its content.
 * @param lst The first node of a list of which you want to pop the last element
 * @return The content of the last node of lst.
 */
void	*lstpop(t_list **lst);

/**
 * @brief Calculate the length of a list made of t_list nodes.
 * @param lst A pointer on the first element of a list
 * @return The length of the list starting by lst.
 */
size_t	lstsize(t_list *lst);

/*************************************************/
/*                     MATH                      */
/*************************************************/

// "Maths" is maybe a bit presomptuous

/**
 * @brief Give you the biggest number of an array arr of n element.
 * @param arr An array of int
 * @param n The length of the array
 * @return The biggest int of the array.
 */
int		arrmax(int *arr, size_t n);

/**
 * @brief Give you the smallest number of an array arr of n element.
 * @param arr An array of int
 * @param n The length of the array
 * @return The smallest int of the array.
 */
int		arrmin(int *arr, size_t n);

/**
 * @brief Returns the biggest number between a and b.
 * @param a An int
 * @param b An other int
 * @return The biggest int.
 */
int		max(int a, int b);

/**
 * @brief Returns the biggest number between a and b.
 * @param a A size_t
 * @param b An other size_t
 * @return The biggest int.
 */
size_t	maxs(size_t a, size_t b);

/**
 * @brief Returns the smallest number between a and b.
 * @param a An int
 * @param b An other int
 * @return The smallest int.
 */
int		min(int a, int b);

/**
 * @brief Returns the smallest number between a and b.
 * @param a A size_t
 * @param b An other size_t
 * @return The smallest int.
 */
size_t	mins(size_t a, size_t b);

/*************************************************/
/*                    MEMORY                     */
/*************************************************/

/**
 * @brief set n bytes of the the memory to 0 starting at the location pointed
 * by s.
 * @param s Pointer of the first element of the memory to erase
 * @param n The number of bytes set to 0
 */
void	ft_bzero(void *s, size_t n);

/**
 * @brief Allocate nmemb followed area of size size in the memory
 * (basically nmemb * size) and set them to 0.
 * @param nmemb The number of element to allocate
 * @param size The size of the elements
 * @return A void pointer on the first element allocated in the memory.
 */
void	*ft_calloc(size_t nmemb, size_t size);

/**		
 * @brief Look in the memory starting at the adress pointed by s of size n for
 * a byte of value c.
 * @param s A pointer to an area of the memory where we will search a value
 * @param c The value to search
 * @param n The size of the memory
 * @return A void pointer on the first byte corresponding to c (or NULL if
 * nothing was found).
 */
void	*ft_memchr(const void *s, int c, size_t n);

/**		
 * @brief Gives the difference between 2 memory areas
 * @param s1 A pointer to an area of the memory where we will search a value
 * @param s2 The value to search
 * @param n The size to compare
 * @return The difference between the first different bytes between in s1 and
 * s2 or 0 if the n bytes of s1 and s2 are identicals.
 */
int		ft_memcmp(const void *s1, const void *s2, size_t n);

/**
 * @brief Copy n bytes of the memory from src to dest.
 * @param src A pointer to the first byte of the source memory area
 * @param dest A pointer to the first byte of the destination memory area
 * @param n The number of bytes to copy
 * @note If the src and dest are overlapping use ft_memmove instead
 * @return dest
 */
void	*ft_memcpy(void *dest, const void *src, size_t n);

/**
 * @brief Allocates a memory of size n with malloc and copy n bytes of ptr into
 * the new memory area.
 * @param ptr A pointer to the first byte of the area tu duplicate
 * @param n The number of bytes to copy into the new memory area
 * @return The new allocated area.
 */
void	*ft_memdup(void *ptr, size_t n);

/**
 * @brief Move n bytes of the memory from src to dest (overlapping safe).
 * @param src A pointer to the first of the source memory area
 * @param dest A pointer to the first of the destination memory area
 * @param n The number of bytes to move
 * @note This function handle memory overlapping meaning that src might be
 * modified but dest will always contain what was in src.
 * @return dest
 */
void	*ft_memmove(const void *src, void *dest, size_t n);

/**
 * @brief Set n bytes of the memory from s to the value c.
 * @param s A pointer to the first of the memory area to set
 * @param c The value to set in the memory
 * @param n The number of bytes to set
 * @return s
 */
void	*ft_memset(void *s, int c, size_t n);

/*************************************************/
/*                    STRING                     */
/*************************************************/

/**
 * @brief Get the index of the first occurence of the char c in the string s.
 * @param s The string to search in
 * @param c The character to look for
 * @return The index of c in s or -1 if not found.
 */
ssize_t	ft_indexof(const char *s, char c);

/**
 * @brief Get the index of the first occurence of the char c in the n first char
 * of the string s.
 * @param s The string to search in
 * @param c The character to look for
 * @param n The number of charcter max to search in
 * @return The index of c in s or -1 if not found.
 */
ssize_t	ft_nindexof(const char *s, char c, size_t n);

/**
 * @brief Split a string s into substring for every character c. The result
 * can't contain any empty string.
 * @param s The string to split
 * @param c The character that delimits substrings
 * @warning The result is a double pointer to dynamically allocated strings
 * using malloc, to avoid memory leaks free them when done. You can use
 * the free_split function to do so.
 */
char	**ft_split(char const *s, char c);

size_t	ft_arrlen(void **arr);

/**
 * @brief Split a string s into substring for every character in the set given
 * in parameter. The result can't contain any empty string.
 * @param s The string to split
 * @param c The character that delimits substrings
 * @note This function behaves exactly like ft_split except that you pass a set
 * of characters as delimiters.
 * @warning The result is a double pointer to dynamically allocated strings
 * using malloc, to avoid memory leaks free them when done. You can use
 * the free_split function to do so.
 */
char	**ft_strtok(char const *s, const char *set);

/**
 * @brief Find the first occurence of the character c in the string s
 * @param s the string to search in
 * @param c the character to find in s
 * @return The adress of the first occurence of c in s OR NULL if c is not found
 */
char	*ft_strchr(const char *s, int c);

/**
 * @brief Find the last occurence of the character c in the string s
 * @param s the string to search in
 * @param c the character to find in s
 * @return The adress of the last occurence of c OR NULL if c is not found
 */
char	*ft_strrchr(const char *s, int c);

/**
 * @brief Gives a way to compare strings by returning the difference of the
 * first different character in the string (or 0 is nothing if found)
 * @param s1 a string
 * @param s2 a string
 * @return The difference (char from s1 - char from s2) when the strings differ,
 * 0 otherwise
 */
int		ft_strcmp(const char *s1, const char *s2);

/**
 * @brief Gives a way to compare n characters of strings by returning the
 * difference of the first different character in the string (or 0 is nothing if
 * found)
 * @param s1 a string
 * @param s2 a string
 * @param n the number of character max to compare
 * @return The difference (char from s1 - char from s2) when one of the n
 * characters of the strings differ, 0 otherwise
 */
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/**
 * @brief Every character of the string src in dest
 * @param dest a free memory space (must include room for null byte)
 * @param src The string to copy to dest
 * @return dest
 */
void	ft_strcpy(char *dest, const char *src);
size_t	ft_strcpy_len(char *dest, const char *src);
void	ft_strncpy(char *dest, const char *src, size_t n);
char	*ft_strdup(const char *s);
char	*ft_strndup(const char *s, size_t n);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
size_t	ft_strlen(const char *s);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
bool	starts_by(const char *s, const char *pattern);
bool	ends_by(const char *s, const char *pattern);

/**
 * @brief Join 2 strings into an new one, the new string is allocated using
 * malloc
 * 
 * @param s1
 * @param s2
 * @return A new string allocated using malloc
 */
char	*ft_strjoin(char const *s1, char const *s2);
char	*strjoinall(size_t count, ...);
char	*strmerge(char *s1, char *s2);
char	*strmergen(char *s1, char *s2, size_t n);
char	*stradd(char *s1, char *s2);
char	*straddn(char *s1, char *s2, size_t n);

/**
 * @brief Delete every characters of set at the beginning and the end of s.
 * @param s The string to trim
 * @param set The set of character to remove
 * @warning This function allocates a new memory area for the new string,
 * ensuring that the original string remains unchanged.
 */
char	*ft_strtrimm(char const *s, char const *set);

/**
 * @brief Delete every characters of set at the beginning and the end of s.
 * @param s The string to trim
 * @param set The set of character to remove
 * @warning This function modifies the existing string in place, avoiding memory
 * reallocation and reducing the risk of memory errors..
 */
char	*ft_strtrim(char *s, char const *set);
int		ft_tolower(int c);
int		ft_toupper(int c);
char	*ft_strstr(const char *big, const char *little);
char	*ft_strnstr(const char *big, const char *little, size_t len);

/**
 * @brief Will try to behave as a simple printf, handling flags csuihHp%
 */
int		ft_printf(const char *format, ...)
		__attribute__((format(printf, 1, 2)));

int		ft_dprintf(int fd, const char *format, ...)
		__attribute__((format(printf, 2, 3)));

void	ft_perror(const char *message);
void	ft_dperror(int fd, const char *message);

char	*get_next_line(int fd);

#endif
