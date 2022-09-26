#ifndef PLATFORM_TYPES_H_
#define PLATFORM_TYPES_H_

typedef unsigned char 		bool;

#ifndef TRUE
  #define TRUE  (bool) 1
#endif

#ifndef FALSE
  #define FALSE (bool) 0
#endif


typedef signed char			sint8;
typedef unsigned char		uint8;

typedef signed short		sint16;
typedef unsigned short  uint16;

typedef signed int			sint32;
typedef unsigned int		uint32;

typedef float				    float32;
typedef double				  float64;

#endif
