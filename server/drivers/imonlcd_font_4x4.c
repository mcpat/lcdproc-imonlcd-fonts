// -*- coding:utf-8 -*-
/*
 * $Id$
 *
 *  Created on: 14.03.2010
 *      Author: Marcel Patzlaff
 *     Version: $Revision:$
 */

#include "imonlcd_fonts.h"

static const char _4x4_normal_chars[256][4]= {
    { 0x0, 0x0, 0x0, 0x0 }, //   0 \u0020 space
    { 0x8, 0x2, 0x8, 0x0 }, //   1 \u263a light smiley face
    { 0x6, 0xc, 0x6, 0x0 }, //   2 \u263b dark smiley face
    { 0xe, 0x7, 0x7, 0xe }, //   3 \u2665 full heart
    { 0xc, 0x6, 0xc, 0x0 }, //   4        small heart
    { 0x0, 0x6, 0x6, 0x0 }, //   5 \u2660 club // TODO
    { 0x0, 0x6, 0x6, 0x0 }, //   6 \u2660 spade // TODO
    { 0x0, 0x6, 0x6, 0x0 }, //   7 \u2022 bullet
    { 0xf, 0x9, 0x9, 0xf }, //   8 \u25d8 big rectangle
    { 0x0, 0x6, 0x6, 0x0 }, //   9 \u25cb small rectangle
    { 0x0, 0x6, 0x6, 0x0 }, //  10 \u25d9 filled rectangle // TODO
    { 0x0, 0x6, 0x6, 0x0 }, //  11 \u2642 man symbol // TODO
    { 0x0, 0x6, 0x6, 0x0 }, //  12 \u2640 woman symbol // TODO
    { 0x0, 0x6, 0x6, 0x0 }, //  13 \u266a musical note // TODO
    { 0x0, 0x6, 0x6, 0x0 }, //  14 \u266b double music note // TODO
    { 0x0, 0x6, 0x6, 0x0 }, //  15 \u25cf record // TODO
    { 0x0, 0x6, 0x6, 0x0 }, //  16 \u25b6 play // TODO
    { 0x0, 0x6, 0x6, 0x0 }, //  17 \u25c0 play backwards // TODO
    { 0x0, 0x6, 0x6, 0x0 }, //  18        pause // TODO
    { 0x0, 0x6, 0x6, 0x0 }, //  19 \u25fe stop // TODO
    { 0x0, 0x6, 0x6, 0x0 }, //  20 \u23cf eject // TODO
    { 0x0, 0x6, 0x6, 0x0 }, //  21        fwd // TODO
    { 0x0, 0x6, 0x6, 0x0 }, //  22        rev // TODO
    { 0x1, 0x1, 0x1, 0x1 }, //  23 \u2581 lower 1/8 block (full)
    { 0x1, 0x1, 0x1, 0x1 }, //  24 \u2582 lower 1/4 block (full)
    { 0x3, 0x3, 0x3, 0x3 }, //  25 \u2583 lower 3/8 block (full)
    { 0x3, 0x3, 0x3, 0x3 }, //  26 \u2584 lower 1/2 block (full)
    { 0x7, 0x7, 0x7, 0x7 }, //  27 \u2585 lower 5/8 block (full)
    { 0x7, 0x7, 0x7, 0x7 }, //  28 \u2586 lower 3/4 block (full)
    { 0xf, 0xf, 0xf, 0xf }, //  29 \u2587 lower 7/8 block (full)
    { 0x0, 0x0, 0x0, 0x0 }, //  30
    { 0x0, 0x0, 0x0, 0x0 }, //  31
    { 0x0, 0x0, 0x0, 0x0 }, //  32 \u0020 space
    { 0x0, 0x6, 0x6, 0x0 }, //  33 \u0021 ! // TODO
    { 0x0, 0x6, 0x6, 0x0 }, //  34 \u0022 " // TODO
    { 0x0, 0x6, 0x6, 0x0 }, //  35 \u0023 # // TODO
    { 0x0, 0x6, 0x6, 0x0 }, //  36 \u0024 $ // TODO
    { 0x0, 0x6, 0x6, 0x0 }, //  37 \u0025 % // TODO
    { 0x0, 0x6, 0x6, 0x0 }, //  38 \u0026 & // TODO
    { 0x0, 0x8, 0x0, 0x0 }, //  39 \u0027 '
    { 0x0, 0x6, 0x9, 0x0 }, //  40 \u0028 (
    { 0x0, 0x9, 0x6, 0x0 }, //  41 \u0029 )
    { 0x0, 0x4, 0x0, 0x0 }, //  42 \u002a *
    { 0x4, 0xe, 0x4, 0x0 }, //  43 \u002b +
    { 0x0, 0x3, 0x0, 0x0 }, //  44 \u002c ,
    { 0x4, 0x4, 0x4, 0x0 }, //  45 \u002d -
    { 0x0, 0x2, 0x0, 0x0 }, //  46 \u002e .
    { 0x2, 0x4, 0x8, 0x0 }, //  47 \u002f /
    { 0xe, 0xa, 0xe, 0x0 }, //  48 \u0030 0
    { 0x0, 0x8, 0xe, 0x0 }, //  49 \u0031 1
    { 0x8, 0xe, 0x2, 0x0 }, //  50 \u0032 2
    { 0xa, 0xa, 0xe, 0x0 }, //  51 \u0033 3
    { 0xc, 0x6, 0x4, 0x0 }, //  52 \u0034 4
    { 0x2, 0xe, 0x8, 0x0 }, //  53 \u0035 5
    { 0xe, 0x6, 0x6, 0x0 }, //  54 \u0036 6
    { 0x8, 0x8, 0xe, 0x0 }, //  55 \u0037 7
    { 0xe, 0xe, 0xe, 0x0 }, //  56 \u0038 8
    { 0xc, 0xc, 0xe, 0x0 }, //  57 \u0039 9
    { 0x0, 0xa, 0x0, 0x0 }, //  58 \u003a :
    { 0x0, 0xb, 0x0, 0x0 }, //  59 \u003b ;
    { 0x0, 0x4, 0xa, 0x0 }, //  60 \u003c <
    { 0xa, 0xa, 0xa, 0x0 }, //  61 \u003d =
    { 0x0, 0xa, 0x4, 0x0 }, //  62 \u003e >
    { 0x0, 0x6, 0x6, 0x0 }, //  63 \u003f ? // TODO
    { 0x0, 0x6, 0x6, 0x0 }, //  64 \u0040 @ // TODO
    { 0x6, 0xc, 0x6, 0x0 }, //  65 \u0041 A
    { 0xe, 0xe, 0xa, 0x0 }, //  66 \u0042 B
    { 0x4, 0xa, 0xa, 0x0 }, //  67 \u0043 C
    { 0xe, 0xa, 0x4, 0x0 }, //  68 \u0044 D
    { 0xe, 0xa, 0xa, 0x0 }, //  69 \u0045 E
    { 0xe, 0x4, 0x0, 0x0 }, //  70 \u0046 F
    { 0xe, 0x2, 0x6, 0x0 }, //  71 \u0047 G
    { 0xe, 0x4, 0xe, 0x0 }, //  72 \u0048 H
    { 0x0, 0xe, 0x0, 0x0 }, //  73 \u0049 I
    { 0x0, 0x2, 0xc, 0x0 }, //  74 \u004a J
    { 0xe, 0x4, 0xa, 0x0 }, //  75 \u004b K
    { 0xc, 0x2, 0x2, 0x0 }, //  76 \u004c L
    { 0xe, 0xc, 0xe, 0x0 }, //  77 \u004d M
    { 0xe, 0x8, 0xe, 0x0 }, //  78 \u004e N
    { 0xe, 0xa, 0xe, 0x0 }, //  79 \u004f O
    { 0xe, 0xc, 0xc, 0x0 }, //  80 \u0050 P
    { 0xe, 0xb, 0xe, 0x0 }, //  81 \u0051 Q
    { 0xe, 0xc, 0xa, 0x0 }, //  82 \u0052 R
    { 0x2, 0xe, 0x8, 0x0 }, //  83 \u0053 S
    { 0x8, 0xe, 0x8, 0x0 }, //  84 \u0054 T
    { 0xe, 0x2, 0xe, 0x0 }, //  85 \u0055 U
    { 0xc, 0x2, 0xc, 0x0 }, //  86 \u0056 V
    { 0xe, 0x6, 0xe, 0x0 }, //  87 \u0057 W
    { 0xa, 0x4, 0xa, 0x0 }, //  88 \u0058 X
    { 0xc, 0x6, 0xc, 0x0 }, //  89 \u0059 Y
    { 0x8, 0xe, 0x2, 0x0 }, //  90 \u005a Z
    { 0x0, 0xf, 0x9, 0x0 }, //  91 \u005b [
    { 0x8, 0x4, 0x2, 0x1 }, //  92 \u005c backslash
    { 0x0, 0x9, 0xf, 0x0 }, //  93 \u005d ]
    { 0x4, 0x8, 0x4, 0x0 }, //  94 \u005e ^
    { 0x1, 0x1, 0x1, 0x1 }, //  95 \u005f _
    { 0x0, 0x8, 0x0, 0x0 }, //  96 \u0060 `
    { 0x6, 0xc, 0x6, 0x0 }, //  97 \u0061 a
    { 0xe, 0xe, 0xa, 0x0 }, //  98 \u0062 b
    { 0x4, 0xa, 0xa, 0x0 }, //  99 \u0063 c
    { 0xe, 0xa, 0x4, 0x0 }, // 100 \u0064 d
    { 0xe, 0xa, 0xa, 0x0 }, // 101 \u0065 e
    { 0xe, 0x4, 0x0, 0x0 }, // 102 \u0066 f
    { 0xe, 0x2, 0x6, 0x0 }, // 103 \u0067 g
    { 0xe, 0x4, 0xe, 0x0 }, // 104 \u0068 h
    { 0x0, 0xe, 0x0, 0x0 }, // 105 \u0069 i
    { 0x0, 0x2, 0xc, 0x0 }, // 106 \u006a j
    { 0xe, 0x4, 0xa, 0x0 }, // 107 \u006b k
    { 0xc, 0x2, 0x2, 0x0 }, // 108 \u006c l
    { 0xe, 0xc, 0xe, 0x0 }, // 109 \u006d m
    { 0xe, 0x8, 0xe, 0x0 }, // 110 \u006e n
    { 0xe, 0xa, 0xe, 0x0 }, // 111 \u006f o
    { 0xe, 0xc, 0xc, 0x0 }, // 112 \u0070 p
    { 0xe, 0xb, 0xe, 0x0 }, // 113 \u0071 q
    { 0xe, 0xc, 0xa, 0x0 }, // 114 \u0072 r
    { 0x2, 0xe, 0x8, 0x0 }, // 115 \u0073 s
    { 0x8, 0xe, 0x8, 0x0 }, // 116 \u0074 t
    { 0xe, 0x2, 0xe, 0x0 }, // 117 \u0075 u
    { 0xc, 0x2, 0xc, 0x0 }, // 118 \u0076 v
    { 0xe, 0x6, 0xe, 0x0 }, // 119 \u0077 w
    { 0xa, 0x4, 0xa, 0x0 }, // 120 \u0078 x
    { 0xc, 0x6, 0xc, 0x0 }, // 121 \u0079 y
    { 0x8, 0xe, 0x2, 0x0 }, // 122 \u007a z
    { 0x0, 0x6, 0x9, 0x0 }, // 123 \u007b {
    { 0x0, 0xf, 0x0, 0x0 }, // 124 \u007c |
    { 0x0, 0x9, 0x6, 0x0 }, // 125 \u007d }
    { 0x0, 0x4, 0x2, 0x0 }, // 126 \u007e ~
    { 0x0, 0x1, 0x1, 0x0 }, // 127 \u2581 lower 1/8 block (trim)
    { 0x0, 0x1, 0x1, 0x0 }, // 128 \u2582 lower 1/4 block (trim)
    { 0x0, 0x3, 0x3, 0x0 }, // 129 \u2583 lower 3/8 block (trim)
    { 0x0, 0x3, 0x3, 0x0 }, // 130 \u2584 lower 1/2 block (trim)
    { 0x0, 0x7, 0x7, 0x0 }, // 131 \u2585 lower 5/8 block (trim)
    { 0x0, 0x7, 0x7, 0x0 }, // 132 \u2586 lower 3/4 block (trim)
    { 0x0, 0xf, 0xf, 0x0 }, // 133 \u2587 lower 7/8 block (trim)
    { 0x0, 0xf, 0xf, 0x0 }, // 134 \u2588 full block (vert trim)
    { 0x6, 0x0, 0x0, 0x0 }, // 135 \u258f left 1/6 block (trim)
    { 0x6, 0x0, 0x0, 0x0 }, // 136 \u258e left 1/3 block (trim)
    { 0x6, 0x6, 0x0, 0x0 }, // 137 \u258c left 1/2 block (trim)
    { 0x6, 0x6, 0x6, 0x0 }, // 138 \u258b left 2/3 block (trim)
    { 0x6, 0x6, 0x6, 0x6 }, // 139 \u258a left 5/6 block (trim)
    { 0x6, 0x6, 0x6, 0x6 }, // 140 \u2588 full block (horiz trim)
    { 0xf, 0xf, 0xf, 0xf }, // 141 \u2588 really full block
    { 0x0, 0x6, 0x6, 0x0 }, // 142 \u03b4 delta // TODO
    { 0x0, 0x6, 0x6, 0x0 }, // 143 \u03b5 epsilon // TODO
    { 0x0, 0x6, 0x6, 0x0 }, // 144 \u03c0 pi // TODO
    { 0x0, 0x6, 0x6, 0x0 }, // 145 \u03c3 sigma // TODO
    { 0x0, 0x6, 0x6, 0x0 }, // 146 \u03c4 tau // TODO
    { 0x0, 0x6, 0x6, 0x0 }, // 147 \u03c6 phi // TODO
    { 0x0, 0x6, 0x6, 0x0 }, // 148 \u221e infinity // TODO
    { 0x0, 0x6, 0x6, 0x0 }, // 149 \u0393 Gamma // TODO
    { 0x0, 0x6, 0x6, 0x0 }, // 150 \u0398 Theta // TODO
    { 0x0, 0x6, 0x6, 0x0 }, // 151 \u03a6 Phi // TODO
    { 0x0, 0x6, 0x6, 0x0 }, // 152 \u03a9 Omega // TODO
    { 0x0, 0x6, 0x6, 0x0 }, // 153        left half of mail icon // TODO
    { 0x0, 0x6, 0x6, 0x0 }, // 154        right half of mail icon // TODO
    { 0x0, 0x6, 0x6, 0x0 }, // 155 \u2190 left arrow // TODO
    { 0x0, 0x6, 0x6, 0x0 }, // 156 \u2191 up arrow // TODO
    { 0x0, 0x6, 0x6, 0x0 }, // 157 \u2192 right arrow // TODO
    { 0x0, 0x6, 0x6, 0x0 }, // 158 \u2193 down arrow // TODO
    { 0x0, 0x6, 0x6, 0x0 }, // 159 \u2194 left right arrrow // TODO
    { 0x0, 0x6, 0x6, 0x0 }, // 160 // TODO
    { 0x0, 0x6, 0x6, 0x0 }, // 161 \u00a1 ¡ inverted exclamation mark // TODO
    { 0x0, 0x6, 0x6, 0x0 }, // 162 \u00a2 ¢ cent // TODO
    { 0x0, 0x6, 0x6, 0x0 }, // 163 \u00a3 £ pound // TODO
    { 0x0, 0x6, 0x6, 0x0 }, // 164 \u20ac € euro // TODO
    { 0x0, 0x6, 0x6, 0x0 }, // 165 \u00a5 ¥ yen // TODO
    { 0x0, 0x6, 0x6, 0x0 }, // 166 \u0160 Š capital S with caron // TODO
    { 0x0, 0x6, 0x6, 0x0 }, // 167 \u00a7 § section // TODO
    { 0x0, 0x6, 0x6, 0x0 }, // 168 \u0161 š small s with caron // TODO
    { 0x0, 0x6, 0x6, 0x0 }, // 169 \u00a9 © copyright // TODO
    { 0x0, 0x6, 0x6, 0x0 }, // 170 \u00aa ª feminine ordinal // TODO
    { 0x0, 0x6, 0x6, 0x0 }, // 171 \u00ab « left double angle // TODO
    { 0x0, 0x6, 0x6, 0x0 }, // 172 \u00ac ¬ not // TODO
    { 0x0, 0x6, 0x6, 0x0 }, // 173 \u00ad ­ hyphen // TODO
    { 0x0, 0x6, 0x6, 0x0 }, // 174 \u00ae ® registered // TODO
    { 0x0, 0x6, 0x6, 0x0 }, // 175 \u00af ¯ macron // TODO
    { 0x0, 0x6, 0x6, 0x0 }, // 176 \u00b0 ° degree // TODO
    { 0x0, 0x6, 0x6, 0x0 }, // 177 \u00b1 ± plus-minus // TODO
    { 0x0, 0x6, 0x6, 0x0 }, // 178 \u00b2 ² superscript 2 // TODO
    { 0x0, 0x6, 0x6, 0x0 }, // 179 \u00b3 ³ superscript 3 // TODO
    { 0x0, 0x6, 0x6, 0x0 }, // 180 \u017d Ž Z caron // TODO
    { 0x0, 0x6, 0x6, 0x0 }, // 181 \u00b5 µ micro // TODO
    { 0x0, 0x6, 0x6, 0x0 }, // 182 \u00b6 ¶ paragraph // TODO
    { 0x0, 0x4, 0x0, 0x0 }, // 183 \u00b7 · middle dot
    { 0x0, 0x6, 0x6, 0x0 }, // 184 \u017e ž z caron // TODO
    { 0x0, 0x6, 0x6, 0x0 }, // 185 \u00b9 ¹ superscript 1 // TODO
    { 0x0, 0x6, 0x6, 0x0 }, // 186 \u00ba º masculine ordinal // TODO
    { 0x0, 0x6, 0x6, 0x0 }, // 187 \u00bb » right double angle // TODO
    { 0xe, 0xa, 0xe, 0x0 }, // 188 \u0152 Œ OE
    { 0xe, 0xa, 0xe, 0x0 }, // 189 \u0153 œ oe
    { 0xc, 0x6, 0xc, 0x0 }, // 190 \u0178 Ÿ Y diaeresis
    { 0x0, 0x6, 0x6, 0x0 }, // 191 \u00bf ¿ inverted question mark // TODO
    { 0x6, 0xc, 0x6, 0x0 }, // 192 \u00c0 À A grave
    { 0x6, 0xc, 0x6, 0x0 }, // 193 \u00c1 Á A acute
    { 0x6, 0xc, 0x6, 0x0 }, // 194 \u00c2 Â A circumflex
    { 0x6, 0xc, 0x6, 0x0 }, // 195 \u00c3 Ã A tilde
    { 0x6, 0xc, 0x6, 0x0 }, // 196 \u00c4 Ä A diaeresis
    { 0x6, 0xc, 0x6, 0x0 }, // 197 \u00c5 Å A ring
    { 0x6, 0xc, 0x6, 0x0 }, // 198 \u00c6 Æ AE
    { 0x4, 0xa, 0xa, 0x0 }, // 199 \u00c7 Ç C cedilla
    { 0xe, 0xa, 0xa, 0x0 }, // 200 \u00c8 È E grave
    { 0xe, 0xa, 0xa, 0x0 }, // 201 \u00c9 É E acute
    { 0xe, 0xa, 0xa, 0x0 }, // 202 \u00ca Ê E circumflex
    { 0xe, 0xa, 0xa, 0x0 }, // 203 \u00cb Ë E diaeresis
    { 0x0, 0xe, 0x0, 0x0 }, // 204 \u00cc Ì I grave
    { 0x0, 0xe, 0x0, 0x0 }, // 205 \u00cd Í I acute
    { 0x0, 0xe, 0x0, 0x0 }, // 206 \u00ce Î I circumflex
    { 0x0, 0xe, 0x0, 0x0 }, // 207 \u00cf Ï I diaeresis
    { 0x0, 0x6, 0x6, 0x0 }, // 208 \u00d0 Ð Eth // TODO
    { 0x0, 0x6, 0x6, 0x0 }, // 209 \u00d1 Ñ N tilde // TODO
    { 0xe, 0xa, 0xe, 0x0 }, // 210 \u00d2 Ò O grave
    { 0xe, 0xa, 0xe, 0x0 }, // 211 \u00d3 Ó O acute
    { 0xe, 0xa, 0xe, 0x0 }, // 212 \u00d4 Ô O circumflex
    { 0xe, 0xa, 0xe, 0x0 }, // 213 \u00d5 Õ O tilde
    { 0xe, 0xa, 0xe, 0x0 }, // 214 \u00d6 Ö O diaeresis
    { 0x0, 0x4, 0x0, 0x0 }, // 215 \u00d7 × multiplication
    { 0xe, 0xa, 0xe, 0x0 }, // 216 \u00d8 Ø O slash
    { 0xe, 0x2, 0xe, 0x0 }, // 217 \u00d9 Ù U grave
    { 0xe, 0x2, 0xe, 0x0 }, // 218 \u00da Ú U acute
    { 0xe, 0x2, 0xe, 0x0 }, // 219 \u00db Û U circumflex
    { 0xe, 0x2, 0xe, 0x0 }, // 220 \u00dc Ü U diaeresis
    { 0xc, 0x6, 0xc, 0x0 }, // 221 \u00dd Ý Y acute
    { 0x0, 0x6, 0x6, 0x0 }, // 222 \u00de Þ Thorn // TODO
    { 0xf, 0xe, 0xa, 0x0 }, // 223 \u00df ß Eszett
    { 0x6, 0xc, 0x6, 0x0 }, // 224 \u00e0 à a grave
    { 0x6, 0xc, 0x6, 0x0 }, // 225 \u00e1 á a acute
    { 0x6, 0xc, 0x6, 0x0 }, // 226 \u00e2 â a circumplex
    { 0x6, 0xc, 0x6, 0x0 }, // 227 \u00e3 ã a tilde
    { 0x6, 0xc, 0x6, 0x0 }, // 228 \u00e4 ä a diaeresis
    { 0x6, 0xc, 0x6, 0x0 }, // 229 \u00e5 å a ring
    { 0x6, 0xc, 0x6, 0x0 }, // 230 \u00e6 æ ae
    { 0x4, 0xa, 0xa, 0x0 }, // 231 \u00e7 ç c cedilla
    { 0xe, 0xa, 0xa, 0x0 }, // 232 \u00e8 è e grave
    { 0xe, 0xa, 0xa, 0x0 }, // 233 \u00e9 é e acute
    { 0xe, 0xa, 0xa, 0x0 }, // 234 \u00ea ê e circumflex
    { 0xe, 0xa, 0xa, 0x0 }, // 235 \u00eb ë e diaeresis
    { 0x0, 0xe, 0x0, 0x0 }, // 236 \u00ec ì i grave
    { 0x0, 0xe, 0x0, 0x0 }, // 237 \u00ed í i acute
    { 0x0, 0xe, 0x0, 0x0 }, // 238 \u00ee î i circumflex
    { 0x0, 0xe, 0x0, 0x0 }, // 239 \u00ef ï i diaeresis
    { 0x0, 0x6, 0x6, 0x0 }, // 240 \u00f0 ð eth // TODO
    { 0x0, 0x6, 0x6, 0x0 }, // 241 \u00f1 ñ n tilde // TODO
    { 0xe, 0xa, 0xe, 0x0 }, // 242 \u00f2 ò o grave
    { 0xe, 0xa, 0xe, 0x0 }, // 243 \u00f3 ó o acute
    { 0xe, 0xa, 0xe, 0x0 }, // 244 \u00f4 ô o circumflex
    { 0xe, 0xa, 0xe, 0x0 }, // 245 \u00f5 õ o tilde
    { 0xe, 0xa, 0xe, 0x0 }, // 246 \u00f6 ö o diaeresis
    { 0x0, 0x6, 0x6, 0x0 }, // 247 \u00f7 ÷ division // TODO
    { 0xe, 0xa, 0xe, 0x0 }, // 248 \u00f8 ø o slash
    { 0xe, 0x2, 0xe, 0x0 }, // 249 \u00f9 ù u grave
    { 0xe, 0x2, 0xe, 0x0 }, // 250 \u00fa ú u acute
    { 0xe, 0x2, 0xe, 0x0 }, // 251 \u00fb û u circumflex
    { 0xe, 0x2, 0xe, 0x0 }, // 252 \u00fc ü u diaeresis
    { 0xc, 0x6, 0xc, 0x0 }, // 253 \u00fd ý y acute
    { 0x0, 0x6, 0x6, 0x0 }, // 254 \u00fe þ thorn // TODO
    { 0xc, 0x6, 0xc, 0x0 }  // 255 \u00ff ÿ y diaeresis
};

static char* _4x4_get_char_pixels(unsigned const char idx) {
    return _4x4_normal_chars[idx];
}

static short* _4x4_get_big_char_pixels(unsigned const char idx) {
    return 0;
}

const imonlcd_font imonlcd_font_4x4= {
    4, 4,
    _4x4_get_char_pixels,
    _4x4_get_big_char_pixels
};
