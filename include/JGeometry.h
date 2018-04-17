#ifndef JGEOMETRY_H
#define JGEOMETRY_H

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
};

#endif // JGEOMETRY_H