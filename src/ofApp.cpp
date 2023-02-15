#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    width = ofGetWidth();
    height = ofGetHeight();

    // Grid
    padding = height*5.0/100.0;
    numVLines = 16;
    numHLines = 13;
    gridSizeX = width-2*padding;
    gridSizeY = height-2*padding;
    
    // Ball Physics
    x = width/2;
    y = height/3;
    ySpeed = 0.0;
    yAcceleration = 0.25;
    xSpeed = 3.4;
    
    // Ball look
    facets = 7;
    radius = 100;

    //Ball Rotation
    rotation = glm::radians(15.0);
    rotSpeed = PI/150;
   
}

//--------------------------------------------------------------
void ofApp::update(){
    updateBall();
    bounceBall();
}

//--------------------------------------------------------------
void ofApp::draw(){

    drawGrid();
    drawBall();
}


//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    width = w;
    height = h;
    
    padding = height*5.0/100.0;
    gridSizeX = width-2*padding;
    gridSizeY = height-2*padding;
}


void ofApp::updateBall() {

    // Update the balls x position
    x += xSpeed;

    // Update y position by using acceleration (physics)
    y += ySpeed;

}
void ofApp::bounceBall() {
    if (x < radius) {
        xSpeed = -xSpeed;
    }
    if (x > width - radius) {
        xSpeed = -xSpeed;
    }

    if (y > height - radius) {
        ySpeed = -ySpeed;
    }
    else {
        ySpeed += yAcceleration;
    }
}

void ofApp::drawGrid() {
    // Clear the screen with a color
    ofClear(50, 50, 50);

    // Draw the grid
    ofSetColor(155, 29, 227);
    ofSetLineWidth(3);

    float xpos = padding;
    float ypos = padding;

    float xStep = gridSizeX / (numVLines - 1);
    float yStep = gridSizeY / (numHLines - 1);

    for (int vlines = 0; vlines < numVLines; vlines++) {
        ofDrawLine(xpos, padding, xpos, padding + gridSizeY);
        xpos += xStep;
    }

    for (int hlines = 0; hlines < numHLines; hlines++) {
        ofDrawLine(padding, ypos, padding + gridSizeX, ypos);
        ypos += yStep;
    }
}
void ofApp::drawBall() {
    // Draw the balls shadow
    ofSetColor(0, 0, 0, 110);
    ofDrawCircle(x + 20, y + 20, radius);

    // Finally draw our ball
    drawAmigaBall(x, y, radius, facets, color1, color2, x * rotSpeed, rotation);

}