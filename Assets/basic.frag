#version 330 core
out vec4 FragColor;
in vec3 ourColor;

uniform vec3 lol;

void main()
{
    FragColor = vec4(ourColor * lol, 1.0);
} 
