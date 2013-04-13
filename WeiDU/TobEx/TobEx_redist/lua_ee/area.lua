-- area.lua

function area_getcurrent()
  local _game = createobject(game)
  local _f = pushcfunction(func_CInfGame_GetActiveArea)
  return createobject(_game:stdcall(_f), "area") --table
end

function area_listsprites(_are)
  if _are.type ~= "area" then
    error("expected an area object(1)")
  end

  local _front = _are:getlist(off_CArea_ListFront)
  local _mid = _are:getlist(off_CArea_ListBack)
  local _back = _are:getlist(off_CArea_List2)

  local _index, _value
  local _obj

  if (_front ~= nil) then
    p("--Front")
    _index, _value = nil, nil
    repeat
      _index, _value = next(_front, _index)
      if (_value ~= nil) then
        _obj = createobject(getsprite(u2n(_value)), "sprite")
        _obj.type = sprite_gettype(_obj)
        _obj:print(1)
      end
    until _index == nil
  end

  if (_mid ~= nil) then
    p("--Back")
    _index, _value = nil, nil
    repeat
      _index, _value = next(_mid, _index)
      if (_value ~= nil) then
        _obj = createobject(getsprite(u2n(_value)), "sprite")
        _obj.type = sprite_gettype(_obj)
        _obj:print(1)
      end
    until _index == nil
  end

  if (_back ~= nil) then
    p("--2")
    _index, _value = nil, nil
    repeat
      _index, _value = next(_back, _index)
      if (_value ~= nil) then
        _obj = createobject(getsprite(u2n(_value)), "sprite")
        _obj.type = sprite_gettype(_obj)
        _obj:print(1)
      end
    until _index == nil
  end
end