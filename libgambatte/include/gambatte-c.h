//
//   Copyright (C) 2007 by sinamas <sinamas at users.sourceforge.net>
//
//   This program is free software; you can redistribute it and/or modify
//   it under the terms of the GNU General Public License version 2 as
//   published by the Free Software Foundation.
//
//   This program is distributed in the hope that it will be useful,
//   but WITHOUT ANY WARRANTY; without even the implied warranty of
//   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//   GNU General Public License version 2 for more details.
//
//   You should have received a copy of the GNU General Public License
//   version 2 along with this program; if not, write to the
//   Free Software Foundation, Inc.,
//   51 Franklin St, Fifth Floor, Boston, MA  02110-1301, USA.
//

#ifndef GAMBATTE_C_H
#define GAMBATTE_C_H

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifdef __cplusplus
typedef gambatte::GB gambatte_c;
#else
typedef struct gambatte_c gambatte_c;
#endif

gambatte_c* gambatte_init();
void gambatte_destroy(gambatte_c* gb);

int gambatte_load(gambatte_c* gb, const char* romfile);
ptrdiff_t gambatte_run(gambatte_c* gb, void* video, ptrdiff_t pitch, void* audio, size_t* samples);

unsigned gambatte_get_input(gambatte_c* gb);
void gambatte_set_input(gambatte_c* gb, unsigned input);

#ifdef __cplusplus
}
#endif

#endif
