/*
   Copyright (C) 2008-2023 J.Rios <anonbeat@gmail.com>
   Copyright (C) 2024 Tiago T Barrionuevo <thothix@protonmail.com>

   This file is part of Guayadeque Music Player.

   Guayadeque is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   Guayadeque is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with Guayadeque. If not, see <https://www.gnu.org/licenses/>.
*/
const unsigned char guImage_exit[] = {
0x89, 0x50, 0x4e, 0x47, 0x0d, 0x0a, 0x1a, 0x0a, 0x00, 0x00, 0x00, 0x0d, 0x49,
0x48, 0x44, 0x52, 0x00, 0x00, 0x00, 0x18, 0x00, 0x00, 0x00, 0x18, 0x08, 0x06,
0x00, 0x00, 0x00, 0xe0, 0x77, 0x3d, 0xf8, 0x00, 0x00, 0x00, 0x06, 0x62, 0x4b,
0x47, 0x44, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xf9, 0x43, 0xbb, 0x7f, 0x00,
0x00, 0x00, 0x09, 0x70, 0x48, 0x59, 0x73, 0x00, 0x00, 0x0b, 0x13, 0x00, 0x00,
0x0b, 0x13, 0x01, 0x00, 0x9a, 0x9c, 0x18, 0x00, 0x00, 0x03, 0x47, 0x49, 0x44,
0x41, 0x54, 0x48, 0xc7, 0xcd, 0x95, 0x5f, 0x68, 0x5b, 0x55, 0x1c, 0xc7, 0x3f,
0xbf, 0xf3, 0x3b, 0x37, 0x49, 0x9b, 0xa4, 0x4d, 0x6a, 0x59, 0x67, 0x62, 0x57,
0xcc, 0x8a, 0x2d, 0x0e, 0x7c, 0x18, 0x32, 0x0b, 0x13, 0xe7, 0x93, 0xef, 0x03,
0xb1, 0x20, 0x08, 0x8a, 0x3e, 0xe9, 0x83, 0x20, 0x6c, 0x0f, 0x3a, 0x61, 0xe2,
0xc3, 0x14, 0x75, 0xe2, 0x43, 0x5f, 0xa4, 0xf6, 0xa1, 0x4c, 0x37, 0x7c, 0xa9,
0x30, 0xa5, 0xd5, 0xae, 0xfe, 0xd9, 0x83, 0x76, 0x9d, 0x9b, 0x28, 0x76, 0x48,
0x3b, 0xd7, 0x05, 0x3a, 0x57, 0x53, 0x1a, 0x4b, 0x6f, 0xb3, 0x2e, 0x26, 0xb9,
0xd7, 0x87, 0xd4, 0x26, 0xe9, 0xd6, 0x26, 0x4c, 0x05, 0x7f, 0xf0, 0xe3, 0xc2,
0x3d, 0xe7, 0xfc, 0x3e, 0xf7, 0xfb, 0x3d, 0xbf, 0x73, 0x2e, 0xfc, 0xc7, 0x21,
0xdb, 0x0d, 0x3e, 0xf0, 0xe0, 0x3e, 0xff, 0x9f, 0x14, 0xff, 0xe9, 0xfb, 0x29,
0xb1, 0xf5, 0x26, 0x9d, 0x1a, 0x1e, 0xe2, 0xfa, 0xf5, 0x05, 0x16, 0x17, 0x17,
0xc8, 0x64, 0x16, 0xb9, 0x9a, 0x4e, 0xf3, 0x47, 0x36, 0x0b, 0xc0, 0x81, 0x03,
0x8f, 0x72, 0xf4, 0xe8, 0x6b, 0xac, 0x39, 0x4b, 0x35, 0x6b, 0x76, 0x74, 0x47,
0x90, 0xc5, 0x5d, 0x00, 0xd4, 0x05, 0x24, 0x93, 0x49, 0x62, 0xb1, 0x18, 0x9d,
0x9d, 0x49, 0x72, 0xb9, 0x1b, 0xec, 0xdd, 0xbb, 0xca, 0xfc, 0xfc, 0x3c, 0x17,
0x2f, 0xfe, 0x40, 0x34, 0x1a, 0xc5, 0xf3, 0xbc, 0x6d, 0xd7, 0x9b, 0x3b, 0x91,
0x1e, 0x8f, 0xb7, 0xd1, 0xd7, 0xd7, 0x47, 0x4b, 0x4b, 0x2b, 0xa1, 0x50, 0xd3,
0xbf, 0x0f, 0x00, 0x08, 0x87, 0xc3, 0x24, 0x12, 0x77, 0x93, 0x4c, 0x26, 0xee,
0x1c, 0xd0, 0x99, 0x2b, 0xd5, 0x05, 0xa5, 0x52, 0x29, 0xd4, 0x2a, 0xea, 0x28,
0xd6, 0xb1, 0x58, 0xc7, 0xa2, 0x6a, 0x1a, 0x03, 0x1c, 0xbc, 0xfc, 0x33, 0x13,
0x47, 0x8e, 0xd5, 0xf5, 0x59, 0xd5, 0x60, 0xad, 0x45, 0xad, 0x62, 0x1d, 0xc5,
0x34, 0x0a, 0x50, 0xcf, 0x23, 0x31, 0x38, 0xc0, 0x37, 0x2f, 0x1c, 0xa6, 0x58,
0x28, 0x6c, 0x3d, 0xcf, 0x2a, 0xd6, 0x31, 0x38, 0xeb, 0x2a, 0x54, 0xb5, 0x31,
0x00, 0xc0, 0x43, 0xf7, 0xf7, 0xb2, 0x6f, 0xfc, 0x34, 0xe7, 0x9f, 0x7e, 0x9e,
0x7c, 0x6e, 0x6d, 0xe3, 0xfd, 0x89, 0x13, 0x1f, 0x12, 0x8b, 0xc5, 0x37, 0x00,
0x6a, 0x2d, 0x36, 0x50, 0xce, 0x6a, 0x05, 0x16, 0x60, 0x58, 0x1d, 0x37, 0x50,
0x2a, 0x44, 0x36, 0x17, 0x0f, 0x94, 0x0a, 0xe0, 0x79, 0x74, 0xef, 0x4e, 0x11,
0xf9, 0xf1, 0x3c, 0x9f, 0x3f, 0xf5, 0x2c, 0x89, 0xf7, 0xde, 0x86, 0x60, 0xb9,
0xbb, 0x7b, 0x7a, 0x7a, 0xe9, 0xef, 0x7f, 0x82, 0x40, 0xb3, 0xa2, 0x56, 0x31,
0xc6, 0x20, 0x22, 0x38, 0x41, 0x65, 0xad, 0x1a, 0x20, 0xbe, 0x6f, 0xfb, 0xf7,
0xec, 0x01, 0x5b, 0x75, 0x2c, 0x8c, 0x01, 0xcf, 0x83, 0x85, 0x05, 0xc8, 0x64,
0xd8, 0x99, 0x4a, 0x71, 0xf0, 0xca, 0x65, 0x46, 0x9e, 0x79, 0x8e, 0xe2, 0xab,
0x47, 0x18, 0x19, 0xf9, 0x84, 0x73, 0xe7, 0xbe, 0xe3, 0xf8, 0xf1, 0x77, 0x71,
0x42, 0xb6, 0xec, 0xbd, 0x01, 0x44, 0x50, 0x47, 0x6a, 0x15, 0x00, 0x50, 0x2c,
0xe2, 0x4f, 0x4f, 0xb3, 0xd5, 0x76, 0x9a, 0xd9, 0x59, 0x5a, 0xba, 0xba, 0x78,
0x32, 0x9d, 0xe6, 0xe3, 0x57, 0x5e, 0xe6, 0xfd, 0x37, 0xdf, 0xd9, 0x18, 0x0b,
0x45, 0x2c, 0xd6, 0x2a, 0x62, 0x0c, 0x08, 0xd8, 0x60, 0x05, 0x50, 0x31, 0x6b,
0x75, 0x95, 0x65, 0x60, 0x19, 0xc8, 0xae, 0xe7, 0x72, 0x55, 0x66, 0x81, 0xa5,
0x74, 0x1a, 0x27, 0x99, 0xe4, 0xb1, 0x9c, 0x4b, 0xf1, 0xd0, 0x4b, 0xdc, 0x58,
0x76, 0xcb, 0x45, 0xd4, 0x60, 0x54, 0xcb, 0xdd, 0xa4, 0x65, 0xab, 0x6e, 0x55,
0xb0, 0xb2, 0x42, 0x16, 0x28, 0x6e, 0xb3, 0xe1, 0x3d, 0x22, 0x14, 0xae, 0x5d,
0xe3, 0x4c, 0x73, 0x18, 0x79, 0xfd, 0x0d, 0x9a, 0x63, 0xd1, 0xf5, 0x4d, 0x16,
0x8c, 0x5d, 0x07, 0x19, 0x30, 0x95, 0x26, 0xaa, 0x02, 0xdc, 0xbc, 0xc9, 0xee,
0x70, 0xf8, 0x96, 0xa2, 0x6e, 0x2e, 0xc7, 0x6f, 0x40, 0x37, 0xe0, 0xfa, 0x3e,
0xa7, 0x23, 0x51, 0xe4, 0xd8, 0x5b, 0xec, 0xb8, 0xaf, 0xab, 0x62, 0x43, 0x00,
0xd4, 0x96, 0xd3, 0xa8, 0xa0, 0x81, 0x4d, 0x00, 0x5f, 0xa4, 0x78, 0xb2, 0x50,
0x2c, 0x51, 0xa8, 0xfd, 0x7e, 0x07, 0xf4, 0x71, 0x11, 0x52, 0xbe, 0x4f, 0x06,
0x98, 0x88, 0xc6, 0x68, 0x1d, 0x18, 0x20, 0xd8, 0xd1, 0x06, 0x50, 0xd5, 0xa6,
0x94, 0x15, 0x58, 0x50, 0x15, 0x8c, 0xfa, 0xb5, 0x80, 0xb3, 0xa9, 0x47, 0xda,
0xb9, 0xcd, 0xbf, 0x61, 0xff, 0x95, 0xb3, 0x6b, 0xf9, 0x52, 0x81, 0x79, 0x31,
0x7c, 0x1b, 0xbf, 0x8b, 0xe4, 0xd0, 0x10, 0xc1, 0xf6, 0x16, 0xe2, 0xf1, 0x36,
0xf2, 0xf9, 0x3f, 0x19, 0x1b, 0x1b, 0xc5, 0x75, 0x5d, 0xa4, 0xd5, 0x60, 0x4c,
0x25, 0x45, 0x36, 0x01, 0x06, 0x67, 0x27, 0xf2, 0xb7, 0xf3, 0x7c, 0xbf, 0x3a,
0x5c, 0x12, 0xc3, 0x74, 0x47, 0x82, 0xde, 0x53, 0x1f, 0xb1, 0x33, 0xd5, 0x85,
0xeb, 0xae, 0x30, 0x39, 0x39, 0xc9, 0xcc, 0xcc, 0x2c, 0x17, 0x96, 0x3e, 0xc3,
0x8b, 0x15, 0x71, 0x9c, 0xf2, 0x35, 0xa1, 0x6a, 0x10, 0x23, 0x88, 0xf1, 0x6a,
0x01, 0x5b, 0x85, 0x0f, 0x5c, 0xda, 0x75, 0x2f, 0x0f, 0x8f, 0x8d, 0x52, 0x72,
0x84, 0xa9, 0xa9, 0x29, 0xe6, 0xe6, 0xe6, 0x38, 0x33, 0x37, 0x8c, 0xe7, 0x7b,
0xd8, 0x26, 0xc5, 0x68, 0xa8, 0x52, 0x58, 0x04, 0x11, 0x40, 0x1a, 0x04, 0xfc,
0xd2, 0x9e, 0xe0, 0xc5, 0xaf, 0x27, 0x98, 0xb9, 0xfa, 0x2b, 0xe3, 0x5f, 0x8e,
0x73, 0x21, 0xfb, 0x29, 0x62, 0x04, 0x1b, 0x50, 0x8c, 0x3a, 0x98, 0xaa, 0xc2,
0x54, 0x7b, 0xec, 0x07, 0x1a, 0x03, 0x7c, 0x71, 0x4f, 0x07, 0xc9, 0xd1, 0x11,
0xbe, 0xfa, 0x7d, 0x10, 0x0c, 0x34, 0xb5, 0xff, 0xad, 0xab, 0xf6, 0x38, 0xfa,
0x9b, 0x9e, 0xe5, 0x08, 0xd7, 0x07, 0x78, 0x02, 0x1f, 0x0c, 0x9d, 0xdc, 0x98,
0xfc, 0xbf, 0x8c, 0xbf, 0x00, 0xb7, 0xbb, 0xf9, 0x46, 0x03, 0x30, 0x30, 0xa4,
0x00, 0x00, 0x00, 0x00, 0x49, 0x45, 0x4e, 0x44, 0xae, 0x42, 0x60, 0x82
};
