#include "Chunk.h"


Chunk::Chunk()
{

}

void Chunk::Init()
{

	chunk = new uint8_t[chunkX * chunkY * chunkZ];


	const float aoStrenght = 0.0f;

	FastNoise noise;


	noise.SetFrequency(0.005f);
	noise.SetFractalOctaves(7);
	noise.SetFractalLacunarity(2);
	noise.SetFractalGain(0.3f);

	noise.SetNoiseType(FastNoise::PerlinFractal);

	for (int z = 0; z < chunkZ; z++)
	{
		for (int x = 0; x < chunkX; x++)
		{
			float height01 = noise.GetPerlinFractal(x, z);

		
			height01 = ((height01 + 1) / 2.0f) * chunkY;

			for (int y = 0; y < chunkY; y++)
			{
				if(y < height01)
					chunk[(y+x* chunkY)+z*chunkX* chunkY] = 1;
				else
					chunk[(y + x * chunkY) + z * chunkX * chunkY] = 0;
			}
		}
	}



	for (int z = 0; z < chunkZ; z++)
	{
		for (int x = 0; x < chunkX; x++)
		{
			for (int y = 0; y < chunkY; y++)
			{
				if (chunk[(y + x * chunkY) + z * chunkX * chunkY] == 1)
				{
					if (x < chunkX-1 && chunk[(y + (x+1) * chunkY) + z * chunkX * chunkY] == 0)
					{
						AddVertexFace(glm::vec3(x,y,z), directions[0]);
					}
					if (x > 0 && chunk[(y + (x - 1) * chunkY) + z * chunkX * chunkY] == 0)
					{
						AddVertexFace(glm::vec3(x, y, z), directions[1]);
					}
					if (y < chunkY-1 && chunk[((y + 1) + x * chunkY) + z * chunkX * chunkY] == 0)
					{
						AddVertexFace(glm::vec3(x, y, z), directions[2]);
					}
					if (y > 0 && chunk[((y - 1) + x * chunkY) + z * chunkX * chunkY] == 0)
					{
						AddVertexFace(glm::vec3(x, y, z), directions[3]);
					}
					if (z < chunkZ-1 && chunk[(y + x * chunkY) + (z+1) * chunkX * chunkY] == 0)
					{
						AddVertexFace(glm::vec3(x, y, z), directions[4]);
					}
					if (z > 0 && chunk[(y + x * chunkY) + (z - 1) * chunkX * chunkY] == 0)
					{
						AddVertexFace(glm::vec3(x, y, z), directions[5]);
					}

				}
			}
		}
	}


	FL::BufferLayout layout({
		{ FL::DataType::Vec3 },
		{ FL::DataType::Vec3 },
		{ FL::DataType::Float }
	});

	ArraySize = vertexChunk.size();

	m_VBO = std::make_shared<FL::VertexBuffer>();

	m_VBO->BuilBuffer(sizeof(vex) * vertexChunk.size(), vertexChunk.data(), GL_STATIC_DRAW);
	m_VBO->SetBufferLayout(layout);

	m_VAO = std::make_shared<FL::VertexArray>();

	m_VAO->AddVertexBuffer(m_VBO);


	delete(chunk);

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
	v.normal = (dir);


	glm::vec3 cubePos;
	uint8_t s_1;
	uint8_t s_2;
	uint8_t	corner;

	if (pos.y < chunkY - 1 && pos.y > 0 && pos.x < chunkX - 1 && pos.x > 0 && pos.z < chunkZ - 1 && pos.z > 0)
	{
		cubePos = pos + dir - i;
		s_1 = chunk[((int)cubePos.y + (int)cubePos.x * chunkY) + (int)cubePos.z * chunkX * chunkY];
		cubePos = pos + dir + j;
		s_2 = chunk[((int)cubePos.y + (int)cubePos.x * chunkY) + (int)cubePos.z * chunkX * chunkY];
		cubePos = pos + dir + j - i;
		corner = chunk[((int)cubePos.y + (int)cubePos.x * chunkY) + (int)cubePos.z * chunkX * chunkY];
	}
	else
	{
		s_1 = 0;
		s_2 = 0;
		corner = 0;
	}


	v.AO = aoStrenght[vertexAO(s_1, s_2, corner)];
	vertexChunk.push_back(v);

	v.pos = postionZero + j / 2.0f + i / 2.0f;

	if (pos.y < chunkY - 1 && pos.y > 0 && pos.x < chunkX - 1 && pos.x > 0 && pos.z < chunkZ - 1 && pos.z > 0)
	{
		cubePos = pos + dir + j;
		s_1 = chunk[((int)cubePos.y + (int)cubePos.x * chunkY) + (int)cubePos.z * chunkX * chunkY];
		cubePos = pos + dir + i;
		s_2 = chunk[((int)cubePos.y + (int)cubePos.x * chunkY) + (int)cubePos.z * chunkX * chunkY];
		cubePos = pos + dir + j + i;
		corner = chunk[((int)cubePos.y + (int)cubePos.x * chunkY) + (int)cubePos.z * chunkX * chunkY];
	}
	else
	{
		s_1 = 0;
		s_2 = 0;
		corner = 0;
	}

	v.AO = aoStrenght[vertexAO(s_1, s_2, corner)];
	vertexChunk.push_back(v);

	v.pos = postionZero - j / 2.0f + i / 2.0f;


	if (pos.y < chunkY - 1 && pos.y > 0 && pos.x < chunkX - 1 && pos.x > 0 && pos.z < chunkZ - 1 && pos.z > 0)
	{
		cubePos = pos + dir - j;
		s_1 = chunk[((int)cubePos.y + (int)cubePos.x * chunkY) + (int)cubePos.z * chunkX * chunkY];
		cubePos = pos + dir + i;
		s_2 = chunk[((int)cubePos.y + (int)cubePos.x * chunkY) + (int)cubePos.z * chunkX * chunkY];
		cubePos = pos + dir - j + i;
		corner = chunk[((int)cubePos.y + (int)cubePos.x * chunkY) + (int)cubePos.z * chunkX * chunkY];
	}
	else
	{
		s_1 = 0;
		s_2 = 0;
		corner = 0;
	}

	v.AO = aoStrenght[vertexAO(s_1, s_2, corner)];
	vertexChunk.push_back(v);

	v.pos = postionZero - j / 2.0f + i / 2.0f;

	if (pos.y < chunkY - 1 && pos.y > 0 && pos.x < chunkX - 1 && pos.x > 0 && pos.z < chunkZ - 1 && pos.z > 0)
	{
		cubePos = pos + dir - j;
		s_1 = chunk[((int)cubePos.y + (int)cubePos.x * chunkY) + (int)cubePos.z * chunkX * chunkY];
		cubePos = pos + dir + i;
		s_2 = chunk[((int)cubePos.y + (int)cubePos.x * chunkY) + (int)cubePos.z * chunkX * chunkY];
		cubePos = pos + dir - j + i;
		corner = chunk[((int)cubePos.y + (int)cubePos.x * chunkY) + (int)cubePos.z * chunkX * chunkY];
	}
	else
	{
		s_1 = 0;
		s_2 = 0;
		corner = 0;
	}

	v.AO = aoStrenght[vertexAO(s_1, s_2, corner)];
	vertexChunk.push_back(v);

	v.pos = postionZero - j / 2.0f - i / 2.0f;

	if (pos.y < chunkY - 1 && pos.y > 0 && pos.x < chunkX - 1 && pos.x > 0 && pos.z < chunkZ - 1 && pos.z > 0)
	{
		cubePos = pos + dir - j;
		s_1 = chunk[((int)cubePos.y + (int)cubePos.x * chunkY) + (int)cubePos.z * chunkX * chunkY];
		cubePos = pos + dir - i;
		s_2 = chunk[((int)cubePos.y + (int)cubePos.x * chunkY) + (int)cubePos.z * chunkX * chunkY];
		cubePos = pos + dir - j - i;
		corner = chunk[((int)cubePos.y + (int)cubePos.x * chunkY) + (int)cubePos.z * chunkX * chunkY];
	}
	else
	{
		s_1 = 0;
		s_2 = 0;
		corner = 0;
	}

	v.AO = aoStrenght[vertexAO(s_1, s_2, corner)];
	vertexChunk.push_back(v);

	v.pos = postionZero + j / 2.0f - i / 2.0f;

	if (pos.y < chunkY - 1 && pos.y > 0 && pos.x < chunkX - 1 && pos.x > 0 && pos.z < chunkZ - 1 && pos.z > 0)
	{
		cubePos = pos + dir + j;
		s_1 = chunk[((int)cubePos.y + (int)cubePos.x * chunkY) + (int)cubePos.z * chunkX * chunkY];
		cubePos = pos + dir - i;
		s_2 = chunk[((int)cubePos.y + (int)cubePos.x * chunkY) + (int)cubePos.z * chunkX * chunkY];
		cubePos = pos + dir + j - i;
		corner = chunk[((int)cubePos.y + (int)cubePos.x * chunkY) + (int)cubePos.z * chunkX * chunkY];
	}
	else
	{
		s_1 = 0;
		s_2 = 0;
		corner = 0;
	}

	v.AO = aoStrenght[vertexAO(s_1, s_2, corner)];
	vertexChunk.push_back(v);
}


void Chunk::Draw()
{
	glm::mat4 model = glm::mat4(1.0f);

	auto trans = GetOwner()->GetComponent<Transform>();

	model = glm::translate(model, trans->GetPosition());
	model = glm::scale(model, trans->GetScale());


	auto shader = ResourceManager::GetShader("voxel");

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