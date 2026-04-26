
#ifndef BALL_H
#define BALL_H

/*
PURPOSE: (Bouncing ball model)
LIBRARY_DEPENDENCY:
    (
        (../src/ball_init.c)
        (../src/ball_force.c)
        (../src/ball_integrate.c)
        (../src/ball_impact.c)
        (../src/ball_default_data.c)
    )
*/

#include "trick/regula_falsi.h"

typedef struct _ayBall
{
    double dPosition;     /* m -- height above ground */
    double dVelocity;     /* m/s -- positive = moving up */
    double dAcceleration; /* m/s2 -- total acceleration acting on ball */
    double dGravity;      /* *i m/s2 -- constant */
    double dBounce;       /* *i -- coefficient of restitution */
    int    iHit;          /* -- impact flag */

    REGULA_FALSI rf;

} ayBall;

#ifdef __cplusplus
extern "C" {
#endif
    void   ay_ball_default_data(ayBall*);
   	void   ay_bounce_init      (ayBall*);
   	void   ay_force            (ayBall*);
	int    ay_integrate        (ayBall*);
	double ay_impact           (ayBall*);
#ifdef __cplusplus
}
#endif


#endif
