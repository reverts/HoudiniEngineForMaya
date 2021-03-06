#ifndef __OutputInstancerObject_h__
#define __OutputInstancerObject_h__

//#include <Maya/MIntArray.h>

#include "OutputObject.h"

class OutputInstancerObject: public OutputObject
{
    public:
        OutputInstancerObject(
                int assetId,
                int objectId,
                Asset* objectControl
                );
        virtual ~OutputInstancerObject();

        MIntArray getInstancedObjIds();
        MStringArray getUniqueInstObjNames();

        virtual MStatus compute(
                MDataHandle& handle,
                bool &needToSyncOutputs
                );
        virtual MStatus setClean(MPlug& plug, MDataBlock& data);

        virtual ObjectType type();

    public:

    protected:
        virtual void update();

        MStringArray getAttributeStringData(HAPI_AttributeOwner owner, MString name);

    private:
        HAPI_GeoInfo myGeoInfo;
        HAPI_PartInfo myPartInfo;

        MStringArray myInstancedObjectNames;
        MStringArray myUniqueInstObjNames;
        MIntArray myInstancedObjectIndices;

        MStringArray myHoudiniInstanceAttribute;
        MStringArray myHoudiniNameAttribute;
};

#endif
