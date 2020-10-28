#pragma once

#include <d3d9.h>
#include <unordered_set>
#include <array>
#include <memory>

#include "..\structs.h"

#define CUSTOMFVF (D3DFVF_XYZRHW | D3DFVF_DIFFUSE | D3DFVF_TEX1)

namespace mgui
{


	class Renderer
	{
	private:

		typedef struct _DX9Vertex
		{
			float x, y, z, rhw;
			D3DCOLOR color;
			float tu, tv;
		} DX9Vertex;

	public:

		Renderer(LPDIRECT3DDEVICE9 device);

		~Renderer();

	public:

		void render(DrawData* data);

		void release();

		bool updateFontMap(); // TODO: Pass in buffer that contains font map

	private:

		LPDIRECT3DDEVICE9 device;
		LPDIRECT3DVERTEXBUFFER9 vBuffer;
		LPDIRECT3DTEXTURE9 fontMap;
		size_t vertexBufferSize;
	};




}