#version 330 core

layout (location = 0) in vec3 aPos;
out vec3 Normal; // Dodajemy normaln¹ jako wyjœcie z Vertex Shader
out vec3 FragPos; // Dodajemy pozycjê fragmentu jako wyjœcie z Vertex Shader

uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;

void main()
{
    // Przekszta³camy wspó³rzêdne do przestrzeni widoku
    vec4 fragPos = model * vec4(aPos, 1.0);
    FragPos = fragPos.xyz;
    gl_Position = projection * view * fragPos;
    
    // Obliczamy normaln¹ w przestrzeni kamery
    mat3 normalMatrix = transpose(inverse(mat3(view * model)));
    Normal = normalize(normalMatrix * aPos);
}
