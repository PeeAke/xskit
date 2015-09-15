#include <xs/pal.h>
#include <xs/canvas.h>
#include <xs/memory.h>
#include <xs/coreclassid.h>
#include <xs/string.h>
#include <xs/resource.h>

xsCanvas::xsCanvas()
{
	context = NULL;
	setFlag(0);
	xsGetScreenDimension(&width, &height);
}

xsCanvas::~xsCanvas()
{
	if (context != NULL)
		context->destroyInstance();
}

int xsCanvas::getWidth(void)
{
	return width;
}
int xsCanvas::getHeight(void)
{
	return height;
}

void xsCanvas::getPreferredSize(int proposedWidth, xsMetrics *m)
{
	//m->width = width;
	//m->height = height;
}

void xsCanvas::paint(xsGraphics *gc)
{
	if (context == NULL)
		return;

	//context->paint(gc);
}

xsCanvasContext *xsCanvas::getContext()
{
	if (context != NULL)
		return context;

	context = static_cast<xsCanvasContext *>(xsCanvasContext::createInstance());
	return context;
}

void xs_canvas_demo(void)
{
	xsCanvas canvas;
	xsCanvasContext *ctx = canvas.getContext();
//	ctx ->scale(2,3);
//	ctx ->rotate(20);
//	ctx ->translate(50,50);
//	ctx ->transform(1,0.5,-0.5,1,30,10);
	ctx->save();
//	ctx->lineWidth = 5.0;
	ctx->moveTo(20,20);
	ctx->lineTo(50,50);
	ctx->lineTo(20,50);
//	ctx->rect(50,50,50,50);
	xsColor black = {255,0,0,0};
	ctx->strokeColor = black;
	ctx->stroke();
	xsColor red = {255,255,0,0};
	ctx->fillColor = red;
	ctx->fill();
	ctx->beginPath();
	ctx->lineTo(120,120);
	ctx->lineTo(150,150);
	ctx->restore();
	ctx->closePath();
	ctx->stroke();
	ctx->fillRect(130,20,20,20);
	ctx->strokeRect(160,20,20,20);
	ctx->clearRect(20,20,20,20);
	ctx->arc(20,100,20,0, 3.14);
	ctx ->bezierCurveTo(100, 100, 130, 80, 170, 100);
	ctx ->stroke();
	ctx ->fill();
	//ctx->arc(20,100,20,0,90,true);
	xsImageParam param = {100, 100, 0};
	xsImage image = {XS_IMGTYPE_UNKNOWN, XS_AFD_FILENAME, L"C:\Users\Lewis\git\icon_bt.bmp", 0, 0, 0, (void *)&param};
	ctx->drawImage(&image,200,200);
	//ctx->drawImage(&image,20,20,20,20,20,20,20,20);
	ctx->fillText(L"AAAAA",10,50,50);
	ctx->strokeText(L"def",10,100,200);
}

