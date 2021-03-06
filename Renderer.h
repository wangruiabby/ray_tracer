#ifndef RENDERER_H
#define RENDERER_H

#include "Color.h"
#include "Ray.h"
#include <vector>
#include "Primitive.h"
#include "PointLight.h"
//#include "mesh.h"
//#include "cube_map.h"

using namespace std;

class Renderer
{
public:
	Renderer();
	Renderer(const uint16_t depth);

	Color RenderRay(
		const Ray&,
		const vector< shared_ptr<const Primitive> > &,
		const vector< shared_ptr<const Light> > &,
		bool globalLighting = false) const;


	//Color RenderRayEnv(
	//	const Ray&,
	//	const vector< shared_ptr<Mesh> > &,
	//	const unique_ptr<CubeMap> &
	//	);

	void SetDepth(const uint16_t depth);
	uint16_t GetDepth(void) const;

private:
	Color RenderRay(
		const Ray &,
		const vector< shared_ptr<const Primitive> > &,
		const vector< shared_ptr<const Light> > &,
		uint16_t depth,
		bool globalLight = false) const;


	uint16_t depth;
};


#endif