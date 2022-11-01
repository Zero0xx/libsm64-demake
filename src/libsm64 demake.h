#ifndef LIB_SM64_DEMAKE_H
#define LIB_SM64_DEMAKE_H

#include <stddef.h>
#include <stdint.h>
#include <stdbool.h>

#include "decomp/include/types.h"

#ifdef _WIN32
    #ifdef SM64_LIB_EXPORT
        #define SM64_LIB_FN __declspec(dllexport)
    #else
        #define SM64_LIB_FN __declspec(dllimport)
    #endif
#else
    #define SM64_LIB_FN
#endif

struct SM64Surface
{
    int16_t type;
    int16_t force;
    uint16_t terrain;
    int32_t vertices[3][3];
};

struct SM64MarioInputs
{
    float camLookX, camLookZ;
    float stickX, stickY;
    uint8_t buttonA, buttonB, buttonZ;
};

struct SM64ObjectTransform
{
    float position[3];
    float eulerRotation[3];
};

struct SM64SurfaceObject
{
     struct SM64ObjectTransform transform;
    uint32_t surfaceCount;
    struct SM64Surface *surfaces;
};

struct SM64MarioState
{
     float position[3];
    float velocity[3];
    float faceAngle;
    int16_t health;
};

struct SM64MarioGeometryBuffers
{
    float *position;
    float *normal;
    float *color;
    float *uv;
    uint16_t numTrianglesUsed;
};

enum
{
    SM64_TEXTURE_WIDTH = 64 * 11,
    SM64_TEXTURE_HEIGHT = 64,
    SM64_GEO_MAX_TRIANGLES = 1024,
}

//Idfk what else to do lmao