-- sprite.lua

function sprite_getcurrent()
  local _area = area_getcurrent()
  local _enum = _area:getdword("0x242")
  if _enum == -1 then
    error("No object")
  end
  local _sprite = createobject(getsprite(_enum), "sprite")
  _sprite.type = sprite_gettype(_sprite)
  return _sprite --table
end

function sprite_gettype(_obj)
  if _obj.type ~= "sprite" then
    error("expected a sprite object (1)")
  end

  local _type = _obj:getbyte(4)
  if _type == 0 then
     return "visualeffect"
  elseif _type == 1 then
     return "sprite"
  elseif _type == 16 then -- 0x10
     return "sound"
  elseif _type == 17 then -- 0x11
     return "container"
  elseif _type == 32 then -- 0x20
     return "spawn"
  elseif _type == 33 then -- 0x21
     return "door"
  elseif _type == 48 then -- 0x30
     return "static"
  elseif _type == 49 then -- 0x31
     return "creature"
  elseif _type == 64 then -- 0x40
     return "objmarker"
  elseif _type == 65 then -- 0x41
     return "trigobj"
  elseif _type == 81 then -- 0x51
     return "tile"
  elseif _type == 96 then -- 0x60
     return "smoke"
  elseif _type == 97 then -- 0x61
     return "area"
  elseif _type == 113 then -- 0x71
     return "baldur"
  else
    return "notype"
  end
end