namespace pro {

template<class T>class vector {
public:
	vector();
	vector(T x, T y);
	~vector();
	void setX(T x);
	void setY(T y);
	T &getX();
	T &getY();
private:
	T x;
	T y;
};


template<class T> vector<T>::vector() {

}

template<class T> vector<T>::vector(T x, T y) {
	this->x = x;
	this->y = y;
}

template<class T> vector<T>::~vector() {

}

template<class T> void vector<T>::setX(T x) {
	this->x = x;
}

template<class T> void vector<T>::setY(T y) {
	this->y = y;
}

template<class T> T &vector<T>::getX() {
	return x;
}

template<class T> T &vector<T>::getY() {
	return y;
}

}