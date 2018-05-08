#include <stdio.h>
#include <stdlib.h>
#include <wchar.h>
#include <locale.h>
#include "convertisseurEgyptien.h"

int initialisation(int *decompose)
{
	int i;

	for(i = 0; i < 7; i++)
	{
		if (decompose[i] != 0)
			return (7 - i);
	}
	return 0;
}


wchar_t *creationTabSigne()
{
	wchar_t *signe;
	signe = malloc(7 * sizeof(wchar_t));
	signe[0] = L'𓏺';
	signe[1] = L'𓎆';
	signe[2] = L'𓍢';
	signe[3] = L'𓆼';
	signe[4] = L'𓂭';
	signe[5] = L'𓆐';
	signe[6] = L'𓁏';

	return (signe);
}

int *decomposition(int nb)
{
	int *decompose;
	decompose = malloc(7 * sizeof(int));
	while (nb > 999999)
	{
		decompose[0]++;
		nb -= 1000000;
	}
	while (nb > 99999)
	{
		decompose[1]++;
		nb -= 100000;
	}
	while (nb > 9999)
	{
		decompose[2]++;
		nb -= 10000;
	}
	while (nb > 999)
	{
		decompose[3]++;
		nb -= 1000;
	}
	while (nb > 99)
	{
		decompose[4]++;
		nb -= 100;
	}
	while (nb > 9)
	{
		decompose[5]++;
		nb -= 10;
	}
	while (nb > 0)
	{
		decompose[6]++;
		nb -= 1;
	}

	return (decompose);

}

void affichage(int *decompose, wchar_t *signe, int init)
{
	int i;
	int j;
	int cpt;
	int tab[7] = {0};

	for (i = 0; i < 7; i++) // bug du 0
	{
		if (decompose[i] == 0)
			tab[i] = 1;
	}
	for(cpt=0; cpt<3; cpt++)
	{
		for (i = init; i > 0; i--)
		{
			if (tab[7 - i] == 1) // bug du 0
			{

			}
			else if (decompose[7 - i] > 3)  // Cas 1
			{
				for (j = 0; j < 3; j++)
					printf("%lc", signe[i - 1]);
				decompose[7 - i] -= 3;
			}
			else if (decompose[7 - i] > 0) // Cas 2
			{
				for (j = 0; j < decompose[7 - i]; j++)
					printf("%lc", signe[i - 1]);
				for (j = 0; j < 3 - decompose[7 - i]; j++)
					printf(" ");
				decompose[7 - i] = 0;
			}
			else // Cas 3
				printf("   ");
			if (tab[8 - i] != 1)
				printf(" ");
		}
		printf("\n");
	}


}

int	main(void)
{
	int nb;
	int *decompose;

	//declaration de la variable qui indique ou commence le nombre
	int init = 0;
	int *signe;

	setlocale(LC_ALL, "");
	signe = creationTabSigne();
	printf("Veuillez saisir votre nombre:\n");
	scanf("%d", &nb);
	//decomposition du nombre saisi
	decompose = decomposition(nb);
	init = initialisation(decompose);
	affichage(decompose, signe, init);

	return 0;
}
