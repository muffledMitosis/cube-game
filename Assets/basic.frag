#version 330 core
out vec4 FragColor;

in vec3 ourColor;
in vec2 TexCoord;

uniform vec3 lol;
uniform sampler2D texture1;
uniform sampler2D texture2;

void main()
{
    /* FragColor = vec4(ourColor * lol, 1.0); */
	// FragColor = texture(texture2, TexCoord) * vec4(ourColor, 1.0);
	FragColor = mix(texture(texture1, TexCoord), texture(texture2, TexCoord), 0.2);
} 
