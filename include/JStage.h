#ifndef JSTAGE_H
#define JSTAGE_H

#include "JGeometry.h"
#include "types.h"

using namespace JGeometry;

namespace JStage
{
    class TObject
    {
        public:
        ~TObject();

        u32 JSGGetName() const;
        u32 JSGGetFlag() const;
        void JSGSetFlag(u32);
        u32 JSGGetData(u32 const, void *, u32);
        void JSGSetData(u32, void const *, u32);
        void JSGGetParent(TObject **const, u32 *);
        void JSGSetParent(TObject *, u32);
        void JSGSetRelation(bool, TObject *, u32);

        VTABLE; // _0
    };

    class TSystem : public TObject
    {
        public:
        ~TSystem();
        
        u32 JSGFGetType() const;
        u32 JSGGetSystemData(u32);
        void JSGSetSystemData(u32, u32);
        void JSGDestroyObject(TObject *);
    };

    class TActor : public TObject
    {
        public:
        ~TActor();
        u32 JSGFGetType() const;
        void JSGGetTranslation(TVec3<f32> *) const;
        void JSGSetTranslation(TVec3<f32> const &);
        void JSGGetScaling(TVec3<f32> *) const;
        void JSGSetScaling(const TVec3<f32> &);
        void JSGGetRotation(TVec3<f32> *) const;
        void JSGSetRotation(const TVec3<f32> &);

        u32 JSGGetShape() const;
        void JSGSetShape(u32);
        u32 JSGGetAnimation() const;
        void JSGSetAnimation(u32);
        f32 JSGGetAnimationFrame() const;
        void JSGSetAnimationFrame(f32);
        f32 JSGGetAnimationFrameMax() const;
    };

    class TCamera : public TObject
    {
        public:
        ~TCamera();

        u32 JSGFGetType() const;
        u32 JSGGetProjectionType() const;
        void JSGSetProjectionType(u32); // JStage::TECameraProjection
        f32 JSGGetProjectionNear() const;
        void JSGSetProjectionNear(f32);
        f32 JSGGetProjectionFar();
        void JSGSetProjectionFar(f32);
        f32 JSGGetProjectionFovy() const;
        void JSGSetProjectionFovy(f32);
        f32 JSGGetProjectionAspect() const;
        void JSGSetProjectionAspect(f32);
        f32* JSGGetProjectionField() const;
        void JSGSetProjectionField(f32 const *);
        u32 JSGGetViewType() const;
        void JSGSetViewType(u32); // JStage::TECameraView
        
    };

    class TAmbientLight : public TObject
    {
        public:
        ~TAmbientLight();

        u32 JSGFGetType() const;
    };
};

#endif // JSTAGE_H