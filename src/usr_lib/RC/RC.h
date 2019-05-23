#ifndef RC_H
#define RC_H

#include "stdio.h"
#include "stdint.h"
#include "string.h"
#include "../CMAT/cmat.h"
#include "../TP/TP_polynomial.h"

#define RC_LEG_LF 0
#define RC_LEG_LH 1
#define RC_LEG_RF 2
#define RC_LEG_RH 3

#define pi 3.1416f

typedef struct RC_Mech_t
{
	char type[16];
	float leg_d;
	float leg_a1;
	float leg_a2;
	float body_w;
	float body_l;

}RC_Mech_t;

typedef struct RC_Move_t
{
	char gait[16];
	float span_x;
	float span_y;
	float span_z;
	float span_w;
	float duty_ratio;
	float cycle;
	float interval;

}RC_Move_t;

typedef struct RC_Pose_t
{
	float body_x;
	float body_y;
	float body_z;
	float body_ro;
	float body_pi;
	float body_ya;
	float pos_ro;
	float pos_pi;

}RC_Pose_t;

typedef struct RC_Zero_t
{
	float width;
	float length;
	float centre_x;
	float centre_y;

}RC_Zero_t;

typedef struct RC_Mat_t
{
	matrix_t *Base[4];
	matrix_t *BodyFrm2LegFrm[4];
	matrix_t *PosFrm2ZeroFrm[4];
	matrix_t *RefFrm2BodyFrm;
	matrix_t *RefFrm2PosFrm;

	matrix_t *ZeroFrm2p[4];
	matrix_t *PosFrm2p[4];
	matrix_t *RefFrm2p[4];
	matrix_t *BodyFrm2p[4];
	matrix_t *LegFrm2p[4];

}RC_Mat_t;

typedef struct RC_Robot_t
{
	RC_Mech_t Mech;
	RC_Move_t Move;
	RC_Pose_t Pose;
	RC_Zero_t Zero;
	
	RC_Mat_t Mat;

}RC_Robot_t;

#endif
