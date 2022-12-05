//
// Created by Administrator on 2022/11/24.
//

#ifndef LERAN_FATAL_H
#define LERAN_FATAL_H

#endif //LERAN_FATAL_H

#include <stdio.h>
#include <stdlib.h>

#define Error( Str )        FatalError( Str )
#define FatalError( Str )   fprintf( stderr, "%s\n", Str ), exit( 1 )
