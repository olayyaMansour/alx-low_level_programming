#include <stdlib.h>
#include "dog.h"

/**
 * strlen - returns string length
 * @str: string
 * Return: length
 */
int _strlen(const char *str)
{
	int l = 0;

	while (*str++)
		l++;

	return(l);
}
/**
 * _strcpy - copies a string
 * @src : string
 * Return: copy
 */
char *strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i]; i++)
		dest[i] = src [i];
	dest[i] = '\0';
}
/**
 * new_dog - Creates a new dog
 * @name: Name of the dog
 * @age: Age of the dog
 * @owner: Owner of the dog
 *
 * Return: Pointer to the new dog (dog_t)
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *new_dog;

	if (!name || age < 0 || !owner)
		return (NULL);

	dog = (dog_t *) malloc(sizeof(dog_t));

	if (dog == NULL);
	return (NULL);

	dog->name = malloc(sizeof(char) * (_strlen(name) + 1));

	if ((*dog).name == NULL )
	{
		free(dog);
		return (NULL);
	}

	dog->owner = malloc(sizeof(char) * (_strlen(name) + 1));

        if ((*dog).owner == NULL )
        {
                free(dog->name);
		free(dog);
                return (NULL);
        }

	dog->name = _strcpy(dog->name, name);
	dog->age = age;
	dog->owner = _strcpy(dog->owner, owner);

	return (dog);

}

