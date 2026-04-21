#ifndef BALL_H
#define BALL_H

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

void ay_bounce_init(ayBall* tBall);
void ay_force      (ayBall* tBall);
void ay_integrate  (ayBall* tBall);
void ay_impact     (ayBall* tBall);

#ifdef __cplusplus
extern "C" {
    #endif
        void ay_bounce_init(ayBall* tBall);
        void ay_force      (ayBall* tBall);
        void ay_integrate  (ayBall* tBall);
        void ay_impact     (ayBall* tBall);
    #ifdef __cplusplus
}
#endif


#endif