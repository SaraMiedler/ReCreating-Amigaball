#pragma once

#include "ofMain.h"
#include "AmigaBall.hpp"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void windowResized(int w, int h);
        void updateBall();
        void bounceBall();
        void drawGrid();
        void drawBall();
    
        int width;
        int height;
        
        // Grid variables
        float padding;
        int numVLines;
        int numHLines;
        float gridSizeX;
        float gridSizeY;
    
        // Ball parameters
        int facets;
        float rotation;
        ofColor color1 = ofColor(255,255,255);
        ofColor color2 = ofColor(255,0,0);
        //ofColor color1;
        //ofColor color2;
        float rotSpeed;
        float radius;

        // Physics
        float x;
        float y;
        float ySpeed;
        float yAcceleration;
        float xSpeed;
};
