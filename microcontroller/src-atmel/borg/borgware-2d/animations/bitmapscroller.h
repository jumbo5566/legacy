#ifndef BITMAP_SCROLLER_H_
#define BITMAP_SCROLLER_H_

#include <stdint.h>


/**
 * This type definition describes a function which is supposed to provide an
 * eight-by-one pixel chunk of a bitmap for a given bit plane. The x-coordinates
 * are based on chunks, not on pixels (i.e. nChunkX=2 has to be interpreted as
 * a pixel based x-coordinate of 16). This way it is easy to provide the bitmap
 * via a simple lookup in an uint8_t typed array. (0,0) is considered as the top
 * left coordinate.
 * @param nBitPlane Number of the desired bit plane.
 * @param nChunkX x-coordinate of the chunk.
 * @param nChunkY y-coordinate of the chunk.
 * @param nFrame The current frame number (in case you want to animate sth.).
 * @return an eight-by-one chunk of the bitmap packed into an uint8_t typed
 */
typedef uint8_t (*bitmap_getChunk_t)(unsigned int const nBitPlane,
                                     unsigned int const nChunkX,
                                     unsigned int const nChunkY,
                                     unsigned int const nFrame);


void bitmap_scroll(unsigned int const nWidth,
                   unsigned int const nHeight,
                   unsigned char const nBitPlanes,
                   unsigned int const nFrameCount,
                   unsigned int const nFrameTick,
                   bitmap_getChunk_t fpGetChunk);

#endif /* BITMAP_SCROLLER_H_ */