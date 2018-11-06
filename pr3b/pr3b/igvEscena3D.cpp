#include <cstdlib>
#include <stdio.h>

#include "igvEscena3D.h"

// Metodos constructores 

igvEscena3D::igvEscena3D () {
	ejes = true;

// Apartado D: inicializar los atributos para el control de los grados de libertad del modelo 
	

// Apartado E: inicializar el atributo/s que indica/n el objeto seleccionado para pintarlo de otro color
	
}

igvEscena3D::~igvEscena3D() {

}


// Metodos publicos 

void pintar_ejes(void) {
  GLfloat rojo[]={1,0,0,1.0};
  GLfloat verde[]={0,1,0,1.0};
  GLfloat azul[]={0,0,1,1.0};

  glMaterialfv(GL_FRONT,GL_EMISSION,rojo);
	glBegin(GL_LINES);
		glVertex3f(1000,0,0);
		glVertex3f(-1000,0,0);
	glEnd();

  glMaterialfv(GL_FRONT,GL_EMISSION,verde);
	glBegin(GL_LINES);
		glVertex3f(0,1000,0);
		glVertex3f(0,-1000,0);
	glEnd();

  glMaterialfv(GL_FRONT,GL_EMISSION,azul);
	glBegin(GL_LINES);
		glVertex3f(0,0,1000);
		glVertex3f(0,0,-1000);
	glEnd();
}

///// Apartado B: Métodos para visualizar cada parte del modelo



////// Apartado C: Métodos para visualizar los volúmenes envolventes (BV) 

void igvEscena3D::pintar_BV(float escalaX, float escalaY, float escalaZ, float *color) {
///// Apartado C: Es importante no usar materiales, sino colores de OpenGL
    glColor3fv(color);
///// Apartado C: Incluir el codigo para pintar un Volumen Envolvente unidad, escalado y del color determinado



}

void igvEscena3D::visualizar_BV() {
///// Apartado C: aquí hay que añadir la visualización del árbol de Bounding Volume del modelo utilizando la pila de matrices de OpenGL
/////             se recomienda crear una método auxiliar que encapsule todo el código para la visualización
/////             del modelo, dejando aquí sólo la llamada a ese método. 

///// Apartado E: Incluir el color de selección adecuado para cada parte

	

}

void igvEscena3D::visualizar() {
	// crear luces
	GLfloat luz0[4]={5.0,5.0,5.0,1}; // luz puntual  
	glLightfv(GL_LIGHT0,GL_POSITION,luz0); // la luz se coloca aquí si permanece fija y no se mueve con la escena
	glEnable(GL_LIGHT0);

	// crear el modelo
	glPushMatrix(); // guarda la matriz de modelado

	// se pintan los ejes
	if (ejes) pintar_ejes();

	//glLightfv(GL_LIGHT0,GL_POSITION,luz0); // la luz se coloca aquí si se mueve junto con la escena

///// Apartado B: aquí hay que añadir la visualización del árbol del modelo utilizando la pila de matrices de OpenGL
/////             se recomienda crear una método auxiliar que encapsule todo el código para la visualización
/////             del modelo, dejando aquí sólo la llamada a ese método, así como distintas funciones una para cada
/////			  parte del modelo. 
	
///// En el apartado E habrá que asignar un color de selección al objeto para indicar que la parte seleccionada se
/////			visualice de un color distinto

	
	  
	glPopMatrix (); // restaura la matriz de modelado
}

// Apartado E: Método/s para indicar el objeto seleccionado



