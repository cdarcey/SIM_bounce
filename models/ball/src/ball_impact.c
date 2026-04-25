
#include <stdio.h>
#include "ball.h"
#include "trick/regula_falsi.h"
#include "trick/integrator_c_intf.h"


double
ay_impact(ayBall* tBall)
{

	if(tBall == NULL)
	{
		printf("invalid ball object\n");
		return -1;
	}

	/* reset to only capture impact on exact time step */
	tBall->iHit = 0;

	/* set error to current postion 
	 * rf.error represents how far we are from the "event"
	 * regula falsi watches this value as we approach zero
	 * each timestep to find the exact moment of impact */
	tBall->rf.error = tBall->dPosition;

	/* get current integration time */
	double dTimeNow = get_integ_time();

	/* estimate time remaining until impact */
	double dTimeToGo = regula_falsi(dTimeNow, &tBall->rf);

	/* check for impact */
	if(dTimeToGo == 0.0)
	{
		tBall->dVelocity = -(tBall->dVelocity * tBall->dBounce);
		tBall->iHit = 1;

		reset_regula_falsi(dTimeNow, &tBall->rf);
		fprintf(stderr, "impact at time: %.9f\n", dTimeNow);
	}

	return dTimeToGo;
}

