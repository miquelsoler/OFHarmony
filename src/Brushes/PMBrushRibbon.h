//
// Created by Miquel Ëngel Soler on 15/12/15.
//

#ifndef HARMONYFOROF_PMBRUSHRIBBON_H
#define HARMONYFOROF_PMBRUSHRIBBON_H

#include "PMRibbonPainter.h"
#include "ofMain.h"

class PMBrushRibbon
{
public:

    PMBrushRibbon();

    void update();
    void draw();

    void setPosition(int x, int y);
    void setColor(ofColor color);
    void setSize(unsigned int size);

    void strokeStarted();
    void strokeEnded();

private:

    vector<PMRibbonPainter> painters;

    ofPoint position;
    unsigned int size;

    bool isInStroke;

    ofFbo fbo;
};


#endif //HARMONYFOROF_PMBRUSHRIBBON_H
