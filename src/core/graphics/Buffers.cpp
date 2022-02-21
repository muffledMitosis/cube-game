#include "Buffers.hpp"
#include "glad/glad.h"
#include <vector>

namespace Graphics {
	VBO::VBO()
	{
		glGenBuffers(1, &(this->id));
		this->Bind();
	}

	void VBO::Bind()
	{
		glBindBuffer(GL_ARRAY_BUFFER, this->id);
	}

	void VBO::BufferData(std::vector<double> &data, int streamType)
	{
		this->Bind();
		glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(double), &data[0], streamType);
	}

	EBO::EBO()
	{
		glGenBuffers(1, &(this->id));
		this->Bind();
	}

	void EBO::Bind()
	{
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->id);
	}

	void EBO::BufferData(std::vector<unsigned int> &data, int streamType)
	{
		this->Bind();
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, data.size() * sizeof(unsigned int), &data[0], streamType);
	}


	VAO::VAO()
	{
		glGenVertexArrays(1, &this->id);
		this->Bind();
	}

	void VAO::Bind()
	{
		glBindVertexArray(this->id);
	}
	
	void VAO::spec(const int& index, const int& size, const int& dataType, const int& stride, const void *offset)
	{
		this->Bind();
		glVertexAttribPointer(index, size, dataType, GL_FALSE, stride, offset);
		glEnableVertexAttribArray(index);
	}

}
