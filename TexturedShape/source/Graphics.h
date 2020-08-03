#pragma once

#include <memory>

class Graphics {
public:
	Graphics();
	~Graphics();

	//clear back buffer and draw
	void Render();

private:

	unsigned int idProgram; //id of OpenGL program

	//components of Graphics
	std::unique_ptr<class VertexArray> VAO;
	std::unique_ptr<class VertexBuffer> VBuffer;
	std::unique_ptr<class IndexBuffer> IBuffer;
	std::unique_ptr<class VertexShader> VShader;
	std::unique_ptr<class FragmentShader> FShader;
	std::unique_ptr<class VertexLayout> InputLayout;
	std::unique_ptr<class Texture> TextureObj;

};