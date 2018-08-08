#ifndef JSTAGE_H
#define JSTAGE_H

#include "JGeometry.h"
#include "types.h"

namespace JStage
{
    class TObject
    {
        public:
        virtual ~TObject();

        virtual u32 JSGGetName() const;
        virtual u32 JSGGetFlag() const;
        virtual void JSGSetFlag(u32);
        virtual u32 JSGGetData(u32 const, void *, u32);
        virtual void JSGSetData(u32, void const *, u32);
        virtual void JSGGetParent(TObject **const, u32 *);
        virtual void JSGSetParent(TObject *, u32);
        virtual void JSGSetRelation(bool, TObject *, u32);

        VTABLE; // _0
    };

    class TSystem : public TObject
    {
        public:
        virtual ~TSystem();
        
        virtual u32 JSGFGetType() const;
        virtual u32 JSGGetSystemData(u32);
        virtual void JSGSetSystemData(u32, u32);
        virtual void JSGDestroyObject(TObject *);
    };

    class TActor : public TObject
    {
        public:
        virtual ~TActor();

        virtual u32 JSGFGetType() const;
        virtual void JSGGetTranslation(JGeometry::TVec3<f32> *) const;
        virtual void JSGSetTranslation(JGeometry::TVec3<f32> const &);
        virtual void JSGGetScaling(JGeometry::TVec3<f32> *) const;
        virtual void JSGSetScaling(const JGeometry::TVec3<f32> &);
        virtual void JSGGetRotation(JGeometry::TVec3<f32> *) const;
        virtual void JSGSetRotation(const JGeometry::TVec3<f32> &);

        virtual u32 JSGGetShape() const;
        virtual void JSGSetShape(u32);
        virtual u32 JSGGetAnimation() const;
        virtual void JSGSetAnimation(u32);
        virtual f32 JSGGetAnimationFrame() const;
        virtual void JSGSetAnimationFrame(f32);
        virtual f32 JSGGetAnimationFrameMax() const;
    };

    class TCamera : public TObject
    {
        public:
        virtual ~TCamera();

        virtual u32 JSGFGetType() const;
        virtual u32 JSGGetProjectionType() const;
        virtual void JSGSetProjectionType(u32); // JStage::TECameraProjection
        virtual f32 JSGGetProjectionNear() const;
        virtual void JSGSetProjectionNear(f32);
        virtual f32 JSGGetProjectionFar();
        virtual void JSGSetProjectionFar(f32);
        virtual f32 JSGGetProjectionFovy() const;
        virtual void JSGSetProjectionFovy(f32);
        virtual f32 JSGGetProjectionAspect() const;
        virtual void JSGSetProjectionAspect(f32);
        virtual f32* JSGGetProjectionField() const;
        virtual void JSGSetProjectionField(f32 const *);
        virtual u32 JSGGetViewType() const;
        virtual void JSGSetViewType(u32); // JStage::TECameraView
        
    };

    class TAmbientLight : public TObject
    {
        public:
        virtual ~TAmbientLight();

        virtual u32 JSGFGetType() const;
    };
};

#endif // JSTAGE_H