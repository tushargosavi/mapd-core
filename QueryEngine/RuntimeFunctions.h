#ifndef QUERYENGINE_RUNTIMEFUNCTIONS_H
#define QUERYENGINE_RUNTIMEFUNCTIONS_H

#include <cassert>
#include <cstdint>
#include <ctime>
#include <limits>

extern "C" int64_t agg_sum(int64_t* agg, const int64_t val);

extern "C" void agg_max(int64_t* agg, const int64_t val);

extern "C" void agg_min(int64_t* agg, const int64_t val);

extern "C" void agg_sum_double(int64_t* agg, const double val);

extern "C" void agg_max_double(int64_t* agg, const double val);

extern "C" void agg_min_double(int64_t* agg, const double val);

extern "C" int32_t agg_sum_int32_skip_val(int32_t* agg, const int32_t val, const int32_t skip_val);

extern "C" int64_t agg_sum_skip_val(int64_t* agg, const int64_t val, const int64_t skip_val);

extern "C" void agg_max_skip_val(int64_t* agg, const int64_t val, const int64_t skip_val);

extern "C" void agg_min_skip_val(int64_t* agg, const int64_t val, const int64_t skip_val);

extern "C" void agg_sum_float_skip_val(int32_t* agg, const float val, const float skip_val);

extern "C" void agg_sum_double_skip_val(int64_t* agg, const double val, const double skip_val);

extern "C" void agg_max_double_skip_val(int64_t* agg, const double val, const double skip_val);

extern "C" void agg_min_double_skip_val(int64_t* agg, const double val, const double skip_val);

extern "C" int32_t agg_sum_int32(int32_t* agg, const int32_t val);

extern "C" void agg_max_int32(int32_t* agg, const int32_t val);

extern "C" void agg_min_int32(int32_t* agg, const int32_t val);

extern "C" void agg_sum_float(int32_t* agg, const float val);

extern "C" void agg_max_float(int32_t* agg, const float val);

extern "C" void agg_min_float(int32_t* agg, const float val);

extern "C" void agg_max_int32_skip_val(int32_t* agg, const int32_t val, const int32_t skip_val);

extern "C" void agg_min_int32_skip_val(int32_t* agg, const int32_t val, const int32_t skip_val);

extern "C" void agg_max_float_skip_val(int32_t* agg, const float val, const float skip_val);

extern "C" void agg_min_float_skip_val(int32_t* agg, const float val, const float skip_val);

extern "C" void agg_count_distinct_bitmap(int64_t* agg, const int64_t val, const int64_t min_val);

#define EMPTY_KEY_64 std::numeric_limits<int64_t>::max()
#define EMPTY_KEY_32 std::numeric_limits<int32_t>::max()
#define EMPTY_KEY_16 std::numeric_limits<int16_t>::max()
#define EMPTY_KEY_8 std::numeric_limits<int8_t>::max()

extern "C" uint32_t key_hash(const int64_t* key, const uint32_t key_qw_count);

extern "C" int64_t* get_group_value(int64_t* groups_buffer,
                                    const uint32_t groups_buffer_entry_count,
                                    const int64_t* key,
                                    const uint32_t key_qw_count,
                                    const uint32_t row_size_quad,
                                    const int64_t* init_val = nullptr);

extern "C" int64_t* get_group_value_with_watchdog(int64_t* groups_buffer,
                                                  const uint32_t groups_buffer_entry_count,
                                                  const int64_t* key,
                                                  const uint32_t key_qw_count,
                                                  const uint32_t row_size_quad,
                                                  const int64_t* init_val = nullptr);

extern "C" int64_t* get_group_value_columnar(int64_t* groups_buffer,
                                             const uint32_t groups_buffer_entry_count,
                                             const int64_t* key,
                                             const uint32_t key_qw_count);

extern "C" int64_t* get_group_value_columnar_with_watchdog(int64_t* groups_buffer,
                                                           const uint32_t groups_buffer_entry_count,
                                                           const int64_t* key,
                                                           const uint32_t key_qw_count);

extern "C" int64_t* get_group_value_fast(int64_t* groups_buffer,
                                         const int64_t key,
                                         const int64_t min_key,
                                         const int64_t bucket,
                                         const uint32_t row_size_quad);

extern "C" int64_t* get_group_value_fast_with_original_key(int64_t* groups_buffer,
                                                           const int64_t key,
                                                           const int64_t orig_key,
                                                           const int64_t min_key,
                                                           const int64_t bucket,
                                                           const uint32_t row_size_quad);

extern "C" uint32_t get_columnar_group_bin_offset(int64_t* key_base_ptr,
                                                  const int64_t key,
                                                  const int64_t min_key,
                                                  const int64_t bucket);

extern "C" int64_t* get_matching_group_value_perfect_hash(int64_t* groups_buffer,
                                                          const uint32_t h,
                                                          const int64_t* key,
                                                          const uint32_t key_qw_count,
                                                          const uint32_t row_size_quad);

extern "C" int64_t* get_group_value_one_key(int64_t* groups_buffer,
                                            const uint32_t groups_buffer_entry_count,
                                            int64_t* small_groups_buffer,
                                            const uint32_t small_groups_buffer_qw_count,
                                            const int64_t key,
                                            const int64_t min_key,
                                            const uint32_t row_size_quad,
                                            const int64_t* init_vals);

extern "C" int64_t* get_group_value_one_key_with_watchdog(int64_t* groups_buffer,
                                                          const uint32_t groups_buffer_entry_count,
                                                          int64_t* small_groups_buffer,
                                                          const uint32_t small_groups_buffer_qw_count,
                                                          const int64_t key,
                                                          const int64_t min_key,
                                                          const uint32_t row_size_quad,
                                                          const int64_t* init_vals);

extern "C" int32_t* get_hash_slot(int32_t* buff, const int64_t key, const int64_t min_key);

extern "C" void linear_probabilistic_count(uint8_t* bitmap,
                                           const uint32_t bitmap_bytes,
                                           const uint8_t* key_bytes,
                                           const uint32_t key_len);

// Regular fixed_width_*_decode are only available from the JIT,
// we need to call them for lazy fetch columns -- create wrappers.

extern "C" int64_t fixed_width_int_decode_noinline(const int8_t* byte_stream,
                                                   const int32_t byte_width,
                                                   const int64_t pos);

extern "C" int64_t fixed_width_unsigned_decode_noinline(const int8_t* byte_stream,
                                                        const int32_t byte_width,
                                                        const int64_t pos);

extern "C" float fixed_width_float_decode_noinline(const int8_t* byte_stream, const int64_t pos);

extern "C" double fixed_width_double_decode_noinline(const int8_t* byte_stream, const int64_t pos);

extern "C" int8_t* extract_str_ptr_noinline(const uint64_t str_and_len);

extern "C" int32_t extract_str_len_noinline(const uint64_t str_and_len);

#endif  // QUERYENGINE_RUNTIMEFUNCTIONS_H
