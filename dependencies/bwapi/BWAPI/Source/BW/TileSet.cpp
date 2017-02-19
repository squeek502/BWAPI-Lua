#include "TileSet.h"
#include "TileType.h"

#include "../../../Debug.h"
#include <BW/Offsets.h>

namespace BW
{
  TileType* TileSet::getTileType(TileID tileID)
  {
    if ( BW::BWDATA::TileSetMap )
      return &BW::BWDATA::TileSetMap[(tileID >> 4 ) & 0x7FF];
    return nullptr;
  }
};
