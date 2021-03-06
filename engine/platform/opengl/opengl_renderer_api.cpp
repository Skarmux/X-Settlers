#include "platform/opengl/opengl_renderer_api.h"
#include "platform/opengl/opengl_shader.h"

#include <SDL.h> // TODO: remove SDL dependency
#include <GLFW/glfw3.h>
#include <glad/glad.h>

static int shader_program;
static unsigned int VBO, VAO, EBO;

void OpenGLRendererAPI::init()
{
	// initialize glad for SDL2
	if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress)) {
		CORE_ERROR("Failed to initialize glad!");
		exit(2);
	}

	// initialize glad for GLFW
	/*if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		CORE_ERROR("Failed to initialize glad!");
		exit(2);
	}*/

	glDisable(GL_DEPTH_TEST);
	glDisable(GL_CULL_FACE);

	// wireframe mode
	// glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

	// Enable blending / alpha
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void OpenGLRendererAPI::set_viewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height)
{
	glViewport(x, y, width, height);
}

void OpenGLRendererAPI::set_clear_color(const glm::vec4& color)
{
	glClearColor(color.r, color.g, color.b, color.a);
}

void OpenGLRendererAPI::clear()
{
	glClear(GL_COLOR_BUFFER_BIT);
}

void OpenGLRendererAPI::draw_indexed(const std::shared_ptr<VertexArray>& vertex_array, uint32_t index_count)
{
	uint32_t count = index_count ? index_count : vertex_array->get_index_buffer()->get_count();
	vertex_array->bind();
	glDrawElements(GL_TRIANGLES, count, GL_UNSIGNED_INT, nullptr);
}

void OpenGLRendererAPI::draw(const std::shared_ptr<VertexArray>& vertex_array, uint32_t triangle_vertex_count) {
	vertex_array->bind();
	glDrawArrays(GL_TRIANGLES, 0, triangle_vertex_count);
}