#pragma once

class Cube
{
private:
	typedef VertexColor VertexType;

public:
	 Cube(Vector3 size);
	~Cube();

	void Render();

private:
	void CreateMesh();

private:
	Vector3 size;

	VertexShader* vertexShader;
	PixelShader* pixelShader;

	MatrixBuffer* worldBuffer;
	VertexBuffer* vertexBuffer;
	IndexBuffer* indexBuffer;

	vector<VertexColor> vertices;
	vector<UINT> indices;

	Matrix world;
};