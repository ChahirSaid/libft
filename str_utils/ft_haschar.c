/**
 * ft_haschar - Check if a character exists in a string
 *
 * @str: String to search
 * @target: Character to search for
 *
 * Returns: 1 if the character is found, 0 otherwise
 */
 int	ft_haschar(char *str, char target)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == target)
			return (1);
		str++;
	}
	return (0);
}