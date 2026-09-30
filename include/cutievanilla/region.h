#ifndef CV_REGION_H_INCLUDED
#define CV_REGION_H_INCLUDED

#define CV_REGION(x, y, w, h) ((CVRegion){x, y, w, h})

typedef struct _CVRegion{

    int x;
    int y;
    
    int width;
    int height;

}CVRegion;




#endif // CV_REGION_H_INCLUDED