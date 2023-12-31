/*****************************************************************/
/*****************************************************************/
/************		Author: Kerolos Hanna			**************/
/************		Kerolos.Hanna@hotmail.com		**************/
/************		Layer:	LIB						**************/
/************		SWC:	Standard Types			**************/
/************		version: 1.00					**************/
/*****************************************************************/
/*****************************************************************/

#ifndef _STD_TYPES_H

#define _STD_TYPES_H

typedef unsigned char			uint8;
typedef unsigned short int		uint16;
typedef unsigned long int		uint32;

typedef signed char				suint8;
typedef signed short int		suint16;
typedef signed long int			suint32;

typedef float					f32;
typedef double					f64;

#define NULL					(void*)0

#define PREBUILD				1
#define POSTBUILD				2

#define ENABLED					1
#define DISABLED				2

#define OK						1
#define NOK						2
#define NULL_POINTER			3
#define BUSY_FUNCTION			4
#endif
