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


	VAO::VAO()
	{
		glGenVertexArrays(1, &this->id);
		this->Bind();
	}

	void VAO::Bind()
	{
		glBindVertexArray(this->id);
	}
	
	void VAO::spec(int index, int size, int dataType, int stride, const void *offset)
	{
		glVertexAttribPointer(index, size, dataType, GL_FALSE, stride, offset);
		glEnableVertexAttribArray(0);
	}

}
