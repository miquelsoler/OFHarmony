//
// Created by Miquel Ëngel Soler on 15/12/15.
//

#include "PMRibbonPainter.h"

PMRibbonPainter::PMRibbonPainter(ofColor _color, float _dx, float _dy, float _ax, float _ay, float _div, float _ease)
{
    color = ofColor::black;

    dx = _dx; dy = _dy;
    ax = _ax; ay = _ay;
    div = _div;
    ease = _ease;

    path.setMode(ofPath::POLYLINES);
    path.setStrokeColor(color);
    path.setFilled(false);
    path.setStrokeWidth(1);
    path.setCurveResolution(500);
    path.setCircleResolution(500);
}

void PMRibbonPainter::draw()
{
    ofEnableBlendMode(OF_BLENDMODE_ADD);
    path.draw();
    ofDisableBlendMode();
}

void PMRibbonPainter::setPosition(int x, int y)
{
    path.moveTo(dx, dy);

    dx -= ax = (ax + (dx - x) * div) * ease;
    dy -= ay = (ay + (dy - y) * div) * ease;

    ofColor currentColor = ofColor(127, color.g, color.b, 127);
    path.setStrokeColor(currentColor);

//    this.context.strokeStyle = "rgba(" + COLOR[0] + ", " + COLOR[1] + ", " + COLOR[2] + ", " + 0.05 * BRUSH_PRESSURE + ")";

    path.lineTo(dx, dy);
}

void PMRibbonPainter::setColor(ofColor _color)
{
    color = _color;
    path.setStrokeColor(color);
}
