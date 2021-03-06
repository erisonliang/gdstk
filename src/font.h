/*
Copyright 2020 Lucas Heitzmann Gabrielli.
This file is part of gdstk, distributed under the terms of the
Boost Software License - Version 1.0.  See the accompanying
LICENSE file or <http://www.boost.org/LICENSE_1_0.txt>
*/

#ifndef GDSTK_HEADER_FONT
#define GDSTK_HEADER_FONT

// This header contains the data for the default font in Gdstk, used in the text function.
// Given a desired code point CP within the range of defined code points, we use it to index
// into arrays _num_polys and _first_poly:
//
// _num_poly[CP - FIRST_CODEPOINT] = p_count is the number of polygons in the requested glyph.
// _first_poly[CP - FIRST_CODEPOINT] = p_idx is the index into _num_coords and _first_coord.
//
// _num_coords[p_idx] = c_count is the number of coordinates in polygon p_idx (counting x and y
// separately, so it is always an even number). The polygon p_idx can be drawn using
// c_count coordinates from _first_coord:
// (_first_coord[p_idx], _first_coord[p_idx + 1], …, _first_coord[p_idx + c_count - 1])
//
// To draw the remaining polygons in the glyph, keep incrementing p_idx to draw all p_count
// polygons.

// Font metrics
#define FIRST_CODEPOINT 0x21
#define HORIZONTAL_STEP 9
#define HORIZONTAL_TAB (4 * HORIZONTAL_STEP)
#define HORIZONTAL_LINESKIP 20
#define VERTICAL_STEP (2 * HORIZONTAL_STEP)
#define VERTICAL_TAB (4 * VERTICAL_STEP)
#define VERTICAL_LINESKIP 16

namespace gdstk {

// Public Domain version of the unscii-16 font from http://pelulamu.net/unscii/
// codepoints 0x21 thru 0x7F

const Vec2 _all_coords[] = {
    5, 7,  5, 15, 3, 15, 3, 7,  5, 3,  5, 5,  3, 5,  3, 3,  3, 12, 3, 15, 1, 15, 1, 12, 7, 12,
    7, 15, 5, 15, 5, 12, 3, 3,  3, 6,  4, 6,  4, 3,  6, 3,  6, 6,  7, 6,  7, 7,  6, 7,  6, 10,
    7, 10, 7, 11, 6, 11, 6, 14, 4, 14, 4, 11, 3, 11, 3, 14, 1, 14, 1, 11, 0, 11, 0, 10, 1, 10,
    1, 7,  3, 7,  3, 10, 4, 10, 4, 7,  3, 7,  1, 7,  0, 7,  0, 6,  1, 6,  1, 3,  2, 4,  3, 4,
    3, 2,  5, 2,  5, 4,  6, 4,  6, 5,  7, 5,  7, 7,  6, 7,  6, 8,  5, 8,  5, 9,  4, 9,  4, 10,
    3, 10, 3, 12, 5, 12, 5, 11, 7, 11, 7, 12, 6, 12, 6, 13, 5, 13, 5, 15, 3, 15, 3, 13, 2, 13,
    2, 12, 1, 12, 1, 10, 2, 10, 2, 9,  3, 9,  3, 8,  4, 8,  4, 7,  5, 7,  5, 5,  3, 5,  3, 6,
    1, 6,  1, 5,  2, 5,  4, 12, 4, 10, 3, 10, 3, 8,  2, 8,  2, 6,  1, 6,  1, 4,  0, 4,  0, 2,
    2, 2,  2, 4,  3, 4,  3, 6,  4, 6,  4, 8,  5, 8,  5, 10, 6, 10, 6, 12, 7, 12, 7, 14, 5, 14,
    5, 12, 2, 10, 2, 13, 0, 13, 0, 10, 7, 3,  7, 6,  5, 6,  5, 3,  1, 9,  1, 8,  0, 8,  0, 4,
    1, 4,  1, 3,  4, 3,  4, 4,  2, 4,  2, 8,  3, 8,  3, 7,  4, 7,  4, 4,  5, 4,  5, 3,  7, 3,
    7, 4,  6, 4,  6, 7,  7, 7,  7, 9,  6, 9,  6, 8,  5, 8,  5, 9,  4, 9,  4, 10, 5, 10, 5, 11,
    6, 11, 6, 13, 5, 13, 5, 14, 2, 14, 2, 13, 1, 13, 1, 11, 3, 11, 3, 13, 4, 13, 4, 11, 3, 11,
    1, 11, 2, 11, 2, 9,  2, 12, 2, 11, 4, 11, 4, 12, 5, 12, 5, 15, 3, 15, 3, 12, 3, 12, 2, 12,
    2, 5,  3, 5,  3, 3,  4, 3,  4, 2,  6, 2,  6, 3,  5, 3,  5, 5,  4, 5,  4, 12, 5, 12, 5, 14,
    6, 14, 6, 15, 4, 15, 4, 14, 3, 14, 3, 12, 4, 12, 4, 5,  3, 5,  3, 3,  2, 3,  2, 2,  4, 2,
    4, 3,  5, 3,  5, 5,  6, 5,  6, 12, 5, 12, 5, 14, 4, 14, 4, 15, 2, 15, 2, 14, 3, 14, 2, 10,
    2, 9,  0, 9,  0, 8,  2, 8,  2, 7,  1, 7,  1, 5,  3, 5,  3, 7,  5, 7,  5, 5,  7, 5,  7, 7,
    6, 7,  6, 8,  8, 8,  8, 9,  6, 9,  6, 10, 7, 10, 7, 12, 5, 12, 5, 10, 3, 10, 3, 12, 1, 12,
    1, 10, 1, 9,  1, 8,  3, 8,  3, 5,  5, 5,  5, 8,  7, 8,  7, 9,  5, 9,  5, 12, 3, 12, 3, 9,
    3, 3,  2, 3,  2, 2,  1, 2,  1, 1,  3, 1,  3, 2,  4, 2,  4, 3,  5, 3,  5, 6,  2, 6,  2, 5,
    3, 5,  7, 9,  1, 9,  1, 8,  7, 8,  5, 3,  5, 6,  3, 6,  3, 3,  5, 14, 5, 12, 4, 12, 4, 10,
    3, 10, 3, 8,  2, 8,  2, 6,  1, 6,  1, 4,  0, 4,  0, 2,  2, 2,  2, 4,  3, 4,  3, 6,  4, 6,
    4, 8,  5, 8,  5, 10, 6, 10, 6, 12, 7, 12, 7, 14, 8, 14, 8, 16, 6, 16, 6, 14, 6, 5,  7, 5,
    7, 12, 6, 12, 6, 13, 5, 13, 5, 14, 2, 14, 2, 13, 1, 13, 1, 12, 0, 12, 0, 5,  2, 5,  2, 7,
    3, 7,  3, 8,  2, 8,  2, 12, 3, 12, 3, 13, 4, 13, 4, 12, 5, 12, 5, 10, 4, 10, 4, 9,  5, 9,
    5, 5,  4, 5,  4, 4,  3, 4,  3, 5,  2, 5,  0, 5,  1, 5,  1, 4,  2, 4,  2, 3,  5, 3,  5, 4,
    6, 4,  4, 9,  3, 9,  3, 8,  4, 8,  2, 12, 1, 12, 1, 11, 3, 11, 3, 4,  1, 4,  1, 3,  7, 3,
    7, 4,  5, 4,  5, 14, 3, 14, 3, 13, 2, 13, 1, 11, 3, 11, 3, 13, 5, 13, 5, 9,  4, 9,  4, 8,
    3, 8,  3, 7,  2, 7,  2, 6,  1, 6,  1, 3,  7, 3,  7, 4,  3, 4,  3, 6,  4, 6,  4, 7,  5, 7,
    5, 8,  6, 8,  6, 9,  7, 9,  7, 13, 6, 13, 6, 14, 2, 14, 2, 13, 1, 13, 2, 4,  2, 3,  6, 3,
    6, 4,  7, 4,  7, 8,  6, 8,  6, 9,  7, 9,  7, 13, 6, 13, 6, 14, 2, 14, 2, 13, 1, 13, 1, 11,
    3, 11, 3, 13, 5, 13, 5, 9,  3, 9,  3, 8,  5, 8,  5, 4,  3, 4,  3, 6,  1, 6,  1, 4,  6, 3,
    6, 7,  7, 7,  7, 8,  6, 8,  6, 14, 4, 14, 4, 13, 3, 13, 3, 12, 2, 12, 2, 11, 1, 11, 1, 10,
    0, 10, 0, 8,  2, 8,  2, 10, 3, 10, 3, 11, 4, 11, 4, 8,  2, 8,  0, 8,  0, 7,  4, 7,  4, 3,
    2, 4,  2, 3,  6, 3,  6, 4,  7, 4,  7, 9,  6, 9,  6, 10, 3, 10, 3, 13, 7, 13, 7, 14, 1, 14,
    1, 9,  5, 9,  5, 4,  3, 4,  3, 6,  1, 6,  1, 4,  7, 9,  6, 9,  6, 10, 3, 10, 3, 12, 4, 12,
    4, 13, 6, 13, 6, 14, 3, 14, 3, 13, 2, 13, 2, 12, 1, 12, 1, 4,  3, 4,  3, 9,  5, 9,  5, 4,
    3, 4,  1, 4,  2, 4,  2, 3,  6, 3,  6, 4,  7, 4,  5, 10, 4, 10, 4, 8,  3, 8,  3, 3,  5, 3,
    5, 8,  6, 8,  6, 10, 7, 10, 7, 14, 1, 14, 1, 13, 5, 13, 7, 8,  6, 8,  6, 9,  7, 9,  7, 13,
    6, 13, 6, 14, 2, 14, 2, 13, 1, 13, 1, 10, 3, 10, 3, 13, 5, 13, 5, 9,  4, 9,  4, 10, 3, 10,
    1, 10, 1, 9,  2, 9,  2, 8,  1, 8,  1, 4,  3, 4,  3, 8,  4, 8,  4, 7,  5, 7,  5, 4,  3, 4,
    1, 4,  2, 4,  2, 3,  6, 3,  6, 4,  7, 4,  5, 5,  4, 5,  4, 4,  2, 4,  2, 3,  5, 3,  5, 4,
    6, 4,  6, 5,  7, 5,  7, 13, 6, 13, 6, 14, 2, 14, 2, 13, 1, 13, 1, 9,  3, 9,  3, 13, 5, 13,
    5, 9,  3, 9,  1, 9,  2, 9,  2, 8,  5, 8,  5, 10, 5, 13, 3, 13, 3, 10, 5, 3,  5, 6,  3, 6,
    3, 3,  5, 10, 5, 13, 3, 13, 3, 10, 3, 3,  2, 3,  2, 2,  1, 2,  1, 1,  3, 1,  3, 2,  4, 2,
    4, 3,  5, 3,  5, 6,  2, 6,  2, 5,  3, 5,  4, 11, 3, 11, 3, 10, 2, 10, 2, 9,  1, 9,  1, 8,
    2, 8,  2, 7,  3, 7,  3, 6,  4, 6,  4, 5,  5, 5,  5, 4,  7, 4,  7, 5,  6, 5,  6, 6,  5, 6,
    5, 7,  4, 7,  4, 8,  3, 8,  3, 9,  4, 9,  4, 10, 5, 10, 5, 11, 6, 11, 6, 12, 7, 12, 7, 13,
    5, 13, 5, 12, 4, 12, 7, 11, 1, 11, 1, 10, 7, 10, 7, 7,  1, 7,  1, 6,  7, 6,  2, 11, 3, 11,
    3, 10, 4, 10, 4, 9,  5, 9,  5, 8,  4, 8,  4, 7,  3, 7,  3, 6,  2, 6,  2, 5,  1, 5,  1, 4,
    3, 4,  3, 5,  4, 5,  4, 6,  5, 6,  5, 7,  6, 7,  6, 8,  7, 8,  7, 9,  6, 9,  6, 10, 5, 10,
    5, 11, 4, 11, 4, 12, 3, 12, 3, 13, 1, 13, 1, 12, 2, 12, 1, 12, 3, 12, 3, 14, 5, 14, 5, 11,
    4, 11, 4, 10, 3, 10, 3, 7,  5, 7,  5, 10, 6, 10, 6, 11, 7, 11, 7, 14, 6, 14, 6, 15, 2, 15,
    2, 14, 1, 14, 5, 3,  5, 5,  3, 5,  3, 3,  0, 4,  1, 4,  1, 3,  6, 3,  6, 4,  2, 4,  2, 13,
    5, 13, 5, 10, 3, 10, 3, 6,  6, 6,  6, 7,  7, 7,  7, 13, 6, 13, 6, 14, 1, 14, 1, 13, 0, 13,
    3, 3,  3, 8,  5, 8,  5, 3,  7, 3,  7, 12, 6, 12, 6, 13, 5, 13, 5, 14, 3, 14, 3, 13, 2, 13,
    2, 12, 1, 12, 1, 9,  3, 9,  3, 12, 5, 12, 5, 9,  3, 9,  1, 9,  1, 3,  7, 7,  6, 7,  6, 8,
    5, 8,  5, 9,  6, 9,  6, 10, 7, 10, 7, 13, 6, 13, 6, 14, 1, 14, 1, 9,  3, 9,  3, 13, 5, 13,
    5, 10, 4, 10, 4, 9,  3, 9,  1, 9,  1, 4,  3, 4,  3, 8,  4, 8,  4, 7,  5, 7,  5, 4,  3, 4,
    1, 4,  1, 3,  6, 3,  6, 4,  7, 4,  1, 4,  2, 4,  2, 3,  6, 3,  6, 4,  7, 4,  7, 6,  5, 6,
    5, 4,  3, 4,  3, 13, 5, 13, 5, 11, 7, 11, 7, 13, 6, 13, 6, 14, 2, 14, 2, 13, 1, 13, 6, 5,
    7, 5,  7, 12, 6, 12, 6, 13, 5, 13, 5, 14, 1, 14, 1, 4,  3, 4,  3, 13, 4, 13, 4, 12, 5, 12,
    5, 5,  4, 5,  4, 4,  3, 4,  1, 4,  1, 3,  5, 3,  5, 4,  6, 4,  7, 3,  7, 4,  3, 4,  3, 8,
    6, 8,  6, 9,  3, 9,  3, 13, 7, 13, 7, 14, 1, 14, 1, 3,  3, 3,  3, 9,  6, 9,  6, 10, 3, 10,
    3, 13, 7, 13, 7, 14, 1, 14, 1, 3,  1, 4,  2, 4,  2, 3,  7, 3,  7, 9,  4, 9,  4, 8,  5, 8,
    5, 4,  3, 4,  3, 13, 5, 13, 5, 11, 7, 11, 7, 13, 6, 13, 6, 14, 2, 14, 2, 13, 1, 13, 3, 3,
    3, 8,  5, 8,  5, 3,  7, 3,  7, 14, 5, 14, 5, 9,  3, 9,  3, 14, 1, 14, 1, 3,  1, 4,  1, 3,
    7, 3,  7, 4,  5, 4,  5, 13, 7, 13, 7, 14, 1, 14, 1, 13, 3, 13, 3, 4,  2, 4,  2, 3,  6, 3,
    6, 4,  7, 4,  7, 14, 5, 14, 5, 4,  3, 4,  3, 6,  1, 6,  1, 4,  2, 3,  2, 8,  3, 8,  3, 7,
    4, 7,  4, 5,  5, 5,  5, 3,  7, 3,  7, 5,  6, 5,  6, 7,  5, 7,  5, 8,  4, 8,  4, 9,  5, 9,
    5, 10, 6, 10, 6, 12, 7, 12, 7, 14, 5, 14, 5, 12, 4, 12, 4, 10, 3, 10, 3, 9,  2, 9,  2, 14,
    0, 14, 0, 3,  7, 3,  7, 4,  3, 4,  3, 14, 1, 14, 1, 3,  2, 3,  2, 10, 3, 10, 3, 8,  4, 8,
    4, 10, 5, 10, 5, 3,  7, 3,  7, 14, 5, 14, 5, 13, 4, 13, 4, 11, 3, 11, 3, 13, 2, 13, 2, 14,
    0, 14, 0, 3,  2, 3,  2, 8,  3, 8,  3, 7,  4, 7,  4, 5,  5, 5,  5, 3,  7, 3,  7, 14, 5, 14,
    5, 9,  4, 9,  4, 10, 3, 10, 3, 12, 2, 12, 2, 14, 0, 14, 0, 3,  7, 13, 6, 13, 6, 14, 2, 14,
    2, 13, 1, 13, 1, 4,  3, 4,  3, 13, 5, 13, 5, 4,  3, 4,  1, 4,  2, 4,  2, 3,  6, 3,  6, 4,
    7, 4,  3, 3,  3, 8,  6, 8,  6, 9,  7, 9,  7, 13, 6, 13, 6, 14, 1, 14, 1, 9,  3, 9,  3, 13,
    5, 13, 5, 9,  3, 9,  1, 9,  1, 3,  4, 2,  5, 2,  5, 1,  7, 1,  7, 2,  6, 2,  6, 4,  7, 4,
    7, 13, 6, 13, 6, 14, 2, 14, 2, 13, 1, 13, 1, 4,  3, 4,  3, 13, 5, 13, 5, 4,  3, 4,  1, 4,
    2, 4,  2, 3,  4, 3,  3, 3,  3, 8,  4, 8,  4, 7,  5, 7,  5, 3,  7, 3,  7, 7,  6, 7,  6, 9,
    7, 9,  7, 13, 6, 13, 6, 14, 1, 14, 1, 9,  3, 9,  3, 13, 5, 13, 5, 9,  3, 9,  1, 9,  1, 3,
    2, 4,  2, 3,  6, 3,  6, 4,  7, 4,  7, 7,  6, 7,  6, 8,  5, 8,  5, 9,  4, 9,  4, 10, 3, 10,
    3, 13, 5, 13, 5, 11, 7, 11, 7, 13, 6, 13, 6, 14, 2, 14, 2, 13, 1, 13, 1, 10, 2, 10, 2, 9,
    3, 9,  3, 8,  4, 8,  4, 7,  5, 7,  5, 4,  3, 4,  3, 6,  1, 6,  1, 4,  5, 3,  5, 13, 7, 13,
    7, 14, 1, 14, 1, 13, 3, 13, 3, 3,  2, 4,  2, 3,  6, 3,  6, 4,  7, 4,  7, 14, 5, 14, 5, 4,
    3, 4,  3, 14, 1, 14, 1, 4,  2, 7,  2, 5,  3, 5,  3, 3,  5, 3,  5, 5,  6, 5,  6, 7,  7, 7,
    7, 14, 5, 14, 5, 7,  3, 7,  3, 14, 1, 14, 1, 7,  2, 3,  2, 4,  3, 4,  3, 6,  4, 6,  4, 4,
    5, 4,  5, 3,  7, 3,  7, 14, 5, 14, 5, 7,  4, 7,  4, 9,  3, 9,  3, 7,  2, 7,  2, 14, 0, 14,
    0, 3,  1, 12, 1, 11, 2, 11, 2, 10, 3, 10, 3, 7,  2, 7,  2, 6,  1, 6,  1, 5,  0, 5,  0, 3,
    2, 3,  2, 5,  3, 5,  3, 6,  5, 6,  5, 5,  6, 5,  6, 3,  8, 3,  8, 5,  7, 5,  7, 6,  6, 6,
    6, 7,  5, 7,  5, 10, 6, 10, 6, 11, 7, 11, 7, 12, 8, 12, 8, 14, 6, 14, 6, 12, 5, 12, 5, 11,
    3, 11, 3, 12, 2, 12, 2, 14, 0, 14, 0, 12, 1, 12, 1, 10, 2, 10, 2, 9,  3, 9,  3, 3,  5, 3,
    5, 9,  6, 9,  6, 10, 7, 10, 7, 12, 8, 12, 8, 14, 6, 14, 6, 12, 5, 12, 5, 10, 3, 10, 3, 12,
    2, 12, 2, 14, 0, 14, 0, 12, 5, 11, 4, 11, 4, 9,  3, 9,  3, 8,  2, 8,  2, 6,  1, 6,  1, 3,
    7, 3,  7, 4,  3, 4,  3, 6,  4, 6,  4, 8,  5, 8,  5, 9,  6, 9,  6, 11, 7, 11, 7, 14, 1, 14,
    1, 13, 5, 13, 6, 2,  6, 3,  4, 3,  4, 14, 6, 14, 6, 15, 2, 15, 2, 2,  1, 14, 1, 12, 2, 12,
    2, 10, 3, 10, 3, 8,  4, 8,  4, 6,  5, 6,  5, 4,  6, 4,  6, 2,  8, 2,  8, 4,  7, 4,  7, 6,
    6, 6,  6, 8,  5, 8,  5, 10, 4, 10, 4, 12, 3, 12, 3, 14, 2, 14, 2, 16, 0, 16, 0, 14, 4, 3,
    2, 3,  2, 2,  6, 2,  6, 15, 2, 15, 2, 14, 4, 14, 2, 13, 1, 13, 1, 11, 0, 11, 0, 9,  2, 9,
    2, 11, 3, 11, 3, 13, 4, 13, 4, 11, 5, 11, 5, 9,  7, 9,  7, 11, 6, 11, 6, 13, 5, 13, 5, 14,
    4, 14, 4, 15, 3, 15, 3, 14, 2, 14, 8, 1,  0, 1,  0, 0,  8, 0,  4, 13, 4, 12, 5, 12, 5, 11,
    7, 11, 7, 12, 6, 12, 6, 13, 5, 13, 5, 15, 3, 15, 3, 13, 6, 9,  6, 10, 2, 10, 2, 9,  5, 9,
    5, 8,  2, 8,  2, 7,  1, 7,  1, 4,  3, 4,  3, 7,  5, 7,  5, 4,  3, 4,  1, 4,  2, 4,  2, 3,
    7, 3,  7, 9,  7, 9,  6, 9,  6, 10, 3, 10, 3, 14, 1, 14, 1, 4,  3, 4,  3, 9,  5, 9,  5, 4,
    3, 4,  1, 4,  1, 3,  6, 3,  6, 4,  7, 4,  1, 4,  2, 4,  2, 3,  6, 3,  6, 4,  7, 4,  7, 5,
    5, 5,  5, 4,  3, 4,  3, 9,  5, 9,  5, 8,  7, 8,  7, 9,  6, 9,  6, 10, 2, 10, 2, 9,  1, 9,
    5, 14, 5, 10, 2, 10, 2, 9,  1, 9,  1, 4,  3, 4,  3, 9,  5, 9,  5, 4,  3, 4,  1, 4,  2, 4,
    2, 3,  7, 3,  7, 14, 2, 4,  2, 3,  6, 3,  6, 4,  3, 4,  3, 6,  7, 6,  7, 9,  6, 9,  6, 10,
    2, 10, 2, 9,  1, 9,  1, 7,  3, 7,  3, 9,  5, 9,  5, 7,  3, 7,  1, 7,  1, 4,  2, 10, 1, 10,
    1, 9,  2, 9,  2, 3,  4, 3,  4, 9,  7, 9,  7, 10, 4, 10, 4, 13, 7, 13, 7, 14, 3, 14, 3, 13,
    2, 13, 5, 1,  1, 1,  1, 0,  6, 0,  6, 1,  7, 1,  7, 10, 2, 10, 2, 9,  1, 9,  1, 4,  3, 4,
    3, 9,  5, 9,  5, 4,  3, 4,  1, 4,  2, 4,  2, 3,  5, 3,  3, 3,  3, 9,  5, 9,  5, 3,  7, 3,
    7, 9,  6, 9,  6, 10, 3, 10, 3, 14, 1, 14, 1, 3,  5, 12, 5, 14, 3, 14, 3, 12, 3, 3,  7, 3,
    7, 4,  5, 4,  5, 10, 1, 10, 1, 9,  3, 9,  6, 12, 6, 14, 4, 14, 4, 12, 1, 1,  1, 0,  5, 0,
    5, 1,  6, 1,  6, 10, 4, 10, 4, 1,  3, 3,  3, 6,  4, 6,  4, 5,  5, 5,  5, 3,  7, 3,  7, 5,
    6, 5,  6, 6,  5, 6,  5, 7,  6, 7,  6, 8,  7, 8,  7, 10, 5, 10, 5, 8,  4, 8,  4, 7,  3, 7,
    3, 14, 1, 14, 1, 3,  3, 3,  7, 3,  7, 4,  5, 4,  5, 14, 1, 14, 1, 13, 3, 13, 2, 3,  2, 8,
    3, 8,  3, 4,  4, 4,  4, 8,  5, 8,  5, 3,  7, 3,  7, 9,  6, 9,  6, 10, 4, 10, 4, 9,  2, 9,
    2, 10, 0, 10, 0, 3,  3, 3,  3, 9,  5, 9,  5, 3,  7, 3,  7, 9,  6, 9,  6, 10, 1, 10, 1, 3,
    7, 9,  6, 9,  6, 10, 2, 10, 2, 9,  1, 9,  1, 4,  3, 4,  3, 9,  5, 9,  5, 4,  3, 4,  1, 4,
    2, 4,  2, 3,  6, 3,  6, 4,  7, 4,  3, 0,  3, 3,  6, 3,  6, 4,  7, 4,  7, 9,  6, 9,  6, 10,
    1, 10, 1, 4,  3, 4,  3, 9,  5, 9,  5, 4,  3, 4,  1, 4,  1, 0,  5, 0,  7, 0,  7, 10, 2, 10,
    2, 9,  1, 9,  1, 4,  3, 4,  3, 9,  5, 9,  5, 4,  3, 4,  1, 4,  2, 4,  2, 3,  5, 3,  3, 3,
    3, 9,  5, 9,  5, 7,  7, 7,  7, 9,  6, 9,  6, 10, 1, 10, 1, 3,  1, 7,  2, 7,  2, 6,  5, 6,
    5, 4,  1, 4,  1, 3,  6, 3,  6, 4,  7, 4,  7, 6,  6, 6,  6, 7,  3, 7,  3, 9,  7, 9,  7, 10,
    2, 10, 2, 9,  1, 9,  1, 10, 1, 9,  2, 9,  2, 4,  3, 4,  3, 3,  7, 3,  7, 4,  4, 4,  4, 9,
    7, 9,  7, 10, 4, 10, 4, 13, 2, 13, 2, 10, 2, 4,  2, 3,  7, 3,  7, 10, 5, 10, 5, 4,  3, 4,
    3, 10, 1, 10, 1, 4,  2, 5,  2, 4,  3, 4,  3, 3,  5, 3,  5, 4,  6, 4,  6, 5,  7, 5,  7, 10,
    5, 10, 5, 5,  3, 5,  3, 10, 1, 10, 1, 5,  1, 5,  1, 3,  3, 3,  3, 4,  4, 4,  4, 3,  6, 3,
    6, 5,  7, 5,  7, 10, 5, 10, 5, 5,  4, 5,  4, 8,  3, 8,  3, 5,  2, 5,  2, 10, 0, 10, 0, 5,
    1, 8,  1, 7,  2, 7,  2, 6,  1, 6,  1, 5,  0, 5,  0, 3,  2, 3,  2, 5,  3, 5,  3, 6,  4, 6,
    4, 5,  5, 5,  5, 3,  7, 3,  7, 5,  6, 5,  6, 6,  5, 6,  5, 7,  6, 7,  6, 8,  7, 8,  7, 10,
    5, 10, 5, 8,  4, 8,  4, 7,  3, 7,  3, 8,  2, 8,  2, 10, 0, 10, 0, 8,  2, 4,  2, 3,  5, 3,
    5, 1,  2, 1,  2, 0,  6, 0,  6, 1,  7, 1,  7, 10, 5, 10, 5, 4,  3, 4,  3, 10, 1, 10, 1, 4,
    5, 8,  4, 8,  4, 7,  3, 7,  3, 6,  2, 6,  2, 5,  1, 5,  1, 3,  7, 3,  7, 4,  3, 4,  3, 5,
    4, 5,  4, 6,  5, 6,  5, 7,  6, 7,  6, 8,  7, 8,  7, 10, 1, 10, 1, 9,  5, 9,  3, 9,  0, 9,
    0, 8,  3, 8,  3, 3,  4, 3,  4, 2,  7, 2,  7, 3,  5, 3,  5, 8,  4, 8,  4, 9,  5, 9,  5, 14,
    7, 14, 7, 15, 4, 15, 4, 14, 3, 14, 5, 2,  5, 16, 3, 16, 3, 2,  2, 9,  3, 9,  3, 8,  2, 8,
    2, 3,  0, 3,  0, 2,  3, 2,  3, 3,  4, 3,  4, 8,  7, 8,  7, 9,  4, 9,  4, 14, 3, 14, 3, 15,
    0, 15, 0, 14, 2, 14, 0, 12, 1, 12, 1, 13, 2, 13, 2, 14, 3, 14, 3, 12, 6, 12, 6, 13, 7, 13,
    7, 15, 6, 15, 6, 14, 5, 14, 5, 13, 4, 13, 4, 15, 1, 15, 1, 14, 0, 14, 2, 6,  2, 8,  1, 8,
    1, 14, 2, 14, 2, 16, 0, 16, 0, 6,  3, 8,  3, 14, 2, 14, 2, 8,  5, 10, 5, 2,  6, 2,  6, 10,
    7, 10, 7, 12, 4, 12, 4, 10,
};

uint16_t _first_poly[] = {
    0,  2,  4,  5,  6,  9,  10, 11, 12, 13,  14,  15,  16,  17,  18,  19,  21, 22, 23, 24,
    25, 26, 27, 28, 29, 30, 32, 34, 35, 37,  38,  40,  41,  42,  43,  44,  45, 46, 47, 48,
    49, 50, 51, 52, 53, 54, 55, 56, 57, 58,  59,  60,  61,  62,  63,  64,  65, 66, 67, 68,
    69, 70, 71, 72, 73, 74, 75, 76, 77, 78,  79,  80,  81,  83,  85,  86,  87, 88, 89, 90,
    91, 92, 93, 94, 95, 96, 97, 98, 99, 100, 101, 102, 103, 104, 105, 108,
};

uint16_t _num_polys[] = {
    2, 2, 1, 1, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 1, 2, 1, 2, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 0,
};

uint16_t _first_coord[] = {
    0,    4,    8,    12,   16,   50,   94,   118,  122,  126,  172,  180,  200,  220,  248,  260,
    274,  278,  282,  310,  352,  356,  370,  400,  428,  455,  475,  501,  515,  552,  578,  582,
    586,  590,  604,  640,  644,  648,  684,  704,  708,  728,  751,  785,  805,  828,  840,  850,
    870,  882,  894,  906,  938,  944,  964,  984,  1002, 1019, 1043, 1066, 1102, 1110, 1122, 1138,
    1158, 1202, 1226, 1250, 1258, 1286, 1294, 1318, 1322, 1334, 1354, 1371, 1391, 1407, 1428, 1444,
    1464, 1476, 1480, 1488, 1492, 1500, 1524, 1532, 1550, 1560, 1578, 1595, 1611, 1621, 1641, 1657,
    1667, 1683, 1703, 1739, 1755, 1779, 1799, 1803, 1823, 1843, 1851, 1855,
};

uint16_t _num_coords[] = {
    4,  4,  4,  4,  34, 44, 24, 4,  4,  46, 8,  20, 20, 28, 12, 14, 4,  4,  28, 42, 4,  14,
    30, 28, 27, 20, 26, 14, 37, 26, 4,  4,  4,  14, 36, 4,  4,  36, 20, 4,  20, 23, 34, 20,
    23, 12, 10, 20, 12, 12, 12, 32, 6,  20, 20, 18, 17, 24, 23, 36, 8,  12, 16, 20, 44, 24,
    24, 8,  28, 8,  24, 4,  12, 20, 17, 20, 16, 21, 16, 20, 12, 4,  8,  4,  8,  24, 8,  18,
    10, 18, 17, 16, 10, 20, 16, 10, 16, 20, 36, 16, 24, 20, 4,  20, 20, 8,  4,  8,
};

}  // namespace gdstk

#endif
