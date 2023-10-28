#include <stdio.h>
#include <stdlib.h>
/**
 * minCoins - Calculates the minimum number of coins needed for change.
 * @amount: The amount of money for which change needs to be made.
 *
 * Return: The minimum number of coins needed for change.
 */
int minCoins(int amount)
{
	int coins[] = {25, 10, 5, 2, 1};
	int numCoins = 0;
	int i = 0;

	while (amount > 0)
	{
		if (amount >= coins[i])
		{
			amount -= coins[i];
			numCoins++;
		} else
		{
			i++;
		}
	}

	return (numCoins);
}
/**
 * main - Entry point of the program.
 * @argc: Argument count, the number of command-line arguments.
 * @argv: Argument vector, an array of strings containing the arguments.
 *
 * Return: 0 for successful execution, 1 for error.
 */
int main(int argc, char *argv[])
{
	int amount;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}
	amount = atoi(argv[1]);

	if (amount < 0)
	{
		printf("0\n");
	} else
	{
		int coins = minCoins(amount);

		printf("%d\n", coins);
	}
	return (0);
}

