

#include <stdio.h>
#include "ball.h"

void
ay_force(ayBall* tBall)
{
	if(tBall == NULL)
	{
		printf("invalid ball object\n");
		return;
	}

	tBall->dAcceleration = -(tBall->dGravity);
}
