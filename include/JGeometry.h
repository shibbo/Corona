#ifndef JGEOMETRY_H
#define JGEOMETRY_H

#include "types.h"

/* This actually isn't a part of JGeometry, but shrug */
struct Vec
{
	f32 x;
	f32 y;
	f32 z;
};

namespace JGeometry
{
	template <typename T>
	class TVec2
	{
		public:
		TVec2();

		T dot(const TVec2<T> &) const;
		void sub(const TVec2<T> &);

		T x; // _0
		T y; // _4
	};

    template <typename T>
	class TVec3 {
		public:

		TVec3();
		TVec3(const TVec3<T> &);
		void set(T, T, T);
		void set(const TVec3<T> &);
		void div(T);
		T dot(const TVec3<T> &) const;
		void add(const TVec3<T> &);
		void sub(const TVec3<T> &);
		void sub(const TVec3<T> &, const TVec3<T> &);
		void scale(T);
		void scale(T, const TVec3<T> &);
		void setMin(const TVec3<T> &);
		void setMax(const TVec3<T> &);
		void scaleAdd(T, const TVec3<T> &, const TVec3<T> &);
		void negate();
		void setLength(const TVec3<T> &, T);
		TVec3<T> operator=(const TVec3<T> &);
		TVec3<T> operator-=(const TVec3<T> &);
		TVec3<T> operator*=(const TVec3<T> &);

		T x; // _0
		T y; // _4
		T z; // _8
    };

	template <typename T>
	class TVec4
	{
		public:
		TVec4(TVec4<T> const &);
		void xyz(); // nullsub
		void scale(T, TVec4<T> const &);
		T dot(TVec4<T> const &) const;
		void set(T, T, T, T);

		T _0;
		T _4;
		T _8;
		T _C;
	};

	template <typename T>
	class TQuat4
	{
		public:
		void setRotate(TVec3<T> const &, TVec3<T> const &, T);
		void slerp(TQuat4<T> const &, T);
		void rotate(TVec3<T> const &, TVec3<T> const &) const;

		T _0;
		T _4;
		T _8;
		T _C;
	};
	
	template <typename T>
	class TRotation3
	{
		public:
		TRotation3();

		void getQuad(TQuat4<f32> &) const;
		void setEular(s16, s16, s16);
	};

	template <typename T>
	class SMatrix34C
	{
		public:
		SMatrix34C(); // nullsub

		void set(T, T, T, T, T, T, T, T, T, T, T, T);

		T _0;
		T _4;
		T _8;
		T _C;
		T _10;
		T _14;
		T _18;
		T _1C;
		T _20;
		T _24;
		T _28;
		T _2C;
	};

	// are these class useless?
	template <typename T>
	class TMatrix34
	{
		public:
		TMatrix34(); // nullsub
	};

	template <typename T>
	class TMatrix44
	{
		public:
		TMatrix44(); // nullsub
	};

	template <typename T>
	class TPartition3
	{
		public:
		TPartition3(); // nullsub
	};

	// notice: this class only supports floats in Sunshine
	// so if any other type is used that is not float, the symbol will be generated
	template <typename T>
	class TUtil
	{
		public:
		T sqrt(T val);
		T inv_sqrt(T val);
		T mod(T, T);
		T one();
	};
};

#endif // JGEOMETRY_H