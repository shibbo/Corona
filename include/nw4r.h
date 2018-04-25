#ifndef __KAMEK_NW4R_H
#define __KAMEK_NW4R_H

#include "kamek.h"

namespace nw4r 
{
	namespace math 
	{
		namespace detail 
		{
			f32 FExp(f32);
			f32 FLog(f32);
		}

		inline f32 FExp(f32 value) { return detail::FExp(value); }
		inline f32 FLog(f32 value) { return (value > 0.0f) ? detail::FLog(value) : NAN; }
		f32 FrSqrt(f32);

		// TODO: inline Idx (rather than FIdx) versions of Sin, Cos, SinCos
		f32 SinFIdx(f32 fidx);
		f32 CosFIdx(f32 fidx);
		void SinCosFIdx(f32 *pSin, f32 *pCos, f32 fidx);
		f32 Atan2FIdx(f32 y, f32 x);
		u16 Atan2Idx(f32 y, f32 x);


		struct VEC2 : public Vec2 { };
		struct VEC3 : public Vec {
			void Report(bool addNewLine, const u8 *prefixText = 0);
		};

		struct MTX33 { f32 data[3][3]; };
		struct MTX34 { f32 data[3][4]; };
		struct MTX44 { f32 data[4][4]; };

		void MTX33Identity(MTX33 *mtx);
		void MTX34ToMTX33(MTX33 *dest, const MTX34 *source);
		void MTX34Zero(MTX34 *mtx);
		void MTX34Add(MTX34 *dest, const MTX34 *sourceA, const MTX34 *sourceB);
		void MTX34Scale(MTX34 *dest, const MTX34 *sourceMatrix, const VEC3 *sourceVector);
		void MTX34Trans(MTX34 *dest, const MTX34 *sourceMatrix, const VEC3 *sourceVector);
		void MTX34RotAxisFIdx(MTX34 *dest, const VEC3 *vector, f32 fidx);
		void MTX34RotXYZFIdx(MTX34 *dest, f32 x, f32 y, f32 z);
		void VEC3TransformNormal(VEC3 *dest, const MTX34 *sourceMatrix, const VEC3 *sourceVector);
		void MTX44Identity(MTX44 *mtx);
		void MTX44Copy(MTX44 *dest, const MTX44 *source);
		
		struct PLANE {
			VEC3 vector;
			f32 constant;

			void Set(const VEC3 *a, const VEC3 *b, const VEC3 *c);
		};

		struct AABB {
			VEC3 minPoint, maxPoint;

			void Set(const VEC3 *pointArray, u32 pointCount);
			void Set(const AABB *otherAABB, const MTX34 *matrix);
		};

		struct FRUSTUM {
			MTX34 matrix;
			PLANE left, right, top, bottom;
			f32 near, far;
			AABB aabb;
			PLANE planes[6];

			void Set(f32 fovy, f32 aspect, f32 near, f32 far, const MTX34 &matrix);
			void Set(f32 top, f32 bottom, f32 left, f32 right, f32 near, f32 far, const MTX34 &matrix);
			u32 IntersectAABB_Ex(const AABB *otherAabb);
		};

		struct SEGMENT3 { VEC3 a, b; };
		struct LINE3 { VEC3 point, direction; };
		struct SPHERE { VEC3 point; f32 radius; };

		f32 DistSqSegment3ToSegment3(const SEGMENT3 *a, const SEGMENT3 *b, f32 *pOut1, f32 *pOut2);
		u32 IntersectionLine3Sphere(const LINE3 *a, const SPHERE *b, f32 *pOut1, f32 *pOut2);
		u32 IntersectionSegment3Sphere(const SEGMENT3 *a, const SPHERE *b, f32 *pOut1, f32 *pOut2);
		bool IntersectionAABB(const AABB *a, const AABB *b);
	}
}

#endif
