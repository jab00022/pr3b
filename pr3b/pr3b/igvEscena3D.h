#ifndef __IGVESCENA3D
#define __IGVESCENA3D

#if defined(__APPLE__) && defined(__MACH__)
#include <GLUT/glut.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#else
#include <GL/glut.h>
#endif


enum {
	basex,
	cuerpoinferior,
	cuerposuperior,
	brazo
};

class igvEscena3D {
	protected:
////// Apartado D: a�adir qu� los atributos para el control de los grados de libertad del modelo
		

////// Apartado E: a�adir aqu� el atributo/s para el control del objeto seleccionado y colorearlo en amarillo
		

		// Otros atributos		
		bool ejes;

	public:
////// Apartado E: color de los vol�menes envolventes para la selecci�n
		

		// Constructores por defecto y destructor
		igvEscena3D();
		~igvEscena3D();

		// Metodos est�ticos

////// Apartado C: M�todos para visualizar los vol�menes envolventes (BV) 
    void pintar_BV(float escalaX, float escalaY, float escalaZ, float *color);
	void visualizar_BV();
	
	// m�todo con las llamadas OpenGL para visualizar la escena
    void visualizar(void);

///// Apartado B: M�todos para visualizar cada parte del modelo
	

////// Apartado D: a�adir aqu� los m�todos para modificar los grados de libertad del modelo
	

////// Apartado E: a�adir aqu� el m�todo/s para indicar el objeto seleccionado
	

	bool get_ejes() { return ejes; };
	void set_ejes(bool _ejes) { ejes = _ejes; };

};

#endif
