

#include <stdio.h>
#include "ball.h"

void 
ay_bounce_init(ayBall* tBall)
{
	if(tBall == NULL)
	{
		printf("invalid ball object\n");
		return;
	}

	reset_regula_falsi(0.0, &tBall->rf);

}
