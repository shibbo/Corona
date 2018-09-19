#ifndef JDRAMA_H
#define JDRAMA_H

#include "J3D.h"
#include "JSUStream.h"
#include "JGeometry.h"
#include "JKR.h"
#include "JStage.h"
#include "camera/TCamConnector.h"
#include "dolphin/GX.h"

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

    class TNameRef
    {
        public:
        TNameRef(char const *);
        virtual ~TNameRef();

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
        u8 _B; // ^^
    };

    class TViewObj : public TNameRef
    {
        public:
        TViewObj(char const *);
        virtual ~TViewObj();
		
		void testPerform(u32, TGraphics *);

        TFlagT<s16> mFlags; // _C
        u16 _E; // _E
    };

    class TPlacement : public TViewObj
    {
        public:
        // has a constructor, but inlined
        virtual ~TPlacement();
		
        virtual void load(JSUMemoryInputStream &stream);

        JGeometry::TVec3<f32> mPosition; // _10
        TFlagT<u16> mUnusedFlags; // _1C (unused)
        u16 _1E; // pad
    };

    class TLightMap : public TViewObj
    {
        public:

        class TLightInfo
        {
            public:
            TLightInfo();

            u32 _0;
            u32 _4;
        }

        virtual ~TLightMap();

        virtual void load(JSUMemoryInputStream &stream);
        virtual void perform(u32, TGraphics *);
    
        s32 mLightArryCount; // _10
        TLightMap::TLightInfo* mLightInfoArry; // _14
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
        u32* mCharacter; // _3C
        TLightMap* mLightMap;  // _40
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

    class TPolarCamera : public TCamera
    {
        public:
        virtual ~TPolarCamera();

        virtual void perform(u32, TGraphics *);
        virtual void load(JSUMemoryInputStream &stream);

        virtual s32 JSGGetProjectionType() const;
        virtual void JSGSetProjectionType(s32 projection);
        virtual f32 JSGGetProjectionFovy() const;
        virtual void JSGSetProjectionFovy(f32 projectionFovy);
        virtual f32 JSGGetProjectionAspect() const;
        virtual void JSGSetProjectionAspect(f32 projectionAspect);

        f32 mProjectionFovy; // _30
        f32 mProjectionAspect; // _34
    };

    class TOrthoProj : public TCamera
    {
        public:
        virtual ~TOrthoProj();

        virtual void load(JSUMemoryInputStream &stream);
        virtual void perform(u32, TGraphics *);

        virtual s32 JSGGetProjectionType() const;
        virtual void JSGSetProjectionType(s32 projection);
        virtual f32* JSGGetProjectionField() const;
        virtual void JSGSetProjectionField(const f32 *projectionField);

        JGeometry::TVec4<f32> mProjectionField; // _30
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

        void setNextXFB(void const *);
        void waitForRetrace(u16);

        _GXRenderModeObj _0;
        _GXRenderModeObj _3C;
        u32 _78;
        void* mNextFB; // _7C
        s32 mTicks; // _80
        s32 mRetraceCount; // _84
    };

    class TViewConnector : public TViewObj
    {
        public:
        TViewConnector(TViewObj *viewObj1, TViewObj *viewObj2, TFlagT<u16> flags, char const *objName);
        virtual ~TViewConnector();

        virtual void perform(u32, TGraphics *);

        TViewObj* mViewObj1; // _10
        TViewObj* mViewObj2; // _14
        u16 mFlag; // _18
        u16 _1A; // padding
    };

    class TViewport : public TViewObj
    {
        public:
        TViewport(TRect const &, char const *);
        virtual ~TViewport();

        virtual void load(JSUMemoryInputStream &stream);
        virtual void perform(u32, TGraphics *);

        TRect mViewportRect; // _10
        u16 _20;
        u16 _22; // padding
    };

    class TScreen : public TViewConnector
    {
        public:
        TScreen(TRect const &, char const *);
        virtual ~TScreen();

        void assignCamera(TViewObj *);
        void assignViewObj(TViewObj *);

        TViewport* mViewport; // _10
        TCamConnector* mCamConnecter; // _14
    };

    class TSmplChara : public TCharacter
    {
        public:
        virtual ~TSmplChara();

        virtual void load(JSUMemoryInputStream &stream);
        virtual u32* getRes(char const *resName);
        
        void mountArc(char const *resName);

        JKRArchive* mArchive; // _C
    };

    bool IsEqualRenderModeVIParams(_GXRenderModeObj const &, _GXRenderModeObj const &);
    bool IsRenderModeHalfAspectRatio(_GXRenderModeObj const &);
    f32 GetRenderModeYScale(_GXRenderModeObj const &);
    void CalcRenderModeXFBHeight(_GXRenderModeObj *, u16);
    void CalcRenderModeVIXOrigin(_GXRenderModeObj *);
    void CalcRenderModeVIYOrigin(_GXRenderModeObj *);
    void CopyRenderModeSamplePattern(_GXRenderModeObj *, u8 const *[2]);
    void CopyRenderModeVFilter(_GXRenderModeObj *, u8 const *);

    s32 GetVIWidthMax();
    s32 GetVIHeightMax();
};

#endif // JDRAMA_H