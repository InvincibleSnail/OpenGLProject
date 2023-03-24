//#include <glad/glad.h>
//#include <GLFW/glfw3.h>
//#include <stb_image.h>
//
//#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtc/type_ptr.hpp>
//
//#include <Shader.hpp>
//#include <Camera.hpp>
//
//#include <iostream>
//
//GLFWwindow* initGLFWWindow();
//void framebuffer_size_callback(GLFWwindow* window, int width, int height);
//void mouse_callback(GLFWwindow* window, double xpos, double ypos);
//void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
//void processInput(GLFWwindow* window);
//
//const unsigned int SCREEN_WIDTH = 800;
//const unsigned int SCREEN_HEIGHT = 600;
//const char* TITLE = "LearnOpenGL";
//
//// camera
//Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));
//float lastX = SCREEN_WIDTH / 2.0f;
//float lastY = SCREEN_HEIGHT / 2.0f;
//bool firstMouse = true;
//
//// timing
//float deltaTime = 0.0f;	// time between current frame and last frame
//float lastFrame = 0.0f;
//
//glm::vec3 lightPos(1.2f, 1.0f, 2.0f);
//
//int main()
//{
//	GLFWwindow* window = initGLFWWindow();
//	if (window == NULL) return -1;
//	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) return -1;
//
//	glEnable(GL_DEPTH_TEST);
//
//	Shader lightingShader("P:/OpenGLProject/src/vertexShader.vs", "P:/OpenGLProject/src/fragmentShader.fs");
//	Shader lightCubeShader("P:/OpenGLProject/colors.vs", "P:/OpenGLProject/colors.fs");
//
//	float vertices[] = {
//		   -0.5f, -0.5f, -0.5f,
//			0.5f, -0.5f, -0.5f,
//			0.5f,  0.5f, -0.5f,
//			0.5f,  0.5f, -0.5f,
//		   -0.5f,  0.5f, -0.5f,
//		   -0.5f, -0.5f, -0.5f,
//
//		   -0.5f, -0.5f,  0.5f,
//			0.5f, -0.5f,  0.5f,
//			0.5f,  0.5f,  0.5f,
//			0.5f,  0.5f,  0.5f,
//		   -0.5f,  0.5f,  0.5f,
//		   -0.5f, -0.5f,  0.5f,
//
//		   -0.5f,  0.5f,  0.5f,
//		   -0.5f,  0.5f, -0.5f,
//		   -0.5f, -0.5f, -0.5f,
//		   -0.5f, -0.5f, -0.5f,
//		   -0.5f, -0.5f,  0.5f,
//		   -0.5f,  0.5f,  0.5f,
//
//			0.5f,  0.5f,  0.5f,
//			0.5f,  0.5f, -0.5f,
//			0.5f, -0.5f, -0.5f,
//			0.5f, -0.5f, -0.5f,
//			0.5f, -0.5f,  0.5f,
//			0.5f,  0.5f,  0.5f,
//
//		   -0.5f, -0.5f, -0.5f,
//			0.5f, -0.5f, -0.5f,
//			0.5f, -0.5f,  0.5f,
//			0.5f, -0.5f,  0.5f,
//		   -0.5f, -0.5f,  0.5f,
//		   -0.5f, -0.5f, -0.5f,
//
//		   -0.5f,  0.5f, -0.5f,
//			0.5f,  0.5f, -0.5f,
//			0.5f,  0.5f,  0.5f,
//			0.5f,  0.5f,  0.5f,
//		   -0.5f,  0.5f,  0.5f,
//		   -0.5f,  0.5f, -0.5f,
//	};
//	unsigned int VBO, cubeVAO;
//	glGenVertexArrays(1, &cubeVAO);
//	glGenBuffers(1, &VBO);
//
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
//
//	glBindVertexArray(cubeVAO);
//
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(0);
//
//	unsigned int lightCubeVAO;
//	glGenVertexArrays(1, &lightCubeVAO);
//	glBindVertexArray(lightCubeVAO);
//
//	glBindBuffer(GL_ARRAY_BUFFER, VBO);
//
//	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
//	glEnableVertexAttribArray(0);
//
//
//	// render loop
//	// -----------
//	while (!glfwWindowShouldClose(window))
//	{
//		// per-frame time logic
//		// --------------------
//		float currentFrame = static_cast<float>(glfwGetTime());
//		deltaTime = currentFrame - lastFrame;
//		lastFrame = currentFrame;
//
//		// input
//		// -----
//		processInput(window);
//
//		// render
//		// ------
//		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
//		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//		// be sure to activate shader when setting uniforms/drawing objects
//		lightingShader.use();
//		lightingShader.setVec3("objectColor", 1.0f, 0.5f, 0.31f);
//		lightingShader.setVec3("lightColor", 1.0f, 1.0f, 1.0f);
//
//		// view/projection transformations
//		glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)SCREEN_WIDTH / (float)SCREEN_HEIGHT, 0.1f, 100.0f);
//		glm::mat4 view = camera.GetViewMatrix();
//		lightingShader.setMat4("projection", projection);
//		lightingShader.setMat4("view", view);
//
//		// world transformation
//		glm::mat4 model = glm::mat4(1.0f);
//		lightingShader.setMat4("model", model);
//
//		// render the cube
//		glBindVertexArray(cubeVAO);
//		glDrawArrays(GL_TRIANGLES, 0, 36);
//
//
//		// also draw the lamp object
//		lightCubeShader.use();
//		lightCubeShader.setMat4("projection", projection);
//		lightCubeShader.setMat4("view", view);
//		model = glm::mat4(1.0f);
//		model = glm::translate(model, lightPos);
//		model = glm::scale(model, glm::vec3(0.2f)); // a smaller cube
//		lightCubeShader.setMat4("model", model);
//
//		glBindVertexArray(lightCubeVAO);
//		glDrawArrays(GL_TRIANGLES, 0, 36);
//
//
//		// glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
//		// -------------------------------------------------------------------------------
//		glfwSwapBuffers(window);
//		glfwPollEvents();
//	}
//
//	// optional: de-allocate all resources once they've outlived their purpose:
//	// ------------------------------------------------------------------------
//	glDeleteVertexArrays(1, &cubeVAO);
//	glDeleteVertexArrays(1, &lightCubeVAO);
//	glDeleteBuffers(1, &VBO);
//
//	// glfw: terminate, clearing all previously allocated GLFW resources.
//	// ------------------------------------------------------------------
//	glfwTerminate();
//	return 0;
//}
//
//GLFWwindow* initGLFWWindow() {
//	glfwInit();
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
//
//#ifdef __APPLE__
//	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
//#endif
//
//	GLFWwindow* window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, TITLE, NULL, NULL);
//	if (window == NULL) {
//		glfwTerminate();
//		return NULL;
//	}
//	else {
//		glfwMakeContextCurrent(window);
//		glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
//		glfwSetCursorPosCallback(window, mouse_callback);
//		glfwSetScrollCallback(window, scroll_callback);
//		glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
//		return window;
//	}
//}
//
//void processInput(GLFWwindow* window)
//{
//	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//		glfwSetWindowShouldClose(window, true);
//
//	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
//		camera.ProcessKeyboard(FORWARD, deltaTime);
//	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
//		camera.ProcessKeyboard(BACKWARD, deltaTime);
//	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
//		camera.ProcessKeyboard(LEFT, deltaTime);
//	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
//		camera.ProcessKeyboard(RIGHT, deltaTime);
//}
//
//void framebuffer_size_callback(GLFWwindow* window, int width, int height)
//{
//	glViewport(0, 0, width, height);
//}
//
//void mouse_callback(GLFWwindow* window, double xposIn, double yposIn)
//{
//	float xpos = static_cast<float>(xposIn);
//	float ypos = static_cast<float>(yposIn);
//
//	if (firstMouse)
//	{
//		lastX = xpos;
//		lastY = ypos;
//		firstMouse = false;
//	}
//
//	float xoffset = xpos - lastX;
//	float yoffset = lastY - ypos;
//
//	lastX = xpos;
//	lastY = ypos;
//
//	camera.ProcessMouseMovement(xoffset, yoffset);
//}
//
//void scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
//{
//	camera.ProcessMouseScroll(static_cast<float>(yoffset));
//}