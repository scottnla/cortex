uniform float time;
uniform vec2 resolution;

void main( void ) {

     vec2 position = ( gl_FragCoord.xy / resolution.xy );

     float cX = position.x - 0.5;
     float cY = position.y - 0.5;

     float newX = log(sqrt(cX*cX + cY*cY));
     float newY = atan(cX, cY);
     
     float color = 0.0;
     color += cos( newX * cos( time / 20.0 ) * 80.0 ) + cos( newX * sin( time / 20.0 ) * 40.0 );
     color += cos( newY * cos( time / 10.0 ) * 40.0 ) + cos( newY * sin( time / 25.0 ) * 80.0 );
     color += cos( newX * cos( time / 5.0 ) * 10.0 ) + cos( newY * sin( time / 30.0 ) * 120.0 );
     color *= cos( time / 10.0 ) * 0.5;

     gl_FragColor = vec4( vec3( color, color * 0.5, cos( color + time / 3.0 ) * 0.75 ), 1.0 );

}