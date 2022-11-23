#include "Framework.h"

Quad::Quad(float width, float height) : width(width), height(height)
{
	material = new Material(L"Shaders/Texture.hlsl");
	material->SetDiffuseMap(L"Textures/Landscape/Box.png");

	CreateMesh();

	worldBuffer = new MatrixBuffer();
}

Quad::~Quad()
{
	delete material;
	delete mesh;
	delete worldBuffer;
}

void Quad::Render()
{
	worldBuffer->SetVSBuffer(0);

	static float angle = 0.0f;

	angle += 0.001f;

	world = XMMatrixRotationX(angle) * XMMatrixRotationY(angle) * XMMatrixRotationZ(angle);
	worldBuffer->Set(world);

	mesh->IASet();
	material->Set();

	DC->DrawIndexed(indices.size(), 0, 0);
}

void Quad::CreateMesh()
{
	Float2 halfSize = { width * 0.5f, height * 0.5f };

	vertices.emplace_back(-halfSize.x, +halfSize.y, -0.5f, 0.f, 0.f); // 0
	vertices.emplace_back(+halfSize.x, +halfSize.y, -0.5f, 1.f, 0.f); // 1
	vertices.emplace_back(-halfSize.x, -halfSize.y, -0.5f, 0.f, 1.f); // 2
	vertices.emplace_back(+halfSize.x, -halfSize.y, -0.5f, 1.f, 1.f); // 3

	vertices.emplace_back(-halfSize.x, +halfSize.y, +0.5f, 0.f, 0.f); // 4
	vertices.emplace_back(+halfSize.x, +halfSize.y, +0.5f, 1.f, 0.f); // 5
	vertices.emplace_back(-halfSize.x, +halfSize.y, -0.5f, 0.f, 1.f); // 6
	vertices.emplace_back(+halfSize.x, +halfSize.y, -0.5f, 1.f, 1.f); // 7

	vertices.emplace_back(+halfSize.x, +halfSize.y, +0.5f, 0.f, 0.f); // 8
	vertices.emplace_back(+halfSize.x, -halfSize.y, +0.5f, 0.f, 1.f); // 9
	vertices.emplace_back(+halfSize.x, +halfSize.y, -0.5f, 1.f, 0.f); // 10
	vertices.emplace_back(+halfSize.x, -halfSize.y, -0.5f, 1.f, 1.f); // 11

	vertices.emplace_back(+halfSize.x, +halfSize.y, +0.5f, 0.f, 0.f); // 12
	vertices.emplace_back(-halfSize.x, +halfSize.y, +0.5f, 1.f, 0.f); // 13
	vertices.emplace_back(+halfSize.x, -halfSize.y, +0.5f, 0.f, 1.f); // 14
	vertices.emplace_back(-halfSize.x, -halfSize.y, +0.5f, 1.f, 1.f); // 15

	vertices.emplace_back(-halfSize.x, -halfSize.y, +0.5f, 0.f, 0.f); // 16
	vertices.emplace_back(-halfSize.x, +halfSize.y, +0.5f, 0.f, 1.f); // 17
	vertices.emplace_back(-halfSize.x, -halfSize.y, -0.5f, 1.f, 0.f); // 18
	vertices.emplace_back(-halfSize.x, +halfSize.y, -0.5f, 1.f, 1.f); // 19

	vertices.emplace_back(-halfSize.x, -halfSize.y, -0.5f, 0.f, 0.f); // 20
	vertices.emplace_back(+halfSize.x, -halfSize.y, -0.5f, 1.f, 0.f); // 21
	vertices.emplace_back(-halfSize.x, -halfSize.y, +0.5f, 0.f, 1.f); // 22
	vertices.emplace_back(+halfSize.x, -halfSize.y, +0.5f, 1.f, 1.f); // 23

	indices =
	{
		 0,  1,  2,  1,  3,  2, // front
		 4,  5,  6,  5,  7,  6, // top
		 8,  9, 10,  9, 11, 10, // right
		12, 13, 14, 13, 15, 14, // back
		16, 17, 18, 17, 19, 18, // left
		20, 21, 22, 21, 23, 22  // bottom
	};

	mesh = new Mesh(vertices.data(), sizeof(VertexType), vertices.size(), indices.data(), indices.size());
}
