#include "ofApp.h"

ofVec2f lastPos;
void ofApp::setup()
{
//    ofEnableSmoothing();
    ofBackground(255);

    ribbon = PMBrushRibbon();
    ribbon.setup();
}

void ofApp::update()
{
    ribbon.update();
    
}

void ofApp::draw()
{
    ribbon.draw();
    //ofSetColor(0,255,0);
    ofDrawBitmapString(ofToString(ofGetFrameRate()),100,100);

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
    
//    ofVec2f actualPos;
//    float dist = actualPos.distance(lastPos);
    
    
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
