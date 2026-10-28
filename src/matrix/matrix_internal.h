/*


*/

#ifndef CV_MATRIX_INTERNAL_H_INCLUDED
#define CV_MATRIX_INTERNAL_H_INCLUDED

#include "cutievanilla.h"

size_t calc_linear_index(const CVMatrix* matrix, const size_t* indices);

const void* cv_matrix_get_linear(const CVMatrix* matrix, size_t index);

void cv_matrix_set_linear(CVMatrix* matrix, size_t index, const void* value);

#endif //CV_MATRIX_INTERNAL_H_INCLUDED