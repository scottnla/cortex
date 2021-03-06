uniform float time;
uniform vec2 resolution;
uniform bool bVert, bHorizon, bDiag, bDiagAlt, bArms, bRings, bSpiral, bSpiralAlt;
uniform float sVert, sHorizon, sDiag, sDiagAlt, sArms, sRings, sSpiral, sSpiralAlt;
uniform float vertPeriod, horizonPeriod, diagPeriod, diagAltPeriod, armPeriod, ringPeriod, spiralPeriod, spiralAltPeriod;
uniform float numVert, numHorizon, numDiag, numDiagAlt, numRings, numArms, numSpiral, numSpiralAlt;

void main( void ) {
    vec2 position = (gl_FragCoord.xy/resolution.xy);

    float cX = position.x - 0.5;
    float cY = position.y - 0.5;
    
    float newX = log(sqrt(cX*cX + cY*cY));
    float newY = atan(cX, cY);
     
    float PI = 3.14159;
    float spiralAngle = PI/3.0;
    float spiralAngleAlt = 2.0*PI - PI/3.0;
    
    float color = 0.0;
    
    //Vertical Bands
    if(bVert) {
        color += sVert * cos(numVert*cY + vertPeriod);
    }   
    //Horizontal Bands
    if(bHorizon) {
        color += sHorizon * cos(numHorizon*cX + horizonPeriod);
    }
    //Diagonal Bands
    if(bDiag) {
        color += sDiag * (cos(2.0*numDiag*(cX*sin(spiralAngle) + cY*cos(spiralAngle)) + diagPeriod));
    }
    //Perpendicular Diagonal bands
    if(bDiagAlt) {
        color += sDiagAlt * (cos(2.0*numDiagAlt*(cX*sin(spiralAngleAlt) + cY*cos(spiralAngleAlt)) + diagAltPeriod));
    }
    //Arms
    if(bArms) {
        color += sArms * cos(numArms*newY + armPeriod);
    }
    //Rings
    if(bRings) {
        color += sRings * cos(numRings*newX + ringPeriod);
    }
    //Spirals
    if(bSpiral) {
        color += sSpiral * (cos(2.0*numSpiral*(newX*sin(spiralAngle) + newY*cos(spiralAngle)) + spiralPeriod));
    }
    if(bSpiralAlt) {
        color += sSpiralAlt * (cos(2.0*numSpiralAlt*(newX*sin(spiralAngleAlt) + newY*cos(spiralAngleAlt)) + spiralAltPeriod));
    }
    //overall brightness/color
    //color *= cos(time/10.0);
    gl_FragColor = vec4( vec3( sin( color + time / 3.0 ) * 0.75, color, sin( color + time / 3.0 ) * 0.75 ), 1.0 );
    
}