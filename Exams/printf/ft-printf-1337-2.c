#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_strlen(char *str)
{
	int i = 0;

	while (str[i])
	{
		i++;
	}
	return (i);
}

int	ft_print_string(char *string)
{
	int	i;
	
	if (!string)
	{
		write(1, "No string to print\n", 20);
		return (-1);
	}
	i = 0;
	while (string[i])
		write(1, &string[i++], 1);
	return (i);
}

int	ft_printf_1337(char *string, ...)
{
	int		i;
	int		count;
	va_list	arg_list;

	va_start(arg_list, string);
	i = 0;
	count = 0;
	while (string[i])
	{
		if (string[i] == '%')
		{
			if (string[i + 1] == 's')
			{
				count += ft_print_string(va_arg(arg_list, char *));
				i += 2;
			}
			else
				count += ft_putchar('%');
		}
		else
			count += ft_putchar(string[i]);
	}
	va_end(arg_list);
	return (count);
}

int	main()
{
	ft_printf("%s\n", "test string");
	return (1);
}