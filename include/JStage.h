#ifndef JSTAGE_H
#define JSTAGE_H

#include "JGeometry.h"

using namespace JGeometry;

namespace JStage
{
    class TObject
    {
        public:
        ~TObject();

        int JSGGetName() const;
        int JSGGetFlag() const;
        void JSGSetFlag(unsigned long);
        int JSGGetData(unsigned long const, void *, unsigned long);
        void JSGSetData(unsigned long, void const *, unsigned long);
        void JSGGetParent(TObject **const, unsigned long *);
        void JSGSetParent(TObject *, unsigned long);
        void JSGSetRelation(bool, TObject *, unsigned long);

        int* vtable; // _0
    };

    class TSystem : public TObject
    {
        public:
        ~TSystem();
        
        int JSGFGetType() const;
        int JSGGetSystemData(unsigned long);
        void JSGSetSystemData(unsigned long, unsigned long);
        void JSGDestroyObject(TObject *);
    };

    class TActor : public TObject
    {
        public:
        ~TActor();
        int JSGFGetType() const;
        void JSGGetTranslation(TVec3<float> *) const;
        void JSGSetTranslation(TVec3<float> const &);
        void JSGGetScaling(TVec3<float> *) const;
        void JSGSetScaling(const TVec3<float> &);
        void JSGGetRotation(TVec3<float> *) const;
        void JSGSetRotation(const TVec3<float> &);

        int JSGGetShape() const;
        void JSGSetShape(unsigned long);
        int JSGGetAnimation() const;
        void JSGSetAnimation(unsigned long);
        float JSGGetAnimationFrame() const;
        void JSGSetAnimationFrame(float);
        float JSGGetAnimationFrameMax() const;
    };
};

#endif // JSTAGE_H