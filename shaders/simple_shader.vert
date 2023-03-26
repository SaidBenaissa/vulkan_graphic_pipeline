#version 450

// Define an array of 3 position vectors
vec2 position[3] = vec2[] (
vec2(0.0, -0.5),
vec2(0.5, 0.5),
vec2(-0.5, 0.5)
);

void main(){
    // Set the position of the vertex based on its index using the position array
    gl_Position = vec4(position[gl_VertexIndex], 0.0, 1.0);
}
