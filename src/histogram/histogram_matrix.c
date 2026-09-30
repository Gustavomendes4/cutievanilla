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

bool cv_histogram_add_matrix(CVHistogram* histogram, CVMatrix* matrix);
