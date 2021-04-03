uniform mat4 VMatrix;
uniform mat4 MMatrix;
uniform mat4 PMatrix;

uniform float x;
uniform vec2 vec_2;
uniform vec3 vec_3;
uniform vec4 vec_4;
uniform mat3 matrix;

uniform sampler2D texture;


void main(void){
  gl_Position = PMatrix * VMatrix * MMatrix * gl_Vertex;
}
