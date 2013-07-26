uniform float time;
uniform vec2 resolution;

void main( void ) {

     vec2 position = ( gl_FragCoord.xy / resolution.xy ) + mouse / 4.0;

     float cX = position.x - 0.5;
     float cY = position.y - 0.5;

     float newX = log(sqrt(cX*cX + cY*cY));
     float newY = atan(cX, cY);
     
     float color = 0.0;
     color += sin( newX * cos( time / 15.0 ) * 80.0 ) + cos( newX * cos( time / 15.0 ) * 10.0 );
     color += sin( newY * sin( time / 10.0 ) * 40.0 ) + cos( newY * sin( time / 25.0 ) * 40.0 );
     color += sin( newX * sin( time / 5.0 ) * 10.0 ) + sin( newY * sin( time / 35.0 ) * 80.0 );
     color *= sin( time / 10.0 ) * 0.5;

     gl_FragColor = vec4( vec3( color, color * 0.5, sin( color + time / 3.0 ) * 0.75 ), 1.0 );

}