/*
 * Copyright 2014 Google Inc.
 *
 * Use of this source code is governed by a BSD-style license that can be
 * found in the LICENSE file.
 */

// EXPERIMENTAL EXPERIMENTAL EXPERIMENTAL EXPERIMENTAL
// DO NOT USE -- FOR INTERNAL TESTING ONLY

#ifndef sk_dash_path_effect_DEFINED
#define sk_dash_path_effect_DEFINED

#include "sk_types.h"

SK_C_PLUS_PLUS_BEGIN_GUARD

/** Create a new dash_path_effect with intervals containing an even number of entries (>=2). */
SK_API sk_dash_path_effect_t* sk_dash_path_effect_create(const float intervals[], int count, float phase);

/** Release the memory used by a sk_dash_path_effect_t. */
SK_API void sk_dash_path_effect_unref(sk_dash_path_effect_t* cpathEffect);

SK_C_PLUS_PLUS_END_GUARD

#endif
