

#include <stdio.h>
#include "ball.h"

#include "trick/integrator_c_intf.h"

int
ay_integrate(ayBall* tBall)
{

	if(tBall == NULL)
	{
		printf("invalid ball object\n");
		return -1;
	}

	/* load current position and velocity */
	load_state(&tBall->dPosition, &tBall->dVelocity, NULL); 

	/* load derivatives (velocity is derivative of position, acceleration is derivative of velocity */
	load_deriv(&tBall->dVelocity, &tBall->dAcceleration, NULL);

	/* call trick integration */
	int ipass = integrate();

	/* unload updated position and velocity */
	unload_state(&tBall->dPosition, &tBall->dVelocity, NULL);	

	return ipass;

}
