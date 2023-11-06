#ifndef DOG_H
#define DOG_H

/**
 * struct dog - Defines a dog's information
 * @name: Name of the dog (string)
 * @age: Age of the dog (float)
 * @owner: Owner of the dog (string)
 */
struct dog {
    char *name;
    float age;
    char *owner;
};

/* Function prototype for init_dog */
void init_dog(struct dog *d, char *name, float age, char *owner);

#endif /* DOG_H */

