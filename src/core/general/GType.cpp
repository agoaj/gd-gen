#include "GType.h"
#include <string>

GType TypeStringToGType(const std::string& typeString)
{
    if (typeString == "float" || typeString == "double")
        return GType::Float;
    if (typeString == "int")
        return GType::Int;
    if (typeString == "bool")
        return GType::Boolean;
    if (typeString == "String")
        return GType::String;
    if (typeString == "PackedByteArray")
        return GType::PackedByteArray;
    if (typeString == "PackedInt32Array")
        return GType::PackedInt32Array;
    if (typeString == "PackedInt64Array")
        return GType::PackedInt64Array;
    if (typeString == "PackedFloat32Array")
        return GType::PackedFloat32Array;
    if (typeString == "PackedFloat64Array")
        return GType::PackedFloat64Array;
    if (typeString == "PackedStringArray")
        return GType::PackedStringArray;
    if (typeString == "PackedVector2Array")
        return GType::PackedVector2Array;
    if (typeString == "PackedVector3Array")
        return GType::PackedVector3Array;
    if (typeString == "PackedColorArray")
        return GType::PackedColorArray;
    if (typeString == "PackedVector4Array")
        return GType::PackedVector4Array;
    if(typeString == "Vector2")
        return GType::Vector2;
    if(typeString == "Vector2i")
        return GType::Vector2i;
    if(typeString == "Vector3")
        return GType::Vector3;
    if(typeString == "Vector3i") 
        return GType::Vector3i;
    if(typeString == "Vector4")
        return GType::Vector4;
    if(typeString == "Vector4i") 
        return GType::Vector4i;
    if(typeString == "Rect2") 
        return GType::Rect2;
    if(typeString == "Rect2i")
        return GType::Rect2i;
    if(typeString == "Transform2D")
        return GType::Transform2D;
    if(typeString == "Transform3D")
        return GType::Transform3D;
    if(typeString == "Plane")
        return GType::Plane;
    if(typeString == "Quaternion")
        return GType::Quaternion;
    if(typeString == "AABB")
        return GType::AABB;
    if(typeString == "Basis")
        return GType::Basis;
    if(typeString == "Projection")
        return GType::Projection;
    if (typeString == "Variant")
        return GType::Variant;
    if (typeString.starts_with("Ref<"))
        return GType::Resource;

    //Assuming object
    return GType::Object;
}