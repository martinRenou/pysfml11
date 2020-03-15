uniform mat4 VMatrix;
uniform mat4 MMatrix;
uniform mat4 PMatrix;

uniform float x;

void main(void){
  gl_Position = PMatrix * VMatrix * MMatrix * gl_Vertex;
}
