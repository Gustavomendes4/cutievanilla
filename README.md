# cutievanilla

A pasta public é /include/, enquanto os submódulos estão dentro de /src/cutievanilla/

assim, a lib pode ser importada com :   #include "cutievanilla.h"

e os modulos publico como:  #include "cutievanilla/matrix.h"



============================================================================
===================   LISTA DE FUNÇÕES EM HISTOGRAMAS    ===================
============================================================================
|
|----histogram.c — núcleo
|    L----cv_histogram_create()
|    L----cv_histogram_free()
|    L----cv_histogram_clone()
|    |
|    L----cv_histogram_bins()
|    L----cv_histogram_element_size()
|    L----cv_histogram_type()
|    |
|    L----cv_histogram_get_value()
|    L----cv_histogram_set_value()
|    |
|    L----cv_histogram_get_count()
|    L----cv_histogram_set_count()
|    |
|    L----cv_histogram_clear()
|    L----cv_histogram_clear_values()
|    L----cv_histogram_clear_counts()
|    |
|    L----cv_histogram_init_values()
|
|
|----histogram_arithmetic.c — operações sobre contagens
|    L----cv_histogram_add_count()
|    L----cv_histogram_add()
|    L----cv_histogram_add_histogram()
|    L----cv_histogram_subtract_histogram()
|    L----cv_histogram_scale()
|
|
|----histogram_search.c — busca de bins
|
|    L----cv_histogram_find_bin()
|    L----cv_histogram_find_nearest_bin()
|    |
|    L----cv_histogram_find_first_nonzero()
|    L----cv_histogram_find_last_nonzero()
|    |
|    L----cv_histogram_find_min_bin()
|    L----cv_histogram_find_max_bin()
|    |
|    L----cv_histogram_find_min_count_bin()
|    L----cv_histogram_find_max_count_bin()
|
|
|----histogram_stats.c — estatísticas
|    L----cv_histogram_total()
|    |
|    L----cv_histogram_min()
|    L----cv_histogram_max()
|    |
|    L----cv_histogram_mean()
|    L----cv_histogram_variance()
|    L----cv_histogram_stddev()
|    |
|    L----cv_histogram_median()
|    L----cv_histogram_percentile()
|    |
|    L----cv_histogram_mode()
|    L----cv_histogram_mode_bin()
|    |
|    L----cv_histogram_skewness()
|    L----cv_histogram_kurtosis()
|
|
|----histogram_distribution.c — distribuição de probabilidade
|
|    L----cv_histogram_probability()
|    L----cv_histogram_cdf()
|    |
|    L----cv_histogram_entropy()
|    L----cv_histogram_quantile()
|
|
|----histogram_transform.c — transformações
|
|    L----cv_histogram_normalize()
|    L----cv_histogram_normalize_range()
|    |
|    L----cv_histogram_cumulative()
|    |
|    L----cv_histogram_clip()
|
|----histogram_compare.c — comparação
|
|    L----cv_histogram_equals()
|    |
|    L----cv_histogram_distance_euclidean()
|    L----cv_histogram_distance_manhattan()
|    L----cv_histogram_distance_chi_square()
|    |
|    L----cv_histogram_distance_hellinger()
|    L----cv_histogram_distance_kl_divergence()
|    L----cv_histogram_distance_js_divergence()
|    |
|    L----cv_histogram_similarity_intersection()
|    L----cv_histogram_similarity_bhattacharyya()
|    |
|    L----cv_histogram_correlation()
|
|----histogram_rebin.c
|
|    L----cv_histogram_rebin()
|    L----cv_histogram_merge_bins()
|
|----histogram_filter.c
|
|    L----cv_histogram_smooth()
|    L----cv_histogram_blur()
|
|----histogram_matrix.c — Matrix → Histogram
|
|    L----cv_histogram_from_matrix()
|    L----cv_histogram_add_matrix()
|    |
|    L----cv_histogram_from_matrix_region()
|    L----cv_histogram_add_matrix_region()
|    |
|    L----cv_histogram_from_matrix_range()
|    L----cv_histogram_add_matrix_range()
|    |
|    L----cv_histogram_from_matrix_mask()
|    L----cv_histogram_add_matrix_mask()
|
|----histogram_image.c — Image → Histogram
|
|    L----cv_histogram_from_image_channel()
|    L----cv_histogram_add_image()
|    |
|    L----cv_histogram_from_image_region()
|    L----cv_histogram_add_image_region()
|    |
|    L----cv_histogram_from_image_mask()
|    L----cv_histogram_add_image_mask()
|    |
|    L----cv_histograms_from_image()
|
L----histogram_io.c — entrada/saída
     L----cv_histogram_load()
     L----cv_histogram_save()