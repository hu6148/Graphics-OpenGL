#include "SizeIs.h"

/* Implement */
SizeIs::SizeIs(): size(SIZE(0)){}
void SizeIs:: setSize(SIZE br) {
	size = br;
}
bool SizeIs:: operator()(const Sphere& sph) {
	if (size == SMALL) {
		return (sph.getRadius() < 7.0f);
	}
	else if (size == MEDIUM) {
		return ((sph.getRadius() >= 7.0f) && (sph.getRadius() <= 12.0f));
	}
	else if (size == LARGE) {
		return (sph.getRadius() > 12.0f);
	}
}