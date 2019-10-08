#include "Mesh.h"



Mesh::Mesh()
{
	MessageBus::SendMessage("REGISTER_MESH", { "REGISTER_MESH", this });
}


Mesh::~Mesh()
{

}
