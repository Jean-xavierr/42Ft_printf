#include <stdio.h>

int		ft_printf(const char *s, ...);

int		main(void)
{
	
	ft_printf("ft_printf : %-15w\n");
	ft_printf("ft_printf : %05d\n", 42);
	ft_printf("ft_printf : %.12s\n", "string");
	ft_printf("ft_printf : %-*10s\n", "test");
//	printf("   printf : %-15w\n");
//	printf("   printf : %-15.5s\n", "Strings");
	return (0);
}
