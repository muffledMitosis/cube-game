#pragma once

namespace Graphics {

class Buffer
{
public:
	unsigned int id;
	Buffer();
	void Bind();
	~Buffer();
};

class VBO : public Buffer
{

}
	
} // namespace Graphics