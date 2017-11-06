#include "TestScene.h"



TestScene::TestScene()
{
	m_rend = new Renderable;
}

void TestScene::Init()
{
	glClearColor(0, 1, 0, 1);
	addObject(m_rend);
}
void TestScene::Update(double dt)
{
}
void TestScene::Close()
{

}

TestScene::~TestScene()
{
}
