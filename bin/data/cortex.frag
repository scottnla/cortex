uniform float time;
uniform vec2 resolution;
uniform bool bVert, bHorizon, bDiag, bArms, bRings, bSpiral;
uniform float vertSpeed, horizonSpeed, diagSpeed, armSpeed, ringSpeed, spiralSpeed;

void main( void ) {
    vec2 position = (gl_FragCoord.xy/resolution.xy);

    float cX = position.x - 0.5;
    float cY = position.y - 0.5;
    
    float newX = log(sqrt(cX*cX + cY*cY));
    float newY = atan(cX, cY);
     
    float PI = 3.14159;
    float numHorBands = 10.0;
    float numVertBands = 10.0;
    float numDiagBands = 10.0;
    float numArms = 6.0;
    float numLines = 5.0;
    float numRings = 5.0;
    float spiralAngle = PI/3.0;
    
    float color = 0.0;
    
    //Vertical Bands
    if(bVert) {
    color += cos(numVertBands*cY + vertSpeed*time);
    }   
    //Horizontal Bands
    if(bHorizon) {
    color += cos(numHorBands*cX + horizonSpeed*time);	
    }
    //Diagonal Bands
    if(bDiag) {
    color += cos(2.0*numDiagBands*(cX*sin(spiralAngle) + cY*cos(spiralAngle)) + diagSpeed*time);
    }
    //Arms
    if(bArms) {
    color += cos(numLines*newY + armSpeed*time);
    }
    //Rings
    if(bRings) {
    color += cos(numRings*newX + ringSpeed*time);
    }
    //Spirals
    if(bSpiral) {
    color += cos(2.0*numArms*(newX*sin(spiralAngle) + newY*cos(spiralAngle)) + spiralSpeed*time);
    }
    //overall brightness/color
    //color *= cos(time/10.0);
    gl_FragColor = vec4( vec3( sin( color + time / 3.0 ) * 0.75, color, sin( color + time / 3.0 ) * 0.75 ), 1.0 );
    
}