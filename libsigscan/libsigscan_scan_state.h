/*
 * Scan state functions
 *
 * Copyright (C) 2014-2015, Joachim Metz <joachim.metz@gmail.com>
 *
 * Refer to AUTHORS for acknowledgements.
 *
 * This software is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This software is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this software.  If not, see <http://www.gnu.org/licenses/>.
 */

#if !defined( _LIBSIGSCAN_SCAN_STATE_H )
#define _LIBSIGSCAN_SCAN_STATE_H

#include <common.h>
#include <types.h>

#include "libsigscan_extern.h"
#include "libsigscan_libcdata.h"
#include "libsigscan_libcerror.h"
#include "libsigscan_scan_tree.h"
#include "libsigscan_types.h"

#if defined( __cplusplus )
extern "C" {
#endif

typedef struct libsigscan_internal_scan_state libsigscan_internal_scan_state_t;

struct libsigscan_internal_scan_state
{
	/* The state
	 */
	int state;

	/* The data offset
	 */
	off64_t data_offset;

	/* The data size
	 */
	size64_t data_size;

	/* The scanned data size
	 */
	size64_t scanned_data_size;

	/* The scan tree
	 */
	libsigscan_scan_tree_t *scan_tree;

	/* The active scan tree node
	 */
	libsigscan_scan_tree_node_t *active_node;

	/* The (scan) buffer
	 */
	uint8_t *buffer;

	/* The (scan) buffer size
	 */
	size_t buffer_size;

	/* The (scan) buffer data size
	 */
	size_t buffer_data_size;

	/* The scan results array
	 */
	libcdata_array_t *scan_results_array;
};

LIBSIGSCAN_EXTERN \
int libsigscan_scan_state_initialize(
     libsigscan_scan_state_t **scan_state,
     libcerror_error_t **error );

LIBSIGSCAN_EXTERN \
int libsigscan_scan_state_free(
     libsigscan_scan_state_t **scan_state,
     libcerror_error_t **error );

LIBSIGSCAN_EXTERN \
int libsigscan_scan_state_set_data_size(
     libsigscan_scan_state_t *scan_state,
     size64_t data_size,
     libcerror_error_t **error );

int libsigscan_scan_state_get_buffer_size(
     libsigscan_scan_state_t *scan_state,
     size_t *buffer_size,
     libcerror_error_t **error );

int libsigscan_scan_state_start(
     libsigscan_scan_state_t *scan_state,
     libsigscan_scan_tree_t *scan_tree,
     size_t scan_buffer_size,
     libcerror_error_t **error );

int libsigscan_scan_state_stop(
     libsigscan_scan_state_t *scan_state,
     libcerror_error_t **error );

int libsigscan_internal_scan_state_scan_buffer(
     libsigscan_internal_scan_state_t *internal_scan_state,
     const uint8_t *buffer,
     size_t buffer_size,
     size_t buffer_offset,
     libcerror_error_t **error );

int libsigscan_scan_state_scan_buffer(
     libsigscan_scan_state_t *scan_state,
     const uint8_t *buffer,
     size_t buffer_size,
     libcerror_error_t **error );

LIBSIGSCAN_EXTERN \
int libsigscan_scan_state_get_number_of_results(
     libsigscan_scan_state_t *scan_state,
     int *number_of_results,
     libcerror_error_t **error );

LIBSIGSCAN_EXTERN \
int libsigscan_scan_state_get_result(
     libsigscan_scan_state_t *scan_state,
     int result_index,
     libsigscan_scan_result_t **scan_result,
     libcerror_error_t **error );

#if defined( __cplusplus )
}
#endif

#endif
