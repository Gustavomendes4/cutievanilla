# cutievanilla

A pasta public é /include/, enquanto os submódulos estão dentro de /src/cutievanilla/

assim, a lib pode ser importada com :   #include "cutievanilla.h"

e os modulos publico como:  #include "cutievanilla/matrix.h"



===================   LISTA DE FUNÇÕES EM MATRIZES     ===================





===================   LISTA DE FUNÇÕES EM METADADOS    ===================

===================   LISTA DE FUNÇÕES EM TIPOS        ===================

===================   LISTA DE FUNÇÕES EM IMAGENS      ===================

===================   LISTA DE FUNÇÕES EM HISTOGRAMAS  ===================
|
|
|----histogram.c — núcleo
|    |----cv_histogram_create()
|    |----cv_histogram_free()
|    |----cv_histogram_clone()
|    |
|    |----cv_histogram_bins()
|    |----cv_histogram_element_size()
|    |----cv_histogram_type()
|    |
|    |----cv_histogram_get_value()
|    |----cv_histogram_set_value()
|    |
|    |----cv_histogram_get_count()
|    |----cv_histogram_set_count()
|    |
|    |----cv_histogram_clear()
|    |----cv_histogram_clear_values()
|    |----cv_histogram_clear_counts()
|    |
|    L----cv_histogram_init_values()
|
|
|----histogram_arithmetic.c — operações sobre contagens
|    |----cv_histogram_add_count()
|    |----cv_histogram_add()
|    |----cv_histogram_add_histogram()
|    |----cv_histogram_subtract_histogram()
|    L----cv_histogram_scale()
|
|
|----histogram_search.c — busca de bins
|
|    |----cv_histogram_find_bin()
|    |----cv_histogram_find_nearest_bin()
|    |
|    |----cv_histogram_find_first_nonzero()
|    |----cv_histogram_find_last_nonzero()
|    |
|    |----cv_histogram_find_min_bin()
|    |----cv_histogram_find_max_bin()
|    |
|    |----cv_histogram_find_min_count_bin()
|    L----cv_histogram_find_max_count_bin()
|
|
|----histogram_stats.c — estatísticas
|    |----cv_histogram_total()
|    |
|    |----cv_histogram_min()
|    |----cv_histogram_max()
|    |
|    |----cv_histogram_mean()
|    |----cv_histogram_variance()
|    |----cv_histogram_stddev()
|    |
|    |----cv_histogram_median()
|    |----cv_histogram_percentile()
|    |
|    |----cv_histogram_mode()
|    |----cv_histogram_mode_bin()
|    |
|    |----cv_histogram_skewness()
|    L----cv_histogram_kurtosis()
|
|
|----histogram_distribution.c — distribuição de probabilidade
|
|    |----cv_histogram_probability()
|    |----cv_histogram_cdf()
|    |
|    |----cv_histogram_entropy()
|    L----cv_histogram_quantile()
|
|
|----histogram_transform.c — transformações
|
|    |----cv_histogram_normalize()
|    |----cv_histogram_normalize_range()
|    |
|    |----cv_histogram_cumulative()
|    |
|    L----cv_histogram_clip()
|
|----histogram_compare.c — comparação
|
|    |----cv_histogram_equals()
|    |
|    |----cv_histogram_distance_euclidean()
|    |----cv_histogram_distance_manhattan()
|    |----cv_histogram_distance_chi_square()
|    |
|    |----cv_histogram_distance_hellinger()
|    |----cv_histogram_distance_kl_divergence()
|    |----cv_histogram_distance_js_divergence()
|    |
|    |----cv_histogram_similarity_intersection()
|    |----cv_histogram_similarity_bhattacharyya()
|    |
|    L----cv_histogram_correlation()
|
|----histogram_rebin.c
|
|    |----cv_histogram_rebin()
|    L----cv_histogram_merge_bins()
|
|----histogram_filter.c
|
|    |----cv_histogram_smooth()
|    L----cv_histogram_blur()
|
|----histogram_matrix.c — Matrix → Histogram
|
|    |----cv_histogram_from_matrix()
|    |----cv_histogram_add_matrix()
|    |
|    |----cv_histogram_from_matrix_region()
|    |----cv_histogram_add_matrix_region()
|    |
|    |----cv_histogram_from_matrix_range()
|    |----cv_histogram_add_matrix_range()
|    |
|    |----cv_histogram_from_matrix_mask()
|    L----cv_histogram_add_matrix_mask()
|
|----histogram_image.c — Image → Histogram
|
|    |----cv_histogram_from_image_channel()
|    |----cv_histogram_add_image()
|    |
|    |----cv_histogram_from_image_region()
|    |----cv_histogram_add_image_region()
|    |
|    |----cv_histogram_from_image_mask()
|    |----cv_histogram_add_image_mask()
|    |
|    L----cv_histograms_from_image()
|
L----histogram_io.c — entrada/saída
     |----cv_histogram_load()
     L----cv_histogram_save()
