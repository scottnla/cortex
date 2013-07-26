uniform float time;
uniform vec2 mouse;
uniform vec2 resolution;

void main( void ) {
     vec2 position = ( gl_FragCoord.xy / resolution.xy ) + mouse / 4.0;

     float cX = position.x - 0.5;
     float cY = position.y - 0.5;

     float newX = log(sqrt(cX*cX + cY*cY));
     float newY = atan(cY, cX);

     float col = newX*100.0+sin(newY*sin(time)*50.0);
     gl_FragColor = vec4(abs(sin(col)), abs(sin(col*.2+1.0)), abs(sin(col*.2)), 1.0 );
}