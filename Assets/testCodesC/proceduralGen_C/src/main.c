#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define WIDTH 	(10)
#define HEIGHT 	(10)

#define SEED 	(12)

static int test_map[HEIGHT][WIDTH];

int random_range(int min, int max)
{
	return (rand()%(max - min + 1)) + min;
}

void set_background(int tab[HEIGHT][WIDTH])
{
	unsigned int i = 0;
	unsigned int j = 0;
	for(i = 0 ; i < HEIGHT; i++)
	{
		for(j = 0; j < WIDTH ; j++)
		{
			tab[i][j] = 1;
		}
	}
}


void set_road(int tab[HEIGHT][WIDTH])
{
	unsigned int i = 0;
	unsigned int j = 0;
	unsigned int startRoad_i = 0;
	unsigned int startRoad_j = 0;
	unsigned int endRoad_i = 0;
	unsigned int endRoad_j = 0;

	// starting road point
	startRoad_i = random_range((HEIGHT-1)/4,3*(HEIGHT-1)/4);
	startRoad_j = random_range((WIDTH-1)/4,3*(WIDTH-1)/4);
	tab[startRoad_i][startRoad_j] = 10;

	// starting road point
	do{
		endRoad_i = random_range((HEIGHT-1)/4,3*(HEIGHT-1)/4);
		endRoad_j = random_range((WIDTH-1)/4,3*(WIDTH-1)/4);
	}while(endRoad_i == startRoad_i || endRoad_j == startRoad_j);
	tab[endRoad_i][endRoad_j] = 11;
	

	

	// for(i = 0 ; i < HEIGHT; i++)
	// {
	// 	for(j = 0; j < WIDTH ; j++)
	// 	{
	// 		tab[i][j] = random_range(1,2);
	// 	}
	// }
}

void print_map(int tab[HEIGHT][WIDTH])
{
	unsigned int i = 0;
	unsigned int j = 0;
	for(i = 0 ; i < HEIGHT; i++)
	{
		for(j = 0; j < WIDTH ; j++)
		{
			printf("%3d  ",tab[i][j] );
		}
		printf("\n");
	}
}

int main()
{
	srand(SEED);
	// srand(time(NULL));

	set_background(test_map);
	
	print_map(test_map);
	
	set_road(test_map);
	printf("\n");
	print_map(test_map);

	return 0;
}