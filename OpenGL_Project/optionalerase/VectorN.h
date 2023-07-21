#pragma once

template<typename T, int N>
class VectorN
{
public:
	VectorN();

	T& operator[](const int i);
	T operator[](const int i) const;

private:
	T value[N];
};

/* Implement */
template<typename T, int N>
VectorN<T, N> operator+(const VectorN<T, N>& v1, const VectorN<T, N>& v2);
template<typename T, int N>
VectorN<T, N> operator-(const VectorN<T, N>& v1, const VectorN<T, N>& v2);
template<typename T, int N>
VectorN<T, N> operator-(const VectorN<T, N>& v);
template<typename T, int N>
VectorN<T, N> operator*(const T s, const VectorN<T, N>& vec3);
template<typename T, int N>
T dotProduct(const VectorN<T, N>& v1, const VectorN<T, N>& v2);

template<typename T, int N>
 VectorN<T, N>::VectorN() {
	 for (int i = 0; i < N; i++) {
		 value[i] = 0;
	}
}

template<typename T, int N>
T& VectorN<T, N>::operator[](const int i) {
	return value[i];
}

template<typename T, int N>
T VectorN<T, N>::operator[](const int i)const {
	return value[i];
}

template<typename T, int N>
VectorN<T, N> operator+(const VectorN<T, N>& v1, const VectorN<T, N>& v2) {
	VectorN<T, N> v;
	for (int i = 0; i < N; i++) {
		v[i] = v1[i] + v2[i];
	}
	return v;
}

template<typename T, int N>
VectorN<T, N> operator-(const VectorN<T, N>& v1, const VectorN<T, N>& v2) {
	VectorN<T, N> v;
	for (int i = 0; i < N; i++) {
		v[i] = v1[i] - v2[i];
	}
	return v;
}

template<typename T, int N>
VectorN<T, N> operator-(const VectorN<T, N>& v) {
	VectorN<T, N> v;
	for (int i = 0; i < N; i++) {
		v[i] = -v[i];
	}
	return v;
}

template<typename T, int N>
VectorN<T, N> operator*(const T s, const VectorN<T, N>& vec3) {
	VectorN<T, N> v;
	for (int i = 0; i < N; i++) {
		v[i] = s*vec3[i];
	}
	return v;
}

template<typename T, int N>
T dotProduct(const VectorN<T, N>& v1, const VectorN<T, N>& v2) {
	T dotproduct = 0;
	for (int i = 0; i < N; i++) {
		dotproduct += v1[i] * v2[i];
	}
	return dotproduct;
}