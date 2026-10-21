#ifndef PICO_H
#define PICO_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

int find_objects(
    float rcsq[],
    int maxndetections,
    void* cascade,
    float angle,
    void* pixels,
    int nrows,
    int ncols,
    int ldim,
    float scalefactor,
    float stridefactor,
    float minsize,
    float maxsize
);

int cluster_detections(
    float rcsq[],
    int ndetections
);

#ifdef __cplusplus
}
#endif

#endif