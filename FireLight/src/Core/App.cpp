#include "App.h"
#include <iostream>
#include "../Utility\Resource.h"
#include "SceneManager.h"
#include "../../imgui/imgui_impl_glfw_gl3.h"
#include "../../imgui/imgui.h"
#include "../Utility/Debug.h"
#include "Time.h"


	App::App()
	{

	}

	void App::start() 
	{

		//Init GLFW/GL3W and start MainLoop
		m_window = new Window(m_width, m_height, m_title.c_str());
		glfwInit();
		m_window->Init();
		if (gl3wInit())
		{
			std::cout << "OpenGL failde to inizialize" << std::endl;
		}
		glEnable(GL_DEPTH_TEST);
		glfwSwapInterval(0);

		mainLoop();
	}

	void App::mainLoop()
	{

		//init a game
		Init();
		//Time Handling

		auto texture = Resource::LoadTexture("source/Texture/Front.png", true, "sprite");
		auto shader = Resource::LoadShader("source/Shaders/2D_shader.vert", "source/Shaders/2D_shader.frag", NULL, "2D_shader");

		testBox = World::CreateEntity();

		World::addGameSystem(new PysixSystem());

		testBox->add_Component<Transform>(glm::vec3(0, 0, 0), 0.0f, glm::vec2(4, 4));
		testBox->add_Component<Sprite>(texture, shader, 6, 1, 0, 0, 64, 64);
		testBox->add_Component<MeshRender>();

		gravity = b2Vec2(0.0f, -10.0f);
		groundbodydef.position.Set(0.0f, -100.0f);
		m_World = new b2World(gravity);
		groundBody = m_World->CreateBody(&groundbodydef);

		groundBox.SetAsBox(50,10);

		groundBody->CreateFixture(&groundBox, 0.0f);



		dynmBodydef.type = b2_dynamicBody;
		dynmBodydef.position.Set(0.0f, 0.0f);
		body = m_World->CreateBody(&dynmBodydef);

		dynamicbox.SetAsBox(1.0f, 1.0f);

		fixtureDef.shape = &dynamicbox;
		fixtureDef.density = 1.0f;
		fixtureDef.friction = 0.3f;

		body->CreateFixture(&fixtureDef);

		testBox->add_Component<PhysicsBody>(body);


		Time::start();



		//MainLoop
		while (!m_window->isClosed())
		{
			Time::Calculate();

			//updateting windows stuff
			//ImGui_ImplGlfwGL3_NewFrame();

			//FixedFrame Update game
			while(Time::GetLag() >= MS_PER_UPDATE)
			{
				//Update(dt);
				SceneManager::update_current_scene(Time::GetDeltaTime());
				World::UpdateGameSystems();
				m_World->Step(Time::GetDeltaTime(), 10,8);

				

				Time::reset();
			}

			render();
			//SceneManager::debug_current_scene();
			//render game
			//ImGui::Render();
		
			m_window->Update();

			m_window->UpdateInput();

		}
		shutDown();
	}

	void App::render()
	{
		glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);
		World::RenderGameSystems();
		SceneManager::render_current_scene();
	}

	void App::shutDown() 
	{
		delete(m_window);
		glfwTerminate();
		ImGui_ImplGlfwGL3_Shutdown();
	}


	void App::set_window_dimension(int width, int height)
	{
		m_width = width;
		m_height = height;
	}

	void App::set_windiw_name(std::string name)
	{
		m_title = name;
	}


	App::~App()
	{

	}