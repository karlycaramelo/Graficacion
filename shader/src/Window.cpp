#include "Window.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

using namespace glm;

Window::Window()
{
    //ctor
}

Window::~Window()
{
    //dtor
}


void Window::initGLEW()
{
    glewExperimental = GL_TRUE;
    glewInit();
    const GLubyte *renderer = glGetString(GL_RENDERER);
    const GLubyte *vendor = glGetString(GL_VENDOR);
    const GLubyte *version = glGetString(GL_VERSION);
    const GLubyte *glslVersion = glGetString(GL_SHADING_LANGUAGE_VERSION);
    GLint next;
    glGetIntegerv(GL_NUM_EXTENSIONS, &next);
    cout << "Vendor: " << vendor << endl;
    cout << "Renderer: " << renderer << endl;
    cout << "Version: " << version << endl;
    cout << "glslVersion: " << glslVersion << endl;
    for(int i = 0; i < next; i++)
        cout << glGetStringi(GL_EXTENSIONS, i) << endl;
}


void Window::initGLFW()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_RESIZABLE, GL_TRUE);

    window = glfwCreateWindow(window_w, window_h, title.c_str(), nullptr, nullptr);

    if(!window)
    {
        cout<<"Failed to crate GLFW window"<<endl;
        glfwTerminate();
        return;
    }

    glfwMakeContextCurrent(window);
    glfwSetKeyCallback(window, key_callback);
}

void Window::startup(string title)
{
    this->title = title;
    initGLFW();
    initGLEW();
    glEnable(GL_DEPTH_TEST);

    program.startup();
    cubo.startup();
}

void Window::shutdown()
{
    cubo.shutdown();
    program.shutdown();
    glfwTerminate();
}

void Window::run()
{

    mat4 model, view, projection;
    projection = glm::perspective(radians(45.0f), (float)window_w/(float)window_h, 0.1f, 100.0f);
    view = glm::translate(view, vec3(0.0f, 0.0f, -3.0f));
    model = glm::rotate(model, radians(45.0f), vec3(0.0f, 1.0f, 1.0f)); //mat4(1.0f)
    mat4 mvp = projection*view*model;


    do{
        glClearColor(0.3f, 0.5f,1.0f,1.0f);
        glClear(GL_COLOR_BUFFER_BIT| GL_DEPTH_BUFFER_BIT);
        program.use();
        program.setUniform("mvp", mvp);
        cubo.draw();
        glfwSwapBuffers(window);
        glfwPollEvents();
    } while(!glfwWindowShouldClose(window));
    shutdown();
}


void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if(action== GLFW_PRESS)
    {
        switch(key)
        {
            case GLFW_KEY_ESCAPE:
                glfwSetWindowShouldClose(window, GL_TRUE);
                break;
        }
    }
}

