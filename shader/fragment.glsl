#version 330

in vec3 Color;
//in vec2 oTexCoord;
out vec4 FragColor;

uniform sampler2D textura;

void main()
{
	FragColor = vec4(Color , 1.0);
	//FragColor = texture(textura, oTexCoord);
}
