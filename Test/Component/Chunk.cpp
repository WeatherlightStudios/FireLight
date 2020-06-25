#include "Chunk.h"


Chunk::Chunk()
{

}

void Chunk::Init()
{
	uint8_t chunk[5][5][5];

	FastNoise noise;

	noise.SetNoiseType(FastNoise::Perlin);

	for (int z = 0; z < 5; z++)
	{
		for (int x = 0; x < 5; x++)
		{
			for (int y = 0; y < 5; y++)
			{
				chunk[x][y][z] = 0;
			}
		}
	}

	chunk[3][2][1] = 1;
	chunk[2][2][1] = 1;
	chunk[1][2][1] = 1;



	for (int z = 0; z < 5; z++)
	{
		for (int x = 0; x < 5; x++)
		{
			for (int y = 0; y < 5; y++)
			{
				if (chunk[x][y][z] == 1)
				{
					if (x < 4 && chunk[x + 1][y][z] == 0)
					{
						AddVertexFace(glm::vec3(x,y,z), directions[0]);
					}
					if (x > 0 && chunk[x - 1][y][z] == 0)
					{
						AddVertexFace(glm::vec3(x, y, z), directions[1]);
					}
					if (y < 4 && chunk[x][y+1][z] == 0)
					{
						AddVertexFace(glm::vec3(x, y, z), directions[2]);
					}
					if (y > 0 && chunk[x][y-1][z] == 0)
					{
						AddVertexFace(glm::vec3(x, y, z), directions[3]);
					}
					if (z < 4 && chunk[x][y][z+1] == 0)
					{
						AddVertexFace(glm::vec3(x, y, z), directions[4]);
					}
					if (z > 0 && chunk[x][y][z-1] == 0)
					{
						AddVertexFace(glm::vec3(x, y, z), directions[5]);
					}

				}
			}
		}
	}


	FL::BufferLayout layout({
		{ FL::DataType::Vec3 },
		{ FL::DataType::Vec3 }
		});

	ArraySize = vertexChunk.size();

	m_VBO = std::make_shared<FL::VertexBuffer>();

	m_VBO->BuilBuffer(sizeof(vex) * vertexChunk.size(), vertexChunk.data(), GL_STATIC_DRAW);
	m_VBO->SetBufferLayout(layout);

	m_VAO = std::make_shared<FL::VertexArray>();

	m_VAO->AddVertexBuffer(m_VBO);

}

void Chunk::Update()
{

}

void Chunk::UpdateMesh()
{

}

int Chunk::checkNeighbor(int x, int y, int z)
{
	return 0;
}

void Chunk::AddVertexFace(glm::vec3 pos, glm::vec3 dir)
{
	glm::vec3 postionZero = pos + (dir / 2.0f);

	glm::vec3 i;
	glm::vec3 j;

	if (dir.x != 0)
	{
		i = glm::vec3(0, 0, dir.x);
		j = glm::vec3(0, 1, 0);
	}
	else if(dir.z != 0)
	{
		i = glm::vec3(-dir.z, 0, 0);
		j = glm::vec3(0, 1, 0);
	}
	else
	{
		i = glm::vec3(dir.y, 0, 0);
		j = glm::vec3(0, 0, dir.y);
	}

	vex v;
	v.pos = postionZero + j / 2.0f - i / 2.0f;
	v.normal = dir;
	vertexChunk.push_back(v);

	v.pos = postionZero + j / 2.0f + i / 2.0f;
	vertexChunk.push_back(v);

	v.pos = postionZero - j / 2.0f + i / 2.0f;
	vertexChunk.push_back(v);

	v.pos = postionZero - j / 2.0f + i / 2.0f;
	vertexChunk.push_back(v);

	v.pos = postionZero - j / 2.0f - i / 2.0f;
	vertexChunk.push_back(v);

	v.pos = postionZero + j / 2.0f - i / 2.0f;
	vertexChunk.push_back(v);
}


void Chunk::Draw()
{
	glm::mat4 model = glm::mat4(1.0f);

	auto trans = GetOwner()->GetComponent<Transform>();

	model = glm::translate(model, trans->GetPosition());
	model = glm::scale(model, trans->GetScale());


	auto shader = ResourceManager::GetShader("shader");

	shader->SetMatrix4("projection", CameraSystem::GetCurrentCamera());
	shader->SetMatrix4("model", model);
	shader->SetVector3f("MyColor", glm::uvec3(1.0f, 0.1f, 0.1f));

	shader->Use();
	m_VAO->Bind();
	glDrawArrays(GL_TRIANGLES, 0, ArraySize);
}

Chunk::~Chunk()
{

}