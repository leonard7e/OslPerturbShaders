#ifndef __PBRBUNDLE__H
#define __PBRBUNDLE__H

struct PbrBundle {
    color SurfaceColor;
    float Subsurface;
    float Metallic;
    float Specular;
    float Roughness;
    color EmissiveColor;
    float EmissiveIntensity;

};

#endif
