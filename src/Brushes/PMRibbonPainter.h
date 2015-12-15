//
// Created by Miquel Ëngel Soler on 15/12/15.
//

#ifndef HARMONYFOROF_PMRIBBONPAINTER_H
#define HARMONYFOROF_PMRIBBONPAINTER_H

#include "ofMain.h"


class PMRibbonPainter
{
public:

    PMRibbonPainter(ofColor color, float dx, float dy, float ax, float ay, float div, float ease);

    void draw();

    void setPosition(int x, int y);
    void setColor(ofColor color);

private:

    float dx, dy;
    float ax, ay;
    float div;
    float ease;

    ofPath path;

    ofColor color;
};

#endif //HARMONYFOROF_PMRIBBONPAINTER_H
