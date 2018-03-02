#version 330

layout (location=0) in vec3 VertexPosition;
layout (location=1) in vec3 VertexColor;
//layout (location=2) in vec2 TexCoord;


out vec3 Color;
//out vec2 oTexCoord;

uniform mat4 mvp;

void main()
{
	Color = VertexColor;
	//oTexCoord = TexCoord;
	gl_Position = mvp*vec4(VertexPosition, 1.0);
}
