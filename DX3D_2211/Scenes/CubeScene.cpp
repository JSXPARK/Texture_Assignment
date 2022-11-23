#include "Framework.h"
#include "CubeScene.h"

CubeScene::CubeScene()
{
	quad = new Quad();
}

CubeScene::~CubeScene()
{
	delete quad;

	delete vertexBuffer;
	delete indexBuffer;
	delete worldBuffer;
	delete viewBuffer;
	delete projectionBuffer;
}

void CubeScene::Update()
{
}

void CubeScene::Render()
{
	quad->Render();
}

void CubeScene::GUIRender()
{
}