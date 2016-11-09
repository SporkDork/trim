#ifndef TGFX_H
#define TGFX_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRIM_RGB 0
#define TRIM_256 1
#define TRIM_16  2

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct {
	u8 r, g, b, a;
} tcolour;

typedef struct {
	tcolour bg;
	tcolour fg;
	char ch;
} tpixel;

typedef struct {
	tpixel *pix;
	int w, h;
	int x, y;
	int mode;
} tsprite;

typedef struct {
	tcolour *img;
	int w, h;
} ttexture;

typedef struct {
	float tx, ty; // Coordinates of a point as mapped on a sprite
	float sx, sy; // Coordinates of a point as mapped to the screen
} tpoint;

typedef struct {
	ttexture tex;
	tpoint point[4];
	int n_points;
} tpolygon;

static const tcolour _trim_16cp[] = {
	{  0,   0,   0, 255}, {  0,   0, 128, 255},
	{  0, 128,   0, 255}, {  0, 128, 128, 255},
	{128,   0,   0, 255}, {128,   0, 128, 255},
	{128, 128,   0, 255}, {192, 192, 192, 255},
	{128, 128, 128, 255}, {  0,   0, 255, 255},
	{  0, 230,   0, 255}, {  0, 255, 255, 255},
	{255,   0,   0, 255}, {255,   0, 255, 255},
	{255, 255,   0, 255}, {255, 255, 255, 255}
};

tsprite *trim_initvideo(int win_w, int win_h, int sc_w, int sc_h, int mode);
void trim_closevideo(tsprite *s);

int trim_openbmp(ttexture *tex, char *name);

void trim_blendcolour(tcolour *dst, tcolour *src);

void trim_createpixel(tpixel *p, tcolour *bg, tcolour *fg, char ch);
tsprite *trim_createsprite(int w, int h, int x, int y, int mode);

void trim_fillsprite(tsprite *spr, tpixel *p);
void trim_applysprite(tsprite *dst, tsprite *src);
void trim_printsprite(tsprite *spr, char *str, int x, int y, int lr);

void trim_renderpolygon(ttexture *tex, tpolygon *poly);
void trim_scaletexture(ttexture *dst, ttexture *src, int w, int h);
void trim_rendertexture(tsprite *spr, ttexture *tex, int x, int y, int w, int h);

void trim_drawsprite(tsprite *s);
void trim_closesprite(tsprite *s);

#endif
