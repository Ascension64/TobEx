-- creature.lua

function creature_getstat(_cre, _n)
  if _cre.type ~= "sprite_creature" then
    error("expected a creature object (1)")
  end
  if _n == nil then
    error("expected a stat number (2)")
  end

  local _f = pushcfunction(func_CCreatureObject_GetDerivedStats)
  local _cds = createobject(_cre:stdcall(_f), "stats")
  _f = pushcfunction(func_CDerivedStats_GetStat)
  p(u2n(_cds:stdcall(_f, _n)))
end

function creature_liststates(_cre)
  if _cre.type ~= "sprite_creature" then
    error("expected a creature object (1)")
  end

  local _f = pushcfunction(func_CCreatureObject_GetDerivedStats)
  local _cds = createobject(_cre:stdcall(_f), "stats")

  local _state = _cds:getdword(off_CDerivedStats_GeneralState)
  if (_state ~= 0) then
    p("--State: (" .. dec2hex(_state) .. ")")
    if band(_state, "0x1") ~= 0 then
      p("STATE_SLEEPING")
    end
    if band(_state, "0x2") ~= 0 then
      p("STATE_BERSERK")
    end
    if band(_state, "0x4") ~= 0 then
      p("STATE_PANIC")
    end
    if band(_state, "0x8") ~= 0 then
      p("STATE_STUNNED")
    end
    if band(_state, "0x10") ~= 0 then
      p("STATE_INVISIBLE")
    end
    if band(_state, "0x20") ~= 0 then
      p("STATE_HELPLESS")
    end
    if band(_state, "0x40") ~= 0 then
      p("STATE_FROZEN_DEATH")
    end
    if band(_state, "0x80") ~= 0 then
      p("STATE_STONE_DEATH")
    end
    if band(_state, "0x100") ~= 0 then
      p("STATE_EXPLODING_DEATH")
    end
    if band(_state, "0x200") ~= 0 then
      p("STATE_FLAME_DEATH")
    end
    if band(_state, "0x400") ~= 0 then
      p("STATE_ACID_DEATH")
    end
    if band(_state, "0x800") ~= 0 then
      p("STATE_DEAD")
    end
    if band(_state, "0x1000") ~= 0 then
      p("STATE_SILENCED")
    end
    if band(_state, "0x2000") ~= 0 then
      p("STATE_CHARMED")
    end
    if band(_state, "0x4000") ~= 0 then
      p("STATE_POISONED")
    end
    if band(_state, "0x8000") ~= 0 then
      p("STATE_HASTED")
    end
    if band(_state, "0x10000") ~= 0 then
      p("STATE_SLOWED")
    end
    if band(_state, "0x20000") ~= 0 then
      p("STATE_INFRAVISION")
    end
    if band(_state, "0x40000") ~= 0 then
      p("STATE_BLIND")
    end
    if band(_state, "0x80000") ~= 0 then
      p("STATE_DISEASED")
    end
    if band(_state, "0x100000") ~= 0 then
      p("STATE_FEEBLEMINDED")
    end
    if band(_state, "0x200000") ~= 0 then
      p("STATE_NONDETECTION")
    end
    if band(_state, "0x400000") ~= 0 then
      p("STATE_IMPROVEDINVISIBILITY")
    end
    if band(_state, "0x800000") ~= 0 then
      p("STATE_BLESS")
    end
    if band(_state, "0x1000000") ~= 0 then
      p("STATE_CHANT")
    end
    if band(_state, "0x2000000") ~= 0 then
      p("STATE_DRAWUPONHOLYMIGHT")
    end
    if band(_state, "0x4000000") ~= 0 then
      p("STATE_LUCK")
    end
    if band(_state, "0x8000000") ~= 0 then
      p("STATE_AID")
    end
    if band(_state, "0x10000000") ~= 0 then
      p("STATE_CHANTBAD")
    end
    if band(_state, "0x20000000") ~= 0 then
      p("STATE_BLUR")
    end
    if band(_state, "0x40000000") ~= 0 then
      p("STATE_MIRRORIMAGE")
    end
    if band(_state, "0x80000000") ~= 0 then
      p("STATE_CONFUSED")
    end
  end
end

function creature_listtriggers(_cre)
  if _cre.type ~= "sprite_creature" then
    error("expected a creature object (1)")
  end

  p("--Triggers")
  local _list = _cre:getlist(off_CGameSprite_Triggers)
  if (_list ~= nil) then
    local _index, _value = nil, nil
    repeat
      _index, _value = next(_list, _index)
      local _trigger
      if (_value ~= nil) then
        _trigger = createobject(_value, "trigger")
        _trigger:print(1)
      end
    until _index == nil
  end
end

function creature_listactions(_cre)
  if _cre.type ~= "sprite_creature" then
    error("expected a creature object (1)")
  end

  p("--Actions (top action running for " .. tostring(_cre:getword(off_CGameSprite_ActionTicksElapsed)) .. " ticks]")
  local _action_c = createobject(_cre:getaddress(off_CGameSprite_CurrentAction), "action")
  _action_c:print(1)

  local _list = _cre:getlist(off_CGameSprite_Actions)
  if (_list ~= nil) then
    local _index, _value = nil, nil
    repeat
      _index, _value = next(_list, _index)
      local _action_l
      if (_value ~= nil) then
        _action_l = createobject(_value, "action")
        _action_l:print(1)
      end
    until _index == nil
  end
end

function creature_listtriggerobjects(_cre)
  if _cre.type ~= "sprite_creature" then
    error("expected a creature object (1)")
  end

  p("--Objects")
  local _object = createobject(_cre:getaddress(off_CGameSprite_ObjectAttackedBy), "object")
  if (_object:print(0) ~= "") then
    p("last AttackedBy: " .. _object:print(0))
  end
  _object = createobject(_cre:getaddress(off_CGameSprite_ObjectCommandedBy), "object")
  if (_object:print(0) ~= "") then
    p("last CommandedBy: " .. _object:print(0))
  end
  _object = createobject(_cre:getaddress(off_CGameSprite_ObjectProtectedBy), "object")
  if (_object:print(0) ~= "") then
    p("last ProtectedBy: " .. _object:print(0))
  end
  _object = createobject(_cre:getaddress(off_CGameSprite_ObjectProtectorOf), "object")
  if (_object:print(0) ~= "") then
    p("last ProtectorOf: " .. _object:print(0))
  end
  _object = createobject(_cre:getaddress(off_CGameSprite_ObjectTargetedBy), "object")
  if (_object:print(0) ~= "") then
    p("last TargetedBy: " .. _object:print(0))
  end
  _object = createobject(_cre:getaddress(off_CGameSprite_ObjectHitBy), "object")
  if (_object:print(0) ~= "") then
    p("last HitBy: " .. _object:print(0))
  end
  _object = createobject(_cre:getaddress(off_CGameSprite_ObjectHelp), "object")
  if (_object:print(0) ~= "") then
    p("last Help shouter: " .. _object:print(0))
  end
  _object = createobject(_cre:getaddress(off_CGameSprite_ObjectTrigger), "object")
  if (_object:print(0) ~= "") then
    p("last Trigger: " .. _object:print(0))
  end
  _object = createobject(_cre:getaddress(off_CGameSprite_ObjectSeenBy), "object")
  if (_object:print(0) ~= "") then
    p("last SeenBy: " .. _object:print(0))
  end
  _object = createobject(_cre:getaddress(off_CGameSprite_ObjectTalkedToBy), "object")
  if (_object:print(0) ~= "") then
    p("last TalkedToBy: " .. _object:print(0))
  end
  _object = createobject(_cre:getaddress(off_CGameSprite_ObjectHeardBy), "object")
  if (_object:print(0) ~= "") then
    p("last HeardBy: " .. _object:print(0))
  end
  _object = createobject(_cre:getaddress(off_CGameSprite_ObjectSummonerOf), "object")
  if (_object:print(0) ~= "") then
    p("last SummonerOf: " .. _object:print(0))
  end
  _object = createobject(_cre:getaddress(off_CGameSprite_Object1), "object")
  if (_object:print(0) ~= "") then
    p("last 1: " .. _object:print(0))
  end
  _object = createobject(_cre:getaddress(off_CGameSprite_Object2), "object")
  if (_object:print(0) ~= "") then
    p("last 2: " .. _object:print(0))
  end
  _object = createobject(_cre:getaddress(off_CGameSprite_Object3), "object")
  if (_object:print(0) ~= "") then
    p("last 3: " .. _object:print(0))
  end
  _object = createobject(_cre:getaddress(off_CGameSprite_Object4), "object")
  if (_object:print(0) ~= "") then
    p("last 4: " .. _object:print(0))
  end
  _object = createobject(_cre:getaddress(off_CGameSprite_Object5), "object")
  if (_object:print(0) ~= "") then
    p("last 5: " .. _object:print(0))
  end
  _object = createobject(_cre:getaddress(off_CGameSprite_Object6), "object")
  if (_object:print(0) ~= "") then
    p("last 6: " .. _object:print(0))
  end
  _object = createobject(_cre:getaddress(off_CGameSprite_Object7), "object")
  if (_object:print(0) ~= "") then
    p("last 7: " .. _object:print(0))
  end
  _object = createobject(_cre:getaddress(off_CGameSprite_Object8), "object")
  if (_object:print(0) ~= "") then
    p("last 8: " .. _object:print(0))
  end
  _object = createobject(_cre:getaddress(off_CGameSprite_Object9), "object")
  if (_object:print(0) ~= "") then
    p("last 9: " .. _object:print(0))
  end
  _object = createobject(_cre:getaddress(off_CGameSprite_Object10), "object")
  if (_object:print(0) ~= "") then
    p("last 10: " .. _object:print(0))
  end
  _object = createobject(_cre:getaddress(off_CGameSprite_Object11), "object")
  if (_object:print(0) ~= "") then
    p("last 11: " .. _object:print(0))
  end
  _object = createobject(_cre:getaddress(off_CGameSprite_Object12), "object")
  if (_object:print(0) ~= "") then
    p("last 12: " .. _object:print(0))
  end
  _object = createobject(_cre:getaddress(off_CGameSprite_Object13), "object")
  if (_object:print(0) ~= "") then
    p("last 13: " .. _object:print(0))
  end
end

function creature_listscripts(_cre)
  if _cre.type ~= "sprite_creature" then
    error("expected a creature object (1)")
  end

  p("--Scripts")
  local _script, _name
  if u2n(_cre:getpointer(off_CGameSprite_ScriptOverride)) ~= 0 then
    _script = createobject(_cre:getpointer(off_CGameSprite_ScriptOverride), "script")
    _name = _script:getstring(0, 8)
    p("Override (0): " .. _name)
  end
  if u2n(_cre:getpointer(off_CGameSprite_Script1)) ~= 0 then
    _script = createobject(_cre:getpointer(off_CGameSprite_Script1), "script")
    _name = _script:getstring(0, 8)
    p("(1): " .. _name)
  end
  if u2n(_cre:getpointer(off_CGameSprite_ScriptAreaSpecific)) ~= 0 then
    _script = createobject(_cre:getpointer(off_CGameSprite_ScriptAreaSpecific), "script")
    _name = _script:getstring(0, 8)
    p("Area (2): " .. _name)
  end
  if u2n(_cre:getpointer(off_CGameSprite_ScriptClass)) ~= 0 then
    _script = createobject(_cre:getpointer(off_CGameSprite_ScriptClass), "script")
    _name = _script:getstring(0, 8)
    p("Class (3): " .. _name)
  end
  if u2n(_cre:getpointer(off_CGameSprite_ScriptRace)) ~= 0 then
    _script = createobject(_cre:getpointer(off_CGameSprite_ScriptRace), "script")
    _name = _script:getstring(0, 8)
    p("Race (4): " .. _name)
  end
  if u2n(_cre:getpointer(off_CGameSprite_ScriptGeneral)) ~= 0 then
    _script = createobject(_cre:getpointer(off_CGameSprite_ScriptGeneral), "script")
    _name = _script:getstring(0, 8)
    p("General (5): " .. _name)
  end
  if u2n(_cre:getpointer(off_CGameSprite_ScriptDefault)) ~= 0 then
    _script = createobject(_cre:getpointer(off_CGameSprite_ScriptDefault), "script")
    _name = _script:getstring(0, 8)
    p("Default (6): " .. _name)
  end

  p("Current script: Index " .. tostring(_cre:getword(off_CGameSprite_CurrentScriptIndex))
    .. " block #" .. tostring(_cre:getword(off_CGameSprite_CurrentScriptBlockIndex))
    .. " response #" .. tostring(_cre:getword(off_CGameSprite_CurrentResponseIndex)))
end