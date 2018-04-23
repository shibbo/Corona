#ifndef JDRAMA_H
#define JDRAMA_H

#include "JSUStream.h"
#include "JGeometry.h"
#include "JStage.h"

using namespace JGeometry;

namespace JDrama
{
	class TNameRefGen
	{
		public:
		void load(JSUMemoryInputStream &);
		int* getNameRef(char const *) const;
		int getRootNameRef();
		int* getInstance();
		
		int* vtable; // _0
		int rootName; // _4
	};
	
	template <typename T>
	class TFlagT {
        public:
		TFlagT(T);
        TFlagT(const TFlagT &);
        void set(T);

        T value;
    };
	
	struct TRect
	{
		int x; // _0
		int y; // _4
		int h; // _8
		int w; // _C
	};
	
	class TGraphics
	{
		public:
		void setViewport(TRect const &, float, float);
		
		char _0[0x20];
		char _20;
		char _21[0x54-0x21];
		int _54;
		int _58;
		int _5C;
		int _60;
	};
	
	/* Size -- 0xC */
    class TNameRef
    {
        public:
        TNameRef(char const *);
        ~TNameRef();

        // note -- some of these may be static
        int getType() const;
		int getType(JSUMemoryInputStream &, JSUMemoryInputStream &);
		void genObject(JSUMemoryInputStream &, JSUMemoryInputStream &);
        void load(JSUMemoryInputStream &);
        void save(JSUMemoryOutputStream &);
        void loadAfter(void);
		void search(char const *);
        TNameRef* searchF(unsigned short, char const *);

        static unsigned short calcKeyCode(char const *);

        int* vtable; // _0
        char* className; // _4
        unsigned short keyCode; // _8
        char _A; // padding
        char _B; // padding
    };

    /* Size -- 0x10 */
    class TViewObj : public TNameRef
    {
        public:
        TViewObj(char const *);
        ~TViewObj();
		
		void testPerform(unsigned long, TGraphics*);

        TFlagT<unsigned short> flags; // _C
        short _E; // _E
    };

    /* Size -- 0x20 */
    class TPlacement : public TViewObj
    {
        public:
        ~TPlacement();
		
        void load(JSUMemoryInputStream &);

        TVec3<float> position; // _10
        short _1C;
        short _1E; // pad
    };
	
	/* Size -- 0x44 */
    class TActor : public TPlacement, public JStage::TActor
    {
        public:
        TActor(char const *);
        ~TActor();

        int getType() const;
        void load(JSUMemoryInputStream &);
        void perform(unsigned long, TGraphics *);
        void JSGGetTranslation(TVec3<float> *) const;
        void JSGSetTranslation(TVec3<float> const &);
        void JSGGetScaling(TVec3<float> *) const;
        void JSGSetScaling(const TVec3<float> &);
        void JSGGetRotation(TVec3<float> *) const;
        void JSGSetRotation(const TVec3<float> &);

        TVec3<float> scale; // _24
        TVec3<float> rotation; // _30
        int _3C;
        int* _40;  
    };	

    class TDirector : public TNameRef, public JStage::TSystem
    {
        public:
        ~TDirector();
        TDirector* searchF(unsigned short, char const *);
        void direct();
        int* JSGFindObject(char const *, int *) const; // JStage::TEObject
        
        int _C; // TSystem vtable
        int* _10;
        int* _14; // padding?
        int _18;  // ^^
        int _1C;  // ^^
        int _20;
    };

    class TCharacter : public TNameRef
    {
        public:
        ~TCharacter();
    };

    class TAmbColor : public TViewObj
    {
        public:
        TAmbColor();
        ~TAmbColor();

        void load(JSUMemoryInputStream &);
        void perform(unsigned long, TGraphics *);

        int* _10;
        char r; // _14
        char g; // _15
        char b; // _16
        char a; // _17
    };
};

#endif // JDRAMA_H