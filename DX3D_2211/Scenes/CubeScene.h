#pragma once

class CubeScene : public Scene
{
public:
	 CubeScene();
	~CubeScene();

	virtual void Update()    override;
	virtual void Render()    override;
	virtual void GUIRender() override;

private:
	Quad* quad;

	MatrixBuffer* worldBuffer;
	MatrixBuffer* viewBuffer;
	MatrixBuffer* projectionBuffer;

	VertexShader* vertexShader;
	PixelShader* pixelShader;

	VertexBuffer* vertexBuffer;
	IndexBuffer* indexBuffer;

	Matrix world;
};