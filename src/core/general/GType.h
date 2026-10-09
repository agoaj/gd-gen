#pragma once
#include <string>

enum class GType
{
    Invalid = 0,
    Float = 1,
    Int = 2,
    Node = 3,
    Resource = 4,
    NodePathToRaw = 5,
    Object = 6,
    Boolean = 7,
    PackedByteArray = 8,
    PackedInt32Array,
    PackedInt64Array,
    PackedFloat32Array,
    PackedFloat64Array,
    PackedStringArray,
    PackedVector2Array,
    PackedVector3Array,
    PackedColorArray,
    PackedVector4Array,
    Vector2,
    Vector2i,
    Rect2,
    Rect2i,
    Vector3,
    Vector3i,
    Transform2D,
    Vector4,
    Vector4i,
    Plane,
    Quaternion,
    AABB,
    Basis,
    Transform3D,
    Projection,
    String,
    Variant,
    Enum
};

GType TypeStringToGType(const std::string& typeString);