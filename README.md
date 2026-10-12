# cutievanilla

A pasta public é /include/, enquanto os submódulos estão dentro de /src/cutievanilla/

assim, a lib pode ser importada com :   #include "cutievanilla.h"

e os modulos publico como:  #include "cutievanilla/matrix.h"



===================   LISTA DE FUNÇÕES EM MATRIZES     ===================
|
|----matrix.c — núcleo
|    |----[x] cv_matrix_create()
|    |----[x] cv_matrix_free()
|    |----[x] cv_matrix_clone()
|
|    |----[x] cv_matrix_get_dimension()
|    |----[x] cv_matrix_get_shape()
|    |----[x] cv_matrix_element_count()
|    |----[x] cv_matrix_element_size()
|
|    |----[x] cv_matrix_get()
|    |----[x] cv_matrix_set()
|
|----matrix_arithmetic.c — Aritmética
|    |----[ ] cv_matrix_fill()
|    |
|    |----[ ] cv_matrix_add()
|    |----[ ] cv_matrix_subtract()
|    |----[ ] cv_matrix_multiply()
|    |----[ ] cv_matrix_divide()
|    |
|    |----[ ] cv_matrix_scale()
|    |----[ ] cv_matrix_add_scalar()
|
|----matrix_geometry.c — Geometria
|    |----[ ] ... { Operações de algebra linear e geometria analítica }
|
|
|----matrix_transform.c — Transform
|    |----[ ] cv_matrix_transpose()
|    |----[ ] cv_matrix_reshape()
|    |----[ ] cv_matrix_permute_axes()
|    |----[ ] cv_matrix_slice()
|    |----[ ] cv_matrix_copy_region()
|
|----matrix_compare.c — Compare
|    |----[ ] cv_matrix_same_shape()
|    |----[ ] cv_matrix_same_type()
|    |----[ ] cv_matrix_equals()
|
L----matrix_stats.c — Statistic
     |----[ ] cv_matrix_min()
     |----[ ] cv_matrix_max()
     |----[ ] cv_matrix_sum()
     |----[ ] cv_matrix_mean()
     |----[ ] cv_matrix_variance()


===================   LISTA DE FUNÇÕES EM METADADOS    ===================

===================   LISTA DE FUNÇÕES EM TIPOS        ===================
|
|----types.c — núcleo
|    |----[x] cv_type_is_valid()
|    |----[x] cv_type_size()
|    |----[x] cv_type_name()
|    |
|    |----[x] cv_type_is_integer()
|    |----[x] cv_type_is_signed()
|    |
|    |----[x] cv_type_equals()
|    |----[x] cv_type_compare()
|    |----[x] cv_type_copy()
|    |----[x] cv_type_set_zero()
|    |
|    |----[x] cv_type_add()
|    |----[x] cv_type_sub()
|    |----[x] cv_type_mul()
|    |----[x] cv_type_div()
|    |
|    |----[x] cv_type_min()
|    |----[x] cv_type_max()
|    |
|    |----[x] cv_type_to_string()
|    |----[x] cv_type_from_string()
|    |
|    |----[x] cv_type_can_convert()
|    |----[x] cv_type_convert()
|
|----types.c — Primitive types
|    |----[x] UINT8
|    |----[x] INT8
|    |----[x] UINT16
|    |----[x] INT16
|    |----[x] UINT32
|    |----[x] INT32
|    |----[ ] FLOAT32
|    |----[ ] FLOAT64

===================   LISTA DE FUNÇÕES EM IMAGENS      ===================
(...)

===================   LISTA DE FUNÇÕES EM REGION      ===================
|
|----region.c — núcleo
|    |----[x] cv_region_is_valid()
|
|----region.c — Geometria
|    |----[x] cv_region_right()
|    |----[x] cv_region_left()
|    |----[x] cv_region_top()
|    |----[x] cv_region_bottom()
|    |----[x] cv_region_area()
|    |----[x] cv_region_center_x()
|    |----[x] cv_region_center_y()
|
|----region.c — Relação
|    |----[x] cv_region_contains_point()
|    |----[x] cv_region_contains()
|    |----[x] cv_region_intersects()
|    |----[x] cv_region_equals()
|
L----region.c — Operacoes Geometricas
     |----[x] cv_region_translated()
     |----[x] cv_region_intersection()
     |----[x] cv_region_union()
     |----[x] cv_region_subregion()
     |----[x] cv_region_split()


===================   LISTA DE FUNÇÕES EM HISTOGRAMAS  ===================
|
|----histogram.c — núcleo
|    |----[x] cv_histogram_create()
|    |----[x] cv_histogram_free()
|    |----[x] cv_histogram_clone()
|    |
|    |----[x] cv_histogram_bins()
|    |----[x] cv_histogram_element_size()
|    |----[x] cv_histogram_type()
|    |
|    |----[x] cv_histogram_get_value()
|    |----[x] cv_histogram_set_value()
|    |
|    |----[x] cv_histogram_get_count()
|    |----[x] cv_histogram_set_count()
|    |
|    |----[x] cv_histogram_clear()
|    |----[x] cv_histogram_clear_values()
|    |----[x] cv_histogram_clear_counts()
|    |
|    L----[ ] cv_histogram_init_values()
|
|
|----histogram_arithmetic.c — operações sobre contagens
|    |----[ ] cv_histogram_add_count()
|    |----[ ] cv_histogram_add()
|    |----[ ] cv_histogram_add_histogram()
|    |----[ ] cv_histogram_subtract_histogram()
|    L----[ ] cv_histogram_scale()
|
|
|----histogram_search.c — busca de bins
|
|    |----[ ] cv_histogram_find_bin()
|    |----[ ] cv_histogram_find_nearest_bin()
|    |
|    |----[ ] cv_histogram_find_first_nonzero()
|    |----[ ] cv_histogram_find_last_nonzero()
|    |
|    |----[ ] cv_histogram_find_min_bin()
|    |----[ ] cv_histogram_find_max_bin()
|    |
|    |----[ ] cv_histogram_find_min_count_bin()
|    L----[ ] cv_histogram_find_max_count_bin()
|
|
|----histogram_stats.c — estatísticas
|    |----[ ] cv_histogram_total()
|    |
|    |----[ ] cv_histogram_min()
|    |----[ ] cv_histogram_max()
|    |
|    |----[ ] cv_histogram_mean()
|    |----[ ] cv_histogram_variance()
|    |----[ ] cv_histogram_stddev()
|    |
|    |----[ ] cv_histogram_median()
|    |----[ ] cv_histogram_percentile()
|    |
|    |----[ ] cv_histogram_mode()
|    |----[ ] cv_histogram_mode_bin()
|    |
|    |----[ ] cv_histogram_skewness()
|    L----[ ] cv_histogram_kurtosis()
|
|
|----histogram_distribution.c — distribuição de probabilidade
|
|    |----[ ] cv_histogram_probability()
|    |----[ ] cv_histogram_cdf()
|    |
|    |----[ ] cv_histogram_entropy()
|    L----[ ] cv_histogram_quantile()
|
|
|----histogram_transform.c — transformações
|
|    |----[ ] cv_histogram_normalize()
|    |----[ ] cv_histogram_normalize_range()
|    |
|    |----[ ] cv_histogram_cumulative()
|    |
|    L----[ ] cv_histogram_clip()
|
|----histogram_compare.c — comparação
|
|    |----[ ] cv_histogram_equals()
|    |
|    |----[ ] cv_histogram_distance_euclidean()
|    |----[ ] cv_histogram_distance_manhattan()
|    |----[ ] cv_histogram_distance_chi_square()
|    |
|    |----[ ] cv_histogram_distance_hellinger()
|    |----[ ] cv_histogram_distance_kl_divergence()
|    |----[ ] cv_histogram_distance_js_divergence()
|    |
|    |----[ ] cv_histogram_similarity_intersection()
|    |----[ ] cv_histogram_similarity_bhattacharyya()
|    |
|    L----[ ] cv_histogram_correlation()
|
|----histogram_rebin.c
|
|    |----[ ] cv_histogram_rebin()
|    L----[ ] cv_histogram_merge_bins()
|
|----histogram_filter.c
|
|    |----[ ] cv_histogram_smooth()
|    L----[ ] cv_histogram_blur()
|
|----histogram_matrix.c — Matrix → Histogram
|
|    |----[ ] cv_histogram_from_matrix()
|    |----[ ] cv_histogram_add_matrix()
|    |
|    |----[ ] cv_histogram_from_matrix_region()
|    |----[ ] cv_histogram_add_matrix_region()
|    |
|    |----[ ] cv_histogram_from_matrix_range()
|    |----[ ] cv_histogram_add_matrix_range()
|    |
|    |----[ ] cv_histogram_from_matrix_mask()
|    L----[ ] cv_histogram_add_matrix_mask()
|
|----histogram_image.c — Image → Histogram
|
|    |----[ ] cv_histogram_from_image_channel()
|    |----[ ] cv_histogram_add_image()
|    |
|    |----[ ] cv_histogram_from_image_region()
|    |----[ ] cv_histogram_add_image_region()
|    |
|    |----[ ] cv_histogram_from_image_mask()
|    |----[ ] cv_histogram_add_image_mask()
|    |
|    L----[ ] cv_histograms_from_image()
|
L----histogram_io.c — entrada/saída
     |----[ ] cv_histogram_load()
     L----[ ] cv_histogram_save()


