#ifndef JDRAMA_H
#define JDRAMA_H

#include "J3D.h"
#include "JSUStream.h"
#include "JGeometry.h"
#include "JStage.h"

using namespace JGeometry;

namespace JDrama
{
	class TNameRefGen
	{
        public:
        void load(JSUMemoryInputStream &stream);
        u32* getNameRef(char const *) const;
        u32 getRootNameRef();
        u32* getInstance();
		
        u32* vtable; // _0
        u32 rootName; // _4
	};
	
	template <typename T>
	class TFlagT 
    {
        public:
	    TFlagT(T);
        TFlagT(const TFlagT &);
        void set(T);

        T value;
    };
	
	struct TRect
	{
		u32 x; // _0
		u32 y; // _4
		u32 h; // _8
		u32 w; // _C
	};
	
	class TGraphics
	{
		public:
		void setViewport(TRect const &, f32, f32);
		
		u8 _0[0x20];
		u8 _20;
		u8 _21[0x54-0x21];
		u32 _54;
		u32 _58;
		u32 _5C;
		u32 _60;
	};
	
	/* Size -- 0xC */
    class TNameRef
    {
        public:
        TNameRef(char const *);
        ~TNameRef();

        // note -- some of these may be static
        u32 getType() const;
		u32 getType(JSUMemoryInputStream &stream, JSUMemoryInputStream &);
		void genObject(JSUMemoryInputStream &stream, JSUMemoryInputStream &);
        void load(JSUMemoryInputStream &stream);
        void save(JSUMemoryOutputStream &stream);
        void loadAfter(void);
		void search(char const *);
        TNameRef* searchF(s16, char const *);

        static s16 calcKeyCode(char const *);

        u32* vtable; // _0
        u8* className; // _4
        s16 keyCode; // _8
        u8 _A; // padding
        u8 _B; // padding
    };

    /* Size -- 0x10 */
    class TViewObj : public TNameRef
    {
        public:
        TViewObj(char const *);
        ~TViewObj();
		
		void testPerform(u32, TGraphics *);

        TFlagT<s16> flags; // _C
        u16 _E; // _E
    };

    /* Size -- 0x20 */
    class TPlacement : public TViewObj
    {
        public:
        ~TPlacement();
		
        void load(JSUMemoryInputStream &stream);

        TVec3<f32> position; // _10
        u16 _1C;
        u16 _1E; // pad
    };
	
	/* Size -- 0x44 */
    class TActor : public TPlacement, public JStage::TActor
    {
        public:
        TActor(char const *);
        ~TActor();

        u32 getType() const;
        void load(JSUMemoryInputStream &stream);
        void perform(u32, TGraphics *);
        void JSGGetTranslation(TVec3<f32> *) const;
        void JSGSetTranslation(TVec3<f32> const &);
        void JSGGetScaling(TVec3<f32> *) const;
        void JSGSetScaling(const TVec3<f32> &);
        void JSGGetRotation(TVec3<f32> *) const;
        void JSGSetRotation(const TVec3<f32> &);

        TVec3<f32> scale; // _24
        TVec3<f32> rotation; // _30
        u32 _3C;
        u32* _40;  
    };	

    class TDirector : public TNameRef, public JStage::TSystem
    {
        public:
        ~TDirector();
        TDirector* searchF(s16, char const *);
        void direct();
        u32* JSGFindObject(char const *, u32 *) const; // JStage::TEObject
        
        u32 _C; // TSystem vtable
        u32* _10;
        u32* _14; // padding?
        u32 _18;  // ^^
        u32 _1C;  // ^^
        u32 _20;
    };

    class TCharacter : public TNameRef
    {
        public:
        ~TCharacter();
    };

    template<typename T, typename U>
    class TNameRefPtrListT : public TNameRef
    {
        public:
        ~TNameRefPtrListT();

        void load(JSUMemoryInputStream &stream);
        void loadAfter();
        //T* searchF(u16, char const *);
    };

    class TAmbColor : public TViewObj, public JStage::TAmbientLight
    {
        public:
        TAmbColor();
        ~TAmbColor();

        void load(JSUMemoryInputStream &stream);
        void perform(u32, TGraphics *);

        u32* _10;
        u8 r; // _14
        u8 g; // _15
        u8 b; // _16
        u8 a; // _17
    };

    class TDrawBufObj : public TViewObj
    {
        public:
        TDrawBufObj();
        TDrawBufObj(u32, u32, char const *);
        ~TDrawBufObj();

        void load(JSUMemoryInputStream &stream);
        void perform(u32, TGraphics *);

        J3DDrawBuffer* drawBuffer; // _10
        u32 bufferSize; // _14
        u32 _18; // init'd to 7
    };

    class TCamera : public TPlacement, public JStage::TCamera
    {
        public:
        ~TCamera();

        u32 getType() const;
        u32 JSGGetFlag() const;
        void JSGSetFlag(u32 flag);
        f32 JSGGetProjectionNear() const;
        void JSGSetProjectionNear(f32 projectionNear);
        f32 JSGGetProjectionFar() const;
        void JSGSetProjectionFar(f32 projectionFar);

        u32 _20; // this is a vtable, I think to JStage::TCamera
        u16 flag; // _24
        u16 _26; // padding?
        f32 projectionNear; // _28
        f32 projectionFar; // _2C
    };

    class TLookAtCamera : public TCamera
    {
        public:
        ~TLookAtCamera();

        void perform(u32, TGraphics *);

        u32 JSGGetProjectionType() const;
        void JSGSetProjectionType(u32); // JStage::TECameraProjection
        f32 JSGGetProjectionFovy() const;
        void JSGSetProjectionFovy(f32 projectionFovy);
        f32 JSGGetProjectionAspect() const;
        void JSGSetProjectionAspect(f32 projectionAspect);
        Vec* JSGGetViewPosition() const;
        void JSGSetViewPosition(Vec *viewPos);
        Vec* JSGGetViewUpVector() const;
        void JSGSetViewUpVector(Vec *upVector);
        Vec* JSGGetViewTargetPosition() const;
        void JSGSetViewTargetPosition(Vec *targetPos);

        TVec3<f32> viewUp; // _30
        TVec3<f32> targetPos; // _3C
        f32 projectionFovy; // _48
        f32 projectionAspect; // _4C
    };
};

#endif // JDRAMA_H