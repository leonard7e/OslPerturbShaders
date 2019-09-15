#ifndef __PBRBUNDLE__H
#define __PBRBUNDLE__H

struct PbrBundle {
    color BaseColor;
    color SSSColor;
    float Subsurface;
    float Metallic;
    float Roughness;
    float Specular;
};

#endif
