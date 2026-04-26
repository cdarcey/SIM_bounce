

#include <stdio.h>
#include "ball.h"

void 
ay_ball_default_data(ayBall* tBall)
{
	
	if(tBall == NULL)
	{
		printf("invalid ball object\n");
		return;
	}

	tBall->dPosition     = 5.0;
	tBall->dVelocity     = 0.0;
	tBall->dAcceleration = 0.0;
	tBall->dGravity      = 9.81;
	tBall->dBounce       = 0.5;
	tBall->iHit          = 0;
}
