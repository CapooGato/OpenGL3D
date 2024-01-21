#version 330 core

layout (location = 0) in vec3 aPos;
out vec3 Normal; // Dodajemy normaln� jako wyj�cie z Vertex Shader
out vec3 FragPos; // Dodajemy pozycj� fragmentu jako wyj�cie z Vertex Shader

uniform mat4 projection;
uniform mat4 view;
uniform mat4 model;

void main()
{
    // Przekszta�camy wsp�rz�dne do przestrzeni widoku
    vec4 fragPos = model * vec4(aPos, 1.0);
    FragPos = fragPos.xyz;
    gl_Position = projection * view * fragPos;
    
    // Obliczamy normaln� w przestrzeni kamery
    mat3 normalMatrix = transpose(inverse(mat3(view * model)));
    Normal = normalize(normalMatrix * aPos);
}
