//
// Copyright (c) 2014 The ANGLE Project Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.
//

// angletypes.h: Workarounds for driver bugs and other issues.

#ifndef LIBANGLE_RENDERER_WORKAROUNDS_H_
#define LIBANGLE_RENDERER_WORKAROUNDS_H_

// TODO(jmadill,zmo,geofflang): make a workarounds library that can operate
// independent of ANGLE's renderer. Workarounds should also be accessible
// outside of the Renderer.

namespace rx
{

enum D3DWorkaroundType
{
    ANGLE_D3D_WORKAROUND_NONE,
    ANGLE_D3D_WORKAROUND_SKIP_OPTIMIZATION,
    ANGLE_D3D_WORKAROUND_MAX_OPTIMIZATION
};

struct Workarounds
{
    Workarounds()
        : mrtPerfWorkaround(false),
          setDataFasterThanImageUpload(false),
          zeroMaxLodWorkaround(false)
    {}

    bool mrtPerfWorkaround;
    bool setDataFasterThanImageUpload;

    // Some renderers can't disable mipmaps on a mipmapped texture (i.e. solely sample from level zero, and ignore the other levels).
    // D3D11 Feature Level 10+ does this by setting MaxLOD to 0.0f in the Sampler state. D3D9 sets D3DSAMP_MIPFILTER to D3DTEXF_NONE.
    // There is no equivalent to this in D3D11 Feature Level 9_3.
    // This causes problems when (for example) an application creates a mipmapped texture2D, but sets GL_TEXTURE_MIN_FILTER to GL_NEAREST (i.e disables mipmaps).
    // To work around this, D3D11 FL9_3 has to create two copies of the texture. The textures' level zeros are identical, but only one texture has mips.
    bool zeroMaxLodWorkaround;
};

}

#endif // LIBANGLE_RENDERER_WORKAROUNDS_H_
