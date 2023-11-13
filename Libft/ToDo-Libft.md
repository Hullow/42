ft_split: continue working on ft_fill_word, starting with the input variables (notably length)


Paco:

FUNCTION         TESTS                RESULT
ft_isalpha       ✓✓✓✓✓✓✓              OK
ft_isdigit       ✓✓✓✓✓✓✓              OK
ft_isalnum       ✓✓✓✓✓✓✓              OK
ft_isascii       ✓✓✓✓✓✓✓✓             OK
ft_isprint       ✓✓✓✓✓✓✓              OK
ft_strlen        ✓✓✓✓✓✓               OK
ft_memset        ✓✓✓✓                 OK
ft_bzero         ✓✓                   OK
ft_memcpy        ✓✓✓                  OK
ft_memmove       ✓✓✓✓✓                OK
ft_strlcpy       ✓✓✓✓✓                OK

*ft_strlcat       ✓✓✓✓✗✗✗✓✓            KO*
*ft_toupper       ✗✗✗✗✗✓✗             	 KO*
*ft_tolower       ✗✗✗✓✗✗✗              KO*
*ft_strchr        ✓✓✓✓✗✗               KO*
*ft_strrchr       ✗✓✓✓✓✓✗✓             KO*
*ft_strncmp       ✓✗✗✓✓✓✓✓✓✓✗          KO*
*ft_memchr        ✓✓✓✓✓✗               KO*
*ft_memcmp        ✓✓✓✓✓✓✗✓✗            KO*
*ft_strnstr       ✗✓✓✓✗✓✓✓✓✓           KO*
*ft_atoi          ✓✓✓✓✓✓✗✗✗✗✓✓✓✓✓✓✓✓✓  KO*
ft_calloc        ✓                    OK
*ft_strdup        A                    KO*

ft_substr        ✓✓✓✓✓                OK

*ft_strjoin       AAA✓                 KO*

ft_strtrim       ✓✓✓✓✓                OK

*ft_split         compil. failed       KO*

Abort: A  Bus error: B  Segmentation fault: S  Timeout: T

More information in: /Users/francis/francinette/temp/libft/war-machine/deepthought
Abort: A  Bus error: B  Segmentation fault: S  Timeout: T