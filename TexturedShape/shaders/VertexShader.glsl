#version 430 core

//take in attributes of vertex
layout(location = 0) in vec3 Position2D;
layout(location = 1) in vec3 ColorRGB;
layout(location = 2) in vec2 TextureUV;

//output color and texture coordinates
out vec3 OutColor;
out vec2 TextureST;

void main()
{
	//leave attributes unmodified
	gl_Position = vec4(Position2D, 1.0);
	OutColor = ColorRGB;
	TextureST = vec2(TextureUV.x, TextureUV.y);
}