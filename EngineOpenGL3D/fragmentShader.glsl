#version 450
in vec4 FragPos;
in vec4 VertexColor;
out vec4 color;

void main() {
    // Ustaw kolor fragmentu na kolor z vertex shadera
    color = VertexColor;
}
