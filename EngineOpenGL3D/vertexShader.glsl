#version 450
layout(location = 0) in vec3 vertexPosition_modelspace;
out vec4 FragPos;
out vec4 VertexColor;
uniform mat4 MVP;
uniform mat4 model;

void main() {
    gl_Position =  MVP * vec4(vertexPosition_modelspace, 1);
    FragPos = model * vec4(vertexPosition_modelspace, 1.0);
    VertexColor = vec4(0.0, 0.4, 0.7, 1.0); // Kolor czerwony
}
