#version 430 core

//output color
out vec4 OutColor;

//input color and texture coordinates
in vec3 ColorRGB;
in vec2 TextureST;

//textures that will be sampled
uniform sampler2D texture1;
uniform sampler2D texture2;

void main()
{
	//interpolate between textures evenly
	OutColor = mix(texture(texture1, TextureST), texture(texture2, TextureST), 0.5);
}