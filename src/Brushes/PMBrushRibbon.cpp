//
// Created by Miquel Ëngel Soler on 15/12/15.
//

#include "PMBrushRibbon.h"

const unsigned int NUM_PAINTERS = 50;
const unsigned int DEFAULT_SIZE = 1;

const ofColor DEFAULT_COLOR = ofColor(1, 1, 1, 255);

PMBrushRibbon::PMBrushRibbon()
{
    for (int i=0; i<NUM_PAINTERS; ++i)
    {
        PMRibbonPainter painter = PMRibbonPainter(DEFAULT_COLOR, ofGetWidth()/2, ofGetHeight()/2, 0, 0, 0.1, ofRandom(0.0f, 1.0f) * 0.2f + 0.6f);
        painters.push_back(painter);
    }

    size = DEFAULT_SIZE;
    isInStroke = false;

    fbo.allocate(ofGetWidth(), ofGetHeight(), GL_RGBA32F_ARB);
    fbo.begin();
    {
        ofClear(0, 0, 0, 0);
    }
    fbo.end();

}

void PMBrushRibbon::setup()
{
    for (int i=0; i<NUM_PAINTERS; ++i)
        painters[i].setup();
}

void PMBrushRibbon::update()
{
    for (int i=0; i<NUM_PAINTERS; ++i)
        painters[i].update();
}

void PMBrushRibbon::draw()
{
    if (isInStroke)
    {
        fbo.begin();
        {
            for (int i=0; i<NUM_PAINTERS; ++i)
                painters[i].draw();
        }
        fbo.end();
    }

    fbo.draw(0, 0);
}

void PMBrushRibbon::setPosition(int x, int y)
{
    for (int i=0; i<NUM_PAINTERS; ++i)
        painters[i].setPosition(x, y);
}

void PMBrushRibbon::setColor(ofColor color)
{
    for (int i=0; i<NUM_PAINTERS; ++i)
        painters[i].setColor(color);
}

void PMBrushRibbon::setSize(unsigned int _size)
{
    if (_size > 0) size = _size;
}

void PMBrushRibbon::strokeStarted()
{
    isInStroke = true;
}

void PMBrushRibbon::strokeEnded()
{
    isInStroke = false;
    for (int i=0; i<NUM_PAINTERS; ++i)
        painters[i].clear();
}
