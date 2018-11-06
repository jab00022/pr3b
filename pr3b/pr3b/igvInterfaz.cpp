#include <cstdlib>
#include <stdio.h>

#include "igvInterfaz.h"

using namespace std;

extern igvInterfaz interfaz; // los callbacks deben ser estaticos y se requiere este objeto para acceder desde
                             // ellos a las variables de la clase

// Metodos constructores -----------------------------------

igvInterfaz::igvInterfaz () {
//// Apartado E: inicialización de los atributos para realizar la selección
	modo = IGV_VISUALIZAR;
	objeto_seleccionado = -1;
	boton_retenido = false;
}

igvInterfaz::~igvInterfaz () {}


// Metodos publicos ----------------------------------------

void igvInterfaz::crear_mundo(void) {
	//// Apartado B: establecer los parámetros de la cámara en función de la escena concreta que se esté modelando
	interfaz.camara.set(IGV_PARALELA, igvPunto3D(6.0, 4.0, 8), igvPunto3D(0, 0, 0), igvPunto3D(0, 1.0, 0),
		-1 * 5, 1 * 5, -1 * 5, 1 * 5, -1 * 3, 200);
}
void igvInterfaz::configura_entorno(int argc, char** argv,
			                              int _ancho_ventana, int _alto_ventana,
			                              int _pos_X, int _pos_Y,
													          string _titulo){
	// inicialización de las variables de la interfaz																	
	ancho_ventana = _ancho_ventana;
	alto_ventana = _alto_ventana;

	// inicialización de la ventana de visualización
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
////// Apartado D: incluir aquí el cambio de la cámara para mostrar las vistas planta, perfil, alzado o perspectiva
		case 'v': 
		
		break;
////// Apartado D: incluir aquí la modificación de los grados de libertad del modelo pulsando las teclas correspondientes


		case 'a': // activa/desactiva la animación de la escena
	// Apartado G: incluir aquí la activación de la animación
			
		break;
	// Apartado D: incluir aquí la activación de visualización de los BV
		case 'w': // activa/desactiva la visualización de los Bounding Volumes (BV)
			
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

	// establece los parámetros de la cámara y de la proyección
	interfaz.camara.aplicar();
}

void igvInterfaz::set_glutDisplayFunc() {
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // borra la ventana y el z-buffer
	// se establece el viewport
	glViewport(0, 0, interfaz.get_ancho_ventana(), interfaz.get_alto_ventana());

///// Apartado E: antes de aplicar las transformaciones de cámara y proyección hay que comprobar el modo para sólo visualizar o seleccionar:
	if (interfaz.modo == IGV_SELECCIONAR) {
        // Apartado E: Para que funcione habrá que dibujar la escena sin efectos, sin iluminación, sin texturas ...
        glDisable(GL_LIGHTING); // desactiva la iluminacion de la escena

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glDisable(GL_TEXTURE_2D);
		glDisable(GL_CULL_FACE);
   
		// Apartado E: Reestablece los colores como no seleccionado
		
        // Apartado E: aplica la cámara
        
		// Apartado E: visualiza los BV cada uno de un color
        		
        // Apartado E: Obtener el color del pixel seleccionado
        
		// Apartado E: Comprobar el color del objeto que hay en el cursor mirando en la tabla de colores
		
		// Apartado E: Asigna al objeto seleccionado el color amarillo
        
		// Apartado E: Cambiar a modo de visualización de la escena
        
		// Apartado E: Habilitar de nuevo la iluminación
		glEnable(GL_LIGHTING);
	} else {
		// aplica las transformaciones en función de los parámetros de la cámara
		interfaz.camara.aplicar();
		// visualiza la escena
		interfaz.escena.visualizar();
	///// Apartado D: visualiza el Bounding Volume
	
		// refresca la ventana
		glutSwapBuffers();
	}
}

void igvInterfaz::set_glutMouseFunc(GLint boton,GLint estado,GLint x,GLint y) {

// Apartado E: comprobar que se ha pulsado el botón izquierdo 
	

// Apartado E: guardar que el boton se ha presionado o se ha soltado, si se ha pulsado hay que
// pasar a modo IGV_SELECCIONAR
	


// Apartado E: guardar el pixel pulsado
	

// Apartado E: renovar el contenido de la ventana de vision 
	
}

void igvInterfaz::set_glutMotionFunc(GLint x,GLint y) {

// Apartado F: si el botón está retenido y hay algún objeto seleccionado,
// comprobar el objeto seleccionado y la posición del ratón y actualizar
// convenientemente el grado de libertad del objeto correspondiente 



// Apartado F: guardar la nueva posición del ratón 


// Apartado F: renovar el contenido de la ventana de vision 
	

}

void igvInterfaz::set_glutIdleFunc() {
///// Apartado G: incluir el código para animar el modelo de la manera más realista posible
	

}

void igvInterfaz::inicializa_callbacks() {
	glutKeyboardFunc(set_glutKeyboardFunc);
	glutReshapeFunc(set_glutReshapeFunc);
	glutDisplayFunc(set_glutDisplayFunc);

    glutMouseFunc(set_glutMouseFunc);
    glutMotionFunc(set_glutMotionFunc);
	glutIdleFunc(set_glutIdleFunc);
}

