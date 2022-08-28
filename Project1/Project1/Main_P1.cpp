#include<iostream>

//#define GLEW_STATIC

#include <GL/glew.h>

#include <GLFW/glfw3.h>

// Shaders
#include "Shader.h"

void resize(GLFWwindow* window, int width, int height);

const GLint WIDTH = 800, HEIGHT = 600;


int main() {
	glfwInit();
	//Verificación de compatibilidad 
	/*glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_COMPAT_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);*/

	GLFWwindow *window = glfwCreateWindow(WIDTH, HEIGHT, "Practica 1", NULL, NULL);
	glfwSetFramebufferSizeCallback(window, resize);
	
	//Verificación de errores de creacion  ventana
	if (window== NULL) 
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();

		return EXIT_FAILURE;
	}

	glfwMakeContextCurrent(window);
	glewExperimental = GL_TRUE;

	//Verificación de errores de inicialización de glew

	if (GLEW_OK != glewInit()) {
		std::cout << "Failed to initialise GLEW" << std::endl;
		return EXIT_FAILURE;
	}

	// Imprimimos informacin de OpenGL del sistema
	std::cout << "> Version: " << glGetString(GL_VERSION) << std::endl;
	std::cout << "> Vendor: " << glGetString(GL_VENDOR) << std::endl;
	std::cout << "> Renderer: " << glGetString(GL_RENDERER) << std::endl;
	std::cout << "> SL Version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;


	Shader OurShader("Shader/core.vs", "Shader/core.frag");//cremaos objjeto shader


	// Set up vertex data (and buffer(s)) and attribute pointers datos de entrada cordenadas
	float vertices[] = {
		//figura 1
		-0.65f,  0.62f, 0.0f,  0.98f,0.18f,0.71f,  // 0 A
		-0.59f, 0.56f, 0.0f,   0.98f,0.18f,0.71f,  // 1 E
		-0.65f, 0.49f, 0.0f,   0.98f,0.18f,0.71f,  // 2 B
	
		-0.59f, 0.56f, 0.0f,   0.07f,0.39f,0.87f,  // 3 E
		-0.53f, 0.62f, 0.0f,   0.07f,0.39f,0.87f,  // 4 F
		-0.53f, 0.50f, 0.0f,   0.07f,0.39f,0.87f,   // 5 G

		-0.59f, 0.56f, 0.0f,   0.36f,0.7f,0.09f,  // 6 E
		-0.65f, 0.49f, 0.0f,   0.36f,0.7f,0.09f,  // 7 B
		-0.59f, 0.44f, 0.0f,   0.36f,0.7f,0.09f,  // 8 O
		-0.59f, 0.56f, 0.0f,   0.36f,0.7f,0.09f,  // 9 E
		-0.59f, 0.44f, 0.0f,   0.36f,0.7f,0.09f,  // 10 O
		-0.53f, 0.50f, 0.0f,   0.36f,0.7f,0.09f,   // 11 G

		-0.59f, 0.44f, 0.0f,   0.33f,0.29f,0.58f,  // 12 O
		-0.50f, 0.53f, 0.0f,   0.33f,0.29f,0.58f,  // 13 P
		-0.40f, 0.53f, 0.0f,   0.33f,0.29f,0.58f,  // 14 K
		
		-0.59f, 0.44f, 0.0f,   0.33f,0.29f,0.58f,  // 15 O
		-0.48f, 0.44f, 0.0f,   0.33f,0.29f,0.58f,  // 16 M
		-0.40f, 0.53f, 0.0f,   0.33f,0.29f,0.58f,  // 17 K

		-0.48f, 0.44f, 0.0f,   0.95f,0.33f,0.07f,  // 18 M
		-0.40f, 0.53f, 0.0f,   0.95f,0.33f,0.07f,  // 19 K
		-0.40f, 0.33f, 0.0f,   0.95f,0.33f,0.07f,  // 20 N

		-0.40f, 0.53f, 0.0f,   0.99f,0.85f,0.0f,  // 21 K
		-0.40f, 0.24f, 0.0f,   0.99f,0.85f,0.0f,  // 22 L
		-0.27f, 0.38f, 0.0f,   0.99f,0.85f,0.0f,  // 23 J

		-0.27f, 0.38f, 0.0f,   0.85f,0.07f,0.07f,  // 24 J
		-0.45f, 0.20f, 0.0f,   0.85f,0.07f,0.07f,  // 25 I
		-0.27f, 0.20f, 0.0f,   0.85f,0.07f,0.07f,  // 26 H
		//figura2
		0.57f, -0.31f, 0.0f,   0.07f,0.39f,0.87f,  // 27 C
		0.48f, -0.31f, 0.0f,   0.07f,0.39f,0.87f,  // 28 S
		0.53f, -0.26f, 0.0f,   0.07f,0.39f,0.87f,  // 29 D

		0.48f, -0.31f, 0.0f,   0.36f,0.7f,0.09f,  // 30 S
		0.53f, -0.26f, 0.0f,   0.36f,0.7f,0.09f,  // 31 D
		0.48f, -0.20f, 0.0f,   0.36f,0.7f,0.09f,  // 32 F1
		0.48f, -0.31f, 0.0f,   0.36f,0.7f,0.09f,  // 33 S
		0.48f, -0.20f, 0.0f,   0.36f,0.7f,0.09f,  // 34 F1
		0.42f, -0.26f, 0.0f,   0.36f,0.7f,0.09f,  // 35 G1

		0.48f, -0.31f, 0.0f,   0.99f,0.85f,0.0f,  // 36 S
		0.37f, -0.20f, 0.0f,   0.99f,0.85f,0.0f,  // 37 T
		0.26f, -0.31f, 0.0f,   0.99f,0.85f,0.0f,  // 38 U

		0.26f, -0.31f, 0.0f,   0.85f,0.07f,0.07f,  // 39 U
		0.41f, -0.31f, 0.0f,   0.85f,0.07f,0.07f,  // 40 W
		0.26f, -0.45f, 0.0f,   0.85f,0.07f,0.07f,  // 41 V

		0.26f, -0.45f, 0.0f,   0.98f,0.18f,0.71f,  // 42 V
		0.31f, -0.51f, 0.0f,   0.98f,0.18f,0.71f,  // 43 A1
		0.22f, -0.51f, 0.0f,   0.98f,0.18f,0.71f,  // 44 Z

		0.26f, -0.31f, 0.0f,   0.95f,0.33f,0.07f,  // 45 U
		0.26f, -0.41f, 0.0f,   0.95f,0.33f,0.07f,  // 46 C1
		0.15f, -0.41f, 0.0f,   0.95f,0.33f,0.07f,  // 47 B1

		0.15f, -0.41f, 0.0f,   0.33f,0.29f,0.58f,  // 48 B1
		0.23f, -0.41f, 0.0f,   0.33f,0.29f,0.58f,  // 49 H1
		0.15f, -0.47f, 0.0f,   0.33f,0.29f,0.58f,  // 50 E1

		0.15f, -0.41f, 0.0f,   0.33f,0.29f,0.58f,  // 51 B1
		0.08f, -0.47f, 0.0f,   0.33f,0.29f,0.58f,  // 52 D1
		0.15f, -0.47f, 0.0f,   0.33f,0.29f,0.58f,  // 53 E1



	};
	unsigned int indices[] = {  // note that we start from 0! arrego indices hace referencia  alos elementos 
		0,1,2,
		3,4,5,
		6,7,8,
		9,10,11,
		12,13,14,
		15,16,17,
		18,19,20,
		21,22,23,
		24,25,26,
		27,28,29,
		30,31,32,
		33,34,35,
		36,37,38,
		39,40,41,
		42,43,44,
		45,46,47,
		48,49,50,
		51,52,53,
	};



	GLuint VBO, VAO,EBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);

	// Enlazar  Vertex Array Object
	glBindVertexArray(VAO);

	//2.- Copiamos nuestros arreglo de vertices en un buffer de vertices para que OpenGL lo use
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	// 3.Copiamos nuestro arreglo de indices en  un elemento del buffer para que OpenGL lo use
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

	// 4. Despues colocamos las caracteristicas de los vertices

	//Posicion
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid *)0);//tomamos desde 0 tres elementos de 6 y guardamos en localidad0 de memoria
	glEnableVertexAttribArray(0);

	//Color
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid *)(3*sizeof(GLfloat)));// se guarda en el primero en el 3 toma los elementos tres que representan color 
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);


	glBindVertexArray(0); // Desenlazamos de memoria el VAO


	
	while (!glfwWindowShouldClose(window))
	{
		// Checa si un eveneto ha sido activado y manda a llamar al callback correspondiente
		glfwPollEvents();

		// Render
		// Clear the colorbuffer
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);


		// Dibujar aquí
		OurShader.Use();
		glBindVertexArray(VAO);//informacion d eloq eu vamosa dibujar VAO la contiene 
		glPointSize(10); //TAMÑO DEPUNTOS 
		//glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, (GLvoid*)(3 * sizeof(GLfloat)));
	    glDrawElements(GL_TRIANGLES,4, GL_UNSIGNED_INT, (GLvoid*)(0*sizeof(GLfloat)));//de donde termino de tomar elementos, desde donde empiezo a tomar elementos
		glDrawElements(GL_TRIANGLES, 5, GL_UNSIGNED_INT, (GLvoid*)(3 * sizeof(GLfloat)));
		glDrawElements(GL_TRIANGLES, 8, GL_UNSIGNED_INT, (GLvoid*)(6 * sizeof(GLfloat)));
		glDrawElements(GL_TRIANGLES, 11, GL_UNSIGNED_INT, (GLvoid*)(9 * sizeof(GLfloat)));
		glDrawElements(GL_TRIANGLES, 14, GL_UNSIGNED_INT, (GLvoid*)(12 * sizeof(GLfloat)));
		glDrawElements(GL_TRIANGLES, 17, GL_UNSIGNED_INT, (GLvoid*)(15 * sizeof(GLfloat)));
		glDrawElements(GL_TRIANGLES, 20, GL_UNSIGNED_INT, (GLvoid*)(18 * sizeof(GLfloat)));
		glDrawElements(GL_TRIANGLES, 23, GL_UNSIGNED_INT, (GLvoid*)(21 * sizeof(GLfloat)));
		glDrawElements(GL_TRIANGLES, 26, GL_UNSIGNED_INT, (GLvoid*)(24 * sizeof(GLfloat)));
		glDrawElements(GL_TRIANGLES, 29, GL_UNSIGNED_INT, (GLvoid*)(27 * sizeof(GLfloat)));
		glDrawElements(GL_TRIANGLES, 32, GL_UNSIGNED_INT, (GLvoid*)(30 * sizeof(GLfloat)));
		glDrawElements(GL_TRIANGLES, 35, GL_UNSIGNED_INT, (GLvoid*)(33 * sizeof(GLfloat)));
		glDrawElements(GL_TRIANGLES, 38, GL_UNSIGNED_INT, (GLvoid*)(36 * sizeof(GLfloat)));
		glDrawElements(GL_TRIANGLES, 41, GL_UNSIGNED_INT, (GLvoid*)(39 * sizeof(GLfloat)));
		glDrawElements(GL_TRIANGLES, 44, GL_UNSIGNED_INT, (GLvoid*)(42 * sizeof(GLfloat)));
		glDrawElements(GL_TRIANGLES, 47, GL_UNSIGNED_INT, (GLvoid*)(45 * sizeof(GLfloat)));
		glDrawElements(GL_TRIANGLES, 50, GL_UNSIGNED_INT, (GLvoid*)(48 * sizeof(GLfloat)));
		glBindVertexArray(0);
	

		// Swap the screen buffers
		glfwSwapBuffers(window);
	}



	glfwTerminate();
	return EXIT_SUCCESS;
}

void resize(GLFWwindow* window, int width, int height)
{
	// Set the Viewport to the size of the created window
	glViewport(0, 0, width, height);
	//glViewport(0, 0, screenWidth, screenHeight);
}