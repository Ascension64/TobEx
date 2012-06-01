$debug

--globals
chitin = GetBaldurChitin()
game = chitin:GetObjectGame()
timer = game:GetWorldTimer()
options = game:GetOptions()

function p(text)
  CLUAConsole:DisplayText(tostring(text))
end

--dump functions
dofile("TobEx_ini/lua/dump.lua")
dofile("TobEx_ini/lua/area.lua")
dofile("TobEx_ini/lua/sprite.lua")
dofile("TobEx_ini/lua/creature.lua")

dofile("TobEx_ini/lua/user.lua")