#ifndef JDRAMA_H
#define JDRAMA_H

#include "GX.h"
#include "J3D.h"
#include "JSUStream.h"
#include "JGeometry.h"
#include "JStage.h"

namespace JDrama
{
	class TNameRefGen
	{
        public:
        virtual void load(JSUMemoryInputStream &stream);
        virtual u32* getNameRef(char const *) const;
        
        u32 getRootNameRef();
        u32* getInstance();
		
        VTABLE; // _0
        u32 mRootName; // _4
	};
	
	template <typename T>
	class TFlagT 
    {
        public:
	    TFlagT(T);
        TFlagT(const TFlagT &);
        void set(T);

        T mValue;
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
        virtual ~TNameRef();

        // note -- some of these may be static
        virtual u32 getType() const;
        virtual void load(JSUMemoryInputStream &stream);
        virtual void save(JSUMemoryOutputStream &stream);
        virtual void loadAfter(void);
		virtual void search(char const *);
        virtual TNameRef* searchF(s16, char const *);

        void genObject(JSUMemoryInputStream &stream, JSUMemoryInputStream &);
        u32 getType(JSUMemoryInputStream &stream, JSUMemoryInputStream &);
        static s16 calcKeyCode(char const *);

        VTABLE; // _0
        u8* mClassName; // _4
        s16 mKeyCode; // _8
        u8 _A; // padding
        u8 _B; // padding
    };

    /* Size -- 0x10 */
    class TViewObj : public TNameRef
    {
        public:
        TViewObj(char const *);
        virtual ~TViewObj();
		
		void testPerform(u32, TGraphics *);

        TFlagT<s16> mFlags; // _C
        u16 _E; // _E
    };

    /* Size -- 0x20 */
    class TPlacement : public TViewObj
    {
        public:
        virtual ~TPlacement();
		
        virtual void load(JSUMemoryInputStream &stream);

        JGeometry::TVec3<f32> mPosition; // _10
        u16 _1C;
        u16 _1E; // pad
    };
	
	/* Size -- 0x44 */
    class TActor : public TPlacement, public JStage::TActor
    {
        public:
        TActor(char const *);
        virtual ~TActor();

        virtual u32 getType() const;
        virtual void load(JSUMemoryInputStream &stream);
        virtual void perform(u32, TGraphics *);
        virtual void JSGGetTranslation(JGeometry::TVec3<f32> *) const;
        virtual void JSGSetTranslation(JGeometry::TVec3<f32> const &);
        virtual void JSGGetScaling(JGeometry::TVec3<f32> *) const;
        virtual void JSGSetScaling(const JGeometry::TVec3<f32> &);
        virtual void JSGGetRotation(JGeometry::TVec3<f32> *) const;
        virtual void JSGSetRotation(const JGeometry::TVec3<f32> &);

        JGeometry::TVec3<f32> mScale; // _24
        JGeometry::TVec3<f32> mRotation; // _30
        u32 _3C;
        u32* _40;  
    };	

    class TDirector : public TNameRef, public JStage::TSystem
    {
        public:
        virtual ~TDirector();

        virtual TDirector* searchF(s16, char const *);
        virtual u32* JSGFindObject(char const *, u32 *) const; // JStage::TEObject
        virtual s32 direct();
        
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
        virtual ~TCharacter();
    };

    template<typename T, typename U>
    class TNameRefPtrListT : public TNameRef
    {
        public:
        virtual ~TNameRefPtrListT();

        virtual void load(JSUMemoryInputStream &stream);
        virtual void loadAfter();
        //T* searchF(u16, char const *);
    };

    class TAmbColor : public TViewObj, public JStage::TAmbientLight
    {
        public:
        TAmbColor();
        virtual ~TAmbColor();

        virtual void load(JSUMemoryInputStream &stream);
        virtual void perform(u32, TGraphics *);

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
        virtual ~TDrawBufObj();

        virtual void load(JSUMemoryInputStream &stream);
        virtual void perform(u32, TGraphics *);

        J3DDrawBuffer* mDrawBuffer; // _10
        u32 mBufferSize; // _14
        u32 _18; // init'd to 7
    };

    class TCamera : public TPlacement, public JStage::TCamera
    {
        public:
        virtual ~TCamera();

        virtual u32 getType() const;
        virtual u32 JSGGetFlag() const;
        virtual void JSGSetFlag(u32 flag);
        virtual f32 JSGGetProjectionNear() const;
        virtual void JSGSetProjectionNear(f32 projectionNear);
        virtual f32 JSGGetProjectionFar() const;
        virtual void JSGSetProjectionFar(f32 projectionFar);

        u32 _20; // this is a vtable, I think to JStage::TCamera
        u16 mFlag; // _24
        u16 _26; // padding?
        f32 mProjectionNear; // _28
        f32 mProjectionFar; // _2C
    };

    class TLookAtCamera : public TCamera
    {
        public:
        virtual ~TLookAtCamera();

        virtual void perform(u32, TGraphics *);

        virtual u32 JSGGetProjectionType() const;
        virtual void JSGSetProjectionType(u32); // JStage::TECameraProjection
        virtual f32 JSGGetProjectionFovy() const;
        virtual void JSGSetProjectionFovy(f32 projectionFovy);
        virtual f32 JSGGetProjectionAspect() const;
        virtual void JSGSetProjectionAspect(f32 projectionAspect);
        virtual Vec* JSGGetViewPosition() const;
        virtual void JSGSetViewPosition(Vec *viewPos);
        virtual Vec* JSGGetViewUpVector() const;
        virtual void JSGSetViewUpVector(Vec *upVector);
        virtual Vec* JSGGetViewTargetPosition() const;
        virtual void JSGSetViewTargetPosition(Vec *targetPos);

        JGeometry::TVec3<f32> mViewUp; // _30
        JGeometry::TVec3<f32> mTargetPos; // _3C
        f32 mProjectionFovy; // _48
        f32 mProjectionAspect; // _4C
    };

    class TDisplay
    {
        public:
        TDisplay(u16, void *, void *, _GXRenderModeObj const &);

        void startRendering();
        void endRendering();
    };

    class TVideo
    {
        public:
        TVideo();
    };

    void CalcRenderModeXFBHeight(_GXRenderModeObj *, u16);
    void CalcRenderModeVIXOrigin(_GXRenderModeObj *);
    void CalcRenderModeVIYOrigin(_GXRenderModeObj *);
    void CopyRenderModeSamplePattern(_GXRenderModeObj *, u8 const *[2]);
    void CopyRenderModeVFilter(_GXRenderModeObj *, u8 const *);
};

#endif // JDRAMA_H