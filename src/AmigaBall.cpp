
#include "AmigaBall.hpp"

//--------------------------------------------------------------------------------------
// Faceted ball algorithm
// Usage: drawAmigaBall(x,y, radius, facets, color1, color2, yRot, zRot)

void ofDrawQuad(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4) {
    ofBeginShape();
    ofVertex(x1, y1);
    ofVertex(x2, y2);
    ofVertex(x3, y3);
    ofVertex(x4, y4);
    ofEndShape();
}

void drawBand(float radius, float facets, float long1, float long2, bool cf, ofColor col1, ofColor col2, float ani) {
    float sLat = glm::radians(180.0f/facets);
    float sLong = sLat;
    float ty = cos(long2) * radius;
    float by = cos(long1) * radius;
    float a = radius * sin(long1 + sLong);
    float b = radius * sin(long1);
    float tx1, bx1, tx2, bx2, c, c1;
    
    for ( float latDeg = -ani; latDeg < (PI- (sLat/2)); latDeg += sLat ) {
        c = cos(latDeg);
        c1 = cos(latDeg + sLat);
        tx1 = c * a;
        bx1 = c * b;
        tx2 = c1 * a;
        bx2 = c1 * b;
        if (cf) {
            ofSetColor(col2);
        } else {
            ofSetColor(col1);
        }
        cf = !cf;
        ofDrawQuad(tx1, ty, tx2, ty, bx2, by, bx1, by);
    }
}

void drawAmigaBall(float xpos, float ypos, float radius, int facets, ofColor c1, ofColor c2, float yrot, float zrot) {
    // constrain angles to interval [0..2*PI[
    yrot -= floor(yrot/(2*PI))*2*PI;
    zrot -= floor(zrot/(2*PI))*2*PI;
    
    float sLong = glm::radians(180.0f/facets);
    ofPushMatrix();
    ofTranslate(xpos, ypos);
    ofRotateZRad(zrot);
    bool colorFlag = false;
    for (float deg = 0; deg < PI- (sLong/2); deg += sLong)
    {
        drawBand(radius, facets, deg, deg + sLong, colorFlag, c1, c2, yrot);
        colorFlag = !colorFlag;
    }
    ofPopMatrix();
}
