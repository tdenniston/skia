/*
 * Copyright 2016 Xamarin Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

#include "SkPath.h"

#include "xamarin/sk_x_path.h"

#include "../sk_types_priv.h"
#include "sk_x_types_priv.h"

void sk_path_rmove_to(sk_path_t* cpath, float dx, float dy) {
    as_path(cpath)->rMoveTo(dx, dy);
}

void sk_path_rline_to(sk_path_t* cpath, float dx, float dy) {
    as_path(cpath)->rLineTo(dx, dy);
}

void sk_path_rquad_to(sk_path_t* cpath, float dx0, float dy0, float dx1, float dy1) {
    as_path(cpath)->rQuadTo(dx0, dy0, dx1, dy1);
}

void sk_path_rconic_to(sk_path_t* cpath, float dx0, float dy0, float dx1, float dy1, float w) {
    as_path(cpath)->rConicTo(dx0, dy0, dx1, dy1, w);
}

void sk_path_rcubic_to(sk_path_t* cpath, float dx0, float dy0, float dx1, float dy1, float dx2, float dy2) {
    as_path(cpath)->rCubicTo(dx0, dy0, dx1, dy1, dx2, dy2);
}

void sk_path_add_rect_start(sk_path_t* cpath, const sk_rect_t* crect, sk_path_direction_t cdir, uint32_t startIndex) {
    SkPath::Direction dir;
    if (!find_sk(cdir, &dir)) {
        return;
    }
    as_path(cpath)->addRect(AsRect(*crect), dir, startIndex);
}

void sk_path_add_arc(sk_path_t* cpath, const sk_rect_t* crect, float startAngle, float sweepAngle) {
    as_path(cpath)->addArc(AsRect(*crect), startAngle, sweepAngle);
}

void sk_path_set_filltype(sk_path_t* cpath, sk_path_filltype_t cfilltype) {
    SkPath::FillType filltype;
    if (!find_sk(cfilltype, &filltype)) {
        return;
    }
    as_path(cpath)->setFillType(filltype);
}

sk_path_filltype_t sk_path_get_filltype(sk_path_t *cpath) {
    sk_path_filltype_t cfilltype; 
    if (!find_c(as_path(cpath)->getFillType(), &cfilltype)) {
        cfilltype = WINDING_SK_PATH_FILLTYPE;
    }
    return cfilltype;
}

void sk_path_transform(sk_path_t* cpath, const sk_matrix_t* cmatrix)
{
    SkMatrix matrix;
    if (cmatrix) {
        from_c(cmatrix, &matrix);
    }
    return as_path(cpath)->transform(matrix);
}

sk_path_t* sk_path_clone(const sk_path_t* cpath)
{
    return (sk_path_t*)new SkPath(AsPath(*cpath));
}

int sk_path_count_verbs(const sk_path_t* cpath)
{
    return AsPath(*cpath).countVerbs();
}

sk_path_iter_t* sk_path_iter_new(const sk_path_t* cpath)
{
	SkPath::RawIter* iter = new SkPath::RawIter(AsPath(*cpath));
	return ToPathIter(iter);
}

void sk_path_iter_delete(sk_path_iter_t* citer)
{
	delete AsPathIter(citer);
}

sk_path_verb_t sk_path_iter_next(sk_path_iter_t* citer, sk_point_t cpts[4])
{
	SkPath::RawIter *iter = AsPathIter(citer);
	SkPoint *pts = AsPoint(cpts);
	SkPath::Verb verb = iter->next(pts);
	return (sk_path_verb_t)verb;
}

sk_path_verb_t sk_path_iter_peek(const sk_path_iter_t* citer)
{
	const SkPath::RawIter *iter = AsPathIter(citer);
	return (sk_path_verb_t)iter->peek();
}

float sk_path_iter_conic_weight(const sk_path_iter_t* citer)
{
	const SkPath::RawIter *iter = AsPathIter(citer);
	return iter->conicWeight();
}
