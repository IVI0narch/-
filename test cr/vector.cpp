struct vect sum(struct vect a, struct vect b) {
	vect v3;
	v3.x = a.x + b.x;
	v3.y = a.y + b.y;
	v3.z = a.z + b.z;
	return v3;
}
