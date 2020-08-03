#include "Graphics.h"
#include "Log.h"
#include "VertexArray.h"
#include "VertexShader.h"
#include "FragmentShader.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "VertexLayout.h"
#include "Texture.h"
#include <GL/glew.h>

//defines the content of a single vertex
struct VERTEX {
	struct {
		float X, Y, Z;
	} Position;
	struct {
		float R, G, B;
	} Color;
	struct {
		float U, V;
	} Texture;
};

//array of vertices the vertex buffer will use
VERTEX Vertices[] = {
	{-0.9f, -0.9f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f}, // bottom left
	{-0.9f,  0.9f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f}, // top left 
	{ 0.9f,  0.9f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f}, // top right
	{ 0.9f, -0.9f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f}, // bottom right
};

//array of indices the index buffer will use
unsigned int Indices[] = {
	0,1,2,3
};

Graphics::Graphics() {

	//initialize GLEW
	PRINT_IF_ELSE(glewInit() != -1, "Initialized GLEW", "Failed to initialize GLEW");

	//create OpenGL program
	GL_USER_ERROR(idProgram = glCreateProgram());
	PRINT_IF_ELSE(idProgram, "Created OpenGL program", "Failed to create OpenGL program");

	//create vertex shader
	VShader = std::make_unique<VertexShader>("shaders/VertexShader.glsl", idProgram);
	VShader->Bind();

	//create fragment shader
	FShader = std::make_unique<FragmentShader>("shaders/FragmentShader.glsl", idProgram);
	FShader->Bind();

	//set OpenGL program for use
	GL_USER_ERROR(glLinkProgram(idProgram));
	glValidateProgram(idProgram);
	GLint isValid;
	glGetProgramiv(idProgram, GL_VALIDATE_STATUS, &isValid);
	PRINT_IF_ELSE(isValid, "Validated OpenGL program", "OpenGL program is not valid");
	GL_USER_ERROR(glUseProgram(idProgram));

	//create vertex array
	VAO = std::make_unique<VertexArray>();
	VAO->Bind();

	//create vertex buffer
	VBuffer = std::make_unique<VertexBuffer>(Vertices, sizeof(Vertices) / sizeof(float));
	VBuffer->Bind();

	//create index buffer
	IBuffer = std::make_unique<IndexBuffer>(Indices, std::size(Indices));
	IBuffer->Bind();

	//create input layout and register each vertex attribute
	InputLayout = std::make_unique<VertexLayout>(idProgram);
	InputLayout->Attributes.emplace_back("Position2D", 3, 0);
	InputLayout->Attributes.emplace_back("ColorRGB", 3, sizeof(float) * 3);
	InputLayout->Attributes.emplace_back("TextureUV", 2, sizeof(float) * 6);
	InputLayout->CreateAttributes();
	InputLayout->Bind();

	//create texture manager and create textures
	TextureObj = std::make_unique<Texture>(idProgram);
	TextureObj->Textures.emplace_back("resources/JamaicanAinsley.png", "texture1");
	TextureObj->Textures.emplace_back("resources/PepperedAinsley.png", "texture2");
	TextureObj->CreateTextures();

	//set background color to black
	glClearColor(0.f, 0.f, 0.f, 1.f);

}

Graphics::~Graphics()
{
	//clean up OpenGL
	GL_USER_ERROR(glDeleteProgram(idProgram));
}

void Graphics::Render()
{
	//clear back buffer
	GL_USER_ERROR(glClear(GL_COLOR_BUFFER_BIT));
	//draw call
	GL_USER_ERROR(glDrawElements(GL_TRIANGLE_FAN, (int)std::size(Indices), GL_UNSIGNED_INT, NULL));
}