#version 330 core
out vec4 FragColor;

in vec2 TexCoord;

uniform sampler2D dirtTexture;

void main()
{
    FragColor = texture(dirtTexture, TexCoord); 
}
