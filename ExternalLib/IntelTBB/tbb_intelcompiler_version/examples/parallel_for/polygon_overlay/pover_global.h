/*
    Copyright 2005-2010 Intel Corporation.  All Rights Reserved.

    The source code contained or described herein and all documents related
    to the source code ("Material") are owned by Intel Corporation or its
    suppliers or licensors.  Title to the Material remains with Intel
    Corporation or its suppliers and licensors.  The Material is protected
    by worldwide copyright laws and treaty provisions.  No part of the
    Material may be used, copied, reproduced, modified, published, uploaded,
    posted, transmitted, distributed, or disclosed in any way without
    Intel's prior express written permission.

    No license under any patent, copyright, trade secret or other
    intellectual property right is granted to or conferred upon you by
    disclosure or delivery of the Materials, either expressly, by
    implication, inducement, estoppel or otherwise.  Any license under such
    intellectual property rights must be express and approved by Intel in
    writing.
*/

//
// pover_global.h
//
#ifndef _POVER_GLOBAL_H_
#define _POVER_GLOBAL_H_

#ifdef _MAIN_C_
#define DEFINE // nothing
#define STATIC static
#define INIT(n) = n
#else // not in main file
#define DEFINE extern
#define STATIC  // nothing
#define INIT(n) // nothing
#endif  // _MAIN_C_

#include <iostream>
#include <fstream>

#ifdef _WINDOWS
#include <windows.h>
#endif

// this Polygon class only supports rectangles
DEFINE int gDrawXOffset INIT(0);   // used for drawing polygons
DEFINE int gDrawYOffset INIT(0);
DEFINE int gPolyXBoxSize INIT(0);  // number of pixels orresponding to one "square" (x)
DEFINE int gPolyYBoxSize INIT(0);  // number of pixels orresponding to one "square" (y)
DEFINE bool gDoDraw INIT(false);       // render the boxes

#define THREADS_UNSET 0
DEFINE int gThreadsLow INIT(THREADS_UNSET);
DEFINE int gThreadsHigh INIT(THREADS_UNSET);

DEFINE std::ofstream gCsvFile;
DEFINE double gSerialTime;
DEFINE char *gCsvFilename INIT(NULL);

#define BORDER_SIZE 10  // number of pixels between maps

// The map size and the number of polygons depends on the version we are compiling.
// If DEBUG then it is small; else it is large.

#ifdef _DEBUG
DEFINE int gNPolygons INIT(30);  // default number of polygons in map
DEFINE int gMapXSize INIT(30);
DEFINE int gMapYSize INIT(30);
DEFINE int gGrainSize INIT(5);
#else
DEFINE int gNPolygons INIT(50000);    // default number of polygons in map
DEFINE int gMapXSize INIT(1000);
DEFINE int gMapYSize INIT(1000);
DEFINE int gGrainSize INIT(20);
#endif
DEFINE int gMyRandomSeed INIT(2453185);

DEFINE bool gIsGraphicalVersion INIT(false);

typedef enum {
    NORTH_SIDE,
    EAST_SIDE,
    SOUTH_SIDE,
    WEST_SIDE
} allSides;

#if _DEBUG
#define PRINT_DEBUG(x) (cout << x << std::endl)
#else
#define PRINT_DEBUG(x)
#endif


#endif // _POVER_GLOBAL_H_
