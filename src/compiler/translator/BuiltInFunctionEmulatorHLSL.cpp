//
// Copyright (c) 2014 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//

#include "angle_gl.h"
#include "compiler/translator/BuiltInFunctionEmulatorHLSL.h"
#include "compiler/translator/SymbolTable.h"

BuiltInFunctionEmulatorHLSL::BuiltInFunctionEmulatorHLSL()
    : BuiltInFunctionEmulator()
{
    TType float1(EbtFloat);
    TType float2(EbtFloat, 2);
    TType float3(EbtFloat, 3);
    TType float4(EbtFloat, 4);

    AddEmulatedFunction(EOpMod, float1, float1,
        "float webgl_mod_emu(float x, float y)\n"
        "{\n"
        "    return x - y * floor(x / y);\n"
        "}\n"
        "\n");
    AddEmulatedFunction(EOpMod, float2, float2,
        "float2 webgl_mod_emu(float2 x, float2 y)\n"
        "{\n"
        "    return x - y * floor(x / y);\n"
        "}\n"
        "\n");
    AddEmulatedFunction(EOpMod, float2, float1,
        "float2 webgl_mod_emu(float2 x, float y)\n"
        "{\n"
        "    return x - y * floor(x / y);\n"
        "}\n"
        "\n");
    AddEmulatedFunction(EOpMod, float3, float3,
        "float3 webgl_mod_emu(float3 x, float3 y)\n"
        "{\n"
        "    return x - y * floor(x / y);\n"
        "}\n"
        "\n");
    AddEmulatedFunction(EOpMod, float3, float1,
        "float3 webgl_mod_emu(float3 x, float y)\n"
        "{\n"
        "    return x - y * floor(x / y);\n"
        "}\n"
        "\n");
    AddEmulatedFunction(EOpMod, float4, float4,
        "float4 webgl_mod_emu(float4 x, float4 y)\n"
        "{\n"
        "    return x - y * floor(x / y);\n"
        "}\n"
        "\n");
    AddEmulatedFunction(EOpMod, float4, float1,
        "float4 webgl_mod_emu(float4 x, float y)\n"
        "{\n"
        "    return x - y * floor(x / y);\n"
        "}\n"
        "\n");

    AddEmulatedFunction(EOpFaceForward, float1, float1, float1,
        "float webgl_faceforward_emu(float N, float I, float Nref)\n"
        "{\n"
        "    if(dot(Nref, I) >= 0)\n"
        "    {\n"
        "        return -N;\n"
        "    }\n"
        "    else\n"
        "    {\n"
        "        return N;\n"
        "    }\n"
        "}\n"
        "\n");
    AddEmulatedFunction(EOpFaceForward, float2, float2, float2,
        "float2 webgl_faceforward_emu(float2 N, float2 I, float2 Nref)\n"
        "{\n"
        "    if(dot(Nref, I) >= 0)\n"
        "    {\n"
        "        return -N;\n"
        "    }\n"
        "    else\n"
        "    {\n"
        "        return N;\n"
        "    }\n"
        "}\n"
        "\n");
    AddEmulatedFunction(EOpFaceForward, float3, float3, float3,
        "float3 webgl_faceforward_emu(float3 N, float3 I, float3 Nref)\n"
        "{\n"
        "    if(dot(Nref, I) >= 0)\n"
        "    {\n"
        "        return -N;\n"
        "    }\n"
        "    else\n"
        "    {\n"
        "        return N;\n"
        "    }\n"
        "}\n"
        "\n");
    AddEmulatedFunction(EOpFaceForward, float4, float4, float4,
        "float4 webgl_faceforward_emu(float4 N, float4 I, float4 Nref)\n"
        "{\n"
        "    if(dot(Nref, I) >= 0)\n"
        "    {\n"
        "        return -N;\n"
        "    }\n"
        "    else\n"
        "    {\n"
        "        return N;\n"
        "    }\n"
        "}\n"
        "\n");

    AddEmulatedFunction(EOpAtan, float1, float1,
        "float webgl_atan_emu(float y, float x)\n"
        "{\n"
        "    if(x == 0 && y == 0) x = 1;\n"   // Avoid producing a NaN
        "    return atan2(y, x);\n"
        "}\n");
    AddEmulatedFunction(EOpAtan, float2, float2,
        "float2 webgl_atan_emu(float2 y, float2 x)\n"
        "{\n"
        "    if(x[0] == 0 && y[0] == 0) x[0] = 1;\n"
        "    if(x[1] == 0 && y[1] == 0) x[1] = 1;\n"
        "    return float2(atan2(y[0], x[0]), atan2(y[1], x[1]));\n"
        "}\n");
    AddEmulatedFunction(EOpAtan, float3, float3,
        "float3 webgl_atan_emu(float3 y, float3 x)\n"
        "{\n"
        "    if(x[0] == 0 && y[0] == 0) x[0] = 1;\n"
        "    if(x[1] == 0 && y[1] == 0) x[1] = 1;\n"
        "    if(x[2] == 0 && y[2] == 0) x[2] = 1;\n"
        "    return float3(atan2(y[0], x[0]), atan2(y[1], x[1]), atan2(y[2], x[2]));\n"
        "}\n");
    AddEmulatedFunction(EOpAtan, float4, float4,
        "float4 webgl_atan_emu(float4 y, float4 x)\n"
        "{\n"
        "    if(x[0] == 0 && y[0] == 0) x[0] = 1;\n"
        "    if(x[1] == 0 && y[1] == 0) x[1] = 1;\n"
        "    if(x[2] == 0 && y[2] == 0) x[2] = 1;\n"
        "    if(x[3] == 0 && y[3] == 0) x[3] = 1;\n"
        "    return float4(atan2(y[0], x[0]), atan2(y[1], x[1]), atan2(y[2], x[2]), atan2(y[3], x[3]));\n"
        "}\n");

    AddEmulatedFunction(EOpAsinh, float1,
        "float webgl_asinh_emu(in float x) {\n"
        "    return log(x + sqrt(pow(x, 2.0) + 1.0));\n"
        "}\n");
    AddEmulatedFunction(EOpAsinh, float2,
        "float2 webgl_asinh_emu(in float2 x) {\n"
        "    return log(x + sqrt(pow(x, 2.0) + 1.0));"
        "}\n");
    AddEmulatedFunction(EOpAsinh, float3,
        "float3 webgl_asinh_emu(in float3 x) {\n"
        "    return log(x + sqrt(pow(x, 2.0) + 1.0));\n"
        "}\n");
    AddEmulatedFunction(EOpAsinh, float4,
        "float4 webgl_asinh_emu(in float4 x) {\n"
        "    return log(x + sqrt(pow(x, 2.0) + 1.0));\n"
        "}\n");

    AddEmulatedFunction(EOpAcosh, float1,
        "float webgl_acosh_emu(in float x) {\n"
        "    return log(x + sqrt(x + 1.0) * sqrt(x - 1.0));\n"
        "}\n");
    AddEmulatedFunction(EOpAcosh, float2,
        "float2 webgl_acosh_emu(in float2 x) {\n"
        "    return log(x + sqrt(x + 1.0) * sqrt(x - 1.0));\n"
        "}\n");
    AddEmulatedFunction(EOpAcosh, float3,
        "float3 webgl_acosh_emu(in float3 x) {\n"
        "    return log(x + sqrt(x + 1.0) * sqrt(x - 1.0));\n"
        "}\n");
    AddEmulatedFunction(EOpAcosh, float4,
        "float4 webgl_acosh_emu(in float4 x) {\n"
        "    return log(x + sqrt(x + 1.0) * sqrt(x - 1.0));\n"
        "}\n");

    AddEmulatedFunction(EOpAtanh, float1,
        "float webgl_atanh_emu(in float x) {\n"
        "    return 0.5 * log((1.0 + x) / (1.0 - x));\n"
        "}\n");
    AddEmulatedFunction(EOpAtanh, float2,
        "float2 webgl_atanh_emu(in float2 x) {\n"
        "    return 0.5 * log((1.0 + x) / (1.0 - x));\n"
        "}\n");
    AddEmulatedFunction(EOpAtanh, float3,
        "float3 webgl_atanh_emu(in float3 x) {\n"
        "    return 0.5 * log((1.0 + x) / (1.0 - x));\n"
        "}\n");
    AddEmulatedFunction(EOpAtanh, float4,
        "float4 webgl_atanh_emu(in float4 x) {\n"
        "    return 0.5 * log((1.0 + x) / (1.0 - x));\n"
        "}\n");

    // The matrix resulting from outer product needs to be transposed
    // (matrices are stored as transposed to simplify element access in HLSL).
    // So the function should return transpose(c * r) where c is a column vector
    // and r is a row vector. This can be simplified by using the following
    // formula:
    //   transpose(c * r) = transpose(r) * transpose(c)
    // transpose(r) and transpose(c) are in a sense free, since to get the
    // transpose of r, we simply can build a column matrix out of the original
    // vector instead of a row matrix.
    AddEmulatedFunction(EOpOuterProduct, float2, float2,
        "float2x2 webgl_outerProduct_emu(in float2 c, in float2 r) {\n"
        "    return mul(float2x1(r), float1x2(c));\n"
        "}\n");
    AddEmulatedFunction(EOpOuterProduct, float3, float3,
        "float3x3 webgl_outerProduct_emu(in float3 c, in float3 r) {\n"
        "    return mul(float3x1(r), float1x3(c));\n"
        "}\n");
    AddEmulatedFunction(EOpOuterProduct, float4, float4,
        "float4x4 webgl_outerProduct_emu(in float4 c, in float4 r) {\n"
        "    return mul(float4x1(r), float1x4(c));\n"
        "}\n");

    AddEmulatedFunction(EOpOuterProduct, float3, float2,
        "float2x3 webgl_outerProduct_emu(in float3 c, in float2 r) {\n"
        "    return mul(float2x1(r), float1x3(c));\n"
        "}\n");
    AddEmulatedFunction(EOpOuterProduct, float2, float3,
        "float3x2 webgl_outerProduct_emu(in float2 c, in float3 r) {\n"
        "    return mul(float3x1(r), float1x2(c));\n"
        "}\n");
    AddEmulatedFunction(EOpOuterProduct, float4, float2,
        "float2x4 webgl_outerProduct_emu(in float4 c, in float2 r) {\n"
        "    return mul(float2x1(r), float1x4(c));\n"
        "}\n");
    AddEmulatedFunction(EOpOuterProduct, float2, float4,
        "float4x2 webgl_outerProduct_emu(in float2 c, in float4 r) {\n"
        "    return mul(float4x1(r), float1x2(c));\n"
        "}\n");
    AddEmulatedFunction(EOpOuterProduct, float4, float3,
        "float3x4 webgl_outerProduct_emu(in float4 c, in float3 r) {\n"
        "    return mul(float3x1(r), float1x4(c));\n"
        "}\n");
    AddEmulatedFunction(EOpOuterProduct, float3, float4,
        "float4x3 webgl_outerProduct_emu(in float3 c, in float4 r) {\n"
        "    return mul(float4x1(r), float1x3(c));\n"
        "}\n");
}

void BuiltInFunctionEmulatorHLSL::OutputEmulatedFunctionDefinition(
    TInfoSinkBase& out) const
{
    OutputEmulatedFunctions(out);
}
