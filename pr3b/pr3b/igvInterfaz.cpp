#include <cstdlib>
#include <stdio.h>

#include "igvInterfaz.h"

using namespace std;

extern igvInterfaz interfaz; // los callbacks deben ser estaticos y se requiere este objeto para acceder desde
                             // ellos a las variables de la clase

// Metodos constructores -----------------------------------

igvInterfaz::igvInterfaz () {
//// Apartado E: inicializaci�n de los atributos para realizar la selecci�n
	modo = IGV_VISUALIZAR;
	objeto_seleccionado = -1;
	boton_retenido = false;
}

igvInterfaz::~igvInterfaz () {}


// Metodos publicos ----------------------------------------

void igvInterfaz::crear_mundo(void) {
	//// Apartado B: establecer los par�metros de la c�mara en funci�n de la escena concreta que se est� modelando
	interfaz.camara.set(IGV_PARALELA, igvPunto3D(6.0, 4.0, 8), igvPunto3D(0, 0, 0), igvPunto3D(0, 1.0, 0),
		-1 * 5, 1 * 5, -1 * 5, 1 * 5, -1 * 3, 200);
}
void igvInterfaz::configura_entorno(int argc, char** argv,
			                              int _ancho_ventana, int _alto_ventana,
			                              int _pos_X, int _pos_Y,
													          string _titulo){
	// inicializaci�n de las variables de la interfaz																	
	ancho_ventana = _ancho_ventana;
	alto_ventana = _alto_ventana;

	// inicializaci�n de la ventana de visualizaci�n
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(_ancho_ventana,_alto_ventana);
	glutInitWindowPosition(_pos_X,_pos_Y);
	glutCreateWindow(_titulo.c_str());

	glEnable(GL_DEPTH_TEST); // activa el ocultamiento de superficies por z-buffer
	glClearColor(1.0,1.0,1.0,0.0); // establece el color de fondo de la ventana

	glEnable(GL_LIGHTING); // activa la iluminacion de la escena
	glEnable(GL_NORMALIZE); // normaliza los vectores normales para calculo iluminacion

	crear_mundo(); // crea el mundo a visualizar en la ventana
}

void igvInterfaz::inicia_bucle_visualizacion() {
	glutMainLoop(); // inicia el bucle de visualizacion de OpenGL
}

void igvInterfaz::set_glutKeyboardFunc(unsigned char key, int x, int y) {
	switch (key) {
////// Apartado D: incluir aqu� el cambio de la c�mara para mostrar las vistas planta, perfil, alzado o perspectiva
		case 'v': 
		
		break;
////// Apartado D: incluir aqu� la modificaci�n de los grados de libertad del modelo pulsando las teclas correspondientes


		case 'a': // activa/desactiva la animaci�n de la escena
	// Apartado G: incluir aqu� la activaci�n de la animaci�n
			
		break;
	// Apartado D: incluir aqu� la activaci�n de visualizaci�n de los BV
		case 'w': // activa/desactiva la visualizaci�n de los Bounding Volumes (BV)
			
		break;
		case 'e': // activa/desactiva la visualizacion de los ejes
			interfaz.escena.set_ejes(interfaz.escena.get_ejes()?false:true);
		break;
		case 27: // tecla de escape para SALIR
			exit(1);
		break;
  }
	glutPostRedisplay(); // renueva el contenido de la ventana de vision
}

void igvInterfaz::set_glutReshapeFunc(int w, int h) {
  // dimensiona el viewport al nuevo ancho y alto de la ventana
  // guardamos valores nuevos de la ventana de visualizacion
	interfaz.set_ancho_ventana(w);
	interfaz.set_alto_ventana(h);

	// establece los par�metros de la c�mara y de la proyecci�n
	interfaz.camara.aplicar();
}

void igvInterfaz::set_glutDisplayFunc() {
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // borra la ventana y el z-buffer
	// se establece el viewport
	glViewport(0, 0, interfaz.get_ancho_ventana(), interfaz.get_alto_ventana());

///// Apartado E: antes de aplicar las transformaciones de c�mara y proyecci�n hay que comprobar el modo para s�lo visualizar o seleccionar:
	if (interfaz.modo == IGV_SELECCIONAR) {
        // Apartado E: Para que funcione habr� que dibujar la escena sin efectos, sin iluminaci�n, sin texturas ...
        glDisable(GL_LIGHTING); // desactiva la iluminacion de la escena

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glDisable(GL_TEXTURE_2D);
		glDisable(GL_CULL_FACE);
   
		// Apartado E: Reestablece los colores como no seleccionado
		
        // Apartado E: aplica la c�mara
        
		// Apartado E: visualiza los BV cada uno de un color
        		
        // Apartado E: Obtener el color del pixel seleccionado
        
		// Apartado E: Comprobar el color del objeto que hay en el cursor mirando en la tabla de colores
		
		// Apartado E: Asigna al objeto seleccionado el color amarillo
        
		// Apartado E: Cambiar a modo de visualizaci�n de la escena
        
		// Apartado E: Habilitar de nuevo la iluminaci�n
		glEnable(GL_LIGHTING);
	} else {
		// aplica las transformaciones en funci�n de los par�metros de la c�mara
		interfaz.camara.aplicar();
		// visualiza la escena
		interfaz.escena.visualizar();
	///// Apartado D: visualiza el Bounding Volume
	
		// refresca la ventana
		glutSwapBuffers();
	}
}

void igvInterfaz::set_glutMouseFunc(GLint boton,GLint estado,GLint x,GLint y) {

// Apartado E: comprobar que se ha pulsado el bot�n izquierdo 
	

// Apartado E: guardar que el boton se ha presionado o se ha soltado, si se ha pulsado hay que
// pasar a modo IGV_SELECCIONAR
	


// Apartado E: guardar el pixel pulsado
	

// Apartado E: renovar el contenido de la ventana de vision 
	
}

void igvInterfaz::set_glutMotionFunc(GLint x,GLint y) {

// Apartado F: si el bot�n est� retenido y hay alg�n objeto seleccionado,
// comprobar el objeto seleccionado y la posici�n del rat�n y actualizar
// convenientemente el grado de libertad del objeto correspondiente 



// Apartado F: guardar la nueva posici�n del rat�n 


// Apartado F: renovar el contenido de la ventana de vision 
	

}

void igvInterfaz::set_glutIdleFunc() {
///// Apartado G: incluir el c�digo para animar el modelo de la manera m�s realista posible
	

}

void igvInterfaz::inicializa_callbacks() {
	glutKeyboardFunc(set_glutKeyboardFunc);
	glutReshapeFunc(set_glutReshapeFunc);
	glutDisplayFunc(set_glutDisplayFunc);

    glutMouseFunc(set_glutMouseFunc);
    glutMotionFunc(set_glutMotionFunc);
	glutIdleFunc(set_glutIdleFunc);
}

