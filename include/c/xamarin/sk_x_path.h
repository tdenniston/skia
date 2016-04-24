/*
 * Copyright 2016 Xamarin Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

// EXPERIMENTAL EXPERIMENTAL EXPERIMENTAL EXPERIMENTAL
// DO NOT USE -- FOR INTERNAL TESTING ONLY

#ifndef sk_x_path_DEFINED
#define sk_x_path_DEFINED

#include "sk_path.h"

#include "sk_types.h"
#include "xamarin/sk_x_types.h"

SK_C_PLUS_PLUS_BEGIN_GUARD

/** Set the beginning of the next contour relative to the last point on the
        previous contour. If there is no previous contour, this is treated the
        same as sk_path_move_to. 
*/
SK_API void sk_path_rmove_to(sk_path_t*, float dx, float dy);
/**
    Same as sk_path_line_to, but the coordinates are considered relative to the last
    point on this contour. If there is no previous point, then a sk_path_move_to(0,0)
    is inserted automatically.
*/
SK_API void sk_path_rline_to(sk_path_t*, float dx, float yd);
/**
    Same as sk_path_quad_to, but the coordinates are considered relative to the last
    point on this contour. If there is no previous point, then a sk_path_move_to(0,0)
    is inserted automatically.
*/
SK_API void sk_path_rquad_to(sk_path_t*, float dx0, float dy0, float dx1, float dy1);
/**
    Same as sk_path_conic_to, but the coordinates are considered relative to the last
    point on this contour. If there is no previous point, then a sk_path_move_to(0,0)
    is inserted automatically.
*/
SK_API void sk_path_rconic_to(sk_path_t*, float dx0, float dy0, float dx1, float dy1, float w);
/**
    Same as sk_path_cubic_to, but the coordinates are considered relative to the last
    point on this contour. If there is no previous point, then a sk_path_move_to(0,0)
    is inserted automatically.
*/
SK_API void sk_path_rcubic_to(sk_path_t*,
                             float dx0, float dy0,
                             float dx1, float dy1,
                             float dx2, float dy2);
/**
   Add a closed rectangle contour to the path with an initial point of the contour
   (startIndex) expressed as a corner index (0-3)
 */
SK_API void sk_path_add_rect_start(sk_path_t* cpath, const sk_rect_t* crect, sk_path_direction_t cdir, uint32_t startIndex);
/**
 Add the specified arc to the path as a new contour.
 */
SK_API void sk_path_add_arc(sk_path_t* cpath, const sk_rect_t* crect, float startAngle, float sweepAngle);
/**
    Get the fill type of the path.
*/
SK_API sk_path_filltype_t sk_path_get_filltype(sk_path_t*);
/**
    Set the fill type of the path.
*/
SK_API void sk_path_set_filltype(sk_path_t*, sk_path_filltype_t);
/**
    Transform the points in this path by matrix, and write the answer back into the path
*/
SK_API void sk_path_transform(sk_path_t* cpath, const sk_matrix_t* cmatrix);
/**
    Creates a copy of the path
*/
SK_API sk_path_t* sk_path_clone(const sk_path_t* cpath);

/** 
    Return the number of verbs in the path
*/
SK_API int sk_path_count_verbs(const sk_path_t* cpath);

/**
	Create a new path iterator.
*/
SK_API sk_path_iter_t* sk_path_iter_new(const sk_path_t* cpath);

/**
	Delete the path iterator.
*/
SK_API void sk_path_iter_delete(sk_path_iter_t* citer);

/** Return the next verb in this iteration of the path. When all
segments have been visited, return kDone_Verb.

@param  pts The points representing the current verb and/or segment
This must not be NULL.
@return The verb for the current segment
*/
SK_API sk_path_verb_t sk_path_iter_next(sk_path_iter_t *citer, sk_point_t cpts[4]);

/** Return what the next verb will be, but do not visit the next segment.

@return The verb for the next segment
*/
SK_API sk_path_verb_t sk_path_iter_peek(const sk_path_iter_t *citer);

/**
*  Return the weight for the current conic. Only valid if the current
*  segment return by next() was a conic.
*/
SK_API float sk_path_iter_conic_weight(const sk_path_iter_t *citer);

SK_C_PLUS_PLUS_END_GUARD

#endif
