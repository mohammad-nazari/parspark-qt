/* fonts/upcean_ttf.h - OCR-B TrueType (EAN/UPC subset) as static array */
/*
    libzint - the open source barcode library
    Copyright (C) 2023 Robin Stuart <rstuart114@gmail.com>

    Redistribution and use in source and binary forms, with or without
    modification, are permitted provided that the following conditions
    are met:

    1. Redistributions of source code must retain the above copyright
       notice, this list of conditions and the following disclaimer.
    2. Redistributions in binary form must reproduce the above copyright
       notice, this list of conditions and the following disclaimer in the
       documentation and/or other materials provided with the distribution.
    3. Neither the name of the project nor the names of its contributors
       may be used to endorse or promote products derived from this software
       without specific prior written permission.

    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
    ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
    IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
    ARE DISCLAIMED.  IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE
    FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
    DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
    OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
    HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
    LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
    OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
    SUCH DAMAGE.
 */
/* SPDX-License-Identifier: BSD-3-Clause */

#ifndef Z_UPCEAN_TTF_H
#define Z_UPCEAN_TTF_H

/* Adapted from OCR-B font version 0.2 Matthew Skala
 *   https://tsukurimashou.osdn.jp/ocr.php.en
 *
 * Copyright Matthew Skala (2011); based on code by Norbert Schwarz (1986, 2011)
 *
 * "The version in this package descends from a set of Metafont
 *  definitions by Norbert Schwarz of Ruhr-Universitaet Bochum,
 *  bearing dates ranging from 1986 to 2010. He originally
 *  distributed it under a "non-commercial use only"
 *  restriction but has since released it for unrestricted use
 *  and distribution. See the README file for more details."
 *
 * The README states (http://mirrors.ctan.org/fonts/ocr-b.zip)
 *
 * "As far as the digitization in METAFONT input which I have
 *  developed, you may freely use, modify, and/or distribute any of
 *  these files or the resulting fonts, without limitation.  A previous
 *  release of ocr-b only granted rights for non-commercial use; that
 *  restriction is now lifted."
 */
static const unsigned char upcean_ttf[2404] = {
    0x00, 0x01, 0x00, 0x00, 0x00, 0x0e, 0x00, 0x80, 0x00, 0x03, 0x00, 0x60, 0x47, 0x44, 0x45, 0x46,
    0x00, 0x11, 0x00, 0x0d, 0x00, 0x00, 0x09, 0x00, 0x00, 0x00, 0x00, 0x16, 0x47, 0x50, 0x4f, 0x53,
    0x44, 0x76, 0x4c, 0x75, 0x00, 0x00, 0x09, 0x18, 0x00, 0x00, 0x00, 0x20, 0x47, 0x53, 0x55, 0x42,
    0xb8, 0xfa, 0xb8, 0xf4, 0x00, 0x00, 0x09, 0x38, 0x00, 0x00, 0x00, 0x2a, 0x4f, 0x53, 0x2f, 0x32,
    0x56, 0xd8, 0x60, 0xec, 0x00, 0x00, 0x06, 0xc4, 0x00, 0x00, 0x00, 0x56, 0x63, 0x6d, 0x61, 0x70,
    0x00, 0x59, 0x00, 0xea, 0x00, 0x00, 0x07, 0x1c, 0x00, 0x00, 0x00, 0x44, 0x67, 0x61, 0x73, 0x70,
    0xff, 0xff, 0x00, 0x03, 0x00, 0x00, 0x08, 0xf8, 0x00, 0x00, 0x00, 0x08, 0x67, 0x6c, 0x79, 0x66,
    0x5a, 0xc9, 0xa9, 0xf4, 0x00, 0x00, 0x00, 0xec, 0x00, 0x00, 0x05, 0x22, 0x68, 0x65, 0x61, 0x64,
    0xfa, 0xed, 0xa9, 0xe5, 0x00, 0x00, 0x06, 0x4c, 0x00, 0x00, 0x00, 0x36, 0x68, 0x68, 0x65, 0x61,
    0x06, 0xc0, 0x01, 0x48, 0x00, 0x00, 0x06, 0xa0, 0x00, 0x00, 0x00, 0x24, 0x68, 0x6d, 0x74, 0x78,
    0x05, 0x8a, 0x02, 0xdf, 0x00, 0x00, 0x06, 0x84, 0x00, 0x00, 0x00, 0x1c, 0x6c, 0x6f, 0x63, 0x61,
    0x08, 0x29, 0x09, 0x54, 0x00, 0x00, 0x06, 0x30, 0x00, 0x00, 0x00, 0x1c, 0x6d, 0x61, 0x78, 0x70,
    0x00, 0x54, 0x00, 0x5a, 0x00, 0x00, 0x06, 0x10, 0x00, 0x00, 0x00, 0x20, 0x6e, 0x61, 0x6d, 0x65,
    0x19, 0xeb, 0x33, 0x64, 0x00, 0x00, 0x07, 0x60, 0x00, 0x00, 0x01, 0x76, 0x70, 0x6f, 0x73, 0x74,
    0x00, 0x03, 0x00, 0x01, 0x00, 0x00, 0x08, 0xd8, 0x00, 0x00, 0x00, 0x20, 0x00, 0x02, 0x00, 0x71,
    0xff, 0xf2, 0x02, 0x65, 0x03, 0x05, 0x00, 0x1d, 0x00, 0x31, 0x00, 0x00, 0x13, 0x34, 0x3e, 0x04,
    0x33, 0x32, 0x1e, 0x04, 0x15, 0x14, 0x0e, 0x02, 0x07, 0x22, 0x06, 0x23, 0x22, 0x26, 0x23, 0x22,
    0x2e, 0x02, 0x37, 0x14, 0x17, 0x16, 0x3b, 0x01, 0x32, 0x11, 0x35, 0x34, 0x2e, 0x02, 0x27, 0x26,
    0x23, 0x22, 0x06, 0x07, 0x06, 0x71, 0x05, 0x10, 0x22, 0x36, 0x54, 0x39, 0x38, 0x54, 0x36, 0x22,
    0x11, 0x05, 0x14, 0x2c, 0x54, 0x3a, 0x03, 0x0a, 0x02, 0x05, 0x13, 0x05, 0x48, 0x66, 0x35, 0x17,
    0x64, 0x66, 0x0a, 0x26, 0x16, 0x80, 0x05, 0x13, 0x2c, 0x23, 0x09, 0x26, 0x3d, 0x3d, 0x0d, 0x0f,
    0x01, 0x57, 0x43, 0x5c, 0x6c, 0x47, 0x3e, 0x1e, 0x1e, 0x3e, 0x48, 0x6b, 0x5d, 0x42, 0x45, 0x73,
    0x68, 0x3f, 0x05, 0x01, 0x01, 0x37, 0x66, 0x79, 0x4e, 0xe8, 0x16, 0x02, 0x01, 0x00, 0x2e, 0x3a,
    0x4b, 0x5a, 0x34, 0x07, 0x02, 0x32, 0x36, 0x3e, 0x00, 0x01, 0x00, 0x90, 0xff, 0xf6, 0x01, 0xc8,
    0x03, 0x02, 0x00, 0x15, 0x00, 0x00, 0x13, 0x34, 0x3f, 0x01, 0x36, 0x3b, 0x01, 0x32, 0x16, 0x15,
    0x11, 0x14, 0x06, 0x22, 0x26, 0x35, 0x11, 0x07, 0x06, 0x23, 0x22, 0x26, 0x90, 0x0f, 0xb7, 0x0e,
    0x12, 0x20, 0x14, 0x1e, 0x1e, 0x28, 0x1e, 0x81, 0x0d, 0x14, 0x15, 0x1d, 0x02, 0x36, 0x17, 0x0c,
    0x9d, 0x0c, 0x1e, 0x14, 0xfd, 0x58, 0x14, 0x1e, 0x1d, 0x15, 0x02, 0x56, 0x6e, 0x0c, 0x1e, 0x00,
    0x00, 0x01, 0x00, 0x82, 0x00, 0x01, 0x02, 0x51, 0x03, 0x05, 0x00, 0x2f, 0x00, 0x00, 0x13, 0x34,
    0x37, 0x36, 0x33, 0x32, 0x16, 0x15, 0x14, 0x0e, 0x03, 0x07, 0x0e, 0x03, 0x07, 0x21, 0x32, 0x16,
    0x14, 0x06, 0x23, 0x21, 0x22, 0x26, 0x3d, 0x01, 0x34, 0x37, 0x3e, 0x01, 0x37, 0x36, 0x37, 0x36,
    0x35, 0x34, 0x26, 0x23, 0x22, 0x07, 0x06, 0x23, 0x22, 0x26, 0x82, 0x15, 0x5c, 0x78, 0x61, 0x7f,
    0x1b, 0x21, 0x41, 0x23, 0x25, 0x28, 0x23, 0x31, 0x16, 0x02, 0x01, 0x2d, 0x15, 0x1d, 0x1e, 0x14,
    0xfe, 0xa0, 0x14, 0x1e, 0x0a, 0x12, 0x5f, 0x48, 0x62, 0x1a, 0x1b, 0x47, 0x35, 0x5d, 0x3d, 0x0c,
    0x11, 0x14, 0x1e, 0x02, 0x9e, 0x1c, 0x0e, 0x3d, 0x76, 0x5f, 0x26, 0x46, 0x2d, 0x37, 0x18, 0x17,
    0x19, 0x1a, 0x32, 0x3d, 0x2a, 0x1e, 0x28, 0x1e, 0x1e, 0x14, 0x15, 0x4f, 0x22, 0x3e, 0x60, 0x2e,
    0x3f, 0x23, 0x23, 0x26, 0x33, 0x3e, 0x2b, 0x09, 0x1e, 0x00, 0x00, 0x01, 0x00, 0x71, 0xff, 0xf3,
    0x02, 0x5c, 0x02, 0xf6, 0x00, 0x2d, 0x00, 0x00, 0x37, 0x34, 0x36, 0x33, 0x32, 0x17, 0x16, 0x33,
    0x32, 0x36, 0x37, 0x35, 0x34, 0x26, 0x23, 0x22, 0x26, 0x34, 0x3f, 0x01, 0x21, 0x22, 0x26, 0x35,
    0x34, 0x36, 0x33, 0x21, 0x32, 0x16, 0x1d, 0x01, 0x14, 0x0f, 0x01, 0x1e, 0x01, 0x1d, 0x01, 0x0e,
    0x01, 0x23, 0x22, 0x2e, 0x02, 0x71, 0x1e, 0x14, 0x07, 0x0c, 0x3f, 0x48, 0x4e, 0x69, 0x04, 0x77,
    0x55, 0x14, 0x1e, 0x0b, 0xb8, 0xfe, 0xe9, 0x14, 0x1e, 0x1d, 0x15, 0x01, 0x6b, 0x14, 0x1e, 0x0f,
    0x9f, 0x5a, 0x6d, 0x05, 0xa3, 0x77, 0x1d, 0x3b, 0x47, 0x2d, 0x45, 0x15, 0x1d, 0x04, 0x1c, 0x49,
    0x47, 0x09, 0x48, 0x48, 0x1e, 0x28, 0x0b, 0xc1, 0x1e, 0x14, 0x15, 0x1d, 0x1e, 0x14, 0x23, 0x12,
    0x0f, 0xa8, 0x17, 0x76, 0x5a, 0x0f, 0x6e, 0x81, 0x06, 0x0f, 0x23, 0x00, 0x00, 0x01, 0x00, 0x71,
    0xff, 0xf6, 0x02, 0x65, 0x03, 0x02, 0x00, 0x26, 0x00, 0x00, 0x37, 0x35, 0x34, 0x37, 0x13, 0x3e,
    0x01, 0x33, 0x32, 0x16, 0x15, 0x14, 0x07, 0x03, 0x33, 0x35, 0x34, 0x36, 0x32, 0x16, 0x1d, 0x01,
    0x33, 0x32, 0x16, 0x14, 0x06, 0x2b, 0x01, 0x15, 0x14, 0x06, 0x22, 0x26, 0x3d, 0x01, 0x23, 0x22,
    0x26, 0x71, 0x05, 0xd9, 0x05, 0x1a, 0x0e, 0x14, 0x1e, 0x05, 0xcc, 0xbd, 0x1e, 0x28, 0x1e, 0x35,
    0x15, 0x1d, 0x1e, 0x14, 0x35, 0x1e, 0x28, 0x1e, 0xf7, 0x14, 0x1e, 0xd6, 0x2b, 0x09, 0x0c, 0x01,
    0xcf, 0x0c, 0x11, 0x1e, 0x14, 0x0b, 0x0a, 0xfe, 0x4d, 0x74, 0x14, 0x1e, 0x1e, 0x14, 0x74, 0x1e,
    0x28, 0x1e, 0x7c, 0x14, 0x1e, 0x1e, 0x14, 0x7c, 0x1d, 0x00, 0x00, 0x01, 0x00, 0x8b, 0xff, 0xf3,
    0x02, 0x3d, 0x02, 0xf6, 0x00, 0x27, 0x00, 0x00, 0x36, 0x34, 0x36, 0x33, 0x32, 0x37, 0x36, 0x35,
    0x34, 0x27, 0x26, 0x23, 0x22, 0x07, 0x23, 0x22, 0x26, 0x3d, 0x01, 0x37, 0x3e, 0x01, 0x33, 0x21,
    0x32, 0x16, 0x14, 0x06, 0x2b, 0x01, 0x07, 0x33, 0x32, 0x16, 0x15, 0x14, 0x07, 0x06, 0x23, 0x22,
    0x8b, 0x1e, 0x14, 0xce, 0x3d, 0x11, 0x21, 0x2e, 0x75, 0x21, 0x1f, 0x04, 0x14, 0x1e, 0x0e, 0x02,
    0x1c, 0x14, 0x01, 0x26, 0x15, 0x1d, 0x1e, 0x14, 0xf7, 0x08, 0x0f, 0x88, 0xa0, 0x55, 0x65, 0xc6,
    0x14, 0x10, 0x2a, 0x1d, 0x6c, 0x20, 0x1e, 0x46, 0x24, 0x32, 0x03, 0x1c, 0x13, 0x03, 0xfb, 0x14,
    0x1b, 0x1e, 0x28, 0x1e, 0x91, 0x82, 0x7e, 0x67, 0x4d, 0x5a, 0x00, 0x02, 0x00, 0x71, 0xff, 0xf3,
    0x02, 0x65, 0x03, 0x02, 0x00, 0x19, 0x00, 0x25, 0x00, 0x00, 0x37, 0x35, 0x34, 0x37, 0x3e, 0x02,
    0x37, 0x36, 0x33, 0x32, 0x16, 0x15, 0x14, 0x07, 0x06, 0x07, 0x36, 0x33, 0x32, 0x16, 0x15, 0x14,
    0x06, 0x22, 0x26, 0x37, 0x14, 0x16, 0x33, 0x32, 0x36, 0x35, 0x34, 0x26, 0x23, 0x22, 0x06, 0x71,
    0x46, 0x1c, 0x52, 0x38, 0x34, 0x0d, 0x17, 0x14, 0x1e, 0x0d, 0x76, 0x37, 0x1e, 0x20, 0x74, 0x86,
    0x8c, 0xdc, 0x89, 0x61, 0x52, 0x44, 0x43, 0x53, 0x4c, 0x4a, 0x48, 0x4e, 0xe5, 0x0c, 0x7e, 0x74,
    0x2f, 0x69, 0x3f, 0x39, 0x0f, 0x1e, 0x14, 0x13, 0x0f, 0x80, 0x4d, 0x06, 0x8c, 0x76, 0x6b, 0x87,
    0x85, 0x6d, 0x42, 0x4c, 0x4d, 0x41, 0x4c, 0x52, 0x54, 0x00, 0x00, 0x01, 0x00, 0x71, 0xff, 0xf6,
    0x02, 0x65, 0x02, 0xf6, 0x00, 0x1d, 0x00, 0x00, 0x13, 0x34, 0x36, 0x33, 0x21, 0x32, 0x16, 0x15,
    0x14, 0x07, 0x0e, 0x01, 0x07, 0x06, 0x15, 0x14, 0x06, 0x22, 0x26, 0x35, 0x34, 0x37, 0x3e, 0x01,
    0x37, 0x36, 0x37, 0x21, 0x22, 0x26, 0x71, 0x1d, 0x15, 0x01, 0x90, 0x15, 0x1d, 0x3c, 0x12, 0x6a,
    0x17, 0x43, 0x1e, 0x28, 0x1e, 0x50, 0x18, 0x6e, 0x11, 0x19, 0x08, 0xfe, 0xac, 0x14, 0x1e, 0x02,
    0xc4, 0x15, 0x1d, 0x1e, 0x14, 0x4d, 0x58, 0x1b, 0x82, 0x27, 0x76, 0xbd, 0x14, 0x1e, 0x1d, 0x15,
    0xd8, 0x8c, 0x2a, 0x89, 0x19, 0x26, 0x14, 0x1e, 0x00, 0x03, 0x00, 0x71, 0xff, 0xf3, 0x02, 0x65,
    0x03, 0x05, 0x00, 0x15, 0x00, 0x20, 0x00, 0x2f, 0x00, 0x00, 0x37, 0x34, 0x37, 0x26, 0x35, 0x34,
    0x36, 0x33, 0x32, 0x16, 0x15, 0x14, 0x06, 0x07, 0x16, 0x15, 0x14, 0x06, 0x07, 0x23, 0x22, 0x26,
    0x37, 0x14, 0x16, 0x3b, 0x01, 0x32, 0x36, 0x35, 0x34, 0x27, 0x06, 0x13, 0x14, 0x1e, 0x02, 0x17,
    0x3e, 0x03, 0x35, 0x34, 0x26, 0x22, 0x06, 0x71, 0x91, 0x6f, 0x84, 0x54, 0x53, 0x85, 0x3a, 0x35,
    0x91, 0x77, 0x57, 0x2c, 0x6d, 0x8d, 0x63, 0x56, 0x41, 0x15, 0x35, 0x4c, 0x94, 0x99, 0x23, 0x12,
    0x29, 0x1c, 0x1d, 0x1d, 0x1d, 0x28, 0x12, 0x4b, 0x52, 0x4b, 0xc8, 0x7c, 0x63, 0x43, 0x6e, 0x4c,
    0x61, 0x62, 0x4b, 0x3d, 0x53, 0x21, 0x63, 0x7c, 0x51, 0x7d, 0x07, 0x77, 0x5e, 0x35, 0x3c, 0x43,
    0x2e, 0x5c, 0x4d, 0x4e, 0x01, 0x35, 0x18, 0x24, 0x1e, 0x10, 0x0d, 0x0d, 0x0f, 0x1e, 0x25, 0x18,
    0x23, 0x26, 0x26, 0x00, 0x00, 0x02, 0x00, 0x71, 0xff, 0xf6, 0x02, 0x65, 0x03, 0x05, 0x00, 0x17,
    0x00, 0x24, 0x00, 0x00, 0x13, 0x34, 0x36, 0x33, 0x32, 0x16, 0x15, 0x14, 0x06, 0x07, 0x06, 0x07,
    0x06, 0x23, 0x22, 0x26, 0x34, 0x37, 0x36, 0x37, 0x06, 0x23, 0x22, 0x26, 0x37, 0x14, 0x16, 0x33,
    0x32, 0x37, 0x36, 0x35, 0x34, 0x26, 0x23, 0x22, 0x06, 0x71, 0x92, 0x68, 0x6b, 0x8f, 0x2a, 0x27,
    0x55, 0x7d, 0x0f, 0x12, 0x14, 0x1e, 0x10, 0x63, 0x46, 0x1b, 0x22, 0x70, 0x8a, 0x64, 0x51, 0x45,
    0x78, 0x14, 0x0a, 0x52, 0x44, 0x3f, 0x57, 0x02, 0x02, 0x6a, 0x99, 0x8f, 0x74, 0x48, 0x73, 0x43,
    0x91, 0x70, 0x0d, 0x1d, 0x2a, 0x10, 0x5a, 0x6e, 0x04, 0x8a, 0x67, 0x3f, 0x4e, 0x45, 0x21, 0x27,
    0x49, 0x56, 0x5e, 0x00, 0x00, 0x01, 0x00, 0x71, 0x00, 0x40, 0x02, 0x65, 0x02, 0xb8, 0x00, 0x14,
    0x00, 0x00, 0x12, 0x34, 0x37, 0x01, 0x36, 0x33, 0x32, 0x16, 0x15, 0x14, 0x07, 0x0d, 0x01, 0x16,
    0x15, 0x14, 0x06, 0x23, 0x22, 0x27, 0x01, 0x71, 0x0d, 0x01, 0x99, 0x0c, 0x10, 0x14, 0x1e, 0x0f,
    0xfe, 0xa7, 0x01, 0x59, 0x0f, 0x1e, 0x14, 0x10, 0x0c, 0xfe, 0x67, 0x01, 0x65, 0x2e, 0x0d, 0x01,
    0x0f, 0x09, 0x1e, 0x14, 0x1a, 0x0a, 0xe6, 0xe6, 0x0f, 0x15, 0x14, 0x1e, 0x09, 0x01, 0x0f, 0x00,
    0x00, 0x01, 0x00, 0x71, 0x00, 0x40, 0x02, 0x65, 0x02, 0xb8, 0x00, 0x15, 0x00, 0x00, 0x37, 0x34,
    0x37, 0x2d, 0x01, 0x26, 0x35, 0x34, 0x36, 0x33, 0x32, 0x17, 0x01, 0x16, 0x15, 0x14, 0x07, 0x01,
    0x06, 0x23, 0x22, 0x26, 0x71, 0x0e, 0x01, 0x59, 0xfe, 0xa7, 0x0e, 0x1e, 0x14, 0x0f, 0x0d, 0x01,
    0x98, 0x0e, 0x0e, 0xfe, 0x68, 0x0d, 0x0f, 0x14, 0x1e, 0x72, 0x14, 0x10, 0xe6, 0xe6, 0x10, 0x14,
    0x15, 0x1d, 0x09, 0xfe, 0xf1, 0x0d, 0x17, 0x1b, 0x09, 0xfe, 0xf1, 0x09, 0x1d, 0x00, 0x00, 0x00,
    0x00, 0x01, 0x00, 0x00, 0x00, 0x0d, 0x00, 0x57, 0x00, 0x05, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02,
    0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0x00, 0x00, 0x00, 0x40, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x46, 0x00, 0x6a, 0x00, 0xaf, 0x00, 0xf0, 0x01, 0x27, 0x01, 0x5f,
    0x01, 0x97, 0x01, 0xc6, 0x02, 0x0c, 0x02, 0x44, 0x02, 0x6a, 0x02, 0x91, 0x00, 0x01, 0x00, 0x00,
    0x00, 0x02, 0x00, 0x00, 0xb6, 0x0c, 0xeb, 0x74, 0x5f, 0x0f, 0x3c, 0xf5, 0x00, 0x0b, 0x03, 0xe8,
    0x00, 0x00, 0x00, 0x00, 0xcc, 0x8a, 0x33, 0x53, 0x00, 0x00, 0x00, 0x00, 0xcc, 0x8a, 0x33, 0x53,
    0xff, 0xa9, 0xfe, 0xb0, 0x03, 0x10, 0x03, 0xaa, 0x00, 0x00, 0x00, 0x08, 0x00, 0x02, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x02, 0xd3, 0x00, 0x00, 0x00, 0x71, 0x00, 0x90, 0x00, 0x82, 0x00, 0x71,
    0x00, 0x71, 0x00, 0x8b, 0x00, 0x71, 0x00, 0x71, 0x00, 0x71, 0x00, 0x71, 0x00, 0x71, 0x00, 0x71,
    0x00, 0x01, 0x00, 0x00, 0x03, 0xaa, 0xfe, 0xb0, 0x00, 0x5a, 0x02, 0xd3, 0xff, 0xa9, 0xff, 0xc3,
    0x03, 0x10, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x01, 0x00, 0x01, 0x02, 0xd3, 0x01, 0x90, 0x00, 0x05, 0x00, 0x00, 0x02, 0x8a,
    0x02, 0xbc, 0x00, 0x00, 0x00, 0x8c, 0x02, 0x8a, 0x02, 0xbc, 0x00, 0x00, 0x01, 0xe0, 0x00, 0x31,
    0x01, 0x02, 0x00, 0x00, 0x02, 0x00, 0x05, 0x09, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x50, 0x66,
    0x45, 0x64, 0x00, 0x40, 0x00, 0x30, 0x00, 0x3e, 0x03, 0x20, 0xff, 0x38, 0x00, 0x5a, 0x03, 0xaa,
    0x01, 0x50, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02,
    0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x14, 0x00, 0x03, 0x00, 0x01, 0x00, 0x00, 0x00, 0x14,
    0x00, 0x04, 0x00, 0x30, 0x00, 0x00, 0x00, 0x08, 0x00, 0x08, 0x00, 0x02, 0x00, 0x00, 0x00, 0x39,
    0x00, 0x3c, 0x00, 0x3e, 0xff, 0xff, 0x00, 0x00, 0x00, 0x30, 0x00, 0x3c, 0x00, 0x3e, 0xff, 0xff,
    0xff, 0xd1, 0xff, 0xcf, 0xff, 0xce, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x07, 0x00, 0x5a, 0x00, 0x03, 0x00, 0x01, 0x04, 0x09, 0x00, 0x00, 0x00, 0x86,
    0x00, 0x00, 0x00, 0x03, 0x00, 0x01, 0x04, 0x09, 0x00, 0x01, 0x00, 0x08, 0x00, 0x86, 0x00, 0x03,
    0x00, 0x01, 0x04, 0x09, 0x00, 0x02, 0x00, 0x0e, 0x00, 0x8e, 0x00, 0x03, 0x00, 0x01, 0x04, 0x09,
    0x00, 0x03, 0x00, 0x52, 0x00, 0x9c, 0x00, 0x03, 0x00, 0x01, 0x04, 0x09, 0x00, 0x04, 0x00, 0x1a,
    0x00, 0xee, 0x00, 0x03, 0x00, 0x01, 0x04, 0x09, 0x00, 0x05, 0x00, 0x14, 0x01, 0x08, 0x00, 0x03,
    0x00, 0x01, 0x04, 0x09, 0x00, 0x06, 0x00, 0x08, 0x00, 0x86, 0x00, 0x4d, 0x00, 0x61, 0x00, 0x74,
    0x00, 0x74, 0x00, 0x68, 0x00, 0x65, 0x00, 0x77, 0x00, 0x20, 0x00, 0x53, 0x00, 0x6b, 0x00, 0x61,
    0x00, 0x6c, 0x00, 0x61, 0x00, 0x20, 0x00, 0x28, 0x00, 0x32, 0x00, 0x30, 0x00, 0x31, 0x00, 0x31,
    0x00, 0x29, 0x00, 0x3b, 0x00, 0x20, 0x00, 0x62, 0x00, 0x61, 0x00, 0x73, 0x00, 0x65, 0x00, 0x64,
    0x00, 0x20, 0x00, 0x6f, 0x00, 0x6e, 0x00, 0x20, 0x00, 0x63, 0x00, 0x6f, 0x00, 0x64, 0x00, 0x65,
    0x00, 0x20, 0x00, 0x62, 0x00, 0x79, 0x00, 0x20, 0x00, 0x4e, 0x00, 0x6f, 0x00, 0x72, 0x00, 0x62,
    0x00, 0x65, 0x00, 0x72, 0x00, 0x74, 0x00, 0x20, 0x00, 0x53, 0x00, 0x63, 0x00, 0x68, 0x00, 0x77,
    0x00, 0x61, 0x00, 0x72, 0x00, 0x7a, 0x00, 0x20, 0x00, 0x28, 0x00, 0x31, 0x00, 0x39, 0x00, 0x38,
    0x00, 0x36, 0x00, 0x2c, 0x00, 0x20, 0x00, 0x32, 0x00, 0x30, 0x00, 0x31, 0x00, 0x31, 0x00, 0x29,
    0x00, 0x4f, 0x00, 0x43, 0x00, 0x52, 0x00, 0x42, 0x00, 0x52, 0x00, 0x65, 0x00, 0x67, 0x00, 0x75,
    0x00, 0x6c, 0x00, 0x61, 0x00, 0x72, 0x00, 0x46, 0x00, 0x6f, 0x00, 0x6e, 0x00, 0x74, 0x00, 0x46,
    0x00, 0x6f, 0x00, 0x72, 0x00, 0x67, 0x00, 0x65, 0x00, 0x20, 0x00, 0x32, 0x00, 0x2e, 0x00, 0x30,
    0x00, 0x20, 0x00, 0x3a, 0x00, 0x20, 0x00, 0x4f, 0x00, 0x43, 0x00, 0x52, 0x00, 0x20, 0x00, 0x42,
    0x00, 0x20, 0x00, 0x52, 0x00, 0x65, 0x00, 0x67, 0x00, 0x75, 0x00, 0x6c, 0x00, 0x61, 0x00, 0x72,
    0x00, 0x20, 0x00, 0x3a, 0x00, 0x20, 0x00, 0x32, 0x00, 0x37, 0x00, 0x2d, 0x00, 0x39, 0x00, 0x2d,
    0x00, 0x32, 0x00, 0x30, 0x00, 0x31, 0x00, 0x32, 0x00, 0x4f, 0x00, 0x43, 0x00, 0x52, 0x00, 0x20,
    0x00, 0x42, 0x00, 0x20, 0x00, 0x52, 0x00, 0x65, 0x00, 0x67, 0x00, 0x75, 0x00, 0x6c, 0x00, 0x61,
    0x00, 0x72, 0x00, 0x56, 0x00, 0x65, 0x00, 0x72, 0x00, 0x73, 0x00, 0x69, 0x00, 0x6f, 0x00, 0x6e,
    0x00, 0x20, 0x00, 0x32, 0x00, 0x20, 0x00, 0x00, 0x00, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xff, 0x00, 0x02,
    0x00, 0x01, 0x00, 0x00, 0x00, 0x0c, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x02, 0x00, 0x01,
    0x00, 0x01, 0x00, 0x0c, 0x00, 0x01, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x0a, 0x00, 0x1c,
    0x00, 0x1e, 0x00, 0x01, 0x44, 0x46, 0x4c, 0x54, 0x00, 0x08, 0x00, 0x04, 0x00, 0x00, 0x00, 0x00,
    0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x0a, 0x00, 0x26,
    0x00, 0x28, 0x00, 0x02, 0x44, 0x46, 0x4c, 0x54, 0x00, 0x0e, 0x6c, 0x61, 0x74, 0x6e, 0x00, 0x18,
    0x00, 0x04, 0x00, 0x00, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00
};

/* vim: set ts=4 sw=4 et : */
#endif /* Z_UPCEAN_TTF_H */