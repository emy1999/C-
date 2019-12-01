#include "array2d.h"
#include "vec3.h"

namespace Color = math::Vec3<float>;

//orismoi methodwn ths array2d.h

	//Returns the width of the array.
	const unsigned int Array2D::getWidth() const {
		return width;
	}
	
	//Returns the height of the array.
	const unsigned int Array2D::getHeight() const {
		return height;
	}
	
	//Obtains a pointer to the internal data.
	T * Array2D::getRawDataPtr() {
		return buffer;
	}
	
	//Copies the array data from an external raw buffer to the internal array buffer.
	void Array2D::setData(const T * const & data_ptr) {
		for(int i = 0; i < width*height; i++){
			Color color = data_ptr[i];
			buffer[i] = *(new Color(color.x, color.y, color.z));
		}
	}
	
	//Returns a reference to the stored item at location (x,y).
	T & Array2D::operator () (unsigned int x, unsigned int y) {
		int * p = &Color(x,y);
	}
	
	//Constructor with data initialization.
	Array2D::Array2D(unsigned int width = 0, unsigned int height = 0, const T * data_ptr = 0) {
		this->width = width;
		this->height = height;
		/*buffer = new Array2D[width*height];
		setData(data_ptr);*/
		buffer = new Color[width*height];
		setData(data_ptr);
	}
	
	//Copy constructor.
	Array2D::Array2D(const Array2D &src) {
		this->width = src.width;
		this->height = src.height;
		/*buffer = new Array2D[width*height];
		const Array2D * constBuffer = src.buffer;
		setData(constBuffer);*/
		buffer = new Color[width*height];
		const Color * constBuffer = src.buffer;
		setData(constBuffer);
	}
	
	//The Array2D destructor.
	Array2D::~Array2D() {
		if (buffer) delete[] buffer;
	}
	
	//Copy assignment operator.
	Array2D & Array2D::operator = (const Array2D & right) {
		if (buffer) delete[] buffer;
		this->width = right.width;
		this->height = right.height;
		buffer = new Color[width*height];
		const Color * constBuffer = right.buffer;
		setData(constBuffer);
		return * this;
	}
	
	