/* Default includes */
#include <stdlib.h>
#include <string.h>

/* Public inclues*/
#include "cutievanilla.h"

CVImage* cv_histogram_from_image(const CVImage* image, size_t channel);

CVImage* cv_histogram_from_image_region(const CVImage* image, size_t channel, CVRegion region);

bool cv_histogram_add_image(const CVHistogram* histogram, CVImage* image);

bool cv_histogram_add_image_region(const CVHistogram* histogram, CVImage* image, CVRegion region);
