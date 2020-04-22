// -------------------------------------------------------------------------------- //
//    Copyright (C) 2008-2020 J.Rios anonbeat@gmail.com
//
//    This Program is free software; you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation; either version 3, or (at your option)
//    any later version.
//
//    This Program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program; see the file LICENSE.  If not, write to
//    the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,
//    Boston, MA 02110-1301 USA.
//
//    http://www.gnu.org/copyleft/gpl.html
//
// -------------------------------------------------------------------------------- //
const unsigned char guImage_pref_crossfader[] = {
0x89, 0x50, 0x4e, 0x47, 0x0d, 0x0a, 0x1a, 0x0a, 0x00, 0x00, 0x00, 0x0d, 
0x49, 0x48, 0x44, 0x52, 0x00, 0x00, 0x00, 0x20, 0x00, 0x00, 0x00, 0x20, 
0x08, 0x06, 0x00, 0x00, 0x00, 0x73, 0x7a, 0x7a, 0xf4, 0x00, 0x00, 0x00, 
0x01, 0x73, 0x52, 0x47, 0x42, 0x00, 0xae, 0xce, 0x1c, 0xe9, 0x00, 0x00, 
0x00, 0x06, 0x62, 0x4b, 0x47, 0x44, 0x00, 0xff, 0x00, 0xff, 0x00, 0xff, 
0xa0, 0xbd, 0xa7, 0x93, 0x00, 0x00, 0x00, 0x09, 0x70, 0x48, 0x59, 0x73, 
0x00, 0x00, 0x0e, 0xc4, 0x00, 0x00, 0x0e, 0xc4, 0x01, 0x95, 0x2b, 0x0e, 
0x1b, 0x00, 0x00, 0x00, 0x07, 0x74, 0x49, 0x4d, 0x45, 0x07, 0xda, 0x05, 
0x07, 0x08, 0x16, 0x1d, 0x5b, 0xcb, 0xaa, 0x96, 0x00, 0x00, 0x05, 0xa4, 
0x49, 0x44, 0x41, 0x54, 0x58, 0xc3, 0xed, 0x56, 0x59, 0x88, 0x1c, 0x55, 
0x14, 0x3d, 0x6f, 0xa9, 0xa5, 0xf7, 0xbd, 0x67, 0x1c, 0x93, 0x89, 0x99, 
0x64, 0x12, 0xc7, 0x65, 0x12, 0x17, 0x10, 0x35, 0x71, 0x89, 0x8e, 0x92, 
0x21, 0x32, 0x26, 0x51, 0x41, 0x0d, 0x28, 0x82, 0x41, 0xc4, 0x05, 0x31, 
0x2e, 0x88, 0xa8, 0x20, 0x2a, 0x92, 0x2f, 0x17, 0xa2, 0xe0, 0x8f, 0x22, 
0x08, 0x46, 0xd0, 0x2f, 0xd1, 0x7c, 0x19, 0x5c, 0xa3, 0xc6, 0x18, 0x62, 
0x34, 0x22, 0x31, 0x46, 0x9d, 0x98, 0xe9, 0xee, 0x31, 0xd3, 0x3d, 0xd3, 
0x5d, 0xd5, 0x55, 0x5d, 0xf5, 0xae, 0x1f, 0x93, 0x7a, 0xe9, 0x64, 0x10, 
0xf2, 0x21, 0xfa, 0x61, 0xee, 0xd7, 0xe9, 0xea, 0x7b, 0xaa, 0xce, 0x5d, 
0xde, 0xbd, 0x0f, 0x38, 0x65, 0xa7, 0xec, 0xff, 0x6e, 0xe2, 0x9f, 0x78, 
0xc9, 0x8a, 0x15, 0xe7, 0xf7, 0x58, 0x96, 0xb1, 0xea, 0xea, 0xab, 0x2e, 
0xab, 0x39, 0xee, 0xcc, 0xaa, 0xc1, 0xa5, 0x03, 0x67, 0xfc, 0x71, 0xa8, 
0x72, 0xe0, 0x5f, 0x8b, 0x62, 0x78, 0x78, 0xe9, 0xe6, 0x72, 0xa9, 0x48, 
0xe7, 0x2e, 0x3f, 0x73, 0x65, 0x4f, 0x4f, 0x56, 0x95, 0x4a, 0x59, 0x3a, 
0x59, 0x2e, 0xff, 0x27, 0x04, 0x14, 0x8b, 0xb9, 0x92, 0x02, 0x40, 0x9c, 
0x67, 0x14, 0x21, 0x08, 0x95, 0xc2, 0x63, 0x8f, 0x6c, 0x8a, 0x9f, 0xb4, 
0x80, 0x97, 0x5e, 0x7c, 0xc6, 0x78, 0x65, 0xf3, 0xe6, 0x44, 0xf4, 0x70, 
0x7a, 0xe6, 0x77, 0x76, 0x32, 0xe4, 0xa7, 0x9f, 0x7a, 0xd4, 0xde, 0xb0, 
0x61, 0xe4, 0x8a, 0x64, 0x3a, 0x71, 0x16, 0x03, 0x43, 0x2a, 0x95, 0x59, 
0xce, 0x98, 0x00, 0x31, 0xe0, 0xe7, 0xf1, 0x7d, 0xf2, 0xef, 0x78, 0x0f, 
0xdc, 0xbd, 0x76, 0xdd, 0x4d, 0x1b, 0xae, 0x5d, 0xac, 0x05, 0xbc, 0xfd, 
0xce, 0xb6, 0x73, 0xdf, 0x7a, 0xf7, 0xc3, 0xfd, 0x91, 0xc3, 0xba, 0xb1, 
0xeb, 0x57, 0x47, 0x78, 0xe5, 0xc5, 0x17, 0x0c, 0xae, 0xb9, 0xf6, 0xca, 
0x73, 0xa2, 0xdf, 0x44, 0x24, 0x86, 0xcf, 0x1e, 0x2c, 0x00, 0xc0, 0xd4, 
0x54, 0xab, 0x3c, 0x3e, 0xf1, 0xe7, 0x47, 0x33, 0x8e, 0xb7, 0x5f, 0xa9, 
0x10, 0x33, 0xd3, 0x4d, 0xa5, 0x14, 0x94, 0x52, 0x0c, 0x03, 0x8b, 0xe7, 
0xad, 0x1b, 0xb9, 0xfc, 0xa2, 0xeb, 0x23, 0xde, 0x83, 0xf7, 0xde, 0xb9, 
0x20, 0xc2, 0x07, 0x7e, 0xaa, 0xaf, 0x09, 0xdb, 0xe9, 0x3b, 0xb4, 0x80, 
0x76, 0xe8, 0x73, 0xc5, 0x7c, 0x2f, 0x72, 0xe8, 0x2b, 0xf7, 0xe9, 0xf4, 
0x19, 0x86, 0x8c, 0x99, 0xa6, 0xa9, 0x6b, 0xca, 0x18, 0x0b, 0x87, 0x86, 
0xce, 0x36, 0x01, 0x60, 0xdf, 0x0f, 0xbb, 0x45, 0xcb, 0x6b, 0x23, 0x91, 
0xb2, 0xd6, 0x70, 0x01, 0x34, 0x1a, 0x53, 0x4a, 0x85, 0x8a, 0x38, 0x04, 
0xdc, 0xc6, 0xcc, 0xc3, 0x89, 0xa4, 0x39, 0x3f, 0xe2, 0xf9, 0x9e, 0x67, 
0x44, 0xd8, 0xf1, 0xbd, 0x3d, 0x47, 0x1a, 0xd3, 0x59, 0x2d, 0x20, 0x99, 
0x4c, 0x24, 0x4d, 0x86, 0xf0, 0xd8, 0xd1, 0x30, 0xfd, 0x08, 0x4b, 0x69, 
0x26, 0x93, 0xc9, 0xa4, 0xea, 0x4e, 0xe1, 0xee, 0xdd, 0xdf, 0xfa, 0x00, 
0x50, 0x9d, 0xac, 0x0d, 0x08, 0x6e, 0xc1, 0x10, 0x76, 0x1c, 0x4a, 0x22, 
0x97, 0x89, 0x97, 0x09, 0x00, 0x63, 0x0a, 0xd2, 0x94, 0x1e, 0x71, 0x4a, 
0x45, 0x9c, 0x3d, 0x7b, 0x76, 0x35, 0x23, 0x9c, 0xcb, 0xa4, 0xdc, 0x10, 
0xee, 0x7c, 0x2d, 0x40, 0x21, 0xb4, 0xec, 0x78, 0x4c, 0x7f, 0x20, 0x91, 
0x48, 0xe8, 0x6c, 0xb4, 0x5d, 0x87, 0x4c, 0xd3, 0x3c, 0xae, 0x86, 0xc9, 
0x78, 0x82, 0x01, 0x40, 0x3a, 0x97, 0x4e, 0x84, 0x08, 0xc0, 0x18, 0x42, 
0x85, 0x0e, 0x42, 0xa2, 0x1c, 0x67, 0x1c, 0x8a, 0x08, 0x4a, 0xa9, 0x8c, 
0x14, 0x28, 0xe8, 0x4c, 0x92, 0x19, 0x3c, 0xfb, 0xd8, 0xa6, 0x8b, 0x00, 
0x60, 0x71, 0xff, 0xe2, 0x9f, 0xb8, 0x62, 0xfd, 0x5a, 0x80, 0xa3, 0x38, 
0x75, 0x02, 0xe8, 0x1e, 0x28, 0x17, 0x7b, 0x74, 0x13, 0x2a, 0xc7, 0x45, 
0xb9, 0x90, 0x3f, 0x4e, 0x40, 0x3e, 0x9d, 0x92, 0x00, 0x10, 0x93, 0x96, 
0x15, 0x12, 0x00, 0x06, 0x13, 0x50, 0x90, 0x86, 0x35, 0x4f, 0x18, 0x8c, 
0x98, 0x60, 0x10, 0x1c, 0x44, 0x41, 0x47, 0x47, 0x95, 0x4c, 0x65, 0xc2, 
0x5d, 0x3b, 0xbf, 0x35, 0x00, 0x60, 0x70, 0xc1, 0xe0, 0xef, 0x9d, 0xa0, 
0x53, 0xd6, 0x02, 0x86, 0xe6, 0x15, 0x07, 0x02, 0x77, 0xe6, 0x60, 0xe4, 
0xfc, 0xe5, 0x17, 0x3b, 0x76, 0xe9, 0x12, 0x18, 0x4c, 0x19, 0x06, 0x0f, 
0xbb, 0x9a, 0x90, 0x73, 0x52, 0x0a, 0x00, 0x1c, 0xa7, 0x5d, 0x27, 0x05, 
0x08, 0x29, 0x1d, 0xc1, 0x2d, 0x34, 0xa6, 0xa7, 0x3b, 0x82, 0x0b, 0xe2, 
0x8a, 0x21, 0x64, 0xc8, 0x40, 0x42, 0xa7, 0xce, 0x6d, 0x4e, 0x3b, 0x2d, 
0xb7, 0x59, 0x06, 0x80, 0xdb, 0x1f, 0xba, 0xff, 0x17, 0x5b, 0xc9, 0x34, 
0x00, 0x48, 0x00, 0x78, 0xf3, 0xf5, 0xad, 0xaf, 0x76, 0x47, 0xf8, 0xfe, 
0xc7, 0x9f, 0x54, 0x23, 0xbc, 0x7d, 0xe7, 0xf7, 0x5f, 0x6e, 0xdf, 0xf9, 
0x3d, 0xba, 0x9a, 0x50, 0x01, 0xa8, 0x02, 0x40, 0x60, 0xf1, 0x40, 0xb9, 
0x3e, 0x5c, 0xdf, 0xaf, 0x43, 0xca, 0x78, 0x10, 0x62, 0xa1, 0xaf, 0x3a, 
0x3c, 0xe0, 0x0c, 0x8e, 0xeb, 0xb7, 0x73, 0xb9, 0xf4, 0xd7, 0x11, 0x6f, 
0xdb, 0x8e, 0x6f, 0x3c, 0x00, 0xef, 0x46, 0x8d, 0xdc, 0x68, 0x4c, 0x95, 
0xa4, 0xc1, 0x05, 0x9b, 0x7f, 0x46, 0x61, 0xbd, 0xdb, 0xa4, 0x37, 0x19, 
0x47, 0xc8, 0xb9, 0x29, 0x48, 0x05, 0x0a, 0x00, 0x53, 0xa4, 0x14, 0x63, 
0x4c, 0x72, 0x0e, 0x41, 0x04, 0x00, 0x0c, 0x60, 0xc0, 0x6c, 0xf0, 0x04, 
0x10, 0x03, 0x01, 0x9c, 0x04, 0x17, 0x9c, 0x00, 0xd5, 0xe9, 0x50, 0x7e, 
0x61, 0x9f, 0x5f, 0x39, 0x58, 0x21, 0x93, 0xc8, 0xe6, 0xa6, 0x08, 0x59, 
0xc8, 0x59, 0x08, 0x84, 0x60, 0x47, 0x7b, 0x98, 0x13, 0x14, 0x11, 0x38, 
0x07, 0x40, 0x06, 0xec, 0x18, 0x6d, 0x93, 0x17, 0x2e, 0x3b, 0x67, 0xe6, 
0xbb, 0xbd, 0x3f, 0x3f, 0xe7, 0xb7, 0x03, 0xbf, 0xa7, 0xb7, 0xb7, 0x8f, 
0x83, 0x19, 0xed, 0x76, 0xbb, 0xee, 0xfb, 0xed, 0x56, 0xab, 0xe5, 0xb8, 
0x42, 0x48, 0x08, 0x2e, 0xc0, 0x04, 0xc0, 0xc0, 0x40, 0x9c, 0x81, 0x88, 
0x20, 0x39, 0x07, 0x2c, 0x73, 0xf8, 0xf0, 0xa1, 0xc3, 0xb7, 0x99, 0xc2, 
0x00, 0x31, 0xc6, 0x24, 0xb7, 0x3a, 0x82, 0x73, 0x53, 0xa9, 0x00, 0xa6, 
0x69, 0x0b, 0x29, 0xd5, 0x7b, 0x8b, 0xfa, 0x4f, 0xff, 0x82, 0x43, 0x86, 
0xb6, 0x6d, 0x0b, 0x52, 0x2a, 0x74, 0x7d, 0xbf, 0x79, 0x68, 0xfc, 0xb7, 
0xfd, 0x7d, 0x0b, 0x7a, 0x33, 0x85, 0x74, 0x62, 0x02, 0x00, 0x30, 0x36, 
0x3a, 0xb2, 0x70, 0xed, 0xd8, 0x48, 0x6f, 0x94, 0xae, 0x67, 0x9e, 0xbf, 
0x4f, 0x37, 0xe1, 0x8d, 0xeb, 0x47, 0x7b, 0x4e, 0x9c, 0x64, 0xb7, 0xde, 
0xbc, 0xde, 0x04, 0x80, 0xb1, 0xb5, 0xa3, 0xfd, 0x0b, 0x87, 0x06, 0x28, 
0x5f, 0xc8, 0x51, 0xa1, 0x90, 0xa5, 0xbe, 0xc1, 0xfe, 0x0f, 0x72, 0xa5, 
0x9c, 0x5f, 0x2c, 0xe6, 0x69, 0x60, 0xc9, 0x22, 0x75, 0xcb, 0x86, 0xd5, 
0xaf, 0x75, 0xf3, 0x46, 0xaf, 0xb9, 0x72, 0x55, 0x84, 0xd7, 0xae, 0xbe, 
0xec, 0xa1, 0x8d, 0xb7, 0xdd, 0xd8, 0xc3, 0x01, 0xa0, 0xd5, 0x09, 0xb7, 
0x20, 0x54, 0xeb, 0x75, 0xbd, 0xb6, 0x6e, 0x2f, 0x46, 0xb8, 0x51, 0xad, 
0x9f, 0x77, 0xa2, 0x80, 0x89, 0x83, 0xe3, 0x79, 0x00, 0xc8, 0xe7, 0xd3, 
0x61, 0xbb, 0xe9, 0x80, 0x81, 0x40, 0x00, 0x72, 0xb9, 0xfc, 0x69, 0x9c, 
0x88, 0x11, 0x11, 0x8e, 0x54, 0x6b, 0x98, 0xac, 0x4d, 0x8f, 0x75, 0xf3, 
0x8c, 0x8e, 0xb7, 0x31, 0xc2, 0x53, 0xbe, 0x7c, 0x70, 0xb2, 0xed, 0x2c, 
0x98, 0x3d, 0x86, 0x6e, 0xdb, 0x4b, 0x27, 0x72, 0x87, 0xf5, 0x7a, 0xbd, 
0xf8, 0x52, 0x3d, 0x40, 0x18, 0x48, 0x9d, 0x28, 0x20, 0x19, 0xb7, 0x38, 
0x00, 0x64, 0x73, 0xa5, 0xa0, 0xed, 0x74, 0x8e, 0x1e, 0x0f, 0x90, 0xe7, 
0x7b, 0xcb, 0x14, 0xe7, 0x02, 0x04, 0x48, 0x21, 0x30, 0x3e, 0x3e, 0x71, 
0x1c, 0x2f, 0x66, 0x9b, 0x25, 0x7d, 0xba, 0x98, 0xd1, 0xa2, 0xa6, 0x9f, 
0x90, 0x00, 0xa0, 0x02, 0xf0, 0xbd, 0x3f, 0xfc, 0xb8, 0x2f, 0xfa, 0xd3, 
0xf3, 0x5c, 0x5d, 0x82, 0x42, 0x3e, 0x93, 0x9b, 0x73, 0x89, 0x10, 0x8c, 
0x00, 0x60, 0xe8, 0xac, 0xa5, 0x01, 0x63, 0x0a, 0x9c, 0x5b, 0x1e, 0xa0, 
0x54, 0x63, 0xbc, 0x6a, 0x49, 0xc9, 0xbd, 0xd0, 0x80, 0x62, 0xc4, 0x91, 
0x4d, 0x67, 0x0b, 0xdd, 0x3c, 0x62, 0x42, 0x2b, 0x52, 0xbe, 0x6a, 0xba, 
0x14, 0xa6, 0x38, 0x00, 0xc4, 0x63, 0x46, 0xdf, 0xf0, 0xf2, 0x61, 0xbd, 
0x9a, 0x6b, 0x95, 0xaa, 0x1e, 0xc5, 0x96, 0x6d, 0xcf, 0xd9, 0x66, 0x8a, 
0x88, 0x03, 0xc0, 0xc6, 0x3b, 0xee, 0xf9, 0x33, 0x93, 0xcd, 0x7e, 0x5a, 
0xab, 0x56, 0xec, 0x5a, 0xb5, 0x16, 0x37, 0x4a, 0xbd, 0x9f, 0xdc, 0xf5, 
0xe4, 0x53, 0xe9, 0x23, 0x95, 0xc9, 0xe4, 0x64, 0xb5, 0x9a, 0x4c, 0xdb, 
0xd6, 0x03, 0xdd, 0xbc, 0xe9, 0xfa, 0xd4, 0x81, 0xa7, 0x9f, 0xd8, 0xc4, 
0x67, 0xc5, 0x04, 0x75, 0x97, 0x39, 0x31, 0x3e, 0x3b, 0xfb, 0xed, 0xd3, 
0x96, 0x2c, 0x59, 0xa6, 0x87, 0x86, 0x69, 0xc6, 0xf4, 0xf2, 0x69, 0xb7, 
0x9a, 0x73, 0x6e, 0x4d, 0x8c, 0x4b, 0x9d, 0xa1, 0x6c, 0x2a, 0x73, 0x6c, 
0x42, 0x66, 0xe2, 0xdc, 0xa9, 0x4c, 0xe8, 0x92, 0xd9, 0x96, 0x9d, 0xe9, 
0xe6, 0x0d, 0x2e, 0x5a, 0x22, 0xbf, 0xfa, 0xec, 0xf3, 0xd9, 0x71, 0x6f, 
0x66, 0x7c, 0x9b, 0xa5, 0x8a, 0x47, 0x9b, 0xd0, 0x15, 0x8f, 0x3e, 0xfe, 
0xf0, 0x8f, 0xfa, 0xa3, 0x14, 0xe8, 0xc9, 0x27, 0x4d, 0x19, 0x9b, 0x23, 
0x40, 0x08, 0x9d, 0xad, 0xa4, 0x69, 0x7a, 0xc7, 0x32, 0x37, 0xfe, 0x4d, 
0x7d, 0xb2, 0xa2, 0xfd, 0x3a, 0x9e, 0x3f, 0xd3, 0xcd, 0xab, 0xd4, 0x6b, 
0x9f, 0x4d, 0x54, 0x27, 0x30, 0x75, 0x64, 0x92, 0xbb, 0xa1, 0xff, 0xab, 
0xe0, 0xbc, 0x0c, 0x00, 0x18, 0xb9, 0xfa, 0xf2, 0x1b, 0x88, 0x48, 0x47, 
0xb5, 0xf7, 0xbb, 0x1d, 0x7a, 0x75, 0x6e, 0x7d, 0x63, 0xcb, 0x9c, 0x8b, 
0xc5, 0x1b, 0xaf, 0xbe, 0xa4, 0x7d, 0x47, 0x57, 0xad, 0xb8, 0x20, 0xc2, 
0x2f, 0x6f, 0x79, 0xe1, 0xb8, 0x7a, 0x75, 0xbf, 0xf3, 0x44, 0xbb, 0x6a, 
0xe4, 0x92, 0xde, 0xeb, 0x56, 0xaf, 0x9c, 0x77, 0xea, 0x5a, 0x7e, 0xca, 
0xfe, 0x73, 0xfb, 0x0b, 0xec, 0xba, 0x4a, 0x21, 0xcb, 0x25, 0xef, 0x57, 
0x00, 0x00, 0x00, 0x00, 0x49, 0x45, 0x4e, 0x44, 0xae, 0x42, 0x60, 0x82, 
};
