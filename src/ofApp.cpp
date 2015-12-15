#include "ofApp.h"

void ofApp::setup()
{
    ribbon = PMBrushRibbon();

    ofEnableSmoothing();
}

void ofApp::update()
{
    ribbon.update();
}

void ofApp::draw()
{
    ribbon.draw();
}

void ofApp::keyPressed(int key)
{
}

void ofApp::keyReleased(int key)
{
}

void ofApp::mouseMoved(int x, int y )
{
}

void ofApp::mouseDragged(int x, int y, int button)
{
    if (button == OF_MOUSE_BUTTON_1)
        ribbon.setPosition(x, y);
}

void ofApp::mousePressed(int x, int y, int button)
{
    if (button == OF_MOUSE_BUTTON_1)
    {
        ribbon.setPosition(x, y);
        ribbon.strokeStarted();
    }
}

void ofApp::mouseReleased(int x, int y, int button)
{
    ribbon.strokeEnded();
}

void ofApp::windowResized(int w, int h)
{
}
