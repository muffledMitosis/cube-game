#pragma once

#include <cstdint>
#include <vector>
namespace Graphics {

class VBO
{
public:
	unsigned int id;
	VBO();
	void BufferData(std::vector<double> &data, int streamType);
	void Bind();
};

class VAO
{
public:
	unsigned int id;
	VAO();
	void Bind();
	void spec(int index, int size, int dataType, int stride, const void* offset);
};

class EBO
{
public:
	unsigned int id;
	EBO();
	void Bind();
	void BufferData(std::vector<unsigned int> &data, int streamType);
};

}
