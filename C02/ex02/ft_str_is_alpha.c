
int ft_str_is_alpha(char *str)
{
while (*str != '\0')
{
    if (*str > 64 && *str < 123) // alphabetical characters: 65 ('A') to 122 ('z')
//    i = 0;
    continue;
    else
    return (0);
str++;
}
return (1);
}

int main(void)
{
    ft_str_is_alpha("abc");
    return(0);
}