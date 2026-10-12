/* Default includes */
#include <stdlib.h>
#include <string.h>

/* Public inclues*/
#include "cutievanilla.h"
#include "cutievanilla/type.h"
#include "cutievanilla/matrix.h"
#include "cutievanilla/histogram.h"
#include "cutievanilla/region.h"



CVHistogram* cv_histogram_from_matrix(CVMatrix* matrix);

CVHistogram* cv_histogram_from_matrix_region(CVMatrix* matrix, CVRegion region);

bool cv_histogram_add_matrix(CVHistogram* histogram, CVMatrix* matrix);

bool cv_histogram_add_matrix_region(
    CVHistogram* histogram,
    CVMatrix* matrix,
    CVRegion region
);
