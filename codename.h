/*
 Copyright (c) 2016 Jacob Gordon. All rights reserved.
 
 Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
 
 1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
 
 2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the
 documentation and/or other materials provided with the distribution.
 
 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR
 TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef JHG_GL_codename_h
#define JHG_GL_codename_h

#include "JHGPixelslib.h"

#define MAX_JHG(a,b) (((a)>(b))?(a):(b))

#define MIN_JHG(a,b) (((a)<(b))?(a):(b))

#define ABS_JHG(a) (((a)<0) ? -(a) : (a))

#define ZSGN_JHG(a) (((a)<0) ? -1 : (a)>0 ? 1 : 0)

//types
typedef JHGPixelcolor_Object* codename_pixelcolor ;
typedef JHGsubpixel cn_RGBcolor ;
typedef JHGPixels_scene codename_pixelscene ;
typedef struct { int x ; int y ; } cn_point ;
typedef struct { codename_pixelscene pixelscene ; cn_point origin ; } codename_scene_object ;
typedef codename_scene_object* codename_scene ;

//funcs
int codename_createcanvas(codename_pixelscene pixelscene, int (*canvas_funtion)(codename_pixelscene pixelscene));
int codename_testfunc(codename_pixelscene pixelscene);
codename_pixelcolor codename_NewColorObject( cn_RGBcolor red, cn_RGBcolor blue, cn_RGBcolor green ) ;
codename_scene codename_NewSceneObject(codename_pixelscene pixelscene, int origin_x, int origin_y) ;
void codename_movescene(codename_scene pointscene, cn_point neworigin) ;
void codename_ChangeBackGroundColor(codename_scene pointscene, cn_RGBcolor red, cn_RGBcolor blue, cn_RGBcolor green );

//Pixel Op funcs
void codename_SetPixel(codename_scene pointscene, int x, int y, cn_RGBcolor red, cn_RGBcolor blue, cn_RGBcolor green);
void cn_SetPixel(codename_scene pointscene, int x, int y, cn_RGBcolor red, cn_RGBcolor blue, cn_RGBcolor green);
void cnpixel_SetColor(codename_scene pointscene, int x, int y, codename_pixelcolor pixcolor);

//Point Op funcs
void cn_SetPoint(codename_scene pointscene, int x, int y, cn_RGBcolor red, cn_RGBcolor blue, cn_RGBcolor green) ;
void cnpoint_SetColor_and_free(codename_scene pointscene, int x, int y, codename_pixelcolor pixcolor) ;
codename_pixelcolor cn_GetPoint(codename_scene pointscene, int x, int y) ;
void cn_GetRBG(codename_scene pointscene, int x, int y, cn_RGBcolor* red, cn_RGBcolor* blue, cn_RGBcolor* green) ;
void cn_SetArcPoint(codename_scene pointscene, int x, int y, int a, int b, int r, double alpha, double beta, cn_RGBcolor red, cn_RGBcolor blue, cn_RGBcolor green) ;

//shapes

//--Lines--
void cnpixel_vline(codename_scene pointscene, int v);
void cnpixel_colorvline(codename_scene pointscene, int v, cn_RGBcolor red, cn_RGBcolor blue, cn_RGBcolor green);
void cnpixel_vlinewithcolor(codename_scene pointscene, int v, codename_pixelcolor pixcolor);
void cnpixel_line(codename_scene pointscene, float m, float b, float scale, cn_RGBcolor red, cn_RGBcolor blue, cn_RGBcolor green );
void cnpixel_linewithcolor(codename_scene pointscene, float m, float b, float scale, codename_pixelcolor pixcolor );
void cnpixel_line_lowp(codename_scene pointscene, int m, int b, int scale, cn_RGBcolor red, cn_RGBcolor blue, cn_RGBcolor green );
void cnpixel_linewithcolor_lowp(codename_scene pointscene, int m, int b, int scale, codename_pixelcolor pixcolor );
void cnpoint_dotline(codename_scene pointscene, int line[], int x, int y, int size, cn_RGBcolor red, cn_RGBcolor blue, cn_RGBcolor green) ;
void cnpoint_linesegment_with_thickness(codename_scene pointscene, int x1, int y1, int x2, int y2, int thickness, cn_RGBcolor red, cn_RGBcolor blue, cn_RGBcolor green) ;
void cnpoint_linesegment(codename_scene pointscene,int x1, int y1, int x2, int y2, cn_RGBcolor red, cn_RGBcolor blue, cn_RGBcolor green) ;
void cnpoint_line3d(codename_scene pointscene,int x1, int y1, int x2, int y2, int z1, int z2, cn_RGBcolor red, cn_RGBcolor blue, cn_RGBcolor green) ;
void cnpoint_line3d_with_thickness(codename_scene pointscene, int x1, int y1, int x2, int y2, int z1, int z2, int thickness, cn_RGBcolor red, cn_RGBcolor blue, cn_RGBcolor green) ;

//--Rectangles--
void cnpoint_Rect(codename_scene pointscene, int size_x, int size_y, int x, int y, cn_RGBcolor red, cn_RGBcolor blue, cn_RGBcolor green ) ; 

//--Circles--
void cnpixel_circle(codename_scene pointscene, float a, float b, float r, cn_RGBcolor red, cn_RGBcolor blue, cn_RGBcolor green );
void cnpoint_wikiCircle(codename_scene pointscene, int a, int b, int r, cn_RGBcolor red, cn_RGBcolor blue, cn_RGBcolor green);
void cnpoint_wikiArc(codename_scene pointscene, int a, int b, int r, double alpha, double beta, cn_RGBcolor red, cn_RGBcolor blue, cn_RGBcolor green) ;

//--Curves--
void cnpoint_Curve(codename_scene pointscene,int x0, int y0, int x1, int y1, int x2, int y2, cn_RGBcolor red, cn_RGBcolor blue, cn_RGBcolor green)  ;

//--Text--
void cnpoint_String(codename_scene pointscene, const char* string, int size, int x, int y, cn_RGBcolor red, cn_RGBcolor blue, cn_RGBcolor green) ;
void cnpoint_printchar(codename_scene pointscene, char c, int size, int x, int y, cn_RGBcolor red, cn_RGBcolor blue, cn_RGBcolor green) ;
#endif
